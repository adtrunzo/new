#include "project.h"

char running=1;
void handler(int sig){
	running=0;
//if joystick movies up, move position variable down
}


void main(void){
	int x = 0;
    int y = 0;
    int color = 1;
	allocate_fb();	
    display_dot(x,y,color);
	while (running){
        switch(checkGyroJoystick()) {
            case 6://KEY_PUSH
                color = color + 1;
                if(color>9){
                    color = 1;
                }
                display_dot(x,y,color);
                break;
            case 5://KEY_UP
                x--;
                if(x==-1){
                    x=7;
                }
                display_dot(x,y,color);
                break;
            case 4://KEY_DOWN
                x++;
                if(x==8){
                    x=0;
                }
                display_dot(x,y,color);
                break;
            case 3://KEY_RIGHT
                y++;
                if(y==8){
                    y=0;
                }
                display_dot(x,y,color);
                break;
            case 2://KEY_LEFT

                y--;
                if(y==-1){
                    y=7;
                }
                display_dot(x,y,color);
                break;
            case 10:
                break;
            case 0:
                free_fb();
                allocate_fb();
                break;
            default:
                running=0;
        }
    //    x = (x+8)%8;
      //  y = (y+8)%8;
       // display_dot(x,y,color);
	}
/*	while(1){
	if(checkGyroJoystick==0){ //if pi was bumped
		free_fb;
	}else{
		checkGyroJoystick();
		display_dot(x,y,color);
	}
	}*/

//	free_fb();
}
