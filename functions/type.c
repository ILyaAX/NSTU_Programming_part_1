#include <ncurses.h>
#include <string.h>
#include <unistd.h>

void typewriter (char mes[], int row, int col);

int main()
{       
	int row, col;
	char mes [] = "Hello World!!! Test typewriter";
        initscr();              
        curs_set (0);
	getmaxyx (stdscr, row, col);
	typewriter (mes, row/2, (col - strlen (mes)) / 2);
	//clear ();
        getch();                      
        endwin();  
        
        return 0;
}

void typewriter (char mes [], int row, int col) {
	
	for (int i = 0; i < strlen (mes); i++) {
		move (row, col + i);
		printw("%c",mes [i]);
		refresh ();
		usleep( 150000 );
	
	}

}
