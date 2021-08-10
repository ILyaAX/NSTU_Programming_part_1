#include <ncurses.h>

int main()
{	

	initscr();			/* Start curses mode 		  */
	for (int i = 0; i < 10; i++) {
	printw("Hello World - %d\n", i);	/* Print Hello World		  */
	}
	refresh();			/* Print it on to the real screen */
	getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */
	
	return 0;
}
