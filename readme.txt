Open the CMakeList.txt file in this main folder to use CMake with Visual Studio!

This CMakeList.txt links all the CMakeList.txt(s) in the subfolders together. Each of those CMakeList.txt(s) contain a single "target". That target can be an executable or a library. The targets link themselves together(A calculator exectable target would link to the math library target to get its math functions) and the main CMakeList.txt here builds them all.
