TITLE Potassium K (DR) channel for Traub 

NEURON {
	SUFFIX k_dr_Bh
	USEION k WRITE ik
	RANGE gk, n_inf, n_tau
}

UNITS {
	(mA) = (milliamp)
	(mV) = (millivolt)
}

PARAMETER { 
	gk = 0.015 	(mho/cm2)
	ek = -75	(mV)  
	erest_act = -60 (mV)
	}

STATE {
	n
}

ASSIGNED {
	v (mV)
	ik     (mA/cm2)
	n_inf
	n_tau (ms)
}

BREAKPOINT {
	SOLVE states METHOD cnexp
	ik = gk * n * (v - ek)
}

INITIAL {
	mh(v)
	n = n_inf
}

DERIVATIVE states {   : exact Hodgkin-Huxley equations
		mh(v)
		n' = (n_inf-n)/n_tau
}

UNITSOFF

PROCEDURE mh(v(mV)) {
	LOCAL alpha, beta, sum
	alpha= ((0.016 * (35.1 + erest_act)) + (-0.016 * v)) / ( -1.0 + exp((v + (-1.0 * (35.1 + erest_act))) / -5))
	beta= 0.25/ exp((v + (-1.0 * (20 + erest_act))) / -40) : rajout d'un - devant le 40 pour avoir l'equation de traub page 5 
															: faisons le test
	sum = alpha + beta
	n_inf = alpha/sum
	n_tau = 1/sum
}

UNITSON