TITLE NMDA_CA receptor for Bhalla 
COMMENT

	Mazid Abiodoun OSSENI,Simon Hardy ,Nicolas Doyon
	Laval University, Quebec, Qc

ENDCOMMENT

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
	POINT_PROCESS nmda_ca

	RANGE tau1, tau2, e, ica
	USEION ca WRITE ica
	NONSPECIFIC_CURRENT i

	RANGE gsyn, Area
	GLOBAL total, mg

}

UNITS {
	(nA) = (nanoamp)
	(mV) = (millivolt)
	(umho) = (micromho)
}

PARAMETER {
	tau1 = 20 (ms)
	tau2 = 20 (ms)
	gmax = 0.002 (mho/cm2) :valeur provenant du ca1.p
	g_mox = 0.0005 (mho/cm2) :valeur de gmax venant de protog
	mg	= 1.2    (mM)	: external magnesium concentration
	eca=80	(mV) : Reversal potential
}

ASSIGNED {
	v (mV)
	i (nA)
	ica (mA)
	:ica     (mA/cm2)
	gsyn (umho)
	factor
	total (umho)
	Area (cm2)
}

STATE {
	A (umho)
	B (umho)

}

INITIAL {
	LOCAL tp
	if (tau1/tau2 > .9999) {
		tau1 = .9999*tau2
	}
	total = 0
	A = 0
	B = 0
	tp = (tau1*tau2)/(tau2 - tau1) * log(tau2/tau1)
	factor = -exp(-tp/tau1) + exp(-tp/tau2)
	factor = 1/factor
	Mgblock(v)
}

BREAKPOINT {
	SOLVE state METHOD cnexp
	gsyn = B - A

	i = g_mox*gsyn*Mgblock(v)*(v - eca)
	ica = i*1e-6

	:ica = (i*1e-6)/Area :e-6 pour convertir en mA
							:0.1* essaie vue que dans bhalla il dit 1/10 de NMDA channel conductance
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

FUNCTION Mgblock(v(mV)) {
	: from Jahr & Stevens, JNS, 1990

	:MG = (1/0.28(/mM)) * ( (1/0.28(/mM)) - (mg*exp(-v * 0.062 (/mV))))

	:Block = 1/eta * (1/eta - [Mg]*exp( -V * gamma))
	:change the voltage

	Mgblock = 1 / (1 +  ( (mg / 3.57 (mM)) * exp(-v * 0.062 (/mV)) ))

}