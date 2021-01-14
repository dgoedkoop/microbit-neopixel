//! @file neopixel.h
//!
//! @brief Support for NeoPixel on BBC micro:bit
//!
//! @copyright Daan Goedkoop

#pragma once

#include <stdint.h>

extern "C"
{
   extern void sendNeopixelBuffer(uint32_t pin, uint8_t *data_address, uint16_t num_leds);
}

//! @brief Support for NeoPixel on BBC micro:bit
class neopixel_strip
{
public:
   //! @brief Initialise a NeoPixel strip
   //!
   //! Allocates memory and initialises the hardware.
   //!
   //! @note The initialisation will set the associated pin to low. After initialisation, one should wait a short
   //! while before sending the first update. Otherwise the initialisation can cause the device to interpret the
   //! value 1 for the first transferred bit (signifying a value of 128 for the green channel of the first LED).
   //!
   //! @param[in] pin_num  The pin to which the NeoPixel array is attached, e.g. MICROBIT_PIN_P0
   //! @param[in] num_leds The length of the NeoPixel array
   //!
   neopixel_strip(uint8_t pin_num, uint8_t num_leds);

   //! @brief Free allocated memory
   //!
   ~neopixel_strip();

   //! @brief Reset the value of all pixels to dark. Does not send an update.
   void clear();

   //! @brief Sets a pixel in the array to the specified colour
   //!
   //! @param[in] index The 0-based index of the pixel
   //! @param[in] red   The brightness of the red channel
   //! @param[in] green The brightness of the green channel
   //! @param[in] blue  The brightness of the blue channel
   //!
   //! @return false if the index was out of bounds
   //!
   bool set_color(uint8_t index, uint8_t red, uint8_t green, uint8_t blue);

   //! @brief Send the stored colour values to the hardware
   //!
   void send();

private:
   uint8_t m_pin_num;
   uint8_t m_num_leds;
   uint8_t *m_data;
};
