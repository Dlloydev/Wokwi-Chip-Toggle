/* Toggle Chip by Dlloydev */

#include "wokwi-api.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  pin_t pin_tog;
  pin_t pin_q;
  pin_t pin_nq;
  uint8_t val;
  uint8_t valp;
  bool status;
} chip_state_t;

static void chip_timer_event(void *user_data);

void chip_init(void) {
  chip_state_t *chip = malloc(sizeof(chip_state_t));
  chip->pin_tog = pin_init("Tog", INPUT_PULLUP);
  chip->pin_q = pin_init("Q", OUTPUT);
  chip->pin_nq = pin_init("nQ", OUTPUT);
  pin_write(chip->pin_nq, HIGH);
  chip->valp = 255;
  chip->val = 255;
  chip->status = false;

  const timer_config_t timer_config = {
    .callback = chip_timer_event,
    .user_data = chip,
  };
  timer_t timer_id = timer_init(&timer_config);
  timer_start(timer_id, 1000, true);  // 1 ms
}

static void chip_timer_event(void *user_data) {
  chip_state_t *chip = (chip_state_t*)user_data;

  // update reading shift register
  chip->val <<= 1;
  chip->val |= pin_read(chip->pin_tog) & 1;

  // detect if falling edge but only if stable for 3 readings
  if ((chip->valp & 7) > 0 && (chip->val & 7) == 0) {
    chip->status = !chip->status;  // toggle
    pin_write(chip->pin_q, chip->status);
    pin_write(chip->pin_nq, !chip->status);
  }
 chip->valp = chip->val;
}
