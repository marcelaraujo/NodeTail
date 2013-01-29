#include <v8.h>
#include <node.h>
#include <string.h>
#include <fstream>
#include "Sleep.h"
#include "Tail.h"

using namespace v8;
using namespace std;
using namespace node;

Persistent<FunctionTemplate> Tail::constructor;

// Initialize
void Tail::Init(Handle<Object> target) {
	HandleScope scope;

	// Setup the constructor
	Tail::constructor = Persistent<FunctionTemplate>::New(FunctionTemplate::New(Tail::New));
	Tail::constructor->InstanceTemplate()->SetInternalFieldCount(1); // for constructors
	Tail::constructor->SetClassName(String::NewSymbol("Tail"));

	target->Set(String::NewSymbol("Tail"), Tail::constructor->GetFunction());
}

Handle<Value> Tail::New(const Arguments &args) {
	HandleScope scope;

	assert(args.IsConstructCall());

	if (args.Length() < 1) {
		ThrowException(Exception::Error(String::New("File path is required.")));
		return scope.Close(Undefined());
	}

	if (!args[0]->IsString()) {
		ThrowException(Exception::TypeError(String::New("File path must be a string.")));
		return scope.Close(Undefined());
	}

	Tail *tail = new Tail();
	tail->Wrap(args.This());

	String::Utf8Value filename(args[0]);

	std::ifstream file;

	file.open( *filename, std::ios::binary );

	printf("looping");

	if( file.is_open() && file.good() ) {

		int length = 0;
		int position = 0;
		int last_position = -1;

		file.seekg( 0, std::ios::end );
		last_position = file.tellg();

		/*
		for(;;) {

			file.seekg( 0, std::ios::end );
			position = file.tellg();


			if ( position > last_position ) {

				file.seekg(last_position);

				length = position - last_position;

				char *buffer = new char[length];

				file.read(buffer, length);

				//string buffer_str(buffer, length);

				Local<String> name = String::New(buffer);

				printf("%s", *name);

				Handle<Value> argv[2] = { String::New("data"), name };

				MakeCallback(args.This(), "emit", 2, argv);

				last_position = position;

				delete[] buffer;
			}


			vi_sleep(1);
		}

		*/

	} else {
		// Close file pointer
		file.close();
		// Throws a exception when file is not found.
		ThrowException(Exception::Error(String::New("File doesn't exist.")));
		return scope.Close(Undefined());
	}

	return scope.Close(args.This());
}

Tail::~Tail() {
	// Perform cleanup
}

extern "C" void Init(Handle<Object> target) {
	HandleScope scope;

	Tail::Init(target);
}

NODE_MODULE(nodetail, Init)
