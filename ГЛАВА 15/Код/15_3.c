int count_on_bits(int n)
{
	int mask = 0x1;
	int count = 0;
	const int size = CHAR_BIT * sizeof(int);

	for (int i = 0; i < size; i++, n >>= 1)
	{
		if (n & mask == 1)
			count++;
	}

	return count;
}