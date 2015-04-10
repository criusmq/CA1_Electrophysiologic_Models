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
   USEION Raf READ Rafi WRITE Rafi VALENCE 1
   USEION RafP READ RafPi WRITE RafPi VALENCE 1
   RANGE  phi, beta, kf_rasGDP
   :RANGE tempRaf, tempRafP 
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
	DRas = 0.65e-3 (um2/ms) :old values 0.65e-3 25% of reduction 1st, then 50% then 75%
	DRaf = 6e-3 (um2/ms) :old values 6e-3
	DKinases = 1e-3 (um2/ms) :old values 1e-3
   	phi 	= 0.25(/ms) :(1/4) phi	= 13.33 (ms)
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
	kcat_raf = 0.07624e-3 (/ms)
	km_raf = 0.072e-3 (mM)
	kcat_rafP = 1e-3 (/ms)
	km_rafP = 0.0167e-3 (mM)
	kcat_mek = 0.105e-3 (/ms)
	km_mek = 0.159091e-3 (mM) :the same for the phosphorylation of MekP to MekPP
	kcat_mekP = 6e-3 (/ms)
	km_mekP = 15.6566e-3 (mM) :the same for the dephosphorylation of MekPP to MekP
	kcat_mapk = 0.15e-3 (/ms)
	km_mapk = 0.0462963e-3 (mM) :the same for the phosphorylation of MapkP to MapkPP
	kcat_mapkP = 1e-3 (/ms) 
	km_mapkP = 0.0666667e-3 (mM) :the same for the dephosphorylation of MapkPP to MapkP
	:k_MM = 0 : for the backward for every Michaelis-Menten equation
	:tempRaf = 0
	:tempRafP = 0
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
  Rafi (mM)
  RafPi (mM)
  RafPhosphatase (mM)
  Mek (mM)
  MekP (mM)
  MekPP (mM)
  MekPhosphatase (mM)
  Mapk (mM)
  MapkP (mM)
  MapkPP (mM)
  MapkPhosphatase (mM)
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
	Rafi = 0.2e-3
  	RafPi = 0
  	RafPhosphatase = 0.00375e-3 :new value from VCell simulation 0.0025 or 0.005 can work too
  								:but the middle is better
  	Mek = 0.18e-3
  	MekP = 0 
 	MekPP = 0 
  	MekPhosphatase = 0.112e-3
  	Mapk = 0.36e-3
  	MapkP = 0
  	MapkPP = 0
  	MapkPhosphatase = 0.001e-3
	}

:Definitions of the temporary variables for the Michaelis-Mentens rates calculation
LOCAL tempRaf, tempRafP , tempMek, tempMekP, tempMekPP1, tempMekPP2, tempMapk, tempMapkP, tempMapkPP1, tempMapkPP2
	
KINETIC state {
   	COMPARTMENT PI*diam {RasGDPi RasGTPi}
   	COMPARTMENT PI*diam*diam/4 {Rafi RafPi Mek MekP MekPP Mapk MapkP MapkPP}
	LONGITUDINAL_DIFFUSION DRas*diam {RasGDPi} :diffusion surfacique
	LONGITUDINAL_DIFFUSION DRas*diam {RasGTPi}
	LONGITUDINAL_DIFFUSION DRaf*PI*diam*diam/4 {Rafi} :diffusion volumique
	LONGITUDINAL_DIFFUSION DRaf*PI*diam*diam/4 {RafPi}
	LONGITUDINAL_DIFFUSION DKinases*PI*diam*diam/4 {Mek} :diffusion volumique
	LONGITUDINAL_DIFFUSION DKinases*PI*diam*diam/4 {MekP}
	LONGITUDINAL_DIFFUSION DKinases*PI*diam*diam/4 {MekPP}
	LONGITUDINAL_DIFFUSION DKinases*PI*diam*diam/4 {Mapk} :diffusion volumique
	LONGITUDINAL_DIFFUSION DKinases*PI*diam*diam/4 {MapkP}
	LONGITUDINAL_DIFFUSION DKinases*PI*diam*diam/4 {MapkPP}
   ~ ca << ( (- beta * ica)- (phi * (cai - caiBase)) ) 
    cai = ca 
    ca_modif = ca - 0.00045
  ~ ca_modif + Cam <-> Cam_Ca (kf_cam1, kr_cam1)
  ~ ca_modif + Cam_Ca <-> Cam_Ca2 (kf_cam2, kr_cam2)
  ~ ca_modif + Cam_Ca2 <-> Cam_Ca3 (kf_cam3, kr_cam3)
  ~ ca_modif + Cam_Ca3 <-> Cam_Ca4 (kf_cam4, kr_cam4)
  ~ Cam_Ca4 + Gef <-> Gef_activated (kf_gef, kr_gef)
  ~ RasGDPi <-> RasGTPi (kf_rasGDP*Gef_activated, kr_rasGDP)
  
  tempRaf = (kcat_raf * RasGTPi)/(Rafi + km_raf)
  tempRafP = (kcat_rafP * RafPhosphatase)/(RafPi + km_rafP)
  ~ Rafi <-> RafPi (tempRaf, tempRafP)
  
  tempMek = (kcat_mek * RafPi)/(Mek + km_mek)
  tempMekP = (kcat_mek * MekPhosphatase)/(MekP + km_mek)
  ~ Mek <-> MekP (tempMek, tempMekP)
  
  tempMekPP1 = (kcat_mek * RafPi)/(MekP + km_mek)
  tempMekPP2 = (kcat_mek * MekPhosphatase)/(MekPP + km_mek)
  ~ MekP <-> MekPP (tempMekPP1, tempMekPP2)
  
  tempMapk = (kcat_mapk * MekPP)/(Mapk + km_mapk)
  tempMapkP = (kcat_mapk * MapkPhosphatase)/(MapkP + km_mapk)
  ~ Mapk <-> MapkP (tempMapk, tempMapkP)
  
  tempMapkPP1 = (kcat_mapk * MekPP)/(MapkP + km_mapk)
  tempMapkPP2 = (kcat_mapk * MapkPhosphatase)/(MapkPP + km_mapk)
  ~ MapkP <-> MapkPP (tempMapkPP1, tempMapkPP2)

}
