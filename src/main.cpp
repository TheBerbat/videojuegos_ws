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
        Render.update();
    }
    catch(std::exception& e)
    {
        std::cout << "Capturada\n";
    }
    catch(const char* s)
    {
        std::cout << "Capturado string " << s << "\n";
    }

    return 0;
}