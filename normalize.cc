#include "normalize.h"

NAN_METHOD(normalize) {

  if (info.Length() < 1) {
    return Nan::ThrowError("parameter must be provided.");
  }
  Nan::Utf8String str(info[0]);

  info.GetReturnValue().Set(Nan::To<v8::String>(info[0]).ToLocalChecked());
}
