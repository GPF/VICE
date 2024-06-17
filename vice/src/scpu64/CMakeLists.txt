add_library(libscpu64)

target_compile_definitions(
    libscpu64
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:HAVE_CONFIG_H NDEBUG _arch_dreamcast __DREAMCAST__ _arch_dreamcast _arch_sub_pristine >
        $<$<COMPILE_LANGUAGE:CXX>:>
        $<$<COMPILE_LANGUAGE:OBJC>:>
    )

target_include_directories(
    libscpu64
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/
        ${CMAKE_SOURCE_DIR}/src/arch/systemheaderoverride
        ${CMAKE_SOURCE_DIR}/src/arch/sdl
        ${CMAKE_SOURCE_DIR}/src/arch/shared
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/drive
        ${CMAKE_SOURCE_DIR}/src/printerdrv
        ${CMAKE_SOURCE_DIR}/src/c64
        ${CMAKE_SOURCE_DIR}/src/c64/cart
        ${CMAKE_SOURCE_DIR}/src/raster
        ${CMAKE_SOURCE_DIR}/src/sid
        ${CMAKE_SOURCE_DIR}/src/tape
        ${CMAKE_SOURCE_DIR}/src/userport
        ${CMAKE_SOURCE_DIR}/src/viciisc
        ${CMAKE_SOURCE_DIR}/src/video
        ${CMAKE_SOURCE_DIR}/src/lib/p64
        ${CMAKE_SOURCE_DIR}/src/vdc
        ${CMAKE_SOURCE_DIR}/src/core/rtc
        ${CMAKE_SOURCE_DIR}/src/joyport
        ${CMAKE_SOURCE_DIR}/src/samplerdrv
        ${CMAKE_SOURCE_DIR}/src/rs232drv
        ${CMAKE_SOURCE_DIR}/src/tapeport
    )

target_compile_options(
    libscpu64
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:-Wno-deprecated-declarations -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:CXX>:-Wno-deprecated-declarations -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:OBJC>:-Wno-deprecated-declarations >
    )

target_sources(
    libscpu64
    PRIVATE
        scpu64-cmdline-options.c
        scpu64-resources.c
        scpu64-snapshot.c
        scpu64.c
        scpu64cpu.c
        scpu64gluelogic.c
        scpu64mem.c
        scpu64memsnapshot.c
        scpu64meminit.c
        scpu64model.c
        scpu64rom.c
        scpu64-cmdline-options.h
        scpu64-resources.h
        scpu64-snapshot.h
        scpu64.h
        scpu64cpu.h
        scpu64gluelogic.h
        scpu64mem.h
        scpu64memsnapshot.h
        scpu64meminit.h
        scpu64rom.h
    )

add_library(libscpu64stubs)

target_compile_definitions(
    libscpu64stubs
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:HAVE_CONFIG_H NDEBUG _arch_dreamcast __DREAMCAST__ _arch_dreamcast _arch_sub_pristine >
        $<$<COMPILE_LANGUAGE:CXX>:>
        $<$<COMPILE_LANGUAGE:OBJC>:>
    )

target_include_directories(
    libscpu64stubs
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/
        ${CMAKE_SOURCE_DIR}/src/arch/systemheaderoverride
        ${CMAKE_SOURCE_DIR}/src/arch/sdl
        ${CMAKE_SOURCE_DIR}/src/arch/shared
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/drive
        ${CMAKE_SOURCE_DIR}/src/printerdrv
        ${CMAKE_SOURCE_DIR}/src/c64
        ${CMAKE_SOURCE_DIR}/src/c64/cart
        ${CMAKE_SOURCE_DIR}/src/raster
        ${CMAKE_SOURCE_DIR}/src/sid
        ${CMAKE_SOURCE_DIR}/src/tape
        ${CMAKE_SOURCE_DIR}/src/userport
        ${CMAKE_SOURCE_DIR}/src/viciisc
        ${CMAKE_SOURCE_DIR}/src/video
        ${CMAKE_SOURCE_DIR}/src/lib/p64
        ${CMAKE_SOURCE_DIR}/src/vdc
        ${CMAKE_SOURCE_DIR}/src/core/rtc
        ${CMAKE_SOURCE_DIR}/src/joyport
        ${CMAKE_SOURCE_DIR}/src/samplerdrv
        ${CMAKE_SOURCE_DIR}/src/rs232drv
        ${CMAKE_SOURCE_DIR}/src/tapeport
    )

target_compile_options(
    libscpu64stubs
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:-Wno-deprecated-declarations -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:CXX>:-Wno-deprecated-declarations -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:OBJC>:-Wno-deprecated-declarations >
    )

target_sources(
    libscpu64stubs
    PRIVATE
        scpu64-stubs.c
    )

