TITLE Sodium NA channel for Traub/Bhalla 
COMMENT

	Mazid Abiodoun OSSENI,Simon Hardy ,Nicolas Doyon
	Laval University, Quebec, Qc
	
ENDCOMMENT

NEURON {
	SUFFIX na_Bh 
	USEION na WRITE ina
	RANGE gna, m_inf, m_tau, h_inf, h_tau
	}

UNITS {
	(mA) = (milliamp)
	(mV) = (millivolt)
}

PARAMETER {
	gna = 0.03 (mho/cm2)
	erest_act = -60 (mV)
	ena     = 55    (mV)
}

STATE {
	m h 
}
ASSIGNED {	
	v  (mV)
	ina     (mA/cm2)
	m_inf
	m_tau (ms)
	h_inf
	h_tau (ms)
}

BREAKPOINT {
	SOLVE states METHOD cnexp
	ina = gna * m*m*h * (v - ena)
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

PROCEDURE mh(v(mV)) {
	LOCAL alpha, beta, sum
	alpha= ((0.32 * (13.1 + erest_act)) + (-0.32 * v)) / ( -1 + exp((v + (-1 * (13.1 + erest_act))) / -4))
	beta= ((-0.28 * (40.1 + erest_act)) +  (0.28 * v)) / ( -1 + exp((v + (-1 * (40.1 + erest_act))) / 5))
	sum = alpha + beta
	m_inf = alpha/sum
	m_tau = 1/sum
	
	alpha= 0.128 * (exp((17 -v + erest_act) / 18))
	beta= 4 / (1 + exp((v + (-1 * (40 + erest_act))) / -5.0))
	sum = alpha + beta
	h_inf = alpha/sum
	h_tau = 1/sum
}

UNITSON