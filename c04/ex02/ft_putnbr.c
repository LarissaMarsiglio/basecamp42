#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	cont;
	char			vet[10];

	cont = 0;
	if (nb == 0)
		ft_putchar('0');
	if (nb < 0 && nb != -2147483648)
	{
		write(1, "-", 1);
		nb = nb * (-1);
	}
	else if (nb == -2147483648)
		write (1, "-2147483648", 11);

	while (nb > 0)
	{
		vet[cont] = (nb % 10) + '0';
		nb = nb / 10;
		cont++;
	}
	while (cont >= 0)
	{
		write(1, &vet[cont], 1);
		cont--;
	}
}
