#include <cstdint>
#include <iostream>
#include <mysys/render.hpp>

constexpr int kSCRWIDTH  { 640 };
constexpr int kSCRHEIGHT { 360 };

int main()
{
    try
    {
        const ECS::RenderSystem_t Render{kSCRWIDTH,kSCRHEIGHT};
        while(Render.update());
    }
    catch(...)
    {
        std::cout << "Capturada\n";
    }

    return 0;
}