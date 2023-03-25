/*
* This class supports: ADS1294, ADS1294R, ADS1296, ADS1296R, ADS1298, ADS1298R.
*/
#ifndef __ADS129X_INCLUDE
#define __ADS129X_INCLUDE

#include <Arduino.h>
#include <SPI.h>
#include "ads1x9x.h"

// ---------------------
// Register map (page 65)
#define ADS129x_REG_PACE 0x15
#define ADS129x_REG_RESP 0x16
#define ADS129x_REG_WCT1 0x18
#define ADS129x_REG_WCT2 0x19
// ---------------------
// CONFIG BIT MASKS
// CONFIG 1
#define ADS129x_REG_CONFIG1_HIGH_RES 0b10000000       /* HR mode */
#define ADS129x_REG_CONFIG1_MULTI_READBACK 0b01000000 /* Multiple readback mode */
#define ADS129x_REG_CONFIG1_CLK_EN 0b00100000         /* Oscillator clock output enabled */
#define ADS129x_REG_CONFIG1_32KSPS 0b00000000         /* HR Mode: 32 kSPS, LP Mode: 16 kSPS */
#define ADS129x_REG_CONFIG1_16KSPS 0b00000001         /* HR Mode: 16 kSPS, LP Mode:  8 kSPS */
#define ADS129x_REG_CONFIG1_8KSPS 0b00000010          /* HR Mode:  8 kSPS, LP Mode:  4 kSPS */
#define ADS129x_REG_CONFIG1_4KSPS 0b00000011          /* HR Mode:  4 kSPS, LP Mode:  2 kSPS */
#define ADS129x_REG_CONFIG1_2KSPS 0b00000100          /* HR Mode:  2 kSPS, LP Mode:  1 kSPS */
#define ADS129x_REG_CONFIG1_1KSPS 0b00000101          /* HR Mode:  1 kSPS, LP Mode: 500 SPS */
#define ADS129x_REG_CONFIG1_500SPS 0b00000110         /* HR Mode: 500 SPS, LP Mode: 250 SPS */
#define ADS129x_REG_CONFIG1_RATE_MASK 0b00000111
// CONFIG 2
#define ADS129x_REG_CONFIG2_INT_TEST 0b00010000 /* Test signals are generated internally */
#define ADS129x_REG_CONFIG2_TEST_AMP 0b00000100
#define ADS129x_REG_CONFIG2_TEST_FREQ_FAST 0b00000001
#define ADS129x_REG_CONFIG2_TEST_FREQ_DC 0b00000011
// CONFIG 3
#define ADS129x_REG_CONFIG3_RESERVED 0b01000000  /* Reserved bits to set to 1 */
#define ADS129x_REG_CONFIG3_PD_REFBUF 0b10000000 /* Enable internal reference buffer */
// Individual Channel Settings
#define ADS129x_REG_CHnSET_PD 0b10000000 /* Channel power-down */
#define ADS129x_REG_CHnSET_GAIN_1 0b00010000
#define ADS129x_REG_CHnSET_GAIN_2 0b00100000
#define ADS129x_REG_CHnSET_GAIN_3 0b00110000
#define ADS129x_REG_CHnSET_GAIN_4 0b01000000
#define ADS129x_REG_CHnSET_GAIN_6 0b00000000
#define ADS129x_REG_CHnSET_GAIN_8 0b01010000
#define ADS129x_REG_CHnSET_GAIN_12 0b01100000
// ---------------------

class ADS129x: public ADS1X9X{
public:
  ADS129x(int cs_pin_set, int drdy_pin_set, int reset_pin_set, SPIClass* spi_set);
  void all_defaults();
  void channel_defaults();
};
#endif
