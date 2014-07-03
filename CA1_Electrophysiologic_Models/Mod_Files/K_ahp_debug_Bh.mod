TITLE Potasium AHP type current for Traub

NEURON { 
	SUFFIX k_ahp_Bh
	USEION k WRITE ik
	USEION ca READ cai
	RANGE gk, ik, n_inf, n_tau
}


UNITS { 
	(mV) = (millivolt) 
	(mA) = (milliamp) 
} 

PARAMETER { 
	gk = 0.0008 	(mho/cm2)
	erest_act = -60 (mV)
	ek = -75	(mV)  
	cai		(1)
}

STATE {
	n
}


ASSIGNED { 
	v      	(mV)
	ik 		(mA/cm2) 
	n_inf
	n_tau (ms)
}
 

BREAKPOINT { 
	SOLVE states METHOD cnexp
	ik = gk * n * ( v - ek ) 
}
 
INITIAL { 
	mh(cai)
	n = n_inf
}
 
DERIVATIVE states { 
	mh(cai)
	n' = (n_inf-n)/n_tau
}

UNITSOFF 

PROCEDURE mh(cai(mM)) {
 	LOCAL alpha, beta, sum
		if(cai<(0.5/2)){ : previously it was 500, an arbitrary valor! 19.4.2 The AHP Current.
						: i think it's too high so i'll put it at 500/1000 for a test
			alpha = 0.00002 * cai
			:beta = 0.001 : 19.4.2 The AHP Current; yet it was beta = alpha + 0.001
			beta = 0.001 + alpha :modification
			sum = alpha + beta
			n_inf = alpha/sum
			n_tau = 1/sum
		}
		else{
			alpha = 0.01
			:beta = 0.001 : 19.4.2 The AHP Current; yet it was beta = alpha + 0.001
			beta = 0.001 + alpha :modification
			sum = alpha + beta
			n_inf = alpha/sum
			n_tau = 1/sum
		}
}

UNITSON
