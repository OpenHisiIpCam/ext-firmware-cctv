/*
 * Copyright (C) Hisilicon Technologies Co., Ltd. 2018-2019. All rights reserved.
 * Description : hi_comm_motionfusion.h
 * Author : ISP SW
 * Create : 2018-12-22
 * Version : Initial Draft
 */
#ifndef __HI_COMM_MOTIONFUSION_H__
#define __HI_COMM_MOTIONFUSION_H__

#include "hi_type.h"
#include "hi_errno.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

#define EN_ERR_GYRO_NOTWORK 20
#define EN_ERR_ACC_NOTWORK  21
#define EN_ERR_MODE         22
#define EN_ERR_USECASE      23

#define HI_ERR_MOTIONFUSION_NOT_CONFIG    HI_DEF_ERR(HI_ID_MOTIONFUSION, EN_ERR_LEVEL_ERROR, EN_ERR_NOT_CONFIG)
#define HI_ERR_MOTIONFUSION_NOBUF         HI_DEF_ERR(HI_ID_MOTIONFUSION, EN_ERR_LEVEL_ERROR, EN_ERR_NOBUF)
#define HI_ERR_MOTIONFUSION_BUF_EMPTY     HI_DEF_ERR(HI_ID_MOTIONFUSION, EN_ERR_LEVEL_ERROR, EN_ERR_BUF_EMPTY)
#define HI_ERR_MOTIONFUSION_NULL_PTR      HI_DEF_ERR(HI_ID_MOTIONFUSION, EN_ERR_LEVEL_ERROR, EN_ERR_NULL_PTR)
#define HI_ERR_MOTIONFUSION_ILLEGAL_PARAM HI_DEF_ERR(HI_ID_MOTIONFUSION, EN_ERR_LEVEL_ERROR, EN_ERR_ILLEGAL_PARAM)
#define HI_ERR_MOTIONFUSION_BUF_FULL      HI_DEF_ERR(HI_ID_MOTIONFUSION, EN_ERR_LEVEL_ERROR, EN_ERR_BUF_FULL)
#define HI_ERR_MOTIONFUSION_SYS_NOTREADY  HI_DEF_ERR(HI_ID_MOTIONFUSION, EN_ERR_LEVEL_ERROR, EN_ERR_SYS_NOTREADY)
#define HI_ERR_MOTIONFUSION_NOT_SUPPORT   HI_DEF_ERR(HI_ID_MOTIONFUSION, EN_ERR_LEVEL_ERROR, EN_ERR_NOT_SUPPORT)
#define HI_ERR_MOTIONFUSION_NOT_PERMITTED HI_DEF_ERR(HI_ID_MOTIONFUSION, EN_ERR_LEVEL_ERROR, EN_ERR_NOT_PERM)
#define HI_ERR_MOTIONFUSION_BUSY          HI_DEF_ERR(HI_ID_MOTIONFUSION, EN_ERR_LEVEL_ERROR, EN_ERR_BUSY)
#define HI_ERR_MOTIONFUSION_INVALID_CHNID HI_DEF_ERR(HI_ID_MOTIONFUSION, EN_ERR_LEVEL_ERROR, EN_ERR_INVALID_CHNID)
#define HI_ERR_MOTIONFUSION_CHN_UNEXIST     HI_DEF_ERR(HI_ID_MOTIONFUSION, EN_ERR_LEVEL_ERROR, EN_ERR_UNEXIST)
#define HI_ERR_MOTIONFUSION_GYRO_NOTWORK    HI_DEF_ERR(HI_ID_MOTIONFUSION, EN_ERR_LEVEL_ERROR, EN_ERR_GYRO_NOTWORK)
#define HI_ERR_MOTIONFUSION_ACC_NOTWORK     HI_DEF_ERR(HI_ID_MOTIONFUSION, EN_ERR_LEVEL_ERROR, EN_ERR_ACC_NOTWORK)
#define HI_ERR_MOTIONFUSION_INVALID_MODE    HI_DEF_ERR(HI_ID_MOTIONFUSION, EN_ERR_LEVEL_ERROR, EN_ERR_MODE)
#define HI_ERR_MOTIONFUSION_INVALID_USECASE HI_DEF_ERR(HI_ID_MOTIONFUSION, EN_ERR_LEVEL_ERROR, EN_ERR_USECASE)

#define MFUSION_MAX_CHN_NUM 1

#define AXIS_NUM         3
#define MATRIX_NUM       9
#define MATRIX_TEMP_NUM  9
#define TEMP_LUT_SAMPLES 30

#define MFUSION_TEMP_GYRO 0x1
#define MFUSION_TEMP_ACC  0x2
#define MFUSION_TEMP_MAGN 0x4
#define MFUSION_TEMP_ALL  0x7

#define MFUSION_DEVICE_GYRO 0x1
#define MFUSION_DEVICE_ACC  0x2
#define MFUSION_DEVICE_MAGN 0x4
#define MFUSION_DEVICE_ALL  0x7

