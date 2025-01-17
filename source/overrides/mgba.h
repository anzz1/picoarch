#include "overrides.h"

static const struct core_override_option mgba_core_option_overrides[] = {
	{
		.key = "mgba_gb_model",
		.desc = "Game Boy Hardware",
		.info = "(Restart) Loads content with a specific Game Boy model. 'auto' selects the most appropriate model for the game.",
		.options = {
			{ "Autodetect", "auto" }
		}
	},
	{
		.key = "mgba_use_bios",
		.desc = "Use BIOS",
		.info = "(Restart) Use official BIOS for emulated hardware, if present.",
		.options = {
			{ "ON", "auto" }
		}
	},
	{
		.key = "mgba_skip_bios",
		.desc = "Skip BIOS Intro",
		.info = "(Restart) Skip the BIOS start-up logo animation. This setting has no effect when 'Use BIOS' is disabled.",
		.default_value = "ON",
	},
	{
		.key = "mgba_gb_colors",
		.desc = "GB Palette",
		.info = "(Restart) Palette used for games that are not GBC or SGB compatible or if hardware is forced to GB."
	},
	{
		.key = "mgba_gb_colors_preset",
		.desc = "GB Color Preset",
		.info = "(Restart) Palette preset to use if available. 'auto' selects the \"best\" / palette available.",
		.default_value = "3",
		.options = {
			{ "0", "Game Boy" },
			{ "1", "Game Boy Color" },
			{ "2", "Super Game Boy" },
			{ "3", "auto" },
		}
	},
	{
		.key = "mgba_sgb_borders",
		.desc = "SGB Borders",
		.info = "(Restart) Display Super Game Boy borders when running Super Game Boy enhanced games."
	},
	{
		.key = "mgba_interframe_blending",
		.info = "Simulates LCD ghosting effects. 'simple' blends 2 frames 50:50. 'smart' reduces flicker. 'LCD' combines multiple frames.",
		.options = {
			{ "OFF", "disabled" },
			{ "mix", "simple" },
			{ "mix_smart", "smart" },
			{ "lcd_ghosting", "LCD accurate" },
			{ "lcd_ghosting_fast", "LCD fast" },
		}
	},
	{
		.key = "mgba_audio_low_pass_range",
		.info = "Cut-off frequency of the low pass audio filter. A higher value increases the perceived 'strength' of the filter."
	},
	{
		.key = "mgba_allow_opposing_directions",
		.desc = "Opp. Directions",
		.info = "Enabling this will allow pressing both left and right (or up and down) directions at the same time."
	},
	{
		.key = "mgba_solar_sensor_level",
		.options = {
			{"sensor", "" },
		}
	},
	{
		.key = "mgba_force_gbp",
		.desc = "GBP Rumble",
		.info = "(Restart) Allows Game Boy Player compatible games to use rumble. May cause glitches such as flickering or lag in some of these games.",
	},
	{
		.key = "mgba_idle_optimization",
		.info = "Reduce system load by optimizing idle loops. Improves performance, and should be disabled only if having problems.",
		.options = {
			{ "Remove Known", "known" },
			{ "Detect and Remove", "detect+known" },
			{ "Don't Remove", "disabled" }
		}
	},
	{
		.key = "mgba_frameskip",
		.info = "Skip frames to avoid audio buffer under-run (crackling). Improves performance at the expense of visual smoothness.",
		.options = {
			{ "disabled", NULL },
			{ "auto", "auto" },
			{ "auto_threshold", "threshold" },
			{ "fixed_interval", "fixed" },
		}
	},
	{
		.key = "mgba_frameskip_threshold",
		.desc = "FS Threshold (%)",
		.info = "When 'Frameskip' is set to 'threshold', sets how low the audio buffer can get before frames will be skipped."
	},
	{
		.key = "mgba_frameskip_interval",
		.desc = "FS Interval",
		.info = "When 'Frameskip' is set to 'fixed', sets number of frames that are skipped before a new frame is rendered."
	},
	{ NULL }
};

me_bind_action mgba_ctrl_actions[] =
{
	{ "UP       ",  1 << RETRO_DEVICE_ID_JOYPAD_UP},
	{ "DOWN     ",  1 << RETRO_DEVICE_ID_JOYPAD_DOWN },
	{ "LEFT     ",  1 << RETRO_DEVICE_ID_JOYPAD_LEFT },
	{ "RIGHT    ",  1 << RETRO_DEVICE_ID_JOYPAD_RIGHT },
	{ "A BUTTON ",  1 << RETRO_DEVICE_ID_JOYPAD_A },
	{ "B BUTTON ",  1 << RETRO_DEVICE_ID_JOYPAD_B },
	{ "A TURBO  ",  1 << RETRO_DEVICE_ID_JOYPAD_X },
	{ "B TURBO  ",  1 << RETRO_DEVICE_ID_JOYPAD_Y },
	{ "START    ",  1 << RETRO_DEVICE_ID_JOYPAD_START },
	{ "SELECT   ",  1 << RETRO_DEVICE_ID_JOYPAD_SELECT },
	{ "L BUTTON ",  1 << RETRO_DEVICE_ID_JOYPAD_L },
	{ "R BUTTON ",  1 << RETRO_DEVICE_ID_JOYPAD_R },
	{ "SOLAR -  ",  1 << RETRO_DEVICE_ID_JOYPAD_L2 },
	{ "SOLAR +  ",  1 << RETRO_DEVICE_ID_JOYPAD_R2 },
	{ "L TURBO  ",  1 << RETRO_DEVICE_ID_JOYPAD_L3 },
	{ "R TURBO  ",  1 << RETRO_DEVICE_ID_JOYPAD_R3 },
	{ NULL,       0 }
};

const struct core_override_fast_forward mgba_fast_forward = {
	.type_key = "mgba_frameskip",
	.interval_key = "mgba_frameskip_interval"
};

#define mgba_overrides {                            \
	.core_name = "mgba",                            \
	.fast_forward = &mgba_fast_forward,             \
	.actions = mgba_ctrl_actions,                   \
	.action_size = array_size(mgba_ctrl_actions),   \
	.options = mgba_core_option_overrides           \
}
