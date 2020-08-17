#pragma once
#include <cstdint>
#include <vector>
#include <myutil/typealiases.hpp>
#include <myutil/gamecontext.hpp>

namespace ECS
{
    struct EntityManager_t : public GameContext_t
    {
        static constexpr std::size_t k_NUMINITALENTITIES { 1000 };

        explicit EntityManager_t();

        void createEntity(uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint32_t color);

        const VecEntities_t& getEntities() const override { return m_Entity; }

    private:
        VecEntities_t m_Entity {};
    };
    
} // namespace ECS
