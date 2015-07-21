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
 static void _difusfunc(ldifusfunc2_t, _NrnThread*);
 
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
#define kf_rasGDP _p[2]
#define ca _p[3]
#define ca_modif _p[4]
#define Cam _p[5]
#define Cam_Ca _p[6]
#define Cam_Ca2 _p[7]
#define Cam_Ca3 _p[8]
#define Cam_Ca4 _p[9]
#define Gef _p[10]
#define Gef_activated _p[11]
#define RafPhosphatase _p[12]
#define Mek _p[13]
#define MekP _p[14]
#define MekPP _p[15]
#define MekPhosphatase _p[16]
#define Mapk _p[17]
#define MapkP _p[18]
#define MapkPP _p[19]
#define MapkPhosphatase _p[20]
#define L _p[21]
#define ica _p[22]
#define cai _p[23]
#define Dca _p[24]
#define Dca_modif _p[25]
#define DCam _p[26]
#define DCam_Ca _p[27]
#define DCam_Ca2 _p[28]
#define DCam_Ca3 _p[29]
#define DCam_Ca4 _p[30]
#define DGef _p[31]
#define DGef_activated _p[32]
#define RasGDPi _p[33]
#define DRasGDPi _p[34]
#define RasGTPi _p[35]
#define DRasGTPi _p[36]
#define Rafi _p[37]
#define DRafi _p[38]
#define RafPi _p[39]
#define DRafPi _p[40]
#define DRafPhosphatase _p[41]
#define DMek _p[42]
#define DMekP _p[43]
#define DMekPP _p[44]
#define DMekPhosphatase _p[45]
#define DMapk _p[46]
#define DMapkP _p[47]
#define DMapkPP _p[48]
#define DMapkPhosphatase _p[49]
#define KV42i _p[50]
#define DKV42i _p[51]
#define KV42Pi _p[52]
#define DKV42Pi _p[53]
#define v _p[54]
#define _g _p[55]
#define _ion_cai	*_ppvar[0]._pval
#define _ion_ica	*_ppvar[1]._pval
#define _style_ca	*((int*)_ppvar[2]._pvoid)
#define _ion_dicadv	*_ppvar[3]._pval
#define _ion_RasGTPi	*_ppvar[4]._pval
#define _style_RasGTP	*((int*)_ppvar[5]._pvoid)
#define _ion_diRasGTPdv	*_ppvar[6]._pval
#define _ion_RasGDPi	*_ppvar[7]._pval
#define _style_RasGDP	*((int*)_ppvar[8]._pvoid)
#define _ion_diRasGDPdv	*_ppvar[9]._pval
#define _ion_Rafi	*_ppvar[10]._pval
#define _style_Raf	*((int*)_ppvar[11]._pvoid)
#define _ion_diRafdv	*_ppvar[12]._pval
#define _ion_RafPi	*_ppvar[13]._pval
#define _style_RafP	*((int*)_ppvar[14]._pvoid)
#define _ion_diRafPdv	*_ppvar[15]._pval
#define _ion_KV42i	*_ppvar[16]._pval
#define _style_KV42	*((int*)_ppvar[17]._pvoid)
#define _ion_diKV42dv	*_ppvar[18]._pval
#define _ion_KV42Pi	*_ppvar[19]._pval
#define _style_KV42P	*((int*)_ppvar[20]._pvoid)
#define _ion_diKV42Pdv	*_ppvar[21]._pval
#define diam	*_ppvar[22]._pval
 
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
 #define _ztempRaf _thread[2]._pval[0]
 #define _ztempRafP _thread[2]._pval[1]
 #define _ztempMek _thread[2]._pval[2]
 #define _ztempMekP _thread[2]._pval[3]
 #define _ztempMekPP1 _thread[2]._pval[4]
 #define _ztempMekPP2 _thread[2]._pval[5]
 #define _ztempMapk _thread[2]._pval[6]
 #define _ztempMapkP _thread[2]._pval[7]
 #define _ztempMapkPP1 _thread[2]._pval[8]
 #define _ztempMapkPP2 _thread[2]._pval[9]
 #define _ztempKV42 _thread[2]._pval[10]
 #define _ztempKV42P _thread[2]._pval[11]
 /* declare global and static user variables */
#define DKinases DKinases_cadifus
 double DKinases = 0.001;
#define DRaf DRaf_cadifus
 double DRaf = 0.006;
#define DRas DRas_cadifus
 double DRas = 0.00065;
#define caiBase caiBase_cadifus
 double caiBase = 5e-05;
#define ceiling ceiling_cadifus
 double ceiling = 2;
#define kcat_KV42 kcat_KV42_cadifus
 double kcat_KV42 = 0.01;
#define km_KV42 km_KV42_cadifus
 double km_KV42 = 0.01;
#define km_mapkP km_mapkP_cadifus
 double km_mapkP = 6.66667e-05;
#define kcat_mapkP kcat_mapkP_cadifus
 double kcat_mapkP = 0.001;
#define km_mapk km_mapk_cadifus
 double km_mapk = 4.62963e-05;
#define kcat_mapk kcat_mapk_cadifus
 double kcat_mapk = 0.00015;
#define km_mekP km_mekP_cadifus
 double km_mekP = 0.0156566;
#define kcat_mekP kcat_mekP_cadifus
 double kcat_mekP = 0.006;
#define km_mek km_mek_cadifus
 double km_mek = 0.000159091;
#define kcat_mek kcat_mek_cadifus
 double kcat_mek = 0.000105;
#define km_rafP km_rafP_cadifus
 double km_rafP = 1.67e-05;
#define kcat_rafP kcat_rafP_cadifus
 double kcat_rafP = 0.001;
#define km_raf km_raf_cadifus
 double km_raf = 7.2e-05;
#define kcat_raf kcat_raf_cadifus
 double kcat_raf = 7.624e-05;
#define kr_rasGDP kr_rasGDP_cadifus
 double kr_rasGDP = 3.7037e-06;
#define kr_gef kr_gef_cadifus
 double kr_gef = 0;
