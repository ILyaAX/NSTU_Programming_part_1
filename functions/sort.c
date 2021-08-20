#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <locale.h>
#include "stdlib.h"
#include <time.h>

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
        init_pair(2, COLOR_GREEN, COLOR_RED);
        init_pair(3, COLOR_YELLOW, COLOR_BLACK);
        init_pair(4, COLOR_GREEN, COLOR_YELLOW);
        attron(COLOR_PAIR(1));          // Установка базовой пары

        int n;
        int arr [n];
	mvprintw (10, 10, "Введите количество элементов в массиве = ");
	scanw ("%d", &n);
       	init_array (arr, n); 
	clear ();
	print_array (arr, n, LINES / 2, (COLS - n * 4) / 2);
	usleep (5000000);
	sorting_choice (arr, n);
	clear ();
        print_array (arr, n, LINES / 2, (COLS - n * 4) / 2);

        getch();

                        //--------------- Завершение режима ncurses
        endwin();

        return 0;
}

void sorting_choice(int A[], int n) {
	for (int i = 0; i < n; i++) {
        	int i_min = i;
        	int j;
		int col_zero = (COLS - n * 4) / 2;
		int row_zero = LINES / 2;
        	for (j = i; j < n; j++) {
            		attron(COLOR_PAIR(3));
			mvprintw (row_zero, col_zero + i_min * 4, "    ");
			mvprintw (row_zero - 2, col_zero + i_min * 4, "%4d", A [i_min]);
			refresh ();
			usleep (500000);
			mvprintw (row_zero, col_zero + j * 4, "    ");
                        mvprintw (row_zero - 2, col_zero + j * 4, "%4d", A [j]);
                        refresh ();
                        usleep (500000);
			if (A [j] < A [i_min]) {
	    			i_min = j;
			}		
			else {
			
			}
	    
	    	}	
        	int tmp = A[i_min];
        	for (j = i_min; j > i - 1; j--) {
           	A[j] = A[j - 1];
        	}
        	A[i] = tmp;
    	}
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
                usleep (90000);
        }
}

