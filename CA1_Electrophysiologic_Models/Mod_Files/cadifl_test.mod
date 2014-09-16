NEURON {
	SUFFIX cadifl
	USEION ca READ ica WRITE cai
	RANGE D
}

UNITS {
	(mM) = (milli/liter)
	(um) = (micron)
	FARADAY = (faraday) (coulomb)
	PI = (pi) (1)
}

PARAMETER {
	D = .6 (um2/ms)
}

ASSIGNED {
	ica (milliamp/cm2)
	diam (um)
	L (um)
}

STATE {
	cai (mM)
}

BREAKPOINT {
	SOLVE conc METHOD sparse
}

KINETIC conc {
	COMPARTMENT PI*diam*diam*L/4 {cai}
	LONGITUDINAL_DIFFUSION D*PI*diam*diam/4 {cai}
	~ cai << (-ica/(FARADAY)*PI*diam*(1e4))
}