var Tail = require(__dirname + '/../lib/nodeTail');
var fs = require('fs');

console.log(Tail);

var e = new Tail('test/test.txt');
e.on('data', function(data) {
	console.log(data);
});

function write() {
	fs.appendFile('message.txt', 'data to append\n', function (err) {
		if (err) {
			throw err;
		}
		console.log('The "data to append" was appended to file!');
	});
}

setInterval(write, 1000);