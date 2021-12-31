#include "Application.h"

Application::Application() : ph()
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
    objs.push_back(new HollowKnight());
    objs.push_back(new Ledge({540, 500} , {0}, 1080, 100));

}


void Application::loop()
{
    bool keep_window_open = true;
    while (keep_window_open)
    {
        while (SDL_PollEvent(&m_WindowEvent) > 0)
        {
            for (auto o : objs) {
                o->handle_events(m_WindowEvent);
            }
            switch (m_WindowEvent.type)
            {
                case SDL_QUIT:
                    keep_window_open = false;
                    break;
            }
        }

        update(1.0 / 60.0);
        draw();
    }
}

void Application::update(double delta_time)
{
    ph.update(delta_time, objs);
    for (auto o : objs) {
        o->update(delta_time);
    }
}

void Application::draw()
{
    SDL_FillRect(m_Surface, NULL, SDL_MapRGB(m_Surface->format, 255, 255, 255));

    for (auto o : objs) {
        o->draw(m_Surface);
    }

    SDL_UpdateWindowSurface(m_Window);
}


Application::~Application()
{
    SDL_FreeSurface(m_Surface);
    SDL_DestroyWindow(m_Window);
}
