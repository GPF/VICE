add_library(libplus4)

target_compile_definitions(
    libplus4
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:HAVE_CONFIG_H NDEBUG _arch_dreamcast __DREAMCAST__ _arch_dreamcast _arch_sub_pristine >
        $<$<COMPILE_LANGUAGE:CXX>:>
        $<$<COMPILE_LANGUAGE:OBJC>:>
    )

target_include_directories(
    libplus4
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/
        ${CMAKE_SOURCE_DIR}/src/arch/systemheaderoverride
        ${CMAKE_SOURCE_DIR}/src/arch/sdl
        ${CMAKE_SOURCE_DIR}/src/arch/shared
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/plus4/cart
        ${CMAKE_SOURCE_DIR}/src/core
        ${CMAKE_SOURCE_DIR}/src/datasette
        ${CMAKE_SOURCE_DIR}/src/drive
        ${CMAKE_SOURCE_DIR}/src/printerdrv
        ${CMAKE_SOURCE_DIR}/src/sid
        ${CMAKE_SOURCE_DIR}/src/tape
        ${CMAKE_SOURCE_DIR}/src/monitor
        ${CMAKE_SOURCE_DIR}/src/video
        ${CMAKE_SOURCE_DIR}/src/samplerdrv
        ${CMAKE_SOURCE_DIR}/src/lib/p64
        ${CMAKE_SOURCE_DIR}/src/joyport
        ${CMAKE_SOURCE_DIR}/src/userport
        ${CMAKE_SOURCE_DIR}/src/raster
        ${CMAKE_SOURCE_DIR}/src/rs232drv
        ${CMAKE_SOURCE_DIR}/src/tapeport
        ${CMAKE_SOURCE_DIR}/src/core/rtc
    )

target_compile_options(
    libplus4
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:-Wno-deprecated-declarations -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:CXX>:-Wno-deprecated-declarations -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:OBJC>:-Wno-deprecated-declarations >
    )

target_sources(
    libplus4
    PRIVATE
        plus4-cmdline-options.c
        plus4-resources.c
        plus4-snapshot.c
        plus4.c
        plus4acia.c
        plus4bus.c
        plus4cpu.c
        plus4datasette.c
        plus4drive.c
        plus4export.c
        plus4iec.c
        plus4io.c
        plus4mem.c
        plus4memcsory256k.c
        plus4memhacks.c
        plus4memhannes256k.c
        plus4memlimit.c
        plus4memrom.c
        plus4memsnapshot.c
        plus4model.c
        plus4parallel.c
        plus4pio1.c
        plus4pio2.c
        plus4printer.c
        plus4rom.c
        plus4romset.c
        plus4speech.c
        plus4tcbm.c
        plus4video.c
        ted-badline.c
        ted-cmdline-options.c
        ted-color.c
        ted-draw.c
        ted-fetch.c
        ted-irq.c
        ted-mem.c
        ted-resources.c
        ted-snapshot.c
        ted-sound.c
        ted-timer.c
        ted-timing.c
        ted.c
        plus4-cmdline-options.h
        plus4-resources.h
        plus4-snapshot.h
        plus4.h
        plus4acia.h
        plus4iec.h
        plus4mem.h
        plus4memcsory256k.h
        plus4memhacks.h
        plus4memhannes256k.h
        plus4memlimit.h
        plus4memrom.h
        plus4memsnapshot.h
        plus4model.h
        plus4parallel.h
        plus4pio1.h
        plus4pio2.h
        plus4rom.h
        plus4speech.h
        plus4tcbm.h
        ted-badline.h
        ted-cmdline-options.h
        ted-color.h
        ted-draw.h
        ted-fetch.h
        ted-irq.h
        ted-mem.h
        ted-resources.h
        ted-snapshot.h
        ted-sound.h
        ted-timer.h
        ted-timing.h
        ted.h
        tedtypes.h
    )

add_library(libplus4stubs)

target_compile_definitions(
    libplus4stubs
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:HAVE_CONFIG_H NDEBUG _arch_dreamcast __DREAMCAST__ _arch_dreamcast _arch_sub_pristine >
        $<$<COMPILE_LANGUAGE:CXX>:>
        $<$<COMPILE_LANGUAGE:OBJC>:>
    )

target_include_directories(
    libplus4stubs
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/
        ${CMAKE_SOURCE_DIR}/src/arch/systemheaderoverride
        ${CMAKE_SOURCE_DIR}/src/arch/sdl
        ${CMAKE_SOURCE_DIR}/src/arch/shared
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/plus4/cart
        ${CMAKE_SOURCE_DIR}/src/core
        ${CMAKE_SOURCE_DIR}/src/datasette
        ${CMAKE_SOURCE_DIR}/src/drive
        ${CMAKE_SOURCE_DIR}/src/printerdrv
        ${CMAKE_SOURCE_DIR}/src/sid
        ${CMAKE_SOURCE_DIR}/src/tape
        ${CMAKE_SOURCE_DIR}/src/monitor
        ${CMAKE_SOURCE_DIR}/src/video
        ${CMAKE_SOURCE_DIR}/src/samplerdrv
        ${CMAKE_SOURCE_DIR}/src/lib/p64
        ${CMAKE_SOURCE_DIR}/src/joyport
        ${CMAKE_SOURCE_DIR}/src/userport
        ${CMAKE_SOURCE_DIR}/src/raster
        ${CMAKE_SOURCE_DIR}/src/rs232drv
        ${CMAKE_SOURCE_DIR}/src/tapeport
        ${CMAKE_SOURCE_DIR}/src/core/rtc
    )

target_compile_options(
    libplus4stubs
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:-Wno-deprecated-declarations -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:CXX>:-Wno-deprecated-declarations -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:OBJC>:-Wno-deprecated-declarations >
    )

target_sources(
    libplus4stubs
    PRIVATE
        plus4-stubs.c
    )

add_subdirectory(cart)
