#include <ncurses.h>

WINDOW *TopWin(int top_win_height, int max_x) {
  WINDOW *win_top = newwin(top_win_height, max_x, 0, 0);

  box(win_top, 0, 0);
  refresh();
  wrefresh(win_top);

  return win_top;
}

WINDOW *LeftWin(int top_win_height, int max_y, int max_x) {
  int half_x = max_x / 2;

  int winHeight = max_y - top_win_height;
  int winWidth = max_x / 2;
  int winStartTop = top_win_height;
  int winStartLeft = 0;

  WINDOW *win_left = newwin(winHeight, winWidth, winStartTop, winStartLeft);

  box(win_left, 0, 0);
  refresh();
  wrefresh(win_left);

  return win_left;
}

int main(void) {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  curs_set(0);

  int max_y, max_x;
  getmaxyx(stdscr, max_y, max_x);

  int TOP_WIN_HEIGHT = 3;
  WINDOW *win_top = TopWin(TOP_WIN_HEIGHT, max_x);
  WINDOW *win_left = LeftWin(TOP_WIN_HEIGHT, max_y, max_x);

  getch();

  delwin(win_top);
  delwin(win_left);
  endwin();
  return 0;
}
