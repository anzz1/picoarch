# Global definitions
platform   ?= $(UNION_PLATFORM)

CC        = $(CROSS_COMPILE)gcc
SYSROOT   = $(shell $(CC) --print-sysroot)

PROCS     = -j4

OBJS      = libpicofe/input.o libpicofe/in_sdl.o libpicofe/linux/in_evdev.o \
            libpicofe/linux/plat.o libpicofe/fonts.o libpicofe/readpng.o \
			libpicofe/config_file.o source/cheat.o source/config.o \
			source/content.o source/core.o source/menu.o source/main.o \
			source/options.o source/overrides.o source/patch.o source/scale.o \
			source/scaler_neon.o source/unzip.o source/util.o

BIN       = picoarch

CFLAGS     += -Wall
CFLAGS     += -fdata-sections -ffunction-sections -DPICO_HOME_DIR='"/.picoarch/"' -flto
CFLAGS     += -I./ -I./libretro-common/include/ -I./source $(shell $(SYSROOT)/usr/bin/sdl-config --cflags)

LDFLAGS    = -lc -ldl -lgcc -lm -lSDL -lpng12 -lz -Wl,--gc-sections -flto

PATCH = git apply

# Extra cores that build
# EXTRA_CORES += mame2003_plus snes9x2005_plus snes9x2005 genesis-plus-gx
CORES = gambatte gpsp fceumm pcsx_rearmed picodrive pokemini mgba smsplus-gx beetle-pce-fast nxengine mednafen_supafaust
CORES+= beetle-vb fake-08 prboom beetle-ngp beetle-supergrafx $(EXTRA_CORES)

# *_BUILD_PATH seems to assume the makefile is present in the root of the repo

fake-08_REPO = https://github.com/jtothebell/fake-08
fake-08_BUILD_PATH = cores/fake-08/platform/libretro
fake-08_CORE = fake08_libretro_miyoomini.so

nxengine_REPO = https://github.com/libretro/nxengine-libretro

mednafen_supafaust_REPO = https://github.com/libretro/supafaust
# mednafen_supafaust_REVISION = 75c658cce454e58ae04ea252f53a31c60d61548e # known good revision

snes9x2005_plus_REPO = https://github.com/libretro/snes9x2005
snes9x2005_plus_FLAGS = USE_BLARGG_APU=1

beetle-pce-fast_REPO = https://github.com/libretro/beetle-pce-fast-libretro
beetle-pce-fast_CORE = mednafen_pce_fast_libretro.so

beetle-vb_REPO = https://github.com/libretro/beetle-vb-libretro
beetle-vb_CORE = mednafen_vb_libretro.so

beetle-ngp_REPO = https://github.com/libretro/beetle-ngp-libretro
beetle-ngp_CORE = mednafen_ngp_libretro.so
# beetle-ngp_REVISION = 65460e3a9ad529f6901caf669abbda11f437ab55 # known good revision

beetle-supergrafx_REPO = https://github.com/libretro/beetle-supergrafx-libretro
beetle-supergrafx_CORE = mednafen_supergrafx_libretro.so
# beetle-supergrafx_REVISION = b73fa3556343ab410f253fac822ec8d7d6e42fc9 # known good revision

bluemsx_REPO = https://github.com/libretro/blueMSX-libretro

fbalpha2012_BUILD_PATH = cores/fbalpha2012/svn-current/trunk
fbalpha2012_MAKEFILE = makefile.libretro

fceumm_REPO = https://github.com/libretro/libretro-fceumm
fceumm_MAKEFILE = Makefile.libretro
# fceumm_REVISION = 154ee559c0d5c592d2f5fc06380b94b7516ab899 # known good revision

fmsx_REPO = https://github.com/libretro/fmsx-libretro

gambatte_REPO = https://github.com/libretro/gambatte-libretro
# gambatte_REVISION = 9574b6ef5961dcadc3fb5601779b673147515073 # known good revision

snes9x_REPO = https://github.com/libretro/snes9x

gme_REPO = https://github.com/libretro/libretro-gme

mame2000_REPO = https://github.com/libretro/mame2000-libretro
mame2003_plus_REPO = https://github.com/libretro/mame2003-plus-libretro

pcsx_rearmed_MAKEFILE = Makefile.libretro
# the next commit breaks trimui patches
pcsx_rearmed_REVISION = 131a1b41835bc0eba3e35998dce376163a0a1b14 

picodrive_REPO = https://github.com/irixxxx/picodrive
picodrive_MAKEFILE = Makefile.libretro
# picodrive_REVISION = 26d58060f4dd334c6ff02da0516ecec7a9fb251c # known good revision

pokemini_REPO = https://github.com/libretro/PokeMini
pokemini_MAKEFILE = Makefile.libretro
pokemini_REVISION = 684e7ea0950f4df48cd1fbf1160e6af3c262c9f0

prboom_REPO = https://github.com/libretro/libretro-prboom
# use known good revision
prboom_REVISION = 47a95e921e9f1e5928730b7369d14129769fa475

quicknes_REPO = https://github.com/libretro/QuickNES_Core

smsplus-gx_MAKEFILE = Makefile.libretro
smsplus-gx_CORE = smsplus_libretro.so
# smsplus-gx_REVISION = 60af17ddb2231ba98f4ed1203e2a2f58d08ea088 # known good revision

