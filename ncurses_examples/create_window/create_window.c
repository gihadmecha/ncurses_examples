#include <ncurses.h>

#define NLINES 10
#define NCOLS 40

//(int) delwin (WINDOW *);

int main(int argc, char const *argv[])
{
	WINDOW* wins[3];

	initscr();			/* Start curses mode 		*/
	start_color();

	/* Initialize all the colors */
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);


	int height = 3;
	int width = 10;
	int starty = (LINES - height) / 2;	/* Calculating for a center placement */
	int startx = (COLS - width) / 2;	/* of the window		*/
	int ch;

	int y = 2;
	int x = 10;
	char label[80];
	int label_x = 1;
	int label_y = 12;

	/* Show it on the screen */
	attron(COLOR_PAIR(4));
	mvprintw(LINES - 2, 0, "Use tab to browse through the windows (F1 to Exit)");
	attroff(COLOR_PAIR(4));


	//(WINDOW *) newwin (int,int,int,int);
	WINDOW* local_win = newwin(height, width, starty, startx);

	for(int i = 0; i < 3 ; ++i){
		wins[i] = newwin(NLINES, NCOLS, y, x);
		wattron(wins[i], COLOR_PAIR(i+1));
		mvwprintw(wins[i], label_x, label_y, "Window Number %d", i + 1);
		wattroff(wins[i], COLOR_PAIR(i+1));
		refresh();
		box(wins[i], 0, 0);
		mvwaddch(wins[i], 2, 0, ACS_LTEE); 
		mvwhline(wins[i], 2, 1, ACS_HLINE, NCOLS - 2); 
		mvwaddch(wins[i], 2, NCOLS - 1, ACS_RTEE); 
		wrefresh(wins[i]);
		y += 3;
		x += 7;

	}	
	//#define box(win, v, h)		wborder(win, v, v, h, h, 0, 0, 0, 0)
	box(local_win, 0, 0);


	//(int) wrefresh (WINDOW *);
	wrefresh(local_win);		/* Show that box 		*/

	
	
	//(int) wborder (WINDOW *,chtype,chtype,chtype,chtype,chtype,chtype,chtype,chtype);
	//wborder(local_win, ',', ',', ',', ',', ',', ',', ',', ',');
	//wborder(local_win, '|', '|', '-', '-', '+', '+', '+', '+');
	//wrefresh(local_win);
	////(int) delwin (WINDOW *);
	//delwin(local_win);	

	getch();
	endwin();			/* End curses mode		  */
	return 0;
}

