TITLE NMDA_Calcium dynamics cai for Traub/Bhalla 
COMMENT

	Mazid Abiodoun OSSENI,Simon Hardy ,Nicolas Doyon
	Laval University, Quebec, Qc
	
ENDCOMMENT

COMMENT

	Implemented by Maciej Lazarewicz 2003 (mlazarew@seas.upenn.edu) modifié :)
	Permet de caluculer le cai (concentration interne de ca dans le neuron)
	Tirer de la documentation. Etant identique dans plusieurs projets mais c'est compatible
	à la documentantion présente dans protodefs.g à propos du ca_conc
	 phi, beta : des constantes correspondants à tau     0.013333   \      // sec
               									 B       17.402e12 \      // Curr to conc for soma
                									Ca_base 0.0
Ca_conc:
B_bhalla == phi_traub donc tau_bhalla = beta_traub

ENDCOMMENT

NEURON {
	SUFFIX nmda_ca_conc_Bh
	USEION ca READ ica WRITE cai
	RANGE  phi, beta
	GLOBAL ceiling
}

UNITS {
	(mA)	= (milliamp)
	(mol) = (1)
  	(molar) = (mol/liter)
 	(mM) = (millimolar)
}

PARAMETER {
	phi 	= 0.25 (/ms) :(1/4)
	:phi	= 4 (ms)
	beta = 17.402 
	ceiling	= 2	(mM)
	caiBase = 50e-6 (mM) : the assumed resting level of intracellular calcium
}

STATE {	cai (mM) }

ASSIGNED { 
	ica		(mA/cm2) 
}
	

INITIAL { 
 	cai= caiBase
}

BREAKPOINT {
	SOLVE state METHOD derivimplicit
}

UNITSOFF
DERIVATIVE state {  
	cai' = (- beta * ica) - (phi * (cai - caiBase))
}
UNITSON
