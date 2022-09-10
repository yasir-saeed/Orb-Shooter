std::list<user> powerups;
std::list<user>::iterator powerUpIterator;
std::list<user>::iterator collisionIterator;

void spawnPowerUp(){
    user PowerUp;
    PowerUp.x = GetRandomValue(0,GetScreenWidth()-15);
    PowerUp.y = GetRandomValue(0, GetScreenHeight()-15);
    PowerUp.spawnTime = GetTime();

    powerups.emplace_back(PowerUp);
}

void powerUpUpdater(std::list<user> &powerUpList){
    for (powerUpIterator = powerUpList.begin(); powerUpIterator != powerUpList.end();) {
        DrawCircle(powerUpIterator->x,powerUpIterator->y,powerUpIterator->radius,BLUE);

        if(GetTime() - powerUpIterator->spawnTime > 10 ){
            powerUpIterator = powerups.erase(powerUpIterator);
        }
        else{
            powerUpIterator++;
        }
    }
}


void userPowerUpCollision(user &Player,std::list<user> &powerUpList){
    for (collisionIterator = powerUpList.begin(); collisionIterator != powerUpList.end();) {

        if ((CheckCollisionCircles({(collisionIterator->x), (collisionIterator->y)}, collisionIterator->radius,
                                   {(Player.x), (Player.y)}, Player.radius))){


            collisionIterator = powerUpList.erase(collisionIterator);
            Player.powerUpSpeed = 2;

        }
        else{
            collisionIterator++;

        }

    }

}