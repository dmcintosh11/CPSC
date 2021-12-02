/// @file DefectDensity.cpp
/// Implements a main function to compute defect density based on user input.

#include <iostream>   // defines cout, cin
#include <string>     // defines std::string
#include <stdexcept>  // std::runtime_error

/// Computes defect density of a program unit based on the number of defects encountered
/// within a specific time period and the size of the program unit.
///
/// @details
/// The program prompts the user to enter the number of unique defects encountered within
/// a specific time period and the size of the program unit using a standard measure
/// such as Source Lines of Code (SLOC) in a particular programming language or in
/// Function Points (a language-independent measure).
///
/// The program then computes the defect density.
///
/// The defect density is the ratio of the number of defects encoutnered to the
/// size of the program unit:
///
///                      Number of unique defects enountered in time period within program unit
/// Defect Density = ---------------------------------------------------------------------------
///                          Size of program unit in a standard measure (such as SLOC)
///
int main()
{
    // Function main contains (at least) two defects that may result in the defect density being incorrectly
    // computed or may result in catastrophic failure of the program.

    long nDefects = 0;         // Unique Defects detected per time interval in program unit.
                               // The time interval may be the start of the project to the present,
                               // or the duration of the current sprint. The program unit may
                               // be a file or a function.

    long nProgramUnitSize = 0; // Size of the program unit in size units such as source lines
                               // of code (SLOC) in a particular language such as C++ or
                               // Function Points (a means to normalize code size across
                               // programming langauges.

    try{
    std::cout << "Enter number of defects in program unit: " << std::endl;
    std::cin >> nDefects;

    if(!(nDefects >= 0)) {
      std::string strMessage = "Invalid number of defects: " + std::to_string(nDefects) + "; number of defects must be >= 0; " +
                                " (Loc: " + __FILE__ + ", " + std::to_string(__LINE__) + ")";
      throw std::runtime_error(strMessage);
    }

    std::cout << "Enter size of program unit in size units such as SLOC: " << std::endl;
    std::cin >> nProgramUnitSize;

    if((nProgramUnitSize <= 0)) {
      std::string strMessage = "Invalid unit of programs: " + std::to_string(nDefects) + "; number of units can't be <= 0; " +
                                " (Loc: " + __FILE__ + ", " + std::to_string(__LINE__) + ")";
      throw std::runtime_error(strMessage);
    }

    double dDefectDensity = static_cast<double>(nDefects) / nProgramUnitSize;

    std::cout << "Number of Defects: " << nDefects << std::endl;
    std::cout << "Program Unit Size: " << nProgramUnitSize << std::endl;
    std::cout << "Defect Density:    " << dDefectDensity << std::endl;
  }

  catch(std::runtime_error & excpt) {
    std::cout << "Exception: " << excpt.what() << std::endl;
    std::cout << "Cannot compute Defect Density" << std::endl;

  }

    return 0;
}
