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
#define COMBO_COUNT 4
#define COMBO_TERM 40
#define TAPPING_TERM 125
#endif

#define PLANCK_EZ_USER_LEDS
#ifndef PLANCK_EZ_USER_LEDS
  #define PLANCK_EZ_LED_LOWER 1
  #define PLANCK_EZ_LED_RAISE 2
  #define PLANCK_EZ_LED_ADJUST 3
#endif

/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR

