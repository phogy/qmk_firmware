#include QMK_KEYBOARD_H
#include "muse.h"
#include "eeprom.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define NO_TH ALGR(KC_T)
#define NO_ETH ALGR(KC_D)

enum planck_keycodes {
  RGB_SLD = SAFE_RANGE,
  TOGGLE_LAYER_COLOR,
  EPRM,
  GRAVE_NORDIC,
  TILDE_NORDIC,
  CIRC_NORDIC
};

enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FUNCTION,
  _MIDIPAD,
  _MIDIPIANO,
  _MIDISCALE,
  _MOUSE
};


#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_LOWER] = LAYOUT_planck_grid(
            RALT(KC_7), RALT(KC_0), RALT(KC_8), RALT(KC_9), RALT(KC_4), KC_PSCREEN,
            KC_RBRACKET, NO_APOS, LSFT(NO_PLUS), LSFT(KC_6), NO_LESS, LSFT(NO_LESS),
            NO_SCLN, NO_SLSH, NO_LPRN, NO_RPRN, RALT(NO_LESS), LSFT(KC_TAB),
            KC_DELETE, LSFT(KC_3), NO_MINS, GRAVE_NORDIC, LSFT(KC_2), TILDE_NORDIC,
            NO_COLN, NO_EQL, NO_AT, LSFT(KC_1), RALT(KC_MINUS), NO_UNDS,
            KC_ENTER, LSFT(KC_5), NO_PLUS, LSFT(NO_APOS), CIRC_NORDIC, NO_HALF,
            KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,KC_TRANSPARENT,
            KC_NO, KC_TRANSPARENT, KC_MEDIA_NEXT_TRACK, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, NO_UNDS),

  [_BASE] = LAYOUT_planck_grid(
            NO_AM, NO_AE, NO_OSLH, KC_P, KC_Y, KC_ESCAPE,
            NO_ACUT, KC_F, KC_G, KC_C, KC_R, KC_L,
            KC_A, KC_O, KC_E, KC_U, KC_I, KC_TAB,
            KC_BSPACE, KC_D, KC_H, KC_T, KC_N, KC_S,
            KC_DOT, KC_Q, KC_J, KC_K, KC_X, KC_COMMA,
            KC_ENTER, KC_B, KC_M, KC_W, KC_V, KC_Z,
            MO(_FUNCTION), KC_LCTRL, KC_LALT, KC_LSHIFT, LOWER, KC_SPACE,
            KC_NO, RAISE, KC_RSHIFT, KC_RALT, KC_LGUI, NO_MINS),


  [_RAISE] = LAYOUT_planck_grid(
            KC_1,KC_2,KC_3,KC_4,KC_5,KC_BRK,
            KC_INSERT,KC_6,KC_7,KC_8,KC_9,KC_0,
            KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_TRANSPARENT,
            KC_TRANSPARENT,KC_PGUP,KC_HOME,KC_UP,KC_END,KC_F11,
            KC_TRANSPARENT,KC_F7,KC_F8,KC_F9,KC_F10,KC_TRANSPARENT,
            KC_TRANSPARENT,KC_PGDOWN,KC_LEFT,KC_DOWN,KC_RIGHT,KC_ENTER,
            KC_F6,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
            KC_NO,KC_TRANSPARENT,KC_AUDIO_VOL_UP,KC_MEDIA_PLAY_PAUSE,KC_AUDIO_VOL_DOWN,KC_F12),

  [_ADJUST] = LAYOUT_planck_grid(
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,AU_TOG,MU_TOG,MU_MOD,KC_TRANSPARENT,
    KC_TRANSPARENT,RGB_TOG,RGB_VAI,RGB_VAD,KC_TRANSPARENT,RESET,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    TOGGLE_LAYER_COLOR,RGB_MOD,RGB_HUI,RGB_HUD,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_NO,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

  [_FUNCTION] = LAYOUT_planck_grid(
    TO(_MIDIPAD),TO(_MOUSE),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_RBRACKET,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_7,KC_8,KC_9,LSFT(NO_APOS),
    TO(_MIDIPIANO),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LSFT(NO_ACUT),
    KC_TRANSPARENT,KC_TRANSPARENT,KC_4,KC_5,KC_6,NO_MINS,
    TO(_MIDISCALE),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,NO_ACUT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_1,KC_2,KC_3,NO_PLUS,
    KC_TRANSPARENT,LSFT(KC_DELETE),LCTL(KC_INSERT),LSFT(KC_INSERT),KC_NO,KC_TRANSPARENT,
    KC_NO,KC_TRANSPARENT,KC_0,KC_DOT,KC_COMMA,KC_ENTER),

  [_MIDIPAD] = LAYOUT_planck_grid(
    MI_C_3, MI_Cs_3, MI_D_3, MI_Ds_3, MI_E_3, MI_F_3, MI_Fs_3, MI_G_3, MI_Gs_3, MI_A_3, MI_As_3, MI_B_3,
    MI_C_2, MI_Cs_2, MI_D_2, MI_Ds_2, MI_E_2, MI_F_2, MI_Fs_2, MI_G_2, MI_Gs_2, MI_A_2, MI_As_2, MI_B_2,
    MI_C_1, MI_Cs_1, MI_D_1, MI_Ds_1, MI_E_1, MI_F_1, MI_Fs_1, MI_G_1, MI_Gs_1, MI_A_1, MI_As_1, MI_B_1,
    TO(_BASE), KC_NO, KC_NO, KC_NO, MI_OCTD, MI_ALLOFF, KC_NO, MI_OCTU, KC_NO, KC_NO, MI_TRNSD, MI_TRNSU
  ),

  [_MIDIPIANO] = LAYOUT_planck_grid(
    MI_VEL_1, MI_VEL_2, MI_VEL_3, MI_VEL_4, MI_VEL_5, MI_VEL_6,
    MI_VEL_7, MI_VEL_8, MI_VEL_9, MI_VEL_10, KC_NO, KC_NO,
    KC_NO, MI_Cs, MI_Ds, KC_NO, MI_Fs, MI_Gs, MI_As, KC_NO, MI_Cs_1, MI_Ds_1, KC_NO, MI_Fs_1,
    MI_C, MI_D, MI_E, MI_F, MI_G, MI_A, MI_B, MI_C_1, MI_D_1, MI_E_1, MI_F_1, MI_G_1,
    TO(_BASE), KC_NO, KC_NO, KC_NO, MI_OCTD, MI_ALLOFF, KC_NO, MI_OCTU, KC_NO, KC_NO, MI_TRNSD, MI_TRNSU
  ),

  [_MIDISCALE] = LAYOUT_planck_grid(
    MI_B_1, MI_C_2, MI_D_2, MI_E_2, MI_F_2, MI_G_2, MI_A_2, MI_B_2, MI_C_3, MI_D_3, MI_E_3, MI_F_3,
    MI_F_1, MI_G_1, MI_A_1, MI_B_1, MI_C_2, MI_D_2, MI_E_2, MI_F_2, MI_G_2, MI_A_2, MI_B_2, MI_C_3,
    MI_C_1, MI_D_1, MI_E_1, MI_F_1, MI_G_1, MI_A_1, MI_B_1, MI_C_2, MI_D_2, MI_E_2, MI_F_2, MI_G_2,
    TO(_BASE), KC_NO, KC_NO, KC_NO, MI_OCTD, MI_ALLOFF, KC_NO, MI_OCTU, KC_NO, KC_NO, MI_TRNSD, MI_TRNSU
  ),

  [_MOUSE] = LAYOUT_planck_grid(
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_BTN3,KC_MS_ACCEL1,KC_MS_ACCEL2,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_MS_WH_UP,KC_NO,KC_MS_UP,KC_NO,KC_MS_ACCEL0,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_MS_WH_DOWN,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_MS_BTN2,
    TO(_BASE),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_NO,KC_TRANSPARENT,KC_MS_BTN1,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

};

#ifdef COMBO_ENABLE
    const uint16_t PROGMEM escape_combo[] = {NO_AM, NO_AE, COMBO_END};
    combo_t key_combos[COMBO_COUNT] = {COMBO(escape_combo, KC_ESC)};
#endif


extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;
bool disable_layer_color = 0;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [_BASE] = { {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {134,255,213},
            {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255},
            {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {134,255,213},
            {134,255,213}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255},
            {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255},
            {134,255,213}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255},
            {85,203,158}, {32,176,255}, {32,176,255}, {32,176,255}, {243,222,234}, {0,0,0},
            {243,222,234}, {32,176,255}, {32,176,255}, {32,176,255}, {0,0,255} },

    [_LOWER] = { {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {205,200,255},
            {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255},
            {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {134,255,213},
            {249,228,255}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255},
            {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255},
            {134,255,213}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {243,222,234}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {32,176,255} },

    [_RAISE] = { {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {205,200,255},
            {134,255,213}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255},
            {85,203,158}, {85,203,158}, {85,203,158}, {85,203,158}, {85,203,158}, {141,255,233},
            {141,255,233}, {0,205,155}, {0,205,155}, {134,255,213}, {0,205,155}, {85,203,158},
            {0,0,255}, {85,203,158}, {85,203,158}, {85,203,158}, {85,203,158}, {0,0,255},
            {0,0,0}, {0,205,155}, {134,255,213}, {134,255,213}, {134,255,213}, {141,255,233},
            {85,203,158}, {32,176,255}, {32,176,255}, {32,176,255}, {243,222,234}, {0,0,0},
            {243,222,234}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158} },

    [_ADJUST] = { {34,119,83}, {34,119,83}, {34,119,83}, {34,119,83}, {34,119,83}, {34,119,83},
            {34,119,83}, {34,119,83}, {34,119,83}, {34,119,83}, {34,119,83}, {34,119,83},
            {34,119,83}, {34,119,83}, {243,222,234}, {32,176,255}, {134,255,213}, {34,119,83},
            {34,119,83}, {14,255,255}, {0,0,255}, {33,255,255}, {34,119,83}, {243,222,234},
            {34,119,83}, {34,119,83}, {34,119,83}, {34,119,83}, {34,119,83}, {34,119,83},
            {0,0,255}, {30,96,255}, {33,255,255}, {33,255,255}, {34,119,83}, {34,119,83},
            {34,119,83}, {34,119,83}, {34,119,83}, {34,119,83}, {243,222,234}, {34,119,83},
            {243,222,234}, {34,119,83}, {34,119,83}, {34,119,83}, {34,119,83} },

    [_FUNCTION] = { {134,255,255}, {31,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255},
            {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0},
            {134,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255},
            {134,255,213}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {32,176,255},
            {134,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255},
            {134,255,213}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {32,176,255},
            {0,0,0}, {134,255,213}, {134,255,213}, {134,255,213}, {0,0,0}, {0,0,0},
            {243,222,234}, {0,0,255}, {32,176,255}, {32,176,255}, {134,255,213} },

    [_MIDIPAD] = { {134,255,128},{134,255,128},{134,255,128},{134,255,128},{134,255,128},{134,255,128},
                {134,255,128},{134,255,128},{134,255,128},{134,255,128},{134,255,128},{134,255,128},
                {134,255,96},{134,255,96},{134,255,96},{134,255,96},{134,255,96},{134,255,96},
                {134,255,96},{134,255,96},{134,255,96},{134,255,96},{134,255,96},{134,255,96},
                {134,255,64},{134,255,64},{134,255,64},{134,255,64},{134,255,64},{134,255,64},
                {134,255,64},{134,255,64},{134,255,64},{134,255,64},{134,255,64},{134,255,64},
                {85,203,158},{0,0,0},{0,0,0},{0,0,0},{243,222,234},{0,0,0},
                {243,222,234},{0,0,0},{0,0,0},{32,176,255},{32,176,255} },

    [_MIDIPIANO] = { {0,0,20},{0,0,40},{0,0,60},{0,0,80},{0,0,100},{0,0,120},
                {0,0,140},{0,0,160},{0,0,180},{0,0,200},{0,0,0},{0,0,0},
                {0,0,0},{134,255,213},{134,255,213},{0,0,0},{134,255,213},{134,255,213},
                {134,255,213},{0,0,0},{134,255,213},{134,255,213},{0,0,0},{134,255,213},
                {0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},
                {0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},
                {85,203,158},{0,0,0},{0,0,0},{0,0,0},{243,222,234},{0,0,0},
                {243,222,234},{0,0,0},{0,0,0},{32,176,255},{32,176,255} },

    [_MIDISCALE] = { {0,0,255},{134,255,213},{0,0,255},{0,0,255},{0,0,255},{0,0,255},
                {0,0,255},{0,0,255},{134,255,213},{0,0,255},{0,0,255},{0,0,255},
                {0,0,255},{0,0,255},{0,0,255},{0,0,255},{134,255,213},{0,0,255},
                {0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{134,255,213},
                {134,255,213},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},
                {0,0,255},{134,255,213},{0,0,255},{0,0,255},{0,0,255},{0,0,255},
                {85,203,158},{0,0,0},{0,0,0},{0,0,0},{243,222,234},{0,0,0},
                {243,222,234},{0,0,0},{0,0,0},{32,176,255},{32,176,255} },

    [_MOUSE] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0}, {35,255,255}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {0,183,238}, {33,255,255}, {0,0,0}, {31,255,255}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {141,255,233}, {33,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {85,203,158},
            {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {243,222,234}, {169,120,255}, {0,0,0}, {0,0,0}, {0,0,0} },
};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        rgb_matrix_set_color( i, rgb.r, rgb.g, rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || disable_layer_color) { return; }
  set_layer_color(biton32(layer_state));
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case RGB_TOG:
  if (record->event.pressed) {
    if (rgb_matrix_config.val) {
      rgb_matrix_sethsv(rgb_matrix_config.hue, rgb_matrix_config.sat, 0);
    } else {
      rgb_matrix_sethsv(rgb_matrix_config.hue, rgb_matrix_config.sat, 255);
    }
  }
  return false;
    case TOGGLE_LAYER_COLOR:
      if (record->event.pressed) {
        disable_layer_color ^= 1;
      }
      return false;
    case GRAVE_NORDIC:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LSHIFT)SS_TAP(X_EQUAL)SS_UP(X_LSHIFT)SS_TAP(X_SPACE));
      }
      return false;
    case TILDE_NORDIC:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_RALT)SS_TAP(X_RBRACKET)SS_UP(X_RALT)SS_TAP(X_SPACE));
      }
      return false;
    case CIRC_NORDIC:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LSHIFT)SS_TAP(X_RBRACKET)SS_UP(X_LSHIFT)SS_TAP(X_SPACE));
      }
      return false;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
uint32_t layer_state_set_user(uint32_t state) {
    palClearPad(GPIOB, 8);
    palClearPad(GPIOB, 9);
#if 0
    uint8_t layer = biton32(state);
    switch (layer) {
        case _LOWER:
            palSetPad(GPIOB, 9);
            break;
        case _RAISE:
            palSetPad(GPIOB, 8);
            break;
        case _ADJUST:
            palSetPad(GPIOB, 9);
            palSetPad(GPIOB, 8);
            break;
        default:
            break;
    }
#endif
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
