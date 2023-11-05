#include "graphicat.hpp"

#include "graphicat/os/window.hpp"

namespace gc {

    void GlobalState::init(const GraphicatProperties &properties) {
        if (!s_global_state)
            s_global_state = new GlobalState(properties);
    }

    void GlobalState::terminate() {
        delete s_global_state;
        s_global_state = nullptr;
    }

    GlobalState *GlobalState::get() { return s_global_state; }

    GlobalState::GlobalState(const GraphicatProperties &properties) {
        gc::os::WindowSystem::init();

        context = vk::raii::Context();

        vk::ApplicationInfo app_info{};
        app_info.apiVersion = VK_API_VERSION_1_3;

        uint32_t required_extension_count;
        const char **pp_required_instance_extensions = glfwGetRequiredInstanceExtensions(&required_extension_count);

        vk::InstanceCreateInfo instance_create_info{};
        instance_create_info.setPApplicationInfo(&app_info);
        instance_create_info.ppEnabledExtensionNames = pp_required_instance_extensions;
        instance_create_info.enabledExtensionCount = required_extension_count;

        instance = context.createInstance(instance_create_info);

        physical_device = instance.enumeratePhysicalDevices()[0];
    }

    GlobalState::~GlobalState() { gc::os::WindowSystem::terminate(); }
} // namespace gc