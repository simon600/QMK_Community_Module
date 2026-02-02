RGB_MATRIX_EFFECT(SIGNALRGB)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#    ifdef SIGNALRGB_USE_BUFFER
extern rgb_led_t srgb_led_buffer[];
#    endif

bool SIGNALRGB(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

#    ifdef SIGNALRGB_USE_BUFFER
    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, srgb_led_buffer[i].r, srgb_led_buffer[i].g, srgb_led_buffer[i].b);
    }
#    endif

    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
