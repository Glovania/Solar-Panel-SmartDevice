# Solar Panel Theme
## Smart Solar Tracker

 > I have always wondered how Solar panels can track the Sun from that far away. Because of that, I have decided to make a simple Solar Tracker that demonstrates how the Solar Panel works. It will need the following items: 1x Arduino Uno Rev3 board, 1x SG90 Servo Motor 9g, 1x Crash Sensor, 1x Solar Cell, 2x LDRs (Light dependent resistors) and 2x 10k Ohm 0.5 Watt Resistors. Servo will be acted as an output. Firstly, when the Arduino Uno board is activated, it will start the function for each specific attached input, which is: Servo, Crash Sensor, and the 2 LDRs. When the LDRs function run, it will start checking for the observable light areas. Then, it will send the values to Servo to start rotating. When Servo received the "information", will start spinning the Solar Cell according to the light values that LDRs have given. Meanwhile, the Crash Sensor will act as a stop button for the project whenever you click the button. To improve the program more, I would make the code more complicated by making the Solar Cell able to transfer the light energies into electricity so that it could light up traffic lights.
# Behaviour
## Function

- When we click the Crash sensor, Solar Tracker program will stop and vice versa.

- When LDRs are activated, detect light levels and sent the value to Servo Motor to start rotating with the observable sun light. (Can use phone's flashflight for a quick demostration).

- When Servo Motor is activated, rotate the Solar Panel based on the light detected from the LDR's values.