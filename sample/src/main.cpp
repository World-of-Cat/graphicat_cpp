#include <graphicat/graphicat.hpp>
#include <graphicat/os/window.hpp>

#include <memory>

enum class Mode { Left, Right, Windowed };

int main() {
    gc::GlobalState::init();

    gc::os::WindowProperties properties{};
    properties.title = "graphicat_sample";
    properties.window_mode = gc::os::wm::FullscreenWindowed(1);

    auto window = std::make_unique<gc::os::Window>(properties);

    Mode mode = Mode::Right;

    while (window->is_open()) {
        window->update();

        if (window->get_key(GLFW_KEY_LEFT)) {
            if (mode != Mode::Left) {
                window->set_window_mode(gc::os::wm::FullscreenExclusive{0});
                mode = Mode::Left;
            }
        }

        if (window->get_key(GLFW_KEY_RIGHT)) {
            if (mode != Mode::Right) {
                window->set_window_mode(gc::os::wm::FullscreenWindowed{1});
                mode = Mode::Right;
            }
        }

        if (window->get_key(GLFW_KEY_UP)) {
            if (mode != Mode::Windowed) {
                window->set_window_mode(gc::os::wm::Windowed{{800, 600}});
                mode = Mode::Windowed;
            }
        }
    }

    gc::GlobalState::terminate();
}