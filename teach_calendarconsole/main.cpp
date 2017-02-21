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
		printf("январь");
		break;
	case 2:
		printf("‘евраль");
		break;
	case 3:
		printf("ћарт");
		break;
	case 4:
		printf("јпрель");
		break;
	case 5:
		printf("ћай");
		break;
	case 6:
		printf("»юнь");
		break;
	case 7:
		printf("»юль");
		break;
	case 8:
		printf("јвгуст");
		break;
	case 9:
		printf("—ент€брь");
		break;
	case 10:
		printf("ќкт€брь");
		break;
	case 11:
		printf("Ќо€брь");
		break;
	case 12:
		printf("ƒекабрь");
		break;
	}
	printf(" %d\n", y);
	printf("ѕн  ¬т  —р  „т  ѕт  —б  ¬с\n");
}

void ShowCalendar(int m, int y, int start) { 
	// m - номер мес€ца, y - номер года, start - номер дн€ недели, с которого начинаетс€ мес€ц
	PokazatZagolovokKalendarya(m, y);
	int d = 1;
	int daysInMonth = DneyVMesyace(m, y);
	//printf("\ndays: %d\n", daysInMonth);
	// показываем первую неделю мес€ца
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
	// показываем средние недели мес€ца
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
			// показываем последнюю неделю мес€ца
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