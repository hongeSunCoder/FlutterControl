//
//  scoped_nsobject.h
//  FlutterControl
//
//  Created by 孙红杰 on 2022/11/11.
//

#ifndef scoped_nsobject_h
#define scoped_nsobject_h

#import <Foundation/NSObject.h>



namespace fml {

template <typename NST>
class scoped_nsprotocol {
    
private:
    NST object_;
    
    [[nodiscard]] NST release() {
        NST temp = object_;
        object_ = nil;
        return temp;
    }
    
public:
    explicit scoped_nsprotocol(NST object = nil) : object_(object) {}
    
    scoped_nsprotocol(const scoped_nsprotocol<NST>& that) : object_([that.object_ retain]) {}
    
    ~scoped_nsprotocol() { [object_  release]; }
    
    scoped_nsprotocol& operator=(const scoped_nsprotocol<NST>& that) {
        
        
        reset([that.get() retain]);
        return *this;
    }
    
    
    void reset(NST object = nil) {
        [object_ release];
        object_ = object;
    }
    
    
    bool operator==(NST that) const { return object_ == that; }
    bool operator!=(NST that) const { return object_ != that; }
    
    operator NST() const { return object_; }
    
    NST get() const { return object_; }

    void swap(scoped_nsprotocol& that) {
        NST temp = that.object_;
        that.object_ = object_;
        object_ = temp;
    }
    
    // Shift reference to the autorelease pool to be released later.
    NST autorelease() { return [release() autorelease]; }
    
}

// Free functions
template <class C>
void swap(scoped_nsprotocol<C>& p1, scoped_nsprotocol<C>& p2) {
  p1.swap(p2);
}

template <class C>
bool operator==(C p1, const scoped_nsprotocol<C>& p2) {
  return p1 == p2.get();
}

template <class C>
bool operator!=(C p1, const scoped_nsprotocol<C>& p2) {
  return p1 != p2.get();
}


template <typename NST>
class scoped_nsobject : public scoped_nsprotocol<NST*> {
 public:
  explicit scoped_nsobject(NST* object = nil) : scoped_nsprotocol<NST*>(object) {}

  scoped_nsobject(const scoped_nsobject<NST>& that) : scoped_nsprotocol<NST*>(that) {}

  template <typename NSU>
  // NOLINTNEXTLINE(google-explicit-constructor)
  scoped_nsobject(const scoped_nsobject<NSU>& that) : scoped_nsprotocol<NST*>(that) {}

  scoped_nsobject& operator=(const scoped_nsobject<NST>& that) {
    scoped_nsprotocol<NST*>::operator=(that);
    return *this;
  }
};


// Specialization to make scoped_nsobject<id> work.
template <>
class scoped_nsobject<id> : public scoped_nsprotocol<id> {
 public:
  explicit scoped_nsobject(id object = nil) : scoped_nsprotocol<id>(object) {}

  scoped_nsobject(const scoped_nsobject<id>& that) : scoped_nsprotocol<id>(that) {}

  template <typename NSU>
  // NOLINTNEXTLINE(google-explicit-constructor)
  scoped_nsobject(const scoped_nsobject<NSU>& that) : scoped_nsprotocol<id>(that) {}

  scoped_nsobject& operator=(const scoped_nsobject<id>& that) {
    scoped_nsprotocol<id>::operator=(that);
    return *this;
  }
};

// Do not use scoped_nsobject for NSAutoreleasePools, use
// ScopedNSAutoreleasePool instead. This is a compile time check. See details
// at top of header.
template <>
class scoped_nsobject<NSAutoreleasePool> {
 private:
  explicit scoped_nsobject(NSAutoreleasePool* object = nil);
  FML_DISALLOW_COPY_AND_ASSIGN(scoped_nsobject);
};


} // namespace fml


#endif /* scoped_nsobject_h */
