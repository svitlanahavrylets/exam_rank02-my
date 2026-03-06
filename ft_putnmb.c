# include <unistd.h>

void	ft_putnmb(int nmb)
{
	long	n;
	char	res;

	n = nmb;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnmb(n / 10);
	res = n % 10 + '0';
	write(1, &res, 1);
}

int	main(void)
{
	ft_putnmb(0);
		write(1, "\n", 1);
	ft_putnmb(-2147483648);
		write(1, "\n", 1);
	ft_putnmb(2147483647);
		write(1, "\n", 1);
	ft_putnmb(1);
		write(1, "\n", 1);
	ft_putnmb(-1);
		write(1, "\n", 1);
	ft_putnmb(11);
		write(1, "\n", 1);
	ft_putnmb(8);
		write(1, "\n", 1);
	return (0);
}