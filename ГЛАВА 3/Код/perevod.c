// Программа для отображения символа ASCII кода в десятичном, восьмеричном и шестнадцатеричном формате.
#include <stdio.h>

int main(void)
{
	char symbol;
	printf("Введите символ: \n");
	scanf("%c", &symbol);
	printf("Ваш символ в:\n десятичном виде: %d,\n восьмеричном: %#o,\n шестнадцатеричном: %#x.\n", symbol, symbol, symbol);

	return 0;
}