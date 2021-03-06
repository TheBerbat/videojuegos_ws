#pragma once
#include <cstdint>
#include <memory>
#include <myutil/typealiases.hpp>

//#ifndef CONSTANTE
//#define CONSTANTE
//
//#endif

namespace ECS
{

    struct EntityManager_t;
    struct Entity_t;
    struct GameContext_t;
    
    struct RenderSystem_t
    {

        explicit RenderSystem_t(uint32_t w, uint32_t h);
        ~RenderSystem_t();

        bool update(const GameContext_t& g) const;
        void drawAllEntities(const VecEntities_t& entities) const;

        static constexpr uint32_t kR = 0x00FF0000;
        static constexpr uint32_t kG = 0x0000FF00;
        static constexpr uint32_t kB = 0x000000FF;
        static constexpr uint32_t sprite[8*8] ={
            kG, kG, kG, kG, kG, kG, kG, kG
           ,kG, kB, kR, kR, kR, kR, kB, kG
           ,kG, kB, kG, kG, kG, kG, kB, kG
           ,kG, kB, kG, kR, kR, kG, kB, kG
           ,kG, kB, kG, kR, kR, kG, kB, kG
           ,kG, kB, kG, kG, kG, kG, kB, kG
           ,kG, kB, kR, kR, kR, kR, kB, kG
           ,kG, kG, kG, kG, kG, kG, kG, kG
        };


        private:
            const uint32_t m_w { 0 }, m_h { 0 };
            std::unique_ptr<uint32_t[]> m_framebuffer { nullptr };
    };

} // namespace ECS
