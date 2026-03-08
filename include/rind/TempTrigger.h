#pragma once

#include <engine/EntityManager.h>
#include <engine/Collider.h>

namespace rind {
    class TempTrigger : public engine::OBBCollider{
    public:
        TempTrigger(
            engine::EntityManager* entityManager,
            const std::string& name,
            const glm::mat4& transform,
            float lifetime = 1.0f
        ) : engine::OBBCollider(entityManager, transform, name), lifetime(lifetime) {
            setIsTrigger(true);
        }

        void update(float deltaTime) override {
            lifetime -= deltaTime;
            if (lifetime <= 0.0f) {
                getEntityManager()->markForDeletion(this);
            }
        }

    private:
        float lifetime = 0.5f;
    };
};