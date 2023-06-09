# Logic
> This is the Logic for each items in the Smart Solar Tracker Project.

## CrashSensor
```mermaid
flowchart TD
%% Comment
    Start([Crash Sensor])
    InputCrashSensor(Get Input)
    GetCrashSensorValue{Get values}
    CheckButton(Has the Button pressed)
    Activate(Re-run the project)
    Finish([End])

    Start --> InputCrashSensor --> GetCrashSensorValue --> CheckButton
    CheckButton -.-> |Yes| Activate
    CheckButton -.-> |No| Finish
``` 

## Servo Motor
```mermaid
flowchart TD
%% Comment
    Start([Servo Motor])
    GetServoMotorExtensionLibrary(Get Servo Motor extension library)
    InputServoMotor(Get Input)
    ReceiveLDRsValue{Receive LDRs value}
    SpinTheSolarCell(Rotate Solar Cell)
    PrintOutError([Print error])

    Start --> GetServoMotorExtensionLibrary --> InputServoMotor --> ReceiveLDRsValue
    ReceiveLDRsValue -.-> |Yes| SpinTheSolarCell
    ReceiveLDRsValue -.-> |No| PrintOutError
```

## LDRs
```mermaid
flowchart TD
%% Comment
    Start([LDRs])
    InputLDR1(Get east LDR Input)
    InputLDR2(Get west LDR Input)
    GetValues{Get values}
    CheckForLightLevels(Check for observable light levels area)
    SentValueToServoMotor(Sent the value to Servo Motor)
    PrintOutError([Print error])


    Start --> InputLDR1 --> GetValues
    Start --> InputLDR2 --> GetValues
    
    GetValues --> CheckForLightLevels

    CheckForLightLevels -.-> |Detected| SentValueToServoMotor
    CheckForLightLevels -.-> |Undetected| PrintOutError