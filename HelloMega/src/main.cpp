#include <Arduino.h>

//                   A0                                                          A15
const char ADDR[] = {22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52};
//                   D0                          D7
const char DATA[] = {39, 41, 43, 45, 47, 49, 51, 53};

#define CLOCK 2
#define READ_WRITE 3

void onClock()
{
  unsigned int address = 0;

  for (int i = 0; i < 16; i++)
  {
    unsigned int bit = digitalRead(ADDR[i]) ? 1 : 0;
    Serial.print(bit);
    address = (address << 1) + bit;
  }

  Serial.print(" :: ");

  unsigned int data = 0;
  for (int i = 0; i < 8; i++)
  {
    unsigned int bit = digitalRead(DATA[i]) ? 1 : 0;
    Serial.print(bit);
    data = (data << 1) + bit;
  }

  char buffer[32];
  // sprintf(buffer, "    %04X  %c %02X", address, digitalRead(READ_WRITE) ? 'r' : 'W', data);
  sprintf(buffer, " %c", digitalRead(READ_WRITE) ? 'r' : 'W');
  Serial.print(buffer);

  Serial.println();
}

void setup()
{
  // put your setup code here, to run once:
  for (int i = 0; i < 16; i++)
  {
    pinMode(ADDR[i], INPUT);
  }

  for (int i = 0; i < 8; i++)
  {
    pinMode(DATA[i], INPUT);
  }

  pinMode(CLOCK, INPUT);
  pinMode(READ_WRITE, INPUT);

  // attachInterrupt(digitalPinToInterrupt(CLOCK), [](){}, RISING);
  // E clock is valid on the rising edge
  attachInterrupt(digitalPinToInterrupt(CLOCK), onClock, FALLING);

  // pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(115200);
}

void loop()
{
  // put your main code here, to run repeatedly:
  // Serial.println("Running!");

  // digitalWrite(LED_BUILTIN, HIGH);
  // delay(500);
  // digitalWrite(LED_BUILTIN, LOW);
  // delay(500);
}