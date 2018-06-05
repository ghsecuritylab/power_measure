//
// Created by Bas on 4-6-2018.
//

#include "DRV_INA129.h"


INA129::INA129(const int address) : address(address)
{

}

float INA129::get_bus_voltage()
{
    if(I2C_BUS.write(address, (char *) INA219_REG_BUSVOLTAGE, 1)){
        UART.printf("I2C busvoltage write failed\r\n");
    }
    int16_t value = 0;
    if(I2C_BUS.read(address, (char *) value, 2)){
        UART.printf("I2C busvoltage read failed\r\n");
    }
    return value * 0.001;
}

float INA129::get_current()
{
//    if(I2C_BUS.write(address, (char *) INA219_REG_CALIBRATION, 1)){
//        UART.printf("I2C busvoltage write failed\r\n");
//    }
//    int16_t value = 0;
//    if(I2C_BUS.read(address, (char *) value, 2)){
//        UART.printf("I2C busvoltage read failed\r\n");
//    }
//    return value * 0.001;
    return 0;
}

int INA129::read_register(uint8_t register_address, uint16_t *value)
{
    if(I2C_BUS.write(address, (char *) register_address, 1)){
        return 1;
    }
    if(I2C_BUS.read(address, (char *) value, 2)){
        return 1;
    }
    return 0;
}

int INA129::write_register(uint8_t register_address)
{
    return 0;
}