#define SIXSIDE_MATRIX_GRADINT 15
#define ZERO_OFFSET_GRADINT    15
#define TEMP_OFFSET_GRADINT    15

#define MFUSION_COMM_BUFFER_SIZE 128
#define MFUSION_LUT_STATUS_NUM   2

typedef hi_s32 IMU_DRIFT[AXIS_NUM];
typedef hi_s32 IMU_MATRIX[MATRIX_NUM];
typedef hi_s32 IMU_MATRIX_TEMP[MATRIX_TEMP_NUM];

typedef struct {
    hi_u32 steady_time_thr;    /* RW; continues steady time (in sec)
                                  threshold for steady detection
                                  range: [0, (1<<16-1] */
    hi_s32 gyro_offset;        /* RW; max gyro ZRO tolerance presented in datasheet,
                                  with (ADC word length - 1) decimal bits
                                  range: [0, 100 * (1<<15)] */
    hi_s32 acc_offset;         /* RW; max acc ZRO tolerance presented in datasheet,
                                  with (ADC word length - 1) decimal bits
                                  range: [0, 0.5 * (1<<15)] */
    hi_s32 gyro_rms;           /* RW; gyro rms noise of under the current filter BW,
                                  with (ADC Word Length - 1) decimal bits
                                  range: [0, 0.5 * (1<<15)] */
    hi_s32 acc_rms;            /* RW; acc rms noise of under the current filter BW
                                  with (acc word length - 1) decimal bits
                                  range: [0, 0.005 * (1<<15)] */
    hi_s32 gyro_offset_factor; /* RW; scale factor of gyro offset for steady detection,
                                  larger -> higher recall, but less the precision
                                  range: [0, 1000 * (1<<4)] */
    hi_s32 acc_offset_factor;  /* RW; scale factor of acc offset for steady detection,
                                  larger -> higher recall, but less the precision
                                  range: [0, 1000 * (1<<4)] */
    hi_s32 gyro_rms_factor;    /* RW; scale factor of gyro rms for steady detection,
                                  larger -> higher recall, but less the precision
                                  range: [0, 1000 * (1<<4)] */
    hi_s32 acc_rms_factor;     /* RW; scale factor of acc rms for steady detection,
                                  larger -> higher recall, but less the precision
                                  range: [0, 1000 * (1<<4)] */
}hi_mfusion_steady_detect_attr;

typedef struct {
    hi_u32 device_mask;        /* device mask: gyro,acc or magn */
    hi_u32 temperature_mask;   /* temperature mask: gyro temperature ,acc temperatureor magn temperature */
    hi_mfusion_steady_detect_attr steady_detect_attr;
} hi_mfusion_attr;

/* angle data per sample */
typedef struct {
    hi_s32 x;
    hi_s32 y;
    hi_s32 z;
    hi_s32 temp;
    hi_u64 pts;
} hi_mfusion_sample_data;

typedef struct {
    hi_mfusion_sample_data gyro_data[MFUSION_COMM_BUFFER_SIZE];
    hi_u32 buff_data_num;     /* RW; data length of the occupied buffer */
    hi_u32 buff_rep_num;      /* RW; data start position of invalid, incase of pts overlap */
} hi_mfusion_gyro_buffer;

typedef struct {
    hi_mfusion_sample_data acc_data[MFUSION_COMM_BUFFER_SIZE];
    hi_u32 buff_data_num;    /* RW; data length of the occupied buffer */
    hi_u32 buff_rep_num;     /* RW; data start position of invalid, incase of pts overlap */
} hi_mfusion_acc_buffer;

typedef enum {
    IMU_TEMP_DRIFT_CURV = 0, /* polynomial mode */
    IMU_TEMP_DRIFT_LUT,      /* lookup table mode */
    IMU_TEMP_DRIFT_BUTT
} hi_mfusion_temp_drift_mode;

typedef struct {
    hi_s32 imu_lut[TEMP_LUT_SAMPLES][AXIS_NUM]; /* RW;temperature drift lookup table
                             the 1st col is the time (in sec) for which the sample has not been updated.
                             the 2nd col is the nearest temperature sample during update */
    hi_s32 gyro_lut_status[TEMP_LUT_SAMPLES][MFUSION_LUT_STATUS_NUM];
    hi_s32 range_min;       /* RW;temperature range minimum  */
    hi_s32 range_max;       /* RW;temperature range maximum  */
    hi_u32 step;
} hi_mfusion_temp_drift_lut;

typedef struct {
    hi_mfusion_temp_drift_mode mode;        /* RW;temperature drift mode  */
    union {
        IMU_MATRIX_TEMP temp_matrix;        /* RW;temperature drift polynomial matrix data */
        hi_mfusion_temp_drift_lut temp_lut; /* RW;temperature drift  lookup table data */
    };
} hi_mfusion_temp_drift;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif

