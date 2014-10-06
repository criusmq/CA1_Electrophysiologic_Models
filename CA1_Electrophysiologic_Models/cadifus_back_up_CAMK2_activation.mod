: CalcimM ion accmMulation with radial and longitudinal diffusion
: J'ai pas besoin de la diffusion radiale donc nannuli inutile et compartment aussi
NEURON {
	SUFFIX cadifus_backup
	USEION ca READ cai, ica WRITE cai
	RANGE  phi, beta
}

UNITS {
	(molar) = (1/liter)
	(mM) = (millimolar)
	(um) = (micron)
	(mA) = (milliamp)
	FARADAY = (faraday) (10000 coulomb)
	PI = (pi) (1)
}

PARAMETER {
	:kf_pkc = 0.6 (/mM-ms) :0.6 mM-1.s-1
	:kb_pkc = 500 (/ms) :0.5 s-1
	
	kf_cam = 0.72 (/mM^2-ms) :72 * 1000000 m6.mol-2.s-1 (third rate constant but what that means??)
	kb_cam = 72000 (/ms) :72 s-1 
	
	kf_cam2 = 3.6 (/mM-ms) :3.6 mM-1.s-1
	kb_cam2 = 10000 (/ms) :10 s-1 
	
	kf_cam3 = 0.465 (/mM-ms) :30.465 mM-1.s-1
	kb_cam3 = 10000 (/ms) :10 s-1
	
	kf_camK2 = 50 (/mM-ms) :3.6 mM-1.s-1
	kb_camK2 = 5000 (/ms) :5 s-1  
	
	phi 	= 0.25 (/ms) :(1/4)
	:phi	= 4 (ms)
	beta = 17.402 
	ceiling	= 2	(mM)
	caiBase = 50e-6 (mM) : the assmMed resting level of intracellular calcimM
}

ASSIGNED {
	diam (mM)
	ica (mA/cm2)
	cai (mM)
}

STATE {
	ca (mM) <1e-10>
	:CaGef (mM)	
  	:Gef   (mM)
  	PKC_cyt (mM)
  	PKC_Ca (mM)
  	CaM_spine (mM)
  	CaM_Ca2_spine (mM)
  	CaM_Ca3_spine (mM)
  	CaM_Ca4_spine (mM)
  	CaMK2_spine (mM)
  	CaM_CaMK2_spine (mM)
}

BREAKPOINT { SOLVE state METHOD sparse }

INITIAL {
	ca = caiBase
	:Gef = 0.5
	:CaGef = 0
	:PKC_cyt = 0.000005 :valeurs initiales manquantes dans Vcell
	:PKC_Ca = 0
	
	CaM_spine = 0.02 :valeurs initiales manquantes dans Vcell
	CaM_Ca2_spine = 0
	
	CaM_Ca3_spine = 0
	
	CaM_Ca4_spine = 0
	
	CaMK2_spine =  0.02 :valeurs initiales manquantes dans Vcell
	CaM_CaMK2_spine = 0
}

KINETIC state {
	
	:COMPARTMENT PI*diam*diam/4 {ca}
	
	:LONGITUDINAL_DIFFUSION 0.6*diam*diam {ca}
	
	:Discussion about the constant units and DCa
	~ ca << ( (- beta * ica) - (phi * (cai - caiBase)) )
	:~ ca + Gef <-> CaGef  (kf, kb)
	:~ ca + PKC_cyt <-> PKC_Ca (kf_pkc, kb_pkc)
	~ 2ca + CaM_spine <-> CaM_Ca2_spine (kf_cam, kb_cam)
	~ ca + CaM_Ca2_spine <-> CaM_Ca3_spine (kf_cam2, kb_cam2)
	~ ca + CaM_Ca3_spine <-> CaM_Ca4_spine (kf_cam3, kb_cam3)
	~ CaM_Ca4_spine + CaMK2_spine <-> CaM_CaMK2_spine (kf_camK2, kb_camK2)
	cai = ca
}
