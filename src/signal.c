#include "signal.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int currentIndex = 0;

void register_signal(const char* handle, void(*func)(void*)) {
    p[currentIndex] = func;
    signals[currentIndex] = malloc(strlen(handle));
    strcpy(signals[currentIndex], handle);
    currentIndex++;
}

void emit_signal_index(int index, void* data) {
    if (p[index] == NULL) {
        printf("Tried to run null function (not registered) at index [%d]\n", index);
        return;
    }
    p[index](data);
}

void emit_signal_str(const char* handle, void* data) {
    for (int i = 0; i < 255; i++) {
        if (p[i] == NULL) {
            return;
        }
        if (strcmp(signals[i], handle) == 0) {
            p[i](data);
        }
    }
}

void free_signals() {
    for (int i = 0; i < 255; i++) {
        free(signals[i]);
    }
}
