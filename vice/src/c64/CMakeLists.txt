add_library(libvsid)

target_compile_definitions(
    libvsid
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:HAVE_CONFIG_H NDEBUG _arch_dreamcast __DREAMCAST__ _arch_dreamcast _arch_sub_pristine >
        $<$<COMPILE_LANGUAGE:CXX>:>
        $<$<COMPILE_LANGUAGE:OBJC>:>
    )

target_include_directories(
    libvsid
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/
        ${CMAKE_SOURCE_DIR}/src/arch/systemheaderoverride
        ${CMAKE_SOURCE_DIR}/src/arch/sdl
        ${CMAKE_SOURCE_DIR}/src/arch/shared
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/c64/cart
        ${CMAKE_SOURCE_DIR}/src/datasette
        ${CMAKE_SOURCE_DIR}/src/printerdrv
        ${CMAKE_SOURCE_DIR}/src/drive
        ${CMAKE_SOURCE_DIR}/src/drive/iec/c64exp
        ${CMAKE_SOURCE_DIR}/src/raster
        ${CMAKE_SOURCE_DIR}/src/sid
        ${CMAKE_SOURCE_DIR}/src/tape
        ${CMAKE_SOURCE_DIR}/src/userport
        ${CMAKE_SOURCE_DIR}/src/viciisc
        ${CMAKE_SOURCE_DIR}/src/lib/p64
        ${CMAKE_SOURCE_DIR}/src/video
        ${CMAKE_SOURCE_DIR}/src/core/rtc
        ${CMAKE_SOURCE_DIR}/src/joyport
        ${CMAKE_SOURCE_DIR}/src/samplerdrv
        ${CMAKE_SOURCE_DIR}/src/tapeport
        ${CMAKE_SOURCE_DIR}/src/core
        ${CMAKE_SOURCE_DIR}/src/rs232drv
        ${CMAKE_SOURCE_DIR}/src/hvsc
        ${CMAKE_SOURCE_DIR}/src/vdrive
        ${CMAKE_SOURCE_DIR}/src/fsdevice
        ${CMAKE_SOURCE_DIR}/src/imagecontents
    )

target_compile_options(
    libvsid
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:-Wno-deprecated-declarations -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:CXX>:-Wno-deprecated-declarations -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:OBJC>:-Wno-deprecated-declarations >
    )

target_sources(
    libvsid
    PRIVATE
        vsid-cmdline-options.c
        vsid-resources.c
        vsid-snapshot.c
        c64gluelogic.c
        c64keyboard.c
        c64memlimit.c
        c64memrom.c
        c64model.c
        c64rom.c
        c64romset.c
        c64rsuser.c
        c64video.c
        vsid-debugcart.c
        psid.c
        reloc65.c
        vsid.c
        vsidcia1.c
        vsidcia2.c
        vsidcpu.c
        vsidmem.c
        vsidmeminit.c
        vsidmemsnapshot.c
        vsidpla.c
        vsidsound.c
        vsid-cmdline-options.h
        c64gluelogic.h
        c64keyboard.h
        c64meminit.h
        c64memlimit.h
        c64memrom.h
        c64memsnapshot.h
        c64model.h
        c64parallel.h
        c64pla.h
        c64rom.h
        c64rsuser.h
        vsid-debugcart.h
        musdrv.h
        psid.h
        psiddrv.h
        psiddrv.h
    )

add_library(libvsidstubs)

target_compile_definitions(
    libvsidstubs
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:HAVE_CONFIG_H NDEBUG _arch_dreamcast __DREAMCAST__ _arch_dreamcast _arch_sub_pristine >
        $<$<COMPILE_LANGUAGE:CXX>:>
        $<$<COMPILE_LANGUAGE:OBJC>:>
    )

