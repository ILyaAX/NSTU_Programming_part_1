#include <ncurses.h>
#include <string.h>
#include <unistd.h>

int main()
{       
	int row, col;
	char mes [] = "Hello World -";
        initscr();                      /* Start curses mode              */
        curs_set (0);
	getmaxyx (stdscr, row, col);
	for (int i = 0; i < 10; i++) {
      	move ((row - 10) / 2 + i, (col - strlen (mes)) / 2);
	printw("%s %4d",mes, i);
        refresh();
        usleep( 200000 );
	if (i < 9) clear ();
	}
        getch();                        /* Wait for user input */
        endwin();                       /* End curses mode                */
        
        return 0;
}

