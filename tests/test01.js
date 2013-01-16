var addon = require('./../build/Release/nodetail.node');

addon.context.on = function(data) {
	console.log(data);
};

console.log( 'This should be eight:', addon.add(3,5) );