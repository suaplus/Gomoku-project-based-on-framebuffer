/*************************************************************************
	> File Name: game.c
	> Author: yas
	> Mail: rage_yas@hotmail.com
	> Created Time: Tue 11 Aug 2026 05:56:26 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include"game.h"
#include"framebuffer.h"

struct loca_cursor cursor = 
{
    .cur_x = CHESS_EDGE + GRID_NUM / 2 * LINE_INTERVAL,
    .cur_y = CHESS_EDGE + GRID_NUM / 2 * LINE_INTERVAL,
};

struct last_loct l_location = { 0, 0};
struct last_loct l_location_2 = { 0, 0};

enum type record[21][21] = {EMPTY};
enum type last_p = EMPTY;
enum type last_p2 = EMPTY;

char instruct = 0;
int flag = 0;

void show_chess_broad()
{
    //draw_clean(MUZHI);
    draw_bmp(0, 0, "./chess.bmp");
    //draw_win(600, 300, 30, 3, BLACK);

    for(int i = 0; i <= GRID_NUM; ++i)
    {
        draw_h_line(CHESS_EDGE, CHESS_EDGE + i * LINE_INTERVAL, GRID_NUM * LINE_INTERVAL, BLACK);
        
        draw_s_line(CHESS_EDGE + i * LINE_INTERVAL, CHESS_EDGE, GRID_NUM * LINE_INTERVAL, BLACK);   
    }

    draw_circle(cursor.cur_x, cursor.cur_y, 11, RED);

    for(int i = 0; i <= GRID_NUM; ++i)
    {
        for(int j = 0; j <= GRID_NUM; ++j)
        {
            if(record[i][j] == BLACK_P)
            {
                draw_circle(i * LINE_INTERVAL + CHESS_EDGE, j * LINE_INTERVAL + CHESS_EDGE, 9, BLACK);
            }else if(record[i][j] == WHITE_P)
            {
                draw_circle(i * LINE_INTERVAL + CHESS_EDGE, j * LINE_INTERVAL + CHESS_EDGE, 9, WHITE);
            }
        }
    }

    if(last_p == WHITE_P)
    {
        draw_circle(685, 310, 30, BLACK);
    }else
    {
        draw_circle(685, 310, 30, WHITE);
    }
}

void instruct_panduan()
{
    flag = 0;
    instruct = getchar();
    
    if(instruct == 'w')
    {
        if(cursor.cur_y > CHESS_EDGE)
        {
            cursor.cur_y -= LINE_INTERVAL;
        }
    }else if(instruct == 's')
    {
        if(cursor.cur_y < fby_g - CHESS_EDGE - 5)
        {
            cursor.cur_y += LINE_INTERVAL;
        }
    }else if(instruct == 'a')
    {
        if(cursor.cur_x > CHESS_EDGE)
        {
            cursor.cur_x -= LINE_INTERVAL;
        }
    }else if(instruct == 'd')
    {
        if(cursor.cur_x < CHESS_EDGE + GRID_NUM * LINE_INTERVAL - 5)
        {
            cursor.cur_x += LINE_INTERVAL;
        }
    }else if(instruct == ' ')
    {
        if(last_p == EMPTY)
        {
            draw_circle(cursor.cur_x, cursor.cur_y, 10, WHITE);   
            record[RECORD_i][RECORD_j] = WHITE_P;
            last_p = WHITE_P;
            l_location.last_x = RECORD_i;
            l_location.last_y = RECORD_j;
        }else if(last_p == WHITE_P)
        {
            if(record[RECORD_i][RECORD_j] == EMPTY)
            {
                draw_circle(cursor.cur_x, cursor.cur_y, 10, BLACK);
                record[RECORD_i][RECORD_j] = BLACK_P;   
                last_p = BLACK_P;
                l_location_2.last_x = l_location.last_x;
                l_location_2.last_y = l_location.last_y;
                last_p2 = WHITE_P;
                l_location.last_x = RECORD_i;
                l_location.last_y = RECORD_j;
            }
        }else if(last_p == BLACK_P)
        {
            if(record[RECORD_i][RECORD_j] == EMPTY)
            {
                draw_circle(cursor.cur_x, cursor.cur_y, 10, WHITE);
                record[RECORD_i][RECORD_j] = WHITE_P;   
                last_p = WHITE_P;
                l_location_2.last_x = l_location.last_x;
                l_location_2.last_y = l_location.last_y;
                last_p2 = BLACK_P;
                l_location.last_x = RECORD_i;
                l_location.last_y = RECORD_j;
            }
        }
    }else if(instruct == 'r')
    {
        if(last_p2 != EMPTY)
        {
            record[l_location.last_x][l_location.last_y] = EMPTY;
            l_location.last_x = l_location_2.last_x;
            l_location.last_y = l_location_2.last_y;
            cursor.cur_x = l_location_2.last_x * LINE_INTERVAL + CHESS_EDGE;
            cursor.cur_y = l_location_2.last_y * LINE_INTERVAL + CHESS_EDGE;
            last_p = last_p2;
            last_p2 = EMPTY;
        }
    }
/*
    else if(instruct == 'c')
    {
        memset(record,0,sizeof(record));
        last_p = EMPTY;
        cursor.cur_x = CHESS_EDGE + GRID_NUM / 2 * LINE_INTERVAL;
        cursor.cur_y = CHESS_EDGE + GRID_NUM / 2 * LINE_INTERVAL;
    }
*/
}

