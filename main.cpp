int analog_input = A0; // Analog output of the sensor
int digital_input = 2; // Digital output of the sensor
  
void setup () {
  pinMode(analog_input, INPUT);
  pinMode(digital_input, INPUT);
  Serial.begin(9600); //begin serial at 9600 bps
}
  
void loop () {
  float analog_value;
  int digital_value;
    
  analog_value = analogRead(analog_input) * (5.0 / 1023.0); //converts analog signal to number between 0-5 
  digital_value = digitalRead(digital_input); //reads value of digital signal
    
  Serial.print("Analog voltage value: "); 
  Serial.print(analog_value, 4);
  Serial.print(" V, \t Threshold value: ");
  
  //if the temperature is over the set threshold, the digital value will be 1 and 0 otherwise
  if (digital_value == 1) {
      Serial.println("reached");
  }
  else {
      Serial.println("not yet reached");
  }
  Serial.println("----------------------------------------------------------------");
  delay(1000); //small pause for every loop update
}
