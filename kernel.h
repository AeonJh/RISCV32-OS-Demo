#pragma once

struct sbiret {
    long error;
    long value;
};

#define PANIC(fmt, ...)                                                     \
    do {                                                                    \
        printf("PANIC at %s:%d: " fmt, __FILE__, __LINE__, ##__VA_ARGS__);  \
        while(1) {}                                                         \
    } while (0)
