: CalcimM ion accmMulation with radial and longitudinal diffusion
: J'ai pas besoin de la diffusion radiale donc nannuli inutile et compartment aussi
NEURON {
	SUFFIX cadifus
	USEION ca READ cai, ica WRITE cai
	RANGE  phi, beta
	GLOBAL TotalBuffer : however TotalBuffer may be RANGE

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
	DCa = 0.6 (um2/ms)
	k1buf = 100 (/mM-ms) : Yamada et al. 1998
	k2buf = 0.1 (/ms)
	TotalBuffer = 0.003 (mM)
	:phi 	= 0.08(/ms) :(1/12)
	phi 	= 0.0025 :(1/400)
	:phi	= 12 (ms)
	beta = 17.402 
	ceiling	= 2	(mM)
	caiBase = 50e-6 (mM) : the assmMed resting level of intracellular calcimM
}

ASSIGNED {
	diam (um)
	ica (mA/cm2)
	cai (mM)
	Kd (/mM)
	B0 (mM)
}

STATE {
	ca (mM) <1e-10>
	CaBuffer (mM)	<1e-10>
  	Buffer   (mM) 	<1e-10>
}

BREAKPOINT { SOLVE state METHOD sparse }

INITIAL {
	
	Kd = k1buf/k2buf
	B0 = TotalBuffer/(1 + Kd*cai)
	
	ca = caiBase
	Buffer = B0
	CaBuffer = TotalBuffer - B0
}

UNITSOFF
KINETIC state {
	
	COMPARTMENT PI*diam*diam/4 {ca CaBuffer Buffer}
	:LONGITUDINAL_DIFFUSION DCa*diam*diam {ca}
	
	~ ca << ( (- beta * ica) - (phi * (cai - caiBase)) )
	
	:~ ca + Buffer <-> CaBuffer  (k1buf, k2buf)
	cai = ca
}
UNITSON