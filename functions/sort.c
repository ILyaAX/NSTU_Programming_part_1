#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <locale.h>
#include "stdlib.h"
#include <time.h>

#define TIME 330000
#define SHIFT_ROW -7
                        //-------------------------- Функции
int init_array (int A[], int n);
void print_array (int A[], int n, int row, int col);
void sorting_choice(int A[], int n);

int main() {

        setlocale (LC_ALL, "ru_RU.UTF-8"); //Локаль для кириллицы

                        //--------------- Инициализация режима ncurses
        initscr();
        curs_set (0);                     // Курсор невидимый

                        //--------------- Инициализация цветовых пар
        start_color();                    // Запуск цветового режима
        init_pair(1, COLOR_CYAN, COLOR_BLACK);
        init_pair(2, COLOR_GREEN, COLOR_BLACK);
        init_pair(3, COLOR_YELLOW, COLOR_BLACK);
        init_pair(4, COLOR_RED, COLOR_BLACK);
        attron(COLOR_PAIR(1));          // Установка базовой пары

        int n;
        int arr [n];
	mvprintw (LINES / 2 + SHIFT_ROW, 10, "Введите количество элементов в массиве = ");
	scanw ("%d", &n);
       	init_array (arr, n); 
	clear ();
	print_array (arr, n, LINES / 2 + SHIFT_ROW, (COLS - n * 4) / 2);
	usleep (TIME * 5);
	sorting_choice (arr, n);
	attron (COLOR_PAIR(1));
	mvprintw (LINES / 2 + SHIFT_ROW - 4, (COLS - 17) / 2, "Массив отсортирован");
	refresh ();
	usleep (TIME * 5);
	mvprintw (LINES - 3, COLS - 45, "Для выхода нажмите любую клавишу >>> ");
        getch();

                        //--------------- Завершение режима ncurses
        endwin();

        return 0;
}

void sorting_choice(int A[], int n) {
	int col_zero = (COLS - n * 4) / 2;
        int row_zero = LINES / 2 + SHIFT_ROW;
	for (int i = 0; i < n - 1; i++) {
        	int i_min = i;
        	int j;
        	for (j = i + 1; j < n; j++) {
			attron (COLOR_PAIR(3));
			mvprintw (row_zero, col_zero + i_min * 4, "    ");
			mvprintw (row_zero - 2, col_zero + i_min * 4, "%4d", A [i_min]);
			refresh ();
			attron (COLOR_PAIR(1));
			usleep (TIME);
			mvprintw (row_zero, col_zero + j * 4, "    ");
                        mvprintw (row_zero - 2, col_zero + j * 4, "%4d", A [j]);
                        refresh ();
                        usleep (TIME);
			if (A [j] < A [i_min]) {
	    			mvprintw (row_zero, col_zero + i_min * 4, "%4d", A [i_min]);
				mvprintw (row_zero - 2, col_zero + i_min * 4, "    ");
				refresh ();
				i_min = j;
				attron (COLOR_PAIR(3));
				mvprintw (row_zero - 2, col_zero + i_min * 4, "%4d", A [i_min]);
				mvprintw (row_zero, col_zero + i_min * 4, "    ");
                                refresh ();
				attron (COLOR_PAIR(1));
			}		
			else {
				mvprintw (row_zero - 2, col_zero + j * 4, "    ");
                        	mvprintw (row_zero, col_zero + j * 4, "%4d", A [j]);
				refresh ();
				usleep (TIME);
			}
	    
	    	}	
        	int tmp = A[i_min];
        	for (j = i_min; j > i; j--) {
           	
			mvprintw (row_zero, col_zero + (j - 1) * 4, "    ");
			usleep (TIME);
                        mvprintw (row_zero, col_zero + j  * 4, "%4d", A [j - 1]);
                        refresh ();
                        usleep (TIME);
			A[j] = A[j - 1];

        	}
        	attron (COLOR_PAIR(2));
		for (int k = i_min * 4; k > i * 4; k--)	{
			mvprintw (row_zero - 2, col_zero + k, "%4d    ", tmp);
                        refresh ();
			usleep (TIME / 4);
		}
		
		mvprintw (row_zero - 2, col_zero + i * 4, "      ");
		refresh ();
                mvprintw (row_zero, col_zero + i * 4, "%4d", tmp);
                refresh ();
                usleep (TIME);
		A[i] = tmp;
		attron (COLOR_PAIR(1));
    	}
	attron (COLOR_PAIR(2));
	mvprintw (row_zero, col_zero + (n - 1) * 4, "%4d", A [n - 1]);
	refresh ();
}


int init_array (int A[], int n) {
        srand (time(NULL));
        for (int i = 0; i < n; i++) {
                A[i] = rand() % 100;
        }
        return 0;
}

void print_array (int A[], int n, int row, int col) {
        for (int i = 0; i < n; i++) {
                mvprintw (row, col + i * 4, "%4d", A [i]);
                refresh ();
                usleep (TIME / 4);
        }
}

