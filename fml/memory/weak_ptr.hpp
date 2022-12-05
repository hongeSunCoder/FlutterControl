//
//  weak_ptr.hpp
//  FlutterControl
//
//  Created by 孙红杰 on 2022/11/8.
//

#ifndef weak_ptr_hpp
#define weak_ptr_hpp

#include <utility>


#include "ref_counted.h"
#include "weak_ptr_internal.hpp"
#include "thread_checker.h"

namespace fml {

struct DebugThreadChecker {
    FML_DECLARE_THREAD_CHECKER(checker);
};


template <typename T>
class WeakPtrFactory;


template <typename T>
class WeakPtr {
    
private:
    template <typename U>
    friend class WeakPtr;
    
    friend class WeakPtrFactory<T>;
    
    explicit WeakPtr(T* ptr, fml::RefPtr<fml::internal::WeakPtrFlag>&& flag, DebugThreadChecker checker) : ptr_(ptr), flag_(std::move(flag)), checker_(checker) {}
    
    
    T* ptr_;
    fml::RefPtr<fml::internal::WeakPtrFlag> flag_;
    DebugThreadChecker checker_;

protected:
    explicit WeakPtr(T* ptr, fml::RefPtr<fml::internal::WeakPtrFlag>&& flag) : ptr_(ptr), flag_(std::move(flag)) {}
    
    void CheckThreadSafe() const {
        FML_DCHECK_THREAD_IS_CURRENT(checker_.checker);
    }
    
public:
    WeakPtr() : ptr_(nullptr) {}
    
    // copy constructor
    WeakPtr(const WeakPtr<T>& r) = default;
    
    template <typename U>
    WeakPtr(const WeakPtr<U>& r) : ptr_(static_cast<T*>(r.ptr_)), flag_(r.flag_), checker_(r.checker_) {}
    
    // move constructor
    WeakPtr(WeakPtr<T>&& r) = default;
    
    template <typename U>
    WeakPtr(WeakPtr<U>&& r) : ptr_(static_cast<T*>(r.ptr_)), flag_(std::move(r.flag_)), checker_(r.checker_) {}
    
    
    //copy assignment
    WeakPtr<T>& operator=(const WeakPtr<T>& r) = default;
    
    //move assignment
    WeakPtr<T>& operator=(WeakPtr<T>&& r) = default;
    
    
    void reset() {flag_ = nullptr;}
    
    
    
    
};


template <typename T>
class WeakPtrFactory {
    
private:
    T* const ptr_;
    fml::RefPtr<fml::internal::WeakPtrFlag> flag_;
    
    void CheckTreadSafe() const {
        FML_DCHECK_CREATION_THREAD_IS_CURRENT(checker_.checker);
    }
    
    DebugThreadChecker checker_;
public:
    explicit WeakPtrFactory(T* ptr): ptr_(ptr), flag_(fml::MakeRefCounted<fml::internal::WeakPtrFlag>()) {
        //fml_dcheck(ptr_);
    }
    
    ~WeakPtrFactory() {
        CheckThreadSafe();
        flag_->Invalidate();
    }
    
    
    // Gets a new weak pointer, which will be valid until this object is
    // destroyed.
    WeakPtr<T> GetWeakPtr() const {
        return WeakPtr<T>(ptr_, flag_.Clone(), checker_);
    }
}


} // namespace fml



#endif /* weak_ptr_hpp */