target_include_directories(
    libvsidstubs
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/
        ${CMAKE_SOURCE_DIR}/src/arch/systemheaderoverride
        ${CMAKE_SOURCE_DIR}/src/arch/sdl
        ${CMAKE_SOURCE_DIR}/src/arch/shared
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/c64/cart
        ${CMAKE_SOURCE_DIR}/src/datasette
        ${CMAKE_SOURCE_DIR}/src/printerdrv
        ${CMAKE_SOURCE_DIR}/src/drive
        ${CMAKE_SOURCE_DIR}/src/drive/iec/c64exp
        ${CMAKE_SOURCE_DIR}/src/raster
        ${CMAKE_SOURCE_DIR}/src/sid
        ${CMAKE_SOURCE_DIR}/src/tape
        ${CMAKE_SOURCE_DIR}/src/userport
        ${CMAKE_SOURCE_DIR}/src/viciisc
        ${CMAKE_SOURCE_DIR}/src/lib/p64
        ${CMAKE_SOURCE_DIR}/src/video
        ${CMAKE_SOURCE_DIR}/src/core/rtc
        ${CMAKE_SOURCE_DIR}/src/joyport
        ${CMAKE_SOURCE_DIR}/src/samplerdrv
        ${CMAKE_SOURCE_DIR}/src/tapeport
        ${CMAKE_SOURCE_DIR}/src/core
        ${CMAKE_SOURCE_DIR}/src/rs232drv
        ${CMAKE_SOURCE_DIR}/src/hvsc
        ${CMAKE_SOURCE_DIR}/src/vdrive
        ${CMAKE_SOURCE_DIR}/src/fsdevice
        ${CMAKE_SOURCE_DIR}/src/imagecontents
    )

target_compile_options(
    libvsidstubs
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:-Wno-deprecated-declarations -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:CXX>:-Wno-deprecated-declarations -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:OBJC>:-Wno-deprecated-declarations >
    )

target_sources(
    libvsidstubs
    PRIVATE
        vsid-stubs.c
        psiddrv.h
    )

add_library(libc64)

target_compile_definitions(
    libc64
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:HAVE_CONFIG_H NDEBUG _arch_dreamcast __DREAMCAST__ _arch_dreamcast _arch_sub_pristine >
        $<$<COMPILE_LANGUAGE:CXX>:>
        $<$<COMPILE_LANGUAGE:OBJC>:>
    )

target_include_directories(
    libc64
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/
        ${CMAKE_SOURCE_DIR}/src/arch/systemheaderoverride
        ${CMAKE_SOURCE_DIR}/src/arch/sdl
        ${CMAKE_SOURCE_DIR}/src/arch/shared
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/c64/cart
        ${CMAKE_SOURCE_DIR}/src/datasette
        ${CMAKE_SOURCE_DIR}/src/printerdrv
        ${CMAKE_SOURCE_DIR}/src/drive
        ${CMAKE_SOURCE_DIR}/src/drive/iec/c64exp
        ${CMAKE_SOURCE_DIR}/src/raster
        ${CMAKE_SOURCE_DIR}/src/sid
        ${CMAKE_SOURCE_DIR}/src/tape
        ${CMAKE_SOURCE_DIR}/src/userport
        ${CMAKE_SOURCE_DIR}/src/viciisc
        ${CMAKE_SOURCE_DIR}/src/lib/p64
        ${CMAKE_SOURCE_DIR}/src/video
        ${CMAKE_SOURCE_DIR}/src/core/rtc
        ${CMAKE_SOURCE_DIR}/src/joyport
        ${CMAKE_SOURCE_DIR}/src/samplerdrv
        ${CMAKE_SOURCE_DIR}/src/tapeport
        ${CMAKE_SOURCE_DIR}/src/core
        ${CMAKE_SOURCE_DIR}/src/rs232drv
        ${CMAKE_SOURCE_DIR}/src/hvsc
        ${CMAKE_SOURCE_DIR}/src/vdrive
        ${CMAKE_SOURCE_DIR}/src/fsdevice
        ${CMAKE_SOURCE_DIR}/src/imagecontents
    )

target_compile_options(
    libc64
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:-Wno-deprecated-declarations -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:CXX>:-Wno-deprecated-declarations -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:OBJC>:-Wno-deprecated-declarations >
    )

target_sources(
    libc64
    PRIVATE
        c64-cmdline-options.c
        c64-memory-hacks.c
        c64-resources.c
        c64-snapshot.c
        c64.c
        c64_256k.c
        c64bus.c
        c64cia1.c
        c64cia2.c
        c64cpu.c
        c64datasette.c
        c64drive.c
        c64export.c
        c64fastiec.c
        c64gluelogic.c
        c64iec.c
        c64io.c
        c64keyboard.c
        c64mem.c
        c64meminit.c
        c64memlimit.c
        c64memrom.c
        c64memsnapshot.c
        c64model.c
        c64parallel.c
        c64pla.c
        c64printer.c
        c64rom.c
        c64romset.c
        c64rsuser.c
        c64sound.c
        c64video.c
        plus256k.c
        plus60k.c
        c64-cmdline-options.h
        c64-memory-hacks.h
        c64-resources.h
        c64-snapshot.h
        c64.h
        c64_256k.h
        c64cart.h
        c64cia.h
        c64fastiec.h
        c64gluelogic.h
        c64iec.h
        c64keyboard.h
        c64mem.h
        c64meminit.h
        c64memlimit.h
        c64memrom.h
        c64memsnapshot.h
        c64model.h
        c64parallel.h
        c64pla.h
        c64rom.h
        c64rsuser.h
        plus256k.h
        plus60k.h
        psiddrv.h
    )

