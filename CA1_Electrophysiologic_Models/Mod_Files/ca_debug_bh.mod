TITLE Calcium CA channel for Traub 

NEURON {
	SUFFIX ca_debug_Bh
	USEION ca WRITE ica
	RANGE gca, m_inf, m_tau, h_inf, h_tau
	
}

UNITS {
	(mA) = (milliamp)
	(mV) = (millivolt)
}

PARAMETER {
	gca  = 0.004  (mho/cm2)
	erest_act = -60 (mV)
	eca     = 80    (mV)
}

STATE {
	m h 
}

ASSIGNED {
	v      	(mV)
	ica     (mA/cm2)
	m_inf
	m_tau (ms)
	h_inf
	h_tau (ms)
}

BREAKPOINT {
	SOLVE states METHOD cnexp
	ica = gca *m*m*h * (v - eca)
}

INITIAL {
	mh(v)
	m = m_inf
	h = h_inf
}

DERIVATIVE states {   : exact Hodgkin-Huxley equations
		mh(v)
		m' = (m_inf-m)/m_tau
		h' = (h_inf-h)/h_tau   
}

UNITSOFF

PROCEDURE mh (v(mV)) {
	LOCAL alpha, beta, sum
	alpha= 1.6 / ( 1 + exp((v + (-65 - erest_act)) / -13.89))
	beta= ((-0.02 * (51.1 + erest_act)) +  (0.02 * v)) / ( -1 + exp((v + (-51.1 - erest_act)) / 5.0))
	sum = alpha + beta
	m_inf = alpha/sum
	m_tau = 1/sum
	 
		if (v > erest_act) {
			alpha = 0.005 * (exp (-0.05*(v - erest_act)))
			beta = 0.005 - alpha : traub page 5; yet it was beta = 0.005 
			sum = alpha + beta
			h_inf = alpha/sum
			h_tau = 1/sum
		}
		else{
			alpha = 0.005
			beta = 0 : traub page 5; yet it was beta = 0.005 
			sum = alpha + beta
			h_inf = alpha/sum
			h_tau = 1/sum
		} 
}



UNITSON