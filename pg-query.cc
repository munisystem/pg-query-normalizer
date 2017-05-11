#include "normalize.h"

NAN_MODULE_INIT(init)
{
    NAN_EXPORT(target, normalize);
}

NODE_MODULE(index, init);
