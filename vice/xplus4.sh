sh-elf-objcopy -R .stack -O binary src/xplus4.elf xplus4.bin
$KOS_BASE/utils/scramble/scramble xplus4.bin 1st_read.bin
cp 1st_read.bin cd/
##mkisofs -l -J -C 0,11702 -G $KOS_BASE/../IP.BIN -V "DREAMCAST" -o vic20.iso cd
#$KOS_BASE/utils/cdi4dc/cdi4dc dc.iso oldvice.cdi -d
# Define the command to find and format the directories
DIRS=$(find . -type d | grep '/cd' | sed 's/^/-d /' | tr '\n' ' ')
~/code/dreamcast/mkdcdisc/builddir/mkdcdisc -n DCPLUS4 -N $DIRS -e src/xplus4.elf -o xplus4.cdi
cp xplus4.cdi xplus4.bin  /mnt/d/dev/dc_dbg/Vice/
