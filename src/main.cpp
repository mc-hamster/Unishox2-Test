

#include <Arduino.h>
extern "C" {
    #include "mesh/compression/unishox2.h"
}



void setup()
{
  Serial.begin(115200);
  Serial.println("Meshtastic Compression Test");


  int ilen,olen;
  char out[100]={0};
  char *in=(char*)"GPVTG,182.66,T,,M,0.002,N,0.004,K,A*30";

  ilen=strlen(in);
  olen=unishox2_compress_simple(in,ilen,out);

  Serial.println(ilen);
  Serial.println(in);
  Serial.println(olen);
  Serial.println(out);

}

void loop()
{
}