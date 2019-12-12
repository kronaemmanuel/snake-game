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

 #include "Output.h"
 #include <stdio.h>
 #include <stdlib.h>    // system("cls");

 Output::Output(Board& newBoard): board(newBoard) {   }

 void Output::updateBoard() {

    clearScreen();

    int i, j;

    // Create a border around the board
    for (i = 0; i < MAX_LINES + 2; i++)
        printf("%c", 177);

    printf("\n");

    for (i = 0; i < MAX_LINES; i++) {
        printf("%c", 177);
        for (j = 0; j < MAX_COLUMNS; j++) {
            switch (board.getXY(i, j)) {
                case 0: { printf(" "); break; }
                case 1: { printf("X"); break; }
                case 2: { printf("%c", 232); break; }
            }
        }
        printf("%c", 177);
        printf("\n");
    }

    for (i = 0; i < MAX_LINES + 2; i++)
        printf("%c", 177);

 }

 void Output::showResults(unsigned int score) {

    clearScreen();

    if (score == 0)
        printf("Sorry, better luck next time...\n");
    else
        printf("Congratulations! You obtained a total score of %d.\n", score);

 }

 void Output::clearScreen() {

    system("cls");

 }
