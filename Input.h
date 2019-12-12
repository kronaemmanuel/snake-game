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

#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

class Input {

public:

	/**
	 * Check if the user has pressed any key.
	 * If he hasn't, return 0.
	 * Else return the key that was pressed. If a special
	 * key's been pressed return only the character != NULL
	 * from the end of the sequence. For example the UP arrow
	 * key has the following code: NULL + 'H'. This method
	 * returns only the character 'H'.
	 */
	char readInput();

};

#endif // INPUT_H_INCLUDED
