// ...

let pass1 = encodeURIComponent('pa$$word1'); // this step is needed if there are special characters in your password, ie "$"
let db1 = mongoose.createConnection(
  `mongodb+srv://user:${pass1}@cluster0.abc123.mongodb.net/demo?retryWrites=true&w=majority`
);

// verify the db1 connection

db1.on('error', (err) => {
  console.log('db1 error!');
});

db1.once('open', () => {
  console.log('db1 success!');
});

// ...

let pass2 = encodeURIComponent('pa$$word2'); // this step is needed if there are special characters in your password, ie "$"
let db2 = mongoose.createConnection(
  `mongodb+srv://dbUser:${pass2}@cluster0.2def3.mongodb.net/db2?retryWrites=true&w=majority`
);

// ...

let model1 = db1.model('model1', model1Schema); // predefined "model1Schema" used to create "model1" on db1

let model2 = db2.model('model2', model2Schema); // predefined "model2Schema" used to create "model2" on db2

// ...