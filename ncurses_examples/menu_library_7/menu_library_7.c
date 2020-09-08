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



void func(char *name);

int main()
{	
	int c;
	ITEM** my_items;
	int n_choices;
	MENU* my_menu;
	WINDOW* my_menu_win;
	int i;

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

	for(int i = 0; i < n_choices; ++i){
	//(ITEM *)	new_item (const char *,const char *);
		my_items[i] = new_item(choices[i], choices[i]);
		my_items[n_choices] = (ITEM *)NULL;
		/* Set the user pointer */
		//set_item_userptr (ITEM *, void *);
		set_item_userptr(my_items[i], func);
	}
		

	//create window
	//(MENU *)	new_menu (ITEM **);
	my_menu = new_menu((ITEM **)my_items);

	
	
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
			{	ITEM *cur;
				void (*p)(char *);

				cur = current_item(my_menu);
				//(void *)	item_userptr (const ITEM *);
				p = item_userptr(cur);
				p((char *)item_name(cur));
				pos_menu_cursor(my_menu);
				break;
			}
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

void func(char *name)
{	move(20, 0);
	//clrtoeol();
	mvprintw(20, 0, "Item selected is : %s", name);
}	