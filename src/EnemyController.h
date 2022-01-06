#pragma once
#include <vector>
#include <algorithm>
#include "Object.h"
class EnemyController
{
    private:
        std::vector<Object *> eList;
    public:
        EnemyController(std::vector<Object *> enemies);
        ~EnemyController() {}

        void modifyEnemies(std::vector<Object *> &enemies);
};