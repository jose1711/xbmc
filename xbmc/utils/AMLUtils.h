/*
 *  Copyright (C) 2011-2018 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#pragma once

#include <xf86drm.h>
#include <xf86drmMode.h>

#include "windowing/Resolution.h"

#include <string>
#include <vector>

enum AML_DEVICE_TYPE
{
  AML_DEVICE_TYPE_UNINIT   = -2,
  AML_DEVICE_TYPE_UNKNOWN  = -1,
  AML_DEVICE_TYPE_M1,
  AML_DEVICE_TYPE_M3,
  AML_DEVICE_TYPE_M6,
  AML_DEVICE_TYPE_M8,   // S802
  AML_DEVICE_TYPE_M8B,  // S805
  AML_DEVICE_TYPE_M8M2  // S812
};

enum AML_DISPLAY_AXIS_PARAM
{
  AML_DISPLAY_AXIS_PARAM_X = 0,
  AML_DISPLAY_AXIS_PARAM_Y,
  AML_DISPLAY_AXIS_PARAM_WIDTH,
  AML_DISPLAY_AXIS_PARAM_HEIGHT
};

enum AML_SUPPORT_H264_4K2K
{
  AML_SUPPORT_H264_4K2K_UNINIT = -1,
  AML_NO_H264_4K2K,
  AML_HAS_H264_4K2K,
  AML_HAS_H264_4K2K_SAME_PROFILE
};

#define AML_GXBB    0x1F
#define AML_GXL     0x21
#define AML_GXM     0x22
#define AML_G12A    0x28
#define AML_G12B    0x29
#define AML_SM1     0x2B
#define AML_SC2     0x32
#define AML_T7      0x36
#define AML_S4      0x37

int  aml_get_cpufamily_id();
bool aml_support_hevc();
bool aml_support_hevc_4k2k();
bool aml_support_hevc_8k4k();
bool aml_support_hevc_10bit();
AML_SUPPORT_H264_4K2K aml_support_h264_4k2k();
bool aml_support_vp9();
bool aml_support_av1();
bool aml_support_dolby_vision();
bool aml_has_frac_rate_policy();
void aml_set_audio_passthrough(bool passthrough);
bool aml_mode_to_resolution(const char *mode, RESOLUTION_INFO *res);
bool aml_get_native_resolution(RESOLUTION_INFO *res);
bool aml_set_native_resolution(const RESOLUTION_INFO &res, std::string framebuffer_name, const int stereo_mode, bool force_mode_switch);
bool aml_probe_resolutions(std::vector<RESOLUTION_INFO> &resolutions);
bool aml_set_display_resolution(const RESOLUTION_INFO &res, std::string framebuffer_name, bool force_mode_switch);
void aml_handle_display_stereo_mode(const int stereo_mode);
void aml_set_framebuffer_resolution(const RESOLUTION_INFO &res, std::string framebuffer_name);
void aml_set_framebuffer_resolution(unsigned int width, unsigned int height, std::string framebuffer_name);
bool aml_read_reg(const std::string &reg, uint32_t &reg_val);
bool aml_has_capability_ignore_alpha();
bool aml_set_reg_ignore_alpha();
bool aml_unset_reg_ignore_alpha();

void aml_set_drmProperty(std::string name, unsigned int obj_type, unsigned int value);
int aml_get_drmProperty(std::string name, unsigned int obj_type);
