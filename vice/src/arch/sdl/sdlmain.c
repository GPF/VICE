/*
 * sdlmain.c - SDL startup.
 *
 * Written by
 *  Hannu Nuotio <hannu.nuotio@tut.fi>
 *  Marco van den Heuvel <blackystardust68@yahoo.com>
 *
 * This file is part of VICE, the Versatile Commodore Emulator.
 * See README for copyright notice.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 *  02111-1307  USA.
 *
 */

#include "vice.h"

#include <stdio.h>

#include "cmdline.h"
#include "log.h"
#include "machine.h"
#include "main.h"
#include "resources.h"
#include "uimenu.h"

#include "vice_sdl.h"

/* FIXME: Ugly hack for preventing SDL crash using -help */
int sdl_help_shutdown = 0;

#ifdef __DREAMCAST__
#include <kos.h>
#include <SDL/SDL_dreamcast.h>
#endif

#ifdef GEKKO
#define __wii__ 1 //needed for libfar ??? I defined it in Makefile so not sure if still needed
#include <debug.h>
#include <fat.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


int main(int argc, char **argv)
{
#ifdef __DREAMCAST__    
printf("VICE DREAMCAST is starting\n");
// char buffer[2048];
    
//     file_t fd;
//     file_t d;
//     dirent_t *de;
//     int amt;

//     printf("Reading directory from CD-Rom /cd/Vice/c64 :\r\n");

//     /* Read and print the root directory */
//     d = fs_open("/cd/Vice/c64", O_RDONLY | O_DIR);

//     if(d == 0) {
//         printf("Can't open root!\r\n");
//         return;
//     }

//     while((de = fs_readdir(d))) {
//         printf("%s  /  ", de->name);

//         if(de->size >= 0) {
//             printf("%d\r\n", de->size);
//         }
//         else {
//             printf("DIR\r\n");
//         }
//     }

//     fs_close(d);

    // /* Read and print a file called README.TXT (if any) */
    // fd = fs_open("/cd/Vice/c64/c64s.vpl", O_RDONLY);

    // if(fd == 0) {
    //     printf("Can't open file README.TXT for reading.\r\n");
        
    // }

    // while((amt = fs_read(fd, buffer, 2048))) {
    //     int i;

    //     for(i = 0; i < amt; i++) printf("%c", buffer[i]);
    // }

    // fs_close(fd);    
//   Allocate space for new arguments
    // const char* newArgv[] = {
    //     "x64", // program name
    //     "--config",
    //     "sd:/apps/Vice/share/sdl-vicerc"
    // };

//x128    
    // const char* newArgv[] = {
    //     "x128.elf",                  // program name
    //     "+VDCdsize",          // argument 1
    //     // "-sounddev", "dummy",   // argument 3 (split into two parts)
    //     // "-soundrate", "22050",  // argument 4 (split into two parts)
    //     // "-soundbufsize", "1024", // argument 5 (split into two parts)
    //     // "-cartcrt","/cd/Vice/carts/mule.crt",
    //     // "-autostart","/cd/Vice/tapes/Mega Vault (1984)(Imagine).tap",        
    //     "-warp",
    //     "-speed", "200"
    // };


//xplus4   
    // const char* newArgv[] = {
    //     "xplus4.elf",                  // program name
    //     "+TEDdsize",          // argument 1
    //     // "-sounddev", "dummy",   // argument 3 (split into two parts)
    //     // "-soundrate", "22050",  // argument 4 (split into two parts)
    //     // "-soundbufsize", "1024", // argument 5 (split into two parts)
    //     // "-cartcrt","/cd/Vice/carts/mule.crt",
    //     // "-autostart","/cd/Vice/tapes/Mega Vault (1984)(Imagine).tap",        
    //     "-warp",
    //     "-speed", "200"
    // };

//xpet4   
    // const char* newArgv[] = {
    //     "xpet.elf",                  // program name
    //     "+CRTCdsize",          // argument 1
    //     // "-sounddev", "dummy",   // argument 3 (split into two parts)
    //     // "-soundrate", "22050",  // argument 4 (split into two parts)
    //     // "-soundbufsize", "1024", // argument 5 (split into two parts)
    //     // "-cartcrt","/cd/Vice/carts/mule.crt",
    //     // "-autostart","/cd/Vice/tapes/Mega Vault (1984)(Imagine).tap",        
    //     "-warp",
    //     "-speed", "200"
    // };

//xvic    
    // const char* newArgv[] = {
    //     "xvic.elf",                  // program name
    //     "+VICdsize",          // argument 1
    //     "+VICdsize",          // argument 1
    //     "+VICdscan",  
    //     "-VICfilter","0",
    //     "-VICfull",        
    //     "-VICshowstatusbar",
    //     "+mouse",
    //     "-sdlbitdepth","32",           // argument 2
    //     "-sdllimitmode","0",
    //     "-sdlinitialw","640",
    //     "-sdlinitialh","480",        
    //     // "-sounddev", "dummy",   // argument 3 (split into two parts)
    //     // "-soundrate", "22050",  // argument 4 (split into two parts)
    //     // "-soundbufsize", "1024", // argument 5 (split into two parts)
    //     // "-cartcrt","/cd/Vice/carts/mule.crt",
    //     "-autostart","/cd/Vice/tapes/Mega Vault (1984)(Imagine).tap",        
    //     "-warp",
    //     "-speed", "200"
    // };


//x64
    const char* GPFnewArgv[] = {
        "x64.elf",                  // program name 
        "-speed", "200",
        "-autostart-warp",
        "-warp",
        "+drive8truedrive",        
        "+VICIIdsize",          
        "+VICIIdscan",  
        "-VICIIfilter","0",
        // "-VICIIfull",
        "-sdlbitdepth","32",          
        "-sdllimitmode","2",
        "-sdlinitialw","512",
        "-sdlinitialh","512",
        // "-aspect","0",
        // "SDLCustomWidth","640",
        // "SDLCustomHeight","480",        
        "-VICIIshowstatusbar",
        // "+mouse",
        // "-sound",        
        // "-sounddev", "sdl",   
        // "-soundrate", "22050",  
        // "-soundbufsize", "512", 
        // "-soundfragsize","3",
        // "-cartcrt","/cd/Vice/carts/Jumpman Junior.crt",
        // "-autostart","/cd/Vice/tapes/STARWAR2.T64",
        "-autostart","/cd/Vice/disks/brucelee.d64",    
        // "-autostart","/cd/Vice/disks/Jumpman (1983)(Epyx)[cr REM][t +3 REM].d64",       
        // "-autostart","/cd/Vice/disks/M.U.L.E. - Slan.d64",               
        // "-keybuf","\x20 \x20 \x20 \x20 \x20 \x20 \x20 \x20 \x20 \x20 \x20 \x20 \x20 \x20 \x20 \x20 \x20 \x20 \x20 \x20 \x20 \x20 \x20 \x20"
         
    //    "-keybuf","10 print \x22 troy was here \x22 \x0a 20 goto 10\x0a run \x0a"
        // "-cartcrt","/cd/Vice/carts/gijoe.crt",  


        // "/cd/Vice/snapshots/brucelee.vsf"

                // "-features"
    };


    int GPFnewArgc = sizeof(GPFnewArgv) / sizeof(GPFnewArgv[0]);
    return main_program(GPFnewArgc, (char **)GPFnewArgv);
#endif 
#ifdef GEKKO    

    printf("VICE WII is starting");
    VIDEO_Init();
+    MOUSE_Init();
+    KEYBOARD_Init(NULL); 
    // DEBUG_Init(1, 1);
	if (!fatInitDefault()) {
		printf("fatInitDefault failure: terminating\n");
		main_exit();
	}    

//   Allocate space for new arguments
    // const char* newArgv[] = {
    //     "x64", // program name
    //     "--config",
    //     "sd:/apps/Vice/share/sdl-vicerc"
    // };
    //  
    // const char* newArgv[] = {
    //     "x64", // program name
    //     "-autostart",
    //     "sd:/apps/Vice/share/vice/C64/brucelee.d64"
    // };   
    const char* newArgv[] = {"Vice.elf"};
    int newArgc = 1;
  
    return main_program(newArgc, (char **)newArgv);
#endif 
    return main_program(argc, argv);
 
}

void main_exit(void)
{
    /* FIXME: Ugly hack for preventing SDL crash using -help */
    if (!sdl_help_shutdown) {
        /* log resources with non default values */
        resources_log_active();
        /* log the active config as commandline options */
        cmdline_log_active();
    }

    log_message(LOG_DEFAULT, "\nExiting...");

    /*
     * Clean up dangling resources due to the 'Quit emu' callback not returning
     * to the calling menu code.
     */
    sdl_ui_menu_shutdown();

    machine_shutdown();

    putchar('\n');
}
