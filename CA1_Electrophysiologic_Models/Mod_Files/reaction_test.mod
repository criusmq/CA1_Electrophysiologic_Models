TITLE Equations tests 
COMMENT
	Exemple_test Rien de réel
	Mazid Abiodoun OSSENI,Simon Hardy ,Nicolas Doyon
	Laval University, Quebec, Qc
	
ENDCOMMENT


NEURON {
   SUFFIX reaction_test
   USEION ca READ cai, ica
   GLOBAL TotalBuffer : vrat must be GLOBAL--see INITIAL block
							: however TotalBuffer may be RANGE

}

UNITS {
   (molar) = (1/liter)
   (mM)    = (millimolar)
   (um)    = (micron)
   (mA)    = (milliamp)
   FARADAY = (faraday)  (10000 coulomb)
   PI      = (pi)       (1)
}


PARAMETER {
  : DCa   = 0.6 (um2/ms)
   k1buf = 1 (/mM-ms) : Kf
   k2buf = 0.1 (/ms)	: kb
   TotalBuffer = 0.5 (mM)
}

ASSIGNED {
	diam (um)
	ica (mA/cm2)
	cai (mM)
   :Kd        (/mM)
	:B0 (mM) 
	L (um)
}

STATE {
  :Citer mes molecules de la reaction
  
   ca      (mM) <1e-10>
   CaGef (mM)	<1e-10>
   Gef   (mM)	<1e-10>
}

BREAKPOINT { SOLVE states METHOD sparse }

INITIAL {
	
	:Kd = k1buf/k2buf
	:B0 = TotalBuffer/(1 + Kd*cai)
	:FROM i=0 TO Nannuli-1 {
		
	ca = cai
	Gef = TotalBuffer
	CaGef = 0

	:}
}


KINETIC states {
	

   :COMPARTMENT PI*diam*diam*L/4 {ca CaGef Gef}
   
   ~ ca + Gef <-> CaGef  (k1buf, k2buf)
   
   
   
   :LONGITUDINAL_DIFFUSION i, DCa*diam*diam*vrat[i] {ca}
   :~ ca[0] << (-ica*PI*diam/(2*FARADAY))  : ica is Ca efflux
   :FROM i=0 TO Nannuli-2 {
    : ~ ca[i] <-> ca[i+1]  (DCa*frat[i+1], DCa*frat[i+1])
   :}
   :dsq = diam*diam
   :FROM i=0 TO Nannuli-1 {
    :dsqvol = dsq*vrat[i]
     :~ ca[i] + Buffer[i] <-> CaBuffer[i]  (k1buf*dsqvol, k2buf*dsqvol)
   :}
:cai = ca[0] 

}
