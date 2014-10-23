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
#define ca _p[2]
#define cagef _p[3]
#define gef _p[4]
#define ica _p[5]
#define cai _p[6]
#define Dca _p[7]
#define Dcagef _p[8]
#define Dgef _p[9]
#define v _p[10]
#define _g _p[11]
#define _ion_cai	*_ppvar[0]._pval
#define _ion_ica	*_ppvar[1]._pval
#define _style_ca	*((int*)_ppvar[2]._pvoid)
#define _ion_dicadv	*_ppvar[3]._pval
#define diam	*_ppvar[4]._pval
 
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
#define DCaGef DCaGef_cadifus
 double DCaGef = 0.9;
#define DGef DGef_cadifus
 double DGef = 0.1;
#define DCa DCa_cadifus
 double DCa = 0.6;
#define caiBase caiBase_cadifus
 double caiBase = 5e-05;
#define ceiling ceiling_cadifus
 double ceiling = 2;
#define kb kb_cadifus
 double kb = 0.1;
#define kf kf_cadifus
 double kf = 1;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "kf_cadifus", "/mM-ms",
 "kb_cadifus", "/ms",
 "ceiling_cadifus", "mM",
 "caiBase_cadifus", "mM",
 "DCa_cadifus", "um2/ms",
 "DGef_cadifus", "um2/ms",
 "DCaGef_cadifus", "um2/ms",
 "phi_cadifus", "/ms",
 "ca_cadifus", "mM",
 "cagef_cadifus", "mM",
 "gef_cadifus", "mM",
 0,0
};
 static double cagef0 = 0;
 static double ca0 = 0;
 static double delta_t = 0.01;
 static double gef0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "kf_cadifus", &kf_cadifus,
 "kb_cadifus", &kb_cadifus,
 "ceiling_cadifus", &ceiling_cadifus,
 "caiBase_cadifus", &caiBase_cadifus,
 "DCa_cadifus", &DCa_cadifus,
 "DGef_cadifus", &DGef_cadifus,
 "DCaGef_cadifus", &DCaGef_cadifus,
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
 
#define _cvode_ieq _ppvar[5]._i
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
 "cagef_cadifus",
 "gef_cadifus",
 0,
 0};
 static Symbol* _morphology_sym;
 static Symbol* _ca_sym;
 static int _type_ica;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 12, _prop);
 	/*initialize range parameters*/
 	phi = 0.25;
 	beta = 17.402;
 	_prop->param = _p;
 	_prop->param_size = 12;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 6, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_morphology_sym);
 	_ppvar[4]._pval = &prop_ion->param[0]; /* diam */
 prop_ion = need_memb(_ca_sym);
  _type_ica = prop_ion->_type;
 nrn_check_conc_write(_prop, prop_ion, 1);
 nrn_promote(prop_ion, 3, 0);
 	_ppvar[0]._pval = &prop_ion->param[1]; /* cai */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ica */
 	_ppvar[2]._pvoid = (void*)(&(prop_ion->dparam[0]._i)); /* iontype for ca */
 	_ppvar[3]._pval = &prop_ion->param[4]; /* _ion_dicadv */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 "ca_cadifus", 1e-10,
 "cagef_cadifus", 1e-10,
 "gef_cadifus", 1e-10,
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
  hoc_register_dparam_size(_mechtype, 6);
 	nrn_writes_conc(_mechtype, 0);
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_synonym(_mechtype, _ode_synonym);
 	hoc_register_ldifus1(_difusfunc);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 cadifus /Users/maoss2/NEURON/CA1_cell_test/Stimulation_case_per_case/CA1_Electrophysiologic_Models/CA1_Electrophysiologic_Models/Mod_Files/x86_64/cadifus.mod\n");
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
 static int _slist1[3], _dlist1[3]; static double *_temp1;
 static int state();
 
