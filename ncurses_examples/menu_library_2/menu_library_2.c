#include <curses.h>
#include <menu.h>
#include <stdlib.h>
#include <string.h>



#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

char *choices[] = {
                        "Choice 1",
                        "Choice 2",
                        "Choice 3",
                        "Choice 4",
                        "Exit",
                  };


void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color);

int main()
{	
	int c;
	ITEM** my_items;
	int n_choices;
	MENU *my_menu;
	WINDOW *my_menu_win;

	//initialize curser
	initscr();
	keypad(stdscr, TRUE);
	start_color();

	init_pair(1, COLOR_RED, COLOR_BLACK);

	//create items
	n_choices = ARRAY_SIZE(choices);

	my_items = (ITEM**)calloc(n_choices + 1, sizeof(ITEM *));

	for(int i = 0; i < n_choices; ++i)
	//(ITEM *)	new_item (const char *,const char *);
		my_items[i] = new_item(choices[i], choices[i]);

	//create window
	//(MENU *)	new_menu (ITEM **);
	my_menu = new_menu((ITEM **)my_items);


	/* Create the window to be associated with the menu */
        my_menu_win = newwin(10, 40, 4, 4);
       // keypad(my_menu_win, TRUE);
     
	/* Set main window and sub window */
        //(int)	set_menu_win (MENU *,WINDOW *);
        set_menu_win(my_menu, my_menu_win);
        //(int)	set_menu_sub (MENU *,WINDOW *);
        //(WINDOW *) derwin (WINDOW *,int,int,int,int);
        set_menu_sub(my_menu, derwin(my_menu_win, 6, 38, 3, 1));


	/* Set menu mark to the string " * " */
        //(int)	set_menu_mark (MENU *, const char *);
        set_menu_mark(my_menu, " * ");


	/* Print a border around the main window and print a title */
    box(my_menu_win, 0, 0);
	print_in_middle(my_menu_win, 1, 0, 40, "My Menu", COLOR_PAIR(1));
	mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
	mvwhline(my_menu_win, 2, 1, ACS_HLINE, 38);
	mvwaddch(my_menu_win, 2, 39, ACS_RTEE);
	mvprintw(LINES - 2, 0, "F1 to exit");
	//refresh();

	//post the menu
	//(int)	post_menu (MENU *);
	post_menu(my_menu);
	wrefresh(my_menu_win);

	/*
	 REQ_LEFT_ITEM         Move left to an item.
     REQ_RIGHT_ITEM      Move right to an item.
     REQ_UP_ITEM         Move up to an item.
     REQ_DOWN_ITEM       Move down to an item.
     REQ_SCR_ULINE       Scroll up a line.
     REQ_SCR_DLINE          Scroll down a line.
     REQ_SCR_DPAGE          Scroll down a page.
     REQ_SCR_UPAGE         Scroll up a page.
     REQ_FIRST_ITEM     Move to the first item.
     REQ_LAST_ITEM         Move to the last item.
     REQ_NEXT_ITEM         Move to the next item.
     REQ_PREV_ITEM         Move to the previous item. 
     REQ_TOGGLE_ITEM     Select/deselect an item.
     REQ_CLEAR_PATTERN     Clear the menu pattern buffer.
     REQ_BACK_PATTERN      Delete the previous character from the pattern buffer.
     REQ_NEXT_MATCH     Move to the next item matching the pattern match.
     REQ_PREV_MATCH     Move to the previous item matching the pattern match.
	*/

	while((c = getch()) != KEY_F(1)){
		switch(c)
	    {	case KEY_DOWN:
	    		//(int)	menu_driver (MENU *,int);
		        menu_driver(my_menu, REQ_DOWN_ITEM);
				break;
			case KEY_UP:
				menu_driver(my_menu, REQ_UP_ITEM);
				break;
		}
		 wrefresh(my_menu_win);
	}

	//(int)	free_menu (MENU *);
	//(int)	unpost_menu (MENU *);
	unpost_menu(my_menu);
	for(int i = 0; i < n_choices; ++i)
	  //(int)	free_item (ITEM *);
      free_item(my_items[i]);
    //(int)	free_menu (MENU *);
	free_menu(my_menu);
	endwin();
	return 0;
}

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color)
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
	wattron(win, color);
	mvwprintw(win, y, x, "%s", string);
	wattroff(win, color);
	refresh();
}