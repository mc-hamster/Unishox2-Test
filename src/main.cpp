

#include <Arduino.h>
extern "C"
{
#include "mesh/compression/unishox2.h"
}

void setup()
{

  delay(100);

  Serial.begin(115200);
  Serial.println("Meshtastic Compression Test");

  int ilen, olen;
  char out[100] = {0};
  char *in = (char *)"Hiiiiiiii! :) How are you doing? I am doing well.";

  ilen = strlen(in);
  olen = unishox2_compress_simple(in, ilen, out);

  Serial.println(ilen);
  Serial.println(in);
  Serial.println(olen);
  Serial.println(out);
}

void loop()
{
}