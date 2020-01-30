#include <stdio.h>
#include <stdlib.h>

void show_menu(const struct font *pst);
int get_num(int limit);
void clear_string(void);

struct font
{
	unsigned int id_font 	: 8;
	unsigned int size_font  : 7;
	unsigned int 			: 1;
	unsigned int alignment  : 2;
	unsigned int 			: 6;
	unsigned int bold     	: 1;
	unsigned int italic     : 1;
	unsigned int underline 	: 1;
	unsigned int 			: 3;
};

int main(void)
{
	struct font font_type = { 0 };
	unsigned char choice;
	unsigned int num;

	show_menu(&font_type);
	while ((choice = getchar()) && choice != 'q')
	{
		clear_string();
		switch (choice)
		{
			case 'f': 
				printf("Введите идентификатор шрифта (0 - 255): ");
				font_type.id_font = get_num(255);
				break;
			case 's':
				printf("Введите размер шрифта (0 - 127): ");
				font_type.size_font = get_num(127);
				break;
			case 'a':
				printf("Введите число для выбора выравнивания (0 - влево, 1 - по центру, 2 - вправо): ");
				font_type.alignment = get_num(2);
				break;
			case 'b':
				printf("Для включения полужирного шрифта введите - 1, для отключения - 0: ");
				font_type.bold = get_num(1);
				break;
			case 'i':
				printf("Для включения курсивного шрифта введите - 1, для отключения - 0: ");
				font_type.italic = get_num(1);
				break;	
			case 'u':
				printf("Для включения подчеркнутого шрифта введите - 1, для отключения - 0: ");
				font_type.underline = get_num(1);
				break;
			default :
				printf("Для выбора введите одну букву из 'fsabiuq':");
				continue;

		}
		show_menu(&font_type);
	}
	puts("Программа завершена!");

	return 0;
}

void show_menu(const struct font *pst)
{
	printf("%s %17s %29s %7s %7s %7s\n", "ИД", "РАЗМЕР", "ВЫРАВНИВАНИЕ", "Ж", "К", "Ч");
	printf("%d %9d %22s %15s %10s %10s\n\n", pst->id_font, pst->size_font, 
			pst->alignment == 0 ? "влево" : (pst->alignment == 1 ? "по центру" : "вправо"),
			pst->bold == 0 ? "откл." : "вкл.", 
			pst->italic == 0 ? "откл." : "вкл.",
			pst->underline == 0 ? "откл." : "вкл.");
	puts("f) изменить шрифт   s) изменить размер   a) изменить выравнивание");
	puts("b) полужирный       i) курсив            u) подчеркнутый");
	puts("q) завершить");
}

int get_num(int limit)
{
	int num;
	bool check = true;

	while (check && scanf("%d", &num))
	{
		clear_string();
		if (num < 0 || num > limit)
		{
			printf("Введите число от 0 до %d: ", limit);
			check = true;
			continue;
		}
		check = false;
	}

	return num;
}

void clear_string(void)
{
	while (getchar() != '\n')
		continue;
}
