#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


void ft_memset_avx_erms(uint8_t value, void *dest, size_t len);


int compare_buffers(const unsigned char *buf1, const unsigned char *buf2, size_t size) {
    for (size_t i = 0; i < size; i++) {
        if (buf1[i] != buf2[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    size_t sizes[] = {0, 1, 10, 32, 64, 100, 256, 1024};
    int values[] = {0, 1, 127, 128, 255};
    size_t num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    size_t num_values = sizeof(values) / sizeof(values[0]);

    unsigned char buffer1[1024];
    unsigned char buffer2[1024];

    for (size_t i = 0; i < num_sizes; i++) {
        for (size_t j = 0; j < num_values; j++) {
            size_t size = sizes[i];
            int value = values[j];

            // Réinitialisation des buffers
            memset(buffer1, 0, sizeof(buffer1));
            memset(buffer2, 6, sizeof(buffer2));

            // Remplissage de buffer1 avec la valeur spécifiée
            memset(buffer1, value, size);

            // Appel à la fonction d'assemblage
            ft_memset_avx_erms(value, buffer2, size);

            // Comparaison des résultats
            if (!compare_buffers(buffer1, buffer2, size)) {
                printf("Test failed for size %zu and value %d\n", size, value);
                return 1;
            } else {
                printf("Test passed for size %zu and value %d\n", size, value);
            }
        }
    }

    printf("All tests passed successfully\n");
    return 0;
}
