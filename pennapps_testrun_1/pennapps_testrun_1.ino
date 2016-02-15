/*

   Udemy.com
   Using Photoresistors (LDRs) with an Arduino

*/

// pin assignments
int LED = 13;
int LDR1 = 0;
int LDR2 = 1;
int LDR3 = 2;
int LDR4 = 3;
int LDR5 = 4;
int LDR6 = 5;
int flag1 = 1;
int flag2 = 1;
int flag3 = 1;
int flag4 = 1;
int flag5 = 1;
int flag6 = 1;

// variables
int base1;
int base2;
int base3;
int base4;
int base5;
int base6;
int threshold2 = 10;
int score = 0;

// declare inputs and outputs
// and take a baseline reading
void setup() {
  pinMode(LED, OUTPUT);
  pinMode(LDR1, INPUT);
  pinMode(LDR2, INPUT);
  pinMode(LDR3, INPUT);
  pinMode(LDR4, INPUT);
  pinMode(LDR5, INPUT);
  pinMode(LDR6, INPUT);
  base1 = analogRead(LDR1);
  base2 = analogRead(LDR2);
  base3 = analogRead(LDR3);
  base4 = analogRead(LDR4);
  base5 = analogRead(LDR5);
  base6 = analogRead(LDR6);
  Serial.begin(9600);

}

// read from the analog input connected to the LDR
// and print the value to the serial port.
// the delay is only to avoid sending so much data
// as to make it unreadable.
void loop() {
  int v1 = analogRead(LDR1);
  int v2 = analogRead(LDR2);
  int v3 = analogRead(LDR3);
  int v4 = analogRead(LDR4);
  int v5 = analogRead(LDR5);
  int v6 = analogRead(LDR6);
  delay(250);

if ((base1 - v1) > threshold2) {
    if (flag1 == 1) {
      score = score + 20;
      flag1 = 0;
      Serial.println(score);
    }
  }
  else {
  flag1 = 1;
  }

  if ((base2 - v2) > threshold2) {
    if (flag2 == 1) {
      score = score + 40;
      flag2 = 0;
      Serial.println(score);
    }
  }
  else {
    flag2 = 1;
  }

  if ((base3 - v3) > threshold2) {
    if (flag3 == 1) {
      score = score + 60;
      flag3 = 0;
      Serial.println(score);
    }
  }
  else {
    flag3 = 1;
  }

  if ((base4 - v4) > threshold2) {
    if (flag4 == 1) {
      score = score + 80;
      flag4 = 0;
      Serial.println(score);
    }
  }
  else {
    flag4 = 1;
  }

  if ((base5 - v5) > threshold2) {
    if (flag5 == 1) {
      score = score + 100;
      flag5 = 0;
      Serial.println(score);
    }
  }
  else {
    flag5 = 1;
  }

  if ((base6 - v6) > threshold2) {
    if (flag6 == 1) {
      score = score + 5;
      flag6 = 0;
      Serial.println(score);
    }
  }
  else {
    flag6 = 1;
  }
}
