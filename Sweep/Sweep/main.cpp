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
		if (MessageBox(wnd, "��Ϸʧ�ܡ�\n����һ����", "ѯ��", MB_YESNO | MB_ICONQUESTION) == IDYES)
			goto star;
		else
			exit(EXIT_SUCCESS);
	}
	if (Is_Win(map) == 1)
	{
		HWND wnd = GetHWnd();
		if (MessageBox(wnd, "��Ϸʤ����\n����һ����", "ѯ��", MB_YESNO | MB_ICONQUESTION) == IDYES)
			goto star;
		else
			exit(EXIT_SUCCESS);
	}
	system("pause");
	return 0;
}