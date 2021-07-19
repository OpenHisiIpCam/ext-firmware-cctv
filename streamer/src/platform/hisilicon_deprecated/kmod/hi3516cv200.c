#if 0
var (
ModulesList = [...][2]string{
    [2]string{"sys_config.ko", "vi_vpss_online={vi_vpss_online} sensor={cmos} pin_mux_select={pin_mux_select}"}, //TODO!!!!!!!!!!!!!!!!!!!!!

    [2]string{"mmz.ko", "mmz=anonymous,0,{mem_start_addr},{mem_mpp_size} anony=1"},
    [2]string{"hi_media.ko", ""},
    [2]string{"hi3518e_base.ko", ""},
    [2]string{"hi3518e_sys.ko", "vi_vpss_online={vi_vpss_online} sensor={cmos} mem_total={mem_total_size}"},

    [2]string{"hi3518e_tde.ko", ""},
    [2]string{"hi3518e_region.ko", ""},
    [2]string{"hi3518e_vgs.ko", ""},
    //[2]string{"hi3518e_isp.ko", "update_pos=1"}, //ov9750
    [2]string{"hi3518e_isp.ko", "update_pos={update_pos} proc_param={proc_param}"}, //rest cmoses
    [2]string{"hi3518e_viu.ko", "detect_err_frame={detect_err_frame}"}, //10
    [2]string{"hi3518e_vpss.ko", "rfr_frame_comp={rfr_frame_comp}"},
    //[2]string{"hi3518e_vou.ko", ""},
    //[2]string{"hi3518e_vou.ko", "transparentTransmit=1"}, //enable transparentTransmit
    //[2]string{"hifb.ko", 'video="hifb:vram0_size:1620"'}, //default pal
    [2]string{"hi3518e_rc.ko", ""},
    [2]string{"hi3518e_venc.ko", ""},
    [2]string{"hi3518e_chnl.ko", "ChnlLowPower={ChnlLowPower}"},
    [2]string{"hi3518e_h264e.ko", "H264eMiniBufMode={H264eMiniBufMode}"},
    [2]string{"hi3518e_jpege.ko", ""},
    [2]string{"hi3518e_ive.ko", "save_power={save_power}"}, //0
    //[2]string{"hi3518e_ive.ko", ""},
    [2]string{"sensor_i2c.ko", ""},
    //[2]string{"pwm.ko", ""},
    //[2]string{"piris.ko", ""},

    [2]string{"acodec.ko", ""},
    [2]string{"hi3518e_aio.ko", ""},
    [2]string{"hi3518e_ai.ko", ""},
    [2]string{"hi3518e_ao.ko", ""},
    [2]string{"hi3518e_aenc.ko", ""},
    [2]string{"hi3518e_adec.ko", ""},
    [2]string{"hi_mipi.ko", ""},
}

MinimalModulesList = [...]string{
    "mmz.ko",
    "hi_media.ko",
    "hi3518e_base.ko",
    "hi3518e_sys.ko",
}
)

#endif
