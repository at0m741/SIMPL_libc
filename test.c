#include <stdio.h>
#include <string.h>
#include "/usr/include/stdlib.h"
#include "./src/config/cpuid_conf.h"

int main(int ac, char **av, char **env)
{
	/* char test[] = "ffffffffffffffffff"; */
	if (ac <= 1)
		return 1;
	int i = strlen(av[1]);
	i = strncmp(av[1], "qqqq", 3);
	i = strlen(av[1]);
	i = strlen(av[1]);
	i = strlen(av[1]);
	i = strncmp(av[1], "qqqq", 3);
	printf("%d\n", i);
	(void)ac;
	(void)av;
	(void)env;
	
	char *str = malloc(sizeof(char) * 10);
	memcpy(str, "qqq0", 4);
	printf("%s\n", str);
	memset(str, 0, 10);
	printf("%s\n", str);
	printf("%p\n", str);
	free(str);
	return 0;
}

