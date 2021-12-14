#include <stdio.h>
#include<Windows.h>
#include<conio.h>
#include "../../../OneDrive/Desktop/알고리즘/Stack.h"


void gotoxy(int x, int y);
void CursorView();
int keyControl();
void init();
void title_screen();
void main_screen();
void StackSort(Stack<int> stack);

int main() {
	CursorView();
	init();
	while (1)
	{
		title_screen();
		int menuCode = keyControl();
		if (menuCode == 1) {
			main_screen();
		}
		if (menuCode == 3) {
			return 0;
		}
		system("cls");
	}
	return 0;
}

void gotoxy(int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void CursorView() {
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void main_screen() {
	system("cls");
	Stack<int> stack;
	stack.push(2);
	stack.push(1);
	stack.push(4);
	stack.push(6);
	stack.push(12);
	stack.push(2);
	stack.push(66);
	stack.push(7);
	stack.push(8);
	stack.push(10);
	stack.push(4);
	StackSort(stack);
	while (!stack.isEmpty()) {
		printf("%d\n", stack.pop());
	}
	while (true)
	{
		if (keyControl() == 2) {
			break;
		}
	}
}

void init() {
	system("mode con:cols=70 lines=30");
}

int keyControl() {
	char temp = _getch();

	if (temp == 'X' || temp == 'x') {
		return 1;
	}
	else if (temp == ' ') {
		return 2;
	}
	else if (temp == 27) {
		return 3;
	}
}

void title_screen() {
	printf("\n\n\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	gotoxy(10, 5);
	printf("             ######### #    \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	gotoxy(10, 6);
	printf("    ###         #      #    #####\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	gotoxy(10, 7);
	printf("   #   #      #   # ####    #\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	gotoxy(10, 8);
	printf("   #   #     #     #   #    #\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	gotoxy(10, 9);
	printf("    ###                #    #####\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	gotoxy(10, 10);
	printf("    # #        ###            #\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	gotoxy(10, 11);
	printf("    # #       #   #           #\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	gotoxy(10, 12);
	printf("   #####       ###          #####\n");
	printf("\n\n\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	gotoxy(12, 15);
	printf("\'X\'");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("를 눌러서 프로그램을 실행시켜주세요.");
	gotoxy(10, 16);
	printf("프로그램 종료는 \"esc\"를 눌러주시기 바랍니다.");
}

void StackSort(Stack<int> stack) {
	Stack<int> buffer;

	while (!stack.isEmpty()) {
		int temp = stack.pop();
		int count = 0;

		while (!buffer.isEmpty() && buffer.peak() > temp) {
			stack.push(buffer.pop());
			count++;
		}

		buffer.push(temp);

		for (int i = 0; i < count; i++) {
			buffer.push(stack.pop());
		}
	}

	while (!buffer.isEmpty()) {
		stack.push(buffer.pop());
	}
}
