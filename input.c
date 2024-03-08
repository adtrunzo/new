#include "project.h"
char xPos = 7, yPos = 7;
int color=1;
int check;
int run=1;
void interrupt_handler(int sig){
    run=0;
}

void callbackFunc(unsigned int code);

int checkGyroJoystick(void) {
    pi_joystick_t* joystick=getJoystickDevice();
    float threshold=1;
    pi_i2c_t* device;
    coordinate_t data;
    //signal(SIGINT, interrupt_handler);
    device=geti2cDevice();
    if (device){
        configureAccelGyro(device);
        float x=0,y=0,z=0;
        float maxx=0,maxy=0,maxz=0;

    while(run && getAccelData(device, &data)){

        float dx=data.x-x,dy=data.y-y,dz=data.z-z;
        if(dx>maxx) maxx=dx;
        if(dy>maxy) maxy=dy;
        if(dz>maxz) maxz=dz;
        if(dx*dx+dy*dy+dz*dz > threshold) {
            printf("bumped: %f %f %f\n",dx,dy,dz);
            return 0;
            //if bumped
        }
        x=data.x; y=data.y; z=data.z;
        int lastX=-1,lastY=-1;
       
        pollJoystick(joystick,callbackFunc,100);
        if(lastX!=xPos || lastY!=yPos) {
            lastX=xPos;
            lastY=yPos;
            
        }
        if(check == 5){
            check=10;
            return 5;
        }else if(check == 4){
            check=10;
            return 4;
        }else if(check == 3){
            check=10;
            return 3;
        }else if(check == 2){
            check=10;
            return 2;
        }else if(check == 6){
            check=10;
            return 6;
        }else{
            return 10;
        }


    }

}
return 0;
}

/* Note that the codes don't really match any orientation of the joystick */
void callbackFunc(unsigned int code) {
    fprintf(stderr,"code: %u\t",code);
    if(code == KEY_UP) {
        fprintf(stderr,"up");
        check = 5;
        if(yPos==0) {
            yPos=7;
        }else{
            yPos--;
        }
    }else if(code == KEY_DOWN) {
        fprintf(stderr,"down");
        check = 4;
        if(yPos==7) {
            yPos=0;
        }else{
            yPos++;
        }
    }else if(code == KEY_RIGHT) {
        check = 3;
        fprintf(stderr,"right");
        if(xPos==7) {
            xPos=0;
        }else{
            xPos++;
        }
    }else if(code == KEY_LEFT) {
        check = 2;
        fprintf(stderr,"left");
        if(xPos==0) {
            xPos=7;
        }else{
            xPos--;
        }
    }else if(code == KEY_ENTER) {
        check = 6;
        fprintf(stderr,"push");
        
        //change color
    }
    fprintf(stderr,"\n");
}

