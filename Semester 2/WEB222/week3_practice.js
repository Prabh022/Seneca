function getDayOfWeek(day) {
    const days = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"];
    if (day >= 1 && day <= 7) {
      return days[day - 1];
    } else {
      return "Invalid day number";
    }
  }
console.log(getDayOfWeek(1));

//String Properties and Methods
let s = "Hello World!";
console.log(s.length); // 12
console.log(s.charAt(0)); // H
console.log(s.padStart(20, "*")); // *****Hello World!
console.log(s.padEnd(20, "*")); // Hello World!*****
console.log(s.included("World")); // true
console.log(s.startsWith("Hello")); // true
console.log(s.endsWith("u")); // false
console.log(s.indexOf("o")); // 4
console.log(s.lastIndexOf("o")); // 7
console.log(s.match(/o/g)); // [ 'o', 'o' ]
console.log(s.replace("World", "JavaScript")); // Hello JavaScript!
console.log(s.slice(0, 5)); // Hello
console.log(s.split(" ")); // [ 'Hello', 'World!' ]
console.log(s.toLowerCase()); // hello world!
console.log(s.toUpperCase()); // HELLO WORLD!
console.log(s.trim()); // Hello World!

// Array Properties and Methods
// methods that modify the original array
let arr = [1, 2, 3, 4, 5];
console.log(arr.push("Error!"));
arr.unshift("Error!");
console.log(arr.pop()); // 5
console.log(arr.pop()); // Error!
console.log(arr);

// methods that do not modify the original array
let arr2 = [1, 2, 3, 4, 5];
console.log(arr2.concat([6, 7, 8])); // [ 1, 2, 3, 4, 5, 6, 7, 8 ]
console.log(arr2.slice(0, 3)); // [ 1, 2, 3 ]
console.log(arr2.indexOf(3)); // 2  
console.log(arr2.lastIndexOf(3)); // 2

//methods for iterting across the elemens in an array
let arr3 = [1, 2, 3, 4, 5];
arr3.forEach((element) => {
    console.log(element); // 1 2 3 4 5
});
arr3.map((element) => {
    console.log(element * 2); // 2 4 6 8 10
} );
arr3.filter((element) => {
    return element > 2; // [ 3, 4, 5 ]
});
arr3.reduce((accumulator, currentValue) => {
    return accumulator + currentValue; // 15
}, 0);

// how to use regex in js
let str = "Hello World!";
let regex = /o/g; // global search for 'o'
console.log(str.match(regex)); // [ 'o', 'o' ]

function log(arr) {
    arr.forEach((element) => {
        console.log(element); 
    });
}

const shoppingList = [];
function addItemToHistory(item) {
    shoppingList.push(item);
    console.log(`Added ${item} to the shopping list.`);

}
console.log(addItemToHistory("milk")); // Added milk to the shopping list.
console.log(addItemToHistory("bread")); // Added bread to the shopping list.
console.log(shoppingList); // [ 'milk', 'bread' ]

function buildArray(n1 , n2) {
    let arr = [];
    for (let i = n1; i <= n2; i++) {
        arr.push(i);
    }
    return arr;

}
console.log(buildArray(2,9));

function addDollars(numbers) {
    return numbers.map(num => `$${num}`);
  }
  
  // Example usage:
  console.log(addDollars([1, 2, 3, 4])); 
  // Output: ['$1', '$2', '$3', '$4']
  
  function tidy(string ) {
    return string.trim();
    

  }
consolelog(tidy("   Hello World!   ")); // "Hello World!"

function measure(str) {
    let total = 0;
    string.forEAach(str=> {
        total += str.length;
    })
    return total;
}
console.log(measure(["a", "bc"])); // 3

function whereIsWaldo(str) {
    let index = str.indexOf("Waldo");
    if (index !== -1) {
        return `Waldo is at index ${index}`;
    } else {
        return "Waldo is not here!";
    }
}

