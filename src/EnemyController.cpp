#include "EnemyController.h"

EnemyController::EnemyController(HollowKnight *hk)
{
    target = hk;
}
void EnemyController::modifyEnemies(std::vector<Object *> &enemies)
{
    srand(time(0));
    int randDecision = rand()%2;
    if(randDecision == 0) //Adding a crawlid enemy
    {
        double randLength = (rand()%880)+100;
        double randBreadth = (rand()%520) + 100;
        enemies.push_back(new Crawlid({randLength, randBreadth}, 80, 60));
    }
    else if(randDecision == 1) //Adding a shooting enemy
    {
        double randLength = (rand()%880)+100;
        double randBreadth = (rand()%520) + 100;
        enemies.push_back(new ShootingEnemy({randLength, randBreadth}, target));
    }
}