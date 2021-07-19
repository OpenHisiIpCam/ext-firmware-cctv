#if 0
typedef struct mpp_sys_init_in_struct {
    unsigned int width;
    unsigned int height;
    unsigned int cnt;
} mpp_sys_init_in;

int mpp_sys_vb_conf(mpp_sys_init_in *in){
	VB_CONF_S   stVbConf;

	memset(&stVbConf, 0, sizeof(stVbConf));

	    stVbConf.u32MaxPoolCnt                  = 128;
        stVbConf.astCommPool[0].u32BlkSize  = (CEILING_2_POWER_L(in->width, 128) * CEILING_2_POWER_L(in->height, 128) * 1.5);

	stVbConf.astCommPool[0].u32BlkCnt       = in->cnt;

	return HI_MPI_VB_SetConf(&stVbConf);
}

int mpp_sys_sys_conf() {
        MPP_SYS_CONF_S stSysConf;

        memset(&stSysConf, 0, sizeof(MPP_SYS_CONF_S));
        stSysConf.u32AlignWidth = 64;

        return HI_MPI_SYS_SetConf(&stSysConf);
}

int mpp_sys_init(error_in *err, mpp_sys_init_in *in) {

    DO_OR_RETURN_ERR_MPP(err, HI_MPI_SYS_Exit);

    DO_OR_RETURN_ERR_MPP(err, HI_MPI_VB_Exit);

    DO_OR_RETURN_ERR_MPP(err, mpp_sys_vb_conf, in);

    DO_OR_RETURN_ERR_MPP(err, HI_MPI_VB_Init);

    DO_OR_RETURN_ERR_MPP(err, mpp_sys_sys_conf);

    DO_OR_RETURN_ERR_MPP(err, HI_MPI_SYS_Init);

    return ERR_NONE;
}
#endif
