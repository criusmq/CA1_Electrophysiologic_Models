:Test de la diffusion longitudinal 
:a inserer au hasard dans un compartiment
NEURON {
	SUFFIX long_dif
	USEION ca READ cai,ica 
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
	cai (mM)
}

STATE {
	ca (mM)
}

BREAKPOINT {
	SOLVE conc METHOD sparse
}

INITIAL {
	ca = cai
}

KINETIC conc {
		
	COMPARTMENT PI*diam*diam/4 {ca}
	LONGITUDINAL_DIFFUSION D*diam*diam {ca}
	
	~ ca << (-ica/(FARADAY)*PI*diam*(1e4))
}