/* Created by Language version: 6.2.0 */
/* VECTORIZED */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scoplib_ansi.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define _threadargscomma_ _p, _ppvar, _thread, _nt,
#define _threadargs_ _p, _ppvar, _thread, _nt
 
#define _threadargsprotocomma_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt,
#define _threadargsproto_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 /* Thread safe. No static _p or _ppvar. */
 
#define t _nt->_t
#define dt _nt->_dt
#define phi _p[0]
#define beta _p[1]
#define ca _p[2]
#define ca_modif _p[3]
#define Cam _p[4]
#define Cam_Ca _p[5]
#define Cam_Ca2 _p[6]
#define Cam_Ca3 _p[7]
#define Cam_Ca4 _p[8]
#define Gef _p[9]
#define Gef_activated _p[10]
#define RasGDP _p[11]
#define RasGTP _p[12]
#define ica _p[13]
#define cai _p[14]
#define Dca _p[15]
#define Dca_modif _p[16]
#define DCam _p[17]
#define DCam_Ca _p[18]
#define DCam_Ca2 _p[19]
#define DCam_Ca3 _p[20]
#define DCam_Ca4 _p[21]
#define DGef _p[22]
#define DGef_activated _p[23]
#define DRasGDP _p[24]
#define DRasGTP _p[25]
#define v _p[26]
#define _g _p[27]
#define _ion_cai	*_ppvar[0]._pval
#define _ion_ica	*_ppvar[1]._pval
#define _style_ca	*((int*)_ppvar[2]._pvoid)
#define diam	*_ppvar[3]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  -1;
 static Datum* _extcall_thread;
 static Prop* _extcall_prop;
 /* external NEURON variables */
 /* declaration of user functions */
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _extcall_prop = _prop;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_cadifus", _hoc_setdata,
 0, 0
};
 /* declare global and static user variables */
#define DRas DRas_cadifus
 double DRas = 0.65;
#define caiBase caiBase_cadifus
 double caiBase = 5e-05;
#define ceiling ceiling_cadifus
 double ceiling = 2;
#define kr_rasGDP kr_rasGDP_cadifus
 double kr_rasGDP = 3.7037e-06;
#define kf_rasGDP kf_rasGDP_cadifus
 double kf_rasGDP = 0.1;
#define kr_gef kr_gef_cadifus
 double kr_gef = 8.33333e-06;
#define kf_gef kf_gef_cadifus
 double kf_gef = 2.75;
#define kr_cam4 kr_cam4_cadifus
 double kr_cam4 = 0.01;
#define kf_cam4 kf_cam4_cadifus
 double kf_cam4 = 0.465;
#define kr_cam3 kr_cam3_cadifus
 double kr_cam3 = 0.01;
#define kf_cam3 kf_cam3_cadifus
 double kf_cam3 = 3.6001;
#define kr_cam2 kr_cam2_cadifus
 double kr_cam2 = 0.0084853;
#define kf_cam2 kf_cam2_cadifus
 double kf_cam2 = 8.4846;
#define kr_cam1 kr_cam1_cadifus
 double kr_cam1 = 0.0084853;
