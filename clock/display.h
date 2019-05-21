
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "framebuffer.h"

void display_hours(int hours, pi_framebuffer_t *dev);


void display_minutes(int min, pi_framebuffer_t *dev);

void display_seconds(int sec, pi_framebuffer_t *dev);

void display_colons(pi_framebuffer_t *dev);
void display_time(int hours, int minutes, int seconds, pi_framebuffer_t *dev);
