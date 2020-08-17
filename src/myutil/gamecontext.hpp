#pragma once

#include <myutil/typealiases.hpp>

namespace ECS
{
    struct GameContext_t
    {
        virtual ~GameContext_t() = default;
        virtual const VecEntities_t& getEntities() const = 0;  // Interfaz virtual pura
    };
    
} // namespace ECS
