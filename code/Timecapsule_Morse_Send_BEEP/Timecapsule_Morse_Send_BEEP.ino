
/*

___________.__               _________                           .__          
\__    ___/|__| _____   ____ \_   ___ \_____  ______  ________ __|  |   ____  
  |    |   |  |/     \_/ __ \/    \  \/\__  \ \____ \/  ___/  |  \  | _/ __ \ 
  |    |   |  |  Y Y  \  ___/\     \____/ __ \|  |_> >___ \|  |  /  |_\  ___/ 
  |____|   |__|__|_|  /\___  >\______  (____  /   __/____  >____/|____/\___  >
                    \/     \/        \/     \/|__|       \/                \/ 
  PLAYAROUND2018 - Taipei, Taiwan

  ATTINY85 Pins  
  =============
                                 _______
                                |   U   |                                     
           (unused)  D5/A0  PB5-|       |- VCC  (3.7 - 5V)                          
         *SD-prog -> D3/A3  PB3-| ATTINY|- PB2  D2/A1 (unused)
                  (unused)  PB4-|   85  |- PB1  D1    BEEP
                            GND-|       |- PB0  D0 -> (unused)
                                |_______|

  * ATtiny workshop platform derived from 8BitMixtape by Marc "Dusjagr" Dusseiller & co.
    https://github.com/8BitMixtape

  * based on TinyAudioBoot and hex2wav by Chris Haberer, Fredrik Olofsson, Budi Prakosa
    https://github.com/ChrisMicro/AttinySound

  * Morse Code decoder by Achindra Bhatnagar
    https://www.hackster.io/achindra/morse-code-transceiver-b5ae38
     
*/

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define BEEPPIN 1

const char * MorseTable[] = {
        // space, !, ", #, $, %, &, '
        NULL, "-.-.--", ".-..-.", NULL, NULL, NULL, NULL, ".----.",
        // ( ) * + , - . /
        "-.--.", "-.--.-", NULL, ".-.-.", "--..--", "-....-", ".-.-.-", "-..-.",
        // 0 1 2 3 4 5 6 7
        "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...",
        // 8 9 : ; < = > ?
        "---..", "----.", "---...", "-.-.-.", NULL, "-...-", NULL, "..--..",
        // @ A B C D E F G
        ".--.-.", ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
        // H I J K L M N O
        "....", "..", ".---", "-.-", ".-..", "--", "-.", "---",
        // P Q R S T U V W
        ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--",

        };

const char message[] = " DONUT ";

int dotLength = 200;
int dashLength =dotLength*3;

void setup()
{
  pinMode(BEEPPIN, OUTPUT);
  digitalWrite(BEEPPIN, LOW);   // turn the LED on
  delay(2000);
  
}


void loop() {
  char ch;
  for(ch = 0; ch <sizeof(message); ch++){
    flashDashDot(MorseTable[message[ch]-32]);
    delay(dotLength*2);
  }
}

void flashDashDot(const char * morseCode)
{
  int i = 0;
  while(morseCode[i] != 0)
  {
    if(morseCode[i] == '.'){
      dot();
    } else if (morseCode[i] == '-'){
      dash();
    }
    i++;
  }
}

void dot()
{
  digitalWrite(BEEPPIN, HIGH);   // turn the BEEP on
  delay(dotLength);
  digitalWrite(BEEPPIN, LOW);   // turn the BEEP off
  delay(dotLength);
}

void dash()
{
  digitalWrite(BEEPPIN, HIGH);   // turn the BEEP on
  delay(dashLength);
  digitalWrite(BEEPPIN, LOW);   // turn the BEEP off
  delay(dotLength);
} 
