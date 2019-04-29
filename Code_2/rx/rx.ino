/* 4th Semester Mini -Project 
 *  Data Transmission using Ultrasonic Sound
 *    By  Shreyas R
 *        Praphul Gowda
 *        Karthik K Bhat
 *        
 *  Receiver Code
 */
int pos = 0;
unsigned char CH = 0;
unsigned int bits1 = 0;
boolean capture = false;
unsigned long start_time = 0;
unsigned long transmission_time = 0;
unsigned int transmission_speed = 0;
unsigned int char_count = 0;

void setup() 
{
   Serial.begin(115200);
   pinMode(5,INPUT_PULLUP);
}
int max_time = 0;
int min_time = 1500;
void loop() 
{
   if(digitalRead(5))
   {
      bits1 = 0;
      unsigned long deltaT = millis();
      while(millis()-deltaT <= 10) if(digitalRead(5)) bits1 ++;
      //Serial.println(bits1);
      if (bits1 > max_time)
      {
         max_time = bits1;
      }
      if (bits1 <min_time)
      {
        min_time = bits1;
      }
      if(capture)
      {
         boolean b = 0;
         if(bits1 > 250 && bits1 < 600) b = 0;
         if(bits1 > 75 && bits1 < 250) b = 1;
         if(b) bitSet(CH,7-pos); else bitClear(CH,7-pos);
         //Serial.print(b);
         //Serial.print('\n');
         //Serial.print(b);
         pos++;
         if(pos == 8)
         {
            Serial.print((char)CH);
            if ((char)CH == '#')
            {
               start_time = millis();
               transmission_speed = 0;
               char_count = 0;
               char_count ++;
            }
            else if ((char)CH == '&')
            {
               transmission_time = millis() - start_time;
               transmission_speed = char_count*8*1000/transmission_time;
               Serial.print("\n\nTransmission Speed: ");
               Serial.print(transmission_speed);
               Serial.println(" characters per second.\n");
            }
            else
            {
               char_count++;
            }
               
            pos = 0;
            capture = false;
         }
      }
      if(bits1 > 600) 
      {
         capture = true;
         pos = 0;
      }
      /*Serial.print("Max Time: ");
      Serial.println(max_time);
      Serial.print("Min Time: ");
      Serial.println(min_time);
      */
   }
}
