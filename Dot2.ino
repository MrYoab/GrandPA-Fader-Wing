  #include <MIDIUSB.h>
int lastcol11;
int lastcol12 = 1;
int lastcol13;
int lastcol14;
int lastcol15;
int lastcol16;
int lastcol17;
int lastcol18;

int lastcol21 = 1;
int lastcol22 = 1;
int lastcol23 = 1;
int lastcol24 = 1;
int lastcol25 = 1;
int lastcol26 = 1;
int lastcol27 = 1;
int lastcol28 = 1;

int col1 = 2;
int col2 = 3;
int col3 = 4;
int col4 = 5;
int col5 = 6;
int col6 = 7;
int col7 = 8;
int col8 = 9;
int row1 = 14;
int row2 = 15;
void setup() {
Serial.begin(9600);
pinMode(col1, INPUT_PULLUP);
pinMode(col2, INPUT_PULLUP);
pinMode(col3, INPUT_PULLUP);
pinMode(col4, INPUT_PULLUP);
pinMode(col5, INPUT_PULLUP);
pinMode(col6, INPUT_PULLUP);
pinMode(col7, INPUT_PULLUP);
pinMode(col8, INPUT_PULLUP);
pinMode(row1, OUTPUT);
pinMode(row2, OUTPUT);
Serial.println("----------+----------");
Serial.println("Begin der Matrix");
Serial.println("----------+----------");

}

void loop() {
  for(int dings = 0; dings <2; dings++)
  {
    setrow(dings + 1);
    delay(1);
    readcol(dings + 1);
  }
}
  
void setrow(int zahl){
  switch(zahl){
    case 1:
      digitalWrite(row1, LOW);
      digitalWrite(row2, HIGH);

      break;
    
    case 2:
      digitalWrite(row1, HIGH);
      digitalWrite(row2, LOW);
      break;
  }
}  

void readcol(int row) {
  switch(row){
    case 1:
      if(lastcol11 != digitalRead(col1)){
        delay(10);
        Serial.println(lastcol11);
        Serial.println(digitalRead(col1));


        //col1

        if(digitalRead(col1) == LOW){
          Serial.print(row);
          Serial.print(" | ");
          Serial.println("1 is pressed");
          lastcol11 = digitalRead(col1);
          Serial.println(lastcol11);
          Serial.println();
          break;
        }
        if(digitalRead(col1) == HIGH){
          Serial.print(row);
          Serial.print(" | ");
          Serial.println("1 is released");
          lastcol11 = digitalRead(col1);
          Serial.println(lastcol11);
          Serial.println();
          break;
        }
      }
      

      //COL 2

      if(lastcol12 != digitalRead(col2)){
        delay(10);
        Serial.println(lastcol12);
        Serial.println(digitalRead(col2));


        if(digitalRead(col2) == LOW){
          Serial.print(row);
          Serial.print(" | ");
          Serial.println("2 is pressed");
          lastcol12 = digitalRead(col2);
          Serial.println(lastcol12);
          Serial.println();
          break;
        }
        if(digitalRead(col2) == HIGH){
          Serial.print(row);
          Serial.print(" | ");
          Serial.println("2 is released");
          lastcol12 = digitalRead(col2);
          Serial.println(lastcol12);
          Serial.println();
          break;
        }
      }

      //COL 3

      if(lastcol13 != digitalRead(col3)){
        delay(10);
        Serial.println(lastcol13);
        Serial.println(digitalRead(col3));


        if(digitalRead(col3) == LOW){
          Serial.print(row);
          Serial.print(" | ");
          Serial.println("3 is pressed");
          lastcol13 = digitalRead(col3);
          Serial.println(lastcol13);
          Serial.println();
          break;
        }
        if(digitalRead(col3) == HIGH){
          Serial.print(row);
          Serial.print(" | ");
          Serial.println("3 is released");
          lastcol13 = digitalRead(col3);
          Serial.println(lastcol13);
          Serial.println();
          break;
        }
      }
      break;

      
    
    //REIHEEEEEEEEEEE 2

    case 2:
      if(lastcol21 != digitalRead(col1)){
        delay(10);
        Serial.println(lastcol21);
        Serial.println(digitalRead(col1));


        //col1

        if(digitalRead(col1) == LOW){
          Serial.print(row);
          Serial.print(" | ");
          Serial.println("1 is pressed");
          lastcol21 = digitalRead(col1);
          Serial.println();
          break;
        }
        if(digitalRead(col1) == HIGH){
          Serial.print(row);
          Serial.print(" | ");
          Serial.println("1 is released");
          lastcol21 = digitalRead(col1);
          Serial.println(lastcol21);
          Serial.println();
          break;
        }
      }
      

      //COL2

      if(lastcol22 != digitalRead(col2)){
          delay(10);
          Serial.println(lastcol22);
          Serial.println(digitalRead(col2));


          if(digitalRead(col2) == LOW){
            Serial.print(row);
            Serial.print(" | ");
            Serial.println("2 is pressed");
            lastcol22 = digitalRead(col2);
            Serial.println(lastcol22);
            Serial.println();
            break;
          }
          if(digitalRead(col2) == HIGH){
            Serial.print(row);
            Serial.print(" | ");
            Serial.println("2 is released");
            lastcol22 = digitalRead(col2);
            Serial.println(lastcol22);
            Serial.println();
            break;
          }
        }

        //COL 3

      if(lastcol23 != digitalRead(col3)){
        delay(10);
        Serial.println(lastcol23);
        Serial.println(digitalRead(col3));


        if(digitalRead(col3) == LOW){
          Serial.print(row);
          Serial.print(" | ");
          Serial.println("3 is pressed");
          lastcol23 = digitalRead(col3);
          Serial.println(lastcol23);
          Serial.println();
          break;
        }
        if(digitalRead(col3) == HIGH){
          Serial.print(row);
          Serial.print(" | ");
          Serial.println("3 is released");
          lastcol23 = digitalRead(col3);
          Serial.println(lastcol23);
          Serial.println();
          break;
        }
      }
      break;


      






  }
}
  




