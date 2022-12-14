
struct user{
    float x,y;
    float radius = 15;
    int spawnTime;
    int powerUpSpeed = 1;
};


user playerMovement(struct user Player){

    // Player controls
    if (IsKeyDown(KEY_A)) {
        Player.x -= (200 * GetFrameTime()) * Player.powerUpSpeed;
    }
    if (IsKeyDown(KEY_D)) {
        Player.x += (200 * GetFrameTime()) * Player.powerUpSpeed;
    }

    if (IsKeyDown(KEY_W)) {
        Player.y -= (200 * GetFrameTime()) * Player.powerUpSpeed;
    }
    if (IsKeyDown(KEY_S)) {
        Player.y += (200 * GetFrameTime()) * Player.powerUpSpeed;
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
