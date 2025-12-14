#ifndef ARENA_H
#define ARENA_H

#define A_HEIGHT 20
#define A_WIDTH 15

class Arena {
private:
    char board[A_HEIGHT][A_WIDTH];

public:
    Arena();

    bool isValidPosition(const char tetromino[4][4], int x, int y);

    void lockPiece(const char tetromino[4][4], int x, int y);

    int clearLines();

    char getCell(int y, int x) const;
};

#endif
