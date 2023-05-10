#include "overrides.h"

static const struct core_override_option fceumm_core_option_overrides[] = {
	{
		.key = "fceumm_ramstate",
		.desc = "RAM Fill (Restart)",
	},
	{
		.key = "fceumm_overscan_h_left",
		.desc = "Crop Left Overscan",
		.default_value = "8",
	},
	{
		.key = "fceumm_overscan_h_right",
		.desc = "Crop Right Overscan",
		.default_value = "8",
	},
	{
		.key = "fceumm_overscan_v_top",
		.desc = "Crop Top Overscan",
		.default_value = "8",
	},
	{
		.key = "fceumm_overscan_v_bottom",
		.desc = "Crop Btm Overscan",
		.default_value = "8",
	},
	{
		.key = "fceumm_up_down_allowed",
		.desc = "Opp. Directions",
	},
	{
		.key = "fceumm_turbo_delay",
		.desc = "Turbo Delay Frames",
	},
	{
		.key = "fceumm_turbo_enable",
		.options = {
			{ "None", "disabled" },
			{ "Player 1", "enabled" },
			{ "Player 2", "" },
			{ "Both", "" },
		}
	},
	{
		.key = "fceumm_apu_1",
		.desc = "Square 1 Channel",
	},
	{
		.key = "fceumm_apu_2",
		.desc = "Square 2 Channel",
	},
	{
		.key = "fceumm_apu_3",
		.desc = "Triangle Channel",
	},
	{
		.key = "fceumm_apu_4",
		.desc = "Noise Channel",
	},
	{
		.key = "fceumm_apu_5",
		.desc = "PCM Channel",
	},
	{
		.key = "fceumm_show_adv_system_options",
		.desc = "Show Sys Options",
	},
	{
		.key = "fceumm_show_adv_sound_options",
		.desc = "Show Snd Options",
	},
	{
		.key = "fceumm_swapduty",
		.desc = "Famiclone Audio",
	},
	{
		.key = "fceumm_aspect",
		.default_value = "Pixel",
		.blocked = true
	},
	{
		.key = "fceumm_arkanoid_mode",
		.blocked = true
	},
	{
		.key = "fceumm_game_genie",
		.blocked = true
	},
	{
		.key = "fceumm_mouse_sensitivity",
		.blocked = true
	},
	{
		.key = "fceumm_show_crosshair",
		.blocked = true
	},
	{
		.key = "fceumm_zapper_mode",
		.blocked = true
	},
	{
		.key = "fceumm_zapper_sensor",
		.blocked = true
	},
	{
		.key = "fceumm_zapper_tolerance",
		.blocked = true
	},
	{
		.key = "fceumm_zapper_trigger",
		.blocked = true
	},
	{ NULL }
};

me_bind_action fceumm_ctrl_actions[] =
{
	{ "UP       ",  1 << RETRO_DEVICE_ID_JOYPAD_UP},
	{ "DOWN     ",  1 << RETRO_DEVICE_ID_JOYPAD_DOWN },
	{ "LEFT     ",  1 << RETRO_DEVICE_ID_JOYPAD_LEFT },
	{ "RIGHT    ",  1 << RETRO_DEVICE_ID_JOYPAD_RIGHT },
	{ "A        ",  1 << RETRO_DEVICE_ID_JOYPAD_A },
	{ "B        ",  1 << RETRO_DEVICE_ID_JOYPAD_B },
	// NOTE: tried to reverse these but all it changed was the labels
	{ "A TURBO  ",  1 << RETRO_DEVICE_ID_JOYPAD_X },
	{ "B TURBO  ",  1 << RETRO_DEVICE_ID_JOYPAD_Y },
	{ "START    ",  1 << RETRO_DEVICE_ID_JOYPAD_START },
	{ "SELECT   ",  1 << RETRO_DEVICE_ID_JOYPAD_SELECT },
	{ "DISK CHNG",  1 << RETRO_DEVICE_ID_JOYPAD_L },
	{ "INS DISK ",  1 << RETRO_DEVICE_ID_JOYPAD_R },
	{ "INS COIN ",  1 << RETRO_DEVICE_ID_JOYPAD_R2 },
	{ NULL,       0 }
};

#define fceumm_overrides {                                    \
	.core_name = "fceumm",                                \
	.actions = fceumm_ctrl_actions,                       \
	.action_size = array_size(fceumm_ctrl_actions),       \
	.options = fceumm_core_option_overrides               \
}
