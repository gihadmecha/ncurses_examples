
#include <ncurses.h>			/* ncurses.h includes stdio.h */  
#include <string.h> 

int main()
{
	char mesg[]="Enter a string: ";
	char str[80];
	int row,col;				/* to store the number of rows and */

	initscr();				/* start the curses mode */

	getmaxyx(stdscr,row,col);		/* get the number of rows and columns */

	//(int) getstr (char *);
	getstr(str);

	//(int) wgetstr (WINDOW *, char *);
	wgetstr (stdscr, str);

	//(int) scanw (const char *,...)GCC_SCANFLIKE(1,2);
	scanw("%s", str);

	//(int) mvscanw (int,int, const char *,...)GCC_SCANFLIKE(3,4);
	mvscanw(9, 9, "%s", str);

	//(int) wscanw (WINDOW *, const char *,...)GCC_SCANFLIKE(2,3);
	wscanw(stdscr, str);

	//(int) mvwscanw (WINDOW *,int,int, const char *,...)GCC_SCANFLIKE(4,5);
	mvwscanw(stdscr, 5, 10, "%s", str);

	//(int) vwscanw (WINDOW *, const char *,va_list) GCC_DEPRECATED(use vw_scanw);
	//vwscanw (WINDOW *, const char *,va_list) GCC_DEPRECATED(use vw_scanw);

	mvprintw(row/2,(col-strlen(mesg))/2,"%s",mesg);     /* print the message at the center of the screen */
	mvprintw(LINES - 5, 0, "You Entered: %s", str);

	getch();

 	endwin();
	
	return 0;
}