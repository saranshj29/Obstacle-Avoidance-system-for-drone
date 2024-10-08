#include <Wire.h>

#include <VL53L0X.h>

const int MAX_SENSOR = 8;

int MIN DISTANCE 2000; // 2m

int WANR LEVEL = 1500; // under 1.5mm

String obstacle="";

char obstacle_b[4]="NN";

String arr_obstacle[] = ("NN", "NE", "EE", "SE", "SS", "SW", "ww", "NW");

VL53LBX arr sensor[MAX_SENSOR];

int s_pin[MAX_SENSOR] = 4, 5, 6, 7, 8, 9, 10, 11);

uint8_t s_address [MAX_SENSOR] ={1, 2, 3, 4, 5, 6, 10, 11);

                                 int directions_distance [MAX_SENSOR] = { 8196, 8190, 8190, 8190, 8190, 8190, 8190, 8190 } ;// error value is 8190

int LEDPin =2;
                                 void setup()

{

Serial.begin (115200); for(int i=0; i<MAX_SENSOR; i++){

pinMode(s_pin [1], OUTPUT);

digitalWrite(s_pin[1], LOW);

}

delay(500);

Wire.begin();

for (int i=0; i<MAX_SENSOR; i++) {

digitalWrite(s_pin[i], HIGH);

delay(150);

arr_sensor[i].init(true);

delay(100);

arr_sensor[i].setAddress(s_address[i]);

}

for(int i=0; i<MAX SENSOR; i++) {

arr_sensor [1], startContinuous();

}

pinMode (LEDPin, OUTPUT);

}

void loop()
  {

    WANR_LEVEL-map(analogRead (A0),0, 1023, 20,1500); // Potentiometer control obstacle detection range from 2cm to 150 cm

for(int i=0; i<MAX_SENSOR; i++) {

directions_distance[i]=arr_sensor[i].readRange Continuous Millimete

if(directions_distance[i] > -1 && directions_distance[i] < 8190) [

if(directions_distance[1] <= MIN_DISTANCE) {

MIN_DISTANCE=directions_distance[i];

obstacle arr_obstacle[i];

obstacle.toCharArray (obstacle_b, 4);

}

1

//Serial.print(directions_distance [1]); Serial.print(" ");

}

if(MIN_DISTANCE < WANR LEVEL) {

  Serial.write(obstacle_b,4); //If Obstacle detected!! Send serial direction signal to ppm reciever
//Serial.println(obstacle);

digitalWrite(LEDPin, HIGH);

}else{

digitalWrite(LEDPin, LOW);

MIN DISTANCE-2006;

obstacle:""

obstacle_b[4]="";
                                 
