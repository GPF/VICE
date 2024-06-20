add_library(libvideo)

target_compile_definitions(
    libvideo
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:HAVE_CONFIG_H NDEBUG _arch_dreamcast __DREAMCAST__ >
        $<$<COMPILE_LANGUAGE:CXX>:>
        $<$<COMPILE_LANGUAGE:OBJC>:>
    )

target_include_directories(
    libvideo
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/
        ${CMAKE_SOURCE_DIR}/src/arch/systemheaderoverride
        ${CMAKE_SOURCE_DIR}/src/arch/sdl
        ${CMAKE_SOURCE_DIR}/src/arch/shared
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/raster
        ${CMAKE_SOURCE_DIR}/src/joyport
    )

target_compile_options(
    libvideo
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:-Wno-deprecated-declarations -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter>
        $<$<COMPILE_LANGUAGE:CXX>:-Wno-deprecated-declarations -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter>
        $<$<COMPILE_LANGUAGE:OBJC>:-Wno-deprecated-declarations >
    )

target_sources(
    libvideo
    PRIVATE
        render1x1.c
        render1x1rgbi.c
        render1x1ntsc.c
        render1x1pal.c
        render1x2.c
        render1x2rgbi.c
        render2x2.c
        render2x2rgbi.c
        render2x2ntsc.c
        render2x2pal.c
        render2x2palu.c
        render2x4.c
        render2x4rgbi.c
        renderscale2x.c
        video-canvas.c
        video-cmdline-options.c
        video-color.c
        video-render-crtmono.c
        video-render-palntsc.c
        video-render-rgbi.c
        video-render.c
        video-resources.c
        video-sound.c
        video-viewport.c
        render-common.h
        render1x1.h
        render1x1rgbi.h
        render1x1ntsc.h
        render1x1pal.h
        render1x2.h
        render1x2rgbi.h
        render2x2.h
        render2x2rgbi.h
        render2x2ntsc.h
        render2x2pal.h
        render2x2palu.h
        render2x4.h
        render2x4rgbi.h
        renderscale2x.h
        video-canvas.h
        video-color.h
        video-render.h
        video-resources.h
        video-sound.h
    )

