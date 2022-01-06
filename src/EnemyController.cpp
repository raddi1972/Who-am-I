#include "EnemyController.h"

EnemyController::EnemyController(std::vector<Object *> enemies)
{
    int i;
    for(i=0;i<enemies.size();i++)
    {
        eList.push_back(enemies[i]);
    }
}
void EnemyController::modifyEnemies(std::vector<Object *> &enemies)
{
    for(int i=0;i<enemies.size();i++)
    {
        delete(enemies[i]);
        enemies[i]=NULL;
    }
    enemies.clear();
    std::vector<Object *>::iterator it;
    it = eList.begin();
    std::vector<int> indices;
    for(int i=0;i<eList.size();i++)
    {
        indices.push_back(i);
    }
    std::random_shuffle(indices.begin(), indices.end());
    for(int i=0;i<3;i++)
    {
        enemies.push_back(eList[indices[i]]);
    }
}