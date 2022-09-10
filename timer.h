#include "raylib.h"
#include "powerups.h"

struct Timer{
    float lifetime;
};



void updateTimer(Timer* timer){
    // subtract this frame from the timer if it's not already expired
    if (timer != NULL && timer->lifetime > 0) {
        timer->lifetime -= GetFrameTime();
    }
}

// check if a timer is done.
bool TimerDone(Timer* timer)
{
    if (timer != NULL)
        return timer->lifetime <= 0;

    return false;
}

void EnemySpawn(Timer* timer,float spawnTime){
    if (TimerDone(timer)) {
        SpawnEnemy();
        timer->lifetime = spawnTime;
    }
}

void powerUpSpawn(Timer* timer){
    if(TimerDone(timer)){
        spawnPowerUp();
        timer->lifetime = (float)GetRandomValue(30,60);
    }
}