#include <stdio.h>
#include <string.h>
#include "/usr/include/stdlib.h"
#include "./src/config/cpuid_conf.h"

int main(int ac, char **av, char **env) {

    if (ac <= 1)
        return 1;

    int i = strlen(av[1]);
    printf("%d\n", i);

    char *str = malloc(5);
    if (!str) {
        printf("Erreur d'allocation de mémoire\n");
        return 1;
    }

    memset(str, 0, 5);  // Initialiser la mémoire allouée
	printf("%p\n", str);
    memset(str, 'A', 5);
    printf("%p\n", str);
    printf("%s\n", str); // Affiche le contenu de str
    free(str);

    return 0;
}
