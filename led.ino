#include <FastLED.h>

#define LED_PIN 7
#define NUM_LEDS 25
#define buttonPIN 2

int counter = 1;
bool isNewMode = false;

const int microphonePin = A0;
CRGB leds[NUM_LEDS];

int numRed = 4;
int numGreen = 4;
int numWhite = 1;
int numYellow = 3;
int numBrown = 4;
int numGray = 3;

int numRed2 = 3;
int numGreen2 = 3;
int numWhite2 = 1;
int numYellow2 = 2;
int numBrown2 = 3;
int numGray2 = 2;
int numBlue2 = 5;

CRGB noColor = CRGB(0, 0, 0);
CRGB red = CRGB(255, 0, 0);
CRGB blue = CRGB(0, 0, 255);
CRGB white = CRGB(128, 0, 128);
CRGB yellow = CRGB(255, 255, 0);
//CRGB brown=  CRGB(50,255,50);
CRGB brown = CRGB(40, 255, 40);  //at start this one was brown for wood, now is dark green
CRGB green = CRGB(0, 25, 0);
CRGB gray = CRGB(178, 255, 232);

char options[6][50] = { "red", "green", "white", "yellow", "brown", "gray" };           //array of colors for 3 and more players
char options2[7][50] = { "red", "green", "white", "yellow", "brown", "gray", "blue" };  //array of colors for 2 players

int listOfLeds[19] = { 2, 3, 1, 6, 7, 5, 8, 12, 13, 11, 14, 10, 17, 18, 16, 19, 22, 23, 21 };  // pins in order to turn on for light show



void setup() {
  //Serial.begin(57600);
  pinMode(buttonPIN, INPUT_PULLUP);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(255);  //here you can put brightness of leds
  // turning off all leds
  leds[0] = noColor;
  leds[4] = noColor;
  leds[9] = noColor;
  leds[15] = noColor;
  leds[20] = noColor;
  leds[24] = noColor;
  FastLED.show();
}
//setting number of fields for 3 and more players
void setupThreePlayer() {
  numRed = 4;
  numGreen = 4;
  numWhite = 1;
  numYellow = 3;
  numBrown = 4;
  numGray = 3;
}
//setting number of fields for 2 players
void setupTwoPlayer() {
  numRed2 = 3;
  numGreen2 = 3;
  numWhite2 = 1;
  numYellow2 = 2;
  numBrown2 = 3;
  numGray2 = 2;
  numBlue2 = 5;
}

