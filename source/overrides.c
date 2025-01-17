#include "overrides.h"
#include "overrides/beetle-ngp.h"
#include "overrides/beetle-pce-fast.h"
#include "overrides/beetle-supergrafx.h"
#include "overrides/bluemsx.h"
#include "overrides/fake-08.h"
#include "overrides/fbalpha2012_neogeo.h"
#include "overrides/fceumm.h"
#include "overrides/fmsx.h"
#include "overrides/gambatte.h"
#include "overrides/gme.h"
#include "overrides/gpsp.h"
#include "overrides/mame2000.h"
#include "overrides/mednafen_supafaust.h"
#include "overrides/mgba.h"
#include "overrides/mgba_sgb.h"
#include "overrides/nxengine.h"
#include "overrides/pcsx_rearmed.h"
#include "overrides/picodrive.h"
#include "overrides/pokemini.h"
#include "overrides/prboom.h"
#include "overrides/quicknes.h"
#include "overrides/smsplus.h"
#include "overrides/snes9x2002.h"
#include "overrides/snes9x2005.h"
#include "overrides/snes9x2005_plus.h"
#include "overrides/xrick.h"
#include "util.h"

static const struct core_override overrides[] = {
	beetle_ngp_overrides,
	beetle_pce_fast_overrides,
	beetle_supergrafx_overrides,
	bluemsx_overrides,
	fake_08_overrides,
	fbalpha2012_neogeo_overrides,
	fceumm_overrides,
	fmsx_overrides,
	gambatte_overrides,
	gme_overrides,
	gpsp_overrides,
	mame2000_overrides,
	mednafen_supafaust_overrides,
	mgba_overrides,
	mgba_sgb_overrides,
	nxengine_overrides,
	pcsx_rearmed_overrides,
	picodrive_overrides,
	pokemini_overrides,
	prboom_overrides,
	quicknes_overrides,
	smsplus_overrides,
	snes9x2002_overrides,
	snes9x2005_overrides,
	snes9x2005_plus_overrides,
	xrick_overrides,
};

static const struct core_override *override;

const struct core_override *get_overrides(void) {
	return override;
}

void set_overrides(const char *core_name) {
	override = NULL;

	for (int i = 0; i < array_size(overrides); i++) {
		if (!strcmp(core_name, overrides[i].core_name)) {
			override = &overrides[i];
			break;
		}
	}
}
