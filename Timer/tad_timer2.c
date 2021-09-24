#include "tad_timer.h"
#include <time.h>
#include <stdlib.h>

typedef struct timer {
    clock_t start;
    clock_t end;
};

Timer* timer_criar() {
    Timer* t = (Timer*) calloc(1, sizeof(Timer));
    t->start = -1;
    t->end = -1;
    return t;
}

void timer_desalocar(Timer** t) {
    free(*t);
    *t = NULL;
}

void timer_start(Timer* t) {
    t->start = clock();
}

void timer_stop(Timer* t) {
    t->end = clock();
}

void timer_reset(Timer* t) {
    t->end = -1;
    t->start = -1;
}

float timer_resultado(Timer* t) {
    double elapsed = (t->end - t->start)/CLOCKS_PER_SEC;
    return elapsed;
}
