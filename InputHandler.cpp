#include "InputHandler.h"
#include <conio.h>

InputHandler::InputHandler() {}

InputState InputHandler::getInput() {
    InputState input;
    input.left = false;
    input.right = false;
    input.down = false;
    input.rotate = false;

    if (_kbhit()) {
        char key = _getch();
        if (key == -32) {
            key = _getch();
            switch (key) {
            case 75: // ←
                input.left = true;
                break;
            case 77: // →
                input.right = true;
                break;
            case 80: // ↓
                input.down = true;
                break;
            }
        }
        else if (key == ' ') {
            input.rotate = true; // Space
        }
    }

    return input;
}
