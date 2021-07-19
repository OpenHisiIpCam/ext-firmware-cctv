#if 0
var (
ModulesList = [...][2]string{
    [2]string{"mmz.ko", "mmz=anonymous,0,{mem_start_addr},{mem_mpp_size} anony=1"},
    [2]string{"hi_media.ko", ""},
    [2]string{"hi3516a_base.ko", ""},
    [2]string{"hi3516a_sys.ko", "vi_vpss_online={vi_vpss_online} sensor={cmos}"}, //0
    [2]string{"hi3516a_tde.ko", ""},
    [2]string{"hi3516a_region.ko", ""},
    [2]string{"hi3516a_vgs.ko", ""},
    [2]string{"hi3516a_isp.ko", ""},
    [2]string{"hi3516a_viu.ko", "detect_err_frame={detect_err_frame}"}, //10
    [2]string{"hi3516a_vpss.ko", ""},
    //[2]string{"hi3516a_vou.ko", "lowPowerMode={lowPowerMode}"}, //0
    //#insmod hi3516a_vou.ko detectCycle=0            #close dac detect
    //[2]string{"hifb.ko", 'video="hifb:vram0_size:1620"'}, //     # default pal
    [2]string{"hi3516a_rc.ko", ""},
    [2]string{"hi3516a_venc.ko", ""},
    [2]string{"hi3516a_chnl.ko", ""},
    [2]string{"hi3516a_h264e.ko", ""},
    [2]string{"hi3516a_h265e.ko", ""},
    [2]string{"hi3516a_jpege.ko", ""},
    [2]string{"hi3516a_vda.ko", ""},
    [2]string{"hi3516a_ive.ko", ""},
    [2]string{"sensor_i2c.ko", ""},
    [2]string{"pwm.ko", ""},
    [2]string{"piris.ko", ""},
    //#insmod extdrv/adv_7441.ko
    //insmod extdrv/sil9024.ko norm=12    #1080P@30fps
    //echo "==== Your input Sensor type is $SNS_TYPE ===="
    //#insert_sns > /dev/null
    //insert_sns

    //insert_audio
    [2]string{"acodec.ko", ""},
    //#insmod hidmac.ko
    [2]string{"hi3516a_aio.ko", ""},
    [2]string{"hi3516a_ai.ko", ""},
    [2]string{"hi3516a_ao.ko", ""},
    [2]string{"hi3516a_aenc.ko", ""},
    [2]string{"hi3516a_adec.ko", ""},
    //#insmod extdrv/tlv_320aic31.ko
    //#insmod extdrv/ak7756.ko


    [2]string{"hi_mipi.ko", ""},
}

MinimalModulesList = [...]string{
    "mmz.ko",
    "hi_media.ko",
    "hi3516a_base.ko",
    "hi3516a_sys.ko",
}
)

#endif