#define kf_gef kf_gef_cadifus
 double kf_gef = 0;
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
#define temp temp_cadifus
 double temp = 10;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "DRas_cadifus", "um2/ms",
 "DRaf_cadifus", "um2/ms",
 "DKinases_cadifus", "um2/ms",
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
 "kr_rasGDP_cadifus", "/ms",
 "kcat_raf_cadifus", "/ms",
 "km_raf_cadifus", "mM",
 "kcat_rafP_cadifus", "/ms",
 "km_rafP_cadifus", "mM",
 "kcat_mek_cadifus", "/ms",
 "km_mek_cadifus", "mM",
 "kcat_mekP_cadifus", "/ms",
 "km_mekP_cadifus", "mM",
 "kcat_mapk_cadifus", "/ms",
 "km_mapk_cadifus", "mM",
 "kcat_mapkP_cadifus", "/ms",
 "km_mapkP_cadifus", "mM",
 "km_KV42_cadifus", "mM",
 "kcat_KV42_cadifus", "/ms",
 "phi_cadifus", "/ms",
 "kf_rasGDP_cadifus", "/mM-ms",
 "ca_cadifus", "mM",
 "ca_modif_cadifus", "mM",
 "Cam_cadifus", "mM",
 "Cam_Ca_cadifus", "mM",
 "Cam_Ca2_cadifus", "mM",
 "Cam_Ca3_cadifus", "mM",
 "Cam_Ca4_cadifus", "mM",
 "Gef_cadifus", "mM",
 "Gef_activated_cadifus", "mM",
 "RafPhosphatase_cadifus", "mM",
 "Mek_cadifus", "mM",
 "MekP_cadifus", "mM",
 "MekPP_cadifus", "mM",
 "MekPhosphatase_cadifus", "mM",
 "Mapk_cadifus", "mM",
 "MapkP_cadifus", "mM",
 "MapkPP_cadifus", "mM",
 "MapkPhosphatase_cadifus", "mM",
 0,0
};
 static double Cam_Ca40 = 0;
 static double Cam_Ca30 = 0;
 static double Cam_Ca20 = 0;
 static double Cam_Ca0 = 0;
 static double Cam0 = 0;
 static double Gef_activated0 = 0;
 static double Gef0 = 0;
 static double KV42Pi0 = 0;
 static double KV42i0 = 0;
 static double MapkPhosphatase0 = 0;
 static double MapkPP0 = 0;
 static double MapkP0 = 0;
 static double Mapk0 = 0;
 static double MekPhosphatase0 = 0;
 static double MekPP0 = 0;
 static double MekP0 = 0;
 static double Mek0 = 0;
 static double RafPhosphatase0 = 0;
 static double RafPi0 = 0;
 static double Rafi0 = 0;
 static double RasGTPi0 = 0;
 static double RasGDPi0 = 0;
 static double ca_modif0 = 0;
 static double ca0 = 0;
 static double delta_t = 0.01;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "DRas_cadifus", &DRas_cadifus,
 "DRaf_cadifus", &DRaf_cadifus,
 "DKinases_cadifus", &DKinases_cadifus,
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
 "kr_rasGDP_cadifus", &kr_rasGDP_cadifus,
 "kcat_raf_cadifus", &kcat_raf_cadifus,
 "km_raf_cadifus", &km_raf_cadifus,
 "kcat_rafP_cadifus", &kcat_rafP_cadifus,
 "km_rafP_cadifus", &km_rafP_cadifus,
 "kcat_mek_cadifus", &kcat_mek_cadifus,
 "km_mek_cadifus", &km_mek_cadifus,
 "kcat_mekP_cadifus", &kcat_mekP_cadifus,
 "km_mekP_cadifus", &km_mekP_cadifus,
 "kcat_mapk_cadifus", &kcat_mapk_cadifus,
 "km_mapk_cadifus", &km_mapk_cadifus,
 "kcat_mapkP_cadifus", &kcat_mapkP_cadifus,
 "km_mapkP_cadifus", &km_mapkP_cadifus,
 "km_KV42_cadifus", &km_KV42_cadifus,
 "kcat_KV42_cadifus", &kcat_KV42_cadifus,
 "temp_cadifus", &temp_cadifus,
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
 
#define _cvode_ieq _ppvar[23]._i
 static void _ode_synonym(int, double**, Datum**);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "6.2.0",
"cadifus",
 "phi_cadifus",
 "beta_cadifus",
 "kf_rasGDP_cadifus",
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
 "RafPhosphatase_cadifus",
 "Mek_cadifus",
 "MekP_cadifus",
 "MekPP_cadifus",
 "MekPhosphatase_cadifus",
 "Mapk_cadifus",
 "MapkP_cadifus",
 "MapkPP_cadifus",
 "MapkPhosphatase_cadifus",
 0,
 0};
 static Symbol* _morphology_sym;
 static Symbol* _ca_sym;
 static int _type_ica;
 static Symbol* _RasGTP_sym;
 static int _type_iRasGTP;
 static Symbol* _RasGDP_sym;
 static int _type_iRasGDP;
 static Symbol* _Raf_sym;
 static int _type_iRaf;
 static Symbol* _RafP_sym;
 static int _type_iRafP;
 static Symbol* _KV42_sym;
 static int _type_iKV42;
 static Symbol* _KV42P_sym;
 static int _type_iKV42P;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 56, _prop);
 	/*initialize range parameters*/
 	phi = 0.25;
 	beta = 17.402;
 	kf_rasGDP = 0.1;
 	_prop->param = _p;
 	_prop->param_size = 56;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 24, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_morphology_sym);
 	_ppvar[22]._pval = &prop_ion->param[0]; /* diam */
 prop_ion = need_memb(_ca_sym);
  _type_ica = prop_ion->_type;
 nrn_check_conc_write(_prop, prop_ion, 1);
 nrn_promote(prop_ion, 3, 0);
 	_ppvar[0]._pval = &prop_ion->param[1]; /* cai */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ica */
 	_ppvar[2]._pvoid = (void*)(&(prop_ion->dparam[0]._i)); /* iontype for ca */
 	_ppvar[3]._pval = &prop_ion->param[4]; /* _ion_dicadv */
 prop_ion = need_memb(_RasGTP_sym);
  _type_iRasGTP = prop_ion->_type;
 nrn_check_conc_write(_prop, prop_ion, 1);
 nrn_promote(prop_ion, 3, 0);
 	_ppvar[4]._pval = &prop_ion->param[1]; /* RasGTPi */
 	_ppvar[5]._pvoid = (void*)(&(prop_ion->dparam[0]._i)); /* iontype for RasGTP */
 	_ppvar[6]._pval = &prop_ion->param[4]; /* _ion_diRasGTPdv */
 prop_ion = need_memb(_RasGDP_sym);
  _type_iRasGDP = prop_ion->_type;
 nrn_check_conc_write(_prop, prop_ion, 1);
 nrn_promote(prop_ion, 3, 0);
 	_ppvar[7]._pval = &prop_ion->param[1]; /* RasGDPi */
 	_ppvar[8]._pvoid = (void*)(&(prop_ion->dparam[0]._i)); /* iontype for RasGDP */
 	_ppvar[9]._pval = &prop_ion->param[4]; /* _ion_diRasGDPdv */
 prop_ion = need_memb(_Raf_sym);
  _type_iRaf = prop_ion->_type;
 nrn_check_conc_write(_prop, prop_ion, 1);
 nrn_promote(prop_ion, 3, 0);
 	_ppvar[10]._pval = &prop_ion->param[1]; /* Rafi */
 	_ppvar[11]._pvoid = (void*)(&(prop_ion->dparam[0]._i)); /* iontype for Raf */
 	_ppvar[12]._pval = &prop_ion->param[4]; /* _ion_diRafdv */
 prop_ion = need_memb(_RafP_sym);
  _type_iRafP = prop_ion->_type;
 nrn_check_conc_write(_prop, prop_ion, 1);
 nrn_promote(prop_ion, 3, 0);
 	_ppvar[13]._pval = &prop_ion->param[1]; /* RafPi */
 	_ppvar[14]._pvoid = (void*)(&(prop_ion->dparam[0]._i)); /* iontype for RafP */
 	_ppvar[15]._pval = &prop_ion->param[4]; /* _ion_diRafPdv */
 prop_ion = need_memb(_KV42_sym);
  _type_iKV42 = prop_ion->_type;
 nrn_check_conc_write(_prop, prop_ion, 1);
 nrn_promote(prop_ion, 3, 0);
 	_ppvar[16]._pval = &prop_ion->param[1]; /* KV42i */
 	_ppvar[17]._pvoid = (void*)(&(prop_ion->dparam[0]._i)); /* iontype for KV42 */
 	_ppvar[18]._pval = &prop_ion->param[4]; /* _ion_diKV42dv */
 prop_ion = need_memb(_KV42P_sym);
  _type_iKV42P = prop_ion->_type;
 nrn_check_conc_write(_prop, prop_ion, 1);
 nrn_promote(prop_ion, 3, 0);
 	_ppvar[19]._pval = &prop_ion->param[1]; /* KV42Pi */
 	_ppvar[20]._pvoid = (void*)(&(prop_ion->dparam[0]._i)); /* iontype for KV42P */
 	_ppvar[21]._pval = &prop_ion->param[4]; /* _ion_diKV42Pdv */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 "ca_cadifus", 1e-10,
 0,0
};
 static void _thread_mem_init(Datum*);
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
 	ion_reg("RasGTP", 1.0);
 	ion_reg("RasGDP", 1.0);
 	ion_reg("Raf", 1.0);
 	ion_reg("RafP", 1.0);
 	ion_reg("KV42", 1.0);
 	ion_reg("KV42P", 1.0);
 	_morphology_sym = hoc_lookup("morphology");
 	_ca_sym = hoc_lookup("ca_ion");
 	_RasGTP_sym = hoc_lookup("RasGTP_ion");
 	_RasGDP_sym = hoc_lookup("RasGDP_ion");
 	_Raf_sym = hoc_lookup("Raf_ion");
 	_RafP_sym = hoc_lookup("RafP_ion");
 	_KV42_sym = hoc_lookup("KV42_ion");
 	_KV42P_sym = hoc_lookup("KV42P_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 4);
  _extcall_thread = (Datum*)ecalloc(3, sizeof(Datum));
  _thread_mem_init(_extcall_thread);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 1, _thread_mem_init);
     _nrn_thread_reg(_mechtype, 0, _thread_cleanup);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
  hoc_register_dparam_size(_mechtype, 24);
 	nrn_writes_conc(_mechtype, 0);
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_synonym(_mechtype, _ode_synonym);
 	hoc_register_ldifus1(_difusfunc);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 cadifus /Users/maoss2/Documents/Kv4.2_Model/Mod_Files/x86_64/cadifus.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double FARADAY = 9.64853;
 static double PI = 3.14159;
 /*Top LOCAL _ztempRaf , _ztempRafP , _ztempMek , _ztempMekP , _ztempMekPP1 , _ztempMekPP2 , _ztempMapk , _ztempMapkP , _ztempMapkPP1 , _ztempMapkPP2 , _ztempKV42 , _ztempKV42P */
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
 static int _slist1[21], _dlist1[21]; static double *_temp1;
 static int state();
 
