add_library(usermod_gpio_hold INTERFACE)

target_sources(usermod_gpio_hold INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/gpio_hold.c
)

target_include_directories(usermod_gpio_hold INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(usermod INTERFACE usermod_gpio_hold)

