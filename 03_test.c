#include <ncurses.h>
#include <string.h>
#include <unistd.h>

int main()
{       
	int row, col;
	char mes [] = "Hello World";
        initscr();                      /* Start curses mode              */
        curs_set (0);
	getmaxyx (stdscr, row, col);
	while (1) {
		for (int i = 0; i < row; i++) {
      		move (i, (col - strlen (mes)) / 2);
		printw("%s",mes);
        	refresh();
        	usleep( 80000 );
		clear ();
		}
	}
        getch();                        /* Wait for user input */
        endwin();                       /* End curses mode                */
        
        return 0;
}

