/*
 * nodeTail
 * https://github.com/marcelaraujo/NodeTail
 *
 * Copyright (c) 2013 Marcel Araujo
 * Licensed under the MIT license.
 */

var tail = require(__dirname + '/../build/Release/nodetail.node').Tail;
var events = require('events');

// extend prototype
function inherits(target, source) {
	for (var k in source.prototype) {
		target.prototype[k] = source.prototype[k];
	}
}

inherits(tail, events.EventEmitter);

module.exports = tail;