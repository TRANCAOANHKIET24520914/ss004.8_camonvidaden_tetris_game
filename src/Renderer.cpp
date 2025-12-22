#include "Renderer.h"
#include <cstdio> // Dùng cho printf nếu cần format số đẹp

using namespace std;

Renderer::Renderer() {
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Renderer::gotoxy(int x, int y) {
    COORD c = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hConsole, c);
}

void Renderer::init() {
    // Ẩn con trỏ chuột nhấp nháy để game nhìn mượt hơn
    CONSOLE_CURSOR_INFO Info;
    Info.bVisible = FALSE;
    Info.dwSize = 20;
    SetConsoleCursorInfo(hConsole, &Info);
}

void Renderer::render(const Arena& arena, const char currentBlock[4][4], int x, int y, int score) {
    // 1. Di chuyển về góc trái trên cùng thay vì xóa màn hình (chống giật)
    gotoxy(0, 0);

    // 2. Vẽ Board và Khối đang rơi
    for (int i = 0; i < A_HEIGHT; i++) {
        for (int j = 0; j < A_WIDTH; j++) {
            // Mặc định lấy pixel từ Arena (tường hoặc các khối đã khóa)
            char pixel = arena.getCell(i, j);

            // Kiểm tra xem vị trí (j, i) có thuộc về khối đang rơi (currentBlock) không
            // Tọa độ khối đang rơi là từ [y, y+3] và [x, x+3]
            if (i >= y && i < y + 4 && j >= x && j < x + 4) {
                // Tính tọa độ cục bộ trong ma trận 4x4 của khối
                int localRow = i - y;
                int localCol = j - x;
                
                // Nếu tại vị trí đó của khối có ký tự (không phải khoảng trắng), vẽ đè lên
                if (currentBlock[localRow][localCol] != ' ') {
                    pixel = currentBlock[localRow][localCol];
                }
            }
            cout << pixel;
        }
        
        // 3. Vẽ UI (Điểm số) bên cạnh bảng chơi
        if (i == 2) cout << "  SCORE: " << score;
        else if (i == 4) cout << "  CONTROLS:";
        else if (i == 5) cout << "  A/D: Move";
        else if (i == 6) cout << "  X: Down";
        else if (i == 7) cout << "  Space: Rotate"; // Dự trù cho module Input
        
        cout << endl; // Xuống dòng sau khi vẽ xong 1 hàng
    }
}

void Renderer::renderGameOver(int finalScore) {
    system("cls"); // Xóa sạch màn hình lần cuối
    gotoxy(0, 0);
    cout << "=========================" << endl;
    cout << "       GAME OVER         " << endl;
    cout << "=========================" << endl;
    cout << " Final Score: " << finalScore << endl;
    cout << "=========================" << endl;
}