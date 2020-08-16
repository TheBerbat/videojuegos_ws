extern "C"{
    #include <tinyPTC/tinyptc.h>
}
#include <mysys/render.hpp>
#include <cstdint>
#include <memory>

namespace ECS
{
    RenderSystem_t::RenderSystem_t(uint32_t w, uint32_t h) : m_w { w }, m_h { h }, m_framebuffer {std::make_unique<uint32_t[]>(m_w*m_h)}
    {
        ptc_open("window", w, h);
    }

    RenderSystem_t::~RenderSystem_t()
    {
        ptc_close();
    }

    //void
    //RenderSystem_t::drawSprite()
    //{
    //    uint32_t *pscr = screen.get();
    //    const uint32_t *psp = sprite;
    //
    //    for(uint32_t i=0; i<8; i++)
    //    {
    //        for(uint32_t j=0; j<8; j++)
    //        {
    //            *pscr = *psp;
    //            ++pscr;
    //            ++psp;
    //        }
    //        pscr += 640 - 8;
    //    }        
    //}

    bool
    RenderSystem_t::update() const
    {
        auto screen = m_framebuffer.get();

        for(uint32_t i=0; i< 640*360; i++)
            screen[i] = kR;
        
        ptc_update(screen);
        return !ptc_process_events();
    }

} // namespace ECS
