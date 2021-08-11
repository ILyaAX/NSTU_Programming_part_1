#include <ncurses.h>
#include <string.h>
#include <unistd.h>

void typewriter (char mes[], int row, int col);

int main()
{       
	int row, col;
	char mes [] = "Knock-knock, Neo. Follow the White Rabbit.";
        initscr();              
        curs_set (1);
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
		if (i % 14 == 0 && i != 0 ) {
			printw("%c",mes [i-4]);
			refresh ();
                	move (row, col + i + 1);
			usleep( 250000 );
			printw("%c",mes [i+5]);
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
