#include <ncurses.h>			/* ncurses.h includes stdio.h */  
#include <string.h> 

int main()
{
	char mesg[] = "just string";
	int row, col;
	unsigned int ch = 50;

	initscr();				/* start the curses mode */

	//(int) addch (const chtype);
	addch (ch | A_BOLD | A_UNDERLINE);

	//(int) move (int, int);
	move (5, 4);           /* moves the cursor to rowth row and colth column */
	addch (55);

	//(int) mvaddch (int, int, const chtype);
	mvaddch (10, 11, 63);

	//(int) waddch (WINDOW *, const chtype);
	waddch (stdscr, 65);

	//#define mvwaddch(win,y,x,ch)		(wmove((win),(y),(x)) == ERR ? ERR : waddch((win),(ch)))
	mvwaddch(stdscr, 2, 5, 33);		

	attron(A_BOLD);
	addch (67);
	addch (67);
	addch (67);
	attroff(A_BOLD);

	//(int) attrset (NCURSES_ATTR_T);
	attrset (A_UNDERLINE);
	mvaddch (11, 11, 68);
	mvaddch (11, 12, 69);
	mvaddch (11, 13, 70);
	mvaddch (11, 14, 71);
	mvaddch (11, 15, 72);
	attroff(A_UNDERLINE);

	addch (ACS_PI);
	addch (ACS_ULCORNER);
	addch(ACS_RARROW);
	addch(ACS_BSBS);

	//#define getmaxyx(win,y,x)	(y = getmaxy(win), x = getmaxx(win))
	//(int) getmaxx (const WINDOW *);
	//(int) getmaxy (const WINDOW *);
	getmaxyx(stdscr, row, col);  /* get the number of rows and columns */

	//(int) mvprintw (int,int, const char *,...) GCC_PRINTFLIKE(3,4);
	mvprintw(row/2,(col-strlen(mesg))/2,"%s",mesg);       /* print the message at the center of the screen */
 	mvprintw(row-3,0,"This screen has %d rows and %d columns\n",row,col);

 	printw("Try resizing your window(if possible) and then run this program again");
    
    move(9,11);
    printw("this(9, 11)position");

    //(int) wprintw (WINDOW *, const char *,...) GCC_PRINTFLIKE(2,3);
    wprintw(stdscr, "    wprintw_test");

    //extern NCURSES_EXPORT(int) mvwprintw (WINDOW*,int,int, const char *,...) GCC_PRINTFLIKE(4,5);
    mvwprintw(stdscr, 20, 20, "specific coordinate at specific window");

    //(int) vwprintw (WINDOW *, const char *,va_list) GCC_DEPRECATED(use vw_printw);
    //vw_printw(stdscr, "       vwprintw_test", 4);

    //(int) addstr (const char *);
    addstr ("       addstr_test");

    //(int) mvaddstr (int, int, const char *);
    mvaddstr (8, 9, "mvaddstr_test");

    //(int) mvwaddstr (WINDOW *, int, int, const char *);
    mvwaddstr (stdscr, 6, 5, "mvwaddstr");

    //(int) waddstr (WINDOW *,const char *);
    waddstr (stdscr,"     waddstr_test");

    //(int) addnstr (const char *, int);
    addnstr ("   addnstr", 7);

 	//refresh();
 
 	getch();

 	endwin();

	return 0;
}