static int state (void* _so, double* _rhs, double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt)
 {int _reset=0;
 {
   double b_flux, f_flux, _term; int _i;
 {int _i; double _dt1 = 1.0/dt;
for(_i=0;_i<21;_i++){
  	_RHS1(_i) = -_dt1*(_p[_slist1[_i]] - _p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
}  
_RHS1(9) *= ( PI * diam * diam / 4.0) ;
_MATELM1(9, 9) *= ( PI * diam * diam / 4.0); 
_RHS1(10) *= ( PI * diam * diam / 4.0) ;
_MATELM1(10, 10) *= ( PI * diam * diam / 4.0); 
_RHS1(11) *= ( PI * diam * diam / 4.0) ;
_MATELM1(11, 11) *= ( PI * diam * diam / 4.0); 
_RHS1(12) *= ( PI * diam * diam / 4.0) ;
_MATELM1(12, 12) *= ( PI * diam * diam / 4.0); 
_RHS1(13) *= ( PI * diam * diam / 4.0) ;
_MATELM1(13, 13) *= ( PI * diam * diam / 4.0); 
_RHS1(14) *= ( PI * diam * diam / 4.0) ;
_MATELM1(14, 14) *= ( PI * diam * diam / 4.0); 
_RHS1(15) *= ( PI * diam * diam / 4.0) ;
_MATELM1(15, 15) *= ( PI * diam * diam / 4.0); 
_RHS1(16) *= ( PI * diam * diam / 4.0) ;
_MATELM1(16, 16) *= ( PI * diam * diam / 4.0); 
_RHS1(17) *= ( PI * diam) ;
_MATELM1(17, 17) *= ( PI * diam); 
_RHS1(18) *= ( PI * diam) ;
_MATELM1(18, 18) *= ( PI * diam);  }
 /* COMPARTMENT PI * diam {
     RasGDPi RasGTPi }
   */
 /* COMPARTMENT PI * diam * diam / 4.0 {
     Rafi RafPi Mek MekP MekPP Mapk MapkP MapkPP }
   */
 /* LONGITUDINAL_DIFFUSION DRas * diam {
     RasGDPi }
   */
 /* LONGITUDINAL_DIFFUSION DRas * diam {
     RasGTPi }
   */
 /* LONGITUDINAL_DIFFUSION DRaf * PI * diam * diam / 4.0 {
     Rafi }
   */
 /* LONGITUDINAL_DIFFUSION DRaf * PI * diam * diam / 4.0 {
     RafPi }
   */
 /* LONGITUDINAL_DIFFUSION DKinases * PI * diam * diam / 4.0 {
     Mek }
   */
 /* LONGITUDINAL_DIFFUSION DKinases * PI * diam * diam / 4.0 {
     MekP }
   */
 /* LONGITUDINAL_DIFFUSION DKinases * PI * diam * diam / 4.0 {
     MekPP }
   */
 /* LONGITUDINAL_DIFFUSION DKinases * PI * diam * diam / 4.0 {
     Mapk }
   */
 /* LONGITUDINAL_DIFFUSION DKinases * PI * diam * diam / 4.0 {
     MapkP }
   */
 /* LONGITUDINAL_DIFFUSION DKinases * PI * diam * diam / 4.0 {
     MapkPP }
   */
 /* ~ ca < < ( ( - beta * ica ) - ( phi * ( cai - caiBase ) ) )*/
 f_flux = b_flux = 0.;
 _RHS1( 20) += (b_flux =   ( ( - beta * ica ) - ( phi * ( cai - caiBase ) ) ) );
 /*FLUX*/
  cai = ca ;
   ca_modif = ca * 2.9 ;
   /* ~ ca_modif + Cam <-> Cam_Ca ( kf_cam1 , kr_cam1 )*/
 f_flux =  kf_cam1 * Cam * ca_modif ;
 b_flux =  kr_cam1 * Cam_Ca ;
 _RHS1( 4) -= (f_flux - b_flux);
 _RHS1( 19) -= (f_flux - b_flux);
 _RHS1( 3) += (f_flux - b_flux);
 
 _term =  kf_cam1 * ca_modif ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 19 ,4)  += _term;
 _MATELM1( 3 ,4)  -= _term;
 _term =  kf_cam1 * Cam ;
 _MATELM1( 4 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 3 ,19)  -= _term;
 _term =  kr_cam1 ;
 _MATELM1( 4 ,3)  -= _term;
 _MATELM1( 19 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 /*REACTION*/
  /* ~ ca_modif + Cam_Ca <-> Cam_Ca2 ( kf_cam2 , kr_cam2 )*/
 f_flux =  kf_cam2 * Cam_Ca * ca_modif ;
 b_flux =  kr_cam2 * Cam_Ca2 ;
 _RHS1( 3) -= (f_flux - b_flux);
 _RHS1( 19) -= (f_flux - b_flux);
 _RHS1( 2) += (f_flux - b_flux);
 
 _term =  kf_cam2 * ca_modif ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 19 ,3)  += _term;
 _MATELM1( 2 ,3)  -= _term;
 _term =  kf_cam2 * Cam_Ca ;
 _MATELM1( 3 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 2 ,19)  -= _term;
 _term =  kr_cam2 ;
 _MATELM1( 3 ,2)  -= _term;
 _MATELM1( 19 ,2)  -= _term;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ ca_modif + Cam_Ca2 <-> Cam_Ca3 ( kf_cam3 , kr_cam3 )*/
 f_flux =  kf_cam3 * Cam_Ca2 * ca_modif ;
 b_flux =  kr_cam3 * Cam_Ca3 ;
 _RHS1( 2) -= (f_flux - b_flux);
 _RHS1( 19) -= (f_flux - b_flux);
 _RHS1( 1) += (f_flux - b_flux);
 
 _term =  kf_cam3 * ca_modif ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 19 ,2)  += _term;
 _MATELM1( 1 ,2)  -= _term;
 _term =  kf_cam3 * Cam_Ca2 ;
 _MATELM1( 2 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 1 ,19)  -= _term;
 _term =  kr_cam3 ;
 _MATELM1( 2 ,1)  -= _term;
 _MATELM1( 19 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ ca_modif + Cam_Ca3 <-> Cam_Ca4 ( kf_cam4 , kr_cam4 )*/
 f_flux =  kf_cam4 * Cam_Ca3 * ca_modif ;
 b_flux =  kr_cam4 * Cam_Ca4 ;
 _RHS1( 1) -= (f_flux - b_flux);
 _RHS1( 19) -= (f_flux - b_flux);
 _RHS1( 0) += (f_flux - b_flux);
 
 _term =  kf_cam4 * ca_modif ;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 19 ,1)  += _term;
 _MATELM1( 0 ,1)  -= _term;
 _term =  kf_cam4 * Cam_Ca3 ;
 _MATELM1( 1 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 0 ,19)  -= _term;
 _term =  kr_cam4 ;
 _MATELM1( 1 ,0)  -= _term;
 _MATELM1( 19 ,0)  -= _term;
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
  /* ~ RasGDPi <-> RasGTPi ( kf_rasGDP * Gef_activated , kr_rasGDP )*/
 f_flux =  kf_rasGDP * Gef_activated * RasGDPi ;
 b_flux =  kr_rasGDP * RasGTPi ;
 _RHS1( 17) -= (f_flux - b_flux);
 _RHS1( 18) += (f_flux - b_flux);
 
 _term =  kf_rasGDP * Gef_activated ;
 _MATELM1( 17 ,17)  += _term;
 _MATELM1( 18 ,17)  -= _term;
 _term =  kr_rasGDP ;
 _MATELM1( 17 ,18)  -= _term;
 _MATELM1( 18 ,18)  += _term;
 /*REACTION*/
  _ztempRaf = ( ( ( 4.0 * kcat_raf / diam ) * 0.00000166057 ) * RasGTPi ) / ( Rafi + km_raf ) ;
   _ztempRafP = ( kcat_rafP * RafPhosphatase ) / ( RafPi + km_rafP ) ;
   /* ~ Rafi <-> RafPi ( _ztempRaf , _ztempRafP )*/
 f_flux =  _ztempRaf * Rafi ;
 b_flux =  _ztempRafP * RafPi ;
 _RHS1( 16) -= (f_flux - b_flux);
 _RHS1( 15) += (f_flux - b_flux);
 
 _term =  _ztempRaf ;
 _MATELM1( 16 ,16)  += _term;
 _MATELM1( 15 ,16)  -= _term;
 _term =  _ztempRafP ;
 _MATELM1( 16 ,15)  -= _term;
 _MATELM1( 15 ,15)  += _term;
 /*REACTION*/
  _ztempMek = ( kcat_mek * RafPi ) / ( Mek + km_mek ) ;
   _ztempMekP = ( kcat_mekP * MekPhosphatase ) / ( MekP + km_mekP ) ;
   /* ~ Mek <-> MekP ( _ztempMek , _ztempMekP )*/
 f_flux =  _ztempMek * Mek ;
 b_flux =  _ztempMekP * MekP ;
 _RHS1( 14) -= (f_flux - b_flux);
 _RHS1( 13) += (f_flux - b_flux);
 
 _term =  _ztempMek ;
 _MATELM1( 14 ,14)  += _term;
 _MATELM1( 13 ,14)  -= _term;
 _term =  _ztempMekP ;
 _MATELM1( 14 ,13)  -= _term;
 _MATELM1( 13 ,13)  += _term;
 /*REACTION*/
  _ztempMekPP1 = ( kcat_mek * RafPi ) / ( MekP + km_mek ) ;
   _ztempMekPP2 = ( kcat_mekP * MekPhosphatase ) / ( MekPP + km_mekP ) ;
   /* ~ MekP <-> MekPP ( _ztempMekPP1 , _ztempMekPP2 )*/
 f_flux =  _ztempMekPP1 * MekP ;
 b_flux =  _ztempMekPP2 * MekPP ;
 _RHS1( 13) -= (f_flux - b_flux);
 _RHS1( 12) += (f_flux - b_flux);
 
 _term =  _ztempMekPP1 ;
 _MATELM1( 13 ,13)  += _term;
 _MATELM1( 12 ,13)  -= _term;
 _term =  _ztempMekPP2 ;
 _MATELM1( 13 ,12)  -= _term;
 _MATELM1( 12 ,12)  += _term;
 /*REACTION*/
  _ztempMapk = ( kcat_mapk * MekPP ) / ( Mapk + km_mapk ) ;
   _ztempMapkP = ( kcat_mapkP * MapkPhosphatase ) / ( MapkP + km_mapkP ) ;
   /* ~ Mapk <-> MapkP ( _ztempMapk , _ztempMapkP )*/
 f_flux =  _ztempMapk * Mapk ;
 b_flux =  _ztempMapkP * MapkP ;
 _RHS1( 11) -= (f_flux - b_flux);
 _RHS1( 10) += (f_flux - b_flux);
 
 _term =  _ztempMapk ;
 _MATELM1( 11 ,11)  += _term;
 _MATELM1( 10 ,11)  -= _term;
 _term =  _ztempMapkP ;
 _MATELM1( 11 ,10)  -= _term;
 _MATELM1( 10 ,10)  += _term;
 /*REACTION*/
  _ztempMapkPP1 = ( kcat_mapk * MekPP ) / ( MapkP + km_mapk ) ;
   _ztempMapkPP2 = ( kcat_mapkP * MapkPhosphatase ) / ( MapkPP + km_mapkP ) ;
   /* ~ MapkP <-> MapkPP ( _ztempMapkPP1 , _ztempMapkPP2 )*/
 f_flux =  _ztempMapkPP1 * MapkP ;
 b_flux =  _ztempMapkPP2 * MapkPP ;
 _RHS1( 10) -= (f_flux - b_flux);
 _RHS1( 9) += (f_flux - b_flux);
 
 _term =  _ztempMapkPP1 ;
 _MATELM1( 10 ,10)  += _term;
 _MATELM1( 9 ,10)  -= _term;
 _term =  _ztempMapkPP2 ;
 _MATELM1( 10 ,9)  -= _term;
 _MATELM1( 9 ,9)  += _term;
 /*REACTION*/
  _ztempKV42 = ( kcat_KV42 * MapkPP ) / ( KV42i + km_KV42 ) ;
   _ztempKV42P = ( kcat_mekP * MekPhosphatase ) / ( KV42Pi + km_mekP ) ;
   /* ~ KV42i <-> KV42Pi ( _ztempKV42 , _ztempKV42P )*/
 f_flux =  _ztempKV42 * KV42i ;
 b_flux =  _ztempKV42P * KV42Pi ;
 _RHS1( 8) -= (f_flux - b_flux);
 _RHS1( 7) += (f_flux - b_flux);
 
 _term =  _ztempKV42 ;
 _MATELM1( 8 ,8)  += _term;
 _MATELM1( 7 ,8)  -= _term;
 _term =  _ztempKV42P ;
 _MATELM1( 8 ,7)  -= _term;
 _MATELM1( 7 ,7)  += _term;
 /*REACTION*/
    } return _reset;
 }
 
