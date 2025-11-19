#include "Orion/Event.h"
#include "Orion/Window.h"
#include <iostream>
#include <vector>
#include <algorithm>

namespace Orion {

    std::vector<EventSubscriber> subscribers;

    void init_event_system(GLFWwindow *window) {
        glfwSetKeyCallback(window, Orion::key_callback);
        glfwSetCursorPosCallback(window, Orion::cursor_callback);
    }

    void poll_events() {
        glfwPollEvents();
    }

    void register_event(EventType type, EventCallback callback, void* userData){
        
        EventSubscriber sub;
        sub.type = type;
        sub.callback = callback;
        sub.userData = userData;

        subscribers.push_back(sub);
    }


    void unregister_event(EventType type, EventCallback callback, void* userData) {
        subscribers.erase(
            std::remove_if(subscribers.begin(), subscribers.end(),
                [type, callback, userData](const EventSubscriber& sub) {
                    return sub.type == type &&
                           sub.callback == callback &&
                           sub.userData == userData;
                }),
            subscribers.end()
        );
    }


    void dispatch_event(const Event &event) {
        for (auto& subscriber: subscribers) {
            if (!subscriber.callback) {
                // Should maybe deregister
                continue;
            }

            if (subscriber.type == event.type) {
                subscriber.callback(event, subscriber.userData);
            }
        }
    }

}