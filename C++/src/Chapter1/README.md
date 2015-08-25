#C++ Solutions: Chapter 1

Solutions working with matrices require a matrix input through stdin.

This can be achieved in one of the following ways:

```
$cat matrixFile.txt | matrixSolution HEIGHT WIDTH
```

```
$matrixSolution HEIGHT WIDTH < matrixFile.txt
```

or you can directly input the matrix using [Bash Here Documents](http://tldp.org/LDP/abs/html/here-docs.html).

```
$matrixSolution HEIGHT WIDTH << EOF
> 1 2 3 4 5
> 6 7 8 9 10
> 11 12 13 14 15
> 16 17 18 19 20
> 21 22 23 24 25
> EOF
```

Sample matrices for testing are located at `C++/data` inside this repository.
