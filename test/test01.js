var Emitter = require(__dirname + '/../lib/nodeTail').Emitter;

var e = new Emitter();

e.on('add', function(s) {
  console.error('You say ping, I say %s.', s);
});

// emits a 'ping' event from c++ land
e.add(5,3);