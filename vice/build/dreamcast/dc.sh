sh-elf-objcopy -R .stack -O binary src/x64 x64.bin
$KOS_BASE/utils/scramble/scramble x64.bin 1st_read.bin
cp 1st_read.bin ../../cd/
#mkisofs -l -J -C 0,11702 -G $KOS_BASE/../IP.BIN -V "DREAMCAST" -o dc.iso cd
#$KOS_BASE/utils/cdi4dc/cdi4dc dc.iso oldvice.cdi -d
# Define the command to find and format the directories
DIRS=$(find ../.. -type d | grep '/cd' | sed 's/^/-d /' | tr '\n' ' ')
~/code/dreamcast/mkdcdisc/builddir/mkdcdisc -n DCVice -N $DIRS -e src/x64 -o vice.cdi -I -N
cp vice.cdi vice.iso x64.bin /mnt/d/dev/dc_dbg/Vice/
