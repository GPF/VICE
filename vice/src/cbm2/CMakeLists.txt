add_library(libcbm2)

target_compile_definitions(
    libcbm2
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:HAVE_CONFIG_H NDEBUG _arch_dreamcast __DREAMCAST__ >
        $<$<COMPILE_LANGUAGE:CXX>:>
        $<$<COMPILE_LANGUAGE:OBJC>:>
    )

target_include_directories(
    libcbm2
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/
        ${CMAKE_SOURCE_DIR}/src/arch/systemheaderoverride
        ${CMAKE_SOURCE_DIR}/src/arch/sdl
        ${CMAKE_SOURCE_DIR}/src/arch/shared
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/cbm2/cart
        ${CMAKE_SOURCE_DIR}/src/sid
        ${CMAKE_SOURCE_DIR}/src/crtc
        ${CMAKE_SOURCE_DIR}/src/vicii
        ${CMAKE_SOURCE_DIR}/src/video
        ${CMAKE_SOURCE_DIR}/src/drive
        ${CMAKE_SOURCE_DIR}/src/printerdrv
        ${CMAKE_SOURCE_DIR}/src/raster
        ${CMAKE_SOURCE_DIR}/src/userport
        ${CMAKE_SOURCE_DIR}/src/samplerdrv
        ${CMAKE_SOURCE_DIR}/src/lib/p64
        ${CMAKE_SOURCE_DIR}/src/joyport
        ${CMAKE_SOURCE_DIR}/src/tape
        ${CMAKE_SOURCE_DIR}/src/rs232drv
        ${CMAKE_SOURCE_DIR}/src/tapeport
        ${CMAKE_SOURCE_DIR}/src/datasette
        ${CMAKE_SOURCE_DIR}/src/core/rtc
    )

target_compile_options(
    libcbm2
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:-Wno-deprecated-declarations -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter>
        $<$<COMPILE_LANGUAGE:CXX>:-Wno-deprecated-declarations -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter>
        $<$<COMPILE_LANGUAGE:OBJC>:-Wno-deprecated-declarations >
    )

target_sources(
    libcbm2
    PRIVATE
        cbm2-cmdline-options.c
        cbm2-resources.c
        cbm2-snapshot.c
        cbm2.c
        cbm2acia1.c
        cbm2bus.c
        cbm2cia1.c
        cbm2cpu.c
        cbm2datasette.c
        cbm2drive.c
        cbm2export.c
        cbm2iec.c
        cbm2io.c
        cbm2mem.c
        cbm2memsnapshot.c
        cbm2model.c
        cbm2printer.c
        cbm2rom.c
        cbm2romset.c
        cbm2sound.c
        cbm2tpi1.c
        cbm2tpi2.c
        cbm2video.c
        cbm2-cmdline-options.h
        cbm2-resources.h
        cbm2-snapshot.h
        cbm2.h
        cbm2acia.h
        cbm2cia.h
        cbm2iec.h
        cbm2mem.h
        cbm2memsnapshot.h
        cbm2model.h
        cbm2rom.h
        cbm2tpi.h
    )

add_library(libcbm2stubs)

target_compile_definitions(
    libcbm2stubs
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:HAVE_CONFIG_H NDEBUG _arch_dreamcast __DREAMCAST__ >
        $<$<COMPILE_LANGUAGE:CXX>:>
        $<$<COMPILE_LANGUAGE:OBJC>:>
    )

target_include_directories(
    libcbm2stubs
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/
        ${CMAKE_SOURCE_DIR}/src/arch/systemheaderoverride
        ${CMAKE_SOURCE_DIR}/src/arch/sdl
        ${CMAKE_SOURCE_DIR}/src/arch/shared
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/cbm2/cart
        ${CMAKE_SOURCE_DIR}/src/sid
        ${CMAKE_SOURCE_DIR}/src/crtc
        ${CMAKE_SOURCE_DIR}/src/vicii
        ${CMAKE_SOURCE_DIR}/src/video
        ${CMAKE_SOURCE_DIR}/src/drive
        ${CMAKE_SOURCE_DIR}/src/printerdrv
        ${CMAKE_SOURCE_DIR}/src/raster
        ${CMAKE_SOURCE_DIR}/src/userport
        ${CMAKE_SOURCE_DIR}/src/samplerdrv
        ${CMAKE_SOURCE_DIR}/src/lib/p64
        ${CMAKE_SOURCE_DIR}/src/joyport
        ${CMAKE_SOURCE_DIR}/src/tape
        ${CMAKE_SOURCE_DIR}/src/rs232drv
        ${CMAKE_SOURCE_DIR}/src/tapeport
        ${CMAKE_SOURCE_DIR}/src/datasette
        ${CMAKE_SOURCE_DIR}/src/core/rtc
    )

target_compile_options(
    libcbm2stubs
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:-Wno-deprecated-declarations -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter>
        $<$<COMPILE_LANGUAGE:CXX>:-Wno-deprecated-declarations -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter>
        $<$<COMPILE_LANGUAGE:OBJC>:-Wno-deprecated-declarations >
    )

target_sources(
    libcbm2stubs
    PRIVATE
        cbm2-stubs.c
    )

add_library(libcbm5x0)

