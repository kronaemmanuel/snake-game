/**----------------------------------------------------------------
 *  Snake
 *  Copyright (C) 2014  PODARIU Ovidiu
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *----------------------------------------------------------------*/


/**----------------------------------------------------------------
 *  Author:        Ovidiu PODARIU
 *  Date:          18-Mar-2014
 *
 *  It describes the snake's characteristics and actions.
 *
 *----------------------------------------------------------------*/

#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

#include "Board.h"

/// The maximum size of the snake - number of "segments".
const unsigned int MAX_SIZE = 20;

class Snake {

private:

	/**
	 * Reference to the current board.
	 */
	Board& board;

	/**
	 * Number of lives the snake has before it dies.
	 */
	unsigned int lives;

	/**
	 * The length of the snake - number of "segments".
	 */
	unsigned int length;

	/**
	 * Stores the coordinates of the snake's "segments".
	 * coord[0] - the head of the snake;
	 */
	unsigned int coord[MAX_SIZE][2];

	/**
	 * The direction of the snake. It can have one of the
	 * following values:
	 *		- 'H' -> the snake goes UP
	 *		- 'P' -> the snake goes DOWN
	 *		- 'K' -> the snake goes LEFT
	 *		- 'M' -> the snake goes RIGHT
	 */
	char direction;

	/**
	 * The player's score.
	 */
	unsigned int score;

    /**
	 * Calculates the next position of the snake
	 * (the X coordinate) based on its current direction.
	 */
	int newXCoord();

    /**
	 * Calculates the next position of the snake
	 * (the Y coordinate) based on its current direction.
	 */
	int newYCoord();

    /**
	 * Resets the snake to its original state
	 * (length = 1 and a random position).
	 */
	void reset();

	/**
	 * When the snake hits a "wall" it loses 1 life.
	 * This method decrements the number of lives
	 * and returns whether the snake is still alive.
	 * @return TRUE  - if lives > 0
	 *         FALSE - otherwise
	 */
	bool loseLife();

	/**
	 * Updates the board with the snake's current
	 * coordinates.
	 */
	void updateBoard();

public:

    /**
     * The constructor initializes the board,
     * the number of lives, the length of the snake,
     * the array storing the snake's coordinates,
     * the direction and the player's score.
     */
	Snake(Board&);

    /**
     * Moves the snake to its next position
     * depending on its current direction.
     */
	void move();

    /**
     * Changes the snake's current direction.
     * @param the new direction of the snake
     */
	void changeDirection(char);

    /**
     * Returns the number of lives.
     * @return the number of lives
     */
	unsigned int getLives();

    /**
     * Returns the length of the snake.
     * @return the length of the snake
     */
	unsigned int getLength();

    /**
     * Returns the player's score.
     * @return the player's score
     */
	unsigned int getScore();

};

#endif // SNAKE_H_INCLUDED
