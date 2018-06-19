#include "mbed.h"
#include "Timeout.h"

Timer delaytje;

#define V_REF 3.28F

Serial UART(USBTX, USBRX, 57600);
AnalogIn MOTOR1_CURRENT_SENSOR(A1);
Timer TIMER_1;

class Usainmonitor{
public:
    Usainmonitor(PinName pin_number, float shunt_value): _adcpin(pin_number) ,_shunt_value(shunt_value){}

    ~Usainmonitor();

    float get_shunt_voltage()
    {
        return (_adcpin.read() * V_REF);
    }

    float get_shunt_resistor_value()
    {
        return _shunt_value;
    }

    float get_voltage()
    {
        return V_REF;
    }

    float get_current()
    {
        return (_adcpin.read() * V_REF) / _shunt_value;
    }
    float get_power()
    {
        return V_REF * get_current();
    }

private:
    AnalogIn _adcpin;
    const float _shunt_value;
};


int main()
{
    Usainmonitor motor_left(A0, 0.1);
    while (1)
    {
        TIMER_1.reset();
        TIMER_1.start();
        while (TIMER_1.read() < 1);
        printf(        "shunt voltage: %f\r\n"
                       "shunt current: %f\r\n"
                       "shunt power:   %f\r\n"
                       "voltage in:    %f\r\n\r\n",
                       motor_left.get_shunt_voltage(), motor_left.get_current(),
                       motor_left.get_power(), motor_left.get_voltage());
    }

//    double      v_in;
//
//    UART.printf("initialize\r\n");
//
//
//    while (1)
//    {
//        TIMER_1.reset();
//        TIMER_1.start();
//        while (TIMER_1.read() < 1);
//
//        v_in = (MOTOR1_CURRENT_SENSOR.read() * V_REF);
//        printf("motor  bits are %f, current is %f \r\n\r\n", MOTOR1_CURRENT_SENSOR.read(), (MOTOR1_CURRENT_SENSOR.read() * V_REF) / R_SHUNT);
//    }
//    return 0;
}


//AnalogIn    v_input(A0);
//AnalogIn    vref(ADC_VREF);
//Timer       tmr;
//
//int main() {
//    double      v_in, vdd;
//    double      v_in_actual;
//
//    while(true) {
//        tmr.reset();
//        tmr.start();
//        vdd  = (1.224f) / vref.read();
//        v_in = v_input.read();
//        v_in_actual = v_in * vdd * ( R1 + R2) / R2;
//        printf("V IN : %5.3f [V]\r\n", v_in_actual);
//        wait_ms(500 - tmr.read_ms());      // 0.5sec interval
//    }
//}
/*******************************************************************************************

 *******************************************************************************************/


//#include "mbed.h"
//#include "DRV_INA129.h"
//
//DigitalOut led(LED1);
//DigitalIn button(USER_BUTTON);
//Timer karel;
////Serial UART(USBTX, USBRX, 57600);
////Serial GPS(D1, D0);
//
//int main()
//{
//    UART.printf("initialize\r\n");
//    INA129 piet;
//    int ack;
//    float harrie;
//    char dummiedata[1] = {1};
//
//
//    while (1)
//    {
//
//
//        harrie = piet.get_config();
//        UART.printf("reg voltage = %04X V\r\n", harrie);
//
////        for(uint8_t i = 0; i < 127; i++){
//            karel.reset();
//            karel.start();
//            while (karel.read_ms() < 1000);
////            ack = I2C_BUS.write(i,dummiedata, 1);
////            if (ack == 0)
////            {
////                UART.printf("I2C bus founded on address %d\r\n", i);
////            }
////        }
//        UART.printf("I2C addresses scanned \r\n");
//    }
//    return 0;
//}