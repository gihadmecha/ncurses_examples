#include <ncurses.h>


//(int) delwin (WINDOW *);

int main(int argc, char const *argv[])
{
	initscr();			/* Start curses mode 		*/
	keypad(stdscr, TRUE);		/* I need that nifty F1 	*/

	int height = 3;
	int width = 10;
	int starty = (LINES - height) / 2;	/* Calculating for a center placement */
	int startx = (COLS - width) / 2;	/* of the window		*/
	int ch;

	printw("Press F1 to exit");
	refresh();

	//(WINDOW *) newwin (int,int,int,int);
	WINDOW* local_win = newwin(height, width, starty, startx);
	//#define box(win, v, h)		wborder(win, v, v, h, h, 0, 0, 0, 0)
	box(local_win, 0, 0);
	//(int) wrefresh (WINDOW *);
	wrefresh(local_win);		/* Show that box 		*/
	



	while((ch = getch()) != KEY_F(1))
	{	switch(ch)
		{	case KEY_LEFT:
				wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
				wrefresh(local_win);
				delwin(local_win);
				//(WINDOW *) newwin (int,int,int,int);
				local_win = newwin(height, width, starty, --startx);
				//#define box(win, v, h)		wborder(win, v, v, h, h, 0, 0, 0, 0)
				box(local_win, 0, 0);
				//(int) wrefresh (WINDOW *);
				wrefresh(local_win);		/* Show that box 		*/
				break;
			case KEY_RIGHT:
				wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
				wrefresh(local_win);
				delwin(local_win);
				//(WINDOW *) newwin (int,int,int,int);
				local_win = newwin(height, width, starty, ++startx);
				//#define box(win, v, h)		wborder(win, v, v, h, h, 0, 0, 0, 0)
				box(local_win, 0, 0);
				//(int) wrefresh (WINDOW *);
				wrefresh(local_win);		/* Show that box 		*/
				break;
			case KEY_UP:
				wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
				wrefresh(local_win);
				delwin(local_win);
				//(WINDOW *) newwin (int,int,int,int);
				local_win = newwin(height, width, --starty, startx);
				//#define box(win, v, h)		wborder(win, v, v, h, h, 0, 0, 0, 0)
				box(local_win, 0, 0);
				//(int) wrefresh (WINDOW *);
				wrefresh(local_win);		/* Show that box 		*/
				break;
			case KEY_DOWN:
				wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
				wrefresh(local_win);
				delwin(local_win);
				//(WINDOW *) newwin (int,int,int,int);
				local_win = newwin(height, width, ++starty, startx);
				//#define box(win, v, h)		wborder(win, v, v, h, h, 0, 0, 0, 0)
				box(local_win, 0, 0);
				//(int) wrefresh (WINDOW *);
				wrefresh(local_win);		/* Show that box 		*/
				break;	
		}
	}
	//(int) wborder (WINDOW *,chtype,chtype,chtype,chtype,chtype,chtype,chtype,chtype);
	//wborder(local_win, ',', ',', ',', ',', ',', ',', ',', ',');
	//wborder(local_win, '|', '|', '-', '-', '+', '+', '+', '+');
	//wrefresh(local_win);
	////(int) delwin (WINDOW *);
	//delwin(local_win);	


	endwin();			/* End curses mode		  */
	return 0;
}