#define kf_cam1 kf_cam1_cadifus
 double kf_cam1 = 1;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "DRas_cadifus", "um2/ms",
 "ceiling_cadifus", "mM",
 "caiBase_cadifus", "mM",
 "kf_cam1_cadifus", "/mM-ms",
 "kr_cam1_cadifus", "/ms",
 "kf_cam2_cadifus", "/mM-ms",
 "kr_cam2_cadifus", "/ms",
 "kf_cam3_cadifus", "/mM-ms",
 "kr_cam3_cadifus", "/ms",
 "kf_cam4_cadifus", "/mM-ms",
 "kr_cam4_cadifus", "/ms",
 "kf_gef_cadifus", "/mM-ms",
 "kr_gef_cadifus", "/ms",
 "kf_rasGDP_cadifus", "/mM-ms",
 "kr_rasGDP_cadifus", "/ms",
 "phi_cadifus", "/ms",
 "ca_cadifus", "mM",
 "ca_modif_cadifus", "mM",
 "Cam_cadifus", "mM",
 "Cam_Ca_cadifus", "mM",
 "Cam_Ca2_cadifus", "mM",
 "Cam_Ca3_cadifus", "mM",
 "Cam_Ca4_cadifus", "mM",
 "Gef_cadifus", "mM",
 "Gef_activated_cadifus", "mM",
 "RasGDP_cadifus", "mM",
 "RasGTP_cadifus", "mM",
 0,0
};
 static double Cam_Ca40 = 0;
 static double Cam_Ca30 = 0;
 static double Cam_Ca20 = 0;
 static double Cam_Ca0 = 0;
 static double Cam0 = 0;
 static double Gef_activated0 = 0;
 static double Gef0 = 0;
 static double RasGTP0 = 0;
 static double RasGDP0 = 0;
 static double ca_modif0 = 0;
 static double ca0 = 0;
 static double delta_t = 0.01;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "DRas_cadifus", &DRas_cadifus,
 "ceiling_cadifus", &ceiling_cadifus,
 "caiBase_cadifus", &caiBase_cadifus,
 "kf_cam1_cadifus", &kf_cam1_cadifus,
 "kr_cam1_cadifus", &kr_cam1_cadifus,
 "kf_cam2_cadifus", &kf_cam2_cadifus,
 "kr_cam2_cadifus", &kr_cam2_cadifus,
 "kf_cam3_cadifus", &kf_cam3_cadifus,
 "kr_cam3_cadifus", &kr_cam3_cadifus,
 "kf_cam4_cadifus", &kf_cam4_cadifus,
 "kr_cam4_cadifus", &kr_cam4_cadifus,
 "kf_gef_cadifus", &kf_gef_cadifus,
 "kr_gef_cadifus", &kr_gef_cadifus,
 "kf_rasGDP_cadifus", &kf_rasGDP_cadifus,
 "kr_rasGDP_cadifus", &kr_rasGDP_cadifus,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(_NrnThread*, _Memb_list*, int);
static void nrn_state(_NrnThread*, _Memb_list*, int);
 static void nrn_cur(_NrnThread*, _Memb_list*, int);
static void  nrn_jacob(_NrnThread*, _Memb_list*, int);
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(_NrnThread*, _Memb_list*, int);
static void _ode_matsol(_NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[4]._i
 static void _ode_synonym(int, double**, Datum**);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "6.2.0",
"cadifus",
 "phi_cadifus",
 "beta_cadifus",
 0,
 0,
 "ca_cadifus",
 "ca_modif_cadifus",
 "Cam_cadifus",
 "Cam_Ca_cadifus",
 "Cam_Ca2_cadifus",
 "Cam_Ca3_cadifus",
 "Cam_Ca4_cadifus",
 "Gef_cadifus",
 "Gef_activated_cadifus",
 "RasGDP_cadifus",
 "RasGTP_cadifus",
 0,
 0};
 static Symbol* _morphology_sym;
 static Symbol* _ca_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 28, _prop);
 	/*initialize range parameters*/
 	phi = 0.25;
 	beta = 17.402;
 	_prop->param = _p;
 	_prop->param_size = 28;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 5, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_morphology_sym);
 	_ppvar[3]._pval = &prop_ion->param[0]; /* diam */
 prop_ion = need_memb(_ca_sym);
 nrn_check_conc_write(_prop, prop_ion, 1);
 nrn_promote(prop_ion, 3, 0);
 	_ppvar[0]._pval = &prop_ion->param[1]; /* cai */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ica */
 	_ppvar[2]._pvoid = (void*)(&(prop_ion->dparam[0]._i)); /* iontype for ca */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 "ca_cadifus", 1e-10,
 0,0
};
 static void _thread_cleanup(Datum*);
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*f)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _cadifus_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("ca", -10000.);
 	_morphology_sym = hoc_lookup("morphology");
 	_ca_sym = hoc_lookup("ca_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 3);
  _extcall_thread = (Datum*)ecalloc(2, sizeof(Datum));
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 0, _thread_cleanup);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
  hoc_register_dparam_size(_mechtype, 5);
 	nrn_writes_conc(_mechtype, 0);
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_synonym(_mechtype, _ode_synonym);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 cadifus /Users/maoss2/NEURON/CA1_cell_test/Stimulation_case_per_case/CA1_Electrophysiologic_Models/CA1_Electrophysiologic_Models/Model_Harvey&Svoboda_Stim/Mod_Files/x86_64/cadifus.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double FARADAY = 9.64853;
 static double PI = 3.14159;
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
 extern double *_nrn_thread_getelm();
 
#define _MATELM1(_row,_col) *(_nrn_thread_getelm(_so, _row + 1, _col + 1))
 
#define _RHS1(_arg) _rhs[_arg+1]
  
