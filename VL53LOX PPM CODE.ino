//This source code can be found at the https://quadmeup.com/generate-ppm-signal-with-arduino/site

// scooped it up and modified it. If you want the original source code, go to the site above,

//download it, and customize il

// PPM. generator originally written by David Hasko

// on https://code.google.com/p/generate-ppm-signal/

#include <SPI.h>

#include <RF24.h>

CONFIGURATION////......

#define CHANNEL NUMBER 8

//set the number of chanels

#define CHANNEL_DEFAULT_VALUE 1000

//set the default servo value

//set the PPM frame length in microseconds (1ms = 1000µs)

#define FRAME LENGTH 22500

//set the pulse length

#define PULSE LENGTH 300

//set polarity of the pulses 1 is positive, O is negative

#define onState 1

//set PPM signal output pin on the arduino

#define sigPin 8

#define SIGNAL TIMEOUT 100 // This is signal timeout in milli seconds.

#define OBSTACLE_TIMEOUT 100 // This is obstacle signal valid limeout in milli seconds

#define LEDPin 2 // This is signal timeout in milli seconds.

"this array holds the servo values for the ppm signal

change theese values in your code (usually servo values move between 1000 and 2000)/

int ppm[CHANNEL_NUMBER]; unsigned long lastRecvTime = 0; unsigned long last_Obstacle_Time = 0;

RF24 radio(9, 10); // CE, CSN

const byte address[6] = "00002";

String obstacle=""

char dir[4]="";

int CH1_MID=1500; int CH2 MID=1500;
int CH2 MID=1500;

struct PacketDala

byte ch1_0; byte ch1_1; byte ch2_0; byte ch2_1; byte ch3_0; byte ch3_1; byte ch4_0; byte ch4_1; byte ch5_0; byte ch5_1; byte ch6_0; byte ch6_1; byte ch7_0; byte ch7_1; byte ch8_0; byte ch8_1;

PacketData receiverData;

void avoid_controll(String dir )( int gap =150; ppm[0] = CH1_MID: ppm[1]= CH2_MID;

if (dir.equals("NN")){ //go backward ppm[1]1500+ gap;

}else if(dir.equals("NE"))(

//go backward + left

ppm[0]=1500-gap;

ppm[1] 1500+ gap;

}else if(dir.equals("EE")){

/go left

ppm[0] 1500-gap;

Jelse if(dir.equals("SE"))(

//go forward + left

ppm[0]=1500-gap;
ppm[1]=1500-gap;

)else if(dir.equals("SS")){(

//go forward

ppm[1] 1500-gap;

}else if(dir.equals("SW")){

/go forward + right

ppm[0] 1500+ gap;

ppm[1]=1500-gap:

} else if(dir.equals("WW"))(

//go right

ppm[0]=1500+ gap;

}else if(dir.equals("NW"))(

//go backward + right

ppm[0]=1500+gap;

ppm[1]=1500+gap:

}

void setup()(

Serial.begin(115200);

initiallize default ppm values

for(int i=0; i<CHANNEL NUMBER; i++){ ppm[i]= CHANNEL_DEFAULT_VALUE;

}

radio.begin();

radio.openReadingPipe(0, address);

radio.setPALevel(RF24_PA_MAX);

radio startListening();

pinMode(LEDPin, OUTPUT);

pinMode(sigPin, OUTPUT);

digitalWrite(sigPin, lonState); //set the PPM signal pin to the default state (off) cli();

TCCR1A=0; // set entire TCCR1 register to 0 TCCR180
TCCR1B = 0;

OCR1A= 100; // compare match register, change this

TCCR1B |= (1 <<WGM12); // turn on CTC mode

TCCR1B |= (1 << CS11); // 8 prescaler 0,5 microseconds at 16mhz

TIMSK1 = (1 << OCIE1A); // enable timer compare interrupt

sei();

}

void loop()(

if (Serial.available() > 0) {

obstacle dir;

Serial.readBytes(dir,4);

avoid_controll(obstacle);

last Obstacle_Time = millis();

unsigned long now_obstacle = millis();

if(now_obstacle-last_Obstacle_Time > OBSTACLE_TIMEOUT) { obstacle=""

if(obstacle.equals("")){

if(radio.avallable()){

radio.read(&receiverData, sizeof(PacketData));

ppm[0] = receiverData.ch1_0*256 + receiverData.ch1_1;

ppm[1] = receiverData.ch2_0*256 + receiverData.ch2_1;

ppm[2] = receiverData.ch3_0*256 + receiverData.ch3_1;

ppm[3] = receiverData.ch4_0*256 + receiverData.ch4_1; ppm[4] = receiverData.ch5_0*256 + receiverData.ch5_1;

ppm[5] = receiverData.ch6_0*256+ receiverData.ch6_1;

ppm[6] = receiverData.ch7_0*256+ receiverData.ch7_1;

ppm(7) receiverData.ch8_0*256 + receiverData.ch8_1;

digitalWrite(LEDPin, HIGH); lastRecvTime = millis();
}

}else{

lastRecvTime = millis();

}

unsigned long now = millis();

if (now-lastRecvTime > SIGNAL_TIMEOUT) {

digitalWrite(LEDPin, LOW);

for(int i=0; i<CHANNEL_NUMBER; i++){

ppm[i]= 900;

}

}

char inputValuesString[200];

sprintf(inputValues String, "%3d,%3d,%d,%d,%d,%3d,%3d,%3d", ppm[0].ppm[1].ppm[2].ppm[3].ppm[4].ppm[5].ppm[6].ppm[7]); Serial.println(inputValuesString); }

ISR(TIMER1_COMPA_vect)( //leave this alone static boolean state = true; TCNT1 = 0; if (state) {//start pulse digitalWrite(sigPin, onState); OCR1A PULSE_LENGTH 2; state = false; } else { //end pulse and calculate when to start the next pulse static byte cur_chan_numb; static unsigned int calc_rest; digitalWrite(sigPin, lonState); state = true;

if(cur_chan_numb >= CHANNEL_NUMBER)( cur_chan_numb = 0; calc_rest = calc_rest + PULSE_LENGTH:// OCR1A (FRAME_LENGTH-calc_rest)*2;
calc_rest = 0;

}

else{ OCR1A = (ppm[cur_chan_numb] - PULSE_LENGTH)*2; calc_rest = calc_rest + ppm[cur_chan_numb]; cur_chan_numb++;

}

}

}
