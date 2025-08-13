#include <U8g2lib.h>
#include <Wire.h>
#include "bitmap.h"

// Initialize the U8g2 library for SH1106 in I2C mode
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);



void setup() {
  // Initialize the display
  u8g2.begin();
  u8g2.clearBuffer(); // Clear the internal buffer

  // Set up a welcome message (optional)
  // u8g2.setFont(u8g2_font_ncenB08_tr); // Choose a font
  // u8g2.drawStr(10, 35, "C1PH3R-FSOCITEY"); // Draw a welcome message
  // u8g2.sendBuffer(); // Send the buffer to the display
  // delay(2000); // Pause for 2 seconds
  u8g2.drawXBMP(0, 0, 64, 64, bitmap_drive);

}

void loop() {
  // Clear the buffer
  u8g2.clearBuffer();

  // Draw the bitmap on the display
  u8g2.drawXBMP(0, 0, 64, 64, myBitmap);
  u8g2.setFont(u8g2_font_ncenB08_tr); // Choose a font
  u8g2.drawStr(70, 30, "C1PH3R"); // Draw a welcome message
  u8g2.drawStr(70, 40, "FSOCITEY"); // Draw a welcome message

  u8g2.sendBuffer(); // Send the buffer to the display

  // Send the buffer to the display
  u8g2.sendBuffer();

  // Pause to avoid refreshing too quickly
  delay(1000);
}
