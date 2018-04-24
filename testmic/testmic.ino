/****************************************
Example Sound Level Sketch for the 
Adafruit Microphone Amplifier

NOT THE SAME AS MEASURING FREQUENCY
Successfuly 4/17.. measured by clapping 
****************************************/
 
const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz) //change to 400 to see if it does anything 
unsigned int sample;
 
void setup() 
{
   Serial.begin(9600);
}
 
 
void loop() 
{
   unsigned long startMillis= millis();  // Start of sample window
   unsigned int peakToPeak = 0;   // peak-to-peak level
 
   unsigned int signalMax = 0;
   unsigned int signalMin = 1024;
 
   // collect data for 50 mS
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(A0);
      //DO NOT PRINT DIRECTLY FROM ANALOG READ, WILL RETURN A SHIT TON OF WING DINGS 
      if (sample < 1024)  // toss out spurious readings
      {
         if (sample > signalMax)
         {
            signalMax = sample;  // save just the max levels
         }
         else if (sample < signalMin)
         {
            signalMin = sample;  // save just the min levels
         }
      }
   }
   peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
   double volts = (peakToPeak * 5.0) / 1024;  // convert to volts
 
   Serial.println(volts);
}
