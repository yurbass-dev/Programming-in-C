int find_bit(int bit, int position)
{
	int find = 0;
	int mask = 0x1;

	if (position < 0 || position > 31 )
	{
		puts("Позиция бита должна быть числом от 0 до 31.");
		exit(EXIT_FAILURE);
	}

	if ((bit >> position & mask) == 1)
		find = 1;

	return find;
}