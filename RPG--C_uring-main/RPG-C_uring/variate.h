#pragma once

//注：小写的为宏定义，主要在处理地图数据，判断移动时使用，大写的单词为全局变量，用来存储道具数量和属性信息。

//该头文件下为变量声明及宏定义

//头文件

#include <stdio.h>
#include <easyx.h>
#include <time.h>

//----------------数据设计----------------//

//地图设计
//场景
#define wall 100
#define road 101
#define door1 102
#define door2 103
#define door3 104
#define tree 105
#define river 106
#define grass 107
#define stone 108
#define flower 109
#define house 110

//道具
#define key1 200
#define key2 201
#define key3 202
#define key4 203

//怪物
#define monster1 300
#define monster2 301
#define monster3 302
#define monster4 303
#define monster5 304
#define monster6 305

//NPC
#define npc1 400
#define npc2 401
#define npc3 402
#define npc4 403
#define npc5 404

//玩家
#define CUR 9999

//----------------数据类型定义----------------//

//怪物
typedef struct monster
{
	int HP;//生命值
	int ATK;//攻击力
	int DEF;//防御力
	int EXP;//经验
}monster;

//玩家
typedef struct gamerole
{
	int x, y;//坐标
	int HP;//生命值
	int ATK;//攻击力
	int DEF;//防御力
	int INT;//蓝量
	int EXP;//经验
	int GRADE;//等级
	int DIR;//方向

}gamerole;


//全局变量声明

extern int KEY1;//蓝钥匙
extern int KEY2;//黄钥匙
extern int KEY3;//红钥匙

extern int MagicStone;//魔法水晶

extern int option;//控制界面跳转的参数

extern int location;//当前地图
extern int* MAP;
extern int MAPx;
extern int MAPy;

extern gamerole HANSER;//玩家

extern monster MONSTER1;//怪物
