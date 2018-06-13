#define d0 467
#define D0 494
#define n0 524
#define N0 555

#define S 588
#define r 623
#define R 660
#define g 699
#define G 740
#define M 784
#define m 831
#define P 880
#define d 933
#define D 988
#define n 1047
#define N 1109

#define S1 1175
#define r1 1246
#define R1 1320
#define g1 1398
#define G1 1480
#define M1 1568
#define d1 1866

#define led0 B0001
#define led1 B0010
#define led2 B0100
#define led3 B1000


#define z 0    // for pausing between two notes, z for zero
#define b 280  // for beats or tempo or speed
               // we can mutiply b by any number to get more duration in any single note, Or devide for vice versa

int speakerPin = 7; // the pin where the speaker is connected to

int numTones =  94;  // number of notes in each verse of the song 22+22+25+25, total 94

int ledPins[] = { 
  3,6,9,11 };  


int tones[] = { n,z,n,z,n,S1,r1,S1,        r1,n,P,n,P,n, z,n,     S1,n,S1,g1,r1,z,
                S1,z,n,z,n,S1,r1,S1,    r1,n,P,n,P,n, z,n,     S1,n,S1,g1,r1,z,
                n,z,n,z,n,S1,g1,z,        g1,z,g1,M1,g1,M1,z,g1,   M1,g1,M1,d1,M1,r1,S1,n,z,
                n,z,n,z,n,S1,g1,z,        g1,z,g1,M1,g1,M1,z,g1,   M1,g1,M1,d1,M1,r1,S1,n,z 
              };

int beat[] = {b,b/10,b,b/8,b,4*b,b,b,       b,3*b,b,b,b,b,b/10,2*b,       2*b,b,2*b,2*b,6*b,2*b,
              b,b/10,b,b/8,b,4*b,b,b,         b,3*b,b,b,b,b,b/10,2*b,     2*b,b,2*b,2*b,6*b,2*b,
              b,b/10,b,b/10,2*b,2*b,2*b,b/15, b,b/10,b,3*b,b,b,b/10,2*b,    b,b,b,3*b,b,3*b,b,b,b,
              b,b/10,b,b/10,2*b,2*b,2*b,b/15, b,b/10,b,3*b,b,b,b/10,2*b,    b,b,b,3*b,b,3*b,b,b,2*b,
             };

byte LEDs[]={ B0010,   B0100,   B1000,   B0001,   B1111,       B0001,    B0001,
   B0001,   B1000,   B0100,   B0010,   B1111,
   B0010,   B1000,   B0100,   B0001,   B1111,
   B0001,   B0100,   B1000,   B0010,   B1111,       B0010,
   B0010,   B0100,   B1000,   B0001,   B1111,       B0001,    B0001,
   B0001,   B1000,   B0100,   B0010,   B1111,       B0010,
   B0010,   B0100,   B1000,   B0001,   B1001,     B0110,    B1100,       B0011,
   B1010,    B0101,    B1010,     B0101,    B1111,
   B0110,    B0110,    B0110,     B1001,    B1001,      B1001,
   B0010,   B0100,   B1000,   B0001,   B1111,
   B0110,    B0110,    B0110,     B0110,    B0110,      B1001,    B1001,       B1001,      B1001,
   B0010,   B0100,   B1000,   B0001,   B0010,    B1111,
   B0110,    B0110,    B0110,     B1001,    B1001,     B1001,
   B0010,   B0100,   B1000,   B0001,   B1111,
   B0110,    B0110,    B0110,     B0110,    B0110,     B1001,     B1001,       B1001,      B1001,
   B1111,       B1111,       B1100,    B0011,    B1111};



void setup()
{
// the setup block is left empty.
}

void loop()
{
  for (int i = 0; i < numTones; i++)
  {

    tone(speakerPin, tones[i]);
    LEDon(i);
  delay(beat[i]);
    LEDoff(i);
    
    }
  
  noTone(speakerPin);
  
}


int currentLEDpin=3;
void LEDon(int thisNote)
{
  if ((LEDs[thisNote]&led0)!=0) digitalWrite(ledPins[0],HIGH);
  if ((LEDs[thisNote]&led1)!=0) digitalWrite(ledPins[1],HIGH);
  if ((LEDs[thisNote]&led2)!=0) digitalWrite(ledPins[2],HIGH);
  if ((LEDs[thisNote]&led3)!=0) digitalWrite(ledPins[3],HIGH);
}

void LEDoff(int thisNote)
{
  if ((LEDs[thisNote]&led0)!=0) digitalWrite(ledPins[0],LOW);
  if ((LEDs[thisNote]&led1)!=0) digitalWrite(ledPins[1],LOW);
  if ((LEDs[thisNote]&led2)!=0) digitalWrite(ledPins[2],LOW);
  if ((LEDs[thisNote]&led3)!=0) digitalWrite(ledPins[3],LOW);
}
