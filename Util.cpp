#include "Util.h"

long Util :: getCurrentTimeInMiliseconds() {
	long            ms; // Milliseconds
    time_t          s;  // Seconds
    struct timespec spec;

    clock_gettime(CLOCK_REALTIME, &spec);

    s  = spec.tv_sec;
    ms = round(spec.tv_nsec / 1.0e6);
    return ms;
}
