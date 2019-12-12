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
 *  Date:          19-Mar-2014
 *
 *  It defines a board that will be common to both the snake
 *  and the food.
 *
 *----------------------------------------------------------------*/

#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

/// The board's maximum widht and height.
const unsigned int MAX_LINES   = 15;
const unsigned int MAX_COLUMNS = 15;

class Board {

private:
	/**
	 * The actual board - a 2D matrix.
	 * Its elements can have one of the following values:
	 *		- 0 -> if the cell is empty
	 *		- 1 -> if the cell is a snake segment
	 *		- 2 -> if the cell is a food item
	 */
	unsigned int board[MAX_LINES][MAX_COLUMNS];

public:

	/**
	 * The constructor intializes all cells with 0.
	 */
	Board();

	/**
	 * Returns the element with the X and Y coordinates.
	 * @param the X coordinate
	 * @param the Y coordinate
	 * @return the element's value - if it's a valid position
	 *         -1                  - otherwise
	 */
	int getXY(int, int);

	/**
	 * Sets the value of the element with the X and Y coordinates.
	 * @param the X coordinate
	 * @param the Y coordinate
	 * @param the new value of the element
	 */
	void setXY(int, int, unsigned int);

	/**
	 * Check whether X and Y represent valid coordinates.
	 * @param the X coordinate
	 * @param the Y coordinate
	 * @return TRUE  - if it's a valid position
	 *         FALSE - otherwise
	 */
	bool isValidXY(int, int);

};

#endif // BOARD_H_INCLUDED
