#include <ncurses.h>
#include <string.h>
#include <unistd.h>

void errtypewriter (char mes[], int row, int col, int index_err);

void typewriter (char mes [], int row, int col);

int main()
{       
	//int row, col;
	char mes1 [] = "Wake up, Neo!";
        char mes2 [] = "Follow the white rabbit...";
	char mes3 [] = "Knock, knock";
	initscr();	
        curs_set (1);
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	//getmaxyx (stdscr, row, col);
	move ( 6, 20);
	refresh ();
	usleep (3000000);	
	typewriter (mes1, 6, 20);
	refresh ();
	usleep (3000000);
	clear ();
	errtypewriter (mes2, 6, 20, 15);
	usleep (3000000); 
	typewriter (mes3, 7, 20);
        curs_set (0);
	getch();
	attroff(COLOR_PAIR(1));	
        endwin();  
        
        return 0;
}

void errtypewriter (char mes [], int row, int col, int index_err) {
	
	for (int i = 0; i < strlen (mes); i++) {
		move (row, col + i);
		if (i == index_err) {
			printw("%c",mes [i-2]);
			refresh ();
                	move (row, col + i + 1);
			usleep( 250000 );
			printw("%c",mes [i+2]);
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
		if (mes [i] == ' ') usleep ( 230000 );
		usleep( 150000 );
	
	}

}

void typewriter (char mes [], int row, int col) {

        for (int i = 0; i < strlen (mes); i++) {
                move (row, col + i);
		printw("%c",mes [i]);
                refresh ();
                if (mes [i] == ' ') usleep( 280000 );
                usleep( 150000 );

        }

}

