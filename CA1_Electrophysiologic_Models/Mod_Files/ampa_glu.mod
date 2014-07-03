COMMENT
Two state kinetic scheme synapse described by rise time tau1,
decay time constant tau2, and peak conductance gtrig.
Decay time MUST be greater than rise time.

The solution of A->G->bath with rate constants 1/tau1 and 1/tau2 is
 A = a*exp(-t/tau1) and
 G = a*tau2/(tau2-tau1)*(-exp(-t/tau1) + exp(-t/tau2))
	where tau1 < tau2

(Notice if tau1 -> 0 then we have just single exponential decay.)
The factor is evaluated in the
initial block such that the peak conductance is gtrig.

Because the solution is a sum of exponentials, the
coupled equations can be solved as a pair of independent equations
by the more efficient cnexp method.

Specify an incremental delivery event
(synapse starts delay after the source
crosses threshold. gtrig is incremented by the amount specified in
the delivery event, onset will be set to the proper time)
ENDCOMMENT

NEURON {
	POINT_PROCESS ampa
	
	RANGE tau1, tau2, e, i
	USEION na WRITE ina
	USEION k WRITE ik
	NONSPECIFIC_CURRENT i
	
	RANGE gsyn, Area
	GLOBAL total
}

UNITS {
	(nA) = (nanoamp)
	(mV) = (millivolt)
	(umho) = (micromho)
}

PARAMETER {
	tau1= 2 (ms)
	tau2 = 9 (ms)
	gmax = 0.07 (mho/cm2) :valeur provenant du ca1.p
	g_mox = 0.004 (mho/cm2) :valeur de gmax venant de protog
	e=0	(mV)
	Area = 3.32e-5 (cm2)
}

ASSIGNED {
	v (mV)
	i (nA)
	ik     (mA/cm2)
	ina     (mA/cm2)
	gsyn (umho)
	factor
	total (umho)
}

STATE {
	A (umho)
	B (umho)
}

INITIAL {
	LOCAL tp
	total = 0
	A = 0
	B = 0
	tp = (tau1*tau2)/(tau2 - tau1) * log(tau2/tau1)
	factor = -exp(-tp/tau1) + exp(-tp/tau2)
	factor = 1/factor
}

BREAKPOINT {
	SOLVE state METHOD cnexp
	gsyn = B - A
	i = g_mox*gsyn*(v - e)
	:ik = (i*1e-6)/Area :e-6 pour convertir en mA
	:ina = (i*1e-6)/Area :e-6 pour convertir en mA
}

DERIVATIVE state {
	A' = -A/tau1
	B' = -B/tau2
}

NET_RECEIVE(weight (umho)) {
	A = A + weight*factor
	B = B + weight*factor
	:state_discontinuity(A, A + weight*factor)
	:state_discontinuity(B, B + weight*factor)
	total = total+weight
}
