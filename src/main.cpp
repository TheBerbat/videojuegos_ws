#include <cstdint>
#include <iostream>
#include <mysys/render.hpp>
#include <myman/entitymanager.hpp>

constexpr int kSCRWIDTH  { 640 };
constexpr int kSCRHEIGHT { 360 };

int main()
{
    try
    {
        ECS::EntityManager_t EntityMan;
        EntityMan.createEntity(20, 40, 16, 16, 0x0000FF00);
        EntityMan.createEntity(200, 100, 20, 20, 0x000FF0F0);
        const ECS::RenderSystem_t Render{kSCRWIDTH,kSCRHEIGHT,EntityMan};
        while(Render.update());
    }
    catch(...)
    {
        std::cout << "Capturada\n";
    }

    return 0;
}