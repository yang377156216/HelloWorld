/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *-pipe -fno-strict-aliasing -Wall -Wstrict-prototypes -Wmissing-prototypes -Werror-implicit-function-declaration -Wpointer-arith -std=gnu99 -ffunction-sections -fdata-sections -Wchar-subscripts -Wcomment -Wformat=2 -Wimplicit-int -Wmain -Wparentheses -Wsequence-point -Wreturn-type -Wswitch -Wtrigraphs -Wunused -Wuninitialized -Wunknown-pragmas -Wfloat-equal -Wundef -Wshadow -Wbad-function-cast -Wwrite-strings -Wsign-compare -Waggregate-return  -Wmissing-declarations -Wformat -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Wlong-long -Wunreachable-code -Wcast-align --param max-inline-insns-single=500
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
#include <hsf.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//#define __LPB100__
#ifdef __LPT100__
static int module_type= HFM_TYPE_LPT100;
const int hf_gpio_fid_to_pid_map_table[HFM_MAX_FUNC_CODE]=
{
	HF_M_PIN(2),	//HFGPIO_F_JTAG_TCK
	HF_M_PIN(3),	//HFGPIO_F_JTAG_TDO
	HF_M_PIN(4),	//HFGPIO_F_JTAG_TDI
	HF_M_PIN(5),	//HFGPIO_F_JTAG_TMS
	HFM_NOPIN,		//HFGPIO_F_USBDP
	HFM_NOPIN,		//HFGPIO_F_USBDM
	HF_M_PIN(39),	//HFGPIO_F_UART0_TX
	HF_M_PIN(40),	//HFGPIO_F_UART0_RTS
	HF_M_PIN(41),	//HFGPIO_F_UART0_RX
	HF_M_PIN(42),	//HFGPIO_F_UART0_CTS
	
	HF_M_PIN(27),	//HFGPIO_F_SPI_MISO
	HF_M_PIN(28),	//HFGPIO_F_SPI_CLK
	HF_M_PIN(29),	//HFGPIO_F_SPI_CS
	HF_M_PIN(30),	//HFGPIO_F_SPI_MOSI
	
	HFM_NOPIN,	//HFGPIO_F_UART1_TX,
	HFM_NOPIN,	//HFGPIO_F_UART1_RTS,
	HFM_NOPIN,	//HFGPIO_F_UART1_RX,
	HFM_NOPIN,	//HFGPIO_F_UART1_CTS,
	
	HF_M_PIN(11),	//HFGPIO_F_NLINK
	HF_M_PIN(12),	//HFGPIO_F_NREADY
	HF_M_PIN(45),	//HFGPIO_F_NRELOAD
	HFM_NOPIN,	//HFGPIO_F_SLEEP_RQ
	HFM_NOPIN,	//HFGPIO_F_SLEEP_ON
	
	HF_M_PIN(18),	//HFGPIO_F_WPS
	HFM_NOPIN,		//HFGPIO_F_RESERVE1
	HFM_NOPIN,		//HFGPIO_F_RESERVE2
	HFM_NOPIN,		//HFGPIO_F_RESERVE3
	HFM_NOPIN,		//HFGPIO_F_RESERVE4
	HFM_NOPIN,		//HFGPIO_F_RESERVE5
	
	HFM_NOPIN,	//HFGPIO_F_USER_DEFINE
};
#elif defined(__LPT200__)
static int module_type= HFM_TYPE_LPT200;
const int hf_gpio_fid_to_pid_map_table[HFM_MAX_FUNC_CODE]=
{
	HF_M_PIN(2),	//HFGPIO_F_JTAG_TCK
	HF_M_PIN(3),	//HFGPIO_F_JTAG_TDO
	HF_M_PIN(4),	//HFGPIO_F_JTAG_TDI
	HF_M_PIN(5),	//HFGPIO_F_JTAG_TMS
	HFM_NOPIN,		//HFGPIO_F_USBDP
	HFM_NOPIN,		//HFGPIO_F_USBDM
	HF_M_PIN(39),	//HFGPIO_F_UART0_TX
	HF_M_PIN(40),	//HFGPIO_F_UART0_RTS
	HF_M_PIN(41),	//HFGPIO_F_UART0_RX
	HF_M_PIN(42),	//HFGPIO_F_UART0_CTS
	
	HF_M_PIN(27),	//HFGPIO_F_SPI_MISO
	HF_M_PIN(28),	//HFGPIO_F_SPI_CLK
	HF_M_PIN(29),	//HFGPIO_F_SPI_CS
	HF_M_PIN(30),	//HFGPIO_F_SPI_MOSI
	
	HFM_NOPIN,	//HFGPIO_F_UART1_TX,
	HFM_NOPIN,	//HFGPIO_F_UART1_RTS,
	HFM_NOPIN,	//HFGPIO_F_UART1_RX,
	HFM_NOPIN,	//HFGPIO_F_UART1_CTS,
	
	HF_M_PIN(43),	//HFGPIO_F_NLINK
	HF_M_PIN(44),	//HFGPIO_F_NREADY
	HF_M_PIN(45),	//HFGPIO_F_NRELOAD
	HFM_NOPIN,	//HFGPIO_F_SLEEP_RQ
	HFM_NOPIN,	//HFGPIO_F_SLEEP_ON
		
	HF_M_PIN(7),		//HFGPIO_F_WPS
	HFM_NOPIN,		//HFGPIO_F_RESERVE1
	HFM_NOPIN,		//HFGPIO_F_RESERVE2
	HFM_NOPIN,		//HFGPIO_F_RESERVE3
	HFM_NOPIN,		//HFGPIO_F_RESERVE4
	HFM_NOPIN,		//HFGPIO_F_RESERVE5
	
	HFM_NOPIN,	//HFGPIO_F_USER_DEFINE
};
#elif defined(__LPB100__)
static int module_type= HFM_TYPE_LPB100;
const int hf_gpio_fid_to_pid_map_table[HFM_MAX_FUNC_CODE]=
{
	HF_M_PIN(2),	//HFGPIO_F_JTAG_TCK
	HFM_NOPIN,	//HFGPIO_F_JTAG_TDO
	HFM_NOPIN,	//HFGPIO_F_JTAG_TDI
	HF_M_PIN(5),	//HFGPIO_F_JTAG_TMS
	HFM_NOPIN,		//HFGPIO_F_USBDP
	HFM_NOPIN,		//HFGPIO_F_USBDM
	HF_M_PIN(39),	//HFGPIO_F_UART0_TX
	HF_M_PIN(40),	//HFGPIO_F_UART0_RTS
	HF_M_PIN(41),	//HFGPIO_F_UART0_RX
	HF_M_PIN(42),	//HFGPIO_F_UART0_CTS
	
	HF_M_PIN(27),	//HFGPIO_F_SPI_MISO
	HF_M_PIN(28),	//HFGPIO_F_SPI_CLK
	HF_M_PIN(29),	//HFGPIO_F_SPI_CS
	HF_M_PIN(30),	//HFGPIO_F_SPI_MOSI
	
	HFM_NOPIN,	//HFGPIO_F_UART1_TX,
	HFM_NOPIN,	//HFGPIO_F_UART1_RTS,
	HFM_NOPIN,	//HFGPIO_F_UART1_RX,
	HFM_NOPIN,	//HFGPIO_F_UART1_CTS,
	
	HF_M_PIN(43),	//HFGPIO_F_NLINK
	HF_M_PIN(44),	//HFGPIO_F_NREADY
	HF_M_PIN(45),	//HFGPIO_F_NRELOAD
	HF_M_PIN(7),	//HFGPIO_F_SLEEP_RQ
	HF_M_PIN(8),	//HFGPIO_F_SLEEP_ON
		
	HF_M_PIN(15),		//HFGPIO_F_WPS
	HFM_NOPIN,		//HFGPIO_F_RESERVE1
	HFM_NOPIN,		//HFGPIO_F_RESERVE2
	HFM_NOPIN,		//HFGPIO_F_RESERVE3
	HFM_NOPIN,		//HFGPIO_F_RESERVE4
	HFM_NOPIN,		//HFGPIO_F_RESERVE5
	
	HFM_NOPIN,	//HFGPIO_F_USER_DEFINE
};
#elif defined(__LPB100U__)
static int module_type= HFM_TYPE_LPB100;
const int hf_gpio_fid_to_pid_map_table[HFM_MAX_FUNC_CODE]=
{
	HF_M_PIN(2),	//HFGPIO_F_JTAG_TCK
	HFM_NOPIN,	//HFGPIO_F_JTAG_TDO
	HFM_NOPIN,	//HFGPIO_F_JTAG_TDI
	HF_M_PIN(5),	//HFGPIO_F_JTAG_TMS
	HFM_NOPIN,		//HFGPIO_F_USBDP
	HFM_NOPIN,		//HFGPIO_F_USBDM
	HF_M_PIN(39),	//HFGPIO_F_UART0_TX
	HFM_NOPIN,//HF_M_PIN(40),	//HFGPIO_F_UART0_RTS
	HF_M_PIN(41),	//HFGPIO_F_UART0_RX
	HFM_NOPIN,//HF_M_PIN(42),	//HFGPIO_F_UART0_CTS
	
	HFM_NOPIN,//HF_M_PIN(27),	//HFGPIO_F_SPI_MISO
	HFM_NOPIN,//HF_M_PIN(28),	//HFGPIO_F_SPI_CLK
	HFM_NOPIN,//HF_M_PIN(29),	//HFGPIO_F_SPI_CS
	HFM_NOPIN,//HF_M_PIN(30),	//HFGPIO_F_SPI_MOSI
	
	HF_M_PIN(29),	//HFGPIO_F_UART1_TX,
	HFM_NOPIN,	//HFGPIO_F_UART1_RTS,
	HF_M_PIN(30),	//HFGPIO_F_UART1_RX,
	HFM_NOPIN,	//HFGPIO_F_UART1_CTS,	
	
	HF_M_PIN(43),	//HFGPIO_F_NLINK
	HF_M_PIN(44),	//HFGPIO_F_NREADY
	HF_M_PIN(45),	//HFGPIO_F_NRELOAD
	HF_M_PIN(7),	//HFGPIO_F_SLEEP_RQ
	HF_M_PIN(8),	//HFGPIO_F_SLEEP_ON
		
	HF_M_PIN(15),		//HFGPIO_F_WPS
	HFM_NOPIN,		//HFGPIO_F_RESERVE1
	HFM_NOPIN,		//HFGPIO_F_RESERVE2
	HFM_NOPIN,		//HFGPIO_F_RESERVE3
	HFM_NOPIN,		//HFGPIO_F_RESERVE4
	HFM_NOPIN,		//HFGPIO_F_RESERVE5
	
	HFM_NOPIN,	//HFGPIO_F_USER_DEFINE
};
#else
#error "invalid project !you must define module type(__LPB100__,__LPT100__,_LPT200__)"
#endif

