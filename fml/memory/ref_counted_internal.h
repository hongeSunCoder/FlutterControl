#ifndef ref_counted_internal_h
#define ref_counted_internal_h

#include <atomic>

#include "macros.h"

namespace fml
{

    namespace internal
    {
        class RefCountedThreadSafeBase
        {
        private:
            /* data */
            mutable std::atomic_uint_fast32_t ref_count_;

        public:
            void AddRef() const
            {
                ref_count_.fetch_add(1u, std::memory_order_relaxed);
            }

            bool HasOneRef() const
            {
                return ref_count_.load(std::memory_order_acquire) == 1u;
            }

        protected:
            RefCountedThreadSafeBase(/* args */);
            ~RefCountedThreadSafeBase();

            bool Release() const
            {

                if (ref_count_.fetch_sub(1u, std::memory_order_release) == 1u)
                {
                    std::atomic_thread_fence(std::memory_order_acquire);
                    return true;
                }

                return false;
            }
        };

        inline RefCountedThreadSafeBase ::RefCountedThreadSafeBase(/* args */)
            : ref_count_(1u)
        {
        }

        inline RefCountedThreadSafeBase ::~RefCountedThreadSafeBase()
        {
        }

    }
}

#endif