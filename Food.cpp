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

#include "Food.h"
#include <stdio.h>  // NULL
#include <stdlib.h> // srand(), rand()
#include <time.h>   // time()

Food::Food(Board& newBoard): board(newBoard) {  }

bool Food::isEaten() {

    // the value of a food item on the board is 2
    if (board.getXY(x, y) == 2)
        return false;
    return true;

}

void Food::generateFood() {

    srand(time(NULL));

    int tempX, tempY;

    // Generate random coordinates until a free
    // position is found(the element on the board
    // at those coordinates = 0).
    // board[tempX][tempY] = 0; is a free position
    do {

        tempX = rand() % MAX_LINES;
        tempY = rand() % MAX_COLUMNS;

    }
    while (board.getXY(tempX, tempY));

    // Create a food item there
    board.setXY(tempX, tempY, 2);

    // Update the coordinates of the current food item
    x = tempX;
    y = tempY;

}
