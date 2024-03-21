function compile_and_run() {
    # Compile the C file
    g++ -std=c++14 -o "$1" "$2" 

    # Check if the compilation was successful before running
    if [ $? -eq 0 ]; then
        echo "Compilation of $2 successful. Running..."
        # Run the compiled program
        ./"$1"
    else
        echo "Error: Compilation of $2 failed."
    fi
}

# Compile and run each C file one by one
compile_and_run "matrix_tests" "matrix_tests.cpp"
compile_and_run "frac_tests" "frac_tests.cpp"
compile_and_run "polynomial_tests" "polynomial_tests.cpp"
compile_and_run "vector_tests" "vector_tests.cpp"
