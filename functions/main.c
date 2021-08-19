#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <locale.h>
#include "stdlib.h"
#include <time.h>

			//-------------------------- Функции
int init_array (int A[], int n, int col);
void print_array (int A[], int n, int row, int col);

int main() {
	
	setlocale (LC_ALL, "ru_RU.UTF-8"); //Локаль для кириллицы

			//-------------------------- Сообщения
	char mes01 [] = "Введите разумное количество элементов в массиве = ";
	char mes02 [] = "С таким раззмером окна и количеством элементов ничего не поместится...";
			//--------------- Инициализация режима ncurses
        initscr();
        curs_set (0);   		  // Курсор невидимый
        
			//--------------- Инициализация цветовых пар
	start_color();  		  // Запуск цветового режима
        init_pair(1, COLOR_CYAN, COLOR_BLACK);
        init_pair(2, COLOR_GREEN, COLOR_RED);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_YELLOW);
	attron(COLOR_PAIR(1));          // Установка базовой пары

	int row, col;			// row - строки, col - столбцы
	getmaxyx (stdscr, row, col);	// Получаем размеры экрана row x col
	
        int n;
        int arr [n];
	int ok_init = 0;
	do {
		curs_set (1);
		if (ok_init) mvprintw (9, 10, mes02);
		mvprintw (10, 10, mes01);
		scanw ("%d", &n);
		ok_init = init_array (arr, n, col);
	}  while (ok_init);
	curs_set (0);
	clear ();
	print_array (arr, n, row / 2, (col - n * 4) / 2);	
	
	getch();
        
			//--------------- Завершение режима ncurses
	endwin();

        return 0;
}

int init_array (int A[], int n, int col) {
	if (n > col / 4) return 1;
	srand (time(NULL)); 
    	for (int i = 0; i < n; i++) {
        	A[i] = rand() % 1000;
    	}
	return 0;
}

void print_array (int A[], int n, int row, int col) {
	for (int i = 0; i < n; i++) {
                mvprintw (row, col + i * 4, "%4d", A [i]);
                refresh ();
                usleep (100000);
        }
}
