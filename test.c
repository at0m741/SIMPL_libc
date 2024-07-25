#include <string.h>
#include <stdio.h>
#include "/usr/include/stdlib.h"

int main(int ac, char **av, char **env)
{
	/* char test[] = "ffffffffffffffffff"; */
	if (ac <= 1)
		return 1;
	
	char *str = malloc(sizeof(char) * 10);
	printf("%s\n", str);
	memset(str, 0, 10);
	printf("%s\n", str);
	printf("%p\n", str);
	free(str);
	int i = strlen(av[1]);
	printf("%d\n", i);
	(void)ac;
	(void)av;
	(void)env;
	return 0;
}

