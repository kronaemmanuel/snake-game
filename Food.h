/**----------------------------------------------------------------
 *  Snake
 *  It describes a food item.
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
