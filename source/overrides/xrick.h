#include "overrides.h"

static const struct core_override_option xrick_core_option_overrides[] = {
	{ NULL }
};

me_bind_action xrick_ctrl_actions[] =
{
	{ "UP         ",  1 << RETRO_DEVICE_ID_JOYPAD_UP},
	{ "DOWN       ",  1 << RETRO_DEVICE_ID_JOYPAD_DOWN },
	{ "LEFT       ",  1 << RETRO_DEVICE_ID_JOYPAD_LEFT },
	{ "RIGHT      ",  1 << RETRO_DEVICE_ID_JOYPAD_RIGHT },
	{ "JUMP       ",  1 << RETRO_DEVICE_ID_JOYPAD_A },
	{ "GUN        ",  1 << RETRO_DEVICE_ID_JOYPAD_B },
	{ "STICK      ",  1 << RETRO_DEVICE_ID_JOYPAD_X },
	{ "BOMB       ",  1 << RETRO_DEVICE_ID_JOYPAD_Y },
	{ "PAUSE      ",  1 << RETRO_DEVICE_ID_JOYPAD_START },
	{ NULL,       0 }
};

#define xrick_overrides {                               \
	.core_name = "xrick",                               \
	.actions = xrick_ctrl_actions,                      \
	.action_size = array_size(xrick_ctrl_actions),      \
	.options = xrick_core_option_overrides              \
}
