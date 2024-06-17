sh-elf-objcopy -R .stack -O binary src/xvic.elf xvic.bin
$KOS_BASE/utils/scramble/scramble xvic.bin 1st_read.bin
cp 1st_read.bin cd/
##mkisofs -l -J -C 0,11702 -G $KOS_BASE/../IP.BIN -V "DREAMCAST" -o vic20.iso cd
#$KOS_BASE/utils/cdi4dc/cdi4dc dc.iso oldvice.cdi -d
# Define the command to find and format the directories
DIRS=$(find . -type d | grep '/cd' | sed 's/^/-d /' | tr '\n' ' ')
~/code/dreamcast/mkdcdisc/builddir/mkdcdisc -n DCVic20 -N $DIRS -e src/xvic.elf -o vic20.cdi
cp vic20.cdi xvic.bin  /mnt/d/dev/dc_dbg/Vice/
