/**----------------------------------------------------------------
 *  Snake
 *  It is used to represent the main menu of the game.
 *----------------------------------------------------------------*/

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

// The key-codes used to verify the user's input
#define UP    72
#define DOWN  80

class Menu {

private:

    /**
     * Defines an option of the menu.
     * Every option has a name and it can
     * either be selected or not.
     */
    struct Option {
        char* name;
        bool selected;
    };

    /**
     * Stores the current options of the main menu.
     */
    Option options[3];

    /**
     * Total number of options.
     */
    unsigned int nrOfOptions;

    /**
     * The id (index) of the currently
     * selected option.
     */
    unsigned int currentOption;

    /**
     * Stores the last command received from
     * the user.
     */
    char lastCommand;


public:

    /**
     * Initialize the options.
     */
    Menu();

    /**
     * Display the main menu of the game:
     * title + options.
     */
    void displayMenu();

    /**
     * Displays the title of the game.
     */
    void displayTitle();

    /**
     * Displays the options of the menu.
     */
    void displayOptions();

    /**
     * Displays copyright information.
     */
    void displayCopyright();

    /**
     * Displays the instructions - how to play the game.
     */
    void displayInstructions();

    /**
     * Displays a counter before the start of the game.
     */
    void displayCounter(unsigned int);

    /**
     * Clears the screen.
     */
    void clearScreen();

    /**
     * Changes the selected option.
     * @param the direction towards the desired option
     */
    void changeOption(char);

    /**
     * @return the id of the currently selected option
     */
    unsigned int getCurrentOption();

    /**
     * @return last command received from the user
     */
    char getLastCommand();

    /**
     * "Resets" the menu. Sets the currently selected
     * option to "New game" and the lastCommand to
     * a random character.
     */
    void resetMenu();

};

#endif // MENU_H_INCLUDED
