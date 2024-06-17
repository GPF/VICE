add_library(libhotkeys)

target_compile_definitions(
    libhotkeys
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:HAVE_CONFIG_H NDEBUG VICE_DATADIR="/usr/local/share/vice" VICE_DOCDIR="/usr/local/share/doc/vice" _arch_dreamcast __DREAMCAST__ _arch_dreamcast _arch_sub_pristine >
        $<$<COMPILE_LANGUAGE:CXX>:>
        $<$<COMPILE_LANGUAGE:OBJC>:>
    )

target_include_directories(
    libhotkeys
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/
        ${CMAKE_SOURCE_DIR}/src/arch/systemheaderoverride
        ${CMAKE_SOURCE_DIR}/src/arch/sdl
        ${CMAKE_SOURCE_DIR}/src/arch/shared
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/rs232drv
    )

target_compile_options(
    libhotkeys
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:-Wno-deprecated-declarations -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:CXX>:-Wno-deprecated-declarations -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:OBJC>:-Wno-deprecated-declarations -g -O3>
    )

target_sources(
    libhotkeys
    PRIVATE
        boolexpr.c
        ifstack.c
        parser.c
        symtab.c
        textfilereader.c
        vhkdebug.c
        vhkkeysyms.c
        uihotkeys.c
        keysymtable.h
        boolexpr.h
        hotkeystypes.h
        ifstack.h
        parser.h
        symtab.h
        textfilereader.h
        vhkdebug.h
        vhkkeysyms.h
        uihotkeys.h
    )

