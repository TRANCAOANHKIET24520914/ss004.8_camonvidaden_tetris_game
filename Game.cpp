#include "Game.h"
#include <windows.h>
#include <ctime>

Game::Game()
{
    srand(time(NULL));
    arena.reset();
    spawnNew();
    score = 0;
    gameOver = false;
}

void Game::spawnNew()
{
    current = Tetromino();
    posX = A_WIDTH / 2 - 2;
    posY = 0;

    if (arena.checkCollision(current, posX, posY))
    {
        gameOver = true;
    }
}

void Game::handleInput(int key)
{
    switch (key)
    {
    case 75: // trai
        if (!arena.checkCollision(current, posX - 1, posY))
            posX--;
        break;
    case 77: // phai
        if (!arena.checkCollision(current, posX + 1, posY))
            posX++;
        break;
    case 80: // xuong
        if (!arena.checkCollision(current, posX, posY + 1))
            posY++;
        break;
    case 32: // space -> xoay
        if (!arena.checkCollision(current, posX, posY))
            current.rotateRight();
        break;
    }
}

void Game::start()
{
    while (!gameOver)
    {
        update();
        Sleep(10);
    }

    system("cls");
    printf("GAME OVER\nScore: %d\n", score);
}
