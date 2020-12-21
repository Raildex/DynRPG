namespace RPG {

// Functions added in the 0.30 update
// ==================================

	/*! \brief Built-in RM2k3 function that gets a random number between 1 and the specified number
		\param maxValue the maximum number to return
		\return A random number between 1 and the specified number
	*/
	int getDiceRoll(int maxValue);

	/*! \brief Goes directly to the title screen.
	*/
	static void goToTitle();

	/*! \brief Quits the game, and runs through the proper quit procedure code.
	*/
	static void quitGame();


	/*static void openOrderMenu() {
		asm volatile("call *%%esi"
			:
			: "S" (0x4A0104)
			: "edx", "ecx", "eax", "cc", "memory");

	}*/

	/*! \brief Built-in RM2k3 function that gets the party's average agility in battle
		\return The agility average of the party
	*/
	static int getAvgPartyAgl();

	/*! \brief Built-in RM2k3 function that gets the monster party's average agility in battle
		\return The agility average of the monster party
	*/
	static int getAvgMonsterPartyAgl();

	/*! \brief Open the main menu directly into a sub-menu. Experimental!!
	*/
	void openMenu(RPG::MenuSubScreen screen, int heroId = 1, int skillOrItemId = 1);

	/*! \brief The unpatch code for using RPG::openMenu. Experimental!!
	*/
	void OpenMenuUnpatch();


}
