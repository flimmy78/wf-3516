
#ifndef _UTIL_H
#define _UTIL_H

#include     <termios.h>   

#include "stdafx.h"

#define LOCKFILE "/mnt/mtd/var/run/sample_venc.pid"

#define LOCKMODE (S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)

#define NONNEGATIVE(x)		(x < 0 ? 10 : x)

typedef struct _eliu_param_t
{
	int is_start;
	int is_connect;
	int record_stream_id;
	int record_fps;
	int record_bitrate;
}eliu_param_t;

typedef enum _gpio_cmd{
	GP_LED_STATUS,
	GP_RESET,
}gpio_cmd_t;

typedef void*  ( *thread_fun)(void *param);

#define SUCCESS 0
#define FAIL	-1

#define ERR_OK				0
#define ERR_READ_CFG		1

#define MAGIC_NUM	0xF2C6EAC2
#define SYS_ENV_SIZE	sizeof(SysInfo)

#define SYS_FILE 	"/mnt/mtd/etc/sysenv.cfg"
#define LOG_FILE 	"/mnt/mtd/etc/logfile.log"
#define VER_FILE  	"/mnt/mtd/etc/version"
#define BOACONF	 	"/mnt/mtd/etc/boa.conf"
#define PTZ_ENV		"/mnt/mtd/etc/ptz_param"
#define TMP_LOG 	"/tmp/run_log_sys"

#define DEVICENAME_DEFAULT			"HI3518_IPNC"


#define IPC2_CFG "/mnt/mtd/etc/ipc2.cfg"
#define DANA_CFG "/mnt/mtd/etc/danale.conf"

#define DEV_MATCH_FILE "/mnt/mtd/load_cfg.sh"

#define SD_PATH	"/mnt/mmc/ipnc"  

#define INTELDEV_PORT	20060
#define ZHONGSH_DEV_PORT	5505

#define IPV4(a,b,c,d)		((d<<24)|(c<<16)|(b<<8)|(a))
// collins 15/1/2010
#define LOG_SYSTEM_SHUTDOWN			"systm shut down"
#define TITLE_DEFAULT				"IPNetCam"
#define IP_DEFAULT					IPV4(192,168, 1,10) //IPV4(10,2,1,6)
#define NETMASK_DEFAULT				IPV4(255,255,255,  0)
#define GATEWAY_DEAFULT				IPV4(192,168, 1,1) //	IPV4(10,2, 1,254)
#define DNS_DEFAULT					IPV4(192,168, 1,1)   //IPV4(10,2,  1,  1)
#define HTTP_PORT_DEFAULT			80
#define DHCP_ENABLE_DEFAULT			0					//dhcp_enable
#define DEVICE_TYPE_DEFAULT			0x1687
#define MAC_DEFAULT					{0x12,0x34,0x56,0x78,0x9a,0xbc}
#define DHCP_CONFIG_DEFAULT			0
#define NO_SCHEDULE					{0,1,{0,0,0},{0,0,0}}
#define SCHEDULE_DEFAULT			{NO_SCHEDULE,NO_SCHEDULE,NO_SCHEDULE,NO_SCHEDULE,NO_SCHEDULE,NO_SCHEDULE,NO_SCHEDULE,NO_SCHEDULE,NO_SCHEDULE,NO_SCHEDULE}
#define LOSTALARM_DEFAULT			0
#define SDAENABLE_DEFAULT			0
#define ALARMDURATION_DEFAULT		0
#define AFTPENABLE_DEFAULT			0
#define ASMTPENABLE_DEFAULT			0
#define AVIDURATION_DEFAULT			0
#define AVIFORMAT_DEFAULT			0
#define FTPFILEFORMAT_DEFAULT		0
#define SDFILEFORMAT_DEFAULT		0
#define ATTFILEFORMAT_DEFAULT		0

/* authority AUTHORITY_NONE = 9 */
#define NONE_ACOUT			 	{ "", "-1", 9}
#define ADMIN_ACOUT			{"admin", "", 0}
#define DANA_ACOUT			{"danale", "admin", 0}
#define ACOUNT_DEFAULT			{ADMIN_ACOUT, DANA_ACOUT, NONE_ACOUT, NONE_ACOUT, NONE_ACOUT, NONE_ACOUT, NONE_ACOUT, NONE_ACOUT, NONE_ACOUT, NONE_ACOUT}
#define SD_INSERT_DEFAULT	0
//GIO
#define	GIOINENABLE_DEFAULT	0
#define	GIOINTYPE_DEFAULT	0
#define	GIOOUTENABLE_DEFAULT	0
#define	GIOOUTTYPE_DEFAULT	0
#define CUR_LOG_DEFAULT	{"", {0, 0, 0, 0, 0, 0, 0, 0, 0}}
#define TSTAMPENABLE_DEFAULT 0
#define TSTAMPFORMAT_DEFAULT 0
#define AUDIOINVOLUME_DEFAULT 2
#define ALARMSTATUS_DEFAULT			0

//#define AVCONFGDEF {{640,480,30,0.3,1,512,3,1,{128,128,128,128,0}},{320,240,30,0.3,1,512,3,0,{0,0,0,0,0}}}


