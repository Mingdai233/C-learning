#define _CRT_SECURE_NO_WARNINGS 1
#include"Sweep.h"

int main()
{
	star:
	int** map=Initgame();
	Display(map);
	game(map);
	if (Is_Win(map) == -1)
	{
		HWND wnd = GetHWnd();
		if (MessageBox(wnd, "游戏失败。\n重来一局吗？", "询问", MB_YESNO | MB_ICONQUESTION) == IDYES)
			goto star;
		else
			exit(EXIT_SUCCESS);
	}
	if (Is_Win(map) == 1)
	{
		HWND wnd = GetHWnd();
		if (MessageBox(wnd, "游戏胜利。\n重来一局吗？", "询问", MB_YESNO | MB_ICONQUESTION) == IDYES)
			goto star;
		else
			exit(EXIT_SUCCESS);
	}
	system("pause");
	return 0;
}