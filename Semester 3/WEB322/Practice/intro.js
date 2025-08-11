let worker = {
    name: "Joe",
    age:  36,
    city: "Toronto",
    setName : function(newname) {
        this.name = newname;
    },
    setAge : function(newAge) {
        this.age = newAge;
    },
};

console.log(worker.name); // Joe
worker.setName("John"); 
console.log(worker.name); // John
console.log(worker.age); // 36

const PI = 3.14159;

console.log('trying to change PI!');

try {
  PI = 99;
} catch (ex) {
  console.log(`uh oh, an error occurred: ${ex.message}`);
  // outputs: uh oh, an error occurred: Assignment to constant variable.
}

console.log(`Alas, it cannot be done, PI remains: ${PI}`);

function connectToDatabase(queryData, query) {
  let randomTime = Math.floor(Math.random() * 2000) + 1;
    console.log('Connecting to the database...');

  setTimeout(() => {
    console.log('Connection Established');
    queryData(query);
  }, randomTime);
}

function queryData(query) {
  let randomTime = Math.floor(Math.random() * 1000) + 1;

  setTimeout(() => {
    console.log(query);
  }, randomTime);
}

connectToDatabase(queryData, 'select * from Employees');

// output "A" after a random time between 0 & 3 seconds
async function outputA() {
  let randomTime = Math.floor(Math.random() * 3000) + 1;

  return new Promise((resolve, reject) => {
    // place our code inside a "Promise" function
    setTimeout(() => {
      console.log('-');
      reject('outputA rejected!'); // call "reject" because the function encountered an error
    }, randomTime);
  });
}

// call the outputA function and when it is "resolved" or "rejected, output a confirmation to the console

outputA()
  .then((data) => {
    console.log(data);
  })
  .catch((reason) => {
    console.log(reason);
  });