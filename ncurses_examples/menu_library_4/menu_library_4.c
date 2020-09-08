#include <curses.h>
#include <menu.h>
#include <stdlib.h>
#include <string.h>



#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

char *choices[] = {
                        
                        "Choice 1", "Choice 2", "Choice 3", "Choice 4", "Choice 5",
						"Choice 6", "Choice 7", "Choice 8", "Choice 9", "Choice 10",
						"Choice 11", "Choice 12", "Choice 13", "Choice 14", "Choice 15",
						"Choice 16", "Choice 17", "Choice 18", "Choice 19", "Choice 20",
                        "Exit",
                        (char *)NULL,
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
	init_pair(2, COLOR_CYAN, COLOR_BLACK);

	//create items
	n_choices = ARRAY_SIZE(choices);

	my_items = (ITEM**)calloc(n_choices + 1, sizeof(ITEM *));

	for(int i = 0; i < n_choices; ++i)
	//(ITEM *)	new_item (const char *,const char *);
		my_items[i] = new_item(choices[i], choices[i]);

	//create window
	//(MENU *)	new_menu (ITEM **);
	my_menu = new_menu((ITEM **)my_items);

	/*
		 O_ONEVALUE
            Only one item can be selected for this menu.

       O_SHOWDESC
            Display  the  item  descriptions  when  the  menu  is
            posted.

       O_ROWMAJOR
            Display the menu in row-major order.

       O_IGNORECASE
            Ignore the case when pattern-matching.

       O_SHOWMATCH
            Move the cursor to within the item  name  while  pat­
            tern-matching.

       O_NONCYCLIC
            Don't   wrap   around  next-item  and  previous-item,
            requests to the other end of the menu.
	*/

	/* Set menu option not to show the description */
	//(int)	menu_opts_off (MENU *,Menu_Options);
	menu_opts_off(my_menu, O_SHOWDESC);


	/* Create the window to be associated with the menu */
        my_menu_win = newwin(10, 70, 4, 4);
       // keypad(my_menu_win, TRUE);
     
	/* Set main window and sub window */
        //(int)	set_menu_win (MENU *,WINDOW *);
        set_menu_win(my_menu, my_menu_win);
        //(int)	set_menu_sub (MENU *,WINDOW *);
        //(WINDOW *) derwin (WINDOW *,int,int,int,int);
        set_menu_sub(my_menu, derwin(my_menu_win, 6, 68, 3, 1));
        //(int)	set_menu_format (MENU *,int,int);
        set_menu_format(my_menu, 5, 3);
        //(int)	set_menu_mark (MENU *, const char *);
        set_menu_mark(my_menu, " * ");


	/* Set menu mark to the string " * " */
        //(int)	set_menu_mark (MENU *, const char *);
        set_menu_mark(my_menu, " * ");


	/* Print a border around the main window and print a title */
    box(my_menu_win, 0, 0);
	//refresh();


	attron(COLOR_PAIR(2));
	mvprintw(LINES - 2, 0, "Use PageUp and PageDown to scoll down or up a page of items");
	mvprintw(LINES - 1, 0, "Arrow Keys to navigate (F1 to Exit)");
	attroff(COLOR_PAIR(2));
	refresh();

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
	    {	
	    	case KEY_DOWN:
				menu_driver(my_menu, REQ_DOWN_ITEM);
				break;
			case KEY_UP:
				menu_driver(my_menu, REQ_UP_ITEM);
				break;
			case KEY_LEFT:
				menu_driver(my_menu, REQ_LEFT_ITEM);
				break;
			case KEY_RIGHT:
				menu_driver(my_menu, REQ_RIGHT_ITEM);
				break;
			case KEY_NPAGE:
				menu_driver(my_menu, REQ_SCR_DPAGE);
				break;
			case KEY_PPAGE:
				menu_driver(my_menu, REQ_SCR_UPAGE);
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
