/** \file   actions-machine.c
 * \brief   UI action implementations for machine-related dialogs and settings (SDL)
 *
 * \author  Bas Wassink <b.wassink@ziggo.nl>
 */

/*
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

#include "machine.h"
#include "monitor.h"
#include "ui.h"
#include "uiactions.h"
#include "vsync.h"

#include "actions-machine.h"


/** \brief  Smart-attach action
 *
 * Attach an image and try to autodetect its type and start it.
 * This is called "Autostart image" in the SDL UI. Since it can attach disk,
 * tape and cartridge images, it makes sense to put it in machine actions, kinda.
 *
 * \param[in]   unused  unused
 */
static void smart_attach_action(void *unused)
{
    sdl_ui_menu_item_activate_by_action(ACTION_SMART_ATTACH);
}

/** \brief  Trigger soft reset of the machine
 *
 * \param[in]   unused  unused
 */
static void reset_soft_action(void *unused)
{
    vsync_suspend_speed_eval();
    machine_trigger_reset(MACHINE_RESET_MODE_SOFT);
}

/** \brief  Trigger hard reset of the machine
 *
 * \param[in]   unused  unused
 */
static void reset_hard_action(void *unused)
{
    vsync_suspend_speed_eval();
    machine_trigger_reset(MACHINE_RESET_MODE_HARD);
}

/** \brief  Open monitor action
 *
 * \param[in]   unused  unused
 */
static void monitor_open_action(void *unused)
{
    /* Are we called from the menu? */
    if (sdl_menu_state) {
        monitor_startup(e_default_space);
    } else {
        /* The monitor was activated with a hotkey. */
        /* we must remember the pause state and unpause, else we can not
           enter the monitor when the emulation is paused */
        sdl_pause_state = ui_pause_active();
        if (sdl_pause_state) {
            sdl_ui_create_draw_buffer_backup();
            ui_pause_disable();
        }
        /* The trap is needed for the machine state to be properly imported. */
        monitor_startup_trap();
    }
}

/** \brief  Quit action
 *
 * Exit the emulator.
 *
 * \param[in]   unused  unused
 */
static void quit_action(void *unused)
{
    ui_sdl_quit();
}


/** \brief  List of mappings for machine-related actions */
static const ui_action_map_t machine_actions[] = {
    {   .action  = ACTION_SMART_ATTACH,
        .handler = smart_attach_action,
        .dialog  = true
    },
    {
        .action  = ACTION_RESET_SOFT,
        .handler = reset_soft_action,
    },
    {
        .action  = ACTION_RESET_HARD,
        .handler = reset_hard_action,
    },
    {   .action  = ACTION_MONITOR_OPEN,
        .handler = monitor_open_action
    },
    {   .action  = ACTION_QUIT,
        .handler = quit_action
    },
    UI_ACTION_MAP_TERMINATOR
};


/** \brief  Register machine actions */
void actions_machine_register(void)
{
    ui_actions_register(machine_actions);
}
