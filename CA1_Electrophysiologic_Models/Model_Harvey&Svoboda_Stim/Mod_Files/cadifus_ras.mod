: Calcium ion accumulation with radial and longitudinal diffusion
NEURON {
   SUFFIX cadifus_ras
   GLOBAL Gef_act
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
	kf_rasGDP = 0.1 (/mM-ms)
	kr_rasGDP = 0.003703703703703704e-3 (/ms)
}

ASSIGNED {
	diam (um)
	Gef_act (1)
}

STATE {
  RasGDP (mM)
  RasGTP (mM)
}

BREAKPOINT { SOLVE state METHOD sparse }


INITIAL {
	RasGDP = 0.0006
	RasGTP = 0
	}
	
KINETIC state {

   	COMPARTMENT PI*diam {RasGDP RasGTP}
	LONGITUDINAL_DIFFUSION DRas*diam {RasGDP}
	LONGITUDINAL_DIFFUSION DRas*diam {RasGTP}
  
  ~ RasGDP <-> RasGTP (kf_rasGDP*Gef_act, kr_rasGDP)
}