genesis-plus-gx_MAKEFILE = Makefile.libretro
genesis-plus-gx_CORE = genesis_plus_gx_libretro.so

ifeq ($(platform), trimui)
	OBJS += source/plat_trimui.o
	CFLAGS += -mcpu=arm926ej-s -mtune=arm926ej-s -fno-PIC -DCONTENT_DIR='"/mnt/SDCARD/Roms"'
	LDFLAGS += -fno-PIC
else ifeq ($(platform), miyoomini)
	OBJS += source/plat_miyoomini.o
	CFLAGS += -marm -mtune=cortex-a7 -mfpu=neon-vfpv4 -mfloat-abi=hard -march=armv7ve -fPIC -DCONTENT_DIR='"/mnt/SDCARD/Roms"'
	LDFLAGS += -fPIC -lmi_sys -lmi_gfx
	MMENU=1
	# PATCH=patch
else ifeq ($(platform), unix)
	OBJS += source/plat_linux.o
	LDFLAGS += -fPIE
endif

ifeq ($(DEBUG), 1)
	CFLAGS += -Og -g
	LDFLAGS += -g
else
	CFLAGS += -Ofast -DNDEBUG

ifneq ($(PROFILE), 1)
	LDFLAGS += -s
endif

endif

ifeq ($(PROFILE), 1)
	CFLAGS += -fno-omit-frame-pointer -pg -g
	LDFLAGS += -pg -g
else ifeq ($(PROFILE), GENERATE)
	CFLAGS	+= -fprofile-generate=./profile/picoarch
	LDFLAGS	+= -lgcov
else ifeq ($(PROFILE), APPLY)
	CFLAGS	+= -fprofile-use -fprofile-dir=./profile/picoarch -fbranch-probabilities
endif

ifeq ($(MINUI), 1)
	MMENU = 1
	CFLAGS += -DMINUI
endif

ifeq ($(MMENU), 1)
	CFLAGS += -DMMENU
	LDFLAGS += -lSDL_image -lSDL_ttf -ldl
endif

CFLAGS += $(EXTRA_CFLAGS)

SOFILES = $(foreach core,$(CORES),$(core)_libretro.so)

print-%:
	@echo '$*=$($*)'

all: $(BIN) cores

libpicofe/.patched:
	cd libpicofe && $(PATCH) -p1 < ../patches/libpicofe/0001-key-combos.patch && touch .patched

clean-libpicofe:
	test ! -f libpicofe/.patched || (cd libpicofe && $(PATCH) -p1 -R < ../patches/libpicofe/0001-key-combos.patch && rm .patched)

plat_miyoomini.o: plat_sdl.c
plat_trimui.o: plat_sdl.c
plat_linux.o: plat_sdl.c

$(BIN): libpicofe/.patched $(OBJS)
	mkdir -p output
	$(CC) $(OBJS) $(LDFLAGS) -o output/$(BIN)

define CORE_template =

$1_REPO ?= https://github.com/libretro/$(1)/

$1_BUILD_PATH ?= cores/$(1)

$1_MAKE = make $(and $($1_MAKEFILE),-f $($1_MAKEFILE)) platform=$(platform) $(and $(DEBUG),DEBUG=$(DEBUG)) $(and $(PROFILE),PROFILE=$(PROFILE)) $($(1)_FLAGS)

clone-$(1):
	mkdir -p cores
	cd cores && git clone $(if $($1_REVISION),,--depth 1) --recursive $$($(1)_REPO) $(1)
	$(if $1_REVISION,cd $$($1_BUILD_PATH) && git checkout $($1_REVISION),)

cores/$(1):
	mkdir -p cores
	cd cores && git clone $(if $($1_REVISION),,--depth 1) --recursive $$($(1)_REPO) $(1)
	$(if $1_REVISION,cd $$($1_BUILD_PATH) && git checkout $($1_REVISION),)
	(test ! -d patches/$(1)) || (cd cores/$(1) && $(foreach patch, $(sort $(wildcard patches/$(1)/*.patch)), $(PATCH) -p1 < ../../$(patch) &&) true)
	# using ../../patches assumes BUILD_PATH is cores/$(1)

$(1): cores/$(1)

$(1)_libretro.so: $(1)
	mkdir -p output
	cd $$($1_BUILD_PATH) && $$($1_MAKE) $(PROCS)
	cp $$($1_BUILD_PATH)/$(if $($(1)_CORE),$($(1)_CORE),$(1)_libretro.so) output/$(1)_libretro.so

clean-$(1):
	test ! -d cores/$(1) || (cd $$($1_BUILD_PATH) && $$($1_MAKE) clean && rm -f $(1)_libretro.so)
endef

$(foreach core,$(CORES),$(eval $(call CORE_template,$(core))))

cores: $(SOFILES)

clean-picoarch:
	rm -f $(OBJS)
	cd output && rm -f $(BIN) $(SOFILES)

clean: clean-libpicofe clean-picoarch
	rm -f $(SOFILES)

clean-all: $(foreach core,$(CORES),clean-$(core)) clean

force-clean: clean
	rm -rf $(CORES)
