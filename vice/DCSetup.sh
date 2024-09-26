#!/bin/sh
./autogen.sh
LIBS="$KOS_LDFLAGS -L/opt/toolchains/dc/kos/addons/lib/dreamcast -lSDL $KOS_LIBS" CFLAGS="$KOS_CFLAGS -D_arch_dreamcast -D__DREAMCAST__ -I/opt/toolchains/dc/kos/addons/include/ -I/opt/toolchains/dc/kos/addons/include/SDL" PATH=.:$PATH ./configure --program-prefix="/cd/Vice/" --host=sh-elf --enable-sdl1ui --enable-x64 --without-sdlsound --disable-hwscale --with-fastsid --disable-realdevice --without-resid --disable-portaudio --disable-ahi --disable-midi --disable-lame --disable-hardsid --disable-catweasel --disable-ssi2001 --disable-parsid --disable-ethernet --disable-ipv6 --disable-html-docs --disable-pdf-docs --disable-debug --disable-debug-gtk3ui --disable-cpuhistory --disable-native-gtk3ui --disable-headlessui --disable-hidmgr --disable-hidutils --disable-rs232 --without-readline --without-pulse --without-alsa --without-oss --without-sun --without-jpeg --without-png --without-gif --without-glew --disable-gtk3ui --without-libcurl --disable-ffmpeg --disable-new8580filter --enable-cmake --with-gnu-ld --cache-file=config.cache