add_library(libc64stubs)

target_compile_definitions(
    libc64stubs
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:HAVE_CONFIG_H NDEBUG _arch_dreamcast __DREAMCAST__ _arch_dreamcast _arch_sub_pristine >
        $<$<COMPILE_LANGUAGE:CXX>:>
        $<$<COMPILE_LANGUAGE:OBJC>:>
    )

target_include_directories(
    libc64stubs
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/
        ${CMAKE_SOURCE_DIR}/src/arch/systemheaderoverride
        ${CMAKE_SOURCE_DIR}/src/arch/sdl
        ${CMAKE_SOURCE_DIR}/src/arch/shared
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/c64/cart
        ${CMAKE_SOURCE_DIR}/src/datasette
        ${CMAKE_SOURCE_DIR}/src/printerdrv
        ${CMAKE_SOURCE_DIR}/src/drive
        ${CMAKE_SOURCE_DIR}/src/drive/iec/c64exp
        ${CMAKE_SOURCE_DIR}/src/raster
        ${CMAKE_SOURCE_DIR}/src/sid
        ${CMAKE_SOURCE_DIR}/src/tape
        ${CMAKE_SOURCE_DIR}/src/userport
        ${CMAKE_SOURCE_DIR}/src/viciisc
        ${CMAKE_SOURCE_DIR}/src/lib/p64
        ${CMAKE_SOURCE_DIR}/src/video
        ${CMAKE_SOURCE_DIR}/src/core/rtc
        ${CMAKE_SOURCE_DIR}/src/joyport
        ${CMAKE_SOURCE_DIR}/src/samplerdrv
        ${CMAKE_SOURCE_DIR}/src/tapeport
        ${CMAKE_SOURCE_DIR}/src/core
        ${CMAKE_SOURCE_DIR}/src/rs232drv
        ${CMAKE_SOURCE_DIR}/src/hvsc
        ${CMAKE_SOURCE_DIR}/src/vdrive
        ${CMAKE_SOURCE_DIR}/src/fsdevice
        ${CMAKE_SOURCE_DIR}/src/imagecontents
    )

target_compile_options(
    libc64stubs
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:-Wno-deprecated-declarations -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:CXX>:-Wno-deprecated-declarations -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:OBJC>:-Wno-deprecated-declarations >
    )

target_sources(
    libc64stubs
    PRIVATE
        c64-stubs.c
        psiddrv.h
    )

add_library(libc64sc)

target_compile_definitions(
    libc64sc
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:HAVE_CONFIG_H NDEBUG _arch_dreamcast __DREAMCAST__ _arch_dreamcast _arch_sub_pristine >
        $<$<COMPILE_LANGUAGE:CXX>:>
        $<$<COMPILE_LANGUAGE:OBJC>:>
    )

target_include_directories(
    libc64sc
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/
        ${CMAKE_SOURCE_DIR}/src/arch/systemheaderoverride
        ${CMAKE_SOURCE_DIR}/src/arch/sdl
        ${CMAKE_SOURCE_DIR}/src/arch/shared
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/c64/cart
        ${CMAKE_SOURCE_DIR}/src/datasette
        ${CMAKE_SOURCE_DIR}/src/printerdrv
        ${CMAKE_SOURCE_DIR}/src/drive
        ${CMAKE_SOURCE_DIR}/src/drive/iec/c64exp
        ${CMAKE_SOURCE_DIR}/src/raster
        ${CMAKE_SOURCE_DIR}/src/sid
        ${CMAKE_SOURCE_DIR}/src/tape
        ${CMAKE_SOURCE_DIR}/src/userport
        ${CMAKE_SOURCE_DIR}/src/viciisc
        ${CMAKE_SOURCE_DIR}/src/lib/p64
        ${CMAKE_SOURCE_DIR}/src/video
        ${CMAKE_SOURCE_DIR}/src/core/rtc
        ${CMAKE_SOURCE_DIR}/src/joyport
        ${CMAKE_SOURCE_DIR}/src/samplerdrv
        ${CMAKE_SOURCE_DIR}/src/tapeport
        ${CMAKE_SOURCE_DIR}/src/core
        ${CMAKE_SOURCE_DIR}/src/rs232drv
        ${CMAKE_SOURCE_DIR}/src/hvsc
        ${CMAKE_SOURCE_DIR}/src/vdrive
        ${CMAKE_SOURCE_DIR}/src/fsdevice
        ${CMAKE_SOURCE_DIR}/src/imagecontents
    )

