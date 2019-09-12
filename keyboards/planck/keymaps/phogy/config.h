#pragma once

#ifdef AUDIO_ENABLE
#define STARTUP_SONG SONG(PLANCK_SOUND)
#endif

#define MIDI_ADVANCED

#define ENCODER_RESOLUTION 4
#ifdef COMBO_ENABLE
#define COMBO_COUNT 1
#define COMBO_TERM 80
#define TAPPING_TERM 125
#endif

/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
  #define EECONFIG_RGB_MATRIX (uint32_t *)16

