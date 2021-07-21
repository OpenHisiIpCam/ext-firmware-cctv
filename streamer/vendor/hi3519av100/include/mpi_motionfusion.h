/*
 * Copyright (C) Hisilicon Technologies Co., Ltd. 2018-2019. All rights reserved.
 * Description : mpi_motionfusion.h
 * Author : ISP SW
 * Create : 2018-12-22
 * Version : Initial Draft
 */
#ifndef __MPI_MOTIONFUSION_H__
#define __MPI_MOTIONFUSION_H__

#include "hi_type.h"
#include "hi_comm_motionfusion.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */

#define MOTIONFUSION_DEVICE_ID_0 0
#define MOTIONFUSION_DEVICE_ID_1 1

hi_s32 hi_mpi_motionfusion_set_attr(const hi_u32 fusion_id, const hi_mfusion_attr *mfusion_attr);

hi_s32 hi_mpi_motionfusion_get_attr(const hi_u32 fusion_id, hi_mfusion_attr *mfusion_attr);

hi_s32 hi_mpi_motionfusion_set_gyro_drift(const hi_u32 fusion_id,
                                          const hi_bool enable,
                                          const IMU_DRIFT drift);

hi_s32 hi_mpi_motionfusion_get_gyro_drift(const hi_u32 fusion_id,
                                          hi_bool *enable,
                                          IMU_DRIFT drift);

hi_s32 hi_mpi_motionfusion_set_gyro_six_side_cal(const hi_u32 fusion_id,
                                                 const hi_bool enable,
                                                 const IMU_MATRIX matrix);

hi_s32 hi_mpi_motionfusion_get_gyro_six_side_cal(const hi_u32 fusion_id,
                                                 hi_bool *enable,
                                                 IMU_MATRIX matrix);

hi_s32 hi_mpi_motionfusion_set_gyro_temp_drift(const hi_u32 fusion_id,
                                               const hi_bool enable,
                                               const hi_mfusion_temp_drift *temp_drift);

hi_s32 hi_mpi_motionfusion_get_gyro_temp_drift(const hi_u32 fusion_id,
                                               hi_bool *enable,
                                               hi_mfusion_temp_drift *temp_drift);

hi_s32 hi_mpi_motionfusion_set_gyro_online_temp_drift(const hi_u32 fusion_id,
                                                      const hi_bool enable,
                                                      const hi_mfusion_temp_drift *temp_drift);

hi_s32 hi_mpi_motionfusion_get_gyro_online_temp_drift(const hi_u32 fusion_id,
                                                      hi_bool *enable,
                                                      hi_mfusion_temp_drift *temp_drift);

hi_s32 hi_mpi_motionfusion_set_gyro_online_drift(const hi_u32 fusion_id,
                                                 const hi_bool enable,
                                                 const IMU_DRIFT drift);

hi_s32 hi_mpi_motionfusion_get_gyro_online_drift(const hi_u32 fusion_id,
                                                 hi_bool *enable,
                                                 IMU_DRIFT drift);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif /* End of #ifndef __MPI_MONTIONFUSION_H__ */
