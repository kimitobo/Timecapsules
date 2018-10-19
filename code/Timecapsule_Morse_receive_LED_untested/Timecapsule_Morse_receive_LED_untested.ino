
/*
___________.__               _________                           .__          
\__    ___/|__| _____   ____ \_   ___ \_____  ______  ________ __|  |   ____  
  |    |   |  |/     \_/ __ \/    \  \/\__  \ \____ \/  ___/  |  \  | _/ __ \ 
  |    |   |  |  Y Y  \  ___/\     \____/ __ \|  |_> >___ \|  |  /  |_\  ___/ 
  |____|   |__|__|_|  /\___  >\______  (____  /   __/____  >____/|____/\___  >
                    \/     \/        \/     \/|__|       \/                \/ 
  PLAYAROUND2018 - Taipei, Taiwan
  
  TimeCapsule by @kimitobo

  ATTINY85 Pins
  =============
                                 _______
                                |   U   |                                     
           (unused)  D5/A0  PB5-|       |- VCC  (3.7 - 5V)                          
         *SD-prog -> D3/A3  PB3-| ATTINY|- PB2  D2/A1 LDR
         (unused) -> D4/A2  PB4-|   85  |- PB1  D1    LED
                            GND-|       |- PB0  D0 -> (unused)
                                |_______|

  * ATtiny workshop platform derived from 8BitMixtape by Marc "Dusjagr" Dusseiller & co.
    https://github.com/8BitMixtape

  * based on TinyAudioBoot and hex2wav by Chris Haberer, Fredrik Olofsson, Budi Prakosa
    https://github.com/ChrisMicro/AttinySound

  * Morse Code decoder by Achindra Bhatnagar
    https://www.hackster.io/achindra/morse-code-transceiver-b5ae38

    Morse Code Binary Tree
    Left child at 2n+1
    Right child at 2n+2
             <.|->
          .E       -T
        .I  -A   .N  -M

*********************************************************************************************************
  
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.


*/

#ifdef __AVR__
#include <avr/power.h>
#endif

#define LEDPIN 1
#define LDRPIN A2

// #include <SoftwareSerial.h>
// SoftwareSerial swSerial(5, 2); // (RX), TX (RX not used)

const char MorseTree[] = {'\0','E', 'T', 'I', 'A', 'N', 'M', 'S',
                          'U', 'R', 'W', 'D', 'K', 'G', 'O', 'H',
                          'V', 'F', 'U', 'L', 'A', 'P', 'J', 'B',
                          'X', 'C', 'Y', 'Z', 'Q', '\0','\0','5',
                          '4', '\0','3', '\0','\0','\0','2', '\0',
                          '\0','+', '\0','\0','\0','\0','1', '6',
                          '=', '/', '\0','\0','\0','(', '\0','7',
                          '\0','\0','\0','8', '\0','9', '0', '\0',
                          '\0','\0','\0','\0','\0','\0','\0','\0',
                          '\0','\0','\0','?', '_', '\0','\0','\0',
                          '\0','"', '\0','\0','.', '\0','\0','\0',
                          '\0','@', '\0','\0','\0','\0','\0','\0',
                          '-', '\0','\0','\0','\0','\0','\0','\0',
                          '\0',';', '!', '\0',')', '\0','\0','\0',
                          '\0','\0',',', '\0','\0','\0','\0',':',
                          '\0','\0','\0','\0','\0','\0','\0'
                         };
int val = 0; // A Variable to Store the Light Value from the LDR
int ctrHigh = 0;
int ctrLow = 0;
int codePtr = 0;
int dotLen = 200;

void setup()
{
  //swSerial.begin(9600);   
  //swSerial.print(codePtr);
  pinMode(LEDPIN, OUTPUT);
  pinMode(LDRPIN, INPUT);  

}

void loop()
{
  val = analogRead(LDRPIN);
  if (val >= 100)
  {
    ctrHigh++;
    ctrLow = 0;
    digitalWrite(LEDPIN, HIGH);
  } else {
    ctrLow++;
    if ((ctrHigh >= dotLen) && (ctrHigh < dotLen*2)) {
      //swSerial.print(".");
      codePtr = (2*codePtr) + 1;
    } else if (ctrHigh >= dotLen * 2) {
      //swSerial.print("-");
      codePtr = (2*codePtr) + 2;
    } else {
      if(ctrLow == dotLen*2){
        //swSerial.print(MorseTree[codePtr]);
        codePtr = 0;
      }
    }
    ctrHigh = 0;
    digitalWrite(LEDPIN, LOW);
    //noTone(9);
  }
}

