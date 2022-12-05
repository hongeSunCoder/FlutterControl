//
//  weak_ptr_internal.cpp
//  FlutterControl
//
//  Created by 孙红杰 on 2022/11/8.
//

#include "weak_ptr_internal.hpp"

namespace fml {

namespace internal {

WeakPtrFlag::WeakPtrFlag() : is_valid_(true) {}
WeakPtrFlag::~WeakPtrFlag() {
    
    //should be invalidated before destruction
    //assert(!is_valid_)
}

void WeakPtrFlag::Invalidate() {
    //invalidation should happen exactly once
    // assert(is_valid_)
    is_valid_ = false;
}

}

}
