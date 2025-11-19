#pragma once
#include "GLFW/glfw3.h"


namespace Orion {

    enum EventType {
        // Keyboard Events
        EVENT_KEY_PRESSED,

        // Mouse Events
        EVENT_MOUSE_CURSOR_MOVE
    };


    struct EventKeyPressed {
        int GLFWKeyCode; // Should use custom keycodes at some point
    };

    struct EventMouseMove {
        int xpos;
        int ypos;
    };

    struct Event {
        EventType type;

        union {
            EventKeyPressed key_pressed_data;
            EventMouseMove mouse_move_data;
        } data;
    };

    typedef void (*EventCallback)(const Event& event, void* userData);

    struct EventSubscriber {
        EventType type;
        EventCallback callback;
        void* userData;
    };

    void poll_events();
    void init_event_system(GLFWwindow *window);
    void register_event(EventType type, EventCallback callback, void* userData = nullptr);
    void unregister_event(EventType type, EventCallback callback, void* userData = nullptr);
    void dispatch_event(const Event &event);
}