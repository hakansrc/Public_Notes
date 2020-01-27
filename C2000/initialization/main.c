#include <F2837xD_Device.h>
#include <F2837xD_Examples.h>

/**
 * main.c
 */
int main(void)
{

    InitSysCtrl();  /*initialize the peripheral clocks*/

    InitPieCtrl();  /*initialize the PIE table (interrupt related)*/
    IER = 0x0000;   /*clear the Interrupt Enable Register   (IER)*/
    IFR = 0x0000;   /*clear the Interrupt Flag Register     (IFR)*/
    InitPieVectTable();

    EALLOW;
    CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 0;   /*stop the TimeBase clock for later synchronization*/
    CpuSysRegs.PCLKCR0.bit.GTBCLKSYNC = 0;  /*stop the global TimeBase clock for later synchronization*/
    EDIS;

    /*Initialize cpu timers*/
    InitCpuTimers();
    ConfigCpuTimer(&CpuTimer0, 200, 1000000); //1 seconds
    ConfigCpuTimer(&CpuTimer1, 200, 1000000); //1 seconds
    ConfigCpuTimer(&CpuTimer2, 200, 1000000); //1 seconds
    CpuTimer0Regs.TCR.all = 0x4000; // enable cpu timer interrupt and disable others
    CpuTimer1Regs.TCR.all = 0x4000; // enable cpu timer interrupt and disable others
    CpuTimer2Regs.TCR.all = 0x4000; // enable cpu timer interrupt and disable others

    while(1)
    {

    }
	return 0;
}
