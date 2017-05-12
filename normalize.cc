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
    return Nan::ThrowError("query must be provided.");
  }

  Nan::Utf8String query(info[0]);
  PgQueryNormalizeResult result = pg_query_normalize(*query);

  if (result.error) {
    v8::Local<v8::String> message = Nan::New(result.error->message).ToLocalChecked();
    return Nan::ThrowError(message);
  }

  v8::Local<v8::String> normalized = Nan::New(result.normalized_query).ToLocalChecked();
  pg_query_free_normalize_result(result);

  info.GetReturnValue().Set(normalized);
}
