/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 18:15:27 by ciglesia          #+#    #+#             */
/*   Updated: 2021/09/20 18:40:13 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>

void	phex(int x)
{
	char *l = "0123456789abcdef";

	write(1, &l[(x / 16) % 16], 1);
	write(1, &l[x % 16], 1);
}

void	print_hex(const unsigned char *mem, size_t size)
{
	size_t i = 0;

	for (; i < size && i < 16; i++)
	{
		phex(mem[i]);
		if (i && i % 2 != 0)
			write(1, " ", 1);
	}
	while (i < 16)
	{
		write(1, "  ", 2);
		if (i && i % 2 != 0)
			write(1, " ", 1);
		i++;
	}
}

void	print_ascii(const unsigned char *mem, size_t size)
{
	for (size_t i = 0; i < size && i < 16; i++)
	{
		if (32 <= mem[i] && mem[i] <= 126)
			write(1, &mem[i], 1);
		else
			write(1, ".", 1);
	}
}

void	print_memory(const void *addr, size_t size)
{
	for (size_t i = 0; i < size; i += 16)
	{
		print_hex(addr + i, size - i);
		print_ascii(addr + i, size - i);
		write(1, "\n", 1);
	}
}
