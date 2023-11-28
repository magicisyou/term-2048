#include "game2048.hpp"
#include <ncurses.h>

// Print game on screen
void display(const Game2048& game) {
	clear();
	int x{}, y{};
	getmaxyx(stdscr, y, x);
	mvaddstr(1, (x - 8) / 2, "Term 2048");
	for(int line{}; line < 3; line++)
		mvchgat(line, 0, -1, A_BOLD, 1, NULL);
	mvprintw(5, x - 14, "Score : %d", game.get_score());
	int y_start{(y - 15) / 2};
	int x_start{(x - 30) / 2};
	for(int line{0}; line < 17; line++)
		mvchgat(y_start + line - 1, x_start - 2, 34, 0, 1, NULL);
	for(int row{}; row < 4; row++) {
		for(int col{}; col < 4; col++) {

			if(game.get_value(row, col))
				mvprintw(y_start + row * 4 + 1, x_start + col * 8 + 1,
					"%d", game.get_value(row, col));
			for(int line{}; line < 3; line++) {
				if(game.get_value(row, col))
					mvchgat(y_start + row * 4 + line, x_start + col * 8, 6, A_BOLD, 3, NULL);
				else
					mvchgat(y_start + row * 4 + line, x_start + col * 8, 6, A_BOLD, 2, NULL);
			}
		}
	}
	if (game.is_locked()) {
		mvaddstr(6, (x - 9) / 2, "Game Over");
	}
}

int main() {
	Game2048 game{};
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	start_color();
	init_pair(1, COLOR_RED, COLOR_WHITE);
	init_pair(2, COLOR_WHITE, COLOR_GREEN);
	init_pair(3, COLOR_WHITE, COLOR_BLUE);
	curs_set(0);

	display(game);
	while (int response = getch()) {
		if (response == 'q' || response == 'Q')
			break;
		switch (response) {
			case 'r':
				game.reset();
				break;
			case KEY_LEFT:
				game.move(Key::left);
				break;
			case KEY_RIGHT:
				game.move(Key::right);
				break;
			case KEY_DOWN:
				game.move(Key::down);
				break;
			case KEY_UP:
				game.move(Key::up);
				break;
			default:
				continue;
		}
		display(game);
		refresh();
	}
	endwin();
	return 0;
}
