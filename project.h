#include "sense.h"
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <linux/input.h>
#include <stddef.h>
#define WHITE 0xFFFF
#define BLACK 0x0000
#define RED 0xF800
#define GREEN 0x07E0
#define BLUE 0x001F
#define PINK 0xFC10
#define CYAN 0x07FF
#define YELLOW 0xFFE0
#define ORANGE 0xFBC0
#define PURPLE 0x781F
//int checkJoystick(void);
int checkGyroJoystick(void);
void drawPoint(int,int);
void clearLEDS(void);
void opendisplay(void);
void freeInputs(void);
void freeOutputs(void);
void allocate_fb(void);
void free_fb(void);
void display_dot(int x, int y,int color);
void callbackFunc(unsigned int code);
