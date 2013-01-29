/*
 * Tail.h
 *
 *  Created on: 20/01/2013
 *  Author: Marcel
 */

#ifndef TAIL_H_
#define TAIL_H_

#include <v8.h>
#include <node.h>

using namespace v8;
using namespace std;
using namespace node;

class Tail : public node::ObjectWrap {
	private:
		~Tail();
	public:
		Tail(){};
		static Persistent<FunctionTemplate> constructor;
		static void Init(Handle<Object> target);
		static Handle<Value> New(const Arguments &args);
};

#endif /* TAIL_H_ */
