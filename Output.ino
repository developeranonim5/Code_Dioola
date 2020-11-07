void outsystem() {

  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("TEMP:");
  lcd.print(Read_Sen[0], 1);
  
  lcd.setCursor(10, 0);
  lcd.print("HIGH:");
  lcd.print(Read_Sen[1], 1);
 
  
  lcd.setCursor(0, 1);
  lcd.print("AIR :");
  lcd.print(Read_Sen[2], 1);
  
  lcd.setCursor(10, 1);
  lcd.print("SOIL:");
  lcd.print(Read_Sen[3], 1);
 
  
  Serial.println("\t\t==Result Enviroment Smart Thrash==");
  Serial.print("Temperature:");
  Serial.print(Read_Sen[0], 1);
  Serial.print(" | ");
  Serial.print("Distance: ");
  Serial.print(Read_Sen[1], 1);
  Serial.print(" | ");
  Serial.print("Humidity:");
  Serial.print(Read_Sen[2], 1);
  Serial.print(" | ");
  Serial.print("Soil:");
  Serial.print(Read_Sen[3], 1);
  Serial.print(" | ");

//  Serial.print("Fan:");
//  Serial.print("On");
//  Serial.print(" | ");

  

  

  //  Serial.print("Category:");
  //  Serial.print(label);
  //  Serial.print(" | ");
  //  Serial.print("K:");
  //  Serial.print(k);
  //  Serial.print(" | ");
  //  time_end = millis();
  //  result_time = (time_end - time_start);
  //  Serial.print("Cumputation Time:");
  //  Serial.print(result_time);
  Serial.print("\n");

}
