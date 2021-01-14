#include "neopixel.h"

#include "nrf_gpio.h"
#include "nrf51.h"

#include <string.h>
#include <stdlib.h>

neopixel_strip::neopixel_strip(uint8_t pin_num, uint8_t num_leds) : m_pin_num{pin_num}, m_num_leds{num_leds}
{
   m_data = static_cast<uint8_t *>(malloc((num_leds * 3) * sizeof(uint8_t)));
   clear();
   nrf_gpio_cfg_output(pin_num);
   NRF_GPIO->OUTCLR = (1UL << pin_num);
}

neopixel_strip::~neopixel_strip()
{
   free(m_data);
}

void neopixel_strip::clear()
{
   memset(m_data, 0, (m_num_leds * 3) * sizeof(uint8_t));
}

void neopixel_strip::send()
{
   NRF_GPIO->OUTCLR = (1UL << m_pin_num);
   sendNeopixelBuffer((1UL << m_pin_num), m_data, m_num_leds);
}

bool neopixel_strip::set_color(uint8_t index, uint8_t red, uint8_t green, uint8_t blue)
{
   if (index < m_num_leds)
   {
      m_data[index * 3] = green;
      m_data[index * 3 + 1] = red;
      m_data[index * 3 + 2] = blue;
      return true;
   }
   else
   {
      return false;
   }
}
