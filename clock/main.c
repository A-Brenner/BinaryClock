#include "display.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
int main (void) {
    pi_framebuffer_t *fb=getFBDevice();

    char str[80];
	scanf("%s",str);
    while (strlen(str) > 7){



        const char s[2] = ":";
        char *token;

        int hours;
        int minutes;
        int seconds;
        int counter =0;
        /* get the first token */
        token = strtok(str, s);

        /* walk through other tokens */
        while( token != NULL ) {
            switch(counter){
                case 0:
                    hours = (int)atoi(token);
                    break;
                case 1:
                    minutes = (int)atoi(token);
                    break;
                case 2:
                    seconds = (int)atoi(token);
                    break;
            }

            token = strtok(NULL, s);
            counter++;
        }
	display_time(hours, minutes, seconds, getFBDevice());
	scanf("%s",str);	


    sleep(1);

	clearBitmap(fb->bitmap,0);
	}
	clearBitmap(fb->bitmap,0);

	return 0;
}

