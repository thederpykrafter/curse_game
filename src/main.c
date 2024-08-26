#include "common.h"
#include <curses.h>

int winWidth, winHeight;
int keyPressed;
bool running = true;

void handleKeys(WINDOW *win) {
  keyPressed = wgetch(win);
  switch (keyPressed) {
    case KEYS_Q:
    case KEYS_ESC:
      running = false;
    case KEYS_CTRL_Q:
      mvprintw(winWidth - 1, 0, "ctrl + q");
      refresh();
      break;
    default:
      break;
  }
}

int main() {
  WINDOW *win = initscr();
  raw();
  noecho();
  keypad(win, true);
  nodelay(win, true);
  nonl();

  while (running) {
    clear();

    getmaxyx(win, winWidth, winHeight);

    mvprintw(0, 0, "Running | X:%d Y:%d", winWidth, winHeight);
    wrefresh(win);

    handleKeys(win);
    napms(1000 / 60);
  }
  endwin();
  return 0;
}
