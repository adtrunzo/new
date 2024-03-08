#include "project.h"
int main(){
	for(;;){
        int result=checkGyroJoystick();
        printf("Got result %d.\n",result);
        int result2=checkGyroJoystick();
        printf("Got result", result2);
	}
	freeInputs();
}
