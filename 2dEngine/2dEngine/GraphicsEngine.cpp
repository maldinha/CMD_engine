#include <iostream>
#include "conio.h"
#include <cctype>
#include <windows.h>
#include <string>
#include "Variables.h"


int CursorX = 0;
int CursorY = 0;
bool finish = false;
// --- Color and Utility Functions ---

// Sets the console color using Windows API constants
void SetConsoleBwColor(bool is_white_on_black) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD attributes;

    if (is_white_on_black) {
        // Bright White Foreground on Black Background
        attributes = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
    }
    else {
        // Black Foreground on Bright White Background
        attributes = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
        // Optionally add FOREGROUND_BLACK (which is often 0) 
        // attributes |= 0; 
    }
    SetConsoleTextAttribute(hConsole, attributes);
}

// Moves the cursor to a specific (x, y) position
void SetCursorPosition(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { (short)x, (short)y };
    SetConsoleCursorPosition(hConsole, pos);
}

/**
 * Draws a solid rectangle using only Black and White colors.
 * @param start_x The starting column (X coordinate, 0-indexed).
 * @param start_y The starting line (Y coordinate, 0-indexed).
 * @param width The width of the rectangle in characters.
 * @param height The height of the rectangle in lines.
 * @param fill_white If true, the rectangle is White; otherwise, it is Black.
 */
void DrawRectangle(int start_x, int start_y, int width, int height, bool fill_white) {
    // Determine the color setting:
    // If fill_white is true, we want a white background block, so we use BLACK text on WHITE background.
    // If fill_white is false, we want a black background block, so we use WHITE text on BLACK background (and rely on the space character).
    SetConsoleBwColor(!fill_white);

    // Create the drawing string (a string of spaces)
    std::string line_of_spaces(width, ' ');

    // Loop through each line of the rectangle
    for (int y = 0; y < height; ++y) {
        // 1. Move the cursor to the start position for this line
        SetCursorPosition(start_x, start_y + y);

        // 2. Print the line of spaces
        // The color attribute set above will fill the background of these spaces.
        std::cout << line_of_spaces;
    }
}
void DrawTextAt(int start_x, int start_y, const std::string& text,bool fill_white) {
    SetConsoleBwColor(!fill_white);
    SetCursorPosition(start_x, start_y);
    std::cout << text;
}










//Insert your code here
void gain() {
    ActivateCursor();
	DrawTextAt(CursorX, CursorY, "Use WASD to move the cursor ", false);
}















int frame = 0;
bool toggle = false;
int main() {

    // Get starting cursor position for clean return
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    COORD originalCursorPos = csbi.dwCursorPosition;


    // Clear the screen (for a cleaner canvas)
    while (true) {
        Sleep(1000 / 60);
      
        system("cls");

        SetCursorPosition(0, originalCursorPos.Y + 25);
        if (_kbhit()) {
            // 2. get the key of so was pressed into Input.
            Input = _getch();
            if (CursorActive) {
                if (toupper(Input) == 'W' && CursorY >= 0) {
                    CursorY--;
                }
                else if (toupper(Input) == 'S' && CursorY <= 24) {
                    CursorY++;
                }
                else if (toupper(Input) == 'A' && CursorX >= 0) {
                    CursorX--;
                }
                else if (toupper(Input) == 'D' && CursorX <= 79) {
                    CursorX++;
                }
            }
        }
        if (CursorActive) {
            DrawRectangle(CursorX, CursorY, 1, 1, true);
        }
        gain();
        // 6. Reset color to default White on Black
        SetConsoleBwColor(true);

    }
    if (finish)
        return 0;
}
    //Insert your code here.
