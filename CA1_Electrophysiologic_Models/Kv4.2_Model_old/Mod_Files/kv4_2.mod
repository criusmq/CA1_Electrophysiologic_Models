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
	USEION KV42P READ KV42Pi
	USEION KV42 READ KV42i
	RANGE gkbar, ik, mshift, hshift, mshift_mutant, hshift_mutant
}

PARAMETER {
	gkbar = 0.019211	(S/cm2)		: 0.21 in soma and prox; 0.019211 in mid/dist dends

	:wild-type of kv4.2			: Schrader et al, 2006
	mvhalf = -24.0	(mV)		: Schrader et al, 2006
	mslope = -18	(mV)		: Schrader et al, 2006 
	mshift = 0	(mV)
	
	hvhalf = 61	(mV)			: Schrader et al, 2006
	hslope	= 3.4	(mV)		: Schrader et al, 2006
	hshift = 0	(mV)
	htau = 10	(ms)			: Schrader et al, 2006


	:mutant of kv4.2 T607D		: Schrader et al, 2006
	mvhalf_mutant = 6	(mV)		: Schrader et al, 2006
	mslope_mutant = -18	(mV)		: Schrader et al, 2006 
	mshift_mutant = 0	(mV)
	
	hvhalf_mutant = 63	(mV)			: Schrader et al, 2006
	hslope_mutant	= 3.9	(mV)		: Schrader et al, 2006
	hshift_mutant = 0	(mV)
	htau_mutant = 20	(ms)			: Schrader et al, 2006


	qfact = 3
	power = 2
	
	ek = -95	(mV)  
	KV42Pi		(1)
	KV42i		(1)
	KV42_total = 1.86e-4  (mM)
}

ASSIGNED { 
	v 		(mV)
    ik 		(mA/cm2)
	:ek 		(mV)

	minf
	hinf
	ninf
	qinf
}

STATE {
    m h n q
}

BREAKPOINT {
    SOLVE states METHOD cnexp
    :ik  = 0.8333 * gkbar * m^power * h * (v-ek) + 0.1667 * gkbar * n^power * q * (v-ek) 
    :ik  = 0.5* gkbar * m^power * h * (v-ek) + 0.5 * gkbar * n^power * q * (v-ek) 
    :ik  = 0.2 * gkbar * m^power * h * (v-ek) + 0.8 * gkbar * n^power * q * (v-ek) 
    :test de  stim faible, c est pour ca c est en commentaire. a enlever automatiquement apres
    if (KV42Pi == 0) { ik  = gkbar * m^power * h * (v-ek) }
    else {
	ik  = (KV42i/KV42_total) * gkbar * m^power * h * (v-ek) + (KV42Pi/KV42_total)*gkbar * n^power * q * (v-ek) }
}

INITIAL {
	rates(v)
	m = minf
	h = hinf
	n = ninf
	q = qinf
}

FUNCTION_TABLE mtau (v(mV))  (ms)	: Tkatch 2000 Fig 2B

DERIVATIVE states {  
	rates(v)
	m' = (minf - m) / (mtau(v) / qfact)
	h' = (hinf - h) / (htau / qfact)
	n' = (ninf - n) / (mtau(v) / qfact)
	q' = (qinf - q) / (htau_mutant / qfact)
}


PROCEDURE rates( v(mV) ) {  : Boltzman adjusted to give proper Erev dependency 
:	TABLE minf, hinf DEPEND mshift, hshift, hslope
:		FROM -200 TO 200 WITH 201

			minf = 1  /  ( 1 + exp( (v - mvhalf - mshift) / mslope) ) 
			hinf = 1  /  ( 1 + exp( (v - hvhalf - hshift) / hslope) ) 
	
			ninf = 1  /  ( 1 + exp( (v - mvhalf_mutant - mshift_mutant) / mslope_mutant) ) 
			qinf = 1  /  ( 1 + exp( (v - hvhalf_mutant - hshift_mutant) / hslope_mutant) ) 
}