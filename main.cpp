#include "raylib.h"
#include "mainmenu.h"
#include "movement.h"
#include "bullets.h"
#include "enemies.h"
#include "timer.h"


int main() {

        float spawnTime = 3.0f;
        Timer enemySpawner;

        user Player;
        Player.x = 400.0f;
        Player.y = 300.0f;
        Player.health = 1;


        Vector2 mousePt;


        const int screenWidth = 800;
        const int screenHeight = 600;
        bool isMenu = true;
        InitWindow(screenWidth, screenHeight, "development");
        SetTargetFPS(60);


        // Main game loop
        while (!WindowShouldClose())    // Detect window close button or ESC key
        {

            updateTimer(&enemySpawner);

            if(TimerDone(&enemySpawner)){
                SpawnEnemy();
                enemySpawner.lifetime = spawnTime;
            }

            mousePt = GetMousePosition();
            BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawFPS(10, 10);
            //----------------------------------------------------------------------------------
            if (isMenu) { // Game menu

                isMenu = mainMenu(playButton, mousePt, isMenu);
                //----------------------------------------------------------------------------------
            } else { // Game loop

                DrawCircle(Player.x, Player.y, Player.radius, BLACK);
                DrawText(TextFormat("SCORE: %i", score), 325, 20, 30, RED);


                // Update player based on movement
                Player = playerMovement(Player);

                // Draw all bullets on screen
                bulletUpdater(ammo);

                // Bullet spawner, if player fires
                shootBullet(Player);

                // Draw all enemies on screen
                enemyUpdater(enemies);

                // check for collisions between bullets and enemies
                bulletCollision(ammo,enemies);


            }

            EndDrawing();
            //----------------------------------------------------------------------------------
        }

        CloseWindow();        // Close window and OpenGL context

        return 0;
    }