static int state (void* _so, double* _rhs, double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt)
 {int _reset=0;
 {
   double b_flux, f_flux, _term; int _i;
 {int _i; double _dt1 = 1.0/dt;
for(_i=0;_i<3;_i++){
  	_RHS1(_i) = -_dt1*(_p[_slist1[_i]] - _p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
}  
_RHS1(0) *= ( PI * diam * diam / 4.0) ;
_MATELM1(0, 0) *= ( PI * diam * diam / 4.0); 
_RHS1(1) *= ( PI * diam * diam / 4.0) ;
_MATELM1(1, 1) *= ( PI * diam * diam / 4.0); 
_RHS1(2) *= ( PI * diam * diam / 4.0) ;
_MATELM1(2, 2) *= ( PI * diam * diam / 4.0);  }
 /* COMPARTMENT PI * diam * diam / 4.0 {
     ca cagef gef }
   */
 /* LONGITUDINAL_DIFFUSION DCa * diam * diam {
     ca }
   */
 /* LONGITUDINAL_DIFFUSION DCaGef * diam * diam {
     cagef }
   */
 /* LONGITUDINAL_DIFFUSION DGef * diam * diam {
     gef }
   */
 /* ~ ca < < ( ( - beta * ica ) - ( phi * ( cai - caiBase ) ) )*/
 f_flux = b_flux = 0.;
 _RHS1( 1) += (b_flux =   ( ( - beta * ica ) - ( phi * ( cai - caiBase ) ) ) );
 /*FLUX*/
  /* ~ ca + gef <-> cagef ( kf , kb )*/
 f_flux =  kf * gef * ca ;
 b_flux =  kb * cagef ;
 _RHS1( 2) -= (f_flux - b_flux);
 _RHS1( 1) -= (f_flux - b_flux);
 _RHS1( 0) += (f_flux - b_flux);
 
 _term =  kf * ca ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 1 ,2)  += _term;
 _MATELM1( 0 ,2)  -= _term;
 _term =  kf * gef ;
 _MATELM1( 2 ,1)  += _term;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 0 ,1)  -= _term;
 _term =  kb ;
 _MATELM1( 2 ,0)  -= _term;
 _MATELM1( 1 ,0)  -= _term;
 _MATELM1( 0 ,0)  += _term;
 /*REACTION*/
  cai = ca ;
     } return _reset;
 }
 
/*CVODE ode begin*/
 static int _ode_spec1(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset=0;{
 double b_flux, f_flux, _term; int _i;
 {int _i; for(_i=0;_i<3;_i++) _p[_dlist1[_i]] = 0.0;}
 /* COMPARTMENT PI * diam * diam / 4.0 {
   ca cagef gef }
 */
 /* LONGITUDINAL_DIFFUSION DCa * diam * diam {
   ca }
 */
 /* LONGITUDINAL_DIFFUSION DCaGef * diam * diam {
   cagef }
 */
 /* LONGITUDINAL_DIFFUSION DGef * diam * diam {
   gef }
 */
 /* ~ ca < < ( ( - beta * ica ) - ( phi * ( cai - caiBase ) ) )*/
 f_flux = b_flux = 0.;
 Dca += (b_flux =   ( ( - beta * ica ) - ( phi * ( cai - caiBase ) ) ) );
 /*FLUX*/
  /* ~ ca + gef <-> cagef ( kf , kb )*/
 f_flux =  kf * gef * ca ;
 b_flux =  kb * cagef ;
 Dgef -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 Dcagef += (f_flux - b_flux);
 
 /*REACTION*/
  cai = ca ;
 _p[_dlist1[0]] /= ( PI * diam * diam / 4.0);
 _p[_dlist1[1]] /= ( PI * diam * diam / 4.0);
 _p[_dlist1[2]] /= ( PI * diam * diam / 4.0);
   } return _reset;
 }
 
