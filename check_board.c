int chk_dbl(int t[4][4], int p, int n)
{
	int i = -1;
	while (++i < p / 4)
		if (t[i][p % 4] == n)
			return (1);
	i = -1;
	while (++i < p % 4)
		if (t[p / 4][i] == n)
			return (1);
	return (0);
}

int chk_col_up(int t[4][4], int p, int e[16])
{
	int i = 0, max = 0, cnt = 0;
	if (p / 4 == 3)
	{
		while (i < 4)
		{
			if (t[i][p % 4] > max)
			{
				max = t[i][p % 4];
				cnt++;
			}
			i++;
		}
		if (e[p % 4] != cnt)
			return (1);
	}
	return (0);
}

int chk_row_right(int t[4][4], int p, int e[16])
{
	int i = 4, max = 0, vis = 0;
	if (p % 4 == 3)
	{
		while (--i >= 0)
		{
			if (t[p / 4][i] > max)
			{
				max = t[p / 4][i];
				vis++;
			}
		}
		if (e[12 + p / 4] != vis)
			return (1);
	}
	return (0);
}

int chk_col_down(int t[4][4], int p, int e[16])
{
	int i = 3, max = 0, cnt = 0;
	if (p / 4 == 3)
	{
		while (i >= 0)
		{
			if (t[i][p % 4] > max)
			{
				max = t[i][p % 4];
				cnt++;
			}
			i--;
		}
		if (e[4 + p % 4] != cnt)
			return (1);
	}
	return (0);
}

int chk_row_left(int t[4][4], int p, int e[16])
{
	int i = 0, max = 0, cnt = 0;
	if (p % 4 == 3)
	{
		while (i < 4)
		{
			if (t[p / 4][i] > max)
			{
				max = t[p / 4][i];
				cnt++;
			}
			i++;
		}
		if (e[8 + p / 4] != cnt)
			return (1);
	}
	return (0);
}

int chk_case(int t[4][4], int p, int e[16])
{
	if (chk_row_left(t, p, e) || chk_row_right(t, p, e) ||
		chk_col_down(t, p, e) || chk_col_up(t, p, e))
		return (1);
	return (0);
}
