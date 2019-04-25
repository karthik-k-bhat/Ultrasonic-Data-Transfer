/* 4th Semester Mini -Project 
 *  Data Transmission using Ultrasonic Sound
 *    By  Shreyas R
 *        Praphul Gowda
 *        Karthik K Bhat
 *        
 *  Transmitter Code
 */

void setup() 
{
    Serial.begin(115200);
    pinMode(3,OUTPUT);
}

void loop() 
{
   send("Ultrasonic communication\n");
   send("Mini-Project\n\n");
   send("By Shreyas, Praphul, Karthik\n");   
}

void send(String msg)
{
   byte ch;
   unsigned int pos = 0;
   unsigned int sz = msg.length();
   while(pos<sz)
   {
      ch = msg.charAt(pos);
      //Serial.print((char)ch);
      tone(3,40000);
      delay(10);
      noTone(3);
      for(int i=0;i<8;i++)
      {
         boolean b;
         b = bitRead(ch,7-i);
         //Serial.println(b);
         if(b) 
         {
            tone(3,40000);
            delay(2);
            Serial.print(1);
            Serial.print('\n');
         }
         else
         {
            tone(3,40000);
            delay(4);
            Serial.print(0);
            Serial.print('\n');
         }
         noTone(3);
         delay(11);
      }
      pos++;
   }
}
