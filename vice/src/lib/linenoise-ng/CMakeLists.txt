add_library(liblinenoiseng)

target_compile_definitions(
    liblinenoiseng
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:>
        $<$<COMPILE_LANGUAGE:CXX>:HAVE_CONFIG_H NDEBUG _arch_dreamcast __DREAMCAST__ _arch_dreamcast _arch_sub_pristine >
        $<$<COMPILE_LANGUAGE:OBJC>:>
    )

target_include_directories(
    liblinenoiseng
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/
        ${CMAKE_SOURCE_DIR}/src/arch/systemheaderoverride
    )

target_compile_options(
    liblinenoiseng
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:-Wno-deprecated-declarations -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:CXX>:-Wno-deprecated-declarations -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -Wno-unused-variable -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:OBJC>:-Wno-deprecated-declarations >
    )

target_sources(
    liblinenoiseng
    PRIVATE
        ConvertUTF.cpp
        linenoise.cpp
        wcwidth.cpp
        ConvertUTF.h
        linenoise.h
        wcwidth.h
    )