#define _linmat1  0
 static int _spth1 = 1;
 static int _cvspth1 = 0;
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[11], _dlist1[11]; static double *_temp1;
 static int state();
 
static int state (void* _so, double* _rhs, double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt)
 {int _reset=0;
 {
   double b_flux, f_flux, _term; int _i;
 {int _i; double _dt1 = 1.0/dt;
for(_i=0;_i<11;_i++){
  	_RHS1(_i) = -_dt1*(_p[_slist1[_i]] - _p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
} }
 /* ~ ca < < ( ( - beta * ica ) - ( phi * ( cai - caiBase ) ) )*/
 f_flux = b_flux = 0.;
 _RHS1( 10) += (b_flux =   ( ( - beta * ica ) - ( phi * ( cai - caiBase ) ) ) );
 /*FLUX*/
  cai = ca ;
   ca_modif = ca - 0.00045 ;
   /* ~ ca_modif + Cam <-> Cam_Ca ( kf_cam1 , kr_cam1 )*/
 f_flux =  kf_cam1 * Cam * ca_modif ;
 b_flux =  kr_cam1 * Cam_Ca ;
 _RHS1( 4) -= (f_flux - b_flux);
 _RHS1( 9) -= (f_flux - b_flux);
 _RHS1( 3) += (f_flux - b_flux);
 
 _term =  kf_cam1 * ca_modif ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 9 ,4)  += _term;
 _MATELM1( 3 ,4)  -= _term;
 _term =  kf_cam1 * Cam ;
 _MATELM1( 4 ,9)  += _term;
 _MATELM1( 9 ,9)  += _term;
 _MATELM1( 3 ,9)  -= _term;
 _term =  kr_cam1 ;
 _MATELM1( 4 ,3)  -= _term;
 _MATELM1( 9 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 /*REACTION*/
  /* ~ ca_modif + Cam_Ca <-> Cam_Ca2 ( kf_cam2 , kr_cam2 )*/
 f_flux =  kf_cam2 * Cam_Ca * ca_modif ;
 b_flux =  kr_cam2 * Cam_Ca2 ;
 _RHS1( 3) -= (f_flux - b_flux);
 _RHS1( 9) -= (f_flux - b_flux);
 _RHS1( 2) += (f_flux - b_flux);
 
 _term =  kf_cam2 * ca_modif ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 9 ,3)  += _term;
 _MATELM1( 2 ,3)  -= _term;
 _term =  kf_cam2 * Cam_Ca ;
 _MATELM1( 3 ,9)  += _term;
 _MATELM1( 9 ,9)  += _term;
 _MATELM1( 2 ,9)  -= _term;
 _term =  kr_cam2 ;
 _MATELM1( 3 ,2)  -= _term;
 _MATELM1( 9 ,2)  -= _term;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ ca_modif + Cam_Ca2 <-> Cam_Ca3 ( kf_cam3 , kr_cam3 )*/
 f_flux =  kf_cam3 * Cam_Ca2 * ca_modif ;
 b_flux =  kr_cam3 * Cam_Ca3 ;
 _RHS1( 2) -= (f_flux - b_flux);
 _RHS1( 9) -= (f_flux - b_flux);
 _RHS1( 1) += (f_flux - b_flux);
 
 _term =  kf_cam3 * ca_modif ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 9 ,2)  += _term;
 _MATELM1( 1 ,2)  -= _term;
 _term =  kf_cam3 * Cam_Ca2 ;
 _MATELM1( 2 ,9)  += _term;
 _MATELM1( 9 ,9)  += _term;
 _MATELM1( 1 ,9)  -= _term;
 _term =  kr_cam3 ;
 _MATELM1( 2 ,1)  -= _term;
 _MATELM1( 9 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ ca_modif + Cam_Ca3 <-> Cam_Ca4 ( kf_cam4 , kr_cam4 )*/
 f_flux =  kf_cam4 * Cam_Ca3 * ca_modif ;
 b_flux =  kr_cam4 * Cam_Ca4 ;
 _RHS1( 1) -= (f_flux - b_flux);
 _RHS1( 9) -= (f_flux - b_flux);
 _RHS1( 0) += (f_flux - b_flux);
 
 _term =  kf_cam4 * ca_modif ;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 9 ,1)  += _term;
 _MATELM1( 0 ,1)  -= _term;
 _term =  kf_cam4 * Cam_Ca3 ;
 _MATELM1( 1 ,9)  += _term;
 _MATELM1( 9 ,9)  += _term;
 _MATELM1( 0 ,9)  -= _term;
 _term =  kr_cam4 ;
 _MATELM1( 1 ,0)  -= _term;
 _MATELM1( 9 ,0)  -= _term;
 _MATELM1( 0 ,0)  += _term;
 /*REACTION*/
  /* ~ Cam_Ca4 + Gef <-> Gef_activated ( kf_gef , kr_gef )*/
 f_flux =  kf_gef * Gef * Cam_Ca4 ;
 b_flux =  kr_gef * Gef_activated ;
 _RHS1( 6) -= (f_flux - b_flux);
 _RHS1( 0) -= (f_flux - b_flux);
 _RHS1( 5) += (f_flux - b_flux);
 
 _term =  kf_gef * Cam_Ca4 ;
 _MATELM1( 6 ,6)  += _term;
 _MATELM1( 0 ,6)  += _term;
 _MATELM1( 5 ,6)  -= _term;
 _term =  kf_gef * Gef ;
 _MATELM1( 6 ,0)  += _term;
 _MATELM1( 0 ,0)  += _term;
 _MATELM1( 5 ,0)  -= _term;
 _term =  kr_gef ;
 _MATELM1( 6 ,5)  -= _term;
 _MATELM1( 0 ,5)  -= _term;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ RasGDP <-> RasGTP ( kf_rasGDP * Gef_activated , kr_rasGDP )*/
 f_flux =  kf_rasGDP * Gef_activated * RasGDP ;
 b_flux =  kr_rasGDP * RasGTP ;
 _RHS1( 8) -= (f_flux - b_flux);
 _RHS1( 7) += (f_flux - b_flux);
 
 _term =  kf_rasGDP * Gef_activated ;
 _MATELM1( 8 ,8)  += _term;
 _MATELM1( 7 ,8)  -= _term;
 _term =  kr_rasGDP ;
 _MATELM1( 8 ,7)  -= _term;
 _MATELM1( 7 ,7)  += _term;
 /*REACTION*/
    } return _reset;
 }
 
