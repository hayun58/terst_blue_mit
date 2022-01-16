#include <SoftwareSerial.h>
SoftwareSerial mySerial(A1, A0); // RX, TX

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
}

int cnt = 0;
String str;

void loop() {
  str = "c" + String(cnt);
  mySerial.print(str);
   Serial.println(str);
  if (cnt < 99) cnt++;
  else cnt = 0;

  if (mySerial.available()) {
    char tav = mySerial.read() ;
    Serial.println(tav);
    if (tav == 's')  cnt = 0;
  }
  delay(1000);
}
