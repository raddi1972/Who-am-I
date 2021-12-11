#include "Application.h"

Application::Application()
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

    m_Image = loadSurface("HollowKnight.bmp");

}


void Application::update()
{
    bool gameloop = true;
    while (gameloop)
    {
        while (SDL_PollEvent(&m_WindowEvent) > 0)
        {
            switch (m_WindowEvent.type)
            {
            case SDL_QUIT:
                gameloop = false;
                break;
            }
            SDL_UpdateWindowSurface(m_Window);
        }

        draw();
    }
}

void Application::draw()
{
    SDL_BlitSurface(m_Image, NULL, m_Surface, NULL);

    SDL_UpdateWindowSurface(m_Window);
}


Application::~Application()
{
    SDL_FreeSurface(m_Surface);
    SDL_DestroyWindow(m_Window);
}
