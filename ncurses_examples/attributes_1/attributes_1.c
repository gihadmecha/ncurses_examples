#include <ncurses.h>

int main()
{	initscr();
	//(int) start_color (void);
	start_color();			/* Start color functionality	*/

	//(int) init_pair (NCURSES_PAIRS_T,NCURSES_COLOR_T,NCURSES_COLOR_T);
	init_pair(1, COLOR_BLUE, COLOR_YELLOW);

	printw("A Big string which i didn't care to type fully \n");

	//(int) mvchgat (int, int, int, attr_t, NCURSES_PAIRS_T, const void *);
	/* 
	 * First two parameters specify the position at which to start 
	 * Third parameter number of characters to update. -1 means till 
	 * end of line
	 * Forth parameter is the normal attribute you wanted to give 
	 * to the charcter
	 * Fifth is the color index. It is the index given during init_pair()
	 * use 0 if you didn't want color
	 * Sixth one is always NULL 
	 */
	mvchgat(1, 0, -1, A_BLINK, 1, NULL);

	//(int) chgat (int, attr_t, NCURSES_PAIRS_T, const void *);
	//chgat(-1, A_REVERSE, 0, NULL);
	//(int) mvchgat (int, int, int, attr_t, NCURSES_PAIRS_T, const void *);
	//(int) mvwchgat (WINDOW *, int, int, int, attr_t, NCURSES_PAIRS_T, const void *);
	//(int) wchgat (WINDOW *, int, attr_t, NCURSES_PAIRS_T, const void *);

	
	//(int) attr_get (attr_t *, NCURSES_PAIRS_T *, void *);	
	//attr_get (attr_t *, NCURSES_PAIRS_T *, NULL);

	//(int) wattr_get (WINDOW *, attr_t *, NCURSES_PAIRS_T *, void *);
	//wattr_get (stdscr, attr_t *, NCURSES_PAIRS_T *, NULL);	


	attron(A_REVERSE);
	addstr ("A_REVERSE\n");
	attroff(A_REVERSE);

	attron(A_BLINK );
	addstr ("A_BLINK \n");
	attroff(A_BLINK);

	attron(A_BOLD);
	addstr ("A_BOLD\n");
	attroff(A_BOLD);

	attron(A_PROTECT);
	addstr ("A_PROTECT\n");
	attroff(A_PROTECT);

	attron(A_INVIS);
	addstr ("A_INVIS\n");
	attroff(A_INVIS);

	attron(A_ALTCHARSET );
	addstr ("A_ALTCHARSET \n");
	attroff(A_ALTCHARSET);

	attron(A_CHARTEXT );
	addstr ("A_CHARTEXT \n");
	attroff(A_CHARTEXT );

	attron(COLOR_PAIR(2));
	addstr ("COLOR_PAIR(2)\n");
	attroff(COLOR_PAIR(2));

	attrset (A_UNDERLINE);
	addstr ("A_UNDERLINE\n");
	attroff(A_UNDERLINE);

	//(int) standend (void);
	standend();
	addstr ("A_NORMAL\n");

	//(int) wattron (WINDOW *, int);
	wattron (stdscr, A_STANDOUT);
	addstr ("A_STANDOUT\n");			
	//(int) wattroff (WINDOW *, int);
	wattroff (stdscr, A_STANDOUT);	
			
	//(int) wattrset (WINDOW *, int);
	wattrset (stdscr, A_DIM);
	addstr ("A_DIM\n");

	//(int) attr_on (attr_t, void *);	
	attr_on (A_BLINK, NULL);	
	addstr ("attr_on\n");

	//(int) attr_off (attr_t, void *);	
	(int) attr_off (A_BLINK, NULL);

	//(int) attr_set (attr_t, NCURSES_PAIRS_T, void *);	
	attr_set (A_REVERSE, 1, NULL);	
	addstr ("attr_set\n");

	//(int) wattr_on (WINDOW *, attr_t, void *);
	wattr_on (stdscr, A_BOLD, NULL);
	addstr ("wattr_on\n");	

	//(int) wattr_off (WINDOW *, attr_t, void *);	
	wattr_off (stdscr, A_REVERSE, NULL);
	addstr ("stop_A_REVERSE\n");
    
    //(int) wattr_set (WINDOW *, attr_t, NCURSES_PAIRS_T, void *);	
    wattr_set (stdscr, A_NORMAL, 1, NULL);
    addstr ("stop_A_BOLD\n");

	getch();
	endwin(); 
	return 0;
}