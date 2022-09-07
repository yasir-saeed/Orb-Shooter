#include <list>
int score;

struct bullet {
    float x, y;
    float radius = 10;
};

std::list<bullet> ammo;
std::list<bullet>::iterator iter;

std::list<user>::iterator collEnemy;
std::list<bullet>::iterator collBullet;

void Spawn(int x, int y) {
    bullet Bullet;
    Bullet.x = x;
    Bullet.y = y;
    ammo.emplace_back(Bullet);
}

void shootBullet(user Player) {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        Spawn(Player.x, Player.y);
    }
}

void bulletUpdater(std::list<bullet> &objects) {
    for (iter = objects.begin(); iter != objects.end();) {
        DrawCircle(iter->x, iter->y, iter->radius, BLACK);

        iter->y -= 350.0f * GetFrameTime();

// erase bullet if offscreen
        if (iter->y < 0)
            iter = objects.erase(iter);
        else
            iter++;
    }

}

void bulletCollision(std::list<bullet> &ammo, std::list<user> &enemies) {

    for (collBullet = ammo.begin(); collBullet != ammo.end(); collBullet++) {
        for (collEnemy = enemies.begin(); collEnemy != enemies.end();) {

            if (CheckCollisionCircles({(collBullet->x), (collBullet->y)}, collBullet->radius,
                                      {(collEnemy->x), (collEnemy->y)}, collEnemy->radius)) {

                collEnemy = enemies.erase(collEnemy);
                collBullet = ammo.erase(collBullet);
                score++;

            } else {
                collEnemy++;
            }
        }

    }
}