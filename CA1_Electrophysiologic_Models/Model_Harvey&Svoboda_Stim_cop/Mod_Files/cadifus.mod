: Calcium ion accumulation with longitudinal diffusion
: diffusion of RasGTP and RasGDP
: default parameter values are for spine
: dendritic values are indicated in comments
: USEION foo READ fooi WRITE fooi VALENCE 1
NEURON {
   SUFFIX cadifus
   USEION ca READ cai, ica WRITE cai
   USEION RasGTP READ RasGTPi WRITE RasGTPi VALENCE 1
   USEION RasGDP READ RasGDPi WRITE RasGDPi VALENCE 1
   RANGE  phi, beta, kf_rasGDP
}

UNITS {
   (molar) = (1/liter)
   (mM)    = (millimolar)
   (um)    = (micron)
   (mA)    = (milliamp)
   FARADAY = (faraday)  (10000 coulomb)
   PI      = (pi)       (1)
}

PARAMETER {
	DRas = 0.65 (um2/ms)
	:DRas = 1000 (um2/ms)
   phi 	= 0.25(/ms) :(1/4)
	:phi	= 13.33 (ms)
	beta = 17.402  
	ceiling	= 2	(mM)
	caiBase = 50e-6 (mM)
	kf_cam1 = 1 (/mM-ms)
	kr_cam1 =  8.4853e-3 (/ms)
	kf_cam2 =  8.4846 (/mM-ms)
	kr_cam2 =  8.4853e-3 (/ms)
	kf_cam3 =  3.6001 (/mM-ms)
	kr_cam3 =  10e-3 (/ms)
	kf_cam4 =  0.465 (/mM-ms)
	kr_cam4 =  10e-3 (/ms)
	kf_gef =  2.75 (/mM-ms)
	kr_gef =  0.008333333e-3(/ms)
	kf_rasGDP = 0.1 (/mM-ms) : for spine, 0 for dendrite
	kr_rasGDP = 0.003703703703703704e-3 (/ms)
}

ASSIGNED {
	diam (um)
	L (um)
	ica (mA/cm2)
	cai (mM)
}

STATE {
   ca       (mM) <1e-10>
   ca_modif (mM)
  Cam (mM)
  Cam_Ca (mM) 
  Cam_Ca2 (mM)
  Cam_Ca3 (mM)
  Cam_Ca4 (mM)
  Gef  (mM)
  Gef_activated  (mM)
  RasGDPi (mM)
  RasGTPi (mM)
}

BREAKPOINT { SOLVE state METHOD sparse }


INITIAL {
	ca = caiBase
	ca_modif = 0
	Cam = 0.02
	Cam_Ca = 0
	Cam_Ca2 = 0
	Cam_Ca3 = 0
	Cam_Ca4 = 0
	Gef = 0.0006
	Gef_activated = 0
	RasGDPi = 0.0012
	RasGTPi = 0
	}
	
KINETIC state {
   	COMPARTMENT PI*(diam/2)^2 {RasGDPi RasGTPi}
	LONGITUDINAL_DIFFUSION DRas*PI*(diam/2)^2 {RasGDPi}
	LONGITUDINAL_DIFFUSION DRas*PI*(diam/2)^2 {RasGTPi}
   ~ ca << ( (- beta * ica)- (phi * (cai - caiBase)) ) 
    cai = ca 
    ca_modif = ca - 0.00045
  ~ ca_modif + Cam <-> Cam_Ca (kf_cam1, kr_cam1)
  ~ ca_modif + Cam_Ca <-> Cam_Ca2 (kf_cam2, kr_cam2)
  ~ ca_modif + Cam_Ca2 <-> Cam_Ca3 (kf_cam3, kr_cam3)
  ~ ca_modif + Cam_Ca3 <-> Cam_Ca4 (kf_cam4, kr_cam4)
  ~ Cam_Ca4 + Gef <-> Gef_activated (kf_gef, kr_gef)
  ~ RasGDPi <-> RasGTPi (kf_rasGDP*Gef_activated, kr_rasGDP)
  
  :~ RasGTP <-> RasGDP (kf_rasGTP, kr_rasGTP)
  

}
