
if(FIRST_RUN)
    set(CMAKE_XCODE_GENERATE_SCHEME ON)
    add_executable(cartconv)
    set(CMAKE_XCODE_GENERATE_SCHEME OFF)
else()
    add_executable(cartconv)
endif()

target_compile_definitions(
    cartconv
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:HAVE_CONFIG_H NDEBUG _arch_dreamcast __DREAMCAST__ _arch_dreamcast _arch_sub_pristine >
        $<$<COMPILE_LANGUAGE:CXX>:>
        $<$<COMPILE_LANGUAGE:OBJC>:>
    )

target_include_directories(
    cartconv
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/
        ${CMAKE_SOURCE_DIR}/src/arch/systemheaderoverride
        ${CMAKE_SOURCE_DIR}/src
    )

target_compile_options(
    cartconv
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:-Wno-deprecated-declarations -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:CXX>:-Wno-deprecated-declarations -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g>
        $<$<COMPILE_LANGUAGE:OBJC>:-Wno-deprecated-declarations >
    )

target_link_options(
    cartconv
    PRIVATE
        -Wno-deprecated-declarations -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g -m4-single-only -ml -Wl,-Ttext=0x8c010000 -Wl,--gc-sections -T/opt/toolchains/dc/kos/utils/ldscripts/shlelf.xc -nodefaultlibs -L/opt/toolchains/dc/kos/lib/dreamcast -L/opt/toolchains/dc/kos/addons/lib/dreamcast -L/opt/toolchains/dc/kos-ports/lib -O2 -fomit-frame-pointer -fno-builtin -m4-single-only -ml -ffunction-sections -fdata-sections -matomic-model=soft-imask -ftls-model=local-exec -Wall -g -m4-single-only -ml -Wl,-Ttext=0x8c010000 -Wl,--gc-sections -T/opt/toolchains/dc/kos/utils/ldscripts/shlelf.xc -nodefaultlibs -L/opt/toolchains/dc/kos/lib/dreamcast -L/opt/toolchains/dc/kos/addons/lib/dreamcast -L/opt/toolchains/dc/kos-ports/lib
    )

target_sources(
    cartconv
    PRIVATE
        cartconv.c
        c64-cartridges.c
        c64-saver.c
        c128-cartridges.c
        c128-saver.c
        cbm2-cartridges.c
        cbm2-saver.c
        plus4-cartridges.c
        plus4-saver.c
        vic20-cartridges.c
        vic20-saver.c
        crt.c
    )

target_link_libraries(
    cartconv
    PRIVATE
    	
    )
