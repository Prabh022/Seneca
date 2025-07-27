#include "BitwisePlayground.h"  
#include "BinaryConverter.h"  

#include <bitset>  
#include <tuple> // Include this header for std::tuple  

std::pair<std::string, std::string> pad(const std::string& a, const std::string& b) {  
  size_t maxLen = std::max(a.size(), b.size());  
  std::string aPad = std::string(maxLen - a.size(), '0') + a;  
  std::string bPad = std::string(maxLen - b.size(), '0') + b;  
  return { aPad, bPad };  
}  

std::string applyBitwise(const std::string& a, const std::string& b, char op) {  
   auto padded = pad(a, b); // Fix auto deduction issue by using a single variable  
   std::string x = padded.first; // Extract first element  
   std::string y = padded.second; // Extract second element  

   std::string result;  
   for (size_t i = 0; i < x.size(); ++i) {  
       if (op == '&') result += (x[i] == '1' && y[i] == '1') ? '1' : '0';  
       else if (op == '|') result += (x[i] == '1' || y[i] == '1') ? '1' : '0';  
       else if (op == '^') result += (x[i] != y[i]) ? '1' : '0';  
   }  
   return result;  
}  

std::string BitwisePlayground::bitwiseAND(const std::string& a, const std::string& b) {  
   return applyBitwise(a, b, '&');  
}  

std::string BitwisePlayground::bitwiseOR(const std::string& a, const std::string& b) {  
   return applyBitwise(a, b, '|');  
}  

std::string BitwisePlayground::bitwiseXOR(const std::string& a, const std::string& b) {  
   return applyBitwise(a, b, '^');  
}