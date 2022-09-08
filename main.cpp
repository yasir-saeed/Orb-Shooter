#include "raylib.h"
#include "mainmenu.h"
#include "movement.h"
#include "bullets.h"
#include "enemies.h"
#include "timer.h"

std::list<user>::iterator enemyIterTwo;
bool userEnemyCollision(user Player,std::list<user> &enemies, bool state){
    for (enemyIterTwo = enemies.begin(); enemyIterTwo != enemies.end();enemyIterTwo++) {

        if (CheckCollisionCircles({(enemyIterTwo->x), (enemyIterTwo->y)}, enemyIterTwo->radius,
                                  {(Player.x), (Player.y)}, Player.radius)){

            state = true;
        }
        else{
            state = false;
        }

    }
    return state;


}


int main() {

        float spawnTime = 2.5f;
        Timer enemySpawner;

        user Player;
        Player.x = 400.0f;
        Player.y = 300.0f;
        Player.health = 1;


    Rectangle playAgainButton = {300, 300, 200, 75};


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

                    // keep track of time between spawns
                    updateTimer(&enemySpawner);

                    // spawn enemies whenever timer completes, then reset timer
                    if (TimerDone(&enemySpawner)) {
                        SpawnEnemy();
                        enemySpawner.lifetime = spawnTime;
                    }



                }
                else{
                    DrawText("GAME OVER", (GetScreenWidth() / 2) - 95, 200, 30, RED);
                    DrawRectangle(playAgainButton.x,playAgainButton.y,playAgainButton.width,playAgainButton.height, RED);
                    DrawText("PLAY AGAIN", playAgainButton.x+35, playAgainButton.y+25, 20, WHITE);

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

