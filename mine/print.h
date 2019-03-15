#ifndef _PRINT_H_
#define _PRINT_H_

#define PAGE_NUM 3
#define SET_NUM 4
#define FREESET_NUM 3
enum
{
	START = 0,
	SET,
	EXIT,
};

void print_start();
void print_set();
void print_exit();

enum{
	EASY, MID, HARD, FREE
};
void print_easy();
void print_mid();
void print_hard();
void print_free();

void print_setnumW(int x, int y, int m, int rev);
void print_setnumH(int x, int y, int m, int rev);
void print_setnumM(int x, int y, int m, int lim);

void print_win(int score);
void print_over(int score);

#endif //_PRINT_H_