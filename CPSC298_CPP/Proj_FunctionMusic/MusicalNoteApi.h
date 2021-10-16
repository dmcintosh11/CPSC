#if !defined(MUSICAL_NOTE_API_H)
#define MUSICAL_NOTE_API_H  // Sentinel

#include <string>

/// @brief Musical Notes Application Programming Interface (API) Header File
/// CPSC-298-6 Programming in C++ Project Musical Note Frequencies with Functions
/// @author dmcintosh@chapman.edu

// //////////////////////////////////////////////////////////////////////////////////
// CONSTANTS
// //////////////////////////////////////////////////////////////////////////////////

/// Speed of sound in meters per second in air at standard temperature and pressure
const double k_dSpeedOfSoundMetersPerSecond = 345.0;

/// Speed of sound in centimeters per second in air at standard temperature and pressure
const double k_dSpeedOfSoundCmPerSecond = k_dSpeedOfSoundMetersPerSecond * 100;

/// Number of halftones in an octave.
const int k_nHalfTonesInOctave = 12;

/// Frequency of note C0; used as the reference frequency in computing the frequencies of other notes.
const double k_dFrequencyRef = 16.35;


// //////////////////////////////////////////////////////////////////////////////////
// FUNCTIONS
// //////////////////////////////////////////////////////////////////////////////////

/// Computes the frequency of a musical note given its octave and half-step (or semitone) number.
///
/// @param nu integer > 0 representing the octave number of the note.
/// @param k  integer from 0 to 11, inclusive, representing the half-step (or semitone) number within the octave.
///
/// @pre nu > 0
/// @pre k >= 0 and k < Number of Halftones (12)
///
/// @return double precision floating point value that is the frequency in Hertz (Hz), or
///         cycles per second, or -1.0 if an error occurred.

// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/ //
// TODO: code the prototype for function computeFrequency based on the method preamble comments above
// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/ //
double computeFrequency(int nu, int k) ;


/// Computes wavelength in centimeters of a musical note at room temperature and pressure given the note's frequency in Hertz.
///
/// @param dFrequency positive double precision value that is the frequency in Hertz (Hz) (non-negative, non-zero)
///
/// @pre dFrequencyHz > 0.0 (i.e. non-zero and non-negative)
/// @pre dFrequencyHz not a special floating point value such as positive or negative infinity, or a quiet or signaling NaN.
///
/// @return double precision value holding the computed wavelength in centimeters or -1.0 if an error occurred.
double computeWavelengthInCm(double dFrequencyHz);


/// Returns the shorthand name of the musical note whose octave and half-tone are specified.
/// @param nu integer > 0 representing the octave number of the note.
/// @param k  integer from 0 to 11, inclusive, representing the half-step (or semitone) number within the octave.
///
/// @pre nu > 0
/// @pre k >= 0 and k < Number of Halftones (12)
///
/// @return a string object holding the shorthand name of the note corresponding to the specified
///         octave and half-tone, or "UNK" if nu and k are invalid.
const std::string getNoteName(int nu, int k);

#endif
