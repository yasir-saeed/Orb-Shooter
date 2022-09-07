#include "raylib.h"
#include "mainmenu.h"
#include "movement.h"
#include "bullets.h"

std::list<user> enemies;
std::list<user>::iterator enemyIter;


void SpawnEnemy() {
    user Enemy;
    Enemy.x = GetRandomValue(0, GetScreenWidth());
    Enemy.y = 25.0f;
    Enemy.health = 1;

    enemies.emplace_back(Enemy);
}


void enemyUpdater(std::list<user> &objects) {
    for (enemyIter = objects.begin(); enemyIter != objects.end();) {


        DrawCircle(enemyIter->x, enemyIter->y, enemyIter->radius, RED);
        enemyIter->y += 100.0f * GetFrameTime();

        if (enemyIter->y > GetScreenHeight()) {
            enemyIter = objects.erase(enemyIter);
        } else
            enemyIter++;
    }
}



    int main() {


        user Player;
        Player.x = 400;
        Player.y = 300;


        Vector2 mousePt;


        const int screenWidth = 800;
        const int screenHeight = 600;
        bool isMenu = true;
        InitWindow(screenWidth, screenHeight, "development");
        SetTargetFPS(60);
        SpawnEnemy();

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

                DrawCircle(Player.x, Player.y, Player.radius, BLACK);

                // Update player based on movement
                Player = playerMovement(Player);

                // iterate through list of bullets, and draw them
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

