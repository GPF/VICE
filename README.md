# VICE GitHub Mirror
This is the official git mirror of the [VICE subversion repo](https://sourceforge.net/p/vice-emu/code/HEAD/tree/).

For news, documentation, developer information, [visit the VICE website](https://vice-emu.sourceforge.io/).

## Download VICE
* [Official Releases](https://vice-emu.sourceforge.io/#download)
* [Snapshot builds of the latest code](https://github.com/VICE-Team/svn-mirror/releases)


## Dreamcast Vice port branch @ dreamcast-port

Quick port of Vice to the dreamcast using the latest sh-elf gcc 13.2 toolchain/Kos/KOS-PORTS/SDL

The DCSetup.sh script runs the autogen.sh and then the dreamcast cmdline to the configure script that works.
I made a copy of the config.h and configure script that were generated and hacked. wrote some fake pkg-config and sdl-config scripts to feed the configure scripts :)

Thanks,
GPF (troy davis)

![image](https://github.com/GPF/VICE/assets/1866144/535dc3aa-f3de-4ea4-b7a8-854a598e589d)
![image](https://github.com/GPF/VICE/assets/1866144/134ae2a2-1649-435e-9c70-9d3d0a2782dd)

