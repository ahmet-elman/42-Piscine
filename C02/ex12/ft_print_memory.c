#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_addr(unsigned long long addr)
{
	char	*base;
	int		i;

	base = "0123456789abcdef";
	i = 15;
	while (i >= 0)
	{
		ft_putchar(base[(addr >> (i * 4)) & 15]);
		i--;
	}
}

void	ft_print_hex(unsigned char *str, unsigned int size)
{
	char			*base;
	unsigned int	i;

	base = "0123456789abcdef";
	i = 0;
	while (i < 16)
	{
		if (i < size)
		{
			ft_putchar(base[str[i] / 16]);
			ft_putchar(base[str[i] % 16]);
		}
		else
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		if (i % 2 == 1)
			ft_putchar(' ');
		i++;
	}
}

void	ft_print_ascii(unsigned char *str, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (str[i] >= 32 && str[i] <= 126)
			ft_putchar(str[i]);
		else
			ft_putchar('.');
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)addr;
	while (i < size)
	{
		len = 16;
		if (size - i < 16)
			len = size - i;
		ft_print_addr((unsigned long long)(str + i));
		write(1, ": ", 2);
		ft_print_hex(str + i, len);
		ft_print_ascii(str + i, len);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}
/*
#include <unistd.h>

void	*ft_print_memory(void *addr, unsigned int size);

int	main(void)
{
	char	str1[] = "Bonjour les aminches\t\n\tc'est fou\ntout\nce qu on peut faire avec\n\n\n\tprint_memory\n\n\n\tlol.lol\n ";
	char	str2[] = "Hello World!";
	char	str3[] = "";
	int		nbr;

	nbr = 123456;
	write(1, "Test 1:\n", 8);
	ft_print_memory(str1, sizeof(str1));
	write(1, "\nTest 2:\n", 9);
	ft_print_memory(str2, sizeof(str2));
	write(1, "\nTest 3 (empty):\n", 17);
	ft_print_memory(str3, sizeof(str3));
	write(1, "\nTest 4 (int):\n", 15);
	ft_print_memory(&nbr, sizeof(nbr));
	return (0);
}
*/

// bu kısım (benim değil) eksik durmasın diye geçiçi olarak eklendi bir arkadaşın geri dönüşü üzerine eklendi :)