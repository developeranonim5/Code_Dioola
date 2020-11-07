const size_t Size_DataTraining = 46;
float knn[46][3], sorter[46][3];
//float DataTester[3];
float DataTester[3]={28.8, 6.5 ,69.3};
float Min_Dt[3], Max_Dt[3];
float Normalization_Trainer[Size_DataTraining ][3];
float Normalization_Tester[3];
float DataTriner[Size_DataTraining][4] = {
  { 33.3,  6.7,  65.2,1}, {30.2, 6.9,  71.2, 1}, {32.9,  5.6,  68.6,1}, {29.9, 5.3,  70.1, 1}, {30.1,  7.5,  70.9, 1},
  { 28.6,  6.8,  68.0,1}, {31.9, 5.4,  69.6, 1}, {36.1,  5.6,  74.1,1}, {32.9,  7.3,  73.2, 1}, {29.8,  7.1, 72.5, 1},
  { 35.4,  4.7,  76.7,1}, {34.3, 5.2,  77.3, 1}, {35.4,  5.9,  78.5,1}, { 37.8,  6.2,  79.8,1}, {35.8, 3.7, 75.7 , 1},
  { 33.4,  4.9, 80.6 ,1},

  {28.6, 4.1,  73.2, 2}, {27.2,  8.7,  75.9, 2}, {30.4,  3.2,  74.2, 2}, {29.4,  3.4,  76.6, 2},  {28.2, 6.2,  74.8, 2},
  {28.9, 3.6,  77.0, 2}, {28.7,  7.1,  78.0, 2}, {26.8,  8.2,  78.3, 2}, {24.3,  2.7,  78.9, 2},  {29.3, 3.2,  79.3, 2},
  {38.3, 8.8,  82.9, 2}, {38.1,  10.1, 79.3, 2}, {37.9,  9.2,  84.2, 2}, {38.9,  8.4,  85.1, 2},  {32.2, 8.5,  80.3, 2},

  {26.6, 2.8,  77.9, 3}, {27.8,  2.6,  78.6, 3}, {27.1,  10.5, 79.9, 3}, {22.9,  2.5,  78.3, 3}, {37.3,  12.3, 82.9, 3},
  {41.1, 9.3,  82.4, 3},  {25.1,  12.1, 85.7, 3},{23.9,  3.6,  83.2, 3}, {24.2,  2.7,  84.5, 3}, {42.9,  11.3, 91.0, 3},
  {41.0, 10.9, 90.0, 3}, {41.8,  7.1,  86.2, 3}, {43.2,  5.9,  94.9, 3}, {39.5, 9.6,  86.5, 3},  {42.5,  8.2,  93.2, 3},

};

void Normalization() {
  time_start = millis();
  memcpy(DataTester,  Read_Sen, sizeof(DataTester));
  Min_Dt[0] = DataTriner[0][0];
  Min_Dt[1] = DataTriner[0][1];
  Min_Dt[2] = DataTriner[0][2];
  Max_Dt[0] = DataTriner[0][0];
  Max_Dt[1] = DataTriner[0][1];
  Max_Dt[2] = DataTriner[0][2];

  //cari MIN MAX data Uji
  for (int a = 0; a < 3; a++) {
    Min_Dt[a] = min(Min_Dt[a], DataTester[a]);
    Max_Dt[a] = max(Max_Dt[a], DataTester[a]);
  }
  //cari MIN MAX data latih
  for (int a = 0; a < 3; a++) {
    for (int b = 0; b < 46; b++) {
      Min_Dt[a] = min(Min_Dt[a], DataTriner[b][a]);
      Max_Dt[a] = max(Max_Dt[a], DataTriner[b][a]);
    }
  }
//    Serial.println("\nMin\t Max");
//    Serial.print(Min_Dt[0],1); Serial.print("\t");
//    Serial.println(Max_Dt[0],1);
//    Serial.print(Min_Dt[1],1); Serial.print("\t");
//    Serial.println(Max_Dt[1],1);
//    Serial.print(Min_Dt[2],1); Serial.print("\t");
//    Serial.println(Max_Dt[2],1);

  //  Normalization Data latih
  for (int a = 0; a < 46; a++) {
    for (int b = 0; b < 3; b++) {
      //Nilai Normlalisai Ganti Data Latih
      Normalization_Trainer[a][b] = (DataTriner[a][b] - Min_Dt[b]) / (Max_Dt[b] - Min_Dt[b]);
    }
  }
   // Normalization Data Uji
  Serial.println("Normalized Tester ");
  for (int b = 0; b < 3; b++) {
    Normalization_Tester[b] = (DataTester[b] - Min_Dt[b]) / (Max_Dt[b] - Min_Dt[b]);
    Serial.print(Normalization_Tester[b]);
    Serial.print("  ");
  }
    Serial.println("    ");
    Serial.println("Normalized Trainer ");
    for (int a = 0; a < 46; a++) {
      Serial.print(a);
      Serial.print(". ");
      Serial.print(Normalization_Trainer[a][0]);
      Serial.print(" ");
      Serial.print(Normalization_Trainer[a][1]);
      Serial.print(" ");
      Serial.println(Normalization_Trainer[a][2]);
   }
  delay(500);

}
void KNNv2() {
  
  for (size_t a = 0; a < Size_DataTraining; a++) {
    knn[a][0] = sqrt(pow(Normalization_Trainer[a][0] - Normalization_Tester[0], 2) + pow(Normalization_Trainer[a][1] - Normalization_Tester[1], 2) + pow(Normalization_Trainer[a][2] - Normalization_Tester[2], 2));
    knn[a][1] = DataTriner[a][3];
  }
  memcpy(sorter, knn, sizeof(sorter));
  //sorting
  for (size_t a = 1; a < Size_DataTraining; a++) {
    for (size_t b = a; b > 0 && sorter[b - 1][0] > sorter [b][0]; b-- ) {
      float T[2];
      memcpy(T, sorter[b - 1], sizeof(T));
      memcpy(sorter[b - 1], sorter[b], sizeof(sorter[b - 1]));
      memcpy(sorter[b], T, sizeof(sorter[b]));
    }
  }
    Serial.print("\nDistance:  \n ");
    for (int a = 0; a < 46; a++) {
      Serial.print(a);
      Serial.print(". ");
      Serial.print(knn[a][0]);
      Serial.print("  ");
      Serial.print(knn[a][1]);
      Serial.print("\n ");
    }
    
    Serial.print("\nSorted\t");
    for (int a=0 ; a < k; a++) {
      Serial.print("\n ");
      Serial.println(sorter[a][0]);
      Serial.print(" ");
      Serial.println(sorter[a][1]);
   }
 delay(500);
}

void Class() {
  size_t vote = 0;
  int optimal = 0, sedang = 0, buruk = 0;
  KNNv2();
 // Serial.println("\t\nKondisi");
  while (vote < k) {

    //Ambil Nilai  Yang Sering Muncul
    if (sorter[vote][1] == 1 ) {
      optimal++;
    } else if (sorter[vote][1] == 2 ) {
      sedang++;
    }
    else if  (sorter[vote][1] == 3 ) {
      buruk++;
    }
    vote++;
  }
  if (optimal > sedang && optimal > buruk  ) {
   // Serial.print("optimal\n");
    label = "Optimal";
  }
  else if (sedang > optimal && sedang > buruk ) {
    //Serial.print("Sedang\n");
    label = "Sedang";

  } else if (buruk > optimal && buruk > sedang ) {
    //Serial.print("Buruk\n");
    label = "Buruk";
  }
  delay(500);
}
