/*
 NOTE:
 * As of now i am only considering gold nucleus. And shall make the code usable
 for a general nuceus later
 TODO:
 * I am planning to do it by allowing the user to alter the parameters of
 Wood-Saxon distribution.
 * Create a INPUT.txt file
*/

#include "Nucleus.h"
#include "Nucleon.h"
// #include <iostream>
#include <vector>
#include "Collision.h"
#include <cmath> 
#include "mathematicalfunctions.h"

#define w 0

using namespace std;

Nucleus::Nucleus(string element_name) {
  element = element_name;
  WoodSaxonDistribution();
  center_of_mass = GetCOM();
  ShiftCOM_Au(-center_of_mass[0], -center_of_mass[1]);
}

// Returns the nucleus type
string Nucleus::GetElement() { return element; }

// Adds new nucleon to the nucleus object
void Nucleus::AddNucleon(Nucleon nu) { nucleons.push_back(nu); }

// Wood Saxon Distribution - Au
void Nucleus::WoodSaxonDistribution() {
  float r_l = 0.0;
  float r_h = R + 3*a;
  for (int i =0; i < max_nucleon_number; i++) {
    vector<float> coord;
    while (1) {
      float r = rd_generate_random_float(r_l, r_h);
      float tr = rd_generate_random_float(0.0, 1.0);
      float rho = (1 + w * pow(r/R, 2)) / (pow(M_E, ((r - R) / a)) + 1);
      if (tr < ((r*r) / (r_h*r_h))*rho ) {
        coord.push_back(r);
        break;
      }
    }
    while (1) {
      float theta = rd_generate_random_float(0.0, M_PI);
      float t_theta = rd_generate_random_float(0.0, 1.0);
      if (t_theta < sin(theta)) {
        coord.push_back(theta);
        break;
      }
    }
    float phi = rd_generate_random_float(0.0, 2*M_PI);
    coord.push_back(phi);
    // setting the cartesian coordinates
    //float x_, y_; // x and y coordinates of the nucleon
    //x_ = r * sin(theta) * cos(phi);
    //y_ = r * sin(theta) * sin(phi);
    Nucleon Nu("proton", coord);
    //Nu.SetX(x_);
    //Nu.SetY(y_);
    AddNucleon(Nu);

  }
}

// Returns Center of mass of the nucleus
vector<float> Nucleus::Nucleus::GetCOM() {
  vector<float> COM;
  float x_com = 0.0;
  float y_com = 0.0;
  float i = 0;
  for (Nucleon nu : nucleons) {
    x_com += nu.GetX();
    y_com += nu.GetY();
    i++;
  }
  x_com = x_com / i;
  y_com = y_com / i;
  COM.push_back(x_com);
  COM.push_back(y_com);
  return COM;
}

vector<Nucleon> Nucleus::GetNucleons() { return nucleons; }

// Shiffts the center of mass of the nucleus
void Nucleus::ShiftCOM_Au(float x, float y) {
  /*for (Nucleon nu : nucleons) {
    nu.SetX(nu.GetX() + x);
    nu.SetY(nu.GetY() + y);
  }*/
  for (int i = 0; i < max_nucleon_number; i++) {
    nucleons[i].SetX(nucleons[i].GetX() + x);
    nucleons[i].SetY(nucleons[i].GetY() + y);
  }
}
