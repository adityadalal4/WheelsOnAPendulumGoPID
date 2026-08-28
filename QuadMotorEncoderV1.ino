const uint8_t PIN_A = 2;
const uint8_t PIN_B = 3;


const int PULSES_PER_REV = 370;

volatile long pulseCount = 0;
long count;


void setup() {
  Serial.begin(115200);
  
  
  pinMode(PIN_A, INPUT);  
  pinMode(PIN_B, INPUT);Serial.println(count);
  
  // Interrupt on every change of channel. This is a 2-edge
  // decode (resolution of full quadrature decoding on both edges
  // of both channels) - simplest correct starting point, can upgrade
  // resolution later once this works.
  attachInterrupt(digitalPinToInterrupt(2), handleA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), handle, CHANGE);
}

void loop() {interrupts();
  static unsigned long lastPrint = 0;
  unsigned long now = millis();
  
  if (now - lastPrint >= 100) {  // print 10x per second
    lastPrint = now;
    
    
    
    noInterrupts();       // briefly disable interrupts to safely read the
    
    count = pulseCount;    // volatile variable without a race condition
    if (count<=0){Serial.println(count/584.0*(370-10));}
    else {Serial.println((count/584.0*(370-10)));}
    interrupts(); 

    

    
  }}
void handleA() {
  // Read both channels to determine direction.
  float a = digitalRead(PIN_A);
  float b = digitalRead(PIN_B);
  
  // Standard quadrature decode logic: if A and B differ, one direction;
  if (a-b){
  pulseCount++;}
  // Standard quadrature decode logic: if A and B differ, one direction;
  else { 
  pulseCount--;}
  }
void handle() {
  // Read both channels to determine direction.
  float a = digitalRead(PIN_A);
  float b = digitalRead(PIN_B);
  
  // Standard quadrature decode logic: if A and B differ, one direction;
  if (a-b){
  pulseCount--;}
  // Standard quadrature decode logic: if A and B differ, one direction;
  else { 
  pulseCount++;}
  
}