target_compile_options(
    libc64sc
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:-Wno-deprecated-declarations -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:CXX>:-Wno-deprecated-declarations -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:OBJC>:-Wno-deprecated-declarations >
    )

target_sources(
    libc64sc
    PRIVATE
        c64-cmdline-options.c
        c64-memory-hacks.c
        c64-resources.c
        c64-snapshot.c
        c64.c
        c64_256k.c
        c64bus.c
        c64cia1.c
        c64cia2.c
        c64cpusc.c
        c64datasette.c
        c64drive.c
        c64export.c
        c64fastiec.c
        c64gluelogic.c
        c64iec.c
        c64io.c
        c64keyboard.c
        c64memsc.c
        c64meminit.c
        c64memlimit.c
        c64memrom.c
        c64memsnapshot.c
        c64scmodel.c
        c64parallel.c
        c64pla.c
        c64printer.c
        c64rom.c
        c64romset.c
        c64rsuser.c
        c64sound.c
        c64video.c
        plus256k.c
        plus60k.c
        c64-cmdline-options.h
        c64-memory-hacks.h
        c64-resources.h
        c64-snapshot.h
        c64.h
        c64_256k.h
        c64cart.h
        c64cia.h
        c64fastiec.h
        c64gluelogic.h
        c64iec.h
        c64keyboard.h
        c64mem.h
        c64meminit.h
        c64memlimit.h
        c64memrom.h
        c64memsnapshot.h
        c64model.h
        c64parallel.h
        c64pla.h
        c64rom.h
        c64rsuser.h
        plus256k.h
        plus60k.h
        psiddrv.h
    )

add_library(libc64scstubs)

target_compile_definitions(
    libc64scstubs
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:HAVE_CONFIG_H NDEBUG _arch_dreamcast __DREAMCAST__ _arch_dreamcast _arch_sub_pristine >
        $<$<COMPILE_LANGUAGE:CXX>:>
        $<$<COMPILE_LANGUAGE:OBJC>:>
    )

target_include_directories(
    libc64scstubs
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/
        ${CMAKE_SOURCE_DIR}/src/arch/systemheaderoverride
        ${CMAKE_SOURCE_DIR}/src/arch/sdl
        ${CMAKE_SOURCE_DIR}/src/arch/shared
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/c64/cart
        ${CMAKE_SOURCE_DIR}/src/datasette
        ${CMAKE_SOURCE_DIR}/src/printerdrv
        ${CMAKE_SOURCE_DIR}/src/drive
        ${CMAKE_SOURCE_DIR}/src/drive/iec/c64exp
        ${CMAKE_SOURCE_DIR}/src/raster
        ${CMAKE_SOURCE_DIR}/src/sid
        ${CMAKE_SOURCE_DIR}/src/tape
        ${CMAKE_SOURCE_DIR}/src/userport
        ${CMAKE_SOURCE_DIR}/src/viciisc
        ${CMAKE_SOURCE_DIR}/src/lib/p64
        ${CMAKE_SOURCE_DIR}/src/video
        ${CMAKE_SOURCE_DIR}/src/core/rtc
        ${CMAKE_SOURCE_DIR}/src/joyport
        ${CMAKE_SOURCE_DIR}/src/samplerdrv
        ${CMAKE_SOURCE_DIR}/src/tapeport
        ${CMAKE_SOURCE_DIR}/src/core
        ${CMAKE_SOURCE_DIR}/src/rs232drv
        ${CMAKE_SOURCE_DIR}/src/hvsc
        ${CMAKE_SOURCE_DIR}/src/vdrive
        ${CMAKE_SOURCE_DIR}/src/fsdevice
        ${CMAKE_SOURCE_DIR}/src/imagecontents
    )

target_compile_options(
    libc64scstubs
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:-Wno-deprecated-declarations -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:CXX>:-Wno-deprecated-declarations -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:OBJC>:-Wno-deprecated-declarations >
    )

