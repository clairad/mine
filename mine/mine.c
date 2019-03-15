#include <stdio.h>
#include <string.h>
#include "print.h"
#include "map.h"
#include <conio.h>
#include <Windows.h>

char g_map[MAXLINE + 2][MAXROW + 2];
char g_markMap[MAXLINE + 2][MAXROW + 2];
int g_win;

int getKeyBoard()
{
	int a = _getch();
	int result = ((char)a < 0) ? (a << 8 | _getch()) : a;
	return result;
}
void(*printSence[PAGE_NUM])() = { print_start, print_set, print_exit };
void(*printSet[SET_NUM])() = { print_easy, print_mid, print_hard, print_free};
void(*printFreeSet[FREESET_NUM])(int x, int y, int m, int lim) = { print_setnumW, print_setnumH, print_setnumM };

void setFree(int *x, int *y, int *m)
{
	int flag = 0;
	int maxmine = 0;
	print_setnumW(*x, *y, *m, 0);
	while (1)
	{
		maxmine = *x * *y * 9 / 10;
		switch (getKeyBoard())
		{
		case ARROW_UP:
			flag--;
			if (flag < 0)
			{
				flag = FREESET_NUM - 1;
			}
			break;
		case ARROW_DOWN:
			flag++;
			if (flag > FREESET_NUM - 1)
			{
				flag = 0;
			}
			break;
		case ARROW_RIGHT:
			if (flag == 2)
			{
				(*m)++;
				(*m) > maxmine ? (*m)-- : (*m);
				break;
			}
			flag ? (*y)++ : (*x)++;
			(*y) > MAXROW  ? (*y)-- : (*y);
			(*x) > MAXLINE ? (*x)-- : (*x);
			break;
		case ARROW_LEFT:
			if (flag == 2)
			{
				(*m)--;
				(*m) < 10 ? (*m)++ : (*m);
				break;
			}
			flag ? (*y)-- : (*x)--;
			(*y) < MINROW  ? (*y)++ : (*y);
			(*x) < MINLINE ? (*x)++ : (*x);
			break;
		case '\r':
			return;
		default:;
		}
		printFreeSet[flag](*x, *y, *m, maxmine);
	}
}

int setPage(int *x, int *y, int *m)
{
	int flag = 0;
	print_easy();
	while (1)
	{
		switch (getKeyBoard())
		{
		case ARROW_UP:
			flag--;
			if (flag < 0)
			{
				flag = SET_NUM - 1;
			}
			break;
		case ARROW_DOWN:
			flag++;
			if (flag > SET_NUM - 1)
			{
				flag = 0;
			}
			break;
		case '\r':
			switch (flag)
			{
			case EASY:
				*x = 9;
				*y = 9;
				*m = 10;
				break;
			case MID:
				*x = 16;
				*y = 16;
				*m = 40;
				break;
			case HARD:
				*x = 16;
				*y = 24;
				*m = 99;
				break;
			case FREE:
				setFree(x, y, m);
			}
			return flag;
		default:;
		}
		printSet[flag]();
	}
}

int welcomePage()
{
	int flag = 0;
	print_start();
	while (1)
	{
		switch (getKeyBoard())
		{
		case ARROW_UP:
			flag--;
			if (flag < 0)
			{
				flag = PAGE_NUM - 1;
			}
			break;
		case ARROW_DOWN:
			flag++;
			if (flag > PAGE_NUM - 1)
			{
				flag = 0;
			}
			break;
		case '\r':
			return flag;
		default:;
		}
		printSence[flag]();
	}
}

void gameStart(int x, int y, int m)
{
	SIGN point;
	int flag = 1;
	int first = 0;
	int arrow = 0;
	int leastMine = m;

	memset(g_map, 0, sizeof(g_map));
	memset(g_markMap, 0, sizeof(g_markMap));

	point.x = DEFSIGN(x) + 1;
	point.y = DEFSIGN(y) + 1;

	g_win = x * y - m;

	printMap(x, y, flag, point, leastMine);

	while (1)
	{ 
		arrow = getKeyBoard();
		switch (arrow)
		{
		case ARROW_UP:
			point.x > 1 ? point.x-- : (point.x = x);
			flag = 1;
			break;
		case ARROW_DOWN:
			point.x < x ? point.x++ : (point.x = 1);
			flag = 1;
			break;
		case ARROW_LEFT:
			point.y > 1 ? point.y-- : (point.y = y);
			flag = 1;
			break;
		case ARROW_RIGHT:
			point.y < y ? point.y++ : (point.y = 1);
			flag = 1;
			break;
		case 'v':
			flag = 0;
			break;
		case 'l':
			printWin(x, y, leastMine);
			Sleep(100);
			break;
		case 'm':
			if (g_markMap[point.x][point.y] == DISPLAYNUM)
			{
				break;
			}

			if (g_markMap[point.x][point.y] != MARKEDMINE)
			{ 
				g_markMap[point.x][point.y] = MARKEDMINE;
				leastMine--;
			}
			else
			{
				g_markMap[point.x][point.y] = COVEREDNUM;
				leastMine++;
			}
			break;
		case ' ':
		case '\r':
			if (!first)
			{
				makeMap(x, y, m, point);
				first = 1;
				leastMine = m;
			}

			if (g_markMap[point.x][point.y] == MARKEDMINE)
			{
				break;
			}

			if (g_markMap[point.x][point.y] == DISPLAYNUM && g_map[point.x][point.y])
			{
				if (setMapNum(x, y, point))
				{ 
					printOver(x, y, leastMine);
					getchar();
					return;
				}
				break;
			}

			if (setMap(x, y, point.x, point.y))
			{
				printOver(x, y, leastMine);
				getchar();
				return;
			}
			break;
		default:;
		}

		if (g_win == 0)
		{
			printWin(x, y, leastMine);
			getchar();
			return;
		}

		printMap(x, y, flag, point, leastMine);
		flag = !flag;
	}
}

int main()
{
	int x = DEFLINE, y = DEFROW, m = DEFMINE;
	while (1)
	{
		switch (welcomePage())
		{
		case START:
			gameStart(x, y, m);
			break;
		case SET:
			setPage(&x, &y, &m);
			break;
		case EXIT:
			return 0;
		}
	}
	return 0;
}