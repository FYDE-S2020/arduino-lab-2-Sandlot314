/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP32 chip.

  Note: This requires ESP32 support package:
    https://github.com/espressif/arduino-esp32

  Please be sure to select the right ESP32 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#define LED 2

const int freq = 5000;     // 5KHz frequency is more than enough. Remember we used 100 before.
const int ledChannel = 0;  // You can have up to 16 pwm channels (0 to 15)
const int resolution = 10; // 10 bit resolution for 1023. Freq should be greater than resolution.
int ledState;
int sliderState = 1023;
int time_count = 0; // timer counter global variable
String content = "";  // null string constant ( an empty string )
BlynkTimer timer;

char input;// to save the input

// Note the different pin setup function!

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "P0g1Q66MlSogqziPxv-M74rPvuQWm24m";

// Your WiFi credentials.
// Set password to "" for open networks.
// The EE IOT network is hidden. You might not be able to see it.
// But you should be able to connect with these credentials. 
char ssid[32] = "utguest";
char pass[32] = "";

void setup()
{
  // Serial Monitor
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  
    // configure LED PWM functionality
    ledcSetup(ledChannel, freq, resolution);

    // attach the channel to the GPIO to be controlled
    ledcAttachPin(LED, ledChannel);


    timer.setInterval(10L, myTimerEvent); // 10 ms interval
    
}


BLYNK_WRITE(V1)
{

    // param is a member variable of the Blynk ADT. It is exposed so you can read it.
    int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
    ledState == pinValue;
    // Because V1 is a button, pinValue will be a 0 or a 1.
    if (pinValue == 0) {
        ledcWrite(ledChannel, 0);// turn LED off
    }
    else {
        ledcWrite(ledChannel, sliderState);// turn LED on
    }
}

// If virtual pin 2 controls fade value, 0 to 1023.
BLYNK_WRITE(2)
{
    // param is a member variable of the Blynk ADT. It is exposed so you can read it.
    int val = param.asInt(); // assigning incoming value from pin V1 to a variable
    sliderState = val;
    if(ledState = 1){
    ledcWrite(ledChannel, val); // Note that this takes ledChannel as an argument, NOT the pin! Set duty = val.
    }
}
// This function is executed whenever Blynk pin V5 requests data from the ESP32
BLYNK_READ(V5) // Widget in the app READS Virtal Pin V5 with the certain frequency
{
    // This command writes Arduino's uptime in seconds to Virtual Pin V5
    Blynk.virtualWrite(V5, millis() / 1000);
}

void myTimerEvent() // Every 10 ms
{
    if (time_count % 25 == 0) { // every 250 ms
        // Do thing that needs to happen every 0.25 seconds
    }
    if (time_count == 100){
        // Do thing that needs to happen every 1 second
        time_count = 0; // reset time counter
    }
    else {
        // Send serial data to Blynk terminal
        char character;
        while(Serial.available()) { // Check if serial is available every 10 ms
            character = Serial.read();
            content.concat(character);
        }
        if (content != "") {
            Blynk.virtualWrite(V3, content);
            content = ""; // Clear String
        }  
    }
    time_count += 1; // Increment on every tick
}
//morse_code by LED
/*
  This code was written by Ebrahim Bawazir in 2013 and updated in 2015
          U R FREE TO USE IT AND MODIFY IT AS U WANT
                      *****************
*/



