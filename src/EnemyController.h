#pragma once
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "HollowKnight.h"
#include "Crawlid.h"
#include "ShootingEnemy.h"
class EnemyController
{
    private:
        std::vector<Object *> eList;
        HollowKnight *target;
    public:
        EnemyController(HollowKnight * hk);
        ~EnemyController() {}

        void modifyEnemies(std::vector<Object *> &enemies);
};