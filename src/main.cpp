#include "mbed.h"
#include "DRV_INA129.h"

DigitalOut led(LED1);
DigitalIn button(USER_BUTTON);
//Serial UART(USBTX, USBRX, 57600);
//Serial GPS(D1, D0);

int main()
{
    INA129 piet(INA129_LEFT_MOTOR_ADDRESS);
    float harrie;
    harrie = piet.get_bus_voltage();
    while (1)
    {

    }
    return 0;
}