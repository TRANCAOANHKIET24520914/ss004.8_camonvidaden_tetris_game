#pragma once
#include<iostream>
using namespace std;

struct InputState {
    bool left;
    bool right;
    bool down;
    bool rotate;
};

class InputHandler {
public:
    InputHandler();

    InputState getInput();     // Đọc input từ bàn phím
};
