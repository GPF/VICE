sh-elf-objcopy -R .stack -O binary src/x128.elf x128.bin
$KOS_BASE/utils/scramble/scramble x128.bin 1st_read.bin
cp 1st_read.bin cd/
##mkisofs -l -J -C 0,11702 -G $KOS_BASE/../IP.BIN -V "DREAMCAST" -o vic20.iso cd
#$KOS_BASE/utils/cdi4dc/cdi4dc dc.iso oldvice.cdi -d
# Define the command to find and format the directories
DIRS=$(find . -type d | grep '/cd' | sed 's/^/-d /' | tr '\n' ' ')
~/code/dreamcast/mkdcdisc/builddir/mkdcdisc -n DCC128 -N $DIRS -e src/x128.elf -o c128.cdi
cp c128.cdi x128.bin  /mnt/d/dev/dc_dbg/Vice/
