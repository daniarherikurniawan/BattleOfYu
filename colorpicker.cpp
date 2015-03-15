#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <linux/fb.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <math.h>


static struct termios old, baru;

// Fungsi fungsi untuk menghandle keyboard

void initTermios(int echo) {
  tcgetattr(0, &old); 
  baru = old;
  baru.c_lflag &= ~ICANON; 
  baru.c_lflag &= echo ? ECHO : ~ECHO;
  tcsetattr(0, TCSANOW, &baru); 
}

void resetTermios(void) {
  tcsetattr(0, TCSANOW, &old);
}

char getch_(int echo) {
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

char getch(void) {
  return getch_(0);
}

char getche(void) {
  return getch_(1);
}

void gotoxy(int x,int y){
    printf("%c[%d;%df",0x1B,y,x);
}


///////////////////////////////////// MAIN \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

int main() {
	long int screensize = 0;
	struct fb_var_screeninfo vinfo;
	struct fb_fix_screeninfo finfo;
	int fbfd; char* fbp; int location; int x, y;
	char c; int tttt = 0; int colmode = 0; int warnax = 0; int warnay = 0;
	int c_r, c_g, c_b;
	
	// buka framebuffer
	fbfd = open("/dev/fb0",O_RDWR);
	
	if (!fbfd) {
		printf("Error: cannot open framebuffer device.\n");
		exit(1);
	}
	
	if (ioctl (fbfd, FBIOGET_FSCREENINFO, &finfo)) {
		printf("Error reading fixed information.\n");
		exit(2);
	}

	if (ioctl (fbfd, FBIOGET_VSCREENINFO, &vinfo)) {
		printf("Error reading variable information.\n");
		exit(3);
	}

	fbp = (char*)mmap(0, finfo.smem_len, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);

	if ((atoi(fbp)) == -1) {
		printf ("Error: failed to map framebuffer device to memory.\n");
		exit(4);
	}
	
	system("clear");
	
	
	// menggambar kotak cokelat untuk alas color picker
	for ( y = 0; y < 275; y++ ){
	      for ( x = 0; x < 345; x++ ) { 
		  location = (x+vinfo.xoffset + 40) * (vinfo.bits_per_pixel/8) + (y+vinfo.yoffset + 40) * finfo.line_length;
	      
		  int b = 179; 
		  int g = 179; 
		  int r = 179; 
			  
		  if ( vinfo.bits_per_pixel == 32 ) { 
			*(fbp + location) = 	b; 
			*(fbp + location + 1) = g; 
			*(fbp + location + 2) = r; 
			*(fbp + location + 3) = 0; 
		    } else { //assume 16bpp 
			unsigned short int t = r<<11 | g << 5 | b; 
			*((unsigned short int*)(fbp + location)) = t; 
		    }
	      }
	}
	
	// menggambar gradasi warna kanan (pelangi)
	int posy = 0;
	
	for ( y = 0; y < 258; y+=6 ){
	  for ( x = 0; x < 30; x++ ) { 
	      location = (vinfo.xoffset + 345 + x) * (vinfo.bits_per_pixel/8) + (posy+vinfo.yoffset + 50) * finfo.line_length;
		  int b = y; 
		  if (b > 255) b = 255;
		  int g = 0; 
		  int r = 255; 
			  
		  if ( vinfo.bits_per_pixel == 32 ) { 
			*(fbp + location) = 	b; 
			*(fbp + location + 1) = g; 
			*(fbp + location + 2) = r; 
			*(fbp + location + 3) = 0; 
		    } else { //assume 16bpp 
			unsigned short int t = r<<11 | g << 5 | b; 
			*((unsigned short int*)(fbp + location)) = t; 
		    }
	  }
	  posy++;
	}
	
	for ( y = 0; y < 258; y+=6 ){
	  for ( x = 0; x < 30; x++ ) { 
	      location = (vinfo.xoffset + 345 + x) * (vinfo.bits_per_pixel/8) + (posy+vinfo.yoffset + 50) * finfo.line_length;
		  int b = 255; 
		  int g = 0; 
		  int r = 255 - y;
		  if (r < 0) r = 0;
			  
		  if ( vinfo.bits_per_pixel == 32 ) { 
			*(fbp + location) = 	b; 
			*(fbp + location + 1) = g; 
			*(fbp + location + 2) = r; 
			*(fbp + location + 3) = 0; 
		    } else { //assume 16bpp 
			unsigned short int t = r<<11 | g << 5 | b; 
			*((unsigned short int*)(fbp + location)) = t; 
		    }
	  }
	  posy++;
	}
	
	for ( y = 0; y < 258; y+=6 ){
	  for ( x = 0; x < 30; x++ ) { 
	      location = (vinfo.xoffset + 345 + x) * (vinfo.bits_per_pixel/8) + (posy+vinfo.yoffset + 50) * finfo.line_length;
		  int b = 255; 
		  int g = y; 
		  if (g > 255) g = 255;
		  int r = 0; 
			  
		  if ( vinfo.bits_per_pixel == 32 ) { 
			*(fbp + location) = 	b; 
			*(fbp + location + 1) = g; 
			*(fbp + location + 2) = r; 
			*(fbp + location + 3) = 0; 
		    } else { //assume 16bpp 
			unsigned short int t = r<<11 | g << 5 | b; 
			*((unsigned short int*)(fbp + location)) = t; 
		    }
	  }
	  posy++;
	}
	
	for ( y = 0; y < 258; y+=6 ){
	  for ( x = 0; x < 30; x++ ) { 
	      location = (vinfo.xoffset + 345 + x) * (vinfo.bits_per_pixel/8) + (posy+vinfo.yoffset + 50) * finfo.line_length;
		  int b = 255 - y; 
		  if (b < 0) b = 0;
		  int g = 255; 
		  int r = 0;
			  
		  if ( vinfo.bits_per_pixel == 32 ) { 
			*(fbp + location) = 	b; 
			*(fbp + location + 1) = g; 
			*(fbp + location + 2) = r; 
			*(fbp + location + 3) = 0; 
		    } else { //assume 16bpp 
			unsigned short int t = r<<11 | g << 5 | b; 
			*((unsigned short int*)(fbp + location)) = t; 
		    }
	  }
	  posy++;
	}
	
	for ( y = 0; y < 258; y+=6 ){
	  for ( x = 0; x < 30; x++ ) { 
	      location = (vinfo.xoffset + 345 + x) * (vinfo.bits_per_pixel/8) + (posy+vinfo.yoffset + 50) * finfo.line_length;
		  int b = 0; 
		  int g = 255; 
		  int r = y; 
		  if (r > 255) r = 255;
			  
		  if ( vinfo.bits_per_pixel == 32 ) { 
			*(fbp + location) = 	b; 
			*(fbp + location + 1) = g; 
			*(fbp + location + 2) = r; 
			*(fbp + location + 3) = 0; 
		    } else { //assume 16bpp 
			unsigned short int t = r<<11 | g << 5 | b; 
			*((unsigned short int*)(fbp + location)) = t; 
		    }
	  }
	  posy++;
	}
	
	for ( y = 0; y < 258; y+=6 ){
	  for ( x = 0; x < 30; x++ ) { 
	      location = (vinfo.xoffset + 345 + x) * (vinfo.bits_per_pixel/8) + (posy+vinfo.yoffset + 50) * finfo.line_length;
		  int b = 0; 
		  int g = 255 - y; 
		  if (g < 0) g = 0;
		  int r = 255;
			  
		  if ( vinfo.bits_per_pixel == 32 ) { 
			*(fbp + location) = 	b; 
			*(fbp + location + 1) = g; 
			*(fbp + location + 2) = r; 
			*(fbp + location + 3) = 0; 
		    } else { //assume 16bpp 
			unsigned short int t = r<<11 | g << 5 | b; 
			*((unsigned short int*)(fbp + location)) = t; 
		    }
	  }
	  posy++;
	}
	
	
	// Ukuran layar = vinfo.yres (tinggi) dan vinfo.xres (panjang)
	
	
	// pengulangan utama
	do{
	  // gambar main gradien berdasar posisi kursor pelangi
	  for ( y = 0; y < 256; y++ )
	      for ( x = 0; x < 256; x++ ) { 
		  location = (x+vinfo.xoffset + 50) * (vinfo.bits_per_pixel/8) + (y+vinfo.yoffset + 50) * finfo.line_length;
		  
		  colmode = tttt / 256;
		  int persen = tttt % 256;
		  int ia, ib, z;
		  double tmp;
		  
		  int b = 0;
		  int g = 0;
		  int r = 0;
		  
		  ia = x % 256;
		  ib = y % 256;
		  z  = sqrt(ia*ia + ib*ib);	// warna yang tetap
		  if (z > 255) z = 255;
		  
		  
		  // fungsi naik atau turun
		  if (colmode % 2 == 0){
		      tmp = (ia * (255-persen))/255;	// warna yang sedang naik
		  }else{
		      tmp = (ia * (persen))/255;		// warna yang sedang turun
		  }
		  
		  tmp = sqrt(tmp*tmp + ib*ib);
		  if (tmp > 255) tmp = 255;
		  
		  
		  switch (colmode){	// switch berdasarkan posisi warna pelangi (untuk menentukan warna mana yang naik dan turun)
		    case 0:
		      b = 255 - tmp;
		      g = 255 - z; 
		      r = 255 - (y % 256); 
		      break;
		      
		   case 1:
		      b = 255 - (y % 256);
		      g = 255 - z; 
		      r = 255 - tmp; 
		      break;
		      
		   case 2:
		      b = 255 - (y % 256);
		      g = 255 - tmp; 
		      r = 255 - z; 
		      break;
		   
		   case 3:
		      b = 255 - tmp;
		      g = 255 - (y % 256); 
		      r = 255 - z; 
		      break;
		   
		   case 4:
		      b = 255 - z;
		      g = 255 - (y % 256); 
		      r = 255 - tmp; 
		      break; 
		      
		   case 5:
		      b = 255 - z;
		      g = 255 - tmp; 
		      r = 255 - (y % 256); 
		      break; 
		    
		  }
		  
		  if (warnax == x && warnay == y){
				// set curent color
				c_r = r;
				c_g = g;
				c_b = b;
		  }
		  
		  if ( vinfo.bits_per_pixel == 32 ) { 
			*(fbp + location) = 	b; 
			*(fbp + location + 1) = g; 
			*(fbp + location + 2) = r; 
			*(fbp + location + 3) = 0; 
		    } else { //assume 16bpp 
			unsigned short int t = r<<11 | g << 5 | b; 
			*((unsigned short int*)(fbp + location)) = t; 
		    }
	      }

	    // gambar sample color
	    for (x=0; x<30; x++) {
	    	for(y=0; y<30; y++) {
	    		location = (vinfo.xoffset + 151 + x) * (vinfo.bits_per_pixel/8) + (y+vinfo.yoffset + 330) * finfo.line_length;
	    		int b = c_b;
	    		int g = c_g;
	    		int r = c_r;

	    		if(vinfo.bits_per_pixel == 32) {
	    			*(fbp + location) =     b;
	    			*(fbp + location + 1) = g;
	    			*(fbp + location + 2) = r;
	    			*(fbp + location + 3) = 0;
	    		}
	    	}
	    }
	      
		// bersihkan space untuk kursor
		for ( y = 0; y < 256; y++ )
	      for ( x = 0; x < 5; x++ ) { 
				location = (vinfo.xoffset + 390 + x) * (vinfo.bits_per_pixel/8) + ( y+vinfo.yoffset + 50) * finfo.line_length;
				int b = 0; 
				int g = 0; 
				  int r = 0; 
					  
				if ( vinfo.bits_per_pixel == 32 ) { 
					*(fbp + location) = 	b; 
					*(fbp + location + 1) = g; 
					*(fbp + location + 2) = r; 
					*(fbp + location + 3) = 0; 
				} else { //assume 16bpp 
					unsigned short int t = r<<11 | g << 5 | b; 
					*((unsigned short int*)(fbp + location)) = t; 
				}
	      }
		  
		for ( y = 0; y < 5; y++ )
			for ( x = 0; x < 256; x++ ) { 
				location = (vinfo.xoffset + 50 + x) * (vinfo.bits_per_pixel/8) + ( y+vinfo.yoffset + 30) * finfo.line_length;
				int b = 0; 
				int g = 0; 
				  int r = 0; 
					  
				if ( vinfo.bits_per_pixel == 32 ) { 
					*(fbp + location) = 	b; 
					*(fbp + location + 1) = g; 
					*(fbp + location + 2) = r; 
					*(fbp + location + 3) = 0; 
				} else { //assume 16bpp 
					unsigned short int t = r<<11 | g << 5 | b; 
					*((unsigned short int*)(fbp + location)) = t; 
				}
			}
			
		for ( y = 0; y < 256; y++ )
			for ( x = 0; x < 5; x++ ) { 
				location = (vinfo.xoffset + 30 + x) * (vinfo.bits_per_pixel/8) + ( y+vinfo.yoffset + 50) * finfo.line_length;
				int b = 0; 
				int g = 0; 
				int r = 0; 
					  
				if ( vinfo.bits_per_pixel == 32 ) { 
					*(fbp + location) = 	b; 
					*(fbp + location + 1) = g; 
					*(fbp + location + 2) = r; 
					*(fbp + location + 3) = 0; 
				} else { //assume 16bpp 
					unsigned short int t = r<<11 | g << 5 | b; 
					*((unsigned short int*)(fbp + location)) = t; 
				}
			}
		 
	    // gambar kursor  
	   for ( x = 0; x < 5; x++ ) { 
	      location = (vinfo.xoffset + 390 + x) * (vinfo.bits_per_pixel/8) + ( (tttt / 6 )+vinfo.yoffset + 50) * finfo.line_length;
		  int b = 255; 
		  int g = 255; 
		  int r = 255; 
			  
		  if ( vinfo.bits_per_pixel == 32 ) { 
			*(fbp + location) = 	b; 
			*(fbp + location + 1) = g; 
			*(fbp + location + 2) = r; 
			*(fbp + location + 3) = 0; 
		    } else { //assume 16bpp 
			unsigned short int t = r<<11 | g << 5 | b; 
			*((unsigned short int*)(fbp + location)) = t; 
		    }
	    }
		
		for ( y = 0; y < 5; y++ ) { 
			location = (vinfo.xoffset + 50 + warnax) * (vinfo.bits_per_pixel/8) + ( y + vinfo.yoffset + 30) * finfo.line_length;
			int b = 255; 
			int g = 255; 
			int r = 255; 
			  
			if ( vinfo.bits_per_pixel == 32 ) { 
				*(fbp + location) = 	b; 
				*(fbp + location + 1) = g; 
				*(fbp + location + 2) = r; 
				*(fbp + location + 3) = 0; 
			} else { //assume 16bpp 
				unsigned short int t = r<<11 | g << 5 | b; 
				*((unsigned short int*)(fbp + location)) = t; 
			}
	    }
	      
		for ( x = 0; x < 5; x++ ) { 
			location = (vinfo.xoffset + 30 + x) * (vinfo.bits_per_pixel/8) + ( warnay + vinfo.yoffset + 50) * finfo.line_length;
			int b = 255; 
			int g = 255; 
			int r = 255; 
			  
			if ( vinfo.bits_per_pixel == 32 ) { 
				*(fbp + location) = 	b; 
				*(fbp + location + 1) = g; 
				*(fbp + location + 2) = r; 
				*(fbp + location + 3) = 0; 
			} else { //assume 16bpp 
				unsigned short int t = r<<11 | g << 5 | b; 
				*((unsigned short int*)(fbp + location)) = t; 
			}
		}
		
		

		// biar kedip-kedipnya ga rusuh
		// print lable sample color
		gotoxy(6,22);
		printf("Sample Color:");

		// print info R,G,B dari sample color
		gotoxy(100, 50);

		// baca input
		c = getch();
		
	  
		if (c == 115){
			tttt = (tttt + 6);
			if (tttt > 1530) tttt = 1530;
			
		}else if(c == 27){
			getch();
			c = getch();
			switch (c){
				case 65:
					warnay--;
					if (warnay < 0) warnay = 0;
					break;
				case 66:
					warnay++;
					if (warnay > 255) warnay = 255;
					break;
				case 67:	
					warnax++;
					if (warnax > 255) warnax = 255;
					break;
				case 68:	
					warnax--;
					if (warnax < 0) warnax = 0;
					break;
			}
		}else if(c == 119){
			tttt -= 6;
			if (tttt < 0) tttt = 0;
		}
	  
	  
	}while (c != 120);
	
	munmap(fbp, screensize);
	close(fbfd);
	
	//printf("Warna yang anda pilih:\nR: %d\nG: %d\nB: %d\n\n", c_r, c_g, c_b);
	
	return 0;
} 
