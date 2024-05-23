#include <Arduino.h>
#include <Adafruit_VL53L0X.h>
#include <config.h>

Adafruit_VL53L0X sensor = Adafruit_VL53L0X();

void setup() {
  // put your setup code here, to run once:
  pinMode(DOUT, OUTPUT);
  digitalWrite(DOUT, LOW);

  Serial.begin(DEBUG_BAUD);

  // wait until serial port
  while (! Serial) {
    delay(1);
  }

  Serial.println(F("VL53L0X AutoLight Controller"));
  if (!sensor.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }

  sensor.setMeasurementTimingBudgetMicroSeconds(TIMING_BUDGET);
  sensor.startRangeContinuous(); // continuous reading mode
}

unsigned int reading = 819;

void loop() {
   if (sensor.isRangeComplete()) { // is the reading ready?
    reading = sensor.readRange(); // get reading
    Serial.println(reading);

    if (TRIP_MM > reading) { // sensor tripped?
      digitalWrite(DOUT, HIGH);
    } else {
      digitalWrite(DOUT, LOW);
    }
  }
}
