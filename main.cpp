#include "raylib.h"
#include "menus.h"
#include "movement.h"
#include "bullets.h"
#include "enemies.h"
#include "timer.h"



int main() {

        float enemySpawnTime = 2.5f;
        float powerUpSpawnTime = (float)GetRandomValue(0,30);

        Timer enemySpawner;
        Timer powerUpSpawner;
        powerUpSpawner.lifetime = powerUpSpawnTime;

        Timer powerUpLength;
        powerUpLength.lifetime = 15.0f;

        user Player;
        Player.x = 400.0f;
        Player.y = 300.0f;


        Vector2 mousePt;


        const int screenWidth = 800;
        const int screenHeight = 600;
        bool isMenu = true;
        bool loseState = false;
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
            }
            else { // Game loop

                Player = Player;
                // Keep track if enemy collides with player, or goes offscreen
                loseState = userEnemyCollision(Player, enemies, loseState);

                DrawText(TextFormat("SCORE: %i", score), 325, 20, 30, RED);


                if (!loseState) {

                    DrawCircle(Player.x, Player.y, Player.radius, BLACK);


                    Player = playerMovement(Player);

                    // Draw all bullets on screen
                    bulletUpdater(ammo);

                    // Bullet spawner, if player fires
                    shootBullet(Player);

                    // Draw all enemies on screen
                    enemyUpdater(enemies);

                    // check for collisions between bullets and enemies
                    bulletCollision(ammo, enemies);

                    powerUpUpdater(powerups);

                    // keep track of time between enemy spawns
                    updateTimer(&enemySpawner);
                    updateTimer(&powerUpSpawner);

                    // spawn enemies whenever timer completes, then reset timer
                    EnemySpawn(&enemySpawner,enemySpawnTime);

                    // spawn power ups when timer is done
                    powerUpSpawn(&powerUpSpawner);

                    // check if player collides with power up
                    userPowerUpCollision(Player,powerups);


                    // start countdown timer if player picks up power-up
                    if(Player.powerUpSpeed == 2){
                        DrawText(TextFormat("2x SPEED"), 350, 60, 20, BLACK);
                        updateTimer(&powerUpLength);

                        if(TimerDone(&powerUpLength)){
                            Player.powerUpSpeed = 1;
                            powerUpLength.lifetime = 15.0f;
                        }
                    }



                }
                // Game over screen if lose condition is met
                else{

                    GameOver();

                    if(CheckCollisionPointRec(mousePt,playAgainButton)
                       && ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT)))){
                        loseState = false;
                        isMenu = true;
                        score = 0;
                        Player.x = GetScreenWidth() / 2;
                        enemies = {};
                    }

                }

            }

            EndDrawing();
            //----------------------------------------------------------------------------------
        }

        CloseWindow();        // Close window and OpenGL context

        return 0;
    }

