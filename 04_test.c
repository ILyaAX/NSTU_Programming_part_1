#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    const int width = 16;
    const int height = 3;

    if (!initscr())
    {
        fprintf(stderr, "Error initialising ncurses.\n");
        exit(1);
    }

    initscr();
    curs_set(0);
    refresh();

    int offsetx = (COLS - width) / 2;
    int offsety = (LINES - height) / 2;

    WINDOW *win = newwin(height, width, offsety, offsetx);

    char hello[] = "Hello, world!";

    mvaddstr(LINES/2, (COLS-strlen(hello))/2, hello);
    box(win, 0, 0);

    wrefresh(win);
    mvprintw (5, 5, "COLS = %d,    LINES = %d", COLS, LINES);
    refresh ();
    getch();

    delwin(win);
    endwin();
}


