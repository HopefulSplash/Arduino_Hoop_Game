#include <SPI.h>
#include <SD.h>
#include <pcmConfig.h>
#include <pcmRF.h>
#include <TMRpcm.h>

//SD card pin
#define SD_ChipSelectPin 10
//soundplayer object
TMRpcm tmrpcm;
int startPin = 0;



int Pin = 15;
int Pin1 = 16;
int Pin2 = 17;
int Pin3 = 18;
int Pin4 = 19;
int Pin5 = 14;


int ledPin = 2;
int ledPin2 = 3;
int ledPin3 = 4;
int ledPin4 = 5;
int ledPin5 = 6;
int ledPin6 = 7;


int sensorValue = digitalRead(Pin);
int sensorValue1 = digitalRead(Pin1);
int sensorValue2 = digitalRead(Pin2);
int sensorValue3 = digitalRead(Pin3);
int sensorValue4 = digitalRead(Pin4);
int sensorValue5 = digitalRead(Pin5);

int randNumber = random(0, 7);

int tempNumber = 9;


void setup() {


  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);


  pinMode(Pin, INPUT);
  pinMode(Pin1, INPUT);
  pinMode(Pin3, INPUT);
  pinMode(Pin2, INPUT);
  pinMode(Pin4, INPUT);
  pinMode(Pin5, INPUT);

  pinMode(startPin, INPUT);

  // Open serial communications and wait for port to open:
  Serial.begin(9600);

  randomSeed(analogRead(A0));

  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    while (1);
  }

  digitalWrite(ledPin, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin4, HIGH);
  digitalWrite(ledPin5, HIGH);
  digitalWrite(ledPin6, HIGH);


  int startPinVal = digitalRead(startPin);
  while (startPinVal == HIGH) {
    startPinVal = digitalRead(startPin);
    delay (1);
  }


  digitalWrite(ledPin, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);
  digitalWrite(ledPin5, LOW);
  digitalWrite(ledPin6, LOW);


  randNumber = random(0, 7);
  tempNumber = 9;

  delay(8000);

  //setup sound
  tmrpcm.speakerPin = 9;
  tmrpcm.quality(2);
  tmrpcm.setVolume(4);
  //play setup sound (user knows the hoop is ready)
  playSound(1);
  tmrpcm.disable();
  tmrpcm.stopPlayback();

  delay(1500);
}

void playSound(int t) {

  char q[] = "1.wav";
  char q1[] = "2.wav";
  char q2[] = "3.wav";

  tmrpcm.disable();
  tmrpcm.stopPlayback();

  if (t == 1) {
    tmrpcm.setVolume(4);
    tmrpcm.play(q);
    delay(4050); //time of clip
  }

  if (t == 2) {
    tmrpcm.setVolume(4);
    tmrpcm.play(q1);
    delay(850); //time of clip
  }


  if (t == 3) {
    tmrpcm.setVolume(4);
    tmrpcm.play(q2);
    delay(386); //time of clip
  }
  tmrpcm.disable();
  tmrpcm.stopPlayback();

  return;
}
void checkRan(int i) {
  if (i == tempNumber) {
    randNumber = random(0, 7);
  }
}

void loop() {

  sensorValue = digitalRead(Pin);
  sensorValue1 = digitalRead(Pin1);
  sensorValue2 = digitalRead(Pin2);
  sensorValue3 = digitalRead(Pin3);
  sensorValue4 = digitalRead(Pin4);
  sensorValue5 = digitalRead(Pin5);



  tempNumber = randNumber;
  randNumber = random(0, 7);



  while (randNumber == tempNumber) {

    checkRan(randNumber);

  }

  if (randNumber == 0) {
    if (sensorValue == LOW) {
      playSound(2);
      tmrpcm.disable();
      tmrpcm.stopPlayback();
      digitalWrite(ledPin, HIGH);
      while (sensorValue == LOW) {
        sensorValue = digitalRead(Pin);
      } //Serial.println("0 Motion");
      playSound(3);
      tmrpcm.disable();
      tmrpcm.stopPlayback();
      digitalWrite(ledPin, LOW);
      delay(random(1000, 3000));
    }
  }
  if (randNumber == 1) {
    if (sensorValue1 == LOW) {
      playSound(2);
      tmrpcm.disable();
      tmrpcm.stopPlayback();
      digitalWrite(ledPin2, HIGH);
      while (sensorValue1 == LOW) {
        sensorValue1 = digitalRead(Pin1);
      } //Serial.println("1 Motion");
      playSound(3);
      tmrpcm.disable();
      tmrpcm.stopPlayback();
      digitalWrite(ledPin2, LOW);
      delay(random(1000, 3000));
    }
  }

  if (randNumber == 2) {
    if (sensorValue2 == LOW) {
      playSound(2);
      tmrpcm.disable();
      tmrpcm.stopPlayback();
      digitalWrite(ledPin3, HIGH);
      while (sensorValue2 == LOW) {
        sensorValue2 = digitalRead(Pin2);
      }// Serial.println("2 Motion");
      playSound(3);
      tmrpcm.disable();
      tmrpcm.stopPlayback();
      digitalWrite(ledPin3, LOW);
      delay(random(1000, 3000));
    }
  }

  if (randNumber == 3) {
    if (sensorValue3 == LOW) {
      playSound(2);
      tmrpcm.disable();
      tmrpcm.stopPlayback();
      digitalWrite(ledPin4, HIGH);
      while (sensorValue3 == LOW) {
        sensorValue3 = digitalRead(Pin3);
      }// Serial.println("3 Motion");
      playSound(3);
      tmrpcm.disable();
      tmrpcm.stopPlayback();
      digitalWrite(ledPin4, LOW);
      delay(random(1000, 3000));
    }
  }

  if (randNumber == 4) {
    if (sensorValue4 == LOW) {
      playSound(2);
      tmrpcm.disable();
      tmrpcm.stopPlayback();
      digitalWrite(ledPin5, HIGH);
      while (sensorValue4 == LOW) {
        sensorValue4 = digitalRead(Pin4);
      } //Serial.println("4 Motion");
      playSound(3);
      tmrpcm.disable();
      tmrpcm.stopPlayback();
      digitalWrite(ledPin5, LOW);
      delay(random(1000, 3000));
    }
  }

  if (randNumber == 5) {
    if (sensorValue5 == LOW) {
      playSound(2);
      tmrpcm.disable();
      tmrpcm.stopPlayback();
      digitalWrite(ledPin6, HIGH);
      while (sensorValue5 == LOW) {
        sensorValue5 = digitalRead(Pin5);
        delay(100);
      } //Serial.println("5 Motion");
      playSound(3);
      tmrpcm.disable();
      tmrpcm.stopPlayback();
      digitalWrite(ledPin6, LOW);
      delay(random(1000, 3000));
    }
  }
}
