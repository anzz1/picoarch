#include "overrides.h"

static const struct core_override_option fbalpha2012_neogeo_core_option_overrides[] = {
	{ NULL }
};

me_bind_action fbalpha2012_neogeo_ctrl_actions[] =
{
	{ "UP          ",  1 << RETRO_DEVICE_ID_JOYPAD_UP},
	{ "DOWN        ",  1 << RETRO_DEVICE_ID_JOYPAD_DOWN },
	{ "LEFT        ",  1 << RETRO_DEVICE_ID_JOYPAD_LEFT },
	{ "RIGHT       ",  1 << RETRO_DEVICE_ID_JOYPAD_RIGHT },
	{ "A           ",  1 << RETRO_DEVICE_ID_JOYPAD_Y },
	{ "B           ",  1 << RETRO_DEVICE_ID_JOYPAD_B },
	{ "C           ",  1 << RETRO_DEVICE_ID_JOYPAD_A },
	{ "D           ",  1 << RETRO_DEVICE_ID_JOYPAD_X },
	{ "START       ",  1 << RETRO_DEVICE_ID_JOYPAD_START },
	{ "SELECT/COIN ",  1 << RETRO_DEVICE_ID_JOYPAD_SELECT },
	{ NULL, 0 }
};

#define fbalpha2012_neogeo_overrides {                             \
	.core_name = "fbalpha2012_neogeo",                           \
	.actions = fbalpha2012_neogeo_ctrl_actions,                    \
	.action_size = array_size(fbalpha2012_neogeo_ctrl_actions),    \
	.options = fbalpha2012_neogeo_core_option_overrides            \
}
