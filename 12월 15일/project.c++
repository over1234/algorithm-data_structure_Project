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
	int menu_num = 0;
	int data;
	gotoxy(40, 0);
	printf("물품 정렬 프로그램");
	printf("\n\n\n\n");
	gotoxy(20, 2);
	printf("환영합니다. 이용자님, 잠시 뒤에 메뉴얼을 띄어드리겠습니다.");
	printf("\n\n\n\n");
	Sleep(2000);
	gotoxy(4, 6);
	printf(" ---------------------------------------메뉴얼 열람----------------------------------------\n");
	gotoxy(4, 7);
	printf("| 1번을 누르시고 물품의 품번을 입력해주시기 바랍니다.                                      |\n");
	gotoxy(4, 8);
	printf("| 만약 값을 잘못 넣으셨다면 2번을 눌러 값을 지워주시면 되겠습니다.                         |\n");
	gotoxy(4, 9);
	printf("| 값을 다 입력하셨다면, 3번을 눌러 품번의 정렬 진행 해주시기 바랍니다.                     |\n");
	gotoxy(4, 10);
	printf("| 정렬된 품번을 보거나 물건 개수를 검토해 보고 싶다면, 4번을 눌러 확인 해주시기 바랍니다.  |\n");
	gotoxy(4, 11);
	printf("| 프로그램을 종료하시고 싶으시다면 0번을 입력해주세요.                                     |\n");
	gotoxy(4, 12);
	printf(" -----------------------------------------------------------------------------------------\n");
	Sleep(1000);
	system("cls");
	Sleep(1000);
	printf("\t\t\t\t\t물품 정렬 프로그램\n\n\n\n");
	
	do {
		printf("\t\t\t   삽입 : 1, 제거 : 2, 정렬 : 3, 출력 : 4, 종료 : 0\n\n");
		printf("\t\t\t\t\t숫자를 입력해주세요. : ");
		scanf_s("%d", &menu_num);
		printf("\n");
		switch (menu_num) {
		case 1:
			printf("\t\t\t\t\t물품의 품번을 입력해주세요. : ");
			scanf_s("%d", &data);
			printf("\n");
			stack.push(data);
			break;
		case 2:
			data = stack.pop();
			if (data)
			{
				printf("\t\t\t\t\t -------------------------\n");
				printf("\t\t\t\t\t| 삭제된 데이터 : %d     |\n", data);
				printf("\t\t\t\t\t -------------------------\n");
			}	
			break;
		case 3:
			StackSort(stack);
			printf("\t\t\t\t\t --------------------------------\n");
			printf("\t\t\t\t\t| 스택 정렬이 완료되었습니다.    |\n");
			printf("\t\t\t\t\t --------------------------------\n");
			break;
		case 4:
			stack.printAll();
			break;
		case 0:
			return;
		default:
			printf("\t\t잘못된 입력 입니다. 삽입 : 1, 제거 : 2, 정렬 : 3, 출력 : 4, 종료 : 0\n");
			break;
		}
	} while (menu_num);
	while (true)
	{
		if (keyControl() == 2) {
			break;
		}
	}
}

void init() {
	system("mode con:cols=100 lines=30");
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
	gotoxy(38, 5);
	printf("     #    ######   #####\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	gotoxy(38, 6);
	printf("    # #   #     #  #    #\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	gotoxy(38, 7);
	printf("   #   #  #     #  #    #\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	gotoxy(38, 8);
	printf("   #####  #     #  #####\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	gotoxy(38, 9);
	printf("   #   #  #     #  #\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	gotoxy(38, 10);
	printf("   #   #  ######   #\n");
	printf("\n\n\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	gotoxy(32, 15);
	printf("\'X\'");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("를 눌러서 프로그램을 실행시켜주세요.");
	gotoxy(30, 16);
	printf("프로그램 종료는 \"esc\"를 눌러주시기 바랍니다.");
}

void StackSort(Stack<int> stack) {
	Stack<int> buffer;

	while (!stack.isEmpty()) {
		int temp = stack.pop();
		int count = 0;

		while (!buffer.isEmpty() && buffer.peak() < temp) {
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
