#include <stdio.h>
#include <stdlib.h>
/*
	多档输出DC电源的控制部分电阻计算
	基础阻值为390K，为1W档位
	其他的调档电阻和390K并联。
*/
#if 0
#define BASE	240	// 第一档电阻值
#define RBASE	2	// 取样电阻阻值。1-R100  2-R200
int main(int argc,char* argv[])
{
	int i;
	float dc;
	dc = 4990 * 50 / (BASE + 10) / R_BASE;	
	printf("R_base = %d BASE Resistor = %d \t DC = %f\n",R_BASE,BASE,dc);
	
	for(i = 51;i < 2000;i++)
	{
		dc = 4990 * 50 / (BASE * i /(BASE + i) + 10) / R_BASE;
		printf("R = %d \t DC = %f\n",i,dc);
	}

	return 0;	
}

#else

#define BASE	(150)		//第一档电阻值
#define	R_FEED	(0.2)		//取样电阻 0.2 -- R200  0.1 -- R100

#define R_START	(51)		//51KOhm
#define R_END	(1000)		//1000KOhm

#define	V_431	(2495)		// TL431电压值mV
#define	R_GET	(10)		// 10K分压电阻

int main(int argc,char* argv[])
{
	double i,dc,R_comp;
	int j;
	i = V_431 * R_GET / R_FEED / (BASE + R_GET);
	printf("R base = %d KOhn,R feed = %f Ohm,I = %f A\n",BASE,R_FEED,i);
	
	for(j = R_START;j <= R_END;j++)
	{
		R_comp = BASE * j / (BASE + j);
		i = V_431 * R_GET / R_FEED / (R_comp + R_GET);
		printf("R = %d KOhm,I = %f mA\n",j,i);
	}
	printf("\n");
	
}
#endif
