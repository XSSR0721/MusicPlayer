/*
Program MusicPlayer;
Author 0x91f aka Lzy;
Description{
	Buzzer
}
*/

/*
================================================================//// Read Me \\\\================================================================
主文件 main.c 中需添加库：#include "MusicPlayer.h"， #include "MusicScore.h"

在主文件main.c 中的main函数中添加初始化函数和PlayMusic函数即可吗， MusicPlayer_init();， playMusic(SanranBanka,297);

主函数中的playMusic函数前的Warning不用管


注意：此处为配置一PWM波，NAME为PWM_0，输出引脚PIN 1 输出至蜂鸣器，由于单片机不同，此文件下代码会存在些许差异，但具体思路一致，可根据情况自行更改

使用方式：playMusic(音乐名,音符数);

音乐库为 MusicScore.h 文件中，MusicNote结构体定义的为音乐名，音符数为对应结构体最后一行后面注释中的数字，如《以恋结缘》名字即为SanranBanka，音符数为 297.
================================================================\\\\ Read Me ////================================================================
*/

#include "MusicPlayer.h"

void MusicPlayer_init(){
	DL_Timer_startCounter(PWM_0_INST);
	NVIC_EnableIRQ(PWM_0_INST_INT_IRQN);
	BuzzON(0,0,0);
}
void BuzzON(uint16_t Period,uint16_t CCPvalue,size_t length){
	//length_Unit: ms;
	if(length <= 0) length = 1;
	if(Period <= 0) Period = CCPvalue = 1;
	DL_Timer_setLoadValue(PWM_0_INST, Period);DL_Timer_setCaptureCompareValue(PWM_0_INST,CCPvalue,DL_TIMER_CC_1_INDEX);
	DL_Common_delayCycles(CPU_Frq * length); 
}
void BuzzOFF(size_t length){
	//Unit: ms;
	DL_Timer_setLoadValue(PWM_0_INST, 1);DL_Timer_setCaptureCompareValue(PWM_0_INST,1,DL_TIMER_CC_1_INDEX);
	DL_Common_delayCycles(CPU_Frq * length);
}

void playMusic(struct MusicNote Score[],uint16_t ScoreLength){
	for(uint16_t i = 0;i < ScoreLength;++i){
		BuzzON(Score[i].Frq,Score[i].Frq/2,Score[i].length);
		BuzzOFF(Score[i].length);
	}
}

void playSpScoreNote(struct MusicNote Score[],uint16_t ScoreLength,uint16_t from,uint16_t to){
	if(to > ScoreLength) to = ScoreLength;
	for(uint16_t i = from;i <= to;++i){
		BuzzON(Score[i].Frq,Score[i].Frq/2,Score[i].length);
		BuzzOFF(Score[i].length);
	}
}