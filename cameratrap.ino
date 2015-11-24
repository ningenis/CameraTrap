#include <Servo.h>

Servo myservo; // inisialisasi objek servo
int angle = 0; // variabel untuk menyimpan nilai sudut servo
// Setting PIR    
int interval = 500; // Interval untuk satu fungsi void loop
int pirPin = 3;    // Pin digital ke sensor PIR

void setup() {
  myservo.attach(9); // Pin 9 untuk servo
  // Deklarasi Pin untuk PIR
  pinMode(pirPin, INPUT);
}

void loop() {
  int val = digitalRead(pirPin);
  if (val == HIGH)
    {
          for(angle = 0; angle < 45; angle += 1) // memutar servo 45 derajat
          { 
            myservo.write(angle); // gerakan servo sesuai posisi sudut
            delay(20); // delay 20 ms/command
          }
          for(angle = 45; angle >= 1; angle -= 1) // memutar balik servo 45 derajat
          {
            myservo.write(angle); // gerakan servo ke arah berlawanan
            delay(20); // delay 20 ms/command
          } 
     } 
  delay(interval);  
}
