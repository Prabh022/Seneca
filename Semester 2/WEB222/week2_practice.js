/*
This are the practices question of the week 2 of the WEB222 course
Questions 1 and 5 are not included in this file yet. Howeverm it 
might be added in the future.
*/


//6. Question

function sum(...args) {
    return args.reduce((acc, curr) => acc + curr, 0);
}

console.log(sum(1,5,14,2));

//7. Question

function allExist(...args) {
    return args.every(args => args != null && args != undefined && args != '' )
}
console.log(allExist(1,5,14,0,1));
console.log(allExist(1,5,14,1));

//8 Question

function generateName(name) {
    return name + ".js";
}

console.log(generateName("dog")); // Output: "dog.js"

//9. Question

function multipleof3(num) {
    return num % 3 === 0;
}
console.log(multipleof3(9)); // Output: true

//10. Question

function checkBetween(num, min, max) {
    return num >= min && num <= max;
}
console.log(checkBetween(5, 1, 10)); // Output: true

//11. Question

function calculateHST(amount) {
    return amount * 0.13;
}

// Example usage:
console.log(calculateHST(100)); // Output: 13

//12. Question

function discountPrice(price, discount) {
    return price - (price * (discount / 100));
}
// Example usage:
console.log(discountPrice(100, 20)); // Output: 80
//13. Question

function formatTime(seconds) {
    const days = Math.floor(seconds / (24 * 3600));
    seconds %= (24 * 3600);
    const hours = Math.floor(seconds / 3600);
    seconds %= 3600;
    const minutes = Math.round(seconds / 60);
    return `${days} Days, ${hours} Hours, ${minutes} Minutes`;
}
console.log(formatTime(100000)); // Output: "1 Days, 3 Hours, 46 Minutes"

//14. Question
function reverseAndConcatenate(str1, str2) {
    return str1.split('').reverse().join('') + str2.split('').reverse().join('');
}
console.log(reverseAndConcatenate("hello", "world")); // Output: "ollehdrow"
//15. Question
function formatDuration(seconds) {
    const totalMinutes = Math.round(seconds / 60);

    const days = Math.floor(totalMinutes / 1440); // 1440 minutes in a day
    const hours = Math.floor((totalMinutes % 1440) / 60);
    const minutes = totalMinutes % 60;

    const parts = [];

    if (days > 0) parts.push(`${days} Day${days !== 1 ? 's' : ''}`);
    if (hours > 0) parts.push(`${hours} Hour${hours !== 1 ? 's' : ''}`);
    if (minutes > 0 || parts.length === 0) {
        parts.push(`${minutes} Minute${minutes !== 1 ? 's' : ''}`);
    }

    return parts.join(', ');
}
console.log(formatDuration(60));         // "1 Minute"
console.log(formatDuration(18300));      // "5 Hours, 5 Minutes"
console.log(formatDuration(98765));      // "1 Day, 3 Hours, 26 Minutes"
console.log(formatDuration(0));          // "0 Minutes"

//16. Question
function sumAsInteger(num1, num2) {
    return Math.floor(num1 + num2);

}
console.log(sumAsInteger(1.5, 2.3)); // Output: 3
//17. Question
function findMatches(...args) {
    const matches = args.filter((item, index) => args.indexOf(item) !== index);
    return [...new Set(matches)];
}
console.log(findMatches(1, 2, 3, 1, 2, 4)); // Output: [1, 2]
//18. Question  
function showOutsideByteRange(...args) {
    args.forEach(num => {
        if (num > 255) {
            console.log(num)
        }
    });
}
showOutsideByteRange(1, 5, 233, 255, 256, 0); // Logs: 256
showOutsideByteRange(100, 300, 400);         // Logs: 300, 400

//19. Question
function prepareString(str) {
    return encodeURIComponent(str)
}
console.log(prepareString("hello world")); // Output: "hello%20world"
console.log(prepareString("name=John&Doe")); // Output: "name%3DJohn%26Doe"
//20. Question
function buildQueryString(...args) {
    return "?" + args.map(encodeURIComponent).join("&");
}
console.log(buildQueryString("name=John", "age=30")); // Output: "?name%3DJohn&age%3D30"
//21. Question
function applyFn(fn, ...nums) {
    return nums.reduce((total, num) => total + fn(num), 0);
}
console.log(applyFn(function(x) { return x * x; }, 1, 2, 3));
// Output: 14  → (1*1 + 2*2 + 3*3 = 1 + 4 + 9 = 14)
