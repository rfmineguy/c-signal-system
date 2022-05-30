#include <stdio.h>
#include "signal.h"

typedef struct {
    
} entity;

void handle_movement(void* data) {
    int* intData = (int*) data;
    printf("Hello world, %d\n", *intData);
}

void handle_two(void* data) {
    char** str = (char**) data;
    printf("String is : %s\n", *str);
}

int main() {
    register_signal("Hell", &handle_movement);
    register_signal("Signal2", &handle_two);

    int data = 2;
    emit_signal_str("Hell", &data);
    
    char* hello = "Helo World";
    emit_signal_str("Signal2", &hello);
    
    free_signals();

    emit_signal_str("Hell", &data);
}
