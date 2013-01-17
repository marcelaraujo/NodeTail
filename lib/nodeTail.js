/*
 * nodeTail
 * https://github.com/marcelaraujo/NodeTail
 *
 * Copyright (c) 2013 Marcel Araujo
 * Licensed under the MIT license.
 */

var Emitter = require(__dirname + '/../build/Release/nodetail.node').Emitter;
var events = require('events');

inherits(Emitter, events.EventEmitter);
exports.Emitter = Emitter;

// extend prototype
function inherits(target, source) {
	for (var k in source.prototype) {
		target.prototype[k] = source.prototype[k];
	}
}
