#include "include/string.h"
#include <stdio.h>

int main(int ac, char **av, char **env)
{
	printf("%d\n", strlen("Test"));
	printf("%d\n", strlen("Test"));
	(void)ac;
	(void)av;
	(void)env;

}

