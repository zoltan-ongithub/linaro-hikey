/*
 *  Hisilicon Terminal SoCs drm driver
 *
 *  Copyright (c) 2014-2015 Hisilicon Limited.
 *  Author:
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */
#ifndef __HISI_DRM_DSI_H__
#define __HISI_DRM_DSI_H__

#define encoder_to_dsi(encoder) \
	container_of(encoder, struct hisi_dsi, base.base)

struct mipi_dsi_phy_register {
	u32 clk_t_lpx;
	u32 clk_t_hs_prepare;
	u32 clk_t_hs_zero;
	u32 clk_t_hs_trial;
	u32 clk_t_wakeup;
	u32 data_t_lpx;
	u32 data_t_hs_prepare;
	u32 data_t_hs_zero;
	u32 data_t_hs_trial;
	u32 data_t_ta_go;
	u32 data_t_ta_get;
	u32 data_t_wakeup;
	u32 rg_hstx_ckg_sel;
	u32 rg_pll_fbd_div5f;
	u32 rg_pll_fbd_div1f;
	u32 rg_pll_fbd_2p;
	u32 rg_pll_enbwt;
	u32 rg_pll_fbd_p;
	u32 rg_pll_fbd_s;
	u32 rg_pll_pre_div1p;
	u32 rg_pll_pre_p;
	u32 rg_pll_vco_750M;
	u32 rg_pll_lpf_rs;
	u32 rg_pll_lpf_cs;
	u32 phy_clklp2hs_time;
	u32 phy_clkhs2lp_time;
	u32 phy_lp2hs_time;
	u32 phy_hs2lp_time;
	u32 clk_to_data_delay;
	u32 data_to_clk_delay;
	u32 lane_byte_clk_kHz;
	u32 clk_division;
	u32 burst_mode;
};

struct hisi_dsi {
	struct drm_encoder_slave base;
	struct drm_connector connector;
	struct i2c_client *client;
	struct drm_i2c_encoder_driver *drm_i2c_driver;
	struct clk *dsi_cfg_clk;
	struct videomode vm;
	int nominal_pixel_clock_kHz;

	u8 __iomem *reg_base;
	u8 color_mode;

	u32 lanes;
	u32 format;
	struct mipi_dsi_phy_register phyreg;
	u32 date_enable_pol;
	u32 vc;
	u32 mode_flags;
	bool enable;

	/* when detect dsi transfer error call this callback to reset dsi */
	int (*reset)(struct drm_encoder *encoder);
};

#endif /* __HISI_DRM_DSI_H__ */
