add_library(libarchdep)

target_compile_definitions(
    libarchdep
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:HAVE_CONFIG_H NDEBUG VICE_DATADIR="/usr/local/share/vice" VICE_DOCDIR="/usr/local/share/doc/vice" _arch_dreamcast __DREAMCAST__ >
        $<$<COMPILE_LANGUAGE:CXX>:>
        $<$<COMPILE_LANGUAGE:OBJC>:HAVE_CONFIG_H NDEBUG VICE_DATADIR="/usr/local/share/vice" VICE_DOCDIR="/usr/local/share/doc/vice" >
    )

target_include_directories(
    libarchdep
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/
        ${CMAKE_SOURCE_DIR}/src/arch/systemheaderoverride
        ${CMAKE_SOURCE_DIR}/src/arch/sdl
        ${CMAKE_SOURCE_DIR}/src/arch/shared
        ${CMAKE_SOURCE_DIR}/src/arch/shared/hotkeys
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/core/rtc
        ${CMAKE_SOURCE_DIR}/src/drive
        ${CMAKE_SOURCE_DIR}/src/lib/p64
        ${CMAKE_SOURCE_DIR}/src/rs232drv
    )

target_compile_options(
    libarchdep
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:-Wno-deprecated-declarations -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter>
        $<$<COMPILE_LANGUAGE:CXX>:-Wno-deprecated-declarations -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter>
        $<$<COMPILE_LANGUAGE:OBJC>:-Wno-deprecated-declarations -g -O3>
    )

