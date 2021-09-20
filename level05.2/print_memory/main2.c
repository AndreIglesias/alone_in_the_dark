#include <stddef.h>
#include <unistd.h>

void    print_memory(const void *addr, size_t size);

int	main(void)
{
	int	tab[10] = {0, 23, 150, 255, 12, 16,  42, 103};
	(void)tab;

	char str[] = "STRONG STRINGIN' STRING";
	(void)str;

	print_memory(tab, sizeof(tab));
	write(1, "\n", 1);
	print_memory(str, sizeof(str));
	return (0);
}