void loop() {
  delay(150);
  if (digitalRead(buttonPIN) == LOW) {
    isNewMode = true;
  } else {
  }
  if (isNewMode) {

    isNewMode = false;
    counter = counter + 1;
    if (counter == 2) {
      musicShow();
    } else if (counter == 3) {
      setupThreePlayer();
      threePlayerGame();
    } else if (counter == 4) {
      setupTwoPlayer();
      twoPlayerGame();
    } else if (counter == 5) {
      counter = 1;
    }
  }
  if (counter == 1) {
    lightShow();
  }
  if (counter == 2) {
    musicShow();
  }
}
// turning on random fileds for 2 player game
void twoPlayerGame() {
  leds[0] = blue;
  leds[4] = blue;
  leds[9] = blue;
  leds[15] = blue;
  leds[20] = blue;
  leds[24] = blue;
  FastLED.show();
  int i = 0;
  int randomIndex;
  char color;
  CRGB ledColor;
  for (i = 0; i < 25; ++i) {
    // those leds are blue, they are outside of files and they presnts sea
    if (i == 0 || i == 4 || i == 9 || i == 15 || i == 20 || i == 24) {

    } else {
back:
      randomIndex = rand() % 7;
      color = options2[randomIndex];

      if (strcmp("red", options2[randomIndex]) == 0) {
        if (numRed2 != 0) {
          numRed2 = numRed2 - 1;
          ledColor = red;
          goto end;
        } else {
          goto back;
        }
      }
      if (strcmp("green", options2[randomIndex]) == 0) {
        if (numGreen2 != 0) {
          numGreen2 = numGreen2 - 1;
          ledColor = green;
          goto end;
        } else {
          goto back;
        }
      }
      if (strcmp("brown", options2[randomIndex]) == 0) {
        if (numBrown2 != 0) {

          numBrown2 = numBrown2 - 1;
          ledColor = brown;
          goto end;
        } else {
          goto back;
        }
      }
      if (strcmp("white", options2[randomIndex]) == 0) {
        if (numWhite2 != 0) {

          numWhite2 = numWhite2 - 1;
          ledColor = white;
          goto end;
        } else {
          goto back;
        }
      }
      if (strcmp("yellow", options2[randomIndex]) == 0) {
        if (numYellow2 != 0) {

          numYellow2 = numYellow2 - 1;
          ledColor = yellow;
          goto end;
        } else {
          goto back;
        }
      }
      if (strcmp("blue", options2[randomIndex]) == 0) {
        if (numBlue2 != 0) {

          numBlue2 = numBlue2 - 1;
          ledColor = blue;
          goto end;
        } else {
          goto back;
        }
      }
      if (strcmp("gray", options2[randomIndex]) == 0) {
        if (numGray2 != 0) {

          numGray2 = numGray2 - 1;
          ledColor = gray;
          goto end;
        } else {
          goto back;
        }
      }
end:
      leds[i] = ledColor;
      FastLED.show();
      delay(100);
    }
  }
}
// turning on random fileds for 3 player game
void threePlayerGame() {
  leds[0] = blue;
  leds[4] = blue;
  leds[9] = blue;
  leds[15] = blue;
  leds[20] = blue;
  leds[24] = blue;
  FastLED.show();
  int i = 0;
  int randomIndex;
  char color;
  CRGB ledColor;
  for (i = 0; i < 25; ++i) {
    // those pins presents sea
    if (i == 0 || i == 4 || i == 9 || i == 15 || i == 20 || i == 24) {

    } else {
back:
      randomIndex = rand() % 6;
      color = options[randomIndex];
      if (strcmp("red", options[randomIndex]) == 0) {

        if (numRed != 0) {

          numRed = numRed - 1;
          ledColor = red;
          goto end;
        } else {
          goto back;
        }
      }
      if (strcmp("green", options[randomIndex]) == 0) {
        if (numGreen != 0) {

          numGreen = numGreen - 1;
          ledColor = green;
          goto end;
        }

        else {
          goto back;
        }
      }
      if (strcmp("brown", options[randomIndex]) == 0) {
        if (numBrown != 0) {

          numBrown = numBrown - 1;
          ledColor = brown;
          goto end;
        } else {
          goto back;
        }
      }
      if (strcmp("white", options[randomIndex]) == 0) {
        if (numWhite != 0) {

          numWhite = numWhite - 1;
          ledColor = white;
          goto end;
        } else {
          goto back;
        }
      }
      if (strcmp("yellow", options[randomIndex]) == 0) {
        if (numYellow != 0) {
          numYellow = numYellow - 1;
          ledColor = yellow;
          goto end;
        } else {
          goto back;
        }
      }
      if (strcmp("gray", options[randomIndex]) == 0) {
        if (numGray != 0) {

          numGray = numGray - 1;
          ledColor = gray;
          goto end;
        } else {
          goto back;
        }
      }
end:
      leds[i] = ledColor;
      FastLED.show();
      delay(50);
    }
  }
}