/*CVODE ode begin*/
 static int _ode_spec1(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset=0;{
 double b_flux, f_flux, _term; int _i;
 {int _i; for(_i=0;_i<11;_i++) _p[_dlist1[_i]] = 0.0;}
 /* ~ ca < < ( ( - beta * ica ) - ( phi * ( cai - caiBase ) ) )*/
 f_flux = b_flux = 0.;
 Dca += (b_flux =   ( ( - beta * ica ) - ( phi * ( cai - caiBase ) ) ) );
 /*FLUX*/
  cai = ca ;
 ca_modif = ca - 0.00045 ;
 /* ~ ca_modif + Cam <-> Cam_Ca ( kf_cam1 , kr_cam1 )*/
 f_flux =  kf_cam1 * Cam * ca_modif ;
 b_flux =  kr_cam1 * Cam_Ca ;
 DCam -= (f_flux - b_flux);
 Dca_modif -= (f_flux - b_flux);
 DCam_Ca += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca_modif + Cam_Ca <-> Cam_Ca2 ( kf_cam2 , kr_cam2 )*/
 f_flux =  kf_cam2 * Cam_Ca * ca_modif ;
 b_flux =  kr_cam2 * Cam_Ca2 ;
 DCam_Ca -= (f_flux - b_flux);
 Dca_modif -= (f_flux - b_flux);
 DCam_Ca2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca_modif + Cam_Ca2 <-> Cam_Ca3 ( kf_cam3 , kr_cam3 )*/
 f_flux =  kf_cam3 * Cam_Ca2 * ca_modif ;
 b_flux =  kr_cam3 * Cam_Ca3 ;
 DCam_Ca2 -= (f_flux - b_flux);
 Dca_modif -= (f_flux - b_flux);
 DCam_Ca3 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca_modif + Cam_Ca3 <-> Cam_Ca4 ( kf_cam4 , kr_cam4 )*/
 f_flux =  kf_cam4 * Cam_Ca3 * ca_modif ;
 b_flux =  kr_cam4 * Cam_Ca4 ;
 DCam_Ca3 -= (f_flux - b_flux);
 Dca_modif -= (f_flux - b_flux);
 DCam_Ca4 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ Cam_Ca4 + Gef <-> Gef_activated ( kf_gef , kr_gef )*/
 f_flux =  kf_gef * Gef * Cam_Ca4 ;
 b_flux =  kr_gef * Gef_activated ;
 DGef -= (f_flux - b_flux);
 DCam_Ca4 -= (f_flux - b_flux);
 DGef_activated += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ RasGDP <-> RasGTP ( kf_rasGDP * Gef_activated , kr_rasGDP )*/
 f_flux =  kf_rasGDP * Gef_activated * RasGDP ;
 b_flux =  kr_rasGDP * RasGTP ;
 DRasGDP -= (f_flux - b_flux);
 DRasGTP += (f_flux - b_flux);
 
 /*REACTION*/
    } return _reset;
 }
 
