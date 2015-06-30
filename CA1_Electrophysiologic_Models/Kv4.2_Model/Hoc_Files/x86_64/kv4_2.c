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
#define gkbar _p[0]
#define mshift _p[1]
#define hshift _p[2]
#define mshift_mutant _p[3]
#define hshift_mutant _p[4]
#define ik _p[5]
#define m _p[6]
#define h _p[7]
#define n _p[8]
#define q _p[9]
#define KV42Pi _p[10]
#define KV42i _p[11]
#define KTESTi _p[12]
#define KTESTPi _p[13]
#define ek _p[14]
#define minf _p[15]
#define hinf _p[16]
#define ninf _p[17]
#define qinf _p[18]
#define Dm _p[19]
#define Dh _p[20]
#define Dn _p[21]
#define Dq _p[22]
#define v _p[23]
#define _g _p[24]
#define _ion_ek	*_ppvar[0]._pval
#define _ion_ik	*_ppvar[1]._pval
#define _ion_dikdv	*_ppvar[2]._pval
#define _ion_KV42Pi	*_ppvar[3]._pval
#define _ion_KV42i	*_ppvar[4]._pval
#define _ion_KTESTi	*_ppvar[5]._pval
#define _style_KTEST	*((int*)_ppvar[6]._pvoid)
#define _ion_KTESTPi	*_ppvar[7]._pval
#define _style_KTESTP	*((int*)_ppvar[8]._pvoid)
 
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
 static void _hoc_mtau(void);
 static void _hoc_ratio(void);
 static void _hoc_rates(void);
 static void _hoc_table_mtau(void);
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
 "setdata_kaf", _hoc_setdata,
 "mtau_kaf", _hoc_mtau,
 "ratio_kaf", _hoc_ratio,
 "rates_kaf", _hoc_rates,
 "table_mtau_kaf", _hoc_table_mtau,
 0, 0
};
#define mtau mtau_kaf
#define table_mtau table_mtau_kaf
 extern double mtau( _threadargsprotocomma_ double );
 extern double table_mtau( );
 /* declare global and static user variables */
#define KV42_total KV42_total_kaf
 double KV42_total = 0.000186;
#define htau_mutant htau_mutant_kaf
 double htau_mutant = 20;
#define hslope_mutant hslope_mutant_kaf
 double hslope_mutant = 3.9;
#define hvhalf_mutant hvhalf_mutant_kaf
 double hvhalf_mutant = 63;
#define htau htau_kaf
 double htau = 10;
#define hslope hslope_kaf
 double hslope = 3.4;
#define hvhalf hvhalf_kaf
 double hvhalf = 61;
#define mslope_mutant mslope_mutant_kaf
 double mslope_mutant = -18;
#define mvhalf_mutant mvhalf_mutant_kaf
 double mvhalf_mutant = 6;
#define mslope mslope_kaf
 double mslope = -18;
#define mvhalf mvhalf_kaf
 double mvhalf = -24;
#define power power_kaf
 double power = 2;
#define qfact qfact_kaf
 double qfact = 3;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "mvhalf_kaf", "mV",
 "mslope_kaf", "mV",
 "hvhalf_kaf", "mV",
 "hslope_kaf", "mV",
 "htau_kaf", "ms",
 "mvhalf_mutant_kaf", "mV",
 "mslope_mutant_kaf", "mV",
 "hvhalf_mutant_kaf", "mV",
 "hslope_mutant_kaf", "mV",
 "htau_mutant_kaf", "ms",
 "KV42_total_kaf", "mM",
 "gkbar_kaf", "S/cm2",
 "mshift_kaf", "mV",
 "hshift_kaf", "mV",
 "mshift_mutant_kaf", "mV",
 "hshift_mutant_kaf", "mV",
 "ik_kaf", "mA/cm2",
 0,0
};
 static double delta_t = 0.01;
 static double h0 = 0;
 static double m0 = 0;
 static double n0 = 0;
 static double q0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "mvhalf_kaf", &mvhalf_kaf,
 "mslope_kaf", &mslope_kaf,
 "hvhalf_kaf", &hvhalf_kaf,
 "hslope_kaf", &hslope_kaf,
 "htau_kaf", &htau_kaf,
 "mvhalf_mutant_kaf", &mvhalf_mutant_kaf,
 "mslope_mutant_kaf", &mslope_mutant_kaf,
 "hvhalf_mutant_kaf", &hvhalf_mutant_kaf,
 "hslope_mutant_kaf", &hslope_mutant_kaf,
 "htau_mutant_kaf", &htau_mutant_kaf,
 "qfact_kaf", &qfact_kaf,
 "power_kaf", &power_kaf,
 "KV42_total_kaf", &KV42_total_kaf,
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
 
