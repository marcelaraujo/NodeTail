#include <v8.h>
#include <node.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

using namespace node;
using namespace v8;

namespace {
	Handle<Value> Add(const Arguments& args) {
		HandleScope scope;

		if (args.Length() < 2) {
			ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
			return scope.Close(Undefined());
		}

		if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
			ThrowException(Exception::TypeError(String::New("Wrong arguments")));
			return scope.Close(Undefined());
		}

		Local<Number> num = Number::New(args[0]->NumberValue() + args[1]->NumberValue());

		return scope.Close(num);
	}

	extern "C" void Init(Handle<Object> target) {
		HandleScope scope;
		target->Set(String::NewSymbol("add"), FunctionTemplate::New(Add)->GetFunction());
	}
	
	NODE_MODULE(nodetail, Init)
}
