# Logic
> For each behaviour, create the mermaid flowchart. Start each flowchart with a Heading naming the functionality. Delete this comment prior to submission.

## CrashSensor

## Servo

## Buzzer system

```mermaid
flowchart TD
    Start([Buzzer])
    getButtonStatus(Get button status)
    checkButton{Has button pressed}
    soundBuzzer(Play sound)
    finish([End])

    Start --> getButtonStatus --> checkButton
    checkButton --> |Yes| soundBuzzer
    checkButton --> |No| finish
    soundBuzzer --> finish
```

## LEDLights system
```mermaid
flowchart TD
    Start([LEDLights])
    getAllThreeLights(Get Red,Yellow & Green LED Lights)
    checkElectricDetected{Light up the LED Lights}
    LEDLightsActivated(Activated)
    finish([End])

    Start --> getAllThreeLights --> checkElectricDetected
    checkElectricDetected --> |Yes| LEDLightsActivated
    checkElectricDetected --> |No| finish
    LEDLightsActivated --> finish
```