#define _cvode_ieq _ppvar[9]._i
 static void _ode_synonym(int, double**, Datum**);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "6.2.0",
"kaf",
 "gkbar_kaf",
 "mshift_kaf",
 "hshift_kaf",
 "mshift_mutant_kaf",
 "hshift_mutant_kaf",
 0,
 "ik_kaf",
 0,
 "m_kaf",
 "h_kaf",
 "n_kaf",
 "q_kaf",
 0,
 0};
 static Symbol* _k_sym;
 static Symbol* _KV42P_sym;
 static Symbol* _KV42_sym;
 static Symbol* _KTEST_sym;
 static Symbol* _KTESTP_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 25, _prop);
 	/*initialize range parameters*/
 	gkbar = 0.019211;
 	mshift = 0;
 	hshift = 0;
 	mshift_mutant = 0;
 	hshift_mutant = 0;
 	_prop->param = _p;
 	_prop->param_size = 25;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 10, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_k_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0]._pval = &prop_ion->param[0]; /* ek */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ik */
 	_ppvar[2]._pval = &prop_ion->param[4]; /* _ion_dikdv */
 prop_ion = need_memb(_KV42P_sym);
 nrn_promote(prop_ion, 1, 0);
 	_ppvar[3]._pval = &prop_ion->param[1]; /* KV42Pi */
 prop_ion = need_memb(_KV42_sym);
 nrn_promote(prop_ion, 1, 0);
 	_ppvar[4]._pval = &prop_ion->param[1]; /* KV42i */
 prop_ion = need_memb(_KTEST_sym);
 nrn_check_conc_write(_prop, prop_ion, 1);
 nrn_promote(prop_ion, 3, 0);
 	_ppvar[5]._pval = &prop_ion->param[1]; /* KTESTi */
 	_ppvar[6]._pvoid = (void*)(&(prop_ion->dparam[0]._i)); /* iontype for KTEST */
 prop_ion = need_memb(_KTESTP_sym);
 nrn_check_conc_write(_prop, prop_ion, 1);
 nrn_promote(prop_ion, 3, 0);
 	_ppvar[7]._pval = &prop_ion->param[1]; /* KTESTPi */
 	_ppvar[8]._pvoid = (void*)(&(prop_ion->dparam[0]._i)); /* iontype for KTESTP */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*f)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _kv4_2_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("k", -10000.);
 	ion_reg("KV42P", -10000.);
 	ion_reg("KV42", -10000.);
 	ion_reg("KTEST", 1.0);
 	ion_reg("KTESTP", 1.0);
 	_k_sym = hoc_lookup("k_ion");
 	_KV42P_sym = hoc_lookup("KV42P_ion");
 	_KV42_sym = hoc_lookup("KV42_ion");
 	_KTEST_sym = hoc_lookup("KTEST_ion");
 	_KTESTP_sym = hoc_lookup("KTESTP_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
  hoc_register_dparam_size(_mechtype, 10);
 	nrn_writes_conc(_mechtype, 0);
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_synonym(_mechtype, _ode_synonym);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 kaf /Users/maoss2/Documents/Kv4.2_Model/Mod_Files/x86_64/kv4_2.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "Fast A-type Potassium current for CA1 (Kv4.2)";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int ratio(_threadargsproto_);
static int rates(_threadargsprotocomma_ double);
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[4], _dlist1[4];
 static int states(_threadargsproto_);
 
static void* _ptable_mtau = (void*)0;
 
extern double hoc_func_table();
 
double mtau ( _threadargsprotocomma_ double _lv ) {
 double _arg[1];
 _arg[0] = _lv;
 return hoc_func_table(_ptable_mtau, 1, _arg);
 }
/*  }
  */
 
static void _hoc_mtau(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  mtau ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 double table_mtau ( ) {
	hoc_spec_table(&_ptable_mtau, 1);
	return 0.;
}
 
static void _hoc_table_mtau(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  table_mtau (  );
 hoc_retpushx(_r);
}
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset = 0; {
   rates ( _threadargscomma_ v ) ;
   ratio ( _threadargs_ ) ;
   Dm = ( minf - m ) / ( mtau ( _threadargscomma_ v ) / qfact ) ;
   Dh = ( hinf - h ) / ( htau / qfact ) ;
   Dn = ( ninf - n ) / ( mtau ( _threadargscomma_ v ) / qfact ) ;
   Dq = ( qinf - q ) / ( htau_mutant / qfact ) ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 rates ( _threadargscomma_ v ) ;
 ratio ( _threadargs_ ) ;
 Dm = Dm  / (1. - dt*( ( ( ( - 1.0 ) ) ) / ( mtau ( _threadargscomma_ v ) / qfact ) )) ;
 Dh = Dh  / (1. - dt*( ( ( ( - 1.0 ) ) ) / ( htau / qfact ) )) ;
 Dn = Dn  / (1. - dt*( ( ( ( - 1.0 ) ) ) / ( mtau ( _threadargscomma_ v ) / qfact ) )) ;
 Dq = Dq  / (1. - dt*( ( ( ( - 1.0 ) ) ) / ( htau_mutant / qfact ) )) ;
 return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
   rates ( _threadargscomma_ v ) ;
   ratio ( _threadargs_ ) ;
    m = m + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / ( mtau ( _threadargscomma_ v ) / qfact ))))*(- ( ( ( minf ) ) / ( mtau ( _threadargscomma_ v ) / qfact ) ) / ( ( ( ( - 1.0) ) ) / ( mtau ( _threadargscomma_ v ) / qfact ) ) - m) ;
    h = h + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / ( htau / qfact ))))*(- ( ( ( hinf ) ) / ( htau / qfact ) ) / ( ( ( ( - 1.0) ) ) / ( htau / qfact ) ) - h) ;
    n = n + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / ( mtau ( _threadargscomma_ v ) / qfact ))))*(- ( ( ( ninf ) ) / ( mtau ( _threadargscomma_ v ) / qfact ) ) / ( ( ( ( - 1.0) ) ) / ( mtau ( _threadargscomma_ v ) / qfact ) ) - n) ;
    q = q + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / ( htau_mutant / qfact ))))*(- ( ( ( qinf ) ) / ( htau_mutant / qfact ) ) / ( ( ( ( - 1.0) ) ) / ( htau_mutant / qfact ) ) - q) ;
   }
  return 0;
}
 
