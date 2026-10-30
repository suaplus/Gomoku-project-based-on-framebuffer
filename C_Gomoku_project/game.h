/*************************************************************************
	> File Name: game.h
	> Author: yas
	> Mail: rage_yas@hotmail.com
	> Created Time: Tue 11 Aug 2026 05:57:05 AM PDT
 ************************************************************************/

#ifndef _GAME_H
#define _GAME_H

#define CHESS_EDGE 50
#define LINE_INTERVAL 25
#define GRID_NUM 20
#define RECORD_i (cursor.cur_x-CHESS_EDGE)/LINE_INTERVAL
#define RECORD_j (cursor.cur_y-CHESS_EDGE)/LINE_INTERVAL

enum type{EMPTY, BLACK_P, WHITE_P};
enum who{NOBODY, WHITE_WIN, BLACK_WIN};

struct loca_cursor
{
    int cur_x;
    int cur_y;
};

struct last_loct
{
    int last_x;
    int last_y;
};

extern void show_chess_broad();
extern void game_begin();

#endif