void lightShow() {
  int randomIndex;
  int i;
  CRGB ledColor;
  while (true) {

    for (i = 0; i < 25; ++i) {
      if (digitalRead(buttonPIN) == LOW) {

        return;
      }

      randomIndex = rand() % 7;

      if (strcmp("gray", options2[randomIndex]) == 0) {
        ledColor = gray;
      } else if (strcmp("blue", options2[randomIndex]) == 0) {
        ledColor = blue;
      } else if (strcmp("green", options2[randomIndex]) == 0) {
        ledColor = green;
      }
      else if (strcmp("brown", options2[randomIndex]) == 0) {
        ledColor = brown;
      }
      } else if (strcmp("white", options2[randomIndex]) == 0) {
        ledColor = white;
      } else if (strcmp("yellow", options2[randomIndex]) == 0) {
        ledColor = yellow;
      } else if (strcmp("red", options2[randomIndex]) == 0) {
        ledColor = red;
      }
      leds[i] = ledColor;
      FastLED.show();
      delay(50);
    }
  }
}
void soundShow() {
  int i;
  int ledsToShow;
  int sensorValue;
  int randomIndex;
  int digitalReadSesnor;
  CRGB ledColor;

  turnOffAllLeds();
  while (true) {

    if (digitalRead(buttonPIN) == LOW) {

      return;
    }
    sensorValue = analogRead(microphonePin); // reading sesnsor Value
    randomIndex = rand() % 7; //getting random color
    
    //set random color
    if (strcmp("gray", options2[randomIndex]) == 0) {
      ledColor = gray;
    } else if (strcmp("blue", options2[randomIndex]) == 0) {
      ledColor = blue;
    } else if (strcmp("green", options2[randomIndex]) == 0) {
      ledColor = green;
    }
    else if (strcmp("brown", options2[randomIndex]) == 0) {
      ledColor = brown;
    }
    } else if (strcmp("white", options2[randomIndex]) == 0) {
      ledColor = white;
    } else if (strcmp("yellow", options2[randomIndex]) == 0) {
      ledColor = yellow;
    } else if (strcmp("red", options2[randomIndex]) == 0) {
      ledColor = red;
    }

    if (sensorValue < 30) {
      turnOffAllLeds();
      ledsToShow = 0;
    }
    if ((sensorValue > 30)) {
      if (sensorValue <= 40) {
        

        ledsToShow = 2;
        for (i = 0; i < ledsToShow; ++i) {
          if (i == 0 || i == 4 || i == 9 || i == 15 || i == 20 || i == 24) {

          } else {
            leds[i] = ledColor;
            FastLED.show();
          }
        }
      }
    }
    if ((sensorValue > 40)) {
      if (sensorValue <= 50) {

        
        ledsToShow = 3;
        for (i = 0; i < ledsToShow; ++i) {
          if (i == 0 || i == 4 || i == 9 || i == 15 || i == 20 || i == 24) {

          } else {
            leds[i] = ledColor;
            FastLED.show();
          }
        }
      }
    }
    if ((sensorValue > 50)) {
      if (sensorValue <= 60) {

        
        ledsToShow = 4;
        for (i = 0; i < ledsToShow; ++i) {
          if (i == 0 || i == 4 || i == 9 || i == 15 || i == 20 || i == 24) {

          } else {
            leds[i] = ledColor;
            FastLED.show();
          }
        }
      }
    }
    if ((sensorValue > 60)) {
      if (sensorValue <= 70) {

        
        ledsToShow = 6;
        for (i = 0; i < ledsToShow; ++i) {
          if (i == 0 || i == 4 || i == 9 || i == 15 || i == 20 || i == 24) {

          } else {
            leds[i] = ledColor;
            FastLED.show();
          }
        }
      }
    }
    if ((sensorValue > 70)) {
      if (sensorValue <= 80) {

        
        ledsToShow = 7;
        for (i = 0; i < ledsToShow; ++i) {
          if (i == 0 || i == 4 || i == 9 || i == 15 || i == 20 || i == 24) {

          } else {
            leds[i] = ledColor;
            FastLED.show();
          }
        }
      }
    }
    if ((sensorValue > 80)) {
      if (sensorValue <= 90) {

        
        ledsToShow = 8;
        for (i = 0; i < ledsToShow; ++i) {
          if (i == 0 || i == 4 || i == 9 || i == 15 || i == 20 || i == 24) {

          } else {
            leds[i] = ledColor;
            FastLED.show();
          }
        }
      }
    }

    if ((sensorValue > 90)) {
      if (sensorValue <= 100) {

        
        ledsToShow = 9;
        for (i = 0; i < ledsToShow; ++i) {
          if (i == 0 || i == 4 || i == 9 || i == 15 || i == 20 || i == 24) {

          } else {
            leds[i] = ledColor;
            FastLED.show();
          }
        }
      }
    }

    if ((sensorValue > 100)) {
      if (sensorValue <= 110) {

        
        ledsToShow = 11;
        for (i = 0; i < ledsToShow; ++i) {
          if (i == 0 || i == 4 || i == 9 || i == 15 || i == 20 || i == 24) {

          } else {
            leds[i] = ledColor;
            FastLED.show();
          }
        }
      }
    }
    if ((sensorValue > 110)) {
      if (sensorValue <= 120) {

        
        ledsToShow = 12;
        for (i = 0; i < ledsToShow; ++i) {
          if (i == 0 || i == 4 || i == 9 || i == 15 || i == 20 || i == 24) {

          } else {
            leds[i] = ledColor;
            FastLED.show();
          }
        }
      }
    }
    if ((sensorValue > 120)) {
      if (sensorValue <= 130) {

        
        ledsToShow = 13;
        for (i = 0; i < ledsToShow; ++i) {
          if (i == 0 || i == 4 || i == 9 || i == 15 || i == 20 || i == 24) {

          } else {
            leds[i] = ledColor;
            FastLED.show();
          }
        }
      }
    }

    if ((sensorValue > 130)) {
      if (sensorValue <= 140) {

        
        ledsToShow = 14;
        for (i = 0; i < ledsToShow; ++i) {
          if (i == 0 || i == 4 || i == 9 || i == 15 || i == 20 || i == 24) {

          } else {
            leds[i] = ledColor;
            FastLED.show();
          }
        }
      }
    }
    if ((sensorValue > 140)) {
      if (sensorValue <= 150) {

        
        ledsToShow = 15;
        for (i = 0; i < ledsToShow; ++i) {
          if (i == 0 || i == 4 || i == 9 || i == 15 || i == 20 || i == 24) {

          } else {
            leds[i] = ledColor;
            FastLED.show();
          }
        }
      }
    }

    if ((sensorValue > 150)) {
      if (sensorValue <= 160) {

        
        ledsToShow = 17;
        for (i = 0; i < ledsToShow; ++i) {
          if (i == 0 || i == 4 || i == 9 || i == 15 || i == 20 || i == 24) {

          } else {
            leds[i] = ledColor;
            FastLED.show();
          }
        }
      }
    }
    if ((sensorValue > 160)) {
      if (sensorValue <= 170) {

        
        ledsToShow = 18;
        for (i = 0; i < ledsToShow; ++i) {
          if (i == 0 || i == 4 || i == 9 || i == 15 || i == 20 || i == 24) {

          } else {
            leds[i] = ledColor;
            FastLED.show();
          }
        }
      }
    }

    if ((sensorValue > 170)) {
      if (sensorValue <= 180) {

        
        ledsToShow = 19;
        for (i = 0; i < ledsToShow; ++i) {
          if (i == 0 || i == 4 || i == 9 || i == 15 || i == 20 || i == 24) {

          } else {
            leds[i] = ledColor;
            FastLED.show();
          }
        }
      }
    }
    if ((sensorValue > 180)) {
      if (sensorValue <= 190) {

        
        ledsToShow = 20;
        for (i = 0; i < ledsToShow; ++i) {
          if (i == 0 || i == 4 || i == 9 || i == 15 || i == 20 || i == 24) {

          } else {
            leds[i] = ledColor;
            FastLED.show();
          }
        }
      }
    }
    if ((sensorValue > 190)) {
      if (sensorValue <= 200) {

        
        ledsToShow = 22;
        for (i = 0; i < ledsToShow; ++i) {
          if (i == 0 || i == 4 || i == 9 || i == 15 || i == 20 || i == 24) {

          } else {
            leds[i] = ledColor;
            FastLED.show();
          }
        }
      }
    }

    if ((sensorValue > 200)) {
      if (sensorValue <= 210) {

        
        ledsToShow = 23;
        for (i = 0; i < ledsToShow; ++i) {
          if (i == 0 || i == 4 || i == 9 || i == 15 || i == 20 || i == 24) {

          } else {
            leds[i] = ledColor;
            FastLED.show();
          }
        }
      }
    }
    if ((sensorValue > 210)) {


      
      ledsToShow = 24;
      for (i = 0; i < ledsToShow; ++i) {
        if (i == 0 || i == 4 || i == 9 || i == 15 || i == 20 || i == 24) {

        } else {
          leds[i] = ledColor;
          FastLED.show();
        }
      }
    }
  }
}

