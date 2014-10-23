: CalcimM ion accmMulation with radial and longitudinal diffusion
: J'ai pas besoin de la diffusion radiale donc nannuli inutile et compartment aussi
NEURON {
	SUFFIX cadifus_dend
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
	kf = 1 (/mM-ms) :1 mM-1.s-1
	kb = 0.1 (/ms) :0.1 s-1
	DCa  = 0.6 (um2/ms)
	DGef = 0.1 (um2/ms)
	DCaGef = 0.9 (um2/ms) 
	:valeurs prises expres pour que la diffusion du calcium soit la plus grande
	phi 	= 0.075(/ms) :(1/4)
	:phi	= 13.33 (ms)
	beta = 17.402 
	ceiling	= 2	(mM)
	caiBase = 50e-6 (mM) : the assmMed resting level of intracellular calcimM
}

ASSIGNED {
	diam (um)
	ica (mA/cm2)
	cai (mM)
}

STATE {
	ca (mM) <1e-10>
	cagef (mM)	<1e-10>
  	gef   (mM) 	<1e-10>
}

BREAKPOINT { SOLVE state METHOD sparse }

INITIAL {
	ca = caiBase
	gef = 0.005
	cagef = 0
}

UNITSOFF
KINETIC state {
	
	COMPARTMENT PI*diam*diam/4 {ca cagef gef}
	LONGITUDINAL_DIFFUSION DCa*diam*diam {ca}
	LONGITUDINAL_DIFFUSION DCaGef*diam*diam {cagef}
	LONGITUDINAL_DIFFUSION DGef*diam*diam {gef}	
	
	~ ca << ( (- beta * ica) - (phi * (cai - caiBase)) )
	
	~ ca + gef <-> cagef  (kf, kb)
	cai = ca
}
UNITSON