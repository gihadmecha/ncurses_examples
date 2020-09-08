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
						"Choice 5",
						"Choice 6",
						"Choice 7",
                        "Exit",
                  };



int main()
{	
	int c;
	ITEM** my_items;
	int n_choices;
	MENU* my_menu;
	WINDOW* my_menu_win;

	//initialize curser
	initscr();
	keypad(stdscr, TRUE);
	start_color();
	
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_MAGENTA, COLOR_BLACK);

	//create items
	n_choices = ARRAY_SIZE(choices);

	my_items = (ITEM**)calloc(n_choices + 1, sizeof(ITEM *));

	for(int i = 0; i < n_choices; ++i)
	//(ITEM *)	new_item (const char *,const char *);
		my_items[i] = new_item(choices[i], choices[i]);
		my_items[n_choices] = (ITEM *)NULL;
		//(int)	item_opts_off (ITEM *,Item_Options);
		item_opts_off(my_items[3], O_SELECTABLE);
		item_opts_off(my_items[6], O_SELECTABLE);

	//create window
	//(MENU *)	new_menu (ITEM **);
	my_menu = new_menu((ITEM **)my_items);


	/* Set fore ground and back ground of the menu */
	//(int)	set_menu_fore (MENU *,chtype);
	set_menu_fore(my_menu, COLOR_PAIR(1) | A_REVERSE);
	//(int)	set_menu_back (MENU *,chtype);
	set_menu_back(my_menu, COLOR_PAIR(2));
	//(int)	set_menu_grey (MENU *,chtype);
	set_menu_grey(my_menu, COLOR_PAIR(3));

	
	/* Make the menu multi valued */
	//(int)	menu_opts_off (MENU *,Menu_Options);
	menu_opts_off(my_menu, O_ONEVALUE);


	/* Post the menu */
	mvprintw(LINES - 3, 0, "Press <ENTER> to see the option selected");
	mvprintw(LINES - 2, 0, "Up and Down arrow keys to naviage (F1 to Exit)");

	//post the menu
	//(int)	post_menu (MENU *);
	post_menu(my_menu);
	refresh();


	while((c = getch()) != KEY_F(1)){
		switch(c)
	    {	
	    	case KEY_DOWN:
				menu_driver(my_menu, REQ_DOWN_ITEM);
				break;
			case KEY_UP:
				menu_driver(my_menu, REQ_UP_ITEM);
				break;
			case 10: /* Enter */
				move(20, 0);
				//clrtoeol();
				//(const char *)	item_name (const ITEM *);
				//(ITEM *)	current_item (const MENU *);
				mvprintw(20, 0, "Item selected is : %s", item_name(current_item(my_menu)));
				//(int)	pos_menu_cursor (const MENU *);
				pos_menu_cursor(my_menu);
				break;
		}
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
