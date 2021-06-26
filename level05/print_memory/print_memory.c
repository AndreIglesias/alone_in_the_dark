/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 21:21:42 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/26 21:58:58 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_byte(unsigned char byte)
{
	char	*lexicon = "0123456789abcdef";

	ft_putchar(lexicon[(byte / 16) % 16]);
	ft_putchar(lexicon[byte % 16]);
}

void	print_hex(const unsigned char *addr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < 16 && i < size)
	{
		print_byte(addr[i]);
		if ((i + 1) % 2 == 0)
			write(1, " ", 1);
		i++;
	}
	while (i < 16)
	{
		write(1, "  ", 2);
		if ((i + 1) % 2 == 0)
			write(1, " ", 1);
		i++;
	}
}

void	print_ascii(const unsigned char *addr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < 16 && i < size)
	{
		if (32 <= addr[i] && addr[i] <= 126)
			ft_putchar(addr[i]);
		else
			write(1, ".", 1);
		i++;
	}
}

void    print_memory(const void *addr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		print_hex(addr + i, size - i);
		print_ascii(addr + i, size - i);
		write(1, "\n", 1);
		i += 16;
	}
}

/* tests */

int     main(void)
{
        int     tab[10] = {0, 23, 150, 255,
                      12, 16,  42, 103};

        print_memory(tab, sizeof(tab));
        return (0);
}
