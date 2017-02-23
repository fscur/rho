#pragma once
#include <rho.h>
#include "animationApi.h"
#include "animation.h"

#include <core\component.h>

namespace rho
{
    class animator :
        public component
    {
    private:
        vector<animation*> _animations;

    public:
        static componentType getComponentType() { return componentType::ANIMATOR; }

    public:
        ANIMATION_API animator();
        ANIMATION_API animator(const animator& original);
        ANIMATION_API ~animator();
        ANIMATION_API void addAnimation(animation* animation);
        ANIMATION_API void animate();

        ANIMATION_API component* clone() const override;
    };
}