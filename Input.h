/**----------------------------------------------------------------
 *  Snake
 *  It is used to get the user's input.
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
