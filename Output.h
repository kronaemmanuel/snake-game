/**----------------------------------------------------------------
 *  Snake
 *  Its purpose is to print messages to standard output
 *  and to draw the board.
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
