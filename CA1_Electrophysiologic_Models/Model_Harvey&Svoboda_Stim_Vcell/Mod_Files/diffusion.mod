: Calcium ion accumulation with radial and longitudinal diffusion
: J'ai pas besoin de la diffusion radiale donc nannuli inutile et compartment aussi
NEURON {
	SUFFIX diffusion
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
	kf = 1 (/mM-ms)
	kb = 0.1 (/ms)
	phi 	= 0.25 (/ms) :(1/13.33) :beta_traub
							:phi	= 13.33 (ms)
	beta = 17.402 (cm2/mA-ms-m3) :phi_traub
	ceiling	= 2	(mM)
	caiBase = 50e-6 (mM) : the assumed resting level of intracellular calcium
	DCa  = 0.6 (um2/ms)
	DGef = 0.5 (um2/ms)
	DCaGef = 0.4 (um2/ms) 
}

ASSIGNED {
	diam (um)
	ica (mA/cm2)
	cai (mM)
}

STATE {
	ca (mM) <1e-10>
	CaGef (mM)	
  	Gef   (mM)
}

BREAKPOINT { SOLVE state METHOD sparse }

INITIAL {
	ca = caiBase
	Gef = 0.005
	CaGef = 0
}


KINETIC state {

	~ ca + Gef <-> CaGef  (kf, kb)
	cai = ca
}
