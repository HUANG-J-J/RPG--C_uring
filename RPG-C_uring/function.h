#pragma once

//该头文件下为函数声明//

#include "variate.h"

//----------------service-----------------//


/*
	负责人：杖芒
	功能：初始化游戏
		初始化全局变量
		初始化界面
		初始化地图
		初始化音乐
		……
	参数：void
	返回值：void
*/
void initGAME();

/*
	 负责人：hanser
	 功能：写入图片
		  loadimage();
		  ……
	 参数：void
	 返回值：void
*/
void loadIMG();
	
/*
	负责人：阿鹿
	功能：写入音乐 
	参数：void
	返回值：void				 	 
*/
void loadMUSIC();

/*
	负责人：杖芒
	功能：根据全局变量location加载对应的地图
		switch(location){
		case 0:
			MAP=map0;
			MAPx=map0x;
			MAPy=map0y;
			break;
		case 1:
			MAP=map1;
			MAPx=map1x;
			MAPy=map1y;
			break;
		case 2:
			......
		}

	参数：void
	返回值：void
*/
void loadMAP();

/*
	负责人：如蕤
	功能：界面跳转
		根据全局变量options来控制程序的界面跳转。
		while (1) {
			switch (options) {
			case 0:
				menu_view();
				break;
			case 1:
				beginGAME();
				break;
			case 2:
				introduction_view();
				break;
			case 3:
				setting_view();
				break;
			......
			case 999:
				exit(0);
		}
	}
	参数：void
	返回值：void
*/
void view_option(void);

/*
	负责人：暂时用简单的数值加减 hanser
	功能：计算与小怪的战斗结果
	参数：与主角战斗的小怪
	返回值：战斗成功true，无法战斗false
*/
bool fight(int monster);

/*
	负责人：hanser
	功能：判断该坐标上是什么，是否能够移动，处理移动之后的结果
		 遇到墙无法移动
		 遇到门判断是否有钥匙
		 遇到npc调用对话
		 遇到怪物调用战斗
		 遇到药水改变玩家属性
		 遇到道具获得该道具
		 遇到入口/出口改变location并重新加载地图
		 …………
	参数：目标移动位置的坐标
	返回值：成功移动true，否则false
*/
bool isMOVE(int x,int y);

/*
	负责人：暂时不用
	函数功能：控制音乐播放
	参数：void
	返回值：void
*/
void music_play();

/*
	负责人：暂无
	函数功能：读档游戏
	参数：void
	返回值：void
*/
void loadGAME();

/*
	负责人：暂无
	函数功能：存档游戏
	参数：void
	返回值：void
*/
void saveGAME();

//----------------view-----------------//

/*
	负责人：如蕤
	功能：开始游戏
		初始化游戏
		展示游戏界面
		接受玩家操作
		…………
	参数：void
	返回值：void
*/
void beginGAME();

/*
	负责人：杖芒
	功能:打开游戏菜单界面
		展示背景
			新的游戏：进入游戏界面
			商城：进入界面
			设置：进入设置界面
			排行榜：进入排行榜界面
			退出程序：exit(0)
		用户按下ws或移动鼠标调整选项
		按下enter或左键确定选项
	参数：void
	返回值：void
*/
void menu_view();

/*
	负责人：杖芒
	功能：配置游戏设置
		音量开关：控制音乐
	参数：void
	返回值：void
*/
void setting_view();

/*
	负责人：杖芒  随便写点东西
	功能：展示游戏说明
		 游戏操作
		 制作组名单
	参数：void
	返回值：void
*/
void introduction_view();

/*
	负责人：如蕤
	功能：打印游戏主界面
		 包括地图、侧边栏等等……
	参数：void
	返回值：void
*/
void game_view();

/*
	负责人：不同的NPC 不同对话 暂时不做
	功能：展示对话信息
	参数：遇到的npc/物件
	返回值：void
*/
void words_view(int npc);

/*
	负责人：如蕤 先用初版的魔塔地图
	功能：打印地图
	参数：void
	返回值：void
*/
void printMAP();

/*
	负责人：hanser
	函数功能：移动
			 若成功移动，需改变地图中的信息并重新打印地图
	参数：void
	返回值：void
*/
void MOVE();
