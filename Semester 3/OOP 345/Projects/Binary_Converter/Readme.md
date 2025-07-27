# Binary Converter Toolkit

Binary Converter Toolkit is a C++ console application that performs binary conversions, arithmetic, and bitwise operations, along with maintaining a history of user actions. Perfect for learning and experimenting with binary systems.

## Features

- Convert Decimal to Binary and Binary to Decimal  
- Binary Addition and Subtraction  
- Bitwise Operations: AND, OR, XOR  
- View History of Previous Operations  
- Built-in Error Handling

## File Structure

BinaryConverterToolkit/
├── main.cpp  
├── BinaryConverter.h / .cpp  
├── BinaryMath.h / .cpp  
├── BitwisePlayground.h / .cpp  
├── HistoryManager.h / .cpp  
└── README.md

## Compilation Instructions

Use any C++17 compatible compiler like g++

g++ main.cpp BinaryConverter.cpp BinaryMath.cpp BitwisePlayground.cpp HistoryManager.cpp -o BinaryToolkit

Run the program

./BinaryToolkit

## Sample Menu

==== Binary Converter Toolkit ====
1. Decimal to Binary  
2. Binary to Decimal  
3. Binary Add  
4. Binary Subtract  
5. Bitwise AND  
6. Bitwise OR  
7. Bitwise XOR  
8. Show History  
9. Exit

## Dependencies

Uses only standard C++17 libraries  
No external dependencies required

## Contributions

Pull requests welcome!  
You can fork the project and enhance features, add GUI, or improve UX.

## License

This project uses the MIT License.