//there is fixed range of sensor value, that ranges depends on microphone(you should play with them!!)
void musicShow() {
  int i;
  int ledsToShow;
  int sensorValue;
  int randomIndex;
  int digitalReadSesnor;
  CRGB ledColor;

  turnOffAllLeds();
  while (true) {
    i = 0;
    if (digitalRead(buttonPIN) == LOW) {

      return;
    }

    sensorValue = analogRead(microphonePin);
    //Serial.println(analogRead(microphonePin));
    randomIndex = rand() % 7;


    if (strcmp("gray", options2[randomIndex]) == 0) {
      ledColor = gray;
    } else if (strcmp("blue", options2[randomIndex]) == 0) {
      ledColor = blue;
    } else if (strcmp("green", options2[randomIndex]) == 0) {
      ledColor = green;
    }

    else if (strcmp("brown", options2[randomIndex]) == 0) {
      ledColor = brown;
    }

    else if (strcmp("gray", options2[randomIndex]) == 0) {
      ledColor = gray;
    } else if (strcmp("white", options2[randomIndex]) == 0) {
      ledColor = white;
    } else if (strcmp("yellow", options2[randomIndex]) == 0) {
      ledColor = yellow;
    } else if (strcmp("red", options2[randomIndex]) == 0) {
      ledColor = red;
    }

    if (sensorValue < 50) {
      turnOffAllLeds();
      ledsToShow = 0;
    }
    if ((sensorValue > 50)) {
      if (sensorValue <= 60) {

        ledsToShow = 1;
        for (i = 0; i < ledsToShow; ++i) {
          leds[listOfLeds[i]] = ledColor;
          FastLED.show();
        }
      }
    }
    if ((sensorValue > 60)) {
      if (sensorValue <= 70) {
        ledsToShow = 2;
        for (i = 0; i < ledsToShow; ++i) {
          leds[listOfLeds[i]] = ledColor;
          FastLED.show();
        }
      }
    }
    if ((sensorValue > 70)) {
      if (sensorValue <= 80) {


        ledsToShow = 3;
        for (i = 0; i < ledsToShow; ++i) {
          leds[listOfLeds[i]] = ledColor;
          FastLED.show();
        }
      }
    }
    if ((sensorValue > 80)) {
      if (sensorValue <= 90) {


        ledsToShow = 4;
        for (i = 0; i < ledsToShow; ++i) {
          leds[listOfLeds[i]] = ledColor;
          FastLED.show();
        }
      }
    }
    if ((sensorValue > 90)) {
      if (sensorValue <= 100) {

        ledsToShow = 5;
        for (i = 0; i < ledsToShow; ++i) {
          leds[listOfLeds[i]] = ledColor;
          FastLED.show();
        }
      }
    }
    if ((sensorValue > 100)) {
      if (sensorValue <= 110) {


        ledsToShow = 6;
        for (i = 0; i < ledsToShow; ++i) {
          leds[listOfLeds[i]] = ledColor;
          FastLED.show();
        }
      }
    }

    if ((sensorValue > 110)) {
      if (sensorValue <= 120) {



        ledsToShow = 7;
        for (i = 0; i < ledsToShow; ++i) {
          leds[listOfLeds[i]] = ledColor;
          FastLED.show();
        }
      }
    }

    if ((sensorValue > 120)) {
      if (sensorValue <= 130) {


        ledsToShow = 8;
        for (i = 0; i < ledsToShow; ++i) {
          leds[listOfLeds[i]] = ledColor;
          FastLED.show();
        }
      }
    }
    if ((sensorValue > 130)) {
      if (sensorValue <= 140) {


        ledsToShow = 9;
        for (i = 0; i < ledsToShow; ++i) {
          leds[listOfLeds[i]] = ledColor;
          FastLED.show();
        }
      }
    }
    if ((sensorValue > 140)) {
      if (sensorValue <= 150) {


        ledsToShow = 10;
        for (i = 0; i < ledsToShow; ++i) {
          leds[listOfLeds[i]] = ledColor;
          FastLED.show();
        }
      }
    }

    if ((sensorValue > 150)) {
      if (sensorValue <= 160) {


        ledsToShow = 11;
        for (i = 0; i < ledsToShow; ++i) {
          leds[listOfLeds[i]] = ledColor;
          FastLED.show();
        }
      }
    }
    if ((sensorValue > 160)) {
      if (sensorValue <= 170) {


        ledsToShow = 12;
        for (i = 0; i < ledsToShow; ++i) {
          leds[listOfLeds[i]] = ledColor;
          FastLED.show();
        }
      }
    }

    if ((sensorValue > 170)) {
      if (sensorValue <= 180) {

        ledsToShow = 13;
        for (i = 0; i < ledsToShow; ++i) {
          leds[listOfLeds[i]] = ledColor;
          FastLED.show();
        }
      }
    }
    if ((sensorValue > 180)) {
      if (sensorValue <= 190) {


        ledsToShow = 14;
        for (i = 0; i < ledsToShow; ++i) {
          leds[listOfLeds[i]] = ledColor;
          FastLED.show();
        }
      }
    }

    if ((sensorValue > 190)) {
      if (sensorValue <= 200) {


        ledsToShow = 15;
        for (i = 0; i < ledsToShow; ++i) {
          leds[listOfLeds[i]] = ledColor;
          FastLED.show();
        }
      }
    }
    if ((sensorValue > 200)) {
      if (sensorValue <= 210) {


        ledsToShow = 16;
        for (i = 0; i < ledsToShow; ++i) {
          leds[listOfLeds[i]] = ledColor;
          FastLED.show();
        }
      }
    }
    if ((sensorValue > 210)) {
      if (sensorValue <= 220) {

        ledsToShow = 17;
        for (i = 0; i < ledsToShow; ++i) {
          leds[listOfLeds[i]] = ledColor;
          FastLED.show();
        }
      }
    }

    if ((sensorValue > 220)) {
      if (sensorValue <= 230) {



        ledsToShow = 18;
        for (i = 0; i < ledsToShow; ++i) {
          leds[listOfLeds[i]] = ledColor;
          FastLED.show();
        }
      }
    }
    if ((sensorValue > 230)) {

      ledsToShow = 19;
      for (i = 0; i < ledsToShow; ++i) {
        leds[listOfLeds[i]] = ledColor;
        FastLED.show();
      }
    }
  }
}
// function to turn all leds if microphone value is 0 !
void turnOffAllLeds() {
  int i;
  for (i = 0; i < 25; ++i) {
    leds[i] = noColor;
    FastLED.show();
  }
}