const hfat_cmd_t user_define_at_cmds_table[]=
{
	{NULL,NULL,NULL,NULL} //the last item must be null
};

static int USER_FUNC socketa_recv_callback(uint32_t event,char *data,uint32_t len,uint32_t buf_len)
{
	if(event==HFNET_SOCKETA_DATA_READY)
	{
		HF_Debug(DEBUG_LEVEL_LOW,"socketa recv %d bytes %d\n",len,buf_len);
	}
	else if(event==HFNET_SOCKETA_CONNECTED)
		u_printf("socket a connected!\n");
	else if(event==HFNET_SOCKETA_DISCONNECTED)
		u_printf("socket a disconnected!\n");
	
	return len;
}

static int USER_FUNC socketb_recv_callback(uint32_t event,char *data,uint32_t len,uint32_t buf_len)
{
	if(event==HFNET_SOCKETB_DATA_READY)
		HF_Debug(DEBUG_LEVEL_LOW,"socketb recv %d bytes %d\n",len,buf_len);
	else if(event==HFNET_SOCKETB_CONNECTED)
		u_printf("socket b connected!\n");
	else if(event==HFNET_SOCKETB_DISCONNECTED)
		u_printf("socket b disconnected!\n");
			
	return len;
}

static void show_reset_reason(void)
{
	uint32_t reset_reason=0;
	
	reset_reason = hfsys_get_reset_reason();
	
	
#if 1
	u_printf("reset_reasion:%08x\n",reset_reason);
#else	
	if(reset_reason&HFSYS_RESET_REASON_ERESET)
	{
		u_printf("ERESET\n");
	}
	if(reset_reason&HFSYS_RESET_REASON_IRESET0)
	{
		u_printf("IRESET0\n");
	}
	if(reset_reason&HFSYS_RESET_REASON_IRESET1)
	{
		u_printf("IRESET1\n");
	}
	if(reset_reason==HFSYS_RESET_REASON_NORMAL)
	{
		u_printf("RESET NORMAL\n");
	}
	if(reset_reason&HFSYS_RESET_REASON_WPS)
	{
		u_printf("RESET FOR WPS\n");
	}
	if(reset_reason&HFSYS_RESET_REASON_SMARTLINK_START)
	{
		u_printf("RESET FOR SMARTLINK START\n");
	}
	if(reset_reason&HFSYS_RESET_REASON_SMARTLINK_OK)
	{
		u_printf("RESET FOR SMARTLINK OK\n");
	}
	if(reset_reason&HFSYS_RESET_REASON_WPS_OK)
	{
		u_printf("RESET FOR WPS OK\n");
	}
#endif
	
	return;
}

