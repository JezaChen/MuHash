# MuHash

C++ implementation of MuHash algorithm, **Ported from [Bitcoin source](https://github.com/bitcoin/bitcoin) code.** 

As stated in the Bitcoin source code, **MuHash** is a hashing algorithm that supports adding set elements in any order but also deleting in any order. As a result, it can maintain a 
running sum for a set of data as a whole, and add/remove when data is added to or removed from it.

The paper that proposed the algorithm is *A New Paradigm for Collision-free Hashing:
Incrementality at Reduced Cost* (https://cseweb.ucsd.edu/~mihir/papers/inchash.pdf).

## How to compile

use cmake to build the project. If an error occurs during the cmake build process, there may be a problem with the first line of the CMakeLists.txt file. Please change the version number on the first line to the cmake version number of the system.

