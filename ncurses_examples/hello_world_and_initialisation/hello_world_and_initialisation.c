#include <ncurses.h>

int main()
{	int ch;

	//(WINDOW *) initscr (void);
	initscr();			/* Start curses mode 		  */
	//(int) noecho (void);
	noecho();			/* Don't echo() while we do getch */
	//(int) keypad (WINDOW *,bool);
	keypad(stdscr, TRUE);		/* We get F1, F2 etc..		*/

	////(int) printw (const char *,...)
   	printw("Hello World !!!\n");	/* Print Hello World		  */
   	//(int) refresh (void);
   	//refresh();			/* Print it on to the real screen */

   	//(int) getch (void);
	getch();			/* Wait for user input */

	printw("\nType any character to see it in bold\n");
	printw("The pressed key is ");
	//(int) attron (NCURSES_ATTR_T);
	attron(A_BOLD);
	ch = getch();
	printw("%c", ch);
	//(int) attroff (NCURSES_ATTR_T);
	attroff(A_BOLD);
	//refresh();
	
	getch();			/* Wait for user input */


   	//(int) endwin (void);
   	endwin();			/* End curses mode		  */
   	return 0;
}