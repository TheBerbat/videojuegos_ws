extern "C"{
    #include <tinyPTC/tinyptc.h>
}
#include <mysys/render.hpp>
#include <myman/entitymanager.hpp>
#include <algorithm>
#include <myutil/gamecontext.hpp>

namespace ECS
{
    RenderSystem_t::RenderSystem_t(uint32_t w, uint32_t h) 
     : m_w { w }
        , m_h { h }
        , m_framebuffer {std::make_unique<uint32_t[]>(m_w*m_h)}
    {
        ptc_open("window", w, h);
    }

    RenderSystem_t::~RenderSystem_t()
    {
        ptc_close();
    }

    void
    RenderSystem_t::drawAllEntities(const VecEntities_t& entities) const
    {
        for (auto& e : entities)
        {
            auto screen = m_framebuffer.get();
            screen += e.y*m_w + e.x;
            auto sprite_it = begin(e.sprite);

            for(uint32_t y=0; y<e.h ; ++y)
            {
                std::copy(sprite_it, sprite_it + e.w, screen);
                sprite_it += e.w;
                screen += m_w;
            }

        }    
    }

    bool
    RenderSystem_t::update(const GameContext_t& g) const
    {
        auto screen = m_framebuffer.get();
        const auto size = m_w*m_h;
        std::fill(screen, screen+size, kR);
        
        drawAllEntities(g.getEntities());

        ptc_update(screen);
        return !ptc_process_events();
    }

} // namespace ECS
