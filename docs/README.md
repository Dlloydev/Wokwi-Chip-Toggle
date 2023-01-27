# Wokwi Toggle Chip

This custom chip for [Wokwi](https://wokwi.com/) provides Toggle flip-flop complementary outputs to a pushbutton.

![image](https://user-images.githubusercontent.com/63488701/214955301-cfcbcf23-e965-4e86-bafa-186a48099e17.png)

- `Tog` (T) pushbutton input is initialized in INPUT_PULLUP mode.
- `Tog` (T) is debounced. The Bounce status of pushbutton has no effect on toggle operation.
- Always 1 toggle action for each pushbutton press.
- `chip_timer_event` will fire every 1 ms.
- Initial powerup status is `Q` LOW, `nQ` HIGH.

## Pin names

| Name | Description                                                |
| ---- | ---------------------------------------------------------- |
| Tog  | Input for pushbutton control, configured INPUT_PULLUP mode |
| Q    | Output, initial state is LOW                               |
| nQ   | Inverted Output, initial state is HIGH                     |
| GND  | Ground                                                     |
| VCC  | Supply voltage                                             |

## Usage

To use this chip in your project, include it as a dependency in your `diagram.json` file:

```json
  "dependencies": {
    "chip-toggle": "github:Dlloydev/Wokwi-Chip-toggle@1.0.0"
  }
```

Then, add the chip to your circuit by adding a `chip-toggle` item to the `parts` section of `diagram.json`:

```json
  "parts": {
    ...,
    { "type": "chip-toggle", "id": "toggle1" }
  },
```

For a complete example, see [the inverter chip test project](https://wokwi.com/projects/350946636543820370).

