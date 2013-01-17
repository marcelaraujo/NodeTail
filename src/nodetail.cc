#include <v8.h>
#include <node.h>
#include <stdlib.h>

using namespace node;
using namespace v8;

namespace {

	struct Emitter: ObjectWrap {
		static Handle<Value> New(const Arguments& args);
		static Handle<Value> Add(const Arguments& args);
	};

	Handle<Value> Emitter::New(const Arguments& args) {
		HandleScope scope;

		assert(args.IsConstructCall());
		Emitter* self = new Emitter();
		self->Wrap(args.This());

		return scope.Close(args.This());
	}

	Handle<Value> Emitter::Add(const Arguments& args) {
		HandleScope scope;

		printf("add\n");

		if (args.Length() < 2) {
			ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
			return scope.Close(Undefined());
		}

		if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
			ThrowException(Exception::TypeError(String::New("Wrong arguments")));
			return scope.Close(Undefined());
		}

		Local<Number> num = Number::New(args[0]->NumberValue() + args[1]->NumberValue());

		Handle<Value> argv[2] = {
			String::New("add"),
			num
		};

		MakeCallback(args.This(), "emit", 2, argv);

		return Undefined();
	}

	extern "C" void Init(Handle<Object> target) {
		HandleScope scope;

		printf("init\n");

		Local<FunctionTemplate> t = FunctionTemplate::New(Emitter::New);
		t->InstanceTemplate()->SetInternalFieldCount(1);
		t->SetClassName(String::New("Emitter"));

		NODE_SET_PROTOTYPE_METHOD(t, "add", Emitter::Add);

		target->Set(String::NewSymbol("Emitter"), t->GetFunction());
		//target->Set(String::NewSymbol("add"), FunctionTemplate::New(Add)->GetFunction());
	}
	
	NODE_MODULE(nodetail, Init)
}
