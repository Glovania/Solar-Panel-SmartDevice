# Logic
> For each behaviour, create the mermaid flowchart. Start each flowchart with a Heading naming the functionality. Delete this comment prior to submission.

## CrashSensor
```mermaid
flowchart TD
    Start([Crash Sensor])
    InputTheButton(Get Input)
    DetermineCrashSensorValue{Get Value}
    PressedTheButton(Has the Button pressed)
    Activate(Run the Arduino Uno Board)
    finish([End])

    Start --> InputTheButton --> DetermineCrashSensorValue --> PressedTheButton
    PressedTheButton --> |Yes| Activate
    PressedTheButton --> |No| finish
``` 
## Servo Motor
```mermaid
flowchart TD
    Start([Servo Motor])
    GetServoExtensionLibrary(Get Library)
    InputServo(Get Input)
    

    Start --> GetServoExtensionLibrary --> InputServo
```