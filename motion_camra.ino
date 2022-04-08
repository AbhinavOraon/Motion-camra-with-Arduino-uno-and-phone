/* @Aouther-
 *  Abhinav Etwa Oraon
 *  OmegaElectronicss
 */
 
uint8_t buf[8] = { 0 };//Keyboard report buffer
//unit_8 is a type of unsigned integer of length 8 bits
#define echoPin 2 // attach pin 2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin 3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
if (distance<40){//if some one cross from the sensor
 buf[2] = 40;   //Press the enter key!
Serial.write(buf, 8); //"PHOTO CLICKED"
releaseKey();//Release the key Function









delay(100); 
}
}
//---------------------------------------------------------------------------------------------------------------------------------
void releaseKey() //function to release the key. 
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8); // Send Release key  
}
