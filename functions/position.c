#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <locale.h>



int main() {
	
	setlocale (LC_ALL, "ru_RU.UTF-8");

	
	
			//--------------- Сообщения
	char mes [] = "Русский текст";
	
	int arr [] = {1, 2, 3 , 4};
	
			//--------------- Инициализация режима ncurses
        initscr();
        curs_set (0);   		  // Курсор невидимый
        
			//--------------- Инициализация цветовых пар
	start_color();  		  // Запуск цветового режима
        init_pair(1, COLOR_CYAN, COLOR_BLACK);
        init_pair(2, COLOR_GREEN, COLOR_RED);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_YELLOW);
	

	int row, col;			// row - строки, col - столбцы
	getmaxyx (stdscr, row, col);	// Получаем размеры экрана
	
	attron(COLOR_PAIR(1)); 		// Установка базовой пары
        for (int i = 0; i < 4; i++) {
		attron (COLOR_PAIR (i + 1));
		mvprintw (row/2, 40 + i * 4, "%4d", arr [i]);
		refresh ();
		usleep (500000);
	}
	attron (COLOR_PAIR (1));
	mvprintw (row / 2 + 1, (col - strlen (mes)) / 2, "%s", mes);
	usleep (1000000);
        getch();
        
			//--------------- Завершение режима ncurses
	endwin();

        return 0;
}