/*CVODE matsol*/
 static int _ode_matsol1(void* _so, double* _rhs, double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset=0;{
 double b_flux, f_flux, _term; int _i;
   b_flux = f_flux = 0.;
 {int _i; double _dt1 = 1.0/dt;
for(_i=0;_i<11;_i++){
  	_RHS1(_i) = _dt1*(_p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
} }
 /* ~ ca < < ( ( - beta * ica ) - ( phi * ( cai - caiBase ) ) )*/
 /*FLUX*/
  cai = ca ;
 ca_modif = ca - 0.00045 ;
 /* ~ ca_modif + Cam <-> Cam_Ca ( kf_cam1 , kr_cam1 )*/
 _term =  kf_cam1 * ca_modif ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 9 ,4)  += _term;
 _MATELM1( 3 ,4)  -= _term;
 _term =  kf_cam1 * Cam ;
 _MATELM1( 4 ,9)  += _term;
 _MATELM1( 9 ,9)  += _term;
 _MATELM1( 3 ,9)  -= _term;
 _term =  kr_cam1 ;
 _MATELM1( 4 ,3)  -= _term;
 _MATELM1( 9 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 /*REACTION*/
  /* ~ ca_modif + Cam_Ca <-> Cam_Ca2 ( kf_cam2 , kr_cam2 )*/
 _term =  kf_cam2 * ca_modif ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 9 ,3)  += _term;
 _MATELM1( 2 ,3)  -= _term;
 _term =  kf_cam2 * Cam_Ca ;
 _MATELM1( 3 ,9)  += _term;
 _MATELM1( 9 ,9)  += _term;
 _MATELM1( 2 ,9)  -= _term;
 _term =  kr_cam2 ;
 _MATELM1( 3 ,2)  -= _term;
 _MATELM1( 9 ,2)  -= _term;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ ca_modif + Cam_Ca2 <-> Cam_Ca3 ( kf_cam3 , kr_cam3 )*/
 _term =  kf_cam3 * ca_modif ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 9 ,2)  += _term;
 _MATELM1( 1 ,2)  -= _term;
 _term =  kf_cam3 * Cam_Ca2 ;
 _MATELM1( 2 ,9)  += _term;
 _MATELM1( 9 ,9)  += _term;
 _MATELM1( 1 ,9)  -= _term;
 _term =  kr_cam3 ;
 _MATELM1( 2 ,1)  -= _term;
 _MATELM1( 9 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ ca_modif + Cam_Ca3 <-> Cam_Ca4 ( kf_cam4 , kr_cam4 )*/
 _term =  kf_cam4 * ca_modif ;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 9 ,1)  += _term;
 _MATELM1( 0 ,1)  -= _term;
 _term =  kf_cam4 * Cam_Ca3 ;
 _MATELM1( 1 ,9)  += _term;
 _MATELM1( 9 ,9)  += _term;
 _MATELM1( 0 ,9)  -= _term;
 _term =  kr_cam4 ;
 _MATELM1( 1 ,0)  -= _term;
 _MATELM1( 9 ,0)  -= _term;
 _MATELM1( 0 ,0)  += _term;
 /*REACTION*/
  /* ~ Cam_Ca4 + Gef <-> Gef_activated ( kf_gef , kr_gef )*/
 _term =  kf_gef * Cam_Ca4 ;
 _MATELM1( 6 ,6)  += _term;
 _MATELM1( 0 ,6)  += _term;
 _MATELM1( 5 ,6)  -= _term;
 _term =  kf_gef * Gef ;
 _MATELM1( 6 ,0)  += _term;
 _MATELM1( 0 ,0)  += _term;
 _MATELM1( 5 ,0)  -= _term;
 _term =  kr_gef ;
 _MATELM1( 6 ,5)  -= _term;
 _MATELM1( 0 ,5)  -= _term;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ RasGDP <-> RasGTP ( kf_rasGDP * Gef_activated , kr_rasGDP )*/
 _term =  kf_rasGDP * Gef_activated ;
 _MATELM1( 8 ,8)  += _term;
 _MATELM1( 7 ,8)  -= _term;
 _term =  kr_rasGDP ;
 _MATELM1( 8 ,7)  -= _term;
 _MATELM1( 7 ,7)  += _term;
 /*REACTION*/
    } return _reset;
 }
 
