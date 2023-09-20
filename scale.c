#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
extern int calculate_new_width(int w1, int h1, int w2, int h2);
extern int calculate_new_height(int w1, int h1, int w2, int h2);

/**
* resize a Pixbuf and keep the aspect ratio
*/
GdkPixbuf *resize(GdkPixbuf *picture, int width, int height) {
	if (picture != NULL) {
    	int newwidth = 0, newheight = 0, flag = 0;
    	newwidth = picture->width;
    	newheight = picture->height;
    	if (newwidth >= width || newheight >= height) {
        	newwidth = calculate_new_width(picture->width, picture->height, width, height);
        	newheight = calculate_new_height(picture->width, picture->height, width, height);
        	flag = 1;
    	}
    	if (flag == 1) {
        	GdkPixbuf *temp = NULL;
        	temp = gdk_pixbuf_scale_simple(picture, newwidth, newheight, GDK_INTERP_BILINEAR);
        	free(picture);
        	return (temp);
    	} else {
        	return (picture);
    	}
	} else {
    	return picture;
	}
}
