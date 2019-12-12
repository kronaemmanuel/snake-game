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

#include "Board.h"

Board::Board() {

	for (int i = 0; i < MAX_LINES; i++)
		for (int j = 0; j < MAX_COLUMNS; j++)
			board[i][j] = 0;

}

int Board::getXY(int x, int y) {

	if (isValidXY(x, y))
		return board[x][y];
	else
		return -1;

}

void Board::setXY(int x, int y, unsigned int value) {

	if (isValidXY(x, y))
		board[x][y] = value;

}

bool Board::isValidXY(int x, int y) {

	if (0 <= x && x < MAX_LINES	&& 0 <= y && y < MAX_COLUMNS)
		return true;

	return false;

}