target_sources(
    libc64scstubs
    PRIVATE
        c64sc-stubs.c
        psiddrv.h
    )

add_library(libc64c128)

target_compile_definitions(
    libc64c128
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:HAVE_CONFIG_H NDEBUG _arch_dreamcast __DREAMCAST__ _arch_dreamcast _arch_sub_pristine >
        $<$<COMPILE_LANGUAGE:CXX>:>
        $<$<COMPILE_LANGUAGE:OBJC>:>
    )

target_include_directories(
    libc64c128
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/
        ${CMAKE_SOURCE_DIR}/src/arch/systemheaderoverride
        ${CMAKE_SOURCE_DIR}/src/arch/sdl
        ${CMAKE_SOURCE_DIR}/src/arch/shared
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/c64/cart
        ${CMAKE_SOURCE_DIR}/src/datasette
        ${CMAKE_SOURCE_DIR}/src/printerdrv
        ${CMAKE_SOURCE_DIR}/src/drive
        ${CMAKE_SOURCE_DIR}/src/drive/iec/c64exp
        ${CMAKE_SOURCE_DIR}/src/raster
        ${CMAKE_SOURCE_DIR}/src/sid
        ${CMAKE_SOURCE_DIR}/src/tape
        ${CMAKE_SOURCE_DIR}/src/userport
        ${CMAKE_SOURCE_DIR}/src/viciisc
        ${CMAKE_SOURCE_DIR}/src/lib/p64
        ${CMAKE_SOURCE_DIR}/src/video
        ${CMAKE_SOURCE_DIR}/src/core/rtc
        ${CMAKE_SOURCE_DIR}/src/joyport
        ${CMAKE_SOURCE_DIR}/src/samplerdrv
        ${CMAKE_SOURCE_DIR}/src/tapeport
        ${CMAKE_SOURCE_DIR}/src/core
        ${CMAKE_SOURCE_DIR}/src/rs232drv
        ${CMAKE_SOURCE_DIR}/src/hvsc
        ${CMAKE_SOURCE_DIR}/src/vdrive
        ${CMAKE_SOURCE_DIR}/src/fsdevice
        ${CMAKE_SOURCE_DIR}/src/imagecontents
    )

target_compile_options(
    libc64c128
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:-Wno-deprecated-declarations -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:CXX>:-Wno-deprecated-declarations -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:OBJC>:-Wno-deprecated-declarations >
    )

target_sources(
    libc64c128
    PRIVATE
        c64bus.c
        c64cia2.c
        c64datasette.c
        c64export.c
        c64gluelogic.c
        c64iec.c
        c64io.c
        c64keyboard.c
        c64meminit.c
        c64memlimit.c
        c64memrom.c
        c64printer.c
        c64pla.c
        c64parallel.c
        c64rsuser.c
        c64sound.c
        c64cart.h
        c64cia.h
        c64gluelogic.h
        c64iec.h
        c64keyboard.h
        c64meminit.h
        c64memlimit.h
        c64memrom.h
        c64pla.h
        c64parallel.h
        c64rsuser.h
        psiddrv.h
    )

add_library(libc64c64dtv)

target_compile_definitions(
    libc64c64dtv
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:HAVE_CONFIG_H NDEBUG _arch_dreamcast __DREAMCAST__ _arch_dreamcast _arch_sub_pristine >
        $<$<COMPILE_LANGUAGE:CXX>:>
        $<$<COMPILE_LANGUAGE:OBJC>:>
    )

target_include_directories(
    libc64c64dtv
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/
        ${CMAKE_SOURCE_DIR}/src/arch/systemheaderoverride
        ${CMAKE_SOURCE_DIR}/src/arch/sdl
        ${CMAKE_SOURCE_DIR}/src/arch/shared
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/c64/cart
        ${CMAKE_SOURCE_DIR}/src/datasette
        ${CMAKE_SOURCE_DIR}/src/printerdrv
        ${CMAKE_SOURCE_DIR}/src/drive
        ${CMAKE_SOURCE_DIR}/src/drive/iec/c64exp
        ${CMAKE_SOURCE_DIR}/src/raster
        ${CMAKE_SOURCE_DIR}/src/sid
        ${CMAKE_SOURCE_DIR}/src/tape
        ${CMAKE_SOURCE_DIR}/src/userport
        ${CMAKE_SOURCE_DIR}/src/viciisc
        ${CMAKE_SOURCE_DIR}/src/lib/p64
        ${CMAKE_SOURCE_DIR}/src/video
        ${CMAKE_SOURCE_DIR}/src/core/rtc
        ${CMAKE_SOURCE_DIR}/src/joyport
        ${CMAKE_SOURCE_DIR}/src/samplerdrv
        ${CMAKE_SOURCE_DIR}/src/tapeport
        ${CMAKE_SOURCE_DIR}/src/core
        ${CMAKE_SOURCE_DIR}/src/rs232drv
        ${CMAKE_SOURCE_DIR}/src/hvsc
        ${CMAKE_SOURCE_DIR}/src/vdrive
        ${CMAKE_SOURCE_DIR}/src/fsdevice
        ${CMAKE_SOURCE_DIR}/src/imagecontents
    )

