#if 0
var (
ModulesList = [...][2]string{
    [2]string{"sys_config.ko", "chip={chip} sensors=sns0={cmos},sns1=NULL, g_cmos_yuv_flag={g_cmos_yuv_flag}"}, //TODO!!!!!!!!!!!!!!!!
    [2]string{"hi_osal.ko", "anony=1 mmz_allocator=hisi mmz=anonymous,0,{mem_start_addr},{mem_mpp_size}"},
    [2]string{"hi3516cv500_base.ko", ""},
    [2]string{"hi3516cv500_sys.ko", ""},
    // insmod hi_tzasc.ko
    [2]string{"hi3516cv500_tde.ko", ""},
    [2]string{"hi3516cv500_rgn.ko", ""},
    [2]string{"hi3516cv500_gdc.ko", ""},
    [2]string{"hi3516cv500_vgs.ko", ""},
    [2]string{"hi3516cv500_dis.ko", ""},
    [2]string{"hi3516cv500_vi.ko", ""},
    [2]string{"hi3516cv500_isp.ko", ""},
    [2]string{"hi3516cv500_vpss.ko", ""},
    [2]string{"hi3516cv500_vo.ko", ""},
    //[2]string{"hifb.ko", "video=\"hifb:vram0_size:1620\""},     //# default fb0:1080p
    [2]string{"hi3516cv500_rc.ko", ""},
    [2]string{"hi3516cv500_venc.ko", ""},
    [2]string{"hi3516cv500_chnl.ko", ""},
    [2]string{"hi3516cv500_vedu.ko", ""},
    [2]string{"hi3516cv500_h264e.ko", ""},
    [2]string{"hi3516cv500_h265e.ko", ""},
    [2]string{"hi3516cv500_jpege.ko", ""},
    [2]string{"hi3516cv500_jpegd.ko", ""},
    [2]string{"hi3516cv500_vfmw.ko", ""},  // [2]string{"hi3516cv500_vfmw.ko", "vdecmaxvchnnum=1"},
    [2]string{"hi3516cv500_vdec.ko", ""}, //[2]string{"hi3516cv500_vdec.ko", "vfmwmaxchnnum=1"},

    [2]string{"hi3516cv500_ive.ko", "save_power=0"},
    //#       insmod /lib/modules/hi3516dv300/hi_ipcm.ko
    //        #nnie_max_tskbuf_num=64
    //        #insmod /lib/modules/hi3516dv300/hi3516cv500_nnie.ko nnie_save_power=1 nnie_max_tskbuf_num=32
    [2]string{"hi3516cv500_nnie.ko", "nnie_save_power=1 nnie_max_tskbuf_num=32"},
    [2]string{"hi_pwm.ko", ""},
    [2]string{"hi_piris.ko", ""},
    [2]string{"hi_sensor_i2c.ko", ""},
    //        #insmod /lib/modules/hi3516dv300/extdrv/hi_sensor_spi.ko
    //#       insmod extdrv/hi_sil9136.ko norm=12    #1080P@30fps for umap7p
    //#       insmod extdrv/mpu_bosch.ko
    //#       insmod extdrv/hi_ssp_st7789.ko
    //#       insmod extdrv/hi_ssp_ota5182.ko
    [2]string{"hi3516cv500_hdmi.ko", ""},
    [2]string{"hi3516cv500_aio.ko", ""},
    [2]string{"hi3516cv500_ai.ko", ""},
    [2]string{"hi3516cv500_ao.ko", ""},
    [2]string{"hi3516cv500_aenc.ko", ""},
    [2]string{"hi3516cv500_adec.ko", ""},
    [2]string{"hi3516cv500_acodec.ko", ""},
    [2]string{"hi_mipi_rx.ko", ""},
    //#       insmod hi_mipi_tx.ko
    //#       insmod hi_user.ko
}

MinimalModulesList = [...]string{
    "sys_config.ko",
    "hi_osal.ko",
    "hi3516cv500_base.ko",
    "hi3516cv500_sys.ko",
}
)

#endif
