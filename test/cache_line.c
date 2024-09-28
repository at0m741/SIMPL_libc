#include <stdio.h>
#include <cpuid.h>
void get_cache_info() {
    unsigned int eax, ebx, ecx, edx;
    for (int i = 0; i < 4; ++i) {

        __cpuid_count(4, i, eax, ebx, ecx, edx);
        int cache_type = eax & 0x1F;
        if (cache_type == 0) {
            break;
        }

        int cache_level = (eax >> 5) & 0x7;
        int line_size = (ebx & 0xFFF) + 1;
        int num_sets = ((ecx & 0xFFFF) + 1);
        int associativity = ((ebx >> 22) & 0x3FF) + 1;
        int cache_size = associativity * line_size * num_sets;

        printf("Cache Level: %d\n", cache_level);
        printf("Cache Type: %d\n", cache_type);
        printf("Cache Line Size: %d bytes\n", line_size);
        printf("Cache Size: %d KB\n", cache_size / 1024);
        printf("Associativity: %d\n", associativity);
        printf("Number of Sets: %d\n", num_sets);
        printf("\n");
    }
}

int main() {
    get_cache_info();
    return 0;
}
