add_library(libuserport)

target_compile_definitions(
    libuserport
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:HAVE_CONFIG_H NDEBUG _arch_dreamcast __DREAMCAST__ _arch_dreamcast _arch_sub_pristine >
        $<$<COMPILE_LANGUAGE:CXX>:>
        $<$<COMPILE_LANGUAGE:OBJC>:>
    )

target_include_directories(
    libuserport
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/
        ${CMAKE_SOURCE_DIR}/src/arch/systemheaderoverride
        ${CMAKE_SOURCE_DIR}/src/arch/sdl
        ${CMAKE_SOURCE_DIR}/src/arch/shared
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/c64/cart
        ${CMAKE_SOURCE_DIR}/src/lib/p64
        ${CMAKE_SOURCE_DIR}/src/core/rtc
        ${CMAKE_SOURCE_DIR}/src/joyport
        ${CMAKE_SOURCE_DIR}/src/samplerdrv
        ${CMAKE_SOURCE_DIR}/src/diag
        ${CMAKE_SOURCE_DIR}/src/drive
    )

target_compile_options(
    libuserport
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:-Wno-deprecated-declarations -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:CXX>:-Wno-deprecated-declarations -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:OBJC>:-Wno-deprecated-declarations >
    )

target_sources(
    libuserport
    PRIVATE
        userport.c
        userport_4bit_sampler.c
        userport_8bss.c
        userport_dac.c
        userport_diag_586220_harness.c
        userport_digimax.c
        userport_hks_joystick.c
        userport_hummer_joystick.c
        userport_io_sim.c
        userport_joystick.c
        userport_petscii_snespad.c
        userport_rtc_58321a.c
        userport_rtc_ds1307.c
        userport_spt_joystick.c
        userport_superpad64.c
        userport_synergy_joystick.c
        userport_wic64.c
        userport_woj_joystick.c
        userport.h
        userport_4bit_sampler.h
        userport_8bss.h
        userport_dac.h
        userport_diag_586220_harness.h
        userport_digimax.h
        userport_hks_joystick.h
        userport_hummer_joystick.h
        userport_io_sim.h
        userport_joystick.h
        userport_petscii_snespad.h
        userport_rtc_58321a.h
        userport_rtc_ds1307.h
        userport_spt_joystick.h
        userport_superpad64.h
        userport_synergy_joystick.h
        userport_wic64.h
        userport_woj_joystick.h
    )

