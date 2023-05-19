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
	#include <stdio.h>

int calculateDamage(int attack, int defense) {
	// 根据攻击力和防御力计算伤害值
	int damage = attack - defense;
	if (damage < 0) {
		damage = 0;  // 确保伤害不会为负数
	}
	return damage;
}

int main() {
	int playerAttack = 20;   // 玩家的攻击力
	int playerDefense = 10;  // 玩家的防御力
	int playerHealth = 100;  // 玩家的血量

	int monsterAttack = 15;   // 怪物的攻击力
	int monsterDefense = 5;   // 怪物的防御力
	int monsterHealth = 80;   // 怪物的血量
	上面部分后续接入端口就好，这里是为了方便测试

	while (playerHealth > 0 && monsterHealth > 0) {
		// 玩家攻击怪物
		int playerDamage = calculateDamage(playerAttack, monsterDefense);
		monsterHealth -= playerDamage;
		printf("玩家对怪物造成了 %d 点伤害。\n", playerDamage);

		// 检查怪物是否被击败
		if (monsterHealth <= 0) {
			printf("战斗成功！\n");
			break;
		}

		// 怪物攻击玩家
		int monsterDamage = calculateDamage(monsterAttack, playerDefense);
		playerHealth -= monsterDamage;
		printf("怪物对玩家造成了 %d 点伤害。\n", monsterDamage);

		// 检查玩家是否被击败
		if (playerHealth <= 0) {
			printf("战斗失败！\n");
			break;
		}
	}

	return 0;
}

以下为boss攻击模块
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <graphics.h>

// 定义窗口大小（弹窗）
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

// 定义玩家和Boss的初始血量
int playerHealth = 100;
int bossHealth = 200;

// 定义玩家的攻击力
int playerAttack = 20;

// 定义Boss的攻击力和技能冷却时间
int bossAttack = 30;
int bossSkillCooldown = 3;
int bossSkillCounter = 0;

// 定义技能函数，待实现具体的技能效果
void useSkill() {
	// 在这里实现技能的效果
	printf("玩家使用了技能！\n");
}

// 定义普通攻击函数
void attackBoss() {
	// 计算玩家对Boss造成的伤害
	int damage = playerAttack;
	bossHealth -= damage;
	printf("玩家对Boss造成了 %d 点伤害。\n", damage);
}

// 定义Boss的技能函数，待实现具体的技能效果
void bossSkill() {
	// 在这里实现Boss技能的效果
	printf("Boss使用了技能！\n");
}

// 绘制游戏界面
void drawGameScreen() {
	settextcolor(WHITE);

	char playerHealthText[20];
	sprintf(playerHealthText, "玩家血量：%d", playerHealth);
	outtextxy(20, 20, playerHealthText);

	char bossHealthText[20];
	sprintf(bossHealthText, "Boss血量：%d", bossHealth);
	outtextxy(20, 50, bossHealthText);

	outtextxy(20, 80, "请点击图片选择行动：");
	outtextxy(20, 120, "1. 普通攻击");
	outtextxy(20, 150, "2. 使用技能");
}

// 处理鼠标点击事件
void handleMouseClick() {
	MOUSEMSG mouseMsg;
	while (1) {
		mouseMsg = GetMouseMsg();
		if (mouseMsg.uMsg == WM_LBUTTONDOWN) {
			if (mouseMsg.x >= 20 && mouseMsg.x <= 120 && mouseMsg.y >= 120 && mouseMsg.y <= 160) {
				// 点击了普通攻击图片
				attackBoss();
				break;
			} else if (mouseMsg.x >= 20 && mouseMsg.x <= 120 && mouseMsg.y >= 150 && mouseMsg.y <= 190) {
				// 点击了使用技能图片
				useSkill();
				break;
			}
		}
	}
}

// 玩家回合
void playerTurn() {
	drawGameScreen();
	handleMouseClick();
}

// Boss回合
void bossTurn() {
	if (bossSkillCounter == 0) {
		bossSkill();
		bossSkillCounter = bossSkillCooldown;
	} else {
		// Boss进行普通攻击
		int damage = bossAttack;
		playerHealth -= damage;
		printf("Boss对玩家造成了 %d 点伤害。\n", damage);
		bossSkillCounter--;
	}
}

// 检查游戏是否结束
bool isGameOver() {
	if (playerHealth <= 0) {
		printf("玩家战败，游戏结束！\n");
		return true;
	} else if (bossHealth <= 0) {
		printf("玩家战胜Boss，游戏结束！\n");
		return true;
	}
	return false;
}

int main() {
	// 初始化窗口
	initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);

	// 设置窗口标题
	setcaption("Undertale Battle");

	// 设置字体大小
	settextstyle(20, 0, "微软雅黑");

	printf("玩家血量：%d\n", playerHealth);
	printf("Boss血量：%d\n", bossHealth);

	while (!isGameOver()) {
		playerTurn();
		if (isGameOver()) {
			break;
		}
		bossTurn();
	}

	// 关闭窗口
	——getch();
	closegraph();

	return 0;
}


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
