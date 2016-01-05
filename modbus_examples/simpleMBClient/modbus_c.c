#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <stdarg.h>
#include <sys/time.h>
//#include <sys/epoll.h>
#include <fcntl.h>
#include <arpa/inet.h>

#include "modbus_c.h"

#include "modbus/modbus.h"


/*
 * ===  FUNCTION  ======================================================================
 *         Name:  viewMenu
 *  Description:
 * =====================================================================================
 */
void viewMenu(void)
{
    printf("%s\n======================================\n", GREENCOLORSTR);
    printf("%s\n--------------------------------------\n", GREENCOLORSTR);
    printf("6  Run INV1 \n");
    printf("7  Run INV2 \n");
    printf("8  Run INV3 \n");
    printf("5  Run VV\n");
    printf("\n======================================\n");
    printf("Press Number(exit:x)>>%s", ENDCOLORSTR);
    return;
}       /* -----  end of function viewMenu ----- */


int main(int argc, char* argv[]) 
{
	modbus_t *ctx;
	uint16_t *tab_rp_registers;
	int nb_points;
	int rc;

	if (argc != 2) {
		fprintf(stdout, "Useage : MODBUS_C [dev]\n");
		return 0;
	}

	ctx = modbus_new_rtu(argv[1], 9600, 'N', 8, 1);
	if (ctx == NULL) {
		fprintf(stderr, "Unable to allocate libmodbus context\n");
		return -1;
	}

	modbus_set_debug(ctx, TRUE);
	modbus_set_slave(ctx, GW_MODBUS_SERVER_ID);
	//modbus_rtu_set_serial_mode(ctx, MODBUS_RTU_RS485);
	//modbus_rtu_set_rts(ctx, MODBUS_RTU_RTS_UP);

	rc = modbus_connect(ctx);
	if (rc == -1) {
		fprintf(stderr, "Unable to connect %s\n", modbus_strerror(errno));
		modbus_free(ctx);
		return -1;
	}

//	nb_points = (GW_MODBUS_REGISTERS_NB > GW_MODBUS_INPUT_REGISTERS_NB) ?  GW_MODBUS_REGISTERS_NB : GW_MODBUS_INPUT_REGISTERS_NB;
//	tab_rp_registers = (uint16_t *)malloc(nb_points * sizeof(uint16_t));
//	memset(tab_rp_registers, 0, nb_points * sizeof(uint16_t));

	char cCmd[10];

	while(1) {
		memset(cCmd, 0x00, sizeof(cCmd));

		viewMenu();
		fflush(NULL);
		//scanf("%c", &cCmd);
		//cCmd = getc(stdin);
		fgets( cCmd, sizeof(cCmd), stdin );
		if(cCmd[0]  == '1') {
			rc = modbus_write_registers(ctx, GW_MODBUS_INPUT_REGISTERS_ADDRESS, GW_MODBUS_INPUT_REGISTERS_NB, GW_MODBUS_INPUT_REGISTERS_INV1);
		} else if(cCmd[0]  == 'x') {
			printf("Stop Runs ");
			break;
		} else {
			printf("Invalid Input(%d)\n",cCmd[0]);
		}
		sleep(1);
	} // end-of-while()

	fprintf(stderr, "TEST[%d] - %s \n", rc, modbus_strerror(errno));

	modbus_close(ctx);
	modbus_free(ctx);

	return 0;
}

// end-of-file
