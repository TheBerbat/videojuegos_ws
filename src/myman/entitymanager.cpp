#include <myman/entitymanager.hpp>
#include <algorithm>

namespace ECS
{
    EntityManager_t::EntityManager_t()
    {
        m_Entity.reserve(k_NUMINITALENTITIES);
    }

    void EntityManager_t::createEntity(uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint32_t color)
    {
        Entity_t& e = m_Entity.emplace_back( w, h );
        e.x = x;
        e.y = y;
        std::fill(begin(e.sprite), end(e.sprite), color);
    }
} // namespace ECS
