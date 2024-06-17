add_library(libmonitor)

target_compile_definitions(
    libmonitor
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:HAVE_CONFIG_H NDEBUG _arch_dreamcast __DREAMCAST__ _arch_dreamcast _arch_sub_pristine >
        $<$<COMPILE_LANGUAGE:CXX>:>
        $<$<COMPILE_LANGUAGE:OBJC>:>
    )

target_include_directories(
    libmonitor
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/
        ${CMAKE_SOURCE_DIR}/src/arch/systemheaderoverride
        ${CMAKE_SOURCE_DIR}/src/arch/sdl
        ${CMAKE_SOURCE_DIR}/src/arch/shared
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/datasette
        ${CMAKE_SOURCE_DIR}/src/drive
        ${CMAKE_SOURCE_DIR}/src/imagecontents
        ${CMAKE_SOURCE_DIR}/src/vdrive
        ${CMAKE_SOURCE_DIR}/src/tapeport
        ${CMAKE_SOURCE_DIR}/src/userport
        ${CMAKE_SOURCE_DIR}/src/joyport
        ${CMAKE_SOURCE_DIR}/src/lib/p64
        ${CMAKE_SOURCE_DIR}/src/core/rtc
    )

target_compile_options(
    libmonitor
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:-Wno-deprecated-declarations -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -Wno-unused-label -Wno-unreachable-code -Wno-misleading-indentation -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:CXX>:-Wno-deprecated-declarations -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:OBJC>:-Wno-deprecated-declarations >
    )

target_sources(
    libmonitor
    PRIVATE
        asm6502.c
        asm6502dtv.c
        asm6809.c
        asmR65C02.c
        asm65816.c
        asmz80.c
        mon_assemble6502.c
        mon_assembleR65C02.c
        mon_assemble65816.c
        mon_assemble6809.c
        mon_assemblez80.c
        mon_breakpoint.c
        mon_command.c
        mon_disassemble.c
        mon_drive.c
        mon_file.c
        mon_memmap.c
        mon_memory.c
        mon_profile.c
        mon_register6502.c
        mon_register6502dtv.c
        mon_register6809.c
        mon_registerR65C02.c
        mon_register65816.c
        mon_registerz80.c
        mon_register.c
        mon_util.c
        monitor.c
        monitor_network.c
        monitor_binary.c
        asm.h
        mon_assemble.h
        mon_breakpoint.h
        mon_command.h
        mon_disassemble.h
        mon_drive.h
        mon_file.h
        mon_memmap.h
        mon_memory.h
        mon_profile.h
        mon_register.h
        mon_util.h
        monitor_network.h
        monitor_binary.h
        montypes.h
        mon_parse.c
        mon_lex.c
        mon_parse.h
    )

