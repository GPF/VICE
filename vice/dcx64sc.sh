sh-elf-objcopy -R .stack -O binary src/x64sc.elf x64sc.bin
$KOS_BASE/utils/scramble/scramble x64sc.bin 1st_read.bin
cp 1st_read.bin cd/
#mkisofs -l -J -C 0,11702 -G $KOS_BASE/../IP.BIN -V "DREAMCAST" -o dc.iso cd
#$KOS_BASE/utils/cdi4dc/cdi4dc dc.iso oldvice.cdi -d
# Define the command to find and format the directories
DIRS=$(find . -type d | grep '/cd' | sed 's/^/-d /' | tr '\n' ' ')
~/code/dreamcast/mkdcdisc/builddir/mkdcdisc -n DCViceSC -N $DIRS -e src/x64sc.elf -o viceSC.cdi -I
cp viceSC.cdi viceSC.iso x64sc.bin /mnt/d/dev/dc_dbg/Vice/
