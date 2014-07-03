TITLE Potassium K (A) channel for Traub 

NEURON {
	SUFFIX k_a_Bh
	USEION k WRITE ik
	RANGE gk,  m_inf, m_tau, h_inf, h_tau
}

UNITS {
	(mA) = (milliamp)
	(mV) = (millivolt)
}

PARAMETER { 
	gk = 0.005 (mho/cm2)
	ek = -75	(mV)  
	erest_act = -60 (mV)
}

STATE {
	m h 
}

ASSIGNED {
	v  (mV)
	ik     (mA/cm2)
	m_inf
	m_tau (ms)
	h_inf
	h_tau (ms)
}

BREAKPOINT {
	SOLVE states METHOD cnexp
	ik = gk * m * h * (v - ek)
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
	alpha= ((0.02 * (13.1 + erest_act)) + (-0.02 * v)) / ( -1 + exp((v + (-13.1 - erest_act)) / -10))
	beta= ((-0.0175 * (40.1 + erest_act)) + (0.0175 * v)) / ( -1 + exp((v + (-40.1 - erest_act)) / 10))
	sum = alpha + beta
	m_inf = alpha/sum
	m_tau = 1/sum
	
	alpha= 0.0016 / exp((v + (13 - erest_act) / 18))
	beta= 0.05 / (1 + exp((v + (-10.1 - erest_act)) / -5))
	sum = alpha + beta
	h_inf = alpha/sum
	h_tau = 1/sum
}

UNITSON