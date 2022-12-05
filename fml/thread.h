//
//  thread.h
//  FlutterControl
//
//  Created by 孙红杰 on 2022/11/4.
//

#ifndef thread_h
#define thread_h

#include <atomic>
#include <functional>
#include <memory>
#include <string>
#include <thread>

#include "macros.h"

namespace fml
{

    class Thread
    {
    public:
        enum class ThreadPriority : int
        {
            Background,
            Normal,
            Display,
            Raster,
        };

        struct ThreadConfig
        {
            ThreadConfig(const std::string &name, ThreadPriority priority) : name(name), priority(priority) {}

            explicit ThreadConfig(const std::string &name) : ThreadConfig(name, ThreadPriority::Normal) {}

            ThreadConfig() : ThreadConfig("", ThreadPriority::Normal) {}

            std::string name;
            ThreadPriority priority;
        };

        using ThreadConfigSetter = std::function<void(const ThreadConfig &)>;

        explicit Thread(const std::string &name = "");

        explicit Thread(const ThreadConfigSetter &setter, const ThreadConfig &config = ThreadConfig());

        ~Thread();

        void Join();

        static void setCurrentThreadName(const ThreadConfig &config);

    private:
        std::unique_ptr<std::thread> thread_;

        std::atomic_bool joined_;

        FML_DISALLOW_COPY_AND_ASSIGN(Thread);
    };

}; // namespace fml

#endif /* thread_h */
