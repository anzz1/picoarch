#include "overrides.h"

static const struct core_override_option beetle_supergrafx_core_option_overrides[] = {	//
	{
		.key = "sgx_disable_softreset",
		.desc = "Soft Reset",
		.info = "Pressing RUN and SELECT simultaneously will SOFT RESET the console.",
		.options = {
			{ "disabled", "enabled" },
			{ "enabled", "disabled" },
		}
	},
	{
		.key = "sgx_turbo_toggle",
		.desc = "Turbo Mode",
		.options = {
			{ "disabled", NULL },
			{ "switch", "toggle" },
			{ "dedicated", "hold" },
		}
	},
	{
		.key = "sgx_cdbios",
		.desc = "CD BIOS",
		.info = "Restart required. Most games can run on 'System Card 3'. 'Games Express' is needed for several unlicensed games.",
	},
	{
		.key = "sgx_detect_gexpress",
		.desc = "Detect GE CD",
		.info = "Restart required. Automatically load the Games Express BIOS regardless of CD BIOS setting when loading Games Express CD games.",
	},
	{
		.key = "sgx_ocmultiplier",
		.desc = "CPU Overclock",
		.info = "Restart required. Adjust CPU clock multiplier. Higher values can reduce slowdowns in games. Can cause glitches and crashes.",
	},
	{
		.key = "sgx_up_down_allowed",
		.desc = "Opp. Directions",
	},
	{
		.key = "sgx_initial_scanline",
		.desc = "First scanline",
	},
	{
		.key = "sgx_hoverscan",
		.desc = "Hrz. Overscan",
	},
	{
		.key = "sgx_cdimagecache",
		.default_value = "disabled",
		.blocked = true,
	},
	{
		.key = "sgx_forcesgx",
		.default_value = "enabled",
		.blocked = true,
	},
	{
		.key = "sgx_multitap",
		.default_value = "disabled",
		.blocked = true,
	},
	{
		.key = "sgx_mouse_sensitivity",
		.blocked = true,
	},
	{
		.key = "sgx_turbo_toggle_hotkey",
		.blocked = true,
	},
	{ NULL }
};

me_bind_action beetle_supergrafx_ctrl_actions[] =
{
	{ "UP       ",  1 << RETRO_DEVICE_ID_JOYPAD_UP},
	{ "DOWN     ",  1 << RETRO_DEVICE_ID_JOYPAD_DOWN },
	{ "LEFT     ",  1 << RETRO_DEVICE_ID_JOYPAD_LEFT },
	{ "RIGHT    ",  1 << RETRO_DEVICE_ID_JOYPAD_RIGHT },
	{ "I        ",  1 << RETRO_DEVICE_ID_JOYPAD_A },
	{ "II       ",  1 << RETRO_DEVICE_ID_JOYPAD_B },
	{ "III      ",  1 << RETRO_DEVICE_ID_JOYPAD_Y },
	{ "IV       ",  1 << RETRO_DEVICE_ID_JOYPAD_X },
	{ "V        ",  1 << RETRO_DEVICE_ID_JOYPAD_L },
	{ "VI       ",  1 << RETRO_DEVICE_ID_JOYPAD_R },
	{ "RUN      ",  1 << RETRO_DEVICE_ID_JOYPAD_START },
	{ "SELECT   ",  1 << RETRO_DEVICE_ID_JOYPAD_SELECT },
//	{ "2 / 6 BTN",  1 << RETRO_DEVICE_ID_JOYPAD_L2 },
	{ NULL,       0 }
};

#define beetle_supergrafx_overrides {                           \
	.core_name = "mednafen_supergrafx",                         \
	.actions = beetle_supergrafx_ctrl_actions,                  \
	.action_size = array_size(beetle_supergrafx_ctrl_actions),  \
	.options = beetle_supergrafx_core_option_overrides          \
}