static int  rates ( _threadargsprotocomma_ double _lv ) {
   minf = 1.0 / ( 1.0 + exp ( ( _lv - mvhalf - mshift ) / mslope ) ) ;
   hinf = 1.0 / ( 1.0 + exp ( ( _lv - hvhalf - hshift ) / hslope ) ) ;
   ninf = 1.0 / ( 1.0 + exp ( ( _lv - mvhalf_mutant - mshift_mutant ) / mslope_mutant ) ) ;
   qinf = 1.0 / ( 1.0 + exp ( ( _lv - hvhalf_mutant - hshift_mutant ) / hslope_mutant ) ) ;
    return 0; }
 
static void _hoc_rates(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r = 1.;
 rates ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
static int  ratio ( _threadargsproto_ ) {
   KTESTi = KV42i / KV42_total ;
   KTESTPi = KV42Pi / KV42_total ;
    return 0; }
 
static void _hoc_ratio(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r = 1.;
 ratio ( _p, _ppvar, _thread, _nt );
 hoc_retpushx(_r);
}
 
static int _ode_count(int _type){ return 4;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ek = _ion_ek;
  KV42Pi = _ion_KV42Pi;
  KV42i = _ion_KV42i;
  KTESTi = _ion_KTESTi;
  KTESTPi = _ion_KTESTPi;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
   _ion_KTESTi = KTESTi;
  _ion_KTESTPi = KTESTPi;
 }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 4; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 static void _ode_synonym(int _cnt, double** _pp, Datum** _ppd) { 
	double* _p; Datum* _ppvar;
 	int _i; 
	for (_i=0; _i < _cnt; ++_i) {_p = _pp[_i]; _ppvar = _ppd[_i];
 _ion_KTESTi =  KV42i / KV42_total ;
 _ion_KTESTPi =  KV42Pi / KV42_total ;
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
  ek = _ion_ek;
  KV42Pi = _ion_KV42Pi;
  KV42i = _ion_KV42i;
  KTESTi = _ion_KTESTi;
  KTESTPi = _ion_KTESTPi;
 _ode_matsol1 (_p, _ppvar, _thread, _nt);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_k_sym, _ppvar, 0, 0);
   nrn_update_ion_pointer(_k_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_k_sym, _ppvar, 2, 4);
   nrn_update_ion_pointer(_KV42P_sym, _ppvar, 3, 1);
   nrn_update_ion_pointer(_KV42_sym, _ppvar, 4, 1);
   nrn_update_ion_pointer(_KTEST_sym, _ppvar, 5, 1);
   nrn_update_ion_pointer(_KTESTP_sym, _ppvar, 7, 1);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  h = h0;
  m = m0;
  n = n0;
  q = q0;
 {
   rates ( _threadargscomma_ v ) ;
   m = minf ;
   h = hinf ;
   n = ninf ;
   q = qinf ;
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
  ek = _ion_ek;
  KV42Pi = _ion_KV42Pi;
  KV42i = _ion_KV42i;
  KTESTi = _ion_KTESTi;
  KTESTPi = _ion_KTESTPi;
 initmodel(_p, _ppvar, _thread, _nt);
   _ion_KTESTi = KTESTi;
  nrn_wrote_conc(_KTEST_sym, (&(_ion_KTESTi)) - 1, _style_KTEST);
  _ion_KTESTPi = KTESTPi;
  nrn_wrote_conc(_KTESTP_sym, (&(_ion_KTESTPi)) - 1, _style_KTESTP);
}}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   ik = KTESTi * gkbar * pow( m , power ) * h * ( v - ek ) + KTESTPi * gkbar * pow( n , power ) * q * ( v - ek ) ;
   }
 _current += ik;

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
  ek = _ion_ek;
  KV42Pi = _ion_KV42Pi;
  KV42i = _ion_KV42i;
  KTESTi = _ion_KTESTi;
  KTESTPi = _ion_KTESTPi;
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ double _dik;
  _dik = ik;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_dikdv += (_dik - ik)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ik += ik ;
  _ion_KTESTi = KTESTi;
  _ion_KTESTPi = KTESTPi;
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
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
  ek = _ion_ek;
  KV42Pi = _ion_KV42Pi;
  KV42i = _ion_KV42i;
  KTESTi = _ion_KTESTi;
  KTESTPi = _ion_KTESTPi;
 { {
 for (; t < _break; t += dt) {
   states(_p, _ppvar, _thread, _nt);
  
}}
 t = _save;
 }   _ion_KTESTi = KTESTi;
  _ion_KTESTPi = KTESTPi;
}}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(m) - _p;  _dlist1[0] = &(Dm) - _p;
 _slist1[1] = &(h) - _p;  _dlist1[1] = &(Dh) - _p;
 _slist1[2] = &(n) - _p;  _dlist1[2] = &(Dn) - _p;
 _slist1[3] = &(q) - _p;  _dlist1[3] = &(Dq) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