/////////////////////////////////////////////
// Arduino (pro)micro midi functions MIDIUSB Library
void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = { 0x09, 0x90 | channel, pitch, velocity };
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = { 0x08, 0x80 | channel, pitch, velocity };
  MidiUSB.sendMIDI(noteOff);
}

void controlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = { 0x0B, 0xB0 | channel, control, value };
  MidiUSB.sendMIDI(event);
}

void pitchBend(byte channel, int value) {
  byte lowValue = value & 0x7F;
  byte highValue = value >> 7;
  midiEventPacket_t pitchBend = { 0x0E, 0xE0 | channel, lowValue, highValue };
  MidiUSB.sendMIDI(pitchBend);
}



/*
if(lastcol21 != digitalRead(col1)){
        delay(1);

        //col1

        if(digitalRead(col1) == LOW){
        Serial.print(row);
        Serial.print(" | ");
        Serial.println("1 is pressed");
        lastcol21 = digitalRead(col1);
        Serial.println(lastcol21);
        break;
        }
        if(digitalRead(col1) == HIGH){
        Serial.print(row);
        Serial.print(" | ");
        Serial.println("1 is released");
        lastcol21 = digitalRead(col1);
        Serial.println(lastcol21);
        Serial.println();
        break;
        }
      }

      //col2

      if(lastcol22 != digitalRead(col2)){
        delay(1);

        if(digitalRead(col2) == LOW){
          Serial.print(row);
          Serial.print(" | ");
          Serial.println("2 is pressed");
          lastcol22 = digitalRead(col2);
          Serial.println(lastcol22);
          break;
        }
        if(digitalRead(col2) == HIGH){
          Serial.print(row);
          Serial.print(" | ");
          Serial.println("2 is released");
          lastcol22 = digitalRead(col2);
          Serial.println(lastcol22);
          Serial.println();
          break;
        }
      }

        //col3

      if(lastcol23 != digitalRead(col3)){
        delay(1);

        if(digitalRead(col3) == LOW){
          Serial.print(row);
          Serial.print(" | ");
          Serial.println("3 is pressed");
          lastcol23 = digitalRead(col3);
          Serial.println(lastcol23);
          break;
        }
        if(digitalRead(col3) == HIGH){
          Serial.print(row);
          Serial.print(" | ");
          Serial.println("3 is released");
          lastcol23 = digitalRead(col3);
          Serial.println(lastcol23);
          Serial.println();
        break;
        }
      }

        //col4

      if(lastcol24 != digitalRead(col4)){
        delay(25);

        if(digitalRead(col4) == LOW){
          Serial.print(row);
          Serial.print(" | ");
          Serial.println("4 is pressed");
          lastcol24 = digitalRead(col4);
          Serial.println(lastcol24);
          break;
        }
        if(digitalRead(col4) == HIGH){
          Serial.print(row);
          Serial.print(" | ");
          Serial.println("4 is released");
          lastcol24 = digitalRead(col4);
          Serial.println(lastcol24);
          Serial.println();
          break;
        }
      }

      //col5

      if(lastcol25 != digitalRead(col5)){
        delay(1);

        if(digitalRead(col5) == LOW){
        Serial.print(row);
        Serial.print(" | ");
        Serial.println("5 is pressed");
        lastcol25 = digitalRead(col5);
        Serial.println(lastcol25);
        break;
        }
        if(digitalRead(col5) == HIGH){
        Serial.print(row);
        Serial.print(" | ");
        Serial.println("5 is released");
        lastcol25 = digitalRead(col5);
        Serial.println(lastcol25);
        Serial.println();
        break;
        }
      }

      //col6

      if(lastcol26 != digitalRead(col6)){
        delay(1);

        if(digitalRead(col6) == LOW){
        Serial.print(row);
        Serial.print(" | ");
        Serial.println("6 is pressed");
        lastcol26 = digitalRead(col6);
        Serial.println(lastcol26);
        break;
        }
        if(digitalRead(col6) == HIGH){
        Serial.print(row);
        Serial.print(" | ");
        Serial.println("6 is released");
        lastcol26 = digitalRead(col6);
        Serial.println(lastcol26);
        Serial.println();
        break;
        }
      }

      //col7

      if(lastcol27 != digitalRead(col7)){
        delay(1);

        if(digitalRead(col7) == LOW){
        Serial.print(row);
        Serial.print(" | ");
        Serial.println("7 is pressed");
        lastcol27 = digitalRead(col7);
        Serial.println(lastcol27);
        break;
        }
        if(digitalRead(col7) == HIGH){
        Serial.print(row);
        Serial.print(" | ");
        Serial.println("7 is released");
        lastcol27 = digitalRead(col7);
        Serial.println(lastcol27);
        Serial.println();
        break;
        }
      }

      //col8

      if(lastcol28 != digitalRead(col8)){
        delay(1);

        if(digitalRead(col8) == LOW){
        Serial.print(row);
        Serial.print(" | ");
        Serial.println("8 is pressed");
        lastcol28 = digitalRead(col8);
        Serial.println(lastcol28);
        break;
        }
        if(digitalRead(col8) == HIGH){
        Serial.print(row);
        Serial.print(" | ");
        Serial.println("8 is released");
        lastcol28 = digitalRead(col8);
        Serial.println(lastcol28);
        Serial.println();
        break;
        }
      }
*/

