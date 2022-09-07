#include "raylib.h"
#include "mainmenu.h"
#include "movement.h"
#include "bullets.h"


int main() {


    player Player;
    Player.x = 400;
    Player.y = 300;
    Player.radius = 15;

    Vector2 mousePt;


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

            isMenu = mainMenu(playButton, mousePt, isMenu);
            //----------------------------------------------------------------------------------
        } else { // Game loop

            DrawCircle(Player.x,Player.y,Player.radius, BLACK);

            // Update player based on movement
            Player = playerMovement(Player);

            // iterate through list of bullets, and draw them
            bulletUpdater(ammo);

            // Bullet spawner, if player fires
            shootBullet(Player);


        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    CloseWindow();        // Close window and OpenGL context

    return 0;
}