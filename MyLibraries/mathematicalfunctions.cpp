#include <cmath>
#include <random>
#include <vector>
#include "Nucleus.h"
#include "Nucleon.h"
#include "Collision.h"

using namespace std;

// Generates a random number using random engine
int rd_generate_random_integer(int lowerbound, int upperbound) {
  std::random_device rd;
  std::default_random_engine generator(rd());
  std::uniform_int_distribution<int> distribution(lowerbound, upperbound);
  return distribution(generator);
}

// Generates a random number using random library
int rand_lib_random_integer(int lowerbound, int upperbound) {
  return rand() % (upperbound - lowerbound + 1) + lowerbound;
}

// Generates a random float number
float rd_generate_random_float(int lowerbound, int upperbound) {
  std::random_device rd;
  std::default_random_engine generator(rd());
  std::uniform_real_distribution<float> distribution(lowerbound, upperbound);
  return distribution(generator);
}

// Calculates volume of sphere
float volume_sphere(float r) { return (4.0 / 3) * M_PI * std::pow(r, 3); }

// Coordinate converter
vector<float> spherical_to_cartesian(float r, float theta, float phi) {
  float x = r * sin(theta) * cos(phi);
  float y = r * sin(theta) * sin(phi);
  float z = r * cos(theta);
  vector<float> coord;
  coord.push_back(x);
  coord.push_back(y);
  coord.push_back(z);
  return coord;
}

// Returns square
float square(float num){
  return num*num;
}

// Wood Sazon distribution function.
float wood_saxon_distribution_probability_funtion(float x){
  float r{};
  r = 1/(pow(M_E, ((x - R) / a))+ 1);
  return r;
}

float roundoff4(float x){
  return roundf((x*10000)/10000);
}

