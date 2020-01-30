unsigned int rotate_bits(unsigned int num, int bits)
{
	unsigned int result;
	unsigned int higher_bits;

	if (bits < 0 || bits > 32)
	{
		puts("Число позиций сдвига должно быть от 0 до 32.\n");
		exit(EXIT_FAILURE);
	}
	higher_bits = num >> (32 - bits);			// сохраняем старшие биты, которые будем перемещать в младшие
	result = num << bits;						// делаем сдвиг влево на число битов
	result |= higher_bits;						// переносим сохраненные старшие биты в младшие (которые пустые)

	return result;
}