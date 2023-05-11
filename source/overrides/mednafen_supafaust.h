#include "overrides.h"

static const struct core_override_option mednafen_supafaust_core_option_overrides[] = {
	{
		.key = "supafaust_frameskip",
		.info = "Skip frames to improve performance at the expense of visual smoothness.",
	},
	{
		.key = "supafaust_frameskip_threshold",
		.default_value = "33",
		.info = "When 'Frameskip' is set to 'Threshold', sets how low the audio buffer can get before frames will be skipped.",
	},
	{
		.key = "supafaust_frameskip_interval",
		.default_value = "4",
		.info = "Specifies the maximum number of frames that can be skipped before a new frame is rendered.",
	},
	{
		.key = "supafaust_deinterlacer",
		.info = "Deinterlacer to use for interlaced video.",
	},
	{
		.key = "supafaust_h_filter",
		.retro_var_value = "Line doubling; none|phr256blend_auto512|phr256blend_512|512_blend|512|phr256blend",
		.default_value = "phr256blend_auto512",
		.info = "Horizontal line doubling/blending filter for hires modes.",
	},
	{
		.key = "supafaust_slstart",
		.retro_var_value = "First line (NTSC); 0|1|2|3|4|5|6|7|8|9|10|11|12|13|14|15|16",
		.info = "First displayed scanline in NTSC mode.",
	},
	{
		.key = "supafaust_slend",
		.retro_var_value = "Last line (NTSC); 223|222|221|220|219|218|217|216|215|214|213|212|211|210|209|208|207",
		.info = "Last displayed scanline in NTSC mode.",
	},
	{
		.key = "supafaust_slstartp",
		.retro_var_value = "First line (PAL); 0|1|2|3|4|5|6|7|8|9|10|11|12|13|14|15|16|17|18|19|20|21|22|23|24",
		.info = "First displayed scanline in PAL mode.",
	},
	{
		.key = "supafaust_slendp",
		.retro_var_value = "Last line (PAL); 238|237|236|235|234|233|232|231|230|229|228|227|226|225|224|223|222|221|220|219|218|217|216|215|214",
		.info = "Last displayed scanline in PAL mode.",
	},
	{
		.key = "supafaust_region",
		.retro_var_value = "Region; auto|ntsc|pal|ntsc_lie_auto|pal_lie_auto|ntsc_lie_pal|pal_lie_ntsc",
		.info = "System region to emulate. PAL (Europe) is 50hz while NTSC (USA/Japan) is 60hz. The 'lie' options can set system region and PPU bit separately.",
	},
	{
		.key = "supafaust_frame_begin_vblank",
		.retro_var_value = "Reduce latency; enabled|disabled",
		.info = "Begins frame in SNES VBlank.",
	},
	{
		.key = "supafaust_run_ahead",
		.retro_var_value = "Run-ahead; disabled|video|video+audio",
		.info = "Enable 1-frame run-ahead.",
	},
	{
		.key = "supafaust_cx4_clock_rate",
		.retro_var_value = "CX4 clock (%); 100|125|150|175|200|250|300|400|500",
		.info = "Set clock speed for the CX4 coprocessor.",
	},
	{
		.key = "supafaust_superfx_clock_rate",
		.retro_var_value = "SuperFX clock (%); 100|125|150|175|200|250|300|400|500|95",
		.info = "Set clock speed for the Super FX coprocessor.",
	},
	{
		.key = "supafaust_superfx_icache",
		.retro_var_value = "SuperFX icache; disabled|enabled",
		.info = "Emulate SuperFX instruction cache.",
	},
	{
		.key = "supafaust_audio_rate",
		.default_value = "disabled",
		.blocked = true,
	},
	{
		.key = "supafaust_correct_aspect",
		.default_value = "enabled",
		.blocked = true,
	},
	{
		.key = "supafaust_multitap",
		.default_value = "disabled",
		.blocked = true,
	},
	{
		.key = "supafaust_pixel_format",
		.default_value = "rgb565",
		.blocked = true,
	},
	{
		.key = "supafaust_renderer",
		.default_value = "mt",
		.blocked = true,
	},
	{
		.key = "supafaust_thread_affinity_emu",
		.blocked = true,
	},
	{
		.key = "supafaust_thread_affinity_ppu",
		.blocked = true,
	},
	{ NULL }
};

me_bind_action mednafen_supafaust_ctrl_actions[] =
{
	{ "UP       ",  1 << RETRO_DEVICE_ID_JOYPAD_UP},
	{ "DOWN     ",  1 << RETRO_DEVICE_ID_JOYPAD_DOWN },
	{ "LEFT     ",  1 << RETRO_DEVICE_ID_JOYPAD_LEFT },
	{ "RIGHT    ",  1 << RETRO_DEVICE_ID_JOYPAD_RIGHT },
	{ "A BUTTON ",  1 << RETRO_DEVICE_ID_JOYPAD_A },
	{ "B BUTTON ",  1 << RETRO_DEVICE_ID_JOYPAD_B },
	{ "X BUTTON ",  1 << RETRO_DEVICE_ID_JOYPAD_X },
	{ "Y BUTTON ",  1 << RETRO_DEVICE_ID_JOYPAD_Y },
	{ "START    ",  1 << RETRO_DEVICE_ID_JOYPAD_START },
	{ "SELECT   ",  1 << RETRO_DEVICE_ID_JOYPAD_SELECT },
	{ "L BUTTON ",  1 << RETRO_DEVICE_ID_JOYPAD_L },
	{ "R BUTTON ",  1 << RETRO_DEVICE_ID_JOYPAD_R },
	{ NULL,       0 }
};

const struct core_override_fast_forward mednafen_supafaust_fast_forward = {
	.type_key = "supafaust_frameskip",
	.type_value = "auto",
	.interval_key = "supafaust_frameskip_interval"
};

#define mednafen_supafaust_overrides {                          \
	.core_name = "mednafen_supafaust",                          \
	.fast_forward = &mednafen_supafaust_fast_forward,           \
	.actions = mednafen_supafaust_ctrl_actions,                 \
	.action_size = array_size(mednafen_supafaust_ctrl_actions), \
	.options = mednafen_supafaust_core_option_overrides         \
}
