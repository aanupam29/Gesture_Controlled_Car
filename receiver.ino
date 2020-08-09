#include <VirtualWire.h>
byte message[VW_MAX_MESSAGE_LEN];
byte messageLength = VW_MAX_MESSAGE_LEN;
int lm=9;
int lmr=8;
int rm=10;
int rmr=7;
int ledPin=13;
void setup()
{
 pinMode(ledPin,OUTPUT);
 pinMode(lm,OUTPUT);
 pinMode(lmr,OUTPUT);
 pinMode(rm,OUTPUT);
 pinMode(rmr,OUTPUT);
 vw_setup(2000);
 vw_rx_start();
}
void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
    if (vw_get_message(buf, &buflen))
    {
	int i;
	for (i = 0; i < buflen; i++)
	{
          if (buf[i]==0x73)//Stationary
          {
            digitalWrite(lm,LOW);  
            digitalWrite(lmr,LOW);
            digitalWrite(rm,LOW);
            digitalWrite(rmr,LOW);
            digitalWrite(ledPin,LOW);
          }
          else
          {
            if(buf[i]==0x66)//Forward
            {
              digitalWrite(lm,LOW);  
              digitalWrite(lmr,HIGH);
              digitalWrite(rm,HIGH);
              digitalWrite(rmr,LOW); 
              digitalWrite(ledPin,HIGH);
            }
            if (buf[i]==0x61)//Backward
            {
              digitalWrite(lm,HIGH);  
              digitalWrite(lmr,LOW);
              digitalWrite(rm,LOW);
              digitalWrite(rmr,HIGH);
              
              digitalWrite(ledPin,HIGH);
            }
            if (buf[i]==0x72)//Left 
            {
              digitalWrite(lm,LOW);  
              digitalWrite(lmr,LOW);
              digitalWrite(rm,HIGH);
              digitalWrite(rmr,LOW);
              digitalWrite(ledPin,HIGH);
            }     
            if (buf[i]==0x6C)//Right 
            {
              digitalWrite(lm,LOW);  
              digitalWrite(lmr,HIGH);
              digitalWrite(rm,LOW);
              digitalWrite(rmr,LOW);
              digitalWrite(ledPin,HIGH);
            }
           }   
	  }
        }
}
