COMMENT
dsyn.mod

dsyn is a "distributed conductance" that is intended to be driven 
by an external function that generates a waveform that follows the
time course of the synaptic conductance.  If that waveform has 
peak amplitude 1, then gbar_dsyn specifies the peak synaptic 
conductance.

x is driven by means of a setpointer statement that links it
to a variable generated by a POINT_PROCESS
ENDCOMMENT

NEURON {
  SUFFIX nmda_ca_current
  USEION ca WRITE ica
  POINTER y : driven by an external function
  RANGE gbar, e
  RANGE g
  :GLOBAL mg
}

UNITS {
  (mV) = (millivolt)
  (mA) = (milliamp)
}

PARAMETER {
  e = 80 (mV)
  gbar = 0.0005 (mho/cm2) :valeur de gmax venant de protog
}

ASSIGNED {
  y (1)
  v (mV)
  g (mho/cm2)
  ica (mA/cm2)
}

INITIAL {
: pour l'instant le gnmda est tjrs pris en compte dans le .hoc juste pr le test! EN cas de resultats
: concluant je le ramene ici
  g = gbar*y
  ica = g*(v-e)
}

BREAKPOINT {
: printf("dsyn\n\n")
  g = gbar*y
  ica = g*(v - e)
}

