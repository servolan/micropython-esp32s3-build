// Module gpio_hold pour MicroPython ESP32-S3
// Expose gpio_hold_en/dis et gpio_deep_sleep_hold_en/dis depuis l'ESP-IDF

#include "py/runtime.h"
#include "py/obj.h"
#include "driver/gpio.h"

STATIC mp_obj_t mp_gpio_hold_en(mp_obj_t pin_obj) {
    gpio_hold_en((gpio_num_t)mp_obj_get_int(pin_obj));
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(mp_gpio_hold_en_obj, mp_gpio_hold_en);

STATIC mp_obj_t mp_gpio_hold_dis(mp_obj_t pin_obj) {
    gpio_hold_dis((gpio_num_t)mp_obj_get_int(pin_obj));
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(mp_gpio_hold_dis_obj, mp_gpio_hold_dis);

STATIC mp_obj_t mp_gpio_deep_sleep_hold_en(void) {
    gpio_deep_sleep_hold_en();
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_0(mp_gpio_deep_sleep_hold_en_obj, mp_gpio_deep_sleep_hold_en);

STATIC mp_obj_t mp_gpio_deep_sleep_hold_dis(void) {
    gpio_deep_sleep_hold_dis();
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_0(mp_gpio_deep_sleep_hold_dis_obj, mp_gpio_deep_sleep_hold_dis);

STATIC const mp_rom_map_elem_t gpio_hold_module_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__),                 MP_ROM_QSTR(MP_QSTR_gpio_hold) },
    { MP_ROM_QSTR(MP_QSTR_gpio_hold_en),             MP_ROM_PTR(&mp_gpio_hold_en_obj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_hold_dis),            MP_ROM_PTR(&mp_gpio_hold_dis_obj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_deep_sleep_hold_en),  MP_ROM_PTR(&mp_gpio_deep_sleep_hold_en_obj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_deep_sleep_hold_dis), MP_ROM_PTR(&mp_gpio_deep_sleep_hold_dis_obj) },
};
STATIC MP_DEFINE_CONST_DICT(gpio_hold_module_globals, gpio_hold_module_globals_table);

const mp_obj_module_t gpio_hold_module = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&gpio_hold_module_globals,
};

MP_REGISTER_MODULE(MP_QSTR_gpio_hold, gpio_hold_module);

