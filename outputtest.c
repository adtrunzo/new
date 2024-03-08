#include "project.h"

//pi_framebuffer_t* fb=NULL;
int main(){
    allocate_fb();
    int x,y,c;
    printf("ctl-c or ctl-d to exit\n");
    printf("x,y,c? ");
	while (scanf("%d,%d,%d",&x,&y,&c)==3){
        x=x%8;
        y=y%8;
        printf("%d,%d,%d\n",x,y,c);
        display_dot(x,y,c);
        printf("x,y,c? ");
	}
    //freeOutputs();
    free_fb();
}