target_sources(
    libarchdep
    PRIVATE
        archdep_access.c
        archdep_boot_path.c
        archdep_cbmfont.c
        archdep_chdir.c
        archdep_close.c
        archdep_create_user_cache_dir.c
        archdep_create_user_config_dir.c
        archdep_create_user_state_dir.c
        archdep_current_dir.c
        archdep_default_autostart_disk_image_file_name.c
        archdep_default_fliplist_file_name.c
        archdep_default_joymap_file_name.c
        archdep_default_logfile.c
        archdep_default_logger.c
        archdep_default_portable_resource_file_name.c
        archdep_default_resource_file_name.c
        archdep_default_rtc_file_name.c
        archdep_default_sysfile_pathlist.c
        archdep_dir.c
        archdep_ethernet_available.c
        archdep_exit.c
        archdep_expand_path.c
        archdep_extra_title_text.c
        archdep_fdopen.c
        archdep_file_exists.c
        archdep_file_is_blockdev.c
        archdep_file_is_chardev.c
        archdep_file_size.c
        archdep_filename_parameter.c
        archdep_fix_permissions.c
        archdep_fix_streams.c
        archdep_fseeko.c
        archdep_ftello.c
        archdep_get_current_drive.c
        archdep_get_hvsc_dir.c
        archdep_get_runtime_info.c
        archdep_get_vice_datadir.c
        archdep_get_vice_docsdir.c
        archdep_get_vice_drivesdir.c
        archdep_get_vice_hotkeysdir.c
        archdep_get_vice_machinedir.c
        archdep_getcwd.c
        archdep_home_path.c
        archdep_icon_path.c
        archdep_is_haiku.c
        archdep_is_macos_bindist.c
        archdep_is_windows_nt.c
        archdep_kbd_get_host_mapping.c
        archdep_list_drives.c
        archdep_make_backup_filename.c
        archdep_mkdir.c
        archdep_mkstemp_fd.c
        archdep_open_default_log_file.c
        archdep_path_is_relative.c
        archdep_program_name.c
        archdep_program_path.c
        archdep_quote_parameter.c
        archdep_quote_unzip.c
        archdep_rawnet_capability.c
        archdep_real_path.c
        archdep_remove.c
        archdep_rename.c
        archdep_require_vkbd.c
        archdep_rmdir.c
        archdep_rtc_get_centisecond.c
        archdep_sanitize_filename.c
        archdep_set_current_drive.c
        archdep_set_openmp_wait_policy.c
        archdep_signals.c
        archdep_socketpeek.c
        archdep_sound.c
        archdep_spawn.c
        archdep_startup_log_error.c
        archdep_stat.c
        archdep_tick.c
        archdep_tmpnam.c
        archdep_user_cache_path.c
        archdep_user_config_path.c
        archdep_user_state_path.c
        archdep_usleep.c
        archdep_xdg.c
        console.c
        coproc.c
        dynlib.c
        rawnetarch.c
        rs232dev.c
        signals.c
        uiactions.c
        rawnetarch_tuntap.c
        rawnetarch_unix.c
        archapi.h
        archdep_access.h
        archdep_beos.h
        archdep_boot_path.h
        archdep_cbmfont.h
        archdep_chdir.h
        archdep_close.h
        archdep_create_user_cache_dir.h
        archdep_create_user_config_dir.h
        archdep_create_user_state_dir.h
        archdep_current_dir.h
        archdep_default_autostart_disk_image_file_name.h
        archdep_default_fliplist_file_name.h
        archdep_default_joymap_file_name.h
        archdep_default_logfile.h
        archdep_default_logger.h
        archdep_default_portable_resource_file_name.h
        archdep_default_resource_file_name.h
        archdep_default_rtc_file_name.h
        archdep_default_sysfile_pathlist.h
        archdep_defs.h
        archdep_dir.h
        archdep_ethernet_available.h
        archdep_exit.h
        archdep_expand_path.h
        archdep_extra_title_text.h
        archdep_fdopen.h
        archdep_file_exists.h
        archdep_file_is_blockdev.h
        archdep_file_is_chardev.h
        archdep_file_size.h
        archdep_filename_parameter.h
        archdep_fix_permissions.h
        archdep_fix_streams.h
        archdep_fseeko.h
        archdep_ftello.h
        archdep_get_current_drive.h
        archdep_get_hvsc_dir.h
        archdep_get_runtime_info.h
        archdep_get_vice_datadir.h
        archdep_get_vice_docsdir.h
        archdep_get_vice_drivesdir.h
        archdep_get_vice_hotkeysdir.h
        archdep_get_vice_machinedir.h
        archdep_getcwd.h
        archdep_home_path.h
        archdep_icon_path.h
        archdep_is_haiku.h
        archdep_is_macos_bindist.h
        archdep_is_windows_nt.h
        archdep_kbd_get_host_mapping.h
        archdep_list_drives.h
        archdep_make_backup_filename.h
        archdep_mkdir.h
        archdep_mkstemp_fd.h
        archdep_network.h
        archdep_open_default_log_file.h
        archdep_path_is_relative.h
        archdep_program_name.h
        archdep_program_path.h
        archdep_quote_parameter.h
        archdep_quote_unzip.h
        archdep_rawnet_capability.h
        archdep_real_path.h
        archdep_remove.h
        archdep_rename.h
        archdep_require_vkbd.h
        archdep_rmdir.h
        archdep_rtc_get_centisecond.h
        archdep_sanitize_filename.h
        archdep_set_current_drive.h
        archdep_set_openmp_wait_policy.h
        archdep_signals.h
        archdep_socketpeek.h
        archdep_sound.h
        archdep_spawn.h
        archdep_startup_log_error.h
        archdep_stat.h
        archdep_tick.h
        archdep_tmpnam.h
        archdep_unix.h
        archdep_user_cache_path.h
        archdep_user_config_path.h
        archdep_user_state_path.h
        archdep_usleep.h
        archdep_win32.h
        archdep_xdg.h
        coproc.h
        macOS-util.h
        rawnetarch.h
        uiactions.h
    )

add_subdirectory(hwsiddrv)
add_subdirectory(mididrv)
add_subdirectory(socketdrv)
add_subdirectory(sounddrv)
add_subdirectory(hotkeys)
