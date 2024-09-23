#include "Collision.h"
#include "Nucleon.h"
#include "Nucleus.h"
#include <cmath>
#include <vector>

using namespace std;

#define R 6.37
#define a 0.53
#define max_nucleon_number 197
#define sigma 4.2
#define colliding_distance sqrt((sigma) / (4 * M_PI))

// Collision object
Collision::Collision(Nucleus N1, Nucleus N2){
  ComputeValues(N1, N2);
}

// Calculate Number of participants
int Collision::GetNpart() { return Npart; }

// Calculate Number of binary collisions
int Collision::GetNcoll() { return Ncoll; }

// Checks if two nucleons are coliding.
int Collision::nucleons_are_colliding(Nucleon nu1, Nucleon nu2) {
  //float distance = 0.0;
  float x1 = nu1.GetX();
  float x2 = nu2.GetX();
  float y1 = nu1.GetY();
  float y2 = nu2.GetY();
  float distance = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
  cout << distance << " ";
  if (distance < colliding_distance) {
    return 1;
  }
  return 0;
}

// calculate Npart and Ncoll
void Collision::ComputeValues(Nucleus N1, Nucleus N2) {
  vector<int> values;
  int Np = 0;
  int Nc = 0;
  vector<Nucleon> Nucleons1 = N1.GetNucleons();
  vector<Nucleon> Nucleons2 = N2.GetNucleons();
  for (int i = 0; i < max_nucleon_number; i++) {
    for (int j = 0; j < max_nucleon_number; j++) {
      //cout << nucleons_are_colliding(Nucleons1[i], Nucleons2[j]) << "";
      if (nucleons_are_colliding(Nucleons1[i], Nucleons2[j])) {
        Nc++;
        //cout << Nucleons2[j].IsMarked() << "\n";
        if (!Nucleons2[j].IsMarked()) {
          Np++;
          Nucleons2[j].Mark();
        }
      }
    }
    //cout << "\n\n\n";
  }
  Npart = Np;
  Ncoll = Nc;
}
