TITLE Potasium C type current for Traub/Bhalla 
COMMENT

	Mazid Abiodoun OSSENI,Simon Hardy ,Nicolas Doyon
	Laval University, Quebec, Qc
	
ENDCOMMENT

NEURON { 
	SUFFIX k_c_Bh
	USEION k WRITE ik
	USEION ca READ cai
	RANGE gk, ik, m_inf, m_tau
}

UNITS { 
	(mV) = (millivolt) 
	(mA) = (milliamp) 
} 

PARAMETER { 
	gk = 0.01 (mho/cm2)
	erest_act = -60 (mV)
	ek = -75	(mV)  
	cai		(1)
}
 
STATE {
	m
}

ASSIGNED { 
	v      	(mV)
	ik 		(mA/cm2) 
	m_inf
	m_tau (ms)
}

BREAKPOINT { 
	SOLVE states METHOD cnexp
	if(cai<(0.5/4)) {ik = gk*0.008*m*cai*(v - ek) } :previously it was 500, an arbitrary valor! 19.4.2 The AHP Current.
													:i think it's too high so i'll put it at 500/1000 for a test
													:z = Ca * 0.008 bhalla notes!!! Previously it was 0.004
	else {ik = gk*m*1*(v - ek)} :z = 1 bhalla notes
}

INITIAL {
	settables(v) 
	m = m_inf
}
DERIVATIVE states {   : exact Hodgkin-Huxley equations
	settables(v)
	m' = (m_inf-m)/m_tau
}

UNITSOFF
        
PROCEDURE settables(v) { 
	LOCAL alpha, beta, sum
	if (v < erest_act + 50) {
		alpha = (exp (0.053872*(v - erest_act) - 668.35))/18.975
		beta = (2*(exp ((erest_act + 6.5 - v)/27))) - alpha
		sum = alpha + beta
		m_inf = alpha/sum
		m_tau = 1/sum
	}
	else{
		alpha = 2*exp((erest_act + 6.5 - v)/27)
		beta = 0
		sum = alpha + beta
		m_inf = alpha/sum
		m_tau = 1/sum
	} 
}

UNITSON