#include "ShootingEnemy.h"

ShootingEnemy::ShootingEnemy(Vec2D Epos, Object *Target)
	: shEnemyR("shEnemyRight.bmp", 1, 1), shEnemyL("shEnemyLeft.bmp", 1 ,1), Object(Epos, {0, 0}, 0.15, 53, 85, 1)
{
	m_Position.x = 0;
	m_Position.y = 0;
	m_Position.w = getLength();
	m_Position.h = getBredth();
    shEnemyR.selectSprite(0,0);
    shEnemyL.selectSprite(0,0);
    health = 4;
    target = Target;
    shootingDir.x = (target->pos.x) - (this->pos.x);
    shootingDir.y = (target->pos.y) - (this->pos.y);
    timepassed = 0.0;
    selectSprite = 0;
	
}


void ShootingEnemy::update(double delta_time)
{
    std::vector<CannonFire *>::iterator it;
    it = fires.begin();
    int i;
    for(i=0;i<fires.size();i++)
    {
        if(fires[i])
        {
            int result = fires[i]->fire(delta_time);
            if(result == 0)
            {
                delete(fires[i]);
                fires[i] = NULL;
                it+=i;
                fires.erase(it);
                i--;
            }
        }
    }
	shootingDir.x = (target->pos.x) - (this->pos.x);
    shootingDir.y = (target->pos.y) - (this->pos.y);
    timepassed += delta_time;
    fireReady(this->pos, target->pos);
    if(timepassed >= 10)
    {
        timepassed = 0.0;
        double mag = sqrt((shootingDir.x * shootingDir.x)+(shootingDir.y * shootingDir.y));
        fires.push_back(new CannonFire(this->pos, {(shootingDir.x/mag)*30, (shootingDir.y/mag)*30}));
    }
}

void ShootingEnemy::draw(SDL_Surface* surface, int x, int y)
{
	m_Position.x = pos.x - getLength() / 2;
	m_Position.y = pos.y - getBredth() / 2;
    int i;
    for(i=0;i<fires.size();i++)
    {
        if(fires[i])
        {
            fires[i]->draw(surface, 0, 0);
        }
    }
    if(selectSprite == 0)
    {
        shEnemyL.drawSelectedSprite(surface, &m_Position);
    }
    else if(selectSprite == 1)
    {
        shEnemyR.drawSelectedSprite(surface, &m_Position);
    }
}

int ShootingEnemy::reduceHealth() //If health becomes zero then destroy this enemy object
{
    if(health > 0)
    {
        health--;
    }
    return health;
}

void ShootingEnemy::fireReady(Vec2D myPos, Vec2D tPos)
{
    if(tPos.x < myPos.x)
    {
        selectSprite = 0;
    }
    else
    {
        selectSprite = 1;
    }
}

ShootingEnemy::~ShootingEnemy()
{
}