std::list<user> enemies;
std::list<user>::iterator enemyIter;
std::list<user>::iterator enemyIterTwo;

// Spawn enemy and add it to list of enemies
void SpawnEnemy() {
    user Enemy;
    Enemy.x = GetRandomValue(0, GetScreenWidth());
    Enemy.y = -25.0f;

    enemies.emplace_back(Enemy);
}

// Draw enemy and update its position, removing it if goes off-screen
void enemyUpdater(std::list<user> &objects) {
    for (enemyIter = objects.begin(); enemyIter != objects.end();) {

        DrawCircle(enemyIter->x, enemyIter->y, enemyIter->radius, RED);
        enemyIter->y += 100.0f * GetFrameTime();

        if (enemyIter->y > GetScreenHeight()+15) {
            enemyIter = objects.erase(enemyIter);


        } else
            enemyIter++;
    }
}

// Check for collision between enemies and player
bool userEnemyCollision(user Player,std::list<user> &enemies, bool state){
    for (enemyIterTwo = enemies.begin(); enemyIterTwo != enemies.end();) {

        if ((CheckCollisionCircles({(enemyIterTwo->x), (enemyIterTwo->y)}, enemyIterTwo->radius,
                                   {(Player.x), (Player.y)}, Player.radius))
            || (enemyIterTwo->y > GetScreenHeight()+5)){

            state = true;
            break;
        }
        else{
            state = false;
            enemyIterTwo++;
        }

    }
    return state;
}