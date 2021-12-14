#include <stdio.h>
#include<Windows.h>
#include<conio.h>
#include "../../../OneDrive/Desktop/�˰���/Stack.h"


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
	printf("��ǰ ���� ���α׷�");
	printf("\n\n\n\n");
	gotoxy(20, 2);
	printf("ȯ���մϴ�. �̿��ڴ�, ��� �ڿ� �޴����� ���帮�ڽ��ϴ�.");
	printf("\n\n\n\n");
	Sleep(2000);
	gotoxy(4, 6);
	printf(" ---------------------------------------�޴��� ����----------------------------------------\n");
	gotoxy(4, 7);
	printf("| 1���� �����ð� ��ǰ�� ǰ���� �Է����ֽñ� �ٶ��ϴ�.                                      |\n");
	gotoxy(4, 8);
	printf("| ���� ���� �߸� �����̴ٸ� 2���� ���� ���� �����ֽø� �ǰڽ��ϴ�.                         |\n");
	gotoxy(4, 9);
	printf("| ���� �� �Է��ϼ̴ٸ�, 3���� ���� ǰ���� ���� ���� ���ֽñ� �ٶ��ϴ�.                     |\n");
	gotoxy(4, 10);
	printf("| ���ĵ� ǰ���� ���ų� ���� ������ ������ ���� �ʹٸ�, 4���� ���� Ȯ�� ���ֽñ� �ٶ��ϴ�.  |\n");
	gotoxy(4, 11);
	printf("| ���α׷��� �����Ͻð� �����ôٸ� 0���� �Է����ּ���.                                     |\n");
	gotoxy(4, 12);
	printf(" -----------------------------------------------------------------------------------------\n");
	Sleep(1000);
	system("cls");
	Sleep(1000);
	printf("\t\t\t\t\t��ǰ ���� ���α׷�\n\n\n\n");
	
	do {
		printf("\t\t\t   ���� : 1, ���� : 2, ���� : 3, ��� : 4, ���� : 0\n\n");
		printf("\t\t\t\t\t���ڸ� �Է����ּ���. : ");
		scanf_s("%d", &menu_num);
		printf("\n");
		switch (menu_num) {
		case 1:
			printf("\t\t\t\t\t��ǰ�� ǰ���� �Է����ּ���. : ");
			scanf_s("%d", &data);
			printf("\n");
			stack.push(data);
			break;
		case 2:
			data = stack.pop();
			if (data)
			{
				printf("\t\t\t\t\t -------------------------\n");
				printf("\t\t\t\t\t| ������ ������ : %d     |\n", data);
				printf("\t\t\t\t\t -------------------------\n");
			}	
			break;
		case 3:
			StackSort(stack);
			printf("\t\t\t\t\t --------------------------------\n");
			printf("\t\t\t\t\t| ���� ������ �Ϸ�Ǿ����ϴ�.    |\n");
			printf("\t\t\t\t\t --------------------------------\n");
			break;
		case 4:
			stack.printAll();
			break;
		case 0:
			return;
		default:
			printf("\t\t�߸��� �Է� �Դϴ�. ���� : 1, ���� : 2, ���� : 3, ��� : 4, ���� : 0\n");
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
	printf("�� ������ ���α׷��� ��������ּ���.");
	gotoxy(30, 16);
	printf("���α׷� ����� \"esc\"�� �����ֽñ� �ٶ��ϴ�.");
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
