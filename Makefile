test:
	cd tests && ./run_tests.sh
clean:
	cd tests/ && rm -f *.out matrix_tests frac_tests polynomial_tests vector_tests
