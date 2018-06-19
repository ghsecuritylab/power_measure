//
// Created by Bas on 4-6-2018.
//

#ifndef BLINKY_DRV_INA129_H
#define BLINKY_DRV_INA129_H

#include "mbed.h"


/* Defines ********************************************************************/
#define INA219_I2C						I2C1
#define INA219_I2C_PORT					GPIOB
#define INA219_I2C_PER_CLOCK			RCC_APB1Periph_I2C1
#define INA219_I2C_GPIO_CLOCK			RCC_APB2Periph_GPIOB
#define INA219_I2C_SDA_PIN				GPIO_Pin_7
#define INA219_I2C_SCL_PIN				GPIO_Pin_6
#define INA219_I2C_CLOCK_SPEED			100000

/** I2C Address Options */
#define INA219_I2C_ADDRESS_CONF_0				(0x40 << 1)			// A0 = GND, A1 = GND
#define INA219_I2C_ADDRESS_CONF_1				(0x41 << 1)			// A0 = VS+, A1 = GND
#define INA219_I2C_ADDRESS_CONF_2				(0x42 << 1)			// A0 = SDA, A1 = GND
#define INA219_I2C_ADDRESS_CONF_3				(0x43 << 1)			// A0 = SCL, A1 = GND
#define INA219_I2C_ADDRESS_CONF_4				(0x44 << 1)			// A0 = GND, A1 = VS+
#define INA219_I2C_ADDRESS_CONF_5				(0x45 << 1)			// A0 = VS+, A1 = VS+
#define INA219_I2C_ADDRESS_CONF_6				(0x46 << 1)			// A0 = SDA, A1 = VS+
#define INA219_I2C_ADDRESS_CONF_7				(0x47 << 1)			// A0 = SCL, A1 = VS+
#define INA219_I2C_ADDRESS_CONF_8				(0x48 << 1)			// A0 = GND, A1 = SDA
#define INA219_I2C_ADDRESS_CONF_9				(0x49 << 1)			// A0 = VS+, A1 = SDA
#define INA219_I2C_ADDRESS_CONF_A				(0x4A << 1)			// A0 = SDA, A1 = SDA
#define INA219_I2C_ADDRESS_CONF_B				(0x4B << 1)			// A0 = SCL, A1 = SDA
#define INA219_I2C_ADDRESS_CONF_C				(0x4C << 1)			// A0 = GND, A1 = SCL
#define INA219_I2C_ADDRESS_CONF_D				(0x4D << 1)			// A0 = VS+, A1 = SCL
#define INA219_I2C_ADDRESS_CONF_E				(0x4E << 1)			// A0 = SDA, A1 = SCL
#define INA219_I2C_ADDRESS_CONF_F				(0x4F << 1)			// A0 = SCL, A1 = SCL
#define INA219_I2C_ADDRESS_DEFAULT				INA219_I2C_ADDRESS_CONF_0


/** Register Addresses ********************************************************/
#define INA219_REG_CONFIG						(0x00)	// CONF REGISTER (R/W)
#define INA219_REG_SHUNTVOLTAGE					(0x01)	// SHUNT VOLTAGE REGISTER (R)
#define INA219_REG_BUSVOLTAGE					(0x02) 	// BUS VOLTAGE REGISTER (R)
#define INA219_REG_POWER						(0x03)	// POWER REGISTER (R)
#define INA219_REG_CURRENT						(0x04)	// CURRENT REGISTER (R)
#define INA219_REG_CALIBRATION					(0x05)	// CALIBRATION REGISTER (R/W)



/** Configuration Register ****************************************************/
#define INA219_CONFIG_RESET						(0x8000)  // Reset Bit

#define INA219_CONFIG_BVOLTAGERANGE_MASK		(0x2000)  // Bus Voltage Range Mask
#define INA219_CONFIG_BVOLTAGERANGE_16V			(0x0000)  // 0-16V Range
#define INA219_CONFIG_BVOLTAGERANGE_32V			(0x2000)  // 0-32V Range

