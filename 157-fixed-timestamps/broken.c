#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// BUG: Using __DATE__ and __TIME__ makes builds non-reproducible
const char* build_date = __DATE__;
const char* build_time = __TIME__;

// Instead, use SOURCE_DATE_EPOCH for reproducible builds
long get_build_timestamp(void) {
    const char* epoch_str = getenv("SOURCE_DATE_EPOCH");
    if (epoch_str != NULL) {
        return atol(epoch_str);
    }
    // BUG: Fallback to current time is non-reproducible
    return time(NULL);
}

void show_reproducibility_issues(void) {
    printf("Reproducible Builds: Fixed Timestamps\n");
    printf("======================================\n\n");

    printf("Non-reproducible approach:\n");
    // BUG: These change every compilation
    printf("  Build date: %s\n", build_date);
    printf("  Build time: %s\n", build_time);

    printf("\nReproducible approach:\n");
    printf("  Use SOURCE_DATE_EPOCH environment variable\n");
    printf("  Strip timestamps from binaries\n");
    printf("  Avoid __DATE__ and __TIME__ macros\n");
}

void demonstrate_source_date_epoch(void) {
    printf("\nSOURCE_DATE_EPOCH demonstration:\n");

    long build_ts = get_build_timestamp();
    printf("  Build timestamp: %ld\n", build_ts);

    // BUG: Should check if SOURCE_DATE_EPOCH is set
    printf("  SOURCE_DATE_EPOCH: not set\n");

    const char* epoch = getenv("SOURCE_DATE_EPOCH");
    if (epoch != NULL) {
        printf("  SOURCE_DATE_EPOCH: %s\n", epoch);
    }
}

int main(void) {
    show_reproducibility_issues();
    demonstrate_source_date_epoch();

    printf("\nFixing timestamps:\n");
    printf("  1. Remove __DATE__/__TIME__ macros\n");
    printf("  2. Use SOURCE_DATE_EPOCH\n");
    printf("  3. Build twice and compare hashes\n");

    return 0;
}
