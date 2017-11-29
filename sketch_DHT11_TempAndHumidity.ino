// Created by team PejalanKaki (Brain, Hafizh, Nobel, Reyhan, Yoga)
// PRD I
// Reference: Arduino Project Hub

#include <DHT.h>                       //include DHTxx Library
#include <LiquidCrystal.h>                   //include LCD Library

#define DHTPIN A1                      //dht signal on Analog (digital hybrid) pin A1
#define DHTTYPE DHT11                     // DHT 11, blue one
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2; //define pin being used by LCD
const int buttonPin = 13;                //define pin being used by button

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);    //assign pin being used by LCD

//variable
int buttonState = 0;
int silent = 0;

void setup() {
  pinMode(9, OUTPUT); //set buzzer - pin 9 as an output
  //set both LED (Green and Red) as output
  pinMode(A0, OUTPUT);
  pinMode(A5, OUTPUT);
  //set button as input
  pinMode(buttonPin, INPUT);
  dht.begin();
    // set up the LCD's number of columns and rows:
    // variety of delays are intended for aesthetical purpose
    // we also add tones to make a 'booting' sound
  lcd.begin(16, 2);
  tone(9, 100);
  lcd.setCursor(0, 0);
  lcd.print("Hello");
  delay(500);
  tone(9, 2000);
  delay(500);
  tone(9, 500);
  delay(500);
  tone(9, 1000);
  delay(500);
  noTone(9);
  lcd.setCursor(0, 1);
  lcd.print("FromTheOtherSide");
  delay(2000);            // 2 secs delay
  lcd.clear();            // clear the lcd
  
}

void loop() {
  // Read the sta te of the pushbutton value
  buttonState = digitalRead(buttonPin);
  
  // button pressed condition
  if(buttonState == HIGH){
    //enter silent mode
    if(silent == 0){
      tone(9, 2000);
      silent = 1;
      delay(100);
      noTone(9);
      lcd.clear();
      lcd.print("Silent mode");
      lcd.setCursor(0, 1);
      lcd.print("Activated!");
      delay(2000);  
      lcd.clear();    
    }
    //cancel the silent mode
    else if(silent == 1){
      tone(9, 2000);
      silent = 0;
      delay(100);
      noTone(9);
      lcd.clear();
      lcd.print("Silent mode");
      lcd.setCursor(0, 1);
      lcd.print("Dectivated!");
      delay(2000);
      lcd.clear();   
    }
  }
  
  // Wait for a second between measurements.
  delay(1000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  //print the final measurement to LCD Output
  lcd.setCursor(0, 0);
  lcd.print("Humid.: ");
  lcd.setCursor(8, 0);
  lcd.print(h);
  lcd.print(char(37));       //percentage symbol
  lcd.setCursor(0, 1);
  lcd.print("Temp. : ");
  lcd.setCursor(8, 1);
  lcd.print(t);
  lcd.print((char)223);       // degree symbol
  lcd.print("C");          // C character

  if (t > 27) {
    //blink the LED on PIN A0 if the temperature is greater than 27 degrees Celcius
    if (silent == 0){
      digitalWrite(A0, HIGH);     // turn the LED on (HIGH is the voltage level)
      tone(9, 100);           //send 100Hz sound signal
      delay(500);             // wait for half a second (500ms)
      
        // Read the state of the pushbutton value
      buttonState = digitalRead(buttonPin);
  
       // button pressed condition
      if(buttonState == HIGH){
       //enter silent mode
      if(silent == 0){
        tone(9, 2000);
        silent = 1;
        delay(100);
        noTone(9);
        lcd.clear();
        lcd.print("Silent mode");
        lcd.setCursor(0, 1);
        lcd.print("Activated!");
        delay(2000);  
        lcd.clear();    
      }
      //cancel the silent mode
     else if(silent == 1){
        tone(9, 2000);
        silent = 0;
        delay(100);
        noTone(9);
        lcd.clear();
        lcd.print("Silent mode");
        lcd.setCursor(0, 1);
        lcd.print("Dectivated!");
        delay(2000);
        lcd.clear();   
        }
      }
      
      digitalWrite(A0, LOW);      // turn the LED off by making the voltage LOW
      noTone(9);                 // stop sound
      delay(500);              // wait for half a second (500ms)
    }
    
    else if (silent == 1){
      digitalWrite(A0, HIGH); // turn the LED on (HIGH is the voltage level)
      delay(500);               // wait for half a second (500ms)
      // Read the state of the pushbutton value
      buttonState = digitalRead(buttonPin);
       // button pressed condition
      if(buttonState == HIGH){
       //enter silent mode
       if(silent == 0){
        tone(9, 2000);
        silent = 1;
        delay(100);
        noTone(9);
        lcd.clear();
        lcd.print("Silent mode");
        lcd.setCursor(0, 1);
        lcd.print("Activated!");
        delay(2000);  
        lcd.clear();    
       }
      //cancel the silent mode
       else if(silent == 1){
        tone(9, 2000);
        silent = 0;
        delay(100);
        noTone(9);
        lcd.clear();
        lcd.print("Silent mode");
        lcd.setCursor(0, 1);
        lcd.print("Dectivated!");
        delay(2000);
        lcd.clear();   
       }
      }
      
      digitalWrite(A0, LOW);    // turn the LED off by making the voltage LOW
      delay(500);           // wait for half a second (500ms)    
    }
  }
  else if (t <= 27) {
	 //blink green LED
    digitalWrite(A5, HIGH);    // turn the LED on (HIGH is the voltage level)
    delay(500);                  // wait for half a second (500ms)
    
     // Read the state of the pushbutton value
      buttonState = digitalRead(buttonPin);
  
       // button pressed condition
      if(buttonState == HIGH){
       //enter silent mode
      if(silent == 0){
        tone(9, 2000);
        silent = 1;
        delay(100);
        noTone(9);
        lcd.clear();
        lcd.print("Silent mode");
        lcd.setCursor(0, 1);
        lcd.print("Activated!");
        delay(2000);  
        lcd.clear();    
        }
      //cancel the silent mode
     else if(silent == 1){
        tone(9, 2000);
        silent = 0;
        delay(100);
        noTone(9);
        lcd.clear();
        lcd.print("Silent mode");
        lcd.setCursor(0, 1);
        lcd.print("Dectivated!");
        delay(2000);
        lcd.clear();   
        }
      }
      
    digitalWrite(A5, LOW);       // turn the LED off by making the voltage LOW
    delay(500); 
    }
}
  
