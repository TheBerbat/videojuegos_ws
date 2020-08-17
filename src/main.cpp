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
        const ECS::RenderSystem_t Render{kSCRWIDTH,kSCRHEIGHT};
        while(Render.update( EntityMan ));
    }
    catch(...)
    {
        std::cout << "Capturada\n";
    }

    return 0;
}
//dwkjnbhwd