#define INA219_CONFIG_GAIN_MASK					(0x1800)  // Gain Mask
#define INA219_CONFIG_GAIN_1_40MV				(0x0000)  // Gain 1, 40mV Range
#define INA219_CONFIG_GAIN_2_80MV				(0x0800)  // Gain 2, 80mV Range
#define INA219_CONFIG_GAIN_4_160MV				(0x1000)  // Gain 4, 160mV Range
#define INA219_CONFIG_GAIN_8_320MV				(0x1800)  // Gain 8, 320mV Range

#define INA219_CONFIG_BADCRES_MASK				(0x0780)  // Bus ADC Resolution Mask
#define INA219_CONFIG_BADCRES_9BIT				(0x0080)  // 9-bit bus res = 0..511
#define INA219_CONFIG_BADCRES_10BIT				(0x0100)  // 10-bit bus res = 0..1023
#define INA219_CONFIG_BADCRES_11BIT				(0x0200)  // 11-bit bus res = 0..2047
#define INA219_CONFIG_BADCRES_12BIT				(0x0400)  // 12-bit bus res = 0..4097

#define INA219_CONFIG_SADCRES_MASK				(0x0078)	// Shunt ADC Resolution and Averaging Mask
#define INA219_CONFIG_SADCRES_9BIT_1S_84US		(0x0000)	// 1 x 9-bit shunt sample
#define INA219_CONFIG_SADCRES_10BIT_1S_148US	(0x0008)	// 1 x 10-bit shunt sample
#define INA219_CONFIG_SADCRES_11BIT_1S_276US	(0x0010)	// 1 x 11-bit shunt sample
#define INA219_CONFIG_SADCRES_12BIT_1S_532US	(0x0018)	// 1 x 12-bit shunt sample
#define INA219_CONFIG_SADCRES_12BIT_2S_1060US	(0x0048)	// 2 x 12-bit shunt samples averaged together
#define INA219_CONFIG_SADCRES_12BIT_4S_2130US	(0x0050)	// 4 x 12-bit shunt samples averaged together
#define INA219_CONFIG_SADCRES_12BIT_8S_4260US	(0x0058)	// 8 x 12-bit shunt samples averaged together
#define INA219_CONFIG_SADCRES_12BIT_16S_8510US	(0x0060)	// 16 x 12-bit shunt samples averaged together
#define INA219_CONFIG_SADCRES_12BIT_32S_17MS	(0x0068)	// 32 x 12-bit shunt samples averaged together
#define INA219_CONFIG_SADCRES_12BIT_64S_34MS	(0x0070)	// 64 x 12-bit shunt samples averaged together
#define INA219_CONFIG_SADCRES_12BIT_128S_69MS	(0x0078)	// 128 x 12-bit shunt samples averaged together

#define INA219_CONFIG_MODE_MASK					(0x0007)  // Operating Mode Mask
#define INA219_CONFIG_MODE_POWERDOWN			(0x0000)
#define INA219_CONFIG_MODE_SVOLT_TRIGGERED		(0x0001)
#define INA219_CONFIG_MODE_BVOLT_TRIGGERED		(0x0002)
#define INA219_CONFIG_MODE_SANDBVOLT_TRIGGERED	(0x0003)
#define INA219_CONFIG_MODE_ADCOFF				(0x0004)
#define INA219_CONFIG_MODE_SVOLT_CONTINUOUS		(0x0005)
#define INA219_CONFIG_MODE_BVOLT_CONTINUOUS		(0x0006)
#define INA219_CONFIG_MODE_SANDBVOLT_CONTINUOUS	(0x0007)


static I2C I2C_BUS(PB_9, PB_8);
static Serial UART(USBTX, USBRX, 57600);
//const int INA129_LEFT_MOTOR_ADDRESS = 0b01000000;
const int INA129_LEFT_MOTOR_ADDRESS = 0b01000001;

class INA129
{
public:
    INA129();

    ~INA129();

    float get_bus_voltage();

    float get_config();

private:
    const int _address;

    int read_register(uint8_t register_address, uint16_t *value);

    int write_register(uint8_t register_address, uint8_t *data, uint8_t data_size);
};

#endif //BLINKY_DRV_INA129_H
