#include "stm32f10x.h"                  // Device header

//void Timer6_Init(void)
//{
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);//打开提tim2的时钟
////RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//打开提gpio的时钟
//	
//	
////	//gpioa初始化结构体
////	/*********************************/
////	GPIO_InitTypeDef GPIO_InitStructure;
////	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
////	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
////	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
////	GPIO_Init(GPIOA, &GPIO_InitStructure);
////	/****************************/
//	TIM_InternalClockConfig(TIM6);
//	
//	
//	//初始化时基单元
//	/*****************************/
//	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
//	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
//	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;//向上计数
//	TIM_TimeBaseInitStructure.TIM_Period = 100 - 1;		//ARR目标
//	TIM_TimeBaseInitStructure.TIM_Prescaler = 36 - 1;		//PSC分频
//	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;//高级定时器的功能
//	TIM_TimeBaseInit(TIM6, &TIM_TimeBaseInitStructure);
//	/***********************************/
//	
//	//初始化捕获
////	/***************************************/
////	TIM_OCInitTypeDef TIM_OCInitStructure;
////	TIM_OCStructInit(&TIM_OCInitStructure);
////	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;//pwm模式1
////	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;//极
////	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;//使能
////	TIM_OCInitStructure.TIM_Pulse = 0;		//CCR
////	TIM_OC3Init(TIM2, &TIM_OCInitStructure);
////	/*********************/
//	//TIM_Cmd(TIM2, ENABLE);//使能
//}

////void PWM_SetCompare3(uint16_t Compare)
////{
////	TIM_SetCompare3(TIM2, Compare);
////}











void Timer6_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);
	
	TIM_InternalClockConfig(TIM6);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = 100-1;
	TIM_TimeBaseInitStructure.TIM_Prescaler = 36-1;
	//TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM6, &TIM_TimeBaseInitStructure);
	
	TIM_ClearFlag(TIM6, TIM_FLAG_Update);
	TIM_ITConfig(TIM6, TIM_IT_Update, ENABLE);
	
	//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);/////////////////NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM6_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_InitStructure);
	
//TIM_Cmd(TIM6, ENABLE);  
}




//void Timer6_Init()
//{
//TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
//	NVIC_InitTypeDef NVIC_InitStructure;

//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE); //时钟使能

//	TIM_TimeBaseStructure.TIM_Period = 5000; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	 计数到5000为500ms
//	TIM_TimeBaseStructure.TIM_Prescaler =7200-1; //设置用来作为TIMx时钟频率除数的预分频值  10Khz的计数频率  
//	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
//	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
// 
//	TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE ); //使能指定的TIM3中断,允许更新中断

//	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;  //TIM3中断
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //先占优先级0级
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //从优先级3级
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
//	NVIC_Init(&NVIC_InitStructure);  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器

//	TIM_Cmd(TIM4, ENABLE);  //使能TIMx外设//}
//}





//void PWM_Init(void)
//{
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);//打开提tim2的时钟
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);//打开提gpio的时钟
//	
//	
//	//gpioa初始化结构体
//	/*********************************/
//	GPIO_InitTypeDef GPIO_InitStructure;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOB, &GPIO_InitStructure);
//	/****************************/
//	TIM_InternalClockConfig(TIM4);
//	
//	
//	//初始化时基单元
//	/*****************************/
//	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
//	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
//	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;//向上计数
//	TIM_TimeBaseInitStructure.TIM_Period = 100 - 1;		//ARR目标
//	TIM_TimeBaseInitStructure.TIM_Prescaler = 36 - 1;		//PSC分频
//	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;//高级定时器的功能
//	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
//	/***********************************/
//	
//	//初始化捕获
//	/***************************************/
//	TIM_OCInitTypeDef TIM_OCInitStructure;
//	TIM_OCStructInit(&TIM_OCInitStructure);
//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;//pwm模式1
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;//极
//	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;//使能
//	TIM_OCInitStructure.TIM_Pulse = 0;		//CCR
//	TIM_OC3Init(TIM2, &TIM_OCInitStructure);
//	/*********************/
//	TIM_Cmd(TIM2, ENABLE);//使能
//}

//void PWM_SetCompare3(uint16_t Compare)
//{
//	TIM_SetCompare3(TIM2, Compare);
//}