/*CVODE ode begin*/
 static int _ode_spec1(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset=0;{
 double b_flux, f_flux, _term; int _i;
 {int _i; for(_i=0;_i<21;_i++) _p[_dlist1[_i]] = 0.0;}
 /* COMPARTMENT PI * diam {
   RasGDPi RasGTPi }
 */
 /* COMPARTMENT PI * diam * diam / 4.0 {
   Rafi RafPi Mek MekP MekPP Mapk MapkP MapkPP }
 */
 /* LONGITUDINAL_DIFFUSION DRas * diam {
   RasGDPi }
 */
 /* LONGITUDINAL_DIFFUSION DRas * diam {
   RasGTPi }
 */
 /* LONGITUDINAL_DIFFUSION DRaf * PI * diam * diam / 4.0 {
   Rafi }
 */
 /* LONGITUDINAL_DIFFUSION DRaf * PI * diam * diam / 4.0 {
   RafPi }
 */
 /* LONGITUDINAL_DIFFUSION DKinases * PI * diam * diam / 4.0 {
   Mek }
 */
 /* LONGITUDINAL_DIFFUSION DKinases * PI * diam * diam / 4.0 {
   MekP }
 */
 /* LONGITUDINAL_DIFFUSION DKinases * PI * diam * diam / 4.0 {
   MekPP }
 */
 /* LONGITUDINAL_DIFFUSION DKinases * PI * diam * diam / 4.0 {
   Mapk }
 */
 /* LONGITUDINAL_DIFFUSION DKinases * PI * diam * diam / 4.0 {
   MapkP }
 */
 /* LONGITUDINAL_DIFFUSION DKinases * PI * diam * diam / 4.0 {
   MapkPP }
 */
 /* ~ ca < < ( ( - beta * ica ) - ( phi * ( cai - caiBase ) ) )*/
 f_flux = b_flux = 0.;
 Dca += (b_flux =   ( ( - beta * ica ) - ( phi * ( cai - caiBase ) ) ) );
 /*FLUX*/
  cai = ca ;
 ca_modif = ca * 2.9 ;
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
  /* ~ RasGDPi <-> RasGTPi ( kf_rasGDP * Gef_activated , kr_rasGDP )*/
 f_flux =  kf_rasGDP * Gef_activated * RasGDPi ;
 b_flux =  kr_rasGDP * RasGTPi ;
 DRasGDPi -= (f_flux - b_flux);
 DRasGTPi += (f_flux - b_flux);
 
 /*REACTION*/
  _ztempRaf = ( ( ( 4.0 * kcat_raf / diam ) * 0.00000166057 ) * RasGTPi ) / ( Rafi + km_raf ) ;
 _ztempRafP = ( kcat_rafP * RafPhosphatase ) / ( RafPi + km_rafP ) ;
 /* ~ Rafi <-> RafPi ( _ztempRaf , _ztempRafP )*/
 f_flux =  _ztempRaf * Rafi ;
 b_flux =  _ztempRafP * RafPi ;
 DRafi -= (f_flux - b_flux);
 DRafPi += (f_flux - b_flux);
 
 /*REACTION*/
  _ztempMek = ( kcat_mek * RafPi ) / ( Mek + km_mek ) ;
 _ztempMekP = ( kcat_mekP * MekPhosphatase ) / ( MekP + km_mekP ) ;
 /* ~ Mek <-> MekP ( _ztempMek , _ztempMekP )*/
 f_flux =  _ztempMek * Mek ;
 b_flux =  _ztempMekP * MekP ;
 DMek -= (f_flux - b_flux);
 DMekP += (f_flux - b_flux);
 
 /*REACTION*/
  _ztempMekPP1 = ( kcat_mek * RafPi ) / ( MekP + km_mek ) ;
 _ztempMekPP2 = ( kcat_mekP * MekPhosphatase ) / ( MekPP + km_mekP ) ;
 /* ~ MekP <-> MekPP ( _ztempMekPP1 , _ztempMekPP2 )*/
 f_flux =  _ztempMekPP1 * MekP ;
 b_flux =  _ztempMekPP2 * MekPP ;
 DMekP -= (f_flux - b_flux);
 DMekPP += (f_flux - b_flux);
 
 /*REACTION*/
  _ztempMapk = ( kcat_mapk * MekPP ) / ( Mapk + km_mapk ) ;
 _ztempMapkP = ( kcat_mapkP * MapkPhosphatase ) / ( MapkP + km_mapkP ) ;
 /* ~ Mapk <-> MapkP ( _ztempMapk , _ztempMapkP )*/
 f_flux =  _ztempMapk * Mapk ;
 b_flux =  _ztempMapkP * MapkP ;
 DMapk -= (f_flux - b_flux);
 DMapkP += (f_flux - b_flux);
 
 /*REACTION*/
  _ztempMapkPP1 = ( kcat_mapk * MekPP ) / ( MapkP + km_mapk ) ;
 _ztempMapkPP2 = ( kcat_mapkP * MapkPhosphatase ) / ( MapkPP + km_mapkP ) ;
 /* ~ MapkP <-> MapkPP ( _ztempMapkPP1 , _ztempMapkPP2 )*/
 f_flux =  _ztempMapkPP1 * MapkP ;
 b_flux =  _ztempMapkPP2 * MapkPP ;
 DMapkP -= (f_flux - b_flux);
 DMapkPP += (f_flux - b_flux);
 
 /*REACTION*/
  _ztempKV42 = ( kcat_KV42 * MapkPP ) / ( KV42i + km_KV42 ) ;
 _ztempKV42P = ( kcat_mekP * MekPhosphatase ) / ( KV42Pi + km_mekP ) ;
 /* ~ KV42i <-> KV42Pi ( _ztempKV42 , _ztempKV42P )*/
 f_flux =  _ztempKV42 * KV42i ;
 b_flux =  _ztempKV42P * KV42Pi ;
 DKV42i -= (f_flux - b_flux);
 DKV42Pi += (f_flux - b_flux);
 
 /*REACTION*/
  _p[_dlist1[9]] /= ( PI * diam * diam / 4.0);
 _p[_dlist1[10]] /= ( PI * diam * diam / 4.0);
 _p[_dlist1[11]] /= ( PI * diam * diam / 4.0);
 _p[_dlist1[12]] /= ( PI * diam * diam / 4.0);
 _p[_dlist1[13]] /= ( PI * diam * diam / 4.0);
 _p[_dlist1[14]] /= ( PI * diam * diam / 4.0);
 _p[_dlist1[15]] /= ( PI * diam * diam / 4.0);
 _p[_dlist1[16]] /= ( PI * diam * diam / 4.0);
 _p[_dlist1[17]] /= ( PI * diam);
 _p[_dlist1[18]] /= ( PI * diam);
   } return _reset;
 }
 
