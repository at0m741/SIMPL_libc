#include "../libft.h"



void get_cpu_features(cpu_feature_t features[], size_t size) {
    cpu_feature_t temp[] = {
        CHECK_FEATURE(mmx),
        CHECK_FEATURE(sse),
        CHECK_FEATURE(sse2),
        CHECK_FEATURE(sse3),
        CHECK_FEATURE(ssse3),
        CHECK_FEATURE(sse4.1),
        CHECK_FEATURE(sse4.2),
        CHECK_FEATURE(avx),
        CHECK_FEATURE(avx2),
		CHECK_FEATURE(avx512f),
    };

    for (size_t i = 0; i < size && i < sizeof(temp) / sizeof(temp[0]); ++i) {
        features[i] = temp[i];
    }
}

void check_cpu_features() {
    cpu_feature_t features[10];
    get_cpu_features(features, sizeof(features) / sizeof(features[0]));

    printf("Checking CPU features:\n");
    for (size_t i = 0; i < sizeof(features) / sizeof(features[0]); ++i) {
        printf("%s: %s\n", features[i].name, features[i].supported ? "supported" : "not supported");
    }
}

int get_cpu_info() {
	cpu_feature_t features[10];
	get_cpu_features(features, sizeof(features) / sizeof(features[0]));

	for (size_t i = 0; i < sizeof(features) / sizeof(features[0]); ++i) {
		if (features[i].supported) {
			return 1;
		}
	}
	return 0;
}
