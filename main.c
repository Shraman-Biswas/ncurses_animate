#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <ncurses.h>

#define DELAY	30000

int main(int argc, char **argv)
{
	int x=0, y=0;
	int dir_x=1, dir_y=1;
	int max_y, max_x;

	printf("[ ncurses animation ]\n");

	/* init ncurses */
	initscr();
	noecho();
	curs_set(FALSE);

	/* get max screen dimensions */
	getmaxyx(stdscr, max_y, max_x);

	/* main loop */
	for (;;) {

		/* draw */
		clear();
		mvprintw(y, x, "O");
		refresh();

		/* collisoon detection */
		if ((x >= max_x) || (x < 0))
			dir_x *= -1;
		if ((y >= max_y) || (y < 0))
			dir_y *= -1;

		/* update movement*/
		x += dir_x;
		y += dir_y;

		/* pause */
		usleep(DELAY);
	}

	/* exit ncurses */
	endwin();

	return EXIT_SUCCESS;
}
