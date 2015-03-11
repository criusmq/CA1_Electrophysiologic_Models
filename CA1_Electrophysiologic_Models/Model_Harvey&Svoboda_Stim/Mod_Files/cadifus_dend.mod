: Calcium ion accumulation with radial and longitudinal diffusion
NEURON {
   SUFFIX cadifus_dend
   USEION ca READ cai, ica WRITE cai
   RANGE  phi, beta
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
   phi 	= 0.075(/ms) :(1/4)
	:phi	= 13.33 (ms)
	beta = 17.402 
	ceiling	= 2	(mM)
	caiBase = 50e-6 (mM)
}

ASSIGNED {
	diam (um)
	ica (mA/cm2)
	cai (mM)
	 
}

STATE {
   ca       (mM) <1e-10>
}

BREAKPOINT { SOLVE state METHOD sparse }


INITIAL {
	ca = caiBase
	}
	
KINETIC state {
   ~ ca << ( (- beta * ica) - (phi * (cai - caiBase)) )
    cai = ca 
}
