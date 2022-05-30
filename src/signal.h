#ifndef SIGNAL_H
#define SIGNAL_H

extern int currentIndex;
void(*p[255])(void*); //8 * 255 = 2040 bytes for function storage
char* signals[255]; //8 * 255 = 2040 bytes just for the pointers

void register_signal(const char*, void (*)(void*));
void emit_signal_index(int, void*);
void emit_signal_str(const char*, void*);

void free_signals();
#endif
