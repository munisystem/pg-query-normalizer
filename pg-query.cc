#include <nan.h>

NAN_METHOD(normalize)
{
    info.GetReturnValue().Set(Nan::New("Hello pg-query-normalizer!!").ToLocalChecked());
}

NAN_MODULE_INIT(init)
{
    NAN_EXPORT(target, normalize);
}

NODE_MODULE(index, init);