void loop()
{
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
   if (Serial.available()) {
    input = Serial.read();//read the input
    if (input == 'a' || input == 'A') {lA();}//if the input is a or A go to function lA
    if (input == 'b' || input == 'B') {lB();}//same but with b letter
    if (input == 'c' || input == 'C') {lC();}
    if (input == 'd' || input == 'D') {lD();}
    if (input == 'e' || input == 'E') {lE();}
    if (input == 'f' || input == 'F') {lF();}
    if (input == 'g' || input == 'G') {lG();}
    if (input == 'h' || input == 'H') {lH();}
    if (input == 'i' || input == 'I') {lI();}
    if (input == 'j' || input == 'J') {lJ();}
    if (input == 'k' || input == 'K') {lK();}
    if (input == 'l' || input == 'L') {lL();}
    if (input == 'm' || input == 'M') {lM();}
    if (input == 'n' || input == 'N') {lN();}
    if (input == 'o' || input == 'O') {lO();}
    if (input == 'p' || input == 'P') {lP();}
    if (input == 'q' || input == 'Q') {lQ();}
    if (input == 'r' || input == 'R') {lR();}
    if (input == 's' || input == 'S') {lS();}
    if (input == 't' || input == 'T') {lT();}
    if (input == 'u' || input == 'U') {lU();}
    if (input == 'v' || input == 'V') {lV();}
    if (input == 'w' || input == 'W') {lW();}
    if (input == 'x' || input == 'X') {lX();}
    if (input == 'y' || input == 'Y') {lY();}
    if (input == 'z' || input == 'Z') {lZ();}
    if (input == '1') {n1();}// the numbers
    if (input == '2') {n2();}
    if (input == '3') {n3();}
    if (input == '4') {n4();}
    if (input == '5') {n5();}
    if (input == '6') {n6();}
    if (input == '7') {n7();}
    if (input == '8') {n8();}
    if (input == '9') {n9();}
    if (input == '0') {n0();}
    if (input == ' ') {space();}//the space
    Serial.println (input);//print the latter saved in the input var
    
  }
}
//fonctions for the letters and the numbers
void lA () {dot();dash();shortspace();}//letter A in morse code!
void lB () {dash();dot();dot();dot();shortspace();}//same for B
void lC () {dash();dot();dash();dot();shortspace();}
void lD () {dash();dot();dot();shortspace();}
void lE () {dot();shortspace();}
void lF () {dot();dot();dash();dot();shortspace();}
void lG () {dash();dash();dot();shortspace();}
void lH () {dot();dot();dot();dot();shortspace();}
void lI () {dot();dot();shortspace();}
void lJ () {dot();dash();dash();dash();shortspace();}
void lK () {dash();dot();dash();shortspace();}
void lL () {dot();dash();dot();dot();shortspace();}
void lM () {dash();dash();shortspace();}
void lN () {dash();dot();shortspace();}
void lO () {dash();dash();dash();shortspace();}
void lP () {dot();dash();dash();dot();shortspace();}
void lQ () {dash();dash();dot();dash();shortspace();}
void lR () {dot();dash();dot();shortspace();}
void lS () {dot();dot();dot();shortspace();}
void lT () {dash();shortspace();}
void lU () {dot();dot();dash();shortspace();}
void lV () {dot();dot();dot();dash();shortspace();}
void lW () {dot();dash();dash();shortspace();}
void lX () {dash();dot();dot();dash();shortspace();}
void lY () {dash();dot();dash();dash();shortspace();}
void lZ () {dash();dash();dot();dot();shortspace();}
void n1 () {dot();dash();dash();dash();dash();shortspace();}//number 1 in morse code
void n2 () {dot();dot();dash();dash();dash();shortspace();}
void n3 () {dot();dot();dot();dash();dash();shortspace();}
void n4 () {dot();dot();dot();dot();dash();shortspace();}
void n5 () {dot();dot();dot();dot();dot();shortspace();}
void n6 () {dash();dot();dot();dot();dot();shortspace();}
void n7 () {dash();dash();dot();dot();dot();shortspace();}
void n8 () {dash();dash();dash();dot();dot();shortspace();}
void n9 () {dash();dash();dash();dash();dot();shortspace();}
void n0 () {dash();dash();dash();dash();dash();shortspace();}
void space () {delay (1200);}//space between words
void dot () {digitalWrite(ledChannel,HIGH); delay (300); digitalWrite(ledChennel,LOW); delay (300);}//the dot this code make the led on for 300 than off for 300
void dash () {digitalWrite(ledChennel,HIGH); delay (900); digitalWrite(ledChennel,LOW); delay (300);}//the dash this code make the led on for 900 than off for 300
void shortspace () {delay(600);}//space between letters
