#define _CRT_SECURE_NO_WARNINGS 1

#include"snake.h"


extern enum dir{ up, down, left, right };

int main()
{
	 Initgame();
	 initgraph(COLS*SIDE, ROWS*SIDE);
	while (1)
	{
		if (_kbhit())
		{
			changedir();
		}
		if (Is_Eatfood())
		{
			Insersnake();
		}
		Snakemove();
		if (!Is_crash())
			break;
		Displaygame();
		Sleep(100);
	}
	return 0;
}