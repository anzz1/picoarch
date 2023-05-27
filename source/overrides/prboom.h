#include "overrides.h"

static const struct core_override_option prboom_core_option_overrides[] = {
	{
		.key = "prboom-resolution",
		.info = "Set the internal resolution the core is rendering at.",
		.options = {
			{ "320x200", NULL },
			{ "640x400", NULL },
			{ "960x600", "" },
			{ "1280x800", "" },
			{ "1600x1000", "" },
			{ "1920x1200", "" },
			{ "2240x1400", "" },
			{ "2560x1600", "" },
		}
	},
	{
		.key = "prboom-find_recursive_on",
		.default_value = "disabled",
		.blocked = true,
	},
	{
		.key = "prboom-purge_limit",
		.default_value = "16",
		.blocked = true,
	},
	{
		.key = "prboom-mouse_on",
		.blocked = true,
	},
	{
		.key = "prboom-analog_deadzone",
		.blocked = true,
	},
	{ NULL }
};

me_bind_action prboom_ctrl_actions[] =
{
	{ "UP            ",  1 << RETRO_DEVICE_ID_JOYPAD_UP},
	{ "DOWN          ",  1 << RETRO_DEVICE_ID_JOYPAD_DOWN },
	{ "LEFT          ",  1 << RETRO_DEVICE_ID_JOYPAD_LEFT },
	{ "RIGHT         ",  1 << RETRO_DEVICE_ID_JOYPAD_RIGHT },
	{ "USE/CONFIRM   ",  1 << RETRO_DEVICE_ID_JOYPAD_A },
	{ "STRAFE/CANCEL ",  1 << RETRO_DEVICE_ID_JOYPAD_B },
	{ "FIRE          ",  1 << RETRO_DEVICE_ID_JOYPAD_X },
	{ "RUN           ",  1 << RETRO_DEVICE_ID_JOYPAD_Y },
	{ "STRAFE LEFT   ",  1 << RETRO_DEVICE_ID_JOYPAD_L },
	{ "STRAFE RIGHT  ",  1 << RETRO_DEVICE_ID_JOYPAD_R },
	{ "PREV WEAPON   ",  1 << RETRO_DEVICE_ID_JOYPAD_L2 },
	{ "NEXT WEAPON   ",  1 << RETRO_DEVICE_ID_JOYPAD_R2 },
	{ "MAP           ",  1 << RETRO_DEVICE_ID_JOYPAD_SELECT },
	{ "MENU          ",  1 << RETRO_DEVICE_ID_JOYPAD_START },
	{ NULL, 0 }
};

#define prboom_overrides {                            \
	.core_name = "prboom",                            \
	.actions = prboom_ctrl_actions,                   \
	.action_size = array_size(prboom_ctrl_actions),   \
	.options = prboom_core_option_overrides,          \
}
