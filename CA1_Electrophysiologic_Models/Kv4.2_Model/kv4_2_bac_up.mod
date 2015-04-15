TITLE Fast A-type Potassium current for CA1 (Kv4.2)

COMMENT
		Mazid Abiodoun OSSENI,Simon Hardy ,Nicolas Doyon
		Laval University, Quebec, Qc
BASED ON Tkatch, T., Baranauskas, G., and Surmeier, D. J. (2000). Kv4.2 mRNA
abundance and A-type K(+) current amplitude are linearly related in
basal ganglia and basal forebrain neurons. J Neurosci 20, 579-588.

ENDCOMMENT

UNITS {
	(mV) = (millivolt)
	(mA) = (milliamp)
	(S) = (siemens)
}

NEURON {
	SUFFIX kaf
	USEION k READ ek WRITE ik
	RANGE gkbar, ik, mshift, hshift
}

PARAMETER {
	gkbar = 0.21	(S/cm2)		: 0.21 in soma and prox; 0.019211 in mid/dist dends

	:wild-type of kv4.2			: Schrader et al, 2006
	mvhalf = -24.0	(mV)		: Schrader et al, 2006
	mslope = -18	(mV)		: Schrader et al, 2006 
	mshift = 0	(mV)
	
	hvhalf = 61	(mV)			: Schrader et al, 2006
	hslope	= 3.4	(mV)		: Schrader et al, 2006
	hshift = 0	(mV)
	htau = 10	(ms)			: Schrader et al, 2006

	qfact = 3
	power = 2
	
	ek = -95	(mV)  
}

ASSIGNED { 
	v 		(mV)
    ik 		(mA/cm2)
	:ek 		(mV)

	minf
	hinf
}

STATE {
    m h 
}

BREAKPOINT {
    SOLVE states METHOD cnexp
	ik  = gkbar * m^power * h * (v-ek)
}

INITIAL {
	rates(v)
	m = minf
	h = hinf
}

FUNCTION_TABLE mtau (v(mV))  (ms)	: Tkatch 2000 Fig 2B

DERIVATIVE states {  
	rates(v)
	m' = (minf - m) / (mtau(v) / qfact)
	h' = (hinf - h) / (htau / qfact)
}


PROCEDURE rates( v(mV) ) {  : Boltzman adjusted to give proper Erev dependency 
:	TABLE minf, hinf DEPEND mshift, hshift, hslope
:		FROM -200 TO 200 WITH 201

			minf = 1  /  ( 1 + exp( (v - mvhalf - mshift) / mslope) ) 
			hinf = 1  /  ( 1 + exp( (v - hvhalf - hshift) / hslope) ) 

}