#include "print.h"
#include <string.h>

void print_start()
{
	char p[512] = { 0 };
	strcat(p, "██████████████████\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　 扫      雷 　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　◆ Game Start 　　　　　█\n");
	strcat(p, "█　　　　　  Game Set　　　　　　█\n");
	strcat(p, "█　　　　　　  Exit　　　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "██████████████████\n");
	strcat(p, "　　　 方向键选择　回车键确认\n");
	strcat(p, "　　　　　　 开始游戏\n");
	system("cls");
	puts(p);
}

void print_set()
{
	char p[512] = { 0 };
	strcat(p, "██████████████████\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　 扫      雷 　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　 Game Start 　　　　　█\n");
	strcat(p, "█　　　　◆  Game Set　　　　　　█\n");
	strcat(p, "█　　　　　　  Exit　　　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "██████████████████\n");
	strcat(p, "　　 　方向键选择　回车键确认\n");
	strcat(p, "　　　　 　设置地图大小\n");
	system("cls");
	puts(p);
}

void print_exit()
{
	char p[512] = { 0 };
	strcat(p, "██████████████████\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　 扫      雷 　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　 Game Start 　　　　　█\n");
	strcat(p, "█　　　　　  Game Set　　　　　　█\n");
	strcat(p, "█　　　　◆　  Exit　　　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "██████████████████\n");
	strcat(p, "　　 　方向键选择　回车键确认\n");
	strcat(p, "　　　　　　 退出游戏\n");
	system("cls");
	puts(p);
}

void print_easy()
{
	char p[512] = { 0 };
	strcat(p, "██████████████████\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　 扫      雷 　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　◆　初　　级　　　　　　█\n");
	strcat(p, "█　　　　　　中　　级　　　　　　█\n");
	strcat(p, "█　　　　　  高　　级　　　　　　█\n");
	strcat(p, "█　　　　　　自 定 义　　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "██████████████████\n");
	strcat(p, "　　　 方向键选择　回车键确认\n");
	strcat(p, "　　　　　 　退出游戏\n");
	system("cls");
	puts(p);
}

void print_mid()
{
	char p[512] = { 0 };
	strcat(p, "██████████████████\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　 扫      雷 　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　　初　　级　　　　　　█\n");
	strcat(p, "█　　　　◆　中　　级　　　　　　█\n");
	strcat(p, "█　　　　　  高　　级　　　　　　█\n");
	strcat(p, "█　　　　　　自 定 义　　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "██████████████████\n");
	strcat(p, "　　　 方向键选择　回车键确认\n");
	strcat(p, "　　　　　　 退出游戏\n");
	system("cls");
	puts(p);
}

void print_hard()
{
	char p[512] = { 0 };
	strcat(p, "██████████████████\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　 扫      雷 　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　　初　　级　　　　　　█\n");
	strcat(p, "█　　　　　　中　　级　　　　　　█\n");
	strcat(p, "█　　　　◆  高　　级　　　　　　█\n");
	strcat(p, "█　　　　　　自 定 义　　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "██████████████████\n");
	strcat(p, "　　　 方向键选择　回车键确认\n");
	strcat(p, "　　　　　　 退出游戏\n");
	system("cls");
	puts(p);
}

void print_free()
{
	char p[512] = { 0 };
	strcat(p, "██████████████████\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　 扫      雷 　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　　初　　级　　　　　　█\n");
	strcat(p, "█　　　　　　中　　级　　　　　　█\n");
	strcat(p, "█　　　　　  高　　级　　　　　　█\n");
	strcat(p, "█　　　　◆　自 定 义　　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "██████████████████\n");
	strcat(p, "　　　 方向键选择　回车键确认\n");
	strcat(p, "　　　　　　 退出游戏\n");
	system("cls");
	puts(p);
}

void print_setnumW(int x, int y, int z, int rev)
{
	char p[512] = { 0 };
	strcat(p, "██████████████████\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　 扫      雷 　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　◆高  度： %2d 　　　　　█\n");
	strcat(p, "█　　　　　宽  度： %2d　　 　　　█\n");
	strcat(p, "█　　　    雷  数：%3d     　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "██████████████████\n");
	strcat(p, "　　　 方向键选择　回车键确认\n");
	strcat(p, "　　　  设置高度（范围9-24）\n");
	system("cls");
	printf(p, x, y, z);
}

void print_setnumH(int x, int y, int z, int rev)
{
	char p[512] = { 0 };
	strcat(p, "██████████████████\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　 扫      雷 　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　  高  度： %2d 　　　　　█\n");
	strcat(p, "█　　　　◆宽  度： %2d　　 　　　█\n");
	strcat(p, "█　　　    雷  数：%3d     　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "██████████████████\n");
	strcat(p, "　　　 方向键选择　回车键确认\n");
	strcat(p, "　　　  设置宽度（范围9-30）\n");
	system("cls");
	printf(p, x, y, z);
}

void print_setnumM(int x, int y, int z, int lim)
{
	char p[512] = { 0 };
	strcat(p, "██████████████████\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　 扫      雷 　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "█　　　　  高  度： %2d 　　　　　█\n");
	strcat(p, "█　　　　  宽  度： %2d　　 　　　█\n");
	strcat(p, "█　　　  ◆雷  数：%3d     　　　█\n");
	strcat(p, "█　　　　　　　　　　　　　　　　█\n");
	strcat(p, "██████████████████\n");
	strcat(p, "　　　 方向键选择　回车键确认\n");
	strcat(p, "　　　  设置雷数（范围10-%d）\n");
	system("cls");
	printf(p, x, y, z, lim);
}
