#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc;
int Send = 7;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  rtc.begin();

  // Uncomment the following line if the DS3231 is not already set to the correct time.
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); // Set the current time on the RTC.

  pinMode(Send, OUTPUT);
}

void loop() {
  DateTime now = rtc.now();

  // Get the current hour and minute.
  int currentHour = now.hour();
  int currentMinute = now.minute();

  // Print RTC time to serial monitor.
  Serial.print("RTC Time: ");
  Serial.print(currentHour);
  Serial.print(":");
  Serial.println(currentMinute);

  // Check if the current time matches the specified clock hours.
  if ((currentHour == 0 || currentHour == 1 || currentHour == 2 || currentHour == 3 ||
       currentHour == 4 || currentHour == 5 || currentHour == 6 || currentHour == 7 ||
       currentHour == 8 || currentHour == 9 || currentHour == 10 || currentHour == 11 ||
       currentHour == 12 || currentHour == 13 || currentHour == 14 || currentHour == 15 ||
       currentHour == 16 || currentHour == 17 || currentHour == 18 || currentHour == 19 ||
       currentHour == 20 || currentHour == 21 || currentHour == 22 || currentHour == 23) &&
      currentMinute == 0) {
    digitalWrite(Send, HIGH); // Turn on the LED
    Serial.println("LED ON - Sending Data...");
    delay(20000);
    digitalWrite(Send, LOW); // Turn off the LED
    Serial.println("LED OFF - Data Sent Successfully");
  }else {
    int remainingMinutes = (60 - currentMinute) % 60;
    int remainingSeconds = (60 - now.second()) % 60;

    Serial.print("Time until next hour: ");
    Serial.print(remainingMinutes);
    Serial.print(" minutes ");
    Serial.print(remainingSeconds);
    Serial.println(" seconds");
  }
  delay(60000); // Wait for 1 minute
}
