/**----------------------------------------------------------------
 *  Snake
 *  It describes the snake's characteristics and actions.
 *----------------------------------------------------------------*/

#include "Snake.h"
#include <stdio.h>  // NULL
#include <stdlib.h> // srand(), rand()
#include <time.h>   // time()

Snake::Snake(Board& newBoard): board(newBoard) {

    lives  = 1;
    length = 1;
    score  = 0;
    direction = 'H'; // the initial direction is UP

    // The snake's initial position will be randomly
    // generated around the middle of the board.
    int tempX, tempY;

    srand(time(NULL));
    tempX = MAX_LINES / 2 + rand() % 4;
    tempY = MAX_COLUMNS / 2 + rand() % 4;

    coord[0][0] = tempX;
    coord[0][1] = tempY;

}

void Snake::move() {

    // The snake's head new coordinates
    int tempX = newXCoord();
    int tempY = newYCoord();

    // Check if the next position is a wall
    // (not a valid position) or a segment of the snake
    // => the snake dies
    if (!board.isValidXY(tempX, tempY) || board.getXY(tempX, tempY) == 1) {
        if (loseLife()) {
            reset();
            return ;
        }
        else
            return ;
    }

    // Check if the next position is occupied by a food item
    if (board.getXY(tempX, tempY) == 2) {
        // The snake grows by 1 segment
        length++;

        // Update the coordinates of the snake's segments
        for (int i = length - 1; i > 0; i--) {
            coord[i][0] = coord[i-1][0];
            coord[i][1] = coord[i-1][1];
        }
        coord[0][0] = tempX;
        coord[0][1] = tempY;

        // Because the snake has grown on the board
        // it will appear like the previous snake
        // plus a new head. Therefore, we can leave
        // the previous snake on the board and add only
        // one extra segment.
        board.setXY(coord[0][0], coord[0][1], 1);

        // Add 10 points to the player's score.
        score += 10;
    }
    else {
        // Because the snake hasn't grown, its tail
        // (the last segment) will not appear anymore on
        // the board. This intruction "deletes" it.
        board.setXY(coord[length-1][0], coord[length-1][1], 0);

        // update the coordinates of the snake's segments
        for (int i = length - 1; i > 0; i--) {
            coord[i][0] = coord[i-1][0];
            coord[i][1] = coord[i-1][1];
        }
        coord[0][0] = tempX;
        coord[0][1] = tempY;

        // Display the snake's new head on the board.
        board.setXY(coord[0][0], coord[0][1], 1);
    }

}

void Snake::changeDirection(char newDirection) {

    // if it's a valid direction
    if (newDirection == 'H'
        || newDirection == 'P'
        || newDirection == 'K'
        || newDirection == 'M')
            direction = newDirection;

}

void Snake::reset() {

    // "delete" the current snake
    for (int i = 0; i < length; i++)
        board.setXY(coord[i][0], coord[i][1], 0);

    length = 1;

    // The snake's head will appear at a random
    // location around the middle of the board.
    int tempX, tempY;

    srand(time(NULL));
    tempX = MAX_LINES / 2 + rand() % 4;
    tempY = MAX_COLUMNS / 2 + rand() % 4;

    coord[0][0] = tempX;
    coord[0][1] = tempY;

    direction = 'H';

}

bool Snake::loseLife() {

    lives--;
    if (lives == 0)
        return false;
    return true;

}

int Snake::newXCoord() {

    if (direction == 'H') return coord[0][0] - 1;
    else if (direction == 'P') return coord[0][0] + 1;
         else if (direction == 'K') return coord[0][0];
              else if (direction == 'M') return coord[0][0];

}

int Snake::newYCoord() {

    if (direction == 'H') return coord[0][1];
    else if (direction == 'P') return coord[0][1];
         else if (direction == 'K') return coord[0][1] - 1;
              else if (direction == 'M') return coord[0][1] + 1;

}

unsigned int Snake::getLives()  { return lives; }

unsigned int Snake::getLength() { return length; }

unsigned int Snake::getScore()  { return score; }
