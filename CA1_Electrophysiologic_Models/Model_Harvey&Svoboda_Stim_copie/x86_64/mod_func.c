#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;

extern void _K_ahp_debug_Bh_reg(void);
extern void _ampa_glu_reg(void);
extern void _ca_conc_debug_reg(void);
extern void _ca_debug_bh_reg(void);
extern void _cadifus_reg(void);
extern void _cadifus_dend_reg(void);
extern void _diffusion_reg(void);
extern void _k_a_debug_Bh_reg(void);
extern void _k_c_debug_Bh_reg(void);
extern void _kdr_debug_reg(void);
extern void _na_debug_reg(void);
extern void _netstims_reg(void);
extern void _nmda_ca_conc_debug_reg(void);
extern void _nmda_ca_current_reg(void);
extern void _nmda_ca_debug_reg(void);
extern void _nmda_current_reg(void);
extern void _nmda_debug_reg(void);

void modl_reg(){
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");

    fprintf(stderr," Mod_Files//K_ahp_debug_Bh.mod");
    fprintf(stderr," Mod_Files//ampa_glu.mod");
    fprintf(stderr," Mod_Files//ca_conc_debug.mod");
    fprintf(stderr," Mod_Files//ca_debug_bh.mod");
    fprintf(stderr," Mod_Files//cadifus.mod");
    fprintf(stderr," Mod_Files//cadifus_dend.mod");
    fprintf(stderr," Mod_Files//diffusion.mod");
    fprintf(stderr," Mod_Files//k_a_debug_Bh.mod");
    fprintf(stderr," Mod_Files//k_c_debug_Bh.mod");
    fprintf(stderr," Mod_Files//kdr_debug.mod");
    fprintf(stderr," Mod_Files//na_debug.mod");
    fprintf(stderr," Mod_Files//netstims.mod");
    fprintf(stderr," Mod_Files//nmda_ca_conc_debug.mod");
    fprintf(stderr," Mod_Files//nmda_ca_current.mod");
    fprintf(stderr," Mod_Files//nmda_ca_debug.mod");
    fprintf(stderr," Mod_Files//nmda_current.mod");
    fprintf(stderr," Mod_Files//nmda_debug.mod");
    fprintf(stderr, "\n");
  }
  _K_ahp_debug_Bh_reg();
  _ampa_glu_reg();
  _ca_conc_debug_reg();
  _ca_debug_bh_reg();
  _cadifus_reg();
  _cadifus_dend_reg();
  _diffusion_reg();
  _k_a_debug_Bh_reg();
  _k_c_debug_Bh_reg();
  _kdr_debug_reg();
  _na_debug_reg();
  _netstims_reg();
  _nmda_ca_conc_debug_reg();
  _nmda_ca_current_reg();
  _nmda_ca_debug_reg();
  _nmda_current_reg();
  _nmda_debug_reg();
}
