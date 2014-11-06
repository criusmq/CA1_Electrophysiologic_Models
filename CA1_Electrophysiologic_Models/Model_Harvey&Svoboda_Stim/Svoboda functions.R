
f <- function(t) {
	t0 <- 1
	tau_GEF <- 2
	y <- ifelse(t<0,0,
		ifelse(t<=t0,(1-exp(-t/tau_GEF)),
			((1-exp(-1/tau_GEF)) * exp(-(t-t0)/tau_GEF))))
	y
}

plot(f,0,10)

# D <- 0.65
# tau_inactivation <- 4.5

# H <- function(x,t){(1/(2*D*t)^0.5) * exp(-x^2/(2*D*t)-t/tau_inactivation)  }

# x <- seq(0,10,length.out=100)
# t <- seq(0.01,10,length.out=100)
# h <- outer(x,t,H)

# dev.new()
# persp(x,t,h)

# phi <- function(x,t){
	# integrand <- function(tau) {H(x,(t-tau))*f(tau)}
	# integrate(integrand,lower = 0, upper = t)
# }

# ras = matrix(nrow=100,ncol=100)

# for(i in 1:length(x))
	# for(j in 1:length(t))
		# ras[i,j] <- phi(x[i],t[j])$value

# dev.new()
# persp(x,t,ras,xlim=c(0,10),ylim=c(0,10),zlim=c(0,0.6),theta=30)

