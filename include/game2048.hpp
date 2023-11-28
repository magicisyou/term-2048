#ifndef GAME2048_HPP
#define GAME2048_HPP

enum class Key {left, right, up, down};

class Game2048 {
	private:
		int m_score{};
		int m_game_state[4][4]{};
		void random_fill();
		void move_left();
		void move_right();
		void move_up();
		void move_down();
	public:
		Game2048();
		void move(Key key);
		bool is_locked() const;
		void reset();
		int get_value(int row, int col) const;
		int get_score() const;
};

#endif