#define AVCONFG0 {1280,720, 0, 0,0, 25,30.0, 0, BITRATE_DEF,1,1,{128,128,128,128,0}, 3}
#define AVCONFG1 {640,480, 0, 0, 0, 25,30.0, 0, 1024, 1,0,{0,0,0,0,0}, 1}
#define AVCONFG2 {352,288, 0, 0, 0, 25,30.0, 0, 128, 1,0,{0,0,0,0,0}, 1}
#define AVCONFG3 {352,288, 0, 0, 0, 25,30.0, 0, 128, 1,0,{0,0,0,0,0}, 1}
#define AVCONFGDEF {AVCONFG0, AVCONFG1, AVCONFG2, AVCONFG3}
/*RECORD Record = {
		{{ RS_NO, RS_NO, RS_NO, RS_NO, RS_NO,RS_NO, RS_NO, RS_NO, RS_NO, RS_NO, RS_NO,RS_NO, RS_NO, RS_NO, RS_NO, RS_NO, RS_NO,RS_NO, RS_NO, RS_NO, RS_NO, RS_NO, RS_NO,RS_NO},
		{ RS_NO, RS_NO, RS_NO, RS_NO, RS_NO,RS_NO, RS_NO, RS_NO, RS_NO, RS_NO, RS_NO,RS_NO, RS_NO, RS_NO, RS_NO, RS_NO, RS_NO,RS_NO, RS_NO, RS_NO, RS_NO, RS_NO, RS_NO,RS_NO},
		{ RS_NO, RS_NO, RS_NO, RS_NO, RS_NO,RS_NO, RS_NO, RS_NO, RS_NO, RS_NO, RS_NO,RS_NO, RS_NO, RS_NO, RS_NO, RS_NO, RS_NO,RS_NO, RS_NO, RS_NO, RS_NO, RS_NO, RS_NO,RS_NO},
		{ RS_NO, RS_NO, RS_NO, RS_NO, RS_NO,RS_NO, RS_NO, RS_NO, RS_NO, RS_NO, RS_NO,RS_NO, RS_NO, RS_NO, RS_NO, RS_NO, RS_NO,RS_NO, RS_NO, RS_NO, RS_NO, RS_NO, RS_NO,RS_NO},
		{ RS_NO, RS_NO, RS_NO, RS_NO, RS_NO,RS_NO, RS_NO, RS_NO, RS_NO, RS_NO, RS_NO,RS_NO, RS_NO, RS_NO, RS_NO, RS_NO, RS_NO,RS_NO, RS_NO, RS_NO, RS_NO, RS_NO, RS_NO,RS_NO},
		{ RS_NO, RS_NO, RS_NO, RS_NO, RS_NO,RS_NO, RS_NO, RS_NO, RS_NO, RS_NO, RS_NO,RS_NO, RS_NO, RS_NO, RS_NO, RS_NO, RS_NO,RS_NO, RS_NO, RS_NO, RS_NO, RS_NO, RS_NO,RS_NO},
		{ RS_NO, RS_NO, RS_NO, RS_NO, RS_NO,RS_NO, RS_NO, RS_NO, RS_NO, RS_NO, RS_NO,RS_NO, RS_NO, RS_NO, RS_NO, RS_NO, RS_NO,RS_NO, RS_NO, RS_NO, RS_NO, RS_NO, RS_NO,RS_NO}
},
		RS_NO,
		0,
		0,	
};*/
#define RECORDDEF  {{{ RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE,RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE,RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE,RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE,RS_CONTINUE},\
	{ RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE,RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE,RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE,RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE,RS_CONTINUE},\
	{ RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE,RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE,RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE,RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE,RS_CONTINUE},\
	{ RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE,RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE,RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE,RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE,RS_CONTINUE},\
	{ RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE,RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE,RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE,RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE,RS_CONTINUE},\
	{ RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE,RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE,RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE,RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE,RS_CONTINUE},\
	{ RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE,RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE,RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE,RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE, RS_CONTINUE,RS_CONTINUE}\
	},\
		0,\
		10,\
}
#define DEFAULTDDNS	"0"
#define DEFAULTTCP	6605
#define DEFAULTVIEWCOLOR  {50,50,50,50,50}
#define DEFAULTMA {{0.0,0.0,0.99,0.99},{0.0,0.0,0.0,0.0},{0.0,0.0,0.0,0.0},{0.0,0.0,0.0,0.0} }
#define DEFAULT_ALARM { 0, 0, 0, 5 }
#define DEFAULT_IODOOR { 1, 0 }
#define DEFAULT_NOISE_LEVEL 1
#define DEFAULT_COLOR_SWITCH 1
#define DEFAULT_EXP_LEVEL 20


typedef struct {
	int res_c_1;
	int res_c_2;
	int res_c_3;
	int res_c_4;
	int res_current;
}MAIN_STREAM_T;

int start_task(pthread_t *thd,  thread_fun thd_fun, void* param);

int lockfile(int fd);
int already_running(void);
// int zs_get_cfg_int(const char *section, const char *keyname, fcfg_file_t * cfile);

void* openOSD(void*dd);

int zs_set_cfg_int( const char*section, const char* keyname, int value, char* cfg_file );
int zs_get_cfg_int(const char *section, const char *keyname, int def_val, char* cfg_file);

int sstw_get_pic_size(GV_PIC_SIZE enPicSize, SSTW_SIZE_T *pstSize);
int get_server_and_id( eliu_server_user_t * eliu_server );
int set_server_and_id( eliu_server_user_t * eliu_server );
//int get_wirless_pin();
int initFontDatabase();
HI_S32 regions_Process();
//void is_have_signal(char* data);
void set_osd2(char* osd2, int len);
int WriteGlobal(void *Buffer);

#endif

