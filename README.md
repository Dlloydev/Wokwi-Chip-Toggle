# Wokwi-Chip-Toggle
## Description

Provides Toggle Outputs for a Pushbutton

![image](https://user-images.githubusercontent.com/63488701/214955301-cfcbcf23-e965-4e86-bafa-186a48099e17.png)

- Provides flip-flop style complementary outputs (Q and nQ).
- `Tog` (T) pushbutton input is initialized in INPUT_PULLUP mode.
- `Tog` (T) is debounced. The Bounce status of pushbutton has no effect on toggle operation.
- Always 1 toggle action for each pushbutton press.
- `chip_timer_event` will fire every 1 ms.
- Initial powerup status is `Q` LOW, `nQ` HIGH.



The actual source code for the chip lives in [src/main.c](https://github.com/Dlloydev/Wokwi-Chip-Toggle/blob/main/src/main.c), and the pins are described in [chip.json](https://github.com/Dlloydev/Wokwi-Chip-Toggle/blob/main/chip.json).

## Examples

[![Wokwi_badge](https://user-images.githubusercontent.com/63488701/212449119-a8510897-c860-4545-8c1a-794169547ba1.svg)](https://wokwi.com/projects/354961142671087617) Example with a pushbutton input and Toggle outputs connected to LEDs.

## License

This project is licensed under the MIT license. See the [LICENSE](https://github.com/Dlloydev/Wokwi-Chip-Debounce/blob/main/LICENSE) file for more details.
