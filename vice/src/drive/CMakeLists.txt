add_library(libdrive)

target_compile_definitions(
    libdrive
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:HAVE_CONFIG_H NDEBUG _arch_dreamcast __DREAMCAST__ _arch_dreamcast _arch_sub_pristine >
        $<$<COMPILE_LANGUAGE:CXX>:>
        $<$<COMPILE_LANGUAGE:OBJC>:>
    )

target_include_directories(
    libdrive
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/
        ${CMAKE_SOURCE_DIR}/src/arch/systemheaderoverride
        ${CMAKE_SOURCE_DIR}/src/arch/sdl
        ${CMAKE_SOURCE_DIR}/src/arch/shared
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/monitor
        ${CMAKE_SOURCE_DIR}/src/vdrive
        ${CMAKE_SOURCE_DIR}/src/core
        ${CMAKE_SOURCE_DIR}/src/core/rtc
        ${CMAKE_SOURCE_DIR}/src/lib/p64
        ${CMAKE_SOURCE_DIR}/src/drive/iec
        ${CMAKE_SOURCE_DIR}/src/drive/tcbm
        ${CMAKE_SOURCE_DIR}/src/drive/ieee
    )

target_compile_options(
    libdrive
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:-Wno-deprecated-declarations -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:CXX>:-Wno-deprecated-declarations -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:OBJC>:-Wno-deprecated-declarations >
    )

target_sources(
    libdrive
    PRIVATE
        drive-check.c
        drive-cmdline-options.c
        drive-resources.c
        drive-snapshot.c
        drive-sound.c
        drive-writeprotect.c
        drive.c
        drivecpu.c
        drivecpu65c02.c
        driveimage.c
        drivemem.c
        driverom.c
        drivesync.c
        rotation.c
        drive-check.h
        drive-cmdline-options.h
        drive-resources.h
        drive-snapshot.h
        drive-sound.h
        drive-writeprotect.h
        drive.h
        drivecpu.h
        drivecpu65c02.h
        driveimage.h
        drivemem.h
        driverom.h
        drivesync.h
        drivetypes.h
        iec-c64exp.h
        iec-plus4exp.h
        iec.h
        iec128dcr.h
        iecieee.h
        ieee.h
        rotation.h
        tcbm.h
        viad.h
    )

add_subdirectory(iec)
add_subdirectory(iec128dcr)
add_subdirectory(iecieee)
add_subdirectory(ieee)
add_subdirectory(tcbm)
