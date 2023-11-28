#include "game2048.hpp"
#include "randomnumber.hpp"
#include <vector>

Game2048::Game2048() {
	random_fill();
	random_fill();
}

// Fill an empty cell with a value of 2
void Game2048::random_fill() {
	std::vector<int> free_cells{};
	for(int row{}; row < 4; row++) {
		for(int col{}; col < 4; col++) {
			if(m_game_state[row][col] == 0) {
				free_cells.resize(free_cells.size() + 1);
				free_cells[free_cells.size() - 1] = row * 4 + col;
			}
		}
	}
	if(free_cells.size()) {
		int index{free_cells.at(Random::get(0, free_cells.size() - 1))};
		m_game_state[index / 4][index % 4 ] = 2;
	}
}

void Game2048::reset() {
	m_score = 0;
	for (int i{}; i < 4; i++) {
		for (int j{}; j < 4; j++) {
			m_game_state[i][j] = 0;
		}
	}
	random_fill();
	random_fill();
}

void Game2048::move_left() {
	for(int row{}; row < 4; row++) {
		for(int col{1}; col <= 3; col++) {
			for(int temp_col{col}; temp_col > 0; temp_col--) {
				if(m_game_state[row][temp_col - 1] == 0 && m_game_state[row][temp_col] != 0) {
					m_game_state[row][temp_col - 1] = m_game_state[row][temp_col];
					m_game_state[row][temp_col] = 0;
				}
			}
		}
		for(int col{1}; col <= 3; col++) {
			if(m_game_state[row][col - 1] == m_game_state[row][col] && m_game_state[row][col] != 0) {
				m_game_state[row][col - 1] *= 2;
				m_score += m_game_state[row][col - 1];
				m_game_state[row][col] = 0;
			}
		}
		for(int col{1}; col <= 3; col++) {
			if(m_game_state[row][col - 1] == 0 && m_game_state[row][col] != 0) {
				m_game_state[row][col - 1] = m_game_state[row][col];
				m_game_state[row][col] = 0;
			}
		}
	}
}

void Game2048::move_right() {
	for(int row{}; row < 4; row++) {
		for(int col{2}; col >= 0; col--) {
			for(int temp_col{col}; temp_col < 3; temp_col++) {
				if(m_game_state[row][temp_col + 1] == 0 && m_game_state[row][temp_col] != 0) {
					m_game_state[row][temp_col + 1] = m_game_state[row][temp_col];
					m_game_state[row][temp_col] = 0;
				}
			}
		}
		for(int col{2}; col >= 0; col--) {
			if(m_game_state[row][col + 1] == m_game_state[row][col] && m_game_state[row][col] != 0) {
				m_game_state[row][col + 1] *= 2;
				m_score += m_game_state[row][col + 1];
				m_game_state[row][col]= 0;
			}
		}
		for(int col{2}; col >= 0; col--) {
			if(m_game_state[row][col + 1] == 0 && m_game_state[row][col] != 0) {
				m_game_state[row][col + 1] = m_game_state[row][col];
				m_game_state[row][col] = 0;
			}
		}
	}
}

void Game2048::move_down() {
	for(int col{}; col < 4; col++) {
		for(int row{2}; row >= 0; row--) {
			for(int temp_row{row}; temp_row < 3; temp_row++) {
				if(m_game_state[temp_row + 1][col] == 0 && m_game_state[temp_row][col] != 0) {
					m_game_state[temp_row + 1][col] = m_game_state[temp_row][col];
					m_game_state[temp_row][col] = 0;
				}
			}
		}
		for(int row{2}; row >= 0; row--) {
			if(m_game_state[row + 1][col] == m_game_state[row][col] && m_game_state[row][col] != 0) {
				m_game_state[row + 1][col] *= 2;
				m_score += m_game_state[row + 1][col];
				m_game_state[row][col]= 0;
			}
		}
		for(int row{2}; row >= 0; row--) {
			if(m_game_state[row + 1][col] == 0 && m_game_state[row][col] != 0) {
				m_game_state[row + 1][col] = m_game_state[row][col];
				m_game_state[row][col] = 0;
			}
		}
	}
}

void Game2048::move_up() {
	for(int col{}; col < 4; col++) {
		for(int row{1}; row <= 3; row++) {
			for(int temp_row{row}; temp_row > 0; temp_row--) {
				if(m_game_state[temp_row - 1][col] == 0 && m_game_state[temp_row][col] != 0) {
					m_game_state[temp_row - 1][col] = m_game_state[temp_row][col];
					m_game_state[temp_row][col] = 0;
				}
			}
		}
		for(int row{1}; row <= 3; row++) {
			if(m_game_state[row - 1][col] == m_game_state[row][col] && m_game_state[row][col] != 0) {
				m_game_state[row - 1][col] *= 2;
				m_score += m_game_state[row - 1][col];
				m_game_state[row][col]= 0;
			}
		}
		for(int row{1}; row <= 3; row++) {
			if(m_game_state[row - 1][col] == 0 && m_game_state[row][col] != 0) {
				m_game_state[row - 1][col] = m_game_state[row][col];
				m_game_state[row][col] = 0;
			}
		}
	}
}

void Game2048::move(Key key) {
	switch(key) {
		case Key::left:
			move_left();
			random_fill();
			break;
		case Key::right:
			move_right();
			random_fill();
			break;
		case Key::down :
			move_down();
			random_fill();
			break;
		case Key::up :
			move_up();
			random_fill();
			break;
		default:
			break;
	}
}

int Game2048::get_value(int row, int col) const {
	return m_game_state[row][col];
}

int Game2048::get_score() const {
	return m_score;
}

bool Game2048::is_locked() const {
	for (int row{}; row < 4; row++) {
		for (int col{}; col < 4; col++) {
			if (!m_game_state[row][col]
					|| (row != 3 && m_game_state[row][col] == m_game_state[row + 1][col]) 
					|| (col != 3 && m_game_state[row][col] == m_game_state[row][col + 1])) {
				return false;
			}
		}
	}
	return true;
}
