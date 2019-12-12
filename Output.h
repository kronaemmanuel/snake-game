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
 *  Date:          21-Mar-2014
 *
 *  Its purpose is to print messages to standard output
 *  and to draw the board.
 *
 *----------------------------------------------------------------*/

#ifndef OUTPUT_H_INCLUDED
#define OUTPUT_H_INCLUDED

#include "Board.h"

class Output {

private:

    /**
	 * Reference to the current board.
	 */
    Board& board;

public:

    /**
     * The constructor initializes the board.
     */
    Output(Board&);

    /**
     * Draw the board.
     */
    void updateBoard();

    /**
     * Print the player's score.
     */
    void showResults(unsigned int);

    /**
     * Clears the screen.
     * ("Erases" the previous board.)
     */
    void clearScreen();

};

#endif // OUTPUT_H_INCLUDED
