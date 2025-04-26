// This is a larger problem combining everything

// 1.
function splitIntoRows(data) {
    return data.replace(/\r\n/g, '\n').trim().split('\n');
  }
//2 
function splitAndTrimFields(row) {
    return row.split(',').map(field => field.trim());
  }
//3
function cleanName(name) {
    return name.replace(/\s+/g, ' ');
  }
//4
function extractAreaCode(phone) {
    const cleaned = phone.replace(/\D/g, ''); // remove non-digits
    return cleaned.slice(0, 3); // area code is first 3 digits
  }
//5
function convertHeight(height) {
    height = height.trim();
    if (height.endsWith('cm')) {
      const cm = parseInt(height);
      const inches = Math.round(cm / 2.54);
      return `${inches} inches`;
    }
    return height; // already in inches
  }
//6
function processRow(row) {
    const [id, name, phone, height] = splitAndTrimFields(row);
    const cleanedName = cleanName(name);
    const areaCode = extractAreaCode(phone);
    const convertedHeight = convertHeight(height);
    return `${id},${cleanedName},${areaCode},${convertedHeight}`;
  }
//7
function processCSV(data) {
    const rows = splitIntoRows(data);
    const processed = rows.map(processRow);
    return processed.join('\n');
  }
  
  const rawData = `
0134134,John Smith,555-567-2341,62 inches
0134135   ,    June    Lee    ,  5554126347 ,        149 cm
0134136,       Kim Thomas       , 5324126347, 138cm
`;

console.log(processCSV(rawData));
 
let s = "0123456789";
console.log(s);