target_compile_options(
    libc64c64dtv
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:-Wno-deprecated-declarations -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:CXX>:-Wno-deprecated-declarations -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:OBJC>:-Wno-deprecated-declarations >
    )

target_sources(
    libc64c64dtv
    PRIVATE
        c64bus.c
        c64drive.c
        c64fastiec.c
        c64keyboard.c
        c64parallel.c
        c64rom.c
        c64romset.c
        c64rsuser.c
        c64video.c
        c64fastiec.h
        c64keyboard.h
        c64parallel.h
        c64rom.h
        c64rsuser.h
        psiddrv.h
    )

add_library(libc64scpu64)

target_compile_definitions(
    libc64scpu64
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:HAVE_CONFIG_H NDEBUG _arch_dreamcast __DREAMCAST__ _arch_dreamcast _arch_sub_pristine >
        $<$<COMPILE_LANGUAGE:CXX>:>
        $<$<COMPILE_LANGUAGE:OBJC>:>
    )

target_include_directories(
    libc64scpu64
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/
        ${CMAKE_SOURCE_DIR}/src/arch/systemheaderoverride
        ${CMAKE_SOURCE_DIR}/src/arch/sdl
        ${CMAKE_SOURCE_DIR}/src/arch/shared
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/c64/cart
        ${CMAKE_SOURCE_DIR}/src/datasette
        ${CMAKE_SOURCE_DIR}/src/printerdrv
        ${CMAKE_SOURCE_DIR}/src/drive
        ${CMAKE_SOURCE_DIR}/src/drive/iec/c64exp
        ${CMAKE_SOURCE_DIR}/src/raster
        ${CMAKE_SOURCE_DIR}/src/sid
        ${CMAKE_SOURCE_DIR}/src/tape
        ${CMAKE_SOURCE_DIR}/src/userport
        ${CMAKE_SOURCE_DIR}/src/viciisc
        ${CMAKE_SOURCE_DIR}/src/lib/p64
        ${CMAKE_SOURCE_DIR}/src/video
        ${CMAKE_SOURCE_DIR}/src/core/rtc
        ${CMAKE_SOURCE_DIR}/src/joyport
        ${CMAKE_SOURCE_DIR}/src/samplerdrv
        ${CMAKE_SOURCE_DIR}/src/tapeport
        ${CMAKE_SOURCE_DIR}/src/core
        ${CMAKE_SOURCE_DIR}/src/rs232drv
        ${CMAKE_SOURCE_DIR}/src/hvsc
        ${CMAKE_SOURCE_DIR}/src/vdrive
        ${CMAKE_SOURCE_DIR}/src/fsdevice
        ${CMAKE_SOURCE_DIR}/src/imagecontents
    )

target_compile_options(
    libc64scpu64
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:-Wno-deprecated-declarations -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:CXX>:-Wno-deprecated-declarations -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:OBJC>:-Wno-deprecated-declarations >
    )

target_sources(
    libc64scpu64
    PRIVATE
        c64bus.c
        c64cia1.c
        c64cia2.c
        c64datasette.c
        c64drive.c
        c64export.c
        c64fastiec.c
        c64iec.c
        c64io.c
        c64keyboard.c
        c64memsnapshot.c
        c64parallel.c
        c64printer.c
        c64romset.c
        c64rsuser.c
        c64sound.c
        c64video.c
        c64cart.h
        c64cia.h
        c64fastiec.h
        c64iec.h
        c64keyboard.h
        c64memsnapshot.h
        c64model.h
        c64parallel.h
        c64rsuser.h
        psiddrv.h
    )

add_subdirectory(cart)