/*CVODE matsol*/
 static int _ode_matsol1(void* _so, double* _rhs, double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset=0;{
 double b_flux, f_flux, _term; int _i;
   b_flux = f_flux = 0.;
 {int _i; double _dt1 = 1.0/dt;
for(_i=0;_i<21;_i++){
  	_RHS1(_i) = _dt1*(_p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
}  
_RHS1(9) *= ( PI * diam * diam / 4.0) ;
_MATELM1(9, 9) *= ( PI * diam * diam / 4.0); 
_RHS1(10) *= ( PI * diam * diam / 4.0) ;
_MATELM1(10, 10) *= ( PI * diam * diam / 4.0); 
_RHS1(11) *= ( PI * diam * diam / 4.0) ;
_MATELM1(11, 11) *= ( PI * diam * diam / 4.0); 
_RHS1(12) *= ( PI * diam * diam / 4.0) ;
_MATELM1(12, 12) *= ( PI * diam * diam / 4.0); 
_RHS1(13) *= ( PI * diam * diam / 4.0) ;
_MATELM1(13, 13) *= ( PI * diam * diam / 4.0); 
_RHS1(14) *= ( PI * diam * diam / 4.0) ;
_MATELM1(14, 14) *= ( PI * diam * diam / 4.0); 
_RHS1(15) *= ( PI * diam * diam / 4.0) ;
_MATELM1(15, 15) *= ( PI * diam * diam / 4.0); 
_RHS1(16) *= ( PI * diam * diam / 4.0) ;
_MATELM1(16, 16) *= ( PI * diam * diam / 4.0); 
_RHS1(17) *= ( PI * diam) ;
_MATELM1(17, 17) *= ( PI * diam); 
_RHS1(18) *= ( PI * diam) ;
_MATELM1(18, 18) *= ( PI * diam);  }
 /* COMPARTMENT PI * diam {
 RasGDPi RasGTPi }
 */
 /* COMPARTMENT PI * diam * diam / 4.0 {
 Rafi RafPi Mek MekP MekPP Mapk MapkP MapkPP }
 */
 /* LONGITUDINAL_DIFFUSION DRas * diam {
 RasGDPi }
 */
 /* LONGITUDINAL_DIFFUSION DRas * diam {
 RasGTPi }
 */
 /* LONGITUDINAL_DIFFUSION DRaf * PI * diam * diam / 4.0 {
 Rafi }
 */
 /* LONGITUDINAL_DIFFUSION DRaf * PI * diam * diam / 4.0 {
 RafPi }
 */
 /* LONGITUDINAL_DIFFUSION DKinases * PI * diam * diam / 4.0 {
 Mek }
 */
 /* LONGITUDINAL_DIFFUSION DKinases * PI * diam * diam / 4.0 {
 MekP }
 */
 /* LONGITUDINAL_DIFFUSION DKinases * PI * diam * diam / 4.0 {
 MekPP }
 */
 /* LONGITUDINAL_DIFFUSION DKinases * PI * diam * diam / 4.0 {
 Mapk }
 */
 /* LONGITUDINAL_DIFFUSION DKinases * PI * diam * diam / 4.0 {
 MapkP }
 */
 /* LONGITUDINAL_DIFFUSION DKinases * PI * diam * diam / 4.0 {
 MapkPP }
 */
 /* ~ ca < < ( ( - beta * ica ) - ( phi * ( cai - caiBase ) ) )*/
 /*FLUX*/
  cai = ca ;
 ca_modif = ca * 2.9 ;
 /* ~ ca_modif + Cam <-> Cam_Ca ( kf_cam1 , kr_cam1 )*/
 _term =  kf_cam1 * ca_modif ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 19 ,4)  += _term;
 _MATELM1( 3 ,4)  -= _term;
 _term =  kf_cam1 * Cam ;
 _MATELM1( 4 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 3 ,19)  -= _term;
 _term =  kr_cam1 ;
 _MATELM1( 4 ,3)  -= _term;
 _MATELM1( 19 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 /*REACTION*/
  /* ~ ca_modif + Cam_Ca <-> Cam_Ca2 ( kf_cam2 , kr_cam2 )*/
 _term =  kf_cam2 * ca_modif ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 19 ,3)  += _term;
 _MATELM1( 2 ,3)  -= _term;
 _term =  kf_cam2 * Cam_Ca ;
 _MATELM1( 3 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 2 ,19)  -= _term;
 _term =  kr_cam2 ;
 _MATELM1( 3 ,2)  -= _term;
 _MATELM1( 19 ,2)  -= _term;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ ca_modif + Cam_Ca2 <-> Cam_Ca3 ( kf_cam3 , kr_cam3 )*/
 _term =  kf_cam3 * ca_modif ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 19 ,2)  += _term;
 _MATELM1( 1 ,2)  -= _term;
 _term =  kf_cam3 * Cam_Ca2 ;
 _MATELM1( 2 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 1 ,19)  -= _term;
 _term =  kr_cam3 ;
 _MATELM1( 2 ,1)  -= _term;
 _MATELM1( 19 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ ca_modif + Cam_Ca3 <-> Cam_Ca4 ( kf_cam4 , kr_cam4 )*/
 _term =  kf_cam4 * ca_modif ;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 19 ,1)  += _term;
 _MATELM1( 0 ,1)  -= _term;
 _term =  kf_cam4 * Cam_Ca3 ;
 _MATELM1( 1 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 0 ,19)  -= _term;
 _term =  kr_cam4 ;
 _MATELM1( 1 ,0)  -= _term;
 _MATELM1( 19 ,0)  -= _term;
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
  /* ~ RasGDPi <-> RasGTPi ( kf_rasGDP * Gef_activated , kr_rasGDP )*/
 _term =  kf_rasGDP * Gef_activated ;
 _MATELM1( 17 ,17)  += _term;
 _MATELM1( 18 ,17)  -= _term;
 _term =  kr_rasGDP ;
 _MATELM1( 17 ,18)  -= _term;
 _MATELM1( 18 ,18)  += _term;
 /*REACTION*/
  _ztempRaf = ( ( ( 4.0 * kcat_raf / diam ) * 0.00000166057 ) * RasGTPi ) / ( Rafi + km_raf ) ;
 _ztempRafP = ( kcat_rafP * RafPhosphatase ) / ( RafPi + km_rafP ) ;
 /* ~ Rafi <-> RafPi ( _ztempRaf , _ztempRafP )*/
 _term =  _ztempRaf ;
 _MATELM1( 16 ,16)  += _term;
 _MATELM1( 15 ,16)  -= _term;
 _term =  _ztempRafP ;
 _MATELM1( 16 ,15)  -= _term;
 _MATELM1( 15 ,15)  += _term;
 /*REACTION*/
  _ztempMek = ( kcat_mek * RafPi ) / ( Mek + km_mek ) ;
 _ztempMekP = ( kcat_mekP * MekPhosphatase ) / ( MekP + km_mekP ) ;
 /* ~ Mek <-> MekP ( _ztempMek , _ztempMekP )*/
 _term =  _ztempMek ;
 _MATELM1( 14 ,14)  += _term;
 _MATELM1( 13 ,14)  -= _term;
 _term =  _ztempMekP ;
 _MATELM1( 14 ,13)  -= _term;
 _MATELM1( 13 ,13)  += _term;
 /*REACTION*/
  _ztempMekPP1 = ( kcat_mek * RafPi ) / ( MekP + km_mek ) ;
 _ztempMekPP2 = ( kcat_mekP * MekPhosphatase ) / ( MekPP + km_mekP ) ;
 /* ~ MekP <-> MekPP ( _ztempMekPP1 , _ztempMekPP2 )*/
 _term =  _ztempMekPP1 ;
 _MATELM1( 13 ,13)  += _term;
 _MATELM1( 12 ,13)  -= _term;
 _term =  _ztempMekPP2 ;
 _MATELM1( 13 ,12)  -= _term;
 _MATELM1( 12 ,12)  += _term;
 /*REACTION*/
  _ztempMapk = ( kcat_mapk * MekPP ) / ( Mapk + km_mapk ) ;
 _ztempMapkP = ( kcat_mapkP * MapkPhosphatase ) / ( MapkP + km_mapkP ) ;
 /* ~ Mapk <-> MapkP ( _ztempMapk , _ztempMapkP )*/
 _term =  _ztempMapk ;
 _MATELM1( 11 ,11)  += _term;
 _MATELM1( 10 ,11)  -= _term;
 _term =  _ztempMapkP ;
 _MATELM1( 11 ,10)  -= _term;
 _MATELM1( 10 ,10)  += _term;
 /*REACTION*/
  _ztempMapkPP1 = ( kcat_mapk * MekPP ) / ( MapkP + km_mapk ) ;
 _ztempMapkPP2 = ( kcat_mapkP * MapkPhosphatase ) / ( MapkPP + km_mapkP ) ;
 /* ~ MapkP <-> MapkPP ( _ztempMapkPP1 , _ztempMapkPP2 )*/
 _term =  _ztempMapkPP1 ;
 _MATELM1( 10 ,10)  += _term;
 _MATELM1( 9 ,10)  -= _term;
 _term =  _ztempMapkPP2 ;
 _MATELM1( 10 ,9)  -= _term;
 _MATELM1( 9 ,9)  += _term;
 /*REACTION*/
  _ztempKV42 = ( kcat_KV42 * MapkPP ) / ( KV42i + km_KV42 ) ;
 _ztempKV42P = ( kcat_mekP * MekPhosphatase ) / ( KV42Pi + km_mekP ) ;
 /* ~ KV42i <-> KV42Pi ( _ztempKV42 , _ztempKV42P )*/
 _term =  _ztempKV42 ;
 _MATELM1( 8 ,8)  += _term;
 _MATELM1( 7 ,8)  -= _term;
 _term =  _ztempKV42P ;
 _MATELM1( 8 ,7)  -= _term;
 _MATELM1( 7 ,7)  += _term;
 /*REACTION*/
    } return _reset;
 }
 
