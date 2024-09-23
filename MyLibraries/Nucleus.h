#ifndef NUCLEUS_H
#define NUCLEUS_H

#include "Nucleon.h"
#include <iostream>
#include <vector>

using namespace std;

class Nucleus {
public:
  Nucleus(string element_name);

  // Returns the nucleus type
  string GetElement();

  // Adds new nucleon to the nucleus object
  void AddNucleon(Nucleon nucleon);

  // Wood Saxon Distribution
  void WoodSaxonDistribution();
  
  // Returns center of mass of the nucleus
  vector<float> GetCOM();

  void ShiftCOM_Au(float x, float y);

  // Nucleons
  vector<Nucleon> GetNucleons();

private:
  string element;               // Nucleus of which element
  vector<float> center_of_mass; // Center of mass of the Nucleus
  vector<Nucleon> nucleons;     // LL nucleons as
};
#endif // !NUCLEUS_H
