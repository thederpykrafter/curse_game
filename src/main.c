#include "common.h"

int main() {
	WINDOW* win = initscr();
	raw();
	noecho();
	keypad(win, true);
	nodelay(win, true);

	int pressed;
	
	while (true) {
		clear();

		mvprintw(0, 0, "Running");
		refresh();

		napms(1000 / 60);

		pressed = wgetch(win);
		if (pressed == 113 || pressed == 27) { // q || esc
			break;
		}
	}
	endwin();
	return 0;
}