void app_init(void)
{
	u_printf("app_init\n");
}

int USER_FUNC app_main (void)
{
	//time_t now=time(NULL);
	
	HF_Debug(DEBUG_LEVEL,"sdk version(%s),the app_main start time is %s %s\n",hfsys_get_sdk_version(),__DATE__,__TIME__);
	if(hfgpio_fmap_check(module_type)!=0)
	{
		while(1)
		{
			HF_Debug(DEBUG_ERROR,"gpio map file error\n");
			msleep(1000);
		}
		return 0;
	}
	show_reset_reason();
	
	while(!hfnet_wifi_is_active())
	{
		msleep(50);
	}
	#if 0
	int up_result=0;
	up_result = hfupdate_auto_upgrade();
	if(up_result<0)
	{
		u_printf("no entry the auto upgrade mode\n");
	}
	else if(up_result==0)
	{
		u_printf("upgrade success\n");
	}
	else
	{
		u_printf("upgrade fail %d\n",up_result);
	}
	#endif
	
	if(hfnet_start_assis(ASSIS_PORT)!=HF_SUCCESS)
	{
		HF_Debug(DEBUG_WARN,"start httpd fail\n");
	}
	
	if(hfnet_start_uart(HFTHREAD_PRIORITIES_LOW,(hfnet_callback_t)NULL)!=HF_SUCCESS)
	{
		HF_Debug(DEBUG_WARN,"start uart fail!\n");
	}
	if(hfnet_start_socketa(HFTHREAD_PRIORITIES_LOW,(hfnet_callback_t)socketa_recv_callback)!=HF_SUCCESS)
	{
		HF_Debug(DEBUG_WARN,"start socketa fail\n");
	}
	if(hfnet_start_socketb(HFTHREAD_PRIORITIES_LOW,(hfnet_callback_t)socketb_recv_callback)!=HF_SUCCESS)
	{
		HF_Debug(DEBUG_WARN,"start socketb fail\n");
	}
	if(hfnet_start_httpd(HFTHREAD_PRIORITIES_MID)!=HF_SUCCESS)
	{
		HF_Debug(DEBUG_WARN,"start httpd fail\n");
	}
	
	return 1;
}

