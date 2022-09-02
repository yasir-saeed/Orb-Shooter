#include "raylib.h"
#include <list>

void init(){

    BeginDrawing();
    ClearBackground(RAYWHITE);

}

int main(void)
{
    std::list<Rectangle> objects;

    Vector2 mousePt = {0.0f, 0.0f};
    Rectangle playButton = {300,275,200,75};

    const int screenWidth = 800;
    const int screenHeight = 600;
    bool isMenu = true;

    InitWindow(screenWidth, screenHeight, "development");
    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        mousePt = GetMousePosition();
        init();

        if(isMenu) { // Game menu

            // Main text
            DrawText("GAME NAME",250,100,50,BLACK);
            DrawText("2022 - Developed by: Yasir Saeed ",285,500,15,BLACK);

            // Play Button
            DrawRectangle(playButton.x,playButton.y,playButton.width,playButton.height,
                          RED);

            DrawText("PLAY", (GetScreenWidth() / 2)-28, 300, 20, WHITE);

            // Check if player clicks play button
            if(CheckCollisionPointRec(mousePt,playButton)){
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    isMenu = false;
                }
            }
        }else{ // Game loop




        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    CloseWindow();        // Close window and OpenGL context

    return 0;
}