/*CVODE end*/
 
static int _ode_count(int _type){ return 21;}
 
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
  RasGTPi = _ion_RasGTPi;
  RasGTPi = _ion_RasGTPi;
  RasGDPi = _ion_RasGDPi;
  RasGDPi = _ion_RasGDPi;
  Rafi = _ion_Rafi;
  Rafi = _ion_Rafi;
  RafPi = _ion_RafPi;
  RafPi = _ion_RafPi;
  KV42i = _ion_KV42i;
  KV42i = _ion_KV42i;
  KV42Pi = _ion_KV42Pi;
  KV42Pi = _ion_KV42Pi;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
  _ion_cai = cai;
  _ion_RasGTPi = RasGTPi;
  _ion_RasGDPi = RasGDPi;
  _ion_Rafi = Rafi;
  _ion_RafPi = RafPi;
  _ion_KV42i = KV42i;
  _ion_KV42Pi = KV42Pi;
 }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 21; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 	_pv[18] = &(_ion_RasGTPi);
 	_pv[17] = &(_ion_RasGDPi);
 	_pv[16] = &(_ion_Rafi);
 	_pv[15] = &(_ion_RafPi);
 	_pv[8] = &(_ion_KV42i);
 	_pv[7] = &(_ion_KV42Pi);
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
  RasGTPi = _ion_RasGTPi;
  RasGTPi = _ion_RasGTPi;
  RasGDPi = _ion_RasGDPi;
  RasGDPi = _ion_RasGDPi;
  Rafi = _ion_Rafi;
  Rafi = _ion_Rafi;
  RafPi = _ion_RafPi;
  RafPi = _ion_RafPi;
  KV42i = _ion_KV42i;
  KV42i = _ion_KV42i;
  KV42Pi = _ion_KV42Pi;
  KV42Pi = _ion_KV42Pi;
 _cvode_sparse_thread(&_thread[_cvspth1]._pvoid, 21, _dlist1, _p, _ode_matsol1, _ppvar, _thread, _nt);
 }}
 
