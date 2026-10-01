# Fire Detection

This project uses an Arduino to detect fire using three analog flame/fire sensors and control a servo based on the detected direction.

## Project Image

![Fire alarm system setup](<./Fire%20Alarm%20Systm.jpg>)

> Note: This image shows the Version 1 setup of the project. The servo-based directional control is part of the current Arduino implementation, but the servo is not visible in this image because the photo was taken before that version was added.

## Overview

The system reads values from three sensors connected to analog pins:

- A0: Left sensor
- A1: Center sensor
- A2: Right sensor

If a sensor value drops below a defined threshold, the Arduino determines which side is detecting fire and rotates the servo toward that direction. This project does not include a physical water nozzle; the servo movement is for directional positioning only.

## Features

- Fire detection using three analog sensors
- Direction-based response for left, center, and right fire detection
- Servo positioning for directional control
- Serial monitoring for debugging sensor readings

## Hardware Used

- Arduino Uno / compatible board
- 3 flame/fire detection sensors
- Servo motor
- Jumper wires and breadboard
- Power supply

## Pin Configuration

| Component     | Arduino Pin |
| ------------- | ----------- |
| Left sensor   | A0          |
| Center sensor | A1          |
| Right sensor  | A2          |
| Servo signal  | 3           |

## Calibration

The threshold is defined in the code as:

```cpp
const int fireThreshold = 300;
```

If your sensors are more or less sensitive, adjust this value to match your environment.

## How It Works

1. The Arduino reads the analog values from all three sensors.
2. If the reading is below the threshold, it assumes fire was detected.
3. Based on which sensor triggered, the servo rotates to the corresponding angle:
   - Left: 0°
   - Center: 90°
   - Right: 180°
4. The system prints status information to the serial monitor for debugging.

## Upload Instructions

1. Open `Fire_Detection.ino` in the Arduino IDE.
2. Connect the Arduino to your computer.
3. Select the correct board and port.
4. Click Upload.
5. Open the Serial Monitor to observe the sensor readings and detection status.

## Notes

- The sensor threshold may need adjustment depending on ambient lighting and sensor quality.
- Use the serial monitor during calibration to see the actual readings.
- This is a basic prototype for an automated fire-response system.

## Related Files

- `Fire_Detection.ino` — Arduino source code
- `Fire Alarm Systm.jpg` — system image
- `Fire Alarm System Using Arduino.pdf` — project documentation/reference
