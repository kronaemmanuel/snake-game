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
 *  The main method. It contains the game loop.
 *
 *----------------------------------------------------------------*/

#include <stdio.h>
#include <windows.h>    // sleep()
#include <conio.h>      // kbhit()
#include "Board.h"
#include "Input.h"
#include "Output.h"
#include "Snake.h"
#include "Food.h"
#include "Menu.h"

int main() {

	Input input;

	Menu menu;

	/**
     * Has the following meaning:
     *   - TRUE  -> the player wants to exit the game
     *   - FALSE -> otherwise
     */
    boolean exit = false;

	do {

        // "reset" the menu
        menu.resetMenu();

        do {
            menu.changeOption(input.readInput());
            menu.displayMenu();
            Sleep(70);
	    }
	    while (menu.getLastCommand() != VK_RETURN);

        /**
         * Depending on the selected option:
         *   - New Game (0) -> a new game will be started
         *   - Instructions (1) -> the instructions of the game
         *                         will be displayed
         *   - Exit (2) -> exit the game
         */
        switch (menu.getCurrentOption()) {

            case 0: {

                Board board;
                Output output(board);
                Snake snake(board);
                Food food(board);

                for (int i = 3; i > 0; i--) {
                    menu.displayCounter(i);
                    Sleep(1000);
                }

                do {

                    snake.changeDirection(input.readInput());

                    snake.move();

                    // If the snake has eaten the food item
                    // generate a new one.
                    if (food.isEaten())
                        food.generateFood();

                    output.updateBoard();

                    Sleep(100);
                }
                while (snake.getLives());

                output.showResults(snake.getScore());

                printf("Press any key to return to the main menu...\n");
                while(true)
                    if (kbhit())
                        break;

                // call getch() to "clear" the buffer
                // ("delete" the key that was pressed)
                getch();

                break;

            }

            case 1: {

                menu.displayInstructions();

                printf("\t Press any key to return to the main menu...");
                while(true)
                    if (kbhit())
                        break;

                // call getch() to "clear" the buffer
                // ("delete" the key that was pressed)
                getch();

                break;

            }

            case 2: { exit = true; break; }

        }

	}
	while (!exit);

    return 0;

}
