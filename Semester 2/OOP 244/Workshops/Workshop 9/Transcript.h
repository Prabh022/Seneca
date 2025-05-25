/***********************************************************************
// OOP244 workshop 9, Transcript module
//
// File	Transcript.h
// Version 1.0
// started by Fardad
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_TRANSCRIPT_H
#define SENECA_TRANSCRIPT_H
#include <iostream>
#include "Marks.h"
namespace seneca {
   class Transcript :
      public Marks {
      // character pointer student name
       char* m_name{};
      // unsigned integer or size_t student number
       size_t m_number{};
   public:
      // Constructor
       Transcript(const char* name, size_t number);
      // Rule of Three
       Transcript(const Transcript& other);            // Copy constructor
       Transcript& operator=(const Transcript& other); // Copy assignment operator

      // Destructor
        ~Transcript();
   };
}
#endif // !SENECA_TRANSCRIPT_H


