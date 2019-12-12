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
 *  Date:          20-Mar-2014
 *
 *  It describes a food item.
 *
 *----------------------------------------------------------------*/

#ifndef FOOD_H_INCLUDED
#define FOOD_H_INCLUDED

#include "Board.h"

class Food {

private:

    /**
	 * Reference to the current board.
	 */
	Board& board;

    /**
     * The coordinates of the current food item.
     */
    unsigned int x, y;

public:

    /**
     * The constructor initializes the board.
     */
    Food(Board&);

    /**
     * Checks whether the current food item
     * has been eaten by the snake.
     * @return True  - the item's been eaten
     *         False - the item hasn't been eaten
     */
    bool isEaten();

    /**
     * Generates a food item at a random position
     * on the board.
     */
    void generateFood();

};

#endif // FOOD_H_INCLUDED
