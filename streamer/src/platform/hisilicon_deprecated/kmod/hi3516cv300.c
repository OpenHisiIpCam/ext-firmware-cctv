#if 0
/*
default)
vou_intf_mode="default";
vedu_frequency=198000000;  # 198M, vedu clock frequency
vgs_frequency=297000000;  # 297M, vgs clock frequency
vpss_frequency=250000000;  # 250M, vpss clock frequency
ive_frequency=297000000;  # 297M, ive clock frequency
/////////
        imx290)
                        bus_type="i2c";
                        pinmux_mode="i2c_mipi";
                        sensor_clk_freq=37125000;
                        intf_mode="default";
                        viu_frequency=198000000;  # 198M, viu clock frequency
                        isp_div=2;                # isp div clk, freq = viu_clk_freq / div
            ;;
        imx323)
                        bus_type="ssp";
                        pinmux_mode="ssp_dc";
                        sensor_clk_freq=37125000;
                        intf_mode="default";
                        viu_frequency=198000000;  # 198M, viu clock frequency
                        isp_div=2;                # isp div clk, freq = viu_clk_freq / div
            ;;
*/

var (
ModulesList = [...][2]string{
    [2]string{"sys_config.ko", "vi_vpss_online={vi_vpss_online}"}, //TODO!!!!!!!!!
    //[2]string{"sys_config.ko", ""},
    [2]string{"hi_osal.ko", "mmz=anonymous,0,{mem_start_addr},{mem_mpp_size} anony=1"},
    [2]string{"hi3516cv300_base.ko", ""},
    [2]string{"hi3516cv300_sys.ko", "vi_vpss_online={vi_vpss_online} sensor={cmos} mem_total={mem_total_size}"},
    [2]string{"hi3516cv300_region.ko", ""},
    [2]string{"hi3516cv300_vgs.ko", "vgs_clk_frequency={vgs_clk_frequency}"},
    //[2]string{"hi3516cv300_viu.ko", "detect_err_frame=10 viu_clk_frequency=198000000 isp_div=2 input_mode=default"},
    [2]string{"hi3516cv300_viu.ko", "detect_err_frame={detect_err_frame} viu_clk_frequency={viu_clk_frequency} isp_div={isp_div} input_mode={input_mode}"}, // 10 19800000 2 default
    //[2]string{"hi3516cv300_isp.ko", "update_pos=0 proc_param=30 port_init_delay=0"},
    [2]string{"hi3516cv300_isp.ko", "update_pos={update_pos} proc_param={proc_param} port_init_delay={port_init_delay}"}, //0 30 0
    [2]string{"hi3516cv300_vpss.ko", "vpss_clk_frequency={vpss_clk_frequency}"}, //250000000
    [2]string{"hi3516cv300_vou.ko", "vou_mode=default"},
    //    #insmod hi3516cv300_vou.ko detectCycle=0 vou_mode=$vou_intf_mode #close dac detect
    //    #insmod hi3516cv300_vou.ko transparentTransmit=1 vou_mode=$vou_intf_mode #enable transparentTransmit
    [2]string{"hi3516cv300_rc.ko", ""},
    [2]string{"hi3516cv300_venc.ko", ""},
    [2]string{"hi3516cv300_chnl.ko", ""},
    [2]string{"hi3516cv300_vedu.ko", "vedu_clk_frequency={vedu_clk_frequency}"}, //198000000
    [2]string{"hi3516cv300_h264e.ko", ""},
    [2]string{"hi3516cv300_h265e.ko", ""},
    [2]string{"hi3516cv300_jpege.ko", ""},
    [2]string{"hi3516cv300_ive.ko", "save_power={save_power} ive_clk_frequency={ive_clk_frequency}"}, //1 297000000
    [2]string{"hi3516cv300_sensor.ko", "sensor_bus_type={sensor_bus_type} sensor_clk_frequency={sensor_clk_frequency} sensor_pinmux_mode={sensor_pinmux_mode}"},
    //[2]string{"hi3516cv300_sensor.ko", "sensor_bus_type=i2c sensor_clk_frequency=37125000 sensor_pinmux_mode=i2c_dc"},
    //[2]string{"hi3516cv300_sensor.ko", "sensor_bus_type=ssp sensor_clk_frequency=37125000 sensor_pinmux_mode=ssp_dc"},
    //[2]string{"hi3516cv300_sensor.ko", "sensor_bus_type=i2c sensor_clk_frequency=37125000 sensor_pinmux_mode=i2c_mipi"},
    //[2]string{"hi3516cv300_pwm.ko", ""},//TODO
    //[2]string{"hi_piris.ko", ""},
    [2]string{"hi3516cv300_aio.ko", ""},
    [2]string{"hi3516cv300_ai.ko", ""},
    [2]string{"hi3516cv300_ao.ko", ""},
    [2]string{"hi3516cv300_aenc.ko", ""},
    [2]string{"hi3516cv300_adec.ko", ""},
    [2]string{"hi_acodec.ko", ""},
    [2]string{"hi_mipi.ko", ""},
}

MinimalModulesList = [...]string{
    "sys_config.ko",
    "hi_osal.ko",
    "hi3516cv300_base.ko",
    "hi3516cv300_sys.ko",
}
)

#endif
