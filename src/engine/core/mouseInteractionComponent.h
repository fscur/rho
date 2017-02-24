#pragma once
#include <rho.h>
#include "coreApi.h"

#include <core/component.h>
#include <input/mouseEventArgs.h>
#include <animation/iMouseClickAnimatable.h>
#include <animation/iMouseHoverAnimatable.h>

namespace rho
{
    class node;

    class mouseInteractionComponent :
        public component
    {
    private:
        vector<std::function<void(node*)>> _onMouseDown;
        vector<std::function<void(node*)>> _onMouseUp;
        vector<std::function<void(mouseEventArgs*, node*)>> _onMouseMove;
        vector<std::function<void(node*)>> _onMouseEnter;
        vector<std::function<void(node*)>> _onMouseLeave;
        uint32_t _pickId;
        bool _isMouseOver;

        iMouseClickAnimatable* _mouseClickAnimatable;
        iMouseHoverAnimatable* _mouseHoverAnimatable;

    public:
        CORE_API mouseInteractionComponent();
        CORE_API mouseInteractionComponent(const mouseInteractionComponent& original);
        CORE_API ~mouseInteractionComponent();

        CORE_API void onMouseDown() const;
        CORE_API void onMouseUp() const;
        CORE_API void onMouseMove(mouseEventArgs* e) const;
        CORE_API void onMouseEnter();
        CORE_API void onMouseLeave();
        CORE_API void addOnMouseDown(std::function<void(node*)> onMouseDown);
        CORE_API void addOnMouseUp(std::function<void(node*)> onMouseUp);
        CORE_API void addOnMouseMove(std::function<void(mouseEventArgs*, node*)> onMouseMove);
        CORE_API void addOnMouseEnter(std::function<void(node*)> onMouseEnter);
        CORE_API void addOnMouseLeave(std::function<void(node*)> onMouseLeave);
        CORE_API void setMouseClickAnimatable(iMouseClickAnimatable* animatable);
        CORE_API void setMouseHoverAnimatable(iMouseHoverAnimatable* animatable);
        CORE_API component * clone() const;
        CORE_API vec3 getSelectionColor() const;
        CORE_API bool isMouseOver() const;

        uint32_t getId() { return _pickId; }
        void setId(uint32_t id) { _pickId = id; }

        static componentType getComponentType() { return componentType::CLICK; }
    };
}