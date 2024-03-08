#include "project.h"


pi_framebuffer_t* fb=NULL;
/*void clearLEDS(void) {
    if(!fb) {
	    fb=getFrameBuffer();
    }
	clearFrameBuffer(fb,0);
}

void opendisplay(void){ 
	sense_fb_bitmap_t *bm=fb->bitmap;
	if(!fb) {
        fb=getFrameBuffer();
    }
}
*/
//	uint16_t color=getColor(255,0,0);
//	clearFrameBuffer(fb,0);
  //  fb->bitmap->pixel[y][x]=color;
//}

void allocate_fb(void) { //making connection between program and LED display
    if(fb==NULL) {
        fb=getFrameBuffer();
    }
}

void free_fb(void) {
    if(fb) {
        clearFrameBuffer(fb,BLACK);
        freeFrameBuffer(fb);
        fb=NULL;
    }
}

void display_dot(int x, int y,int color) {
    if(fb == NULL) {
	fprintf(stderr,"Tried to draw (%d,%d) to a non-existent frame buffer!\n",x,y);
	return;
    }
    	if(color==1){
            sense_fb_bitmap_t *bm=fb->bitmap;
            bm->pixel[x][y] = WHITE;
    	}else
    	if(color==2){
            sense_fb_bitmap_t *bm=fb->bitmap;
            bm->pixel[x][y] = RED;
    	}else
    	if(color==3){
            sense_fb_bitmap_t *bm=fb->bitmap;
            bm->pixel[x][y] = GREEN;
    	}else
    	if(color==4){
            sense_fb_bitmap_t *bm=fb->bitmap;
            bm->pixel[x][y] = BLUE;
    	}else
    	if(color==5){
            sense_fb_bitmap_t *bm=fb->bitmap;
            bm->pixel[x][y] = PINK;

    	}else
    	if(color==6){
            sense_fb_bitmap_t *bm=fb->bitmap;
            bm->pixel[x][y] = CYAN;
    	}else
    	if(color==7){
            sense_fb_bitmap_t *bm=fb->bitmap;
            bm->pixel[x][y] = YELLOW;
    	}else
    	if(color==8){
            sense_fb_bitmap_t *bm=fb->bitmap;
            bm->pixel[x][y] = ORANGE;
    	}else
    	if(color==9){
            sense_fb_bitmap_t *bm=fb->bitmap;
            bm->pixel[x][y] = PURPLE;
}
}
