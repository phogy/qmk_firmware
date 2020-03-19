#pragma once

/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#ifdef AUDIO_ENABLE
#define STARTUP_SONG SONG(PLANCK_SOUND)
#endif

#define MIDI_ADVANCED

#define ENCODER_RESOLUTION 4
#ifdef COMBO_ENABLE
#define COMBO_COUNT 5
#define COMBO_TERM 40
#endif
#define TAPPING_TERM 125

#define MK_3_SPEED
#define MK_MOMENTARY_ACCEL
#define MK_C_OFFSET_UNMOD 4
#define MK_C_OFFSET_0 1
#define MK_C_OFFSET_1 20
#define MK_C_OFFSET_2 50

#define PLANCK_EZ_USER_LEDS
#ifndef PLANCK_EZ_USER_LEDS
  #define PLANCK_EZ_LED_LOWER 1
  #define PLANCK_EZ_LED_RAISE 2
  #define PLANCK_EZ_LED_ADJUST 3
#endif

#define RGB_MATRIX_HUE_STEP 2
/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR

