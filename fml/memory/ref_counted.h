#ifndef ref_counted_h
#define ref_counted_h

#include "macros.h"
#include "ref_counted_internal.h"
#include "ref_ptr.h"

namespace fml
{

    template <typename T>
    class RefCountedThreadSafe : public internal::RefCountedThreadSafeBase
    {
    private:
        /* data */
    protected:
        RefCountedThreadSafe(/* args */);
        ~RefCountedThreadSafe();

    public:
        void Release() const
        {
            if (internal::RefCountedThreadSafeBase::Release())
            {
                delete static_cast<const T *>(this);
            }
        }
    };

#define FML_FRIEND_REF_COUNTED_THREAD_SAFE(T) \
    friend class ::fml::RefCountedThreadSafe<T>

#define FML_FRIEND_MAKE_REF_COUNTED(T) \
    friend class ::fml::internal::MakeRefCountedHelper<T>

}

#endif
