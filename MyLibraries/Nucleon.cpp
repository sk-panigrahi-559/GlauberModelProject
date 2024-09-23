#include "Nucleon.h"
#include "mathematicalfunctions.h"
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

// Defining Nucleon Class
// Nucleon constructor
Nucleon::Nucleon(string nu_type, vector<float> coord) {
  nucleon_type = nu_type;
  r = coord[0];
  theta = coord[1];
  phi = coord[2];
  count_marker = 0;
  vector<float> cart_coord = spherical_to_cartesian(r, theta, phi);
  x = roundoff4(cart_coord[0]);
  y = roundoff4(cart_coord[1]);
  z = roundoff4(cart_coord[2]);
}
// Data Accessing methods
string Nucleon::GetType() { return nucleon_type; }
int Nucleon::IsMarked() { return count_marker; }
float Nucleon::GetX() { return x; }
float Nucleon::GetY() { return y; }

// Data manipulating methods
void Nucleon::Setr(float r_value) { r = r_value; }
void Nucleon::SetTheta(float theta_value) { theta = theta_value; }
void Nucleon::SetPhi(float phi_value) { phi = phi_value; }
void Nucleon::SetX(float x_value) { x = x_value; }
void Nucleon::SetY(float y_value) { x = y_value; }
void Nucleon::SetZ(float z_value) { x = z_value; }
void Nucleon::Mark() { count_marker = 1; }
