commondir = $(VICE_DATADIR)/common

GRESOURCE_TARGET = $(builddir)/vice.gresource
GRESOURCE_XML = $(srcdir)/vice.gresource.xml

icon_files = icon1024x1024.png \
	     Icon-128@2x.png \
	     C128_16.png \
	     C128_24.png \
	     C128_32.png \
	     C128_48.png \
	     C128_64.png \
	     C128_256.png \
	     C128_1024.svg \
	     C64_16.png \
	     C64_24.png \
	     C64_32.png \
	     C64_48.png \
	     C64_64.png \
	     C64_256.png \
	     C64_1024.svg \
	     CBM2_16.png \
	     CBM2_24.png \
	     CBM2_32.png \
	     CBM2_48.png \
	     CBM2_64.png \
	     CBM2_256.png \
	     CBM2_1024.svg \
	     DTV_16.png \
	     DTV_24.png \
	     DTV_32.png \
	     DTV_48.png \
	     DTV_64.png \
	     DTV_256.png \
	     DTV_1024.svg \
	     PET_16.png \
	     PET_24.png \
	     PET_32.png \
	     PET_48.png \
	     PET_64.png \
	     PET_256.png \
	     PET_256.svg \
	     PET_1024.svg \
	     Plus4_16.png \
	     Plus4_24.png \
	     Plus4_32.png \
	     Plus4_48.png \
	     Plus4_64.png \
	     Plus4_256.png \
	     Plus4_1024.svg \
	     SCPU_16.png \
	     SCPU_24.png \
	     SCPU_32.png \
	     SCPU_48.png \
	     SCPU_64.png \
	     SCPU_256.png \
	     SCPU_1024.svg \
	     SID_16.png \
	     SID_24.png \
	     SID_32.png \
	     SID_48.png \
	     SID_64.png \
	     SID_256.png \
	     SID_1024.svg \
	     VIC20_16.png \
	     VIC20_24.png \
	     VIC20_32.png \
	     VIC20_48.png \
	     VIC20_64.png \
	     VIC20_256.png \
	     VIC20_1024.svg

logo_files = CBM_Logo.svg \
	     vice-logo-black.svg

font_files = C64_Pro_Mono-STYLE.ttf \
             PetMe1282Y.ttf \
             PetMe128.ttf \
             PetMe2X.ttf \
             PetMe2Y.ttf \
             PetMe642Y.ttf \
             PetMe64.ttf \
             PetMe.ttf

common_DATA = $(icon_files) \
	      $(logo_files) \
	      $(font_files)

EXTRA_DIST = $(icon_files) \
	     $(logo_files) \
	     $(font_files) \
             PetMe-FreeLicense.txt \
	     x64.rc \
	     x64sc.rc \
	     x64dtv.rc \
	     xscpu64.rc \
	     x128.rc \
	     xvic.rc \
	     xplus4.rc \
	     xpet.rc \
	     xcbm2.rc \
	     xcbm5x0.rc \
	     vsid.rc \
	     vice.gresource.xml


if USE_GTK3UI
# Generate gresource binary file, required by all Gtk3 emus
$(GRESOURCE_TARGET): $(GRESOURCE_XML)
	glib-compile-resources --sourcedir $(top_srcdir) $< --target $@

common_DATA += $(GRESOURCE_TARGET)

# The *.ico and *.res files are currently generated in
# src/arch/gtk3/data/win32/Makefile.am, but the plan is to move that to here
# to also be able to generate the files for linking with SDL binaries on Win32
CLEANFILES = \
	$(GRESOURCE_TARGET) \
	x64.ico \
	x64sc.ico \
	x64dtv.ico \
	xscpu64.ico \
	x128.ico \
	xvic.ico \
	xplus4.ico \
	xpet.ico \
	xcbm2.ico \
	xcbm5x0.ico \
	vsid.ico \
	x64.res \
	x64sc.res \
	x64dtv.res \
	xscpu64.res \
	x128.res \
	xvic.res \
	xplus4.res \
	xpet.res \
	xcbm2.res \
	xcbm5x0.res \
	vsid.res

endif
