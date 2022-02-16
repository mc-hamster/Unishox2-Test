/** NimBLE_Secure_Server Demo:
 *
 * This example demonstrates the secure passkey protected conenction and communication between an esp32 server and an esp32 client.
 * Please note that esp32 stores auth info in nvs memory. After a successful connection it is possible that a passkey change will be ineffective.
 * To avoid this clear the memory of the esp32's between security testings. esptool.py is capable of this, example: esptool.py --port /dev/ttyUSB0 erase_flash.
 *
 *  Created: on Jan 08 2021
 *      Author: mblasee
 */

#include <Arduino.h>
#include "mesh/compression/unishox2.h"


void setup()
{
  Serial.begin(115200);
  Serial.println("Meshtastic Compression Test");


  char *message[] = {"Hello friends!"};
  uint32_t len = 20;
  char *output[] = {};
  int result = unishox2_compress_simple(*message, len, *output);
  Serial.println(*message);
  Serial.println(*output);
}

void loop()
{
}