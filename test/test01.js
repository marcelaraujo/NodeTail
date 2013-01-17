/*
 * nodeTail
 * https://github.com/marcelaraujo/NodeTail
 *
 * Copyright (c) 2013 Marcel Araujo
 * Licensed under the MIT license.
 */
 
var Emitter = require(__dirname + '/../lib/nodeTail');

var e = new Emitter();

e.on('add', function(s) {
  console.error('You say ping, I say %s.', s);
});

// emits a 'ping' event from c++ land
e.add(5,3);