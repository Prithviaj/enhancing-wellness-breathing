// Define pins for LEDs - store these in arrays since there are multiple LEDs.
// These are constant and won't change.
const int num_LEDs = 5; // Number of LEDs for each sensor

const int chest_LED_pins[] = {9, 10, 11, 12, 13}; // Chest sensor LED pins
const int belly_LED_pins[] = {8, 7, 6, 5, 4};     // Belly sensor LED pins

// Define pins for sensors and potentiometers
const int chest_sensor_pin = A0;
const int chest_min_adjust_pin = A1;
const int chest_max_adjust_pin = A2;
const int belly_min_adjust_pin = A3;
const int belly_max_adjust_pin = A4;
const int belly_sensor_pin = A5;

// Define variables for sensor and potentiometer readings
int chest_min_adjust_reading;
int chest_max_adjust_reading;
int chest_sensor_reading;
int belly_min_adjust_reading;
int belly_max_adjust_reading;
int belly_sensor_reading;

void setup() {
    Serial.begin(9600);
    for (int i = 0; i < num_LEDs; i++) {
        pinMode(chest_LED_pins[i], OUTPUT);
        pinMode(belly_LED_pins[i], OUTPUT);
    }
}

void loop() {
    // Read sensor and potentiometer values
    chest_min_adjust_reading = analogRead(chest_min_adjust_pin);
    chest_max_adjust_reading = analogRead(chest_max_adjust_pin);
    chest_sensor_reading = analogRead(chest_sensor_pin);

    belly_min_adjust_reading = analogRead(belly_min_adjust_pin);
    belly_max_adjust_reading = analogRead(belly_max_adjust_pin);
    belly_sensor_reading = analogRead(belly_sensor_pin);
    
    Serial.print("Chest Sensor: "); Serial.print(chest_sensor_reading);
    Serial.print(" | Belly Sensor: "); Serial.println(belly_sensor_reading);
    
    delay(500); // Adjust delay as needed
}
