#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;

extern void _Stim_1_2_3_4_5_6.hoc_reg(void);

void modl_reg(){
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");

    fprintf(stderr," Stim_1_2_3_4_5_6.hoc.mod");
    fprintf(stderr, "\n");
  }
  _Stim_1_2_3_4_5_6.hoc_reg();
}
