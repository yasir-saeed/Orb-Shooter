std::list<user> enemies;
std::list<user>::iterator enemyIter;
std::list<user>::iterator enemyIterTwo;


void SpawnEnemy() {
    user Enemy;
    Enemy.x = GetRandomValue(0, GetScreenWidth());
    Enemy.y = -25.0f;
    Enemy.health = 1;

    enemies.emplace_back(Enemy);
}


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

