#include "MyLibraries/Collision.h"
#include "MyLibraries/Nucleon.h"
#include "MyLibraries/Nucleus.h"
#include "MyLibraries/mathematicalfunctions.h"
#include <iostream>
#include <cmath>

#define N_events 1 // Number of events generated

int main(int argc, char *argv[]) {

  cout << ":::::::::: Glauber Model :::::::::\n";
  cout << "Colliding Distance : " << colliding_distance << "\n";
  cout << "Au-Au Collision\n";
  cout << "Sigma : " << sigma << "\n";
  for (int i = 0; i < N_events; i++) {
    Nucleus N1("Au");
    cout << "COM1 : " << N1.GetCOM()[0] <<","<< N1.GetCOM()[1] << "\n";
    Nucleus N2("Au");
    cout << "COM2 : " << N2.GetCOM()[0] <<","<< N2.GetCOM()[1] << "\n";
    float impactparam = rd_generate_random_float(0, 16.0);

//    float t_impactpram = rd_generate_random_float(0, 1);
    N2.ShiftCOM_Au(0.0, impactparam);
    //cout << "nucleus 1\n";
    /*for (Nucleon nu : N1.GetNucleons()) {
      cout << nu.GetX() << ",";
      cout << nu.GetY() << "\n";
    }
    */
    Collision Event(N1, N2);
    cout << "COM2 : " << N2.GetCOM()[0] <<","<< N2.GetCOM()[1] << "\n";
    cout << "Event : " << i + 1 << "; b = " << impactparam << 
      "; Npart = " << Event.GetNpart() << "; Ncoll = " << Event.GetNcoll() << "\n";
  }

  return 0;
}