static void _thread_mem_init(Datum* _thread) {
   _thread[2]._pval = (double*)ecalloc(12, sizeof(double));
 }
 
static void _thread_cleanup(Datum* _thread) {
   _nrn_destroy_sparseobj_thread(_thread[_cvspth1]._pvoid);
   _nrn_destroy_sparseobj_thread(_thread[_spth1]._pvoid);
   free((void*)(_thread[2]._pval));
 }
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_ca_sym, _ppvar, 0, 1);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 3, 4);
   nrn_update_ion_pointer(_RasGTP_sym, _ppvar, 4, 1);
   nrn_update_ion_pointer(_RasGTP_sym, _ppvar, 6, 4);
   nrn_update_ion_pointer(_RasGDP_sym, _ppvar, 7, 1);
   nrn_update_ion_pointer(_RasGDP_sym, _ppvar, 9, 4);
   nrn_update_ion_pointer(_Raf_sym, _ppvar, 10, 1);
   nrn_update_ion_pointer(_Raf_sym, _ppvar, 12, 4);
   nrn_update_ion_pointer(_RafP_sym, _ppvar, 13, 1);
   nrn_update_ion_pointer(_RafP_sym, _ppvar, 15, 4);
   nrn_update_ion_pointer(_KV42_sym, _ppvar, 16, 1);
   nrn_update_ion_pointer(_KV42_sym, _ppvar, 18, 4);
   nrn_update_ion_pointer(_KV42P_sym, _ppvar, 19, 1);
   nrn_update_ion_pointer(_KV42P_sym, _ppvar, 21, 4);
 }
 static void* _difspace1;
extern double nrn_nernst_coef();
static double _difcoef1(int _i, double* _p, Datum* _ppvar, double* _pdvol, double* _pdfcdc, Datum* _thread, _NrnThread* _nt) {
   *_pdvol =  PI * diam ; *_pdfcdc=0.;
   return DRas * diam ;
}
 static void* _difspace2;
extern double nrn_nernst_coef();
static double _difcoef2(int _i, double* _p, Datum* _ppvar, double* _pdvol, double* _pdfcdc, Datum* _thread, _NrnThread* _nt) {
   *_pdvol =  PI * diam ; *_pdfcdc=0.;
   return DRas * diam ;
}
 static void* _difspace3;
extern double nrn_nernst_coef();
static double _difcoef3(int _i, double* _p, Datum* _ppvar, double* _pdvol, double* _pdfcdc, Datum* _thread, _NrnThread* _nt) {
   *_pdvol =  PI * diam * diam / 4.0 ; *_pdfcdc=0.;
   return DRaf * PI * diam * diam / 4.0 ;
}
 static void* _difspace4;
extern double nrn_nernst_coef();
static double _difcoef4(int _i, double* _p, Datum* _ppvar, double* _pdvol, double* _pdfcdc, Datum* _thread, _NrnThread* _nt) {
   *_pdvol =  PI * diam * diam / 4.0 ; *_pdfcdc=0.;
   return DRaf * PI * diam * diam / 4.0 ;
}
 static void* _difspace5;
extern double nrn_nernst_coef();
static double _difcoef5(int _i, double* _p, Datum* _ppvar, double* _pdvol, double* _pdfcdc, Datum* _thread, _NrnThread* _nt) {
   *_pdvol =  PI * diam * diam / 4.0 ; *_pdfcdc=0.;
   return DKinases * PI * diam * diam / 4.0 ;
}
 static void* _difspace6;
extern double nrn_nernst_coef();
static double _difcoef6(int _i, double* _p, Datum* _ppvar, double* _pdvol, double* _pdfcdc, Datum* _thread, _NrnThread* _nt) {
   *_pdvol =  PI * diam * diam / 4.0 ; *_pdfcdc=0.;
   return DKinases * PI * diam * diam / 4.0 ;
}
 static void* _difspace7;
extern double nrn_nernst_coef();
static double _difcoef7(int _i, double* _p, Datum* _ppvar, double* _pdvol, double* _pdfcdc, Datum* _thread, _NrnThread* _nt) {
   *_pdvol =  PI * diam * diam / 4.0 ; *_pdfcdc=0.;
   return DKinases * PI * diam * diam / 4.0 ;
}
 static void* _difspace8;
