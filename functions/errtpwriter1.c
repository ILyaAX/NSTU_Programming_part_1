#include <ncurses.h>
#include <string.h>
#include <unistd.h>

void errtypewriter (char mes[], int row, int col);

int main()
{       
	int row, col;
	char mes1 [] = "Knock-knock, Neo.";
        char mes2 [] = "Follow the White Rabbit...";
	initscr();              
        curs_set (1);
	getmaxyx (stdscr, row, col);
	errtypewriter (mes1, row/2, (col - strlen (mes1)) / 2);
	errtypewriter (mes2, row/2 + 1, (col - strlen (mes1)) / 2);
	//clear ();
        getch();                      
        endwin();  
        
        return 0;
}

void errtypewriter (char mes [], int row, int col) {
	
	for (int i = 0; i < strlen (mes); i++) {
		move (row, col + i);
		if (i == strlen (mes) / 3 ) {
			printw("%c",mes [i-4]);
			refresh ();
                	move (row, col + i + 1);
			usleep( 250000 );
			printw("%c",mes [i-2]);
                        refresh ();
                        usleep( 850000 );
			printw("\b \b");
			refresh ();
			usleep( 600000 );
			printw("\b \b");
			refresh ();
                        usleep( 300000 );

		}

		printw("%c",mes [i]);
		refresh ();
		usleep( 150000 );
	
	}

}
