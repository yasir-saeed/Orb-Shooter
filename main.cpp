#include "raylib.h"
#include "mainmenu.h"
#include "movement.h"
#include <list>



struct bullet{
    int x,y;
    int radius = 10;
    bool isVisible = true;

};

std::list<bullet> objects;
std::list<bullet>::iterator iter;


void Spawn(int x,int y){
    bullet Bullet;
    Bullet.x = x;
    Bullet.y = y;
    objects.emplace_back(Bullet);
}


int main() {


    player Player;
    Player.x = 400;
    Player.y = 300;
    Player.radius = 15;



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

            isMenu = mainMenu(playButton, mousePt, isMenu);
            //----------------------------------------------------------------------------------
        } else { // Game loop

            DrawCircle(Player.x,Player.y,Player.radius, BLACK);
            Player = playerMovement(Player);

            // iterate through list of bullets, and draw them
            for (iter = objects.begin(); iter != objects.end();) {
                DrawCircle(iter->x,iter->y,iter->radius,BLACK);

                iter->y -= 350.0f * GetFrameTime();

                if(iter->y < 0)
                    iter = objects.erase(iter);
                else
                    iter++;

            }
            
            // Bullet spawner
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                Spawn(Player.x,Player.y);

            }




        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    CloseWindow();        // Close window and OpenGL context

    return 0;
}