enum who res_panduan()
{
    //enum who win = NOBODY;
    int cnt_h = 1;
    int cnt_l = 1;
    int cnt_yx = 1;
    int cnt_zx = 1;

    int i = 1;

    if(last_p == EMPTY)
    {
        return NOBODY;
    }
    //hang
    for(i = 1; i < 5; ++i)
    {
        if(l_location.last_x + i > 20)
        {
            break;
        }else
        {
            if(record[l_location.last_x + i][l_location.last_y] == record[l_location.last_x][l_location.last_y])
            {
                ++cnt_h;
            }else
            {
                break;
            }
        }
    }
    for(i = 1; i < 5; ++i)
    {
        if(l_location.last_x - i < 0)
        {
            break;
        }else
        {
            if(record[l_location.last_x - i][l_location.last_y] == record[l_location.last_x][l_location.last_y])
            {
                ++cnt_h;
            }else
            {
                break;
            }
        }
    }

    //lie
    for(i = 1; i < 5; ++i)
    {
        if(l_location.last_y + i > 20)
        {
            break;
        }else
        {
            if(record[l_location.last_x][l_location.last_y + i] == record[l_location.last_x][l_location.last_y])
            {
                ++cnt_l;
            }else
            {
                break;
            }
        }
    }
    for(i = 1; i < 5; ++i)
    {
        if(l_location.last_y - i < 0)
        {
            break;
        }else
        {
            if(record[l_location.last_x][l_location.last_y - i] == record[l_location.last_x][l_location.last_y])
            {
                ++cnt_l;
            }else
            {
                break;
            }
        }
    }

    //you xie
    for(i = 1; i < 5; ++i)
    {
        if(l_location.last_x - i < 0 || l_location.last_y + i > 20)
        {
            break;
        }else
        {
            if(record[l_location.last_x - i][l_location.last_y + i] == record[l_location.last_x][l_location.last_y])
            {
                ++cnt_yx;
            }else
            {
                break;
            }
        }
    }
    for(i = 1; i < 5; ++i)
    {
        if(l_location.last_x + i > 20 || l_location.last_y - i < 0)
        {
            break;
        }else
        {
            if(record[l_location.last_x + i][l_location.last_y - i] == record[l_location.last_x][l_location.last_y])
            {
                ++cnt_yx;
            }else
            {
                break;
            }
        }
    }

    //zuo xie
    for(i = 1; i < 5; ++i)
    {
        if(l_location.last_x - i < 0 || l_location.last_y - i < 0)
        {
            break;
        }else
        {
            if(record[l_location.last_x - i][l_location.last_y - i] == record[l_location.last_x][l_location.last_y])
            {
                ++cnt_zx;
            }else
            {
                break;
            }
        }
    }
    for(i = 1; i < 5; ++i)
    {
        if(l_location.last_x + i > 20 || l_location.last_y + i > 20)
        {
            break;
        }else
        {
            if(record[l_location.last_x + i][l_location.last_y + i] == record[l_location.last_x][l_location.last_y])
            {
                ++cnt_zx;
            }else
            {
                break;
            }
        }
    }

    //res
    if(cnt_h == 5 || cnt_l == 5 || cnt_yx == 5 || cnt_zx == 5)
    {
        if(record[l_location.last_x][l_location.last_y] == WHITE_P)
        {
            return WHITE_WIN;
        }else
        {
            return BLACK_WIN;
        }
    }else
    {
        return NOBODY;
    }

}
void game_again()
{
    memset(record,0,sizeof(record));
    last_p = EMPTY;
    cursor.cur_x = CHESS_EDGE + GRID_NUM / 2 * LINE_INTERVAL;
    cursor.cur_y = CHESS_EDGE + GRID_NUM / 2 * LINE_INTERVAL;
}

void game_begin()
{
    while(1)
    {
        instruct_panduan();
        
        //draw_circle(400,300,100,RED);

        if(res_panduan() == WHITE_WIN)
        {
            //draw_win(600, 300, 30, 3, WHITE);
            draw_bmp(150, 160, "./white.bmp");
            break;

        }else if(res_panduan() == BLACK_WIN)
        {
            //draw_win(600, 300, 30, 3, BLACK);
            draw_bmp(150, 160, "./black.bmp");
            break;
        }
            

        //draw_circle(400,300,100,RED);

        show_chess_broad();
    
    }
}
