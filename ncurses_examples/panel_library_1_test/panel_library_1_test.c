
#include <panel.h>

int main()
{	WINDOW* my_wins[3];
	WINDOW* old_win;
	PANEL* my_panels[3];
	PANEL* top;

	int lines = 10, cols = 40, y = 2, x = 4, i;
	int ch;


	int height = 3;
	int width = 10;
	int starty = (LINES - height) / 2;	/* Calculating for a center placement */
	int startx = (COLS - width) / 2;	/* of the window		*/

	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);

	/* Create windows for the panels */
	my_wins[0] = newwin(lines, cols, y, x);
	my_wins[1] = newwin(lines, cols, y + 1, x + 5);
	my_wins[2] = newwin(lines, cols, y + 2, x + 10);

	/* 
	 * Create borders around the windows so that you can see the effect
	 * of panels
	 */
	for(i = 0; i < 3; ++i)
		box(my_wins[i], 0, 0);

	/* Attach a panel to each window */ 	/* Order is bottom up */
	my_panels[0] = new_panel(my_wins[0]); 	/* Push 0, order: stdscr-0 */
	my_panels[1] = new_panel(my_wins[1]); 	/* Push 1, order: stdscr-0-1 */
	my_panels[2] = new_panel(my_wins[2]); 	/* Push 2, order: stdscr-0-1-2 */

	/* Set up the user pointers to the next panel */
	set_panel_userptr(my_panels[0], my_panels[1]);
	set_panel_userptr(my_panels[1], my_panels[2]);
	set_panel_userptr(my_panels[2], my_panels[0]);


	/* Update the stacking order. 2nd panel will be on top */
	update_panels();

	/* Show it on the screen */
	doupdate();

	top = my_panels[2];

	while((ch = getch()) != KEY_F(1))
	{	switch(ch)
		{	case 9:
				//(NCURSES_CONST void*) panel_userptr (const PANEL *);
				top = (PANEL *)panel_userptr(top);
				//(int)     top_panel (PANEL *);
				top_panel(top);
				break;
			case KEY_LEFT:
				//(WINDOW*) panel_window (const PANEL *);
				old_win = panel_window (top);
				WINDOW* local_win = newwin(height, width, starty, startx);
				//(int)     replace_panel (PANEL *,WINDOW *);
				replace_panel (top,local_win);
				box(local_win, 0, 0);
				wrefresh(local_win);
					//delwin(old_win);
				break;
			case KEY_RIGHT:
				//(int)     move_panel (PANEL *, int, int);
				move_panel (top, starty, startx);
				break;
			case 'a':
				//(int)     hide_panel (PANEL *);
				hide_panel(my_panels[0]);
				break;
			case 'b':
				//(int)     show_panel (PANEL *);
				show_panel(my_panels[0]);
				break;
			case 'c':
				//(PANEL*)  panel_above (const PANEL *);
				panel_above (top);
				break;
			case 'd':
				//(PANEL*)  panel_below (const PANEL *);
				panel_below (top);
				break;
		}
		update_panels();
		doupdate();
	}
	

	endwin();
}