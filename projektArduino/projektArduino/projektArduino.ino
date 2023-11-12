#include "pitches.h"
#include <stdio.h>
#include <stdlib.h>



byte diody[9] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
byte glosnik = 11;


void setup() {
  
  for(byte x = 0; x < 9; x++){
    pinMode(diody[x], OUTPUT);
  }
  pinMode(glosnik, OUTPUT);
  
}

void loop() {
  
  weWishYouAMerryChristmasSong(glosnik);
  delay(1000);

}

void weWishYouAMerryChristmasSong(byte glosnik){

  // change this to make the song slower or faster
  int tempo = 150;

  int melody[] = {

  // We Wish You a Merry Christmas
    
    NOTE_C5,4, //1
    NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
    NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,
    NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
    NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,
    NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8,
    NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,
    NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,

    NOTE_F5,2, NOTE_C5,4, //8 
    NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
    NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,
    NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
    NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,
    NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8,
    NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,
    NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
    NOTE_F5,2, NOTE_C5,4,

    NOTE_F5,4, NOTE_F5,4, NOTE_F5,4,//17
    NOTE_E5,2, NOTE_E5,4,
    NOTE_F5,4, NOTE_E5,4, NOTE_D5,4,
    NOTE_C5,2, NOTE_A5,4,
    NOTE_AS5,4, NOTE_A5,4, NOTE_G5,4,
    NOTE_C6,4, NOTE_C5,4, NOTE_C5,8, NOTE_C5,8,
    NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
    NOTE_F5,2, NOTE_C5,4, 
    NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
    NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,
    
    NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8, //27
    NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,
    NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8,
    NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,
    NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
    NOTE_F5,2, NOTE_C5,4,
    NOTE_F5,4, NOTE_F5,4, NOTE_F5,4,
    NOTE_E5,2, NOTE_E5,4,
    NOTE_F5,4, NOTE_E5,4, NOTE_D5,4,
    
    NOTE_C5,2, NOTE_A5,4,//36
    NOTE_AS5,4, NOTE_A5,4, NOTE_G5,4,
    NOTE_C6,4, NOTE_C5,4, NOTE_C5,8, NOTE_C5,8,
    NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
    NOTE_F5,2, NOTE_C5,4, 
    NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
    NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,
    NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8, 
    NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,
    
    NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8,//45
    NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,
    NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
    NOTE_F5,2, NOTE_C5,4,
    NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
    NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,
    NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
    NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,
    
    NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, //53
    NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,
    NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
    NOTE_F5,2, REST,4
  };

  int notes = sizeof(melody) / sizeof(melody[0]) / 2;
  int wholenote = (60000 * 4) / tempo;
  int divider = 0, noteDuration = 0;

    for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

      // calculates the duration of each note
      divider = melody[thisNote + 1];
      if (divider > 0) {
        // regular note, just proceed
        noteDuration = (wholenote) / divider;
      } else if (divider < 0) {
        // dotted notes are represented with negative durations!!
        noteDuration = (wholenote) / abs(divider);
        noteDuration *= 1.5; // increases the duration in half for dotted notes
      }

      byte diodaPierwsza = rand() % (10 + 1 - 2) + 2;
      byte diodaDruga = rand() % (10 + 1 - 2) + 2;
      byte diodaTrzecia = rand() % (10 + 1 - 2) + 2;

      digitalWrite(diodaPierwsza, HIGH);
      digitalWrite(diodaDruga, HIGH);
      digitalWrite(diodaTrzecia, HIGH);
      delay(100);
      digitalWrite(diodaPierwsza, LOW);
      digitalWrite(diodaDruga, LOW);
      digitalWrite(diodaTrzecia, LOW);

      tone(glosnik, melody[thisNote], noteDuration * 0.9);
      delay(noteDuration);
      noTone(glosnik);
    }

}
