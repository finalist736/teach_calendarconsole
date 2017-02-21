#include <stdio.h>
#include <locale.h>

int DneyVMesyace(int m, int y) {
	if (m == 4 || m == 6 || m == 9 || m == 11)
	{
		return 30;
	}
	else if (m == 2)
	{
		if (y % 4 == 0 && y % 100 != 0)
		{
			return 29;
		}
		else if (y % 4 == 0 && y % 400 == 0)
		{
			return 29;
		}
		else
		{
			return 28;
		}
	}
	else
	{
		return 31;
	}
}

void PokazatZagolovokKalendarya(int m, int y) {
	switch (m) {
	case 1:
		printf("������");
		break;
	case 2:
		printf("�������");
		break;
	case 3:
		printf("����");
		break;
	case 4:
		printf("������");
		break;
	case 5:
		printf("���");
		break;
	case 6:
		printf("����");
		break;
	case 7:
		printf("����");
		break;
	case 8:
		printf("������");
		break;
	case 9:
		printf("��������");
		break;
	case 10:
		printf("�������");
		break;
	case 11:
		printf("������");
		break;
	case 12:
		printf("�������");
		break;
	}
	printf(" %d\n", y);
	printf("��  ��  ��  ��  ��  ��  ��\n");
}

void ShowCalendar(int m, int y, int start) { 
	// m - ����� ������, y - ����� ����, start - ����� ��� ������, � �������� ���������� �����
	PokazatZagolovokKalendarya(m, y);
	int d = 1;
	int daysInMonth = DneyVMesyace(m, y);
	//printf("\ndays: %d\n", daysInMonth);
	// ���������� ������ ������ ������
	for (int i = 0; i < 7; i++)
	{
		if (i < start - 1)
		{
			printf("    ");
		}
		else
		{
			printf("%d   ", d++);
		}
	}
	printf("\n");
	// ���������� ������� ������ ������
	while (d <= daysInMonth)
	{
		for (int i = 0; i < 7; i++)
		{
			printf("%d  ", d);
			if (d < 10)
			{
				printf(" ");
			}
			d++;
			// ���������� ��������� ������ ������
			if (d > daysInMonth)
			{
				break;
			}
		}
		printf("\n");
	}
	

}


int main() {
	setlocale(LC_ALL, "Russian");
	ShowCalendar(2, 2017, 3);
}