#include <stdio.h>
#include "framebuffer.h"
#include "game.h"

int main(void)
{
	init_fb("/dev/fb0");
        
    show_chess_broad();
    
    game_begin();
	
    return 0;
}
