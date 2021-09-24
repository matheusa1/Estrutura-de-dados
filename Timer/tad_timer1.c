#include "tad_timer.h"
#include <time.h>
#include <stdlib.h>

struct timer {
    time_t start;
    time_t end;
    time_t total;
};

Timer* timer_criar() {
    Timer* t = (Timer*) malloc(sizeof(Timer));
    t->start = -1;
    t->end = -1;
    t->total = -1;
    return t;
}

void timer_desalocar(Timer** t) {
    free(*t);
    *t = NULL;
}

void timer_start(Timer* t) {
    time(&t->start);
}

void timer_stop(Timer* t) {
    time(&t->end);
}

void timer_reset(Timer* t) {
    t->start = -1;
    t->end = -1;
    t->total = -1;
}

float timer_resultado(Timer* t) {
    time_t elapsed = t->end - t->start;
    return elapsed;
}