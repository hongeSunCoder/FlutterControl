//
//  weak_ptr_internal.hpp
//  FlutterControl
//
//  Created by 孙红杰 on 2022/11/8.
//

#ifndef weak_ptr_internal_hpp
#define weak_ptr_internal_hpp

#include "macros.h"
#include "ref_counted.h"

namespace fml {
namespace internal {

class WeakPtrFlag : public fml::RefCountedThreadSafe<WeakPtrFlag> {

public:
    WeakPtrFlag();
    
    ~WeakPtrFlag();
    
    bool is_valid() const {return is_valid_;}
    
    void Invalidate();
    
private:
    bool is_valid_;
};

} //namespace internal
} //namespace fml

#endif /* weak_ptr_internal_hpp */
