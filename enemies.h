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

        if (enemyIter->y > GetScreenHeight()+15) {
            enemyIter = objects.erase(enemyIter);


        } else
            enemyIter++;
    }
}