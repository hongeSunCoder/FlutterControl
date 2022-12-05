//
//  weak_ptr.h
//  FlutterControl
//
//  Created by 孙红杰 on 2022/11/9.
//

#ifndef weak_ptr_h
#define weak_ptr_h


#include <pthread.h>

namespace fml {

class ThreadChecker final {
private:
    pthread_t self_;
    
public:
    ThreadChecker(): self_(pthread_self()) {}
    ~ThreadChecker();
    
    bool IsCreationThreadCurrent() const {
        pthread_t current_thread = pthread_self();
        bool is_creation_thread_current = !!pthread_equal(current_thread, self_);
        
        if (!is_creation_thread_current) {
            static const int buffer_length = 128;
            char expected_thread[buffer_length];
            char actual_thread[buffer_length];
            
            if (0 == pthread_getname_np(current_thread, actual_thread, buffer_length)
                
                && 0 == pthread_getname_np(self_, expected_thread, buffer_length)) {
                // IsCreationThreadCurrent expected thread: $expected_thread,
                // actual thread: $actual_thread
            }
        }
        
        return is_creation_thread_current;
    }
};

#if !defined(NDEBUG)
#define FML_DECLARE_THREAD_CHECKER(c) fml::ThreadChecker c

#define FML_DCHECK_THREAD_IS_CURRENT(c) \
    (c).IsCreationThreadCurrent()

#endif

} //namespace fml


#endif /* weak_ptr_h */
