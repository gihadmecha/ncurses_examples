#include <ncurses.h>

int main(int argc, char const *argv[])
{
	initscr();			/* Start curses mode 		  */
	printw("Hello World !!!\n");	/* Print Hello World		  */
	refresh();			/* Print it on to the real screen */

	//(int) def_prog_mode (void);
	def_prog_mode();                   /* Save the tty modes		  */
	endwin();							/* End curses mode temporarily	  */
	system("/bin/sh");		/* Do whatever you like in cooked mode */
	//(int) reset_prog_mode (void);
	reset_prog_mode();                 /* Return to the previous tty mode*/
										/* stored by def_prog_mode() 	  */
	refresh();							/* Do refresh() to restore the	  */
										/* Screen contents		  */
	printw("Another String\n");	/* Back to curses use the full    */
	refresh();			/* capabilities of curses	  */
	endwin();			/* End curses mode		  */
	return 0;
}