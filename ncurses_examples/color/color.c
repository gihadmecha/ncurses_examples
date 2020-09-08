#include <ncurses.h>
#include <stdlib.h>
#include <string.h>




void print_in_middle(WINDOW* win, int starty, int startx, int width, char* string);

int main(int argc, char const *argv[])
{
	initscr();			/* Start curses mode 		*/

	//(bool) has_colors (void);
	if(has_colors() == FALSE)
	{	endwin();
		printf("Your terminal does not support color\n");
		//exit(1);
	}

	start_color();			/* Start color 			*/

	/*
	 	COLOR_BLACK   0
        COLOR_RED     1
        COLOR_GREEN   2
        COLOR_YELLOW  3
        COLOR_BLUE    4
        COLOR_MAGENTA 5
        COLOR_CYAN    6
        COLOR_WHITE   7
	*/
	init_pair(1, COLOR_RED, COLOR_BLACK);



	attron(COLOR_PAIR(1));
	print_in_middle(stdscr, LINES / 2, 0, 0, "Viola !!! In color ...");
	attroff(COLOR_PAIR(1));

	//rgb
	//(int) init_color (NCURSES_COLOR_T,NCURSES_COLOR_T,NCURSES_COLOR_T,NCURSES_COLOR_T);
	//init_color (COLOR_RED, 700, 0, 0);  

	//(bool) can_change_color (void);
	
	//(int) color_content (NCURSES_COLOR_T,NCURSES_COLOR_T*,NCURSES_COLOR_T*,NCURSES_COLOR_T*);

	//(int) pair_content (NCURSES_PAIRS_T,NCURSES_COLOR_T*,NCURSES_COLOR_T*);

	getch();
	endwin();
	return 0;
}


void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string)
{	int length, x, y;
	float temp;

	if(win == NULL)
		win = stdscr;
	getyx(win, y, x);
	if(startx != 0)
		x = startx;
	if(starty != 0)
		y = starty;
	if(width == 0)
		width = 80;

	length = strlen(string);
	temp = (width - length)/ 2;
	x = startx + (int)temp;
	mvwprintw(win, y, x, "%s", string);
	refresh();
}
