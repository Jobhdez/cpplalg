function compile_and_run() {
    g++ -std=c++14 -o "$1" "$2" 

    if [ $? -eq 0 ]; then
        echo "Compilation of $2 successful. Running..."
        ./"$1"
    else
        echo "Error: Compilation of $2 failed."
    fi
}

compile_and_run "matrix_tests" "matrix_tests.cpp"
compile_and_run "vector_tests" "vector_tests.cpp"
