#pragma once
  char Input = ' ';
  bool CursorActive = false;
/**
  Gives you input, of so is an keycode of so was pressed. Returns "0" if no key was pressed.
 
 
 */
const char GetInput() {
	if (Input) {
		return Input;
	}
	else if (Input == ' ');
	return '0';
}

/**
  Activates the cursor for input reading.

 */
void ActivateCursor() {
	CursorActive = true;
}