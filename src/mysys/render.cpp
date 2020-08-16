extern "C"{
    #include <tinyPTC/tinyptc.h>
}
#include <mysys/render.hpp>

namespace ECS
{
    RenderSystem_t::RenderSystem_t(uint32_t w, uint32_t h) : m_w { w }, m_h { h }
    {
        ptc_open("window", w, h);
    }

    RenderSystem_t::~RenderSystem_t()
    {
        ptc_close();
    }

} // namespace ECS
