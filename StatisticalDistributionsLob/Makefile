OFILES = Bernoulli.o Gamma.o NegBinomial.o Beta.o GammaPoisson.o Normal.o BetaBinomial.o Geometric.o Poisson.o Binomial.o JohnsonSb.o Triangular.o ChiSquared.o JohnsonSl.o Uniform.o Empirical.o JohnsonSu.o UniformDiscrete.o Exponential.o Lognormal.o Weibull.o
all: ${OFILES}

${OFILES}: %.o: %.cpp $(if $(shell test -e %.h), %.h)
	c++ -c -std=c++11z $<
