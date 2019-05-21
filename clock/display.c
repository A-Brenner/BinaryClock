#include "framebuffer.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void display_colons(pi_framebuffer_t *dev) {
    uint16_t white=getColor(255,255,255);
    pi_framebuffer_t *fb = dev;
    fb->bitmap->pixel[1][1]=white;
    fb->bitmap->pixel[1][2]=white;
    fb->bitmap->pixel[1][4]=white;
    fb->bitmap->pixel[1][5]=white;
	
	fb->bitmap->pixel[2][1]=white;
    fb->bitmap->pixel[2][2]=white;
    fb->bitmap->pixel[2][4]=white;
    fb->bitmap->pixel[2][5]=white;
	
	fb->bitmap->pixel[4][1]=white;
    fb->bitmap->pixel[4][2]=white;
    fb->bitmap->pixel[4][4]=white;
    fb->bitmap->pixel[4][5]=white;
	
	fb->bitmap->pixel[5][1]=white;
    fb->bitmap->pixel[5][2]=white;
    fb->bitmap->pixel[5][4]=white;
    fb->bitmap->pixel[5][5]=white;
}

char * decToBin(int n)
{
    long binaryNumber = 0;
    int remainder, i = 1, step = 1;

    while (n!=0)
    {
        remainder = n%2;
        n /= 2;
        binaryNumber += remainder*i;
        i *= 10;
    }
    char *bin = (char *) malloc(sizeof(char) * 7);
    sprintf(bin, "%ld", binaryNumber);
    return bin;
}


void display_hours(int hours, pi_framebuffer_t *dev){
	uint16_t blue=getColor(0,0,255);
    pi_framebuffer_t *fb = dev;
  
    char *bin = decToBin(hours);
	int j = 0;

    for (int i = strlen(bin) - 1; i >= 0; i--){
        if (bin[i] == '1'){
			fb->bitmap->pixel[j][6]=blue;
			
        }
		j++;

    }
    
}

void display_minutes(int min, pi_framebuffer_t *dev){
	uint16_t green=getColor(0,255,0);
    pi_framebuffer_t *fb = dev;
  
    char *bin = decToBin(min);
	int j = 0;

    for (int i = strlen(bin) - 1; i >= 0; i--){
        if (bin[i] == '1'){
			fb->bitmap->pixel[j][3]=green;
			
        }
		j++;

    }
    
}
void display_seconds(int sec, pi_framebuffer_t *dev){
	uint16_t red=getColor(255,0,0);
    pi_framebuffer_t *fb = dev;
  
    char *bin = decToBin(sec);
	int j = 0;

    for (int i = strlen(bin) - 1; i >= 0; i--){
        if (bin[i] == '1'){
			fb->bitmap->pixel[j][0]=red;
			
        }
		j++;

    }
    
}
void display_time(int hours, int minutes, int seconds, pi_framebuffer_t *dev){
	display_colons(dev);

	display_hours(hours, dev);
	display_minutes(minutes, dev);
	display_seconds(seconds, dev);
}





