# Programming Logic

> For each behaviour, create the mermaid flowchart. Start each flowchart with a Heading naming the functionality. Delete this comment prior to submission.

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