target_compile_definitions(
    libcbm5x0
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:HAVE_CONFIG_H NDEBUG _arch_dreamcast __DREAMCAST__ >
        $<$<COMPILE_LANGUAGE:CXX>:>
        $<$<COMPILE_LANGUAGE:OBJC>:>
    )

target_include_directories(
    libcbm5x0
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/
        ${CMAKE_SOURCE_DIR}/src/arch/systemheaderoverride
        ${CMAKE_SOURCE_DIR}/src/arch/sdl
        ${CMAKE_SOURCE_DIR}/src/arch/shared
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/cbm2/cart
        ${CMAKE_SOURCE_DIR}/src/sid
        ${CMAKE_SOURCE_DIR}/src/crtc
        ${CMAKE_SOURCE_DIR}/src/vicii
        ${CMAKE_SOURCE_DIR}/src/video
        ${CMAKE_SOURCE_DIR}/src/drive
        ${CMAKE_SOURCE_DIR}/src/printerdrv
        ${CMAKE_SOURCE_DIR}/src/raster
        ${CMAKE_SOURCE_DIR}/src/userport
        ${CMAKE_SOURCE_DIR}/src/samplerdrv
        ${CMAKE_SOURCE_DIR}/src/lib/p64
        ${CMAKE_SOURCE_DIR}/src/joyport
        ${CMAKE_SOURCE_DIR}/src/tape
        ${CMAKE_SOURCE_DIR}/src/rs232drv
        ${CMAKE_SOURCE_DIR}/src/tapeport
        ${CMAKE_SOURCE_DIR}/src/datasette
        ${CMAKE_SOURCE_DIR}/src/core/rtc
    )

target_compile_options(
    libcbm5x0
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:-Wno-deprecated-declarations -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter>
        $<$<COMPILE_LANGUAGE:CXX>:-Wno-deprecated-declarations -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter>
        $<$<COMPILE_LANGUAGE:OBJC>:-Wno-deprecated-declarations >
    )

target_sources(
    libcbm5x0
    PRIVATE
        cbm2-cmdline-options.c
        cbm5x0-resources.c
        cbm5x0-snapshot.c
        cbm5x0.c
        cbm2acia1.c
        cbm2bus.c
        cbm5x0cia1.c
        cbm2cpu.c
        cbm2datasette.c
        cbm2drive.c
        cbm2export.c
        cbm2iec.c
        cbm2io.c
        cbm5x0mem.c
        cbm2memsnapshot.c
        cbm2model.c
        cbm5x0printer.c
        cbm5x0rom.c
        cbm2romset.c
        cbm2sound.c
        cbm2tpi1.c
        cbm2tpi2.c
        cbm5x0video.c
        cbm2-cmdline-options.h
        cbm2-resources.h
        cbm2-snapshot.h
        cbm2.h
        cbm2acia.h
        cbm2cia.h
        cbm2iec.h
        cbm2mem.h
        cbm2memsnapshot.h
        cbm2model.h
        cbm2rom.h
        cbm2tpi.h
    )

add_library(libcbm5x0stubs)

target_compile_definitions(
    libcbm5x0stubs
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:HAVE_CONFIG_H NDEBUG _arch_dreamcast __DREAMCAST__ >
        $<$<COMPILE_LANGUAGE:CXX>:>
        $<$<COMPILE_LANGUAGE:OBJC>:>
    )

target_include_directories(
    libcbm5x0stubs
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/
        ${CMAKE_SOURCE_DIR}/src/arch/systemheaderoverride
        ${CMAKE_SOURCE_DIR}/src/arch/sdl
        ${CMAKE_SOURCE_DIR}/src/arch/shared
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/cbm2/cart
        ${CMAKE_SOURCE_DIR}/src/sid
        ${CMAKE_SOURCE_DIR}/src/crtc
        ${CMAKE_SOURCE_DIR}/src/vicii
        ${CMAKE_SOURCE_DIR}/src/video
        ${CMAKE_SOURCE_DIR}/src/drive
        ${CMAKE_SOURCE_DIR}/src/printerdrv
        ${CMAKE_SOURCE_DIR}/src/raster
        ${CMAKE_SOURCE_DIR}/src/userport
        ${CMAKE_SOURCE_DIR}/src/samplerdrv
        ${CMAKE_SOURCE_DIR}/src/lib/p64
        ${CMAKE_SOURCE_DIR}/src/joyport
        ${CMAKE_SOURCE_DIR}/src/tape
        ${CMAKE_SOURCE_DIR}/src/rs232drv
        ${CMAKE_SOURCE_DIR}/src/tapeport
        ${CMAKE_SOURCE_DIR}/src/datasette
        ${CMAKE_SOURCE_DIR}/src/core/rtc
    )

target_compile_options(
    libcbm5x0stubs
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:-Wno-deprecated-declarations -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter>
        $<$<COMPILE_LANGUAGE:CXX>:-Wno-deprecated-declarations -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter>
        $<$<COMPILE_LANGUAGE:OBJC>:-Wno-deprecated-declarations >
    )

target_sources(
    libcbm5x0stubs
    PRIVATE
        cbm5x0-stubs.c
    )

add_subdirectory(cart)
