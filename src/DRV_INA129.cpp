//
// Created by Bas on 4-6-2018.
//

#include "DRV_INA129.h"

//1000100
//1000000

INA129::INA129() : _address(0x60)
{
    I2C_BUS.frequency(50000);
}

float INA129::get_bus_voltage()
{
    uint16_t value = 0;
    read_register(INA219_REG_BUSVOLTAGE, (uint16_t *) value);
    return value * 0.001;
}

float INA129::get_config()
{
    uint16_t value = 0;
    read_register(INA219_REG_CONFIG, (uint16_t *) value);
    return value;
}

int INA129::read_register(uint8_t register_address, uint16_t *value)
{
//    I2C_BUS.start();
    char testarray[1] = {register_address};
    if(I2C_BUS.write(_address,  testarray, 1)){
        UART.printf("I2C READ (write function) FAILED\r\n");
//        return -1;
    }
    if(I2C_BUS.read(_address, (char *) value, 2)){
        UART.printf("I2C READ (read function) FAILED\r\n");
//        return -2;
    }
//    I2C_BUS.stop();
    return 0;
}

int INA129::write_register(uint8_t register_address, uint8_t *data, uint8_t data_size)
{
    if(I2C_BUS.write(_address, (char *) register_address, 1)){
        UART.printf("I2C WRITE (write 1 function) FAILED\r\n");
//        return -1;
    }
    if(I2C_BUS.write(_address, (char *) data, data_size)){
//        return -2;
    }
    return 0;
}