/*CVODE end*/
 
static int _ode_count(int _type){ return 11;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  cai = _ion_cai;
  ica = _ion_ica;
  cai = _ion_cai;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
  _ion_cai = cai;
 }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 11; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 static void _ode_synonym(int _cnt, double** _pp, Datum** _ppd) { 
	double* _p; Datum* _ppvar;
 	int _i; 
	for (_i=0; _i < _cnt; ++_i) {_p = _pp[_i]; _ppvar = _ppd[_i];
 _ion_cai =  ca ;
 }}
 
static void _ode_matsol(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  cai = _ion_cai;
  ica = _ion_ica;
  cai = _ion_cai;
 _cvode_sparse_thread(&_thread[_cvspth1]._pvoid, 11, _dlist1, _p, _ode_matsol1, _ppvar, _thread, _nt);
 }}
 
static void _thread_cleanup(Datum* _thread) {
   _nrn_destroy_sparseobj_thread(_thread[_cvspth1]._pvoid);
   _nrn_destroy_sparseobj_thread(_thread[_spth1]._pvoid);
 }
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_ca_sym, _ppvar, 0, 1);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 1, 3);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  Cam_Ca4 = Cam_Ca40;
  Cam_Ca3 = Cam_Ca30;
  Cam_Ca2 = Cam_Ca20;
  Cam_Ca = Cam_Ca0;
  Cam = Cam0;
  Gef_activated = Gef_activated0;
  Gef = Gef0;
  RasGTP = RasGTP0;
  RasGDP = RasGDP0;
  ca_modif = ca_modif0;
  ca = ca0;
 {
   ca = caiBase ;
   ca_modif = 0.0 ;
   Cam = 0.02 ;
   Cam_Ca = 0.0 ;
   Cam_Ca2 = 0.0 ;
   Cam_Ca3 = 0.0 ;
   Cam_Ca4 = 0.0 ;
   Gef = 0.0006 ;
   Gef_activated = 0.0 ;
   RasGDP = 0.0006 ;
   RasGTP = 0.0 ;
   }
 
}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
  cai = _ion_cai;
  ica = _ion_ica;
  cai = _ion_cai;
 initmodel(_p, _ppvar, _thread, _nt);
  _ion_cai = cai;
  nrn_wrote_conc(_ca_sym, (&(_ion_cai)) - 1, _style_ca);
}}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{
} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 
}}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type) {
 double _break, _save;
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 _break = t + .5*dt; _save = t;
 v=_v;
{
  cai = _ion_cai;
  ica = _ion_ica;
  cai = _ion_cai;
 { {
 for (; t < _break; t += dt) {
  sparse_thread(&_thread[_spth1]._pvoid, 11, _slist1, _dlist1, _p, &t, dt, state, _linmat1, _ppvar, _thread, _nt);
  
}}
 t = _save;
 } {
   }
  _ion_cai = cai;
}}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(Cam_Ca4) - _p;  _dlist1[0] = &(DCam_Ca4) - _p;
 _slist1[1] = &(Cam_Ca3) - _p;  _dlist1[1] = &(DCam_Ca3) - _p;
 _slist1[2] = &(Cam_Ca2) - _p;  _dlist1[2] = &(DCam_Ca2) - _p;
 _slist1[3] = &(Cam_Ca) - _p;  _dlist1[3] = &(DCam_Ca) - _p;
 _slist1[4] = &(Cam) - _p;  _dlist1[4] = &(DCam) - _p;
 _slist1[5] = &(Gef_activated) - _p;  _dlist1[5] = &(DGef_activated) - _p;
 _slist1[6] = &(Gef) - _p;  _dlist1[6] = &(DGef) - _p;
 _slist1[7] = &(RasGTP) - _p;  _dlist1[7] = &(DRasGTP) - _p;
 _slist1[8] = &(RasGDP) - _p;  _dlist1[8] = &(DRasGDP) - _p;
 _slist1[9] = &(ca_modif) - _p;  _dlist1[9] = &(Dca_modif) - _p;
 _slist1[10] = &(ca) - _p;  _dlist1[10] = &(Dca) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
