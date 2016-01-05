#ifndef _MODBUS_UTILS_H
#define _MODBUS_UTILS_H


#include "gw_types.h"
#include "modbus.h"
#include "modbus-private.h"
#include "gw_init_app.h"

/* Function codes */
//#define _FC_READ_COILS 0x01
//#define _FC_READ_DISCRETE_INPUTS 0x02
//#define _FC_READ_HOLDING_REGISTERS 0x03
//#define _FC_READ_INPUT_REGISTERS 0x04
//#define _FC_WRITE_SINGLE_COIL 0x05
//#define _FC_WRITE_SINGLE_REGISTER 0x06
//#define _FC_READ_EXCEPTION_STATUS 0x07
//#define _FC_WRITE_MULTIPLE_COILS 0x0F
//#define _FC_WRITE_MULTIPLE_REGISTERS 0x10
//#define _FC_REPORT_SLAVE_ID 0x11
//#define _FC_READ_AND_WRITE_REGISTERS 0x17

#define SERIAL_BITS 8
#define PARITY 'N' //'N' 'O' 'E'
#define STOP_BITS 1

void mbrtu_receiver_start(IN gw_app_t *config);
int openSerialPort(char *acSerialPortName, int tBaudRate);

#endif // _MODBUS_UTILS_H