extern double nrn_nernst_coef();
static double _difcoef8(int _i, double* _p, Datum* _ppvar, double* _pdvol, double* _pdfcdc, Datum* _thread, _NrnThread* _nt) {
   *_pdvol =  PI * diam * diam / 4.0 ; *_pdfcdc=0.;
   return DKinases * PI * diam * diam / 4.0 ;
}
 static void* _difspace9;
extern double nrn_nernst_coef();
static double _difcoef9(int _i, double* _p, Datum* _ppvar, double* _pdvol, double* _pdfcdc, Datum* _thread, _NrnThread* _nt) {
   *_pdvol =  PI * diam * diam / 4.0 ; *_pdfcdc=0.;
   return DKinases * PI * diam * diam / 4.0 ;
}
 static void* _difspace10;
extern double nrn_nernst_coef();
static double _difcoef10(int _i, double* _p, Datum* _ppvar, double* _pdvol, double* _pdfcdc, Datum* _thread, _NrnThread* _nt) {
   *_pdvol =  PI * diam * diam / 4.0 ; *_pdfcdc=0.;
   return DKinases * PI * diam * diam / 4.0 ;
}
 static void _difusfunc(ldifusfunc2_t _f, _NrnThread* _nt) {int _i;
  (*_f)(_mechtype, _difcoef1, &_difspace1, 0,  -8, 34 , _nt);
  (*_f)(_mechtype, _difcoef2, &_difspace2, 0,  -5, 36 , _nt);
  (*_f)(_mechtype, _difcoef3, &_difspace3, 0,  -11, 38 , _nt);
  (*_f)(_mechtype, _difcoef4, &_difspace4, 0,  -14, 40 , _nt);
  (*_f)(_mechtype, _difcoef5, &_difspace5, 0,  13, 42 , _nt);
  (*_f)(_mechtype, _difcoef6, &_difspace6, 0,  14, 43 , _nt);
  (*_f)(_mechtype, _difcoef7, &_difspace7, 0,  15, 44 , _nt);
  (*_f)(_mechtype, _difcoef8, &_difspace8, 0,  17, 46 , _nt);
  (*_f)(_mechtype, _difcoef9, &_difspace9, 0,  18, 47 , _nt);
  (*_f)(_mechtype, _difcoef10, &_difspace10, 0,  19, 48 , _nt);
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
  MapkPhosphatase = MapkPhosphatase0;
  MapkPP = MapkPP0;
  MapkP = MapkP0;
  Mapk = Mapk0;
  MekPhosphatase = MekPhosphatase0;
  MekPP = MekPP0;
  MekP = MekP0;
  Mek = Mek0;
  RafPhosphatase = RafPhosphatase0;
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
   RasGDPi = 90.0 ;
   RasGTPi = 0.0 ;
   Rafi = 0.2e-3 ;
   RafPi = 0.0 ;
   RafPhosphatase = 0.00375e-3 ;
   Mek = 0.18e-3 ;
   MekP = 0.0 ;
   MekPP = 0.0 ;
   MekPhosphatase = 0.112e-3 ;
   Mapk = 0.36e-3 ;
   MapkP = 0.0 ;
   MapkPP = 0.0 ;
   MapkPhosphatase = 0.001e-3 ;
   KV42i = 1.86e-4 ;
   KV42Pi = 0.0 ;
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
  RasGTPi = _ion_RasGTPi;
  RasGTPi = _ion_RasGTPi;
  RasGDPi = _ion_RasGDPi;
  RasGDPi = _ion_RasGDPi;
  Rafi = _ion_Rafi;
  Rafi = _ion_Rafi;
  RafPi = _ion_RafPi;
  RafPi = _ion_RafPi;
  KV42i = _ion_KV42i;
  KV42i = _ion_KV42i;
  KV42Pi = _ion_KV42Pi;
  KV42Pi = _ion_KV42Pi;
 initmodel(_p, _ppvar, _thread, _nt);
  _ion_cai = cai;
  nrn_wrote_conc(_ca_sym, (&(_ion_cai)) - 1, _style_ca);
  _ion_RasGTPi = RasGTPi;
  nrn_wrote_conc(_RasGTP_sym, (&(_ion_RasGTPi)) - 1, _style_RasGTP);
  _ion_RasGDPi = RasGDPi;
  nrn_wrote_conc(_RasGDP_sym, (&(_ion_RasGDPi)) - 1, _style_RasGDP);
  _ion_Rafi = Rafi;
  nrn_wrote_conc(_Raf_sym, (&(_ion_Rafi)) - 1, _style_Raf);
  _ion_RafPi = RafPi;
  nrn_wrote_conc(_RafP_sym, (&(_ion_RafPi)) - 1, _style_RafP);
  _ion_KV42i = KV42i;
  nrn_wrote_conc(_KV42_sym, (&(_ion_KV42i)) - 1, _style_KV42);
  _ion_KV42Pi = KV42Pi;
  nrn_wrote_conc(_KV42P_sym, (&(_ion_KV42Pi)) - 1, _style_KV42P);
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
  RasGTPi = _ion_RasGTPi;
  RasGTPi = _ion_RasGTPi;
  RasGDPi = _ion_RasGDPi;
  RasGDPi = _ion_RasGDPi;
  Rafi = _ion_Rafi;
  Rafi = _ion_Rafi;
  RafPi = _ion_RafPi;
  RafPi = _ion_RafPi;
  KV42i = _ion_KV42i;
  KV42i = _ion_KV42i;
  KV42Pi = _ion_KV42Pi;
  KV42Pi = _ion_KV42Pi;
 { {
 for (; t < _break; t += dt) {
  sparse_thread(&_thread[_spth1]._pvoid, 21, _slist1, _dlist1, _p, &t, dt, state, _linmat1, _ppvar, _thread, _nt);
  
}}
 t = _save;
 } {
   }
  _ion_cai = cai;
  _ion_RasGTPi = RasGTPi;
  _ion_RasGDPi = RasGDPi;
  _ion_Rafi = Rafi;
  _ion_RafPi = RafPi;
  _ion_KV42i = KV42i;
  _ion_KV42Pi = KV42Pi;
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
 _slist1[7] = &(KV42Pi) - _p;  _dlist1[7] = &(DKV42Pi) - _p;
 _slist1[8] = &(KV42i) - _p;  _dlist1[8] = &(DKV42i) - _p;
 _slist1[9] = &(MapkPP) - _p;  _dlist1[9] = &(DMapkPP) - _p;
 _slist1[10] = &(MapkP) - _p;  _dlist1[10] = &(DMapkP) - _p;
 _slist1[11] = &(Mapk) - _p;  _dlist1[11] = &(DMapk) - _p;
 _slist1[12] = &(MekPP) - _p;  _dlist1[12] = &(DMekPP) - _p;
 _slist1[13] = &(MekP) - _p;  _dlist1[13] = &(DMekP) - _p;
 _slist1[14] = &(Mek) - _p;  _dlist1[14] = &(DMek) - _p;
 _slist1[15] = &(RafPi) - _p;  _dlist1[15] = &(DRafPi) - _p;
 _slist1[16] = &(Rafi) - _p;  _dlist1[16] = &(DRafi) - _p;
 _slist1[17] = &(RasGDPi) - _p;  _dlist1[17] = &(DRasGDPi) - _p;
 _slist1[18] = &(RasGTPi) - _p;  _dlist1[18] = &(DRasGTPi) - _p;
 _slist1[19] = &(ca_modif) - _p;  _dlist1[19] = &(Dca_modif) - _p;
 _slist1[20] = &(ca) - _p;  _dlist1[20] = &(Dca) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
