#include "raylib.h"
#include <list>

void mainMenu(Rectangle button) {
    DrawText("GAME NAME", 250, 100, 50, BLACK);
    DrawText("2022 - Developed by: Yasir Saeed ", 285, 500, 15, BLACK);

    // Play Button
    DrawRectangle(button.x, button.y, button.width, button.height,
                  RED);

    DrawText("PLAY", (GetScreenWidth() / 2) - 28, 300, 20, WHITE);
}


int main() {
    std::list<Rectangle> objects;

    Vector2 mousePt;
    Rectangle playButton = {300, 275, 200, 75};

    const int screenWidth = 800;
    const int screenHeight = 600;
    bool isMenu = true;
    InitWindow(screenWidth, screenHeight, "development");
    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        mousePt = GetMousePosition();
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawFPS(10, 10);
        //----------------------------------------------------------------------------------
        if (isMenu) { // Game menu

            mainMenu(playButton);

            // Check if player clicks play button
            if (CheckCollisionPointRec(mousePt, playButton)
                && ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT)))) {
                isMenu = false;

            }
            //----------------------------------------------------------------------------------
        } else { // Game loop





        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    CloseWindow();        // Close window and OpenGL context

    return 0;
}