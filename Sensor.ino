void Temp_Sen() {
  sensor_Ds.requestTemperatures();
  float Celsius = sensor_Ds.getTempCByIndex(0);
  Read_Sen[0] = Celsius ; // For Real
 // Read_Sen[0] = DataTester[0] ; // For Tester
  delay(500);
}

void Dist_Sen() {
  float distance = sensor_Vl.readRangeContinuousMillimeters();
  distance = distance_media - (distance / 10);
  if (sensor_Vl.timeoutOccurred()) {
    Serial.print(" TIMEOUT VL53L0X");
  }
  Read_Sen[1] = distance;
 // Read_Sen[1] =DataTester[1] ;
  delay(500);
}

void Humi_Sen() {
  float humidity = sensor_Dht.readHumidity();
  Read_Sen[2] = humidity ;
  // Read_Sen[2] = DataTester[2] ;
  delay(500);
}

void Soil() {
  float moisture_percentage;
  int sensor_analog;
  sensor_analog = analogRead(sensor_pin);
  moisture_percentage = ( 100 - ( (sensor_analog/1023.00) * 100 ) );
  Read_Sen[3] =  moisture_percentage;
  delay(500);
}
