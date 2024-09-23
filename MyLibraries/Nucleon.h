#ifndef NUCLEON_H
#define NUCLEON_H

// #include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

// Defining Nucleon Class
class Nucleon {
public:
  // Nucleon constructor
  Nucleon(string, vector<float>);

  // Data Accessing methods
  string GetType();
  int IsMarked();
  float GetX();
  float GetY();

  // Data manipulating methods
  void Setr(float);
  void SetTheta(float);
  void SetPhi(float);
  void SetX(float x_value);
  void SetY(float y_value);
  void SetZ(float z_value);
  void Mark();

private:
  // Type of nucleon proton/neutron
  string nucleon_type;
  // Coordinates
  float r;
  float theta;
  float phi;

  float x;
  float y;
  float z;
  // Coloured or not coloured : used for counting Npart and Ncoll
  int count_marker = 0;
};

#endif