/*CVODE matsol*/
 static int _ode_matsol1(void* _so, double* _rhs, double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset=0;{
 double b_flux, f_flux, _term; int _i;
   b_flux = f_flux = 0.;
 {int _i; double _dt1 = 1.0/dt;
for(_i=0;_i<3;_i++){
  	_RHS1(_i) = _dt1*(_p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
}  
_RHS1(0) *= ( PI * diam * diam / 4.0) ;
_MATELM1(0, 0) *= ( PI * diam * diam / 4.0); 
_RHS1(1) *= ( PI * diam * diam / 4.0) ;
_MATELM1(1, 1) *= ( PI * diam * diam / 4.0); 
_RHS1(2) *= ( PI * diam * diam / 4.0) ;
_MATELM1(2, 2) *= ( PI * diam * diam / 4.0);  }
 /* COMPARTMENT PI * diam * diam / 4.0 {
 ca cagef gef }
 */
 /* LONGITUDINAL_DIFFUSION DCa * diam * diam {
 ca }
 */
 /* LONGITUDINAL_DIFFUSION DCaGef * diam * diam {
 cagef }
 */
 /* LONGITUDINAL_DIFFUSION DGef * diam * diam {
 gef }
 */
 /* ~ ca < < ( ( - beta * ica ) - ( phi * ( cai - caiBase ) ) )*/
 /*FLUX*/
  /* ~ ca + gef <-> cagef ( kf , kb )*/
 _term =  kf * ca ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 1 ,2)  += _term;
 _MATELM1( 0 ,2)  -= _term;
 _term =  kf * gef ;
 _MATELM1( 2 ,1)  += _term;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 0 ,1)  -= _term;
 _term =  kb ;
 _MATELM1( 2 ,0)  -= _term;
 _MATELM1( 1 ,0)  -= _term;
 _MATELM1( 0 ,0)  += _term;
 /*REACTION*/
  cai = ca ;
   } return _reset;
 }
 
/*CVODE end*/
 
static int _ode_count(int _type){ return 3;}
 
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
	for (_i=0; _i < 3; ++_i) {
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
 _cvode_sparse_thread(&_thread[_cvspth1]._pvoid, 3, _dlist1, _p, _ode_matsol1, _ppvar, _thread, _nt);
 }}
 
static void _thread_cleanup(Datum* _thread) {
   _nrn_destroy_sparseobj_thread(_thread[_cvspth1]._pvoid);
   _nrn_destroy_sparseobj_thread(_thread[_spth1]._pvoid);
 }
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_ca_sym, _ppvar, 0, 1);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 3, 4);
 }
 static void* _difspace1;
extern double nrn_nernst_coef();
static double _difcoef1(int _i, double* _p, Datum* _ppvar, double* _pdvol, double* _pdfcdc, Datum* _thread, _NrnThread* _nt) {
   *_pdvol =  PI * diam * diam / 4.0 ;
 if (_i == 0) {
  *_pdfcdc = nrn_nernst_coef(_type_ica)*( ( ( - beta * _ion_dicadv  ) - ( phi * ( cai - caiBase ) ) ));
 }else{ *_pdfcdc=0.;}
   return DCa * diam * diam ;
}
 static void* _difspace2;
extern double nrn_nernst_coef();
static double _difcoef2(int _i, double* _p, Datum* _ppvar, double* _pdvol, double* _pdfcdc, Datum* _thread, _NrnThread* _nt) {
   *_pdvol =  PI * diam * diam / 4.0 ; *_pdfcdc=0.;
   return DCaGef * diam * diam ;
}
 static void* _difspace3;
extern double nrn_nernst_coef();
static double _difcoef3(int _i, double* _p, Datum* _ppvar, double* _pdvol, double* _pdfcdc, Datum* _thread, _NrnThread* _nt) {
   *_pdvol =  PI * diam * diam / 4.0 ; *_pdfcdc=0.;
   return DGef * diam * diam ;
}
 static void _difusfunc(ldifusfunc2_t _f, _NrnThread* _nt) {int _i;
  (*_f)(_mechtype, _difcoef1, &_difspace1, 0,  2, 7 , _nt);
  (*_f)(_mechtype, _difcoef2, &_difspace2, 0,  3, 8 , _nt);
  (*_f)(_mechtype, _difcoef3, &_difspace3, 0,  4, 9 , _nt);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  cagef = cagef0;
  ca = ca0;
  gef = gef0;
 {
   ca = caiBase ;
   gef = 0.005 ;
   cagef = 0.0 ;
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
  sparse_thread(&_thread[_spth1]._pvoid, 3, _slist1, _dlist1, _p, &t, dt, state, _linmat1, _ppvar, _thread, _nt);
  
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
 _slist1[0] = &(cagef) - _p;  _dlist1[0] = &(Dcagef) - _p;
 _slist1[1] = &(ca) - _p;  _dlist1[1] = &(Dca) - _p;
 _slist1[2] = &(gef) - _p;  _dlist1[2] = &(Dgef) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
