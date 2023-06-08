# Logic
> This is the Logic for each items in the Smart Solar Tracker Project.
## CrashSensor
```mermaid
flowchart TD
    Start([Crash Sensor])
    InputCrashSensor(Get Input)
    GetCrashSensorValue{Get values}
    CheckButton(Has the Button pressed)
    Activate(Re-run the project)
    Finish([End])

    Start --> InputCrashSensor --> GetCrashSensorValue --> CheckButton
    CheckButton --> |Yes| Activate
    CheckButton --> |No| Finish
``` 
## Servo Motor
```mermaid
flowchart TD
    Start([Servo Motor])
    GetServoMotorExtensionLibrary(Get Servo Motor extension library)
    InputServoMotor(Get Input)
    ReceiveLDRsValue{Receive LDRs value}
    SpinTheSolarCell(Rotate Solar Cell)
    PrintOutError([Print error])

    Start --> GetServoMotorExtensionLibrary --> InputServoMotor --> ReceiveLDRsValue
    ReceiveLDRsValue --> |Yes| SpinTheSolarCell
    ReceiveLDRsValue --> |No| PrintOutError
```

## Potentiometer
```mermaid
flowchart TD
    Start([Potentiometer])
    InputPotentiometer(Get Input)
    GetPotentiometerValues{Get fixed values}
    Check(Check)
    Activate(Run the project)
    Deactivate(Stop the project)
    Debug(Print the value)


    Start --> InputPotentiometer --> GetPotentiometerValues --> Check
    Check --> |<=1023| Activate --> Debug
    Check --> |>=100| Deactivate --> Debug
```
## LDRs
```mermaid
flowchart TD
    Start([LDRs])
    InputLDR1(Get east LDR Input)
    InputLDR2(Get west LDR Input)
    GetLDR1Values{Get values}
    GetLDR2Values{Get values}
    CheckForLightLevels(Check for observable light levels area)
    

    Start --> InputLDR1 --> GetLDR1Values --> CheckForLightLevels
    Start --> InputLDR2 --> GetLDR2Values --> CheckForLightLevels