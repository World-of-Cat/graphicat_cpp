#pragma once
#include <memory>

#include <vulkan/vulkan.hpp>
#include <vulkan/vulkan_raii.hpp>

namespace gc {
    struct GraphicatProperties {};

    class GlobalState {
        inline static GlobalState *s_global_state;

        GlobalState(const GraphicatProperties &properties = {});

        vk::raii::Context context;
        vk::raii::Instance instance;
        vk::raii::PhysicalDevice physical_device;
        vk::raii::Device device;

      public:
        ~GlobalState();

        static void init(const GraphicatProperties &properties = {});
        static void terminate();

        static GlobalState *get();
    };

} // namespace gc