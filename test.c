#include "include/string.h"
#include "include/stdio.h"

int main(int ac, char **av, char **env)
{
	int i = strlen("Test");
	printf("%d\n", i);
	printf("%d\n", strlen("Test"));
	(void)ac;
	(void)av;
	(void)env;

}

