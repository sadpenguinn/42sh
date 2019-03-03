int		octal_to_decimal(int oct)
{
	int 	base;
	int 	tmp;
	int		dec;
	int 	ld;

	base = 1;
	dec = 0;
	tmp = oct;
	while (tmp)
	{
		ld = tmp % 10;
		tmp = tmp / 10;
		dec += ld * base;
		base = base * 8;
	}
	return (dec);
}
