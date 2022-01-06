#include "Application.h"

Application::Application() : ph(), pakka("pakka.bmp", 1080, 720), gameOver("GAME_OVER.bmp", 1080, 720)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }

    m_Window = SDL_CreateWindow("GAME", // creates a window
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIN_W, WIN_H, 0);

    if (!m_Window)
    {
        std::cout << "Failed to create the window" << std::endl;
        return;
    }

    m_Surface = SDL_GetWindowSurface(m_Window);

    if (!m_Surface)
    {
        std::cout << "Failed to get surface from the window" << std::endl;
        std::cout << "SDLError: " << SDL_GetError() << std::endl;
        return;
    }

    filecount = 0 ;
    filename = "HighestScores.txt";
    Health *health = new Health();
    NDCounter *scoreCounter = new NDCounter({1028,57});

    // Creating the main character
    hk = new HollowKnight(health, scoreCounter);
    ec = new EnemyController(hk);
    drawables.push_back(health);
    drawables.push_back(scoreCounter);
    objs.push_back(new Ledge({540, 720} , {0, 0}, 1080, 42));
    objs.push_back(new Ledge({0, 360} , {0, 0}, 16, 720));
    objs.push_back(new Ledge({1080, 360} , {0, 0}, 12, 720));
    objs.push_back(new Ledge({574, 37} , {0, 0}, 1080, 57));
    

    objs.push_back(new Ledge({540.5, 289.5}, {0, 0}, 25, 60));
    objs.push_back(new Ledge({546, 470} , {0, 0}, 77, 24));

    objs.push_back(new Ledge({305.5, 577}, {0, 0}, 25, 60));
    objs.push_back(new Ledge({776.5, 577}, {0, 0}, 25, 60));

    objs.push_back(new Ledge({440, 497}, {0, 0}, 25, 60));
    objs.push_back(new Ledge({642,497}, {0, 0}, 25, 60));

    objs.push_back(new Ledge({540, 683} , {0, 0}, 150, 69));

    objs.push_back(new Ledge({67.5, 653} , {0, 0}, 153, 54));
    objs.push_back(new Ledge({1012.5, 653} , {0, 0}, 153, 54));


    objs.push_back(new Ledge({540, 73} , {0, 0}, 415, 57));

    objs.push_back(new Ledge({338, 146} , {0, 0}, 18, 60));
    objs.push_back(new Ledge({742, 146} , {0, 0}, 18, 60));

    objs.push_back(new Ledge({28, 332} , {0, 0}, 32, 54));
    objs.push_back(new Ledge({1052, 332} , {0, 0}, 32, 54));
    

//######################
    objs.push_back(new Ledge({305, 346} , {0, 0}, 15, 97));

       
    objs.push_back(new Ledge({370, 312} , {0, 0}, 82, 27));
    objs.push_back(new Ledge({246, 384} , {0, 0}, 43, 29));


    objs.push_back(new Ledge({104, 491} , {0, 0}, 16, 23));



    objs.push_back(new Ledge({172, 203} , {0, 0}, 23, 26));
    objs.push_back(new Ledge({159, 232} , {0, 0}, 1, 18));
//######################
    objs.push_back(new Ledge({775, 346} , {0, 0}, 15, 97));
    
       
    objs.push_back(new Ledge({710, 312} , {0, 0}, 82, 27));
    objs.push_back(new Ledge({834, 384} , {0, 0}, 43, 29));


    objs.push_back(new Ledge({976, 491} , {0, 0}, 16, 23));



    objs.push_back(new Ledge({908, 203} , {0, 0}, 23, 26));
    objs.push_back(new Ledge({921, 232} , {0, 0}, 1, 18));


    // Creating new enemies
    enemies.push_back(new Crawlid({ 231, 652 }, 80, 60));
    enemies.push_back(new Crawlid({ 849, 652 }, 80, 60));
    enemies.push_back(new ShootingEnemy({ 800,500 }, hk));
}


void Application::loop()
{
    double timepassed = 0.0;
    bool keep_window_open = true;
    while (keep_window_open)
    {
        timepassed += 1.0/60.0;
        while (SDL_PollEvent(&m_WindowEvent) > 0)
        {
            hk->handle_events(m_WindowEvent);
            switch (m_WindowEvent.type)
            {
                case SDL_QUIT:
                    keep_window_open = false;
                    break;
            }
        }

        if(timepassed >= 400)
        {
            timepassed = 0.0;
            ec->modifyEnemies(enemies);
        }

        update(1.0 / 60.0);
        draw();
    }
}

void Application::update(double delta_time)
{
    ph.update(delta_time, objs, hk, enemies);

    for (auto obj : enemies) {
        ShootingEnemy* se = dynamic_cast<ShootingEnemy*> (obj);
        if(se)
            se->collideFireBalls(hk, ph, objs);
        

    }


    for (auto obj : enemies) {
        if (hk->getAttack()) {
            if (ph.detectCollision(*hk->getAttack(), *obj)) {
                Enemy* em = dynamic_cast<Enemy*> (obj);
                if (em) {
                    em->reduceHealth();
                    delete hk->getAttack();
                    hk->setAttack();
                    if (hk->isFacingRight) hk->vel.x -= 15;
                    else hk->vel.y += 15;
                }
            }
        }
    }

    for (int i = 0; i < enemies.size(); i++) {
        Enemy* em = dynamic_cast<Enemy*> (enemies[i]);
        if (em) {
            if (em->health <= 0) {
                enemies.erase(enemies.begin() + i);
                hk->increaseScore();
            }
        }
    }

    for (auto o : enemies) {
        if (ph.detectCollision(*o, *hk)) {
            std::cout << "collided" << std::endl;
            ph.collisionHandler(*hk, *o);
            hk->reduceHealth();
            if (hk->vel.y > 2 || hk->vel.y < -2) {
                hk->vel.y = -100;
            }
            else {
                if (hk->isFacingRight) {
                    hk->vel.x = -15;
                }
                else {
                    hk->vel.x = 15;
                }
                Crawlid* c = dynamic_cast<Crawlid*> (o);
                if (c) {
                    if (c->isFacingRight) c->vel.x = -5;
                    else c->vel.x = 5;

                }
            }
        }
    }

    hk->update(delta_time);
    for (auto obj : drawables) {
        obj->update(delta_time);
    }

    for (auto obj : enemies) {
        obj->update(delta_time);
    }
}

void Application::draw()
{
    if (hk->getHealth()->getHealth() == 0)
    {
        filecount++;
        if(filecount == 1)
        {
            std::ofstream file_out;
            file_out.open(filename, std::ios_base::app);
            file_out << "Highest Score for the game : "<<hk->getScore()<<std::endl;
            file_out.close();
        }
        gameOver.moveMap(0, 0);
        gameOver.drawMap(m_Surface);
        hk->getHealth()->flag=false;
    }
    else {
        pakka.moveMap(0, 0);
        pakka.drawMap(m_Surface);
    
        hk->draw(m_Surface, objs[0]->getPos().x - 500 + 42, objs[0]->getPos().y - 400 + 42);
    
        for (Object* obj : drawables) {
            obj->draw(m_Surface, 0, 0);
        }
        for (auto obj : enemies) {
            obj->draw(m_Surface, 0, 0);
        }

    }
    SDL_UpdateWindowSurface(m_Window);
}


Application::~Application()
{
    SDL_FreeSurface(m_Surface);
    SDL_DestroyWindow(m_Window);
}
