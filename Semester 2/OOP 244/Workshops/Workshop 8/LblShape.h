#ifndef SENECA_LABELEDSHAPE_H
#define SENECA_LABELEDSHAPE_H
#include<iostream>
#include"utils.h"
#include"shape.h"

namespace seneca {

   class LblShape: public Shape    {
      // Dynamically allocated label for the shape
       char* m_label{ nullptr };
   protected:
      // Returns the label string for derived classes to access
       const char* label() const { return m_label; }
   public:
      // Default constructor
       LblShape() = default;

      // Constructor with label initialization
       LblShape(const char* label) {
           m_label = nullptr;
           if (label && label[0] != '\0') {
               Utils u;
               u.alocpy(m_label, label);
           }
       }

      // Copy constructor and assignment operator are deleted to prevent copying
       LblShape(const LblShape&) = delete;
       LblShape& operator=(const LblShape&) = delete;

      // Reads label specifications from input stream
       // Override getSpecs: reads label from istream (comma delimited)
       void getSpecs(std::istream& is) override {
           char tempLabel[81] = { '\0' };  // buffer for input

           // Read up to 80 chars or until comma
           is.getline(tempLabel, 81, ',');

           // Clear previous label memory if any
           delete[] m_label;
           m_label = nullptr;

           // Copy using Utils::alocpy
           if (tempLabel[0] != '\0') {
               Utils u;
               u.alocpy(m_label, tempLabel);
           }
       }

      // Destructor to release dynamically allocated memory
       virtual ~LblShape() {
           delete[] m_label;
       }
   };
}

#endif // !SENECA_LABELEDSHAPE_H
