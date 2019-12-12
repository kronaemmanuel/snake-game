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
 *  Date:          17-Mar-2014
 *
 *  It is used to get the user's input.
 *
 *----------------------------------------------------------------*/

#include "Input.h"
#include <conio.h>      // kbhit(); getch();

char Input::readInput() {

	if (_kbhit()) {
		char ch = _getch();
		if (ch == 0) ch = _getch();
		return ch;
	}
	else
		return 0;

}
