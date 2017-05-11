#include "normalize.h"

static void initialize() {
  static bool initialized = false;
  if (!initialized) {
    pg_query_init();
    initialized = true;
  }
}

NAN_METHOD(normalize) {
  initialize();

  if (info.Length() < 1) {
    return Nan::ThrowError("parameter must be provided.");
  }
  Nan::Utf8String str(info[0]);

  info.GetReturnValue().Set(Nan::To<v8::String>(info[0]).ToLocalChecked());
}
