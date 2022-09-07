#include <list>


struct bullet{
    int x,y;
    int radius = 10;
};

std::list<bullet> ammo;
std::list<bullet>::iterator iter;



void Spawn(int x,int y){
    bullet Bullet;
    Bullet.x = x;
    Bullet.y = y;
    ammo.emplace_back(Bullet);
}

void shootBullet(player Player){
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        Spawn(Player.x,Player.y);
    }
}

void bulletUpdater(std::list<bullet>& objects){
    for (iter = objects.begin(); iter != objects.end();) {
        DrawCircle(iter->x,iter->y,iter->radius,BLACK);

        iter->y -= 350.0f * GetFrameTime();

// erase bullet if offscreen
        if(iter->y < 0)
            iter = objects.erase(iter);
        else
            iter++;
    }

}