#if 0
var (
ModulesList = [...][2]string{
    [2]string{"hi_osal.ko", "mmz=anonymous,0,{mem_start_addr},{mem_mpp_size} anony=1"},
    [2]string{"hi3519v101_base.ko", ""},
    [2]string{"hi3519v101_sys.ko", "vi_vpss_online={vi_vpss_online} sensor={cmos},NULL mem_total={mem_total_size}"},
    [2]string{"hi3519v101_tde.ko", ""}, //ALL
    [2]string{"hi3519v101_region.ko", ""},
    [2]string{"hi3519v101_fisheye.ko", ""},
    [2]string{"hi3519v101_vgs.ko", ""},
    [2]string{"hi3519v101_isp.ko", "proc_param={proc_param}"},
    [2]string{"hi3519v101_viu.ko", "detect_err_frame={detect_err_frame}"},
    [2]string{"hi3519v101_vpss.ko", ""},
    [2]string{"hi3519v101_vou.ko", ""},
    //[2]string{"hifb.ko",              "video='hifb:vram0_size:1620'"},
    [2]string{"hi3519v101_rc.ko", ""},
    [2]string{"hi3519v101_venc.ko", ""},
    [2]string{"hi3519v101_chnl.ko", ""},
    [2]string{"hi3519v101_vedu.ko", ""},
    [2]string{"hi3519v101_h264e.ko", ""},
    [2]string{"hi3519v101_h265e.ko", ""},
    [2]string{"hi3519v101_jpege.ko", ""},
    [2]string{"hi3519v101_ive.ko", "save_power={save_power}"}, //ALL
    [2]string{"hi3519v101_photo.ko", ""},           //ALL
    //[2]string{"hi_sensor_i2c.ko",     ""},//ALL
    [2]string{"hi_pwm.ko", ""},
    //[2]string{"hi_piris.ko",          ""},
    //[2]string{"hi_sil9136.ko",        "norm=12"},
    //[2]string{"gyro_bosch.ko",        ""},
    [2]string{"hi3519v101_aio.ko", ""},  //ALL
    [2]string{"hi3519v101_ai.ko", ""},   //ALL
    [2]string{"hi3519v101_ao.ko", ""},   //ALL
    [2]string{"hi3519v101_aenc.ko", ""}, //ALL
    [2]string{"hi3519v101_adec.ko", ""}, //ALL
    [2]string{"hi_acodec.ko", ""},       //ALL
    //[2]string{"hi_tlv320aic31.ko",    ""},
    [2]string{"hi_mipi.ko", ""},
    [2]string{"hi_user.ko", ""},
    //[2]string{"hi_ssp_sony.ko", ""},
}

MinimalModulesList = [...]string{
    "hi_osal.ko",
    "hi3519v101_base.ko",
    "hi3519v101_sys.ko",
}
)

#endif

#if 0
extern const char _binary_hi_osal_ko_start[];
extern const char _binary_hi_osal.ko_end[];
const kmod_item_t test = { .name = "", .start =, .end = };

extern const char _binary_ _start[];
extern const char _binary_ _end[];
const kmod_item_t test = { .name = "", .start =, .end = };

extern const char _binary_ _start[];
extern const char _binary_ _end[];
const kmod_item_t test = { .name = "", .start =, .end = };

extern const char _binary_ _start[];
extern const char _binary_ _end[];
const kmod_item_t test = { .name = "", .start =, .end = };

extern const char _binary_ _start[];
extern const char _binary_ _end[];
const kmod_item_t test = { .name = "", .start =, .end = };

extern const char _binary_ _start[];
extern const char _binary_ _end[];
const kmod_item_t test = { .name = "", .start =, .end = };

extern const char _binary_ _start[];
extern const char _binary_ _end[];
const kmod_item_t test = { .name = "", .start =, .end = };

extern const char _binary_ _start[];
extern const char _binary_ _end[];
const kmod_item_t test = { .name = "", .start =, .end = };

extern const char _binary_ _start[];
extern const char _binary_ _end[];
const kmod_item_t test = { .name = "", .start =, .end = };

extern const char _binary_ _start[];
extern const char _binary_ _end[];
const kmod_item_t test = { .name = "", .start =, .end = };

extern const char _binary_ _start[];
extern const char _binary_ _end[];
const kmod_item_t test = { .name = "", .start =, .end = };
#endif
