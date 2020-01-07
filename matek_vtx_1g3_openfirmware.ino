#include "util.h"

/* Led Cathode, set LOW to light LED */
#define LED_K1 PB_8

/* LED Anode - Set HIGH to light LED */
#define LED_CH4 PA_0
#define LED_CH5 PA_1
#define LED_CH6 PA_2
#define LED_CH7 PA_3
#define LED_CH8 PA_4
#define LED_CH9 PA_5
#define LED_CHH PA_6
#define LED_CHC PA_7
#define LED_CHD PB_0

/* VTX channel selection GPIO */
#define VTX_CS1 PA_8
#define VTX_CS2 PA_11
#define VTX_CS3 PA_12
#define VTX_S1 PA_15

/* User pushbutton */
#define KEY1 PF_0

/* Channel List */
struct {
  uint8_t led_pin;
  uint8_t vtx_s1_value;
  uint8_t vtx_cs1_value;
  uint8_t vtx_cs2_value;
  uint8_t vtx_cs3_value;
} channel_list[] = {
  // led_pin, s1, cs1, cs2, cs3 
  {  LED_CH4, 0, 0, 0, 0},
  {  LED_CH5, 0, 0, 0, 1},
  {  LED_CH6, 0, 0, 1, 0},
  {  LED_CH7, 0, 0, 1, 1},
  {  LED_CH8, 0, 1, 0, 0},
  {  LED_CH9, 0, 1, 0, 1},
  {  LED_CHH, 0, 1, 1, 0},
  {  LED_CHC, 0, 1, 1, 1},
  {  LED_CHD, 1, 1, 0, 0},
};

/* ------------------------------ */

static void activate_channel(int channel);
static void leds_off(void);

/* ------------------------------ */

void setup() {
  // put your setup code here, to run once:

  pinMode(LED_K1, OUTPUT);
  digitalWrite(LED_K1, HIGH);

  pinMode(LED_CH4, OUTPUT);
  pinMode(LED_CH5, OUTPUT);
  pinMode(LED_CH6, OUTPUT);
  pinMode(LED_CH7, OUTPUT);
  pinMode(LED_CH8, OUTPUT);
  pinMode(LED_CH9, OUTPUT);
  pinMode(LED_CHH, OUTPUT);
  pinMode(LED_CHC, OUTPUT);
  pinMode(LED_CHD, OUTPUT);
  leds_off();

  pinMode(VTX_CS1, OUTPUT);
  pinMode(VTX_CS2, OUTPUT);
  pinMode(VTX_CS3, OUTPUT);
  pinMode(VTX_S1, OUTPUT);

  pinMode(KEY1, INPUT);

  /* TODO: Activate the last used channel */
  activate_channel(0);

}
    
/* ------------------------------ */


void loop() {
  // put your main code here, to run repeatedly:
  int i;

  for( i = 0; i < NUMEL(channel_list); i++ ) {
    activate_channel(i);
    delay(5000);
  }
}

/* ------------------------------ */

static void leds_off(void) {
  digitalWrite(LED_K1, HIGH);
  digitalWrite(LED_CH4, LOW);
  digitalWrite(LED_CH5, LOW);
  digitalWrite(LED_CH6, LOW);
  digitalWrite(LED_CH7, LOW);
  digitalWrite(LED_CH8, LOW);
  digitalWrite(LED_CH9, LOW);
  digitalWrite(LED_CHH, LOW);
  digitalWrite(LED_CHC, LOW);
  digitalWrite(LED_CHD, LOW);
}

static void activate_channel(int channel) {
  if(channel >= NUMEL(channel_list)) return;

  leds_off();
  digitalWrite(channel_list[channel].led_pin, HIGH);
  digitalWrite(LED_K1, LOW);

  digitalWrite(VTX_S1, channel_list[channel].vtx_s1_value);
  digitalWrite(VTX_CS1, channel_list[channel].vtx_cs1_value);
  digitalWrite(VTX_CS2, channel_list[channel].vtx_cs2_value);
  digitalWrite(VTX_CS3, channel_list[channel].vtx_cs3_value);

  
}
