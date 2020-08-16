extern "C"{
    #include <tinyPTC/tinyptc.h>
}
#include <mysys/render.hpp>
#include <memory>

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

    void
    RenderSystem_t::update() const
    {
        auto screen = std::make_unique<uint32_t[]>(m_w*m_h);

        while(!ptc_process_events())
        {
            for(uint32_t i=0; i< 640*360; i++)
                screen[i] = kR;
            
            uint32_t *pscr = screen.get();
            const uint32_t *psp = sprite;

            for(uint32_t i=0; i<8; i++)
            {
                for(uint32_t j=0; j<8; j++)
                {
                    *pscr = *psp;
                    ++pscr;
                    ++psp;
                }
                pscr += 640 - 8;
            }

            ptc_update(screen.get());
        }
    }

} // namespace ECS
