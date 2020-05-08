#include <node.h>

using namespace v8;

double factorial(double n) {
  if (n == 0)
    return 1;
  return n * factorial(n - 1);
}

void factorial(const v8::FunctionCallbackInfo<v8::Value>& info) {
  double n = info[0]->NumberValue();

  double result = factorial(n);

  v8::Local<v8::Number> Result = v8::Number::New(info.GetIsolate(), result);

  info
    .GetReturnValue()
    .Set(Result);
}

void Init(v8::Local<v8::Object> exports) {
  NODE_SET_METHOD(exports, "factorial", factorial);
}

NODE_MODULE(addon, Init)