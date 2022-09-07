
struct player{
    int x,y;
    int radius;
};


player playerMovement(struct player Player){

    // Player controls
    if (IsKeyDown(KEY_A)) {
        Player.x -= 200 * GetFrameTime();
    }
    if (IsKeyDown(KEY_D)) {
        Player.x += 200 * GetFrameTime();
    }

    if (IsKeyDown(KEY_W)) {
        Player.y -= 200 * GetFrameTime();
    }
    if (IsKeyDown(KEY_S)) {
        Player.y += 200 * GetFrameTime();
    }

    // Prevent user from going off-screen

    if(Player.x < 0 + Player.radius){
        Player.x = 0 + Player.radius;
    }
    else if(Player.x > GetScreenWidth() - Player.radius){
        Player.x = GetScreenWidth() - Player.radius;
    }

    if(Player.y < 0 + Player.radius){
        Player.y = 0 + Player.radius;
    }
    else if(Player.y > GetScreenHeight() - Player.radius){
        Player.y = GetScreenHeight() - Player.radius;
    }

    return Player;
}
