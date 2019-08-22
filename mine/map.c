#include "map.h"
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

void makeMap(int x, int y, int m, SIGN point)
{
	int i, j;
	srand((unsigned)time(NULL));
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			g_map[point.x + i][point.y + j] = MINE;
		}
	}
	

	int rand_num;
	i = 0;
	while (i++ < m)
	{
		rand_num = rand() % (x * y);
		while (1)
		{ 
			if (BLANK == g_map[rand_num / y + 1][rand_num % y + 1])
			{
				g_map[rand_num / y + 1][rand_num % y + 1] = MINE;
				break;
			}
			else
			{
				rand_num++;
				if (rand_num >= x * y)
				{
					rand_num = 0;
				}
			}
		}
	}
	
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			g_map[point.x + i][point.y + j] = BLANK;
		}
	}

	for (i = 1; i <= x; i++)
	{
		for (j = 1; j <= y; j++)
		{
			if (g_map[i][j] != MINE)
			{
				g_map[i][j] = countMine(i, j);
			}

			if (g_markMap[i][j] == MARKEDMINE)
			{
				g_markMap[i][j] = COVEREDNUM;
			}
		}
	}
}

int countMine(int x, int y)
{
	int count = 0;
	int i, j;

	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			count += g_map[x + i][y + j] == MINE;
		}
	}

	return count;
}

int setMap(int x, int y, int pointx, int pointy)
{
	if (pointx < 1 || pointx > x ||
		pointy < 1 || pointy > y ||
		g_markMap[pointx][pointy] == DISPLAYNUM)
	{
		return 0;
	}

	if (g_map[pointx][pointy] == MINE)
	{
		return 1;
	}

	g_markMap[pointx][pointy] = DISPLAYNUM;
	g_win--;

	if (g_map[pointx][pointy] != 0)
	{
		return 0;
	}

	int i, j;
	for (i = pointx - 1; i <= pointx + 1; i++)
	{
		for (j = pointy - 1; j <= pointy + 1; j++)
		{
			setMap(x, y, i, j);
		}
	}

	return 0;
}

int setMapNum(int x, int y, SIGN point)
{
	int i, j, count = 0, flag = 0;
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			count += g_markMap[point.x + i][point.y + j] == MARKEDMINE;
		}
	}

	if (count == g_map[point.x][point.y])
	{
		for (i = -1; i <= 1; i++)
		{
			for (j = -1; j <= 1; j++)
			{
				if (g_markMap[point.x + i][point.y + j] == COVEREDNUM)
				{ 
					flag |= setMap(x, y, point.x + i, point.y + j);
				}
			}
		}
	}
	return flag;
}

void printHelp(char * mapsign, int y, int m)
{
	int i;
	char tmp[64] = { 0 };
	strcat(mapsign, "\n");
	for (i = 0; i < y / 2 - 4; i++)
	{
		strcat(mapsign, "　");
	}

	
	strcat(mapsign, "方向键控制 空格键确定\n");
	for (i = 0; i < y / 2 - 4; i++)
	{
		strcat(mapsign, "　");
	}
	strcat(mapsign, "v-隐藏光标 m-标记地雷\n");

	for (i = 0; i < y / 2 - 4; i++)
	{
		strcat(mapsign, "　");
	}
	sprintf(tmp, "  未标记雷数：%3d\n", m);
	strcat(mapsign, tmp);
}

void printMap(int x, int y, int flag, SIGN point, int m)
{
	int i, j;
	char mapsign[2000] = { 0 };
	char charform[][3] = { "　", "１", "２", "３", "４", "５", "６", "７", "８" };

	for (i = 0; i < y + 2; i++)
	{
		strcat(mapsign, "█");
	}

	strcat(mapsign, "\n");

	for (i = 1; i <= x; i++)
	{
		strcat(mapsign, "█");
		for (j = 1; j <= y; j++)
		{
			if (i == point.x && j == point.y && flag)
			{
				strcat(mapsign, "□");
				continue;
			}

			if (g_markMap[i][j] == COVEREDNUM)
			{ 
				strcat(mapsign, "■");
			}
			else if (g_markMap[i][j] == MARKEDMINE)
			{
				strcat(mapsign, "△");
			}
			else
			{
				if (g_map[i][j] == MINE)
				{
					strcat(mapsign, "¤");
				}
				else if (g_map[i][j] >= 0)
				{
					strcat(mapsign, charform[g_map[i][j]]);
				}
			}
		}
		strcat(mapsign, "█\n");
	}

	for (i = 0; i < y + 2; i++)
	{
		strcat(mapsign, "█");
	}

	printHelp(mapsign, y, m);

	system("cls");
	puts(mapsign);
}

void printWin(int x, int y, int m)
{
	int i, j;
	char mapsign[2000] = { 0 };
	char charform[][3] = {"　", "１", "２", "３", "４", "５", "６", "７", "８"};


	for (i = 0; i < y / 2 - 1; i++)
	{
		strcat(mapsign, "█");
	}

	strcat(mapsign, "你赢了！");

	if (y % 2)
	{
		strcat(mapsign, "！");
	}

	for (i = 0; i < y / 2 - 1; i++)
	{
		strcat(mapsign, "█");
	}

	strcat(mapsign, "\n");

	for (i = 1; i <= x; i++)
	{
		strcat(mapsign, "█");
		for (j = 1; j <= y; j++)
		{
			if (g_map[i][j] == MINE && g_markMap[i][j] == MARKEDMINE)
			{
				strcat(mapsign, "△");
			}
			else if (g_map[i][j] == MINE)
			{
				strcat(mapsign, "¤");
			}
			else if(g_map[i][j] >= 0)
			{
				strcat(mapsign, charform[g_map[i][j]]);
			}
		}
		strcat(mapsign, "█\n");
	}

	for (i = 0; i < y / 2 - 2; i++)
	{
		strcat(mapsign, "█");
	}

	strcat(mapsign, "按回车键继续");

	if (y % 2)
	{
		strcat(mapsign, "！");
	}

	for (i = 0; i < y / 2 - 2; i++)
	{
		strcat(mapsign, "█");
	}

	printHelp(mapsign, y, m);

	system("cls");
	puts(mapsign);
	
}

void printOver(int x, int y, int m)
{
	int i, j;
	char mapsign[2000] = { 0 };
	char charform[][3] = { "　", "１", "２", "３", "４", "５", "６", "７", "８" };

	for (i = 0; i < y / 2 - 1; i++)
	{
		strcat(mapsign, "█");
	}

	strcat(mapsign, "你输了…");

	if (y % 2)
	{
		strcat(mapsign, "…");
	}

	for (i = 0; i < y / 2 - 1; i++)
	{
		strcat(mapsign, "█");
	}

	strcat(mapsign, "\n");

	for (i = 1; i <= x; i++)
	{
		strcat(mapsign, "█");
		for (j = 1; j <= y; j++)
		{
			if (g_markMap[i][j] == COVEREDNUM && g_map[i][j] != MINE)
			{
				strcat(mapsign, "■");
			}
			else if (g_markMap[i][j] == MARKEDMINE && g_map[i][j] == MINE)
			{
				strcat(mapsign, "△");
			}
			else if (g_markMap[i][j] == MARKEDMINE && g_map[i][j] != MINE)
			{
				strcat(mapsign, "×");
			}
			else
			{
				if (g_map[i][j] == MINE)
				{
					strcat(mapsign, "¤");
				}
				else if (g_map[i][j] >= 0)
				{
					strcat(mapsign, charform[g_map[i][j]]);
				}
			}
		}
		strcat(mapsign, "█\n");
	}

	for (i = 0; i < y / 2 - 2; i++)
	{
		strcat(mapsign, "█");
	}

	strcat(mapsign, "按回车键继续");

	if (y % 2)
	{
		strcat(mapsign, "！");
	}

	for (i = 0; i < y / 2 - 2; i++)
	{
		strcat(mapsign, "█");
	}

	printHelp(mapsign, y, m);

	system("cls");
	puts(mapsign);
}