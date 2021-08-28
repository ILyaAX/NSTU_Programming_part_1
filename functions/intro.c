#include <ncurses.h>
#include <unistd.h>
#include <locale.h>
#include "stdlib.h"
#include <time.h>

#define TIME 330000	    // Отвечает за скорость анимации
#define SHIFT_ROW -4	// Смещение от центра экрана печати массива
                       
			        //-------------------------- Функции
void init_array (int A[], int n);
void print_array (int A[], int n, int row, int col);
void sorting_choice(int A[], int n);
void intro ();

int main() {

    setlocale (LC_ALL, "ru_RU.UTF-8"); //Локаль для кириллицы

                    //--------------- Инициализация режима ncurses
    initscr();
    curs_set (0);                     // Курсор невидимый

                    //--------------- Инициализация цветовых пар
    start_color();                    // Запуск цветового режима
    init_pair (1, COLOR_CYAN, COLOR_BLACK);
    init_pair (2, COLOR_GREEN, COLOR_BLACK);
    init_pair (3, COLOR_YELLOW, COLOR_BLACK);
    init_pair (4, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(1));          // Установка базовой пары
    
    intro ();

	mvprintw (LINES / 2 + SHIFT_ROW, 10, "Введите количество элементов в массиве = ");
	int n;	
	scanw ("%d", &n);
	clear ();
	int arr [n];
	init_array (arr, n); 
	print_array (arr, n, LINES / 2 + SHIFT_ROW, (COLS - n * 4) / 2);

			//---------------- Создание окна счетчиков
    WINDOW *win_counters = newwin (7, 40, LINES / 2, (COLS - 38) / 2);
    wattron(win_counters, COLOR_PAIR(1));
    box (win_counters, 0, 0);
    wrefresh (win_counters);

	usleep (TIME * 2);
	sorting_choice (arr, n);
	attron (COLOR_PAIR(1));
	mvprintw (LINES / 2 + SHIFT_ROW - 4, (COLS - 17) / 2, "Массив отсортирован");
	refresh ();
	usleep (TIME * 3);
	attron (COLOR_PAIR(1) | A_BLINK);
	mvprintw (LINES - 3, COLS - 45, "Для выхода нажмите любую клавишу >>> ");
    getch();
	delwin(win_counters);
                        //--------------- Завершение режима ncurses
    endwin();

    return 0;
}

void sorting_choice(int A[], int n) {
	int comparisons = 0;
	int shifts = 0;
	int col_zero = (COLS - n * 4) / 2;
    int row_zero = LINES / 2 + SHIFT_ROW;
	for (int i = 0; i < n - 1; i++) {
        int i_min = i;
        int j;
        for (j = i + 1; j < n; j++) {
			comparisons++;
			attron (COLOR_PAIR(3));
			attron (A_BOLD);
			mvprintw (row_zero, col_zero + i_min * 4, "    ");
			mvprintw (row_zero - 2, col_zero + i_min * 4, "%4d", A [i_min]);
			attron (COLOR_PAIR(1));
			attroff(A_BOLD);
			mvprintw (LINES / 2 + 2, (COLS - 30) / 2, "Количество сравнений = %d", comparisons);
			refresh ();
			usleep (TIME);
			attron (A_BOLD);
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
           	shifts++;
			attroff (A_BOLD);
			mvprintw (LINES / 2 + 4, (COLS - 30) / 2, "Количество сдвигов = %d", shifts);	
			mvprintw (row_zero, col_zero + (j - 1) * 4, "    ");
			usleep (TIME);
            attron (A_BOLD);
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
		shifts++;
        attroff (A_BOLD);
		mvprintw (LINES / 2 + 4, (COLS - 30) / 2, "Количество сдвигов = %d", shifts);
    }
	attron (COLOR_PAIR(2));
	attron (A_BOLD);
	mvprintw (row_zero, col_zero + (n - 1) * 4, "%4d", A [n - 1]);
	attroff (A_BOLD);
	refresh ();
}

void init_array (int A[], int n) {
    srand (time(NULL));     // Инициализирует массив случайными числами от 0 до 99
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 100;
    }
}

void print_array (int A[], int n, int row, int col) {
    attron (A_BOLD);        // Выводит на экран с задержкой значения массива
    for (int i = 0; i < n; i++) {
        mvprintw (row, col + i * 4, "%4d", A [i]);
        refresh ();
        usleep (TIME / 8);
    }
	attroff (A_BOLD);
}

void intro (){
    char *mes[10];           // Начальный экран с текстом
    mes [0] = "    Эта программа с помощью  библиотеки ncurses, управляющей  свойствами";
    mes [1] = "вывода терминала  анимирует действия  выполняемые  над  массивом  чисел.";
    mes [2] = "    Вам  будет  предложено выбрать  размерность  массива,  который затем";
    mes [3] = "будет заполнен случайными числами  и  упорядочен  при  помощи  алгоритма";
    mes [4] = "сортировки выбором.";
    mes [5] = " ";
    mes [6] = "    Алгоритм  сортировки:"; 
    mes [7] = "Выбирается минимальный элемент в массиве и запоминается. Все последующие";
    mes [8] = "за  ним  элементы  сдвигаются  на  один вправо. Сам элемент заносится на";
    mes [9] = "освободившуюся позицию.";
    WINDOW *intro;
    intro = newwin (LINES - 6, COLS - 10, 3, 5);
    wattron(intro, COLOR_PAIR(1));
    box (intro, 0, 0);
    wrefresh (intro);
    int lines_intro = getmaxy (intro);
    int cols_intro = getmaxx (intro);
    for (int i = 0; i < 10; i++) {
        if (i == 6) {           // вывод другим цветом 6-й строки
            wattron (intro, COLOR_PAIR(4));
            mvwprintw (intro, lines_intro / 2 - 5 + i, (cols_intro - 72) / 2, mes [i]);
            wrefresh (intro);
            usleep (TIME);
            wattron (intro, COLOR_PAIR(1));
        }
        else {  
            mvwprintw (intro, lines_intro / 2 - 5 + i, (cols_intro - 72) / 2, mes [i]);
            wrefresh (intro);
            usleep (TIME);
        }
    }
    usleep (TIME * 3);
    wattron (intro, A_BLINK);
    mvwprintw (intro, lines_intro - 3, cols_intro - 45, "Для продолжения нажмите любую клавишу >>>");
    wrefresh (intro);
    wattroff (intro, A_BLINK);
    wgetch (intro);
    delwin (intro);
}
