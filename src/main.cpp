

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

  int orig_len, compressed_len;
  char compressed_out[100] = {0};
  char *orig = (char *)"Hiiiiiiii! :) How are you doing? I am doing well.";
  //char *orig = (char *)"Meshtastic";

  orig_len = strlen(orig);
  compressed_len = unishox2_compress_simple(orig, orig_len, compressed_out);

  Serial.println(orig_len);
  Serial.println(orig);
  Serial.println(compressed_len);
  Serial.println(compressed_out);

  char decompressed_out[100] = {};
  int decompressed_len;

  decompressed_len = unishox2_decompress_simple(compressed_out, compressed_len, decompressed_out);

  Serial.println(decompressed_len);
  Serial.println(decompressed_out);
}

void loop()
{
}