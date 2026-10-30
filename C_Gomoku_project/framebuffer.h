#ifndef __FRAMEBUFFER_H__
#define __FRAMEBUFFER_H__

#define RGB_FMT_888 32
#define RGB_FMT_565 16

#define RED   0x00FF0000
#define GREEN 0x0000FF00
#define BLUE  0x000000FF
#define BLACK 0x00000000
#define WHITE 0x00FFFFFF
#define YELLOW 0x00FFFF00
#define MUZHI 0x00DEB887

//#define WORD_D 5
//#define SUM_D d1+d2+d3+d4+d5+d6
//
//当前显示设备可视化界面的分辨率
extern int fbx_g;   //800   横向分辨率
extern int fby_g;   //600   纵向分辨率

//初始化显示设备:/dev/fb0
extern int init_fb(char *devname);
//绘制一个像素点
//x ： 横向坐标
//y ： 纵向坐标
//col ：RGB888颜色值
extern void draw_point(int x, int y, unsigned int col);

extern void draw_h_line(int x, int y, int len, unsigned int col);
extern void draw_clean(unsigned int col);
extern void draw_s_line(int x, int y, int len, unsigned int col);
extern void draw_rect(int x, int y, int h, int k, unsigned int col);
extern void draw_circle(int x0, int y0, int r, unsigned int col);
extern void draw_zxie_line(int x, int y, int size, unsigned int col);
extern void draw_yxie_line(int x, int y, int size, unsigned int col);
//extern void draw_win(int x, int y , int size, int thick, int col);
extern void draw_bmp(int x, int y, char *bmpname);

#endif


