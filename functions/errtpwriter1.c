#include <ncurses.h>
#include <string.h>
#include <unistd.h>

void errtypewriter (char mes[], int row, int col, int index_err);

void typewriter (char mes [], int row, int col);

int main()
{       
	int row, col;
	char mes1 [] = "Wake up, Neo!";
        char mes2 [] = "Follow the white rabbit...";
	char mes3 [] = "Knock, knock";
	initscr();	
        curs_set (1);
	getmaxyx (stdscr, row, col);
	move ( row/2, (col - strlen (mes1)) / 2);
	refresh ();
	//printw (" ");
	//for (int i = 0; i < 7; i++) {
	//	curs_set (1);
	//	usleep (500000);
	//	curs_set (0);
        //        usleep (500000);
	//}
	//curs_set (1);
	usleep (3000000);	
	typewriter (mes1, row/2, (col - strlen (mes1)) / 2);
	refresh ();
	usleep (3000000);
	clear ();
	errtypewriter (mes2, row/2, (col - strlen (mes1)) / 2, 15);
	usleep (3000000); 
	typewriter (mes3, row/2 + 1, (col - strlen (mes1)) / 2);
        curs_set (0);
	getch();                      
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

