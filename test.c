#include "include/string.h"
#include "include/stdio.h"

int main(int ac, char **av, char **env)
{
	/* char test[] = "ffffffffffffffffff"; */
	if (ac <= 1)
		return 1;
	int i = strlen(av[1]);
	printf("%d\n", i);
	(void)ac;
	(void)av;
	(void)env;
	/* memset(test, **av, 3); */
}

