# Embedded Leakage Notification Demo

Arduino-style embedded C/C++ demo simulating moisture/leakage detection with threshold logic, state handling, LED/buzzer alerts, and serial output.

## Purpose

The purpose of this project was to get hands-on experience with basic embedded software concepts, including sensor input, threshold logic, state handling, serial output, and simple alert behaviour.

The project is inspired by embedded notification systems where software reacts to sensor input and provides a clear warning when a threshold is reached.

## Components

- Arduino Uno
- Potentiometer used as simulated moisture sensor
- LED for warning indication
- Buzzer for alert sound
- Serial Monitor for debugging/output

## How it works

The potentiometer simulates a moisture sensor by producing an analog input value between 0 and 1023.

- Low value: normal/dry state
- High value: possible leakage detected

The system has two states:

- `NORMAL`
- `WARNING`

When the sensor value reaches the leakage threshold, the system enters `WARNING` state, turns on the LED, activates the buzzer briefly, and prints the warning status to the Serial Monitor.

When the sensor value drops below the reset threshold, the system returns to `NORMAL` state and turns off the LED.

## Threshold logic

The demo uses two thresholds:

- Leakage threshold: 650
- Reset threshold: 550

Using two thresholds prevents the system from rapidly switching between normal and warning states when the sensor value is close to the limit. This is a simple form of hysteresis.

## Files

- `leakage_notification_demo.ino` — Arduino C/C++ source code
- `normal-state.png` — screenshot of the system in normal state
- `warning-state.png` — screenshot of the system in warning state

## What I learned

Through this project, I practiced:

- Reading analog sensor input
- Writing basic Arduino C/C++ logic
- Working with output components such as LED and buzzer
- Using state handling with `NORMAL` and `WARNING`
- Avoiding repeated unnecessary alerts
- Printing system status to the Serial Monitor
- Thinking about simple memory-conscious embedded code structure

## Possible improvements

Future improvements could include:

- Using a real moisture sensor instead of simulated input
- Adding calibration for different sensor ranges
- Adding battery-saving sleep behaviour
- Reducing serial output for low-power operation
- Adding wireless notification, for example BLE
- Testing on real Arduino or ESP32 hardware
