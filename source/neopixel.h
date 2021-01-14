#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif
   extern void sendNeopixelBuffer(uint32_t pin, uint8_t *data_address, uint16_t num_leds);

#ifdef __cplusplus
}
#endif

class neopixel_strip
{
public:
   neopixel_strip(uint8_t pin_num, uint8_t num_leds);

   ~neopixel_strip();

   void clear();

   void send();

   bool set_color(uint8_t index, uint8_t red, uint8_t green, uint8_t blue);

private:
   uint8_t m_pin_num;
   uint8_t m_num_leds;
   uint8_t *m_data;
};
