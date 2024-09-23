#include "Nucleus.h"

#define R 6.37
#define a 0.53
#define max_nucleon_number 197
#define sigma 4.2
#define colliding_distance sqrt((sigma) / (4 * M_PI))

class Collision {
public:
  Collision(Nucleus N1, Nucleus N2);
  int GetNpart();
  int GetNcoll();
  void ComputeValues(Nucleus N1, Nucleus N2);
  int nucleons_are_colliding(Nucleon nu1, Nucleon nu2);

private:
  int Npart = 0;
  int Ncoll = 0;
  //float imact_parameter = 0;
};
