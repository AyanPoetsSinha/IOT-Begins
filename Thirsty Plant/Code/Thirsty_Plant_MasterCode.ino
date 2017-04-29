#include <LiquidCrystal.h>

#define length 16.0




// The following variables are part of a Moving Average filter that smooths
// the sensor values over 16 samples.
const int LENBUF = 16;
int sensebuffer[LENBUF];
int senseid = 0;



unsigned char b;  
int Contrast=50;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);   


// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  analogWrite(6,Contrast);
  lcd.begin(16, 2);
  Serial.begin(9600);
   pinMode(7, OUTPUT); //red led
   pinMode(8, OUTPUT); // green led
   
  
 
}

// the loop routine runs over and over again forever:
void loop() {
   String TweetWords;
   //taking the value from sensor to a variable
   int sensorValue= analogRead(A0);
   //converting the variable to the percentage 
   sensorValue=sensorValue-23;
   sensorValue=(sensorValue/10);
   sensorValue=100-sensorValue;
    unsigned char b;
    //for maintaining gap problem in the lcd occured at the time of production of the code
    
  for (int i =0;i<(length-b);i++)
  {
    lcd.print(" ");
  }
  //printing the sensor value to the monitor
   Serial.println(sensorValue);
   delay(100);
   //printing the first line of the lcd
   lcd.setCursor(0, 0);
   lcd.print("Moist Value:");
   lcd.print(sensorValue);
   lcd.print(" %");
   //putting delay to show it more brightly and changeing the value more frequently
   delay(100);
    //printing the Second line of the lcd
   lcd.setCursor(0, 1);
   //checking to see if the sensor value is greater than 48%
   if(sensorValue>=48 )
   {
    lcd.print(" I'm Moist");
    //8 is wired to green light. it will light up
    digitalWrite(8, HIGH);
    //7 is wired to red light. it will stay dim.
    digitalWrite(7, LOW);
    }
    else
    {
         //checking to see if the sensor value is less than 48% it will print thirsty message 
      lcd.print("I'm thirsty");
      //red light will light up
      digitalWrite(7, HIGH);
      //green will dim down.
      digitalWrite(8, LOW);
     }  
     
//end of the code
}




