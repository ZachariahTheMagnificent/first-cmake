# My First CMake!

__Open this folder in Visual Studio to start using CMake!__

What's CMake? CMake is a build system designed to build C++ projects.

What's a build system? Well, you know how a C++ compiler creates an application from source(.cpp) files? Those source files also `#include` header files too. Question is, how does the compiler find those files in the first place? In fact, how does the compiler know to build the application using settings like "build in debug mode" or "Use this library"? Visual Studio users don't think about it too much as Visual Studio takes care of that for you. Underneath the hood, Visual Studio uses a tool called MSBuild that configures the compiler for you to build your application.

Back before build systems were used, programmers would interface with the compiler directly, running commands like

`compiler build-app "app.exe" -debug_mode -header_files "header.hpp" -source_files "main.cpp"`.

This obviously doesn't scale well once you start using multiple files and libraries with tons of settings so programmers use tools like build systems to automate the build process for them.

Unlike Visual Studio, CMake is more universal as it could work with multiple compilers and editors from Windows to even Linux. Plus, a lot of libraries use it meaning that if your project uses CMake, it can more easily intergrate those libraries.

CMake works with CMake projects defined by a CMakeLists.txt. These projects contain "targets" that can then be "linked" together to build a library, an application or even multiple of them at once! There are various commands you can put in a CMakeLists.txt but the ones in this project contain all the commands you need for most projects.

Let's start with the main CMakeLists.txt in the main directory.

```cmake
cmake_minimum_required(VERSION 3.11)
```

This is the first line of every CMakeLists.txt. It specifies the version of CMake the project uses.

```cmake
project(first-cmake VERSION 1.0.0 DESCRIPTION "A test to see if I can make a CMake Project" LANGUAGES CXX)
```

This should be the second line of your CMakeLists.txt. It takes the name of your project + some optional details. Those optional details are VERSION(Major.Minor.Patch.Tweak), DESCRIPTION, LANGUAGES like C and CXX(C++) and HOMEPAGE_URL(not shown here). The order you specify these optional details don't matter.

```cmake
# Build the math project.
```

This is a comment. It starts with a # and follows it up with some text. CMake just ignores comments so you can use them to write any sort of information you want in the file. Be sure that the text are all in one line.

```cmake
# Build the math project.
add_subdirectory("${PROJECT_SOURCE_DIR}/math")
```

This command tells CMake to add another CMake project to the build. `${PROJECT_SOURCE_DIR}` simply specifies the directory the current CMake project is in.

This is a common pattern where you have one main CMake project build all the other CMake projects. Other than that, the main CMake project doesn't do much.

Let's take a look at the parser project. This project has a library called parser.

```cmake
# Declare the library.
add_library(parser)
```

This declares that the project has a library called parser. In CMake terms, parser is a target. More on that later.

```cmake
# Declare that the library uses C++17
target_compile_features(parser PUBLIC cxx_std_17)
```

This declares that the parser target uses C++17. Notice the `PUBLIC` keyword there. This means that any other CMake target that links with parser will inherit this setting. In other words, targets that use parser will also use C++17.

```cmake
# Declare our includes.
target_include_directories(parser
	PUBLIC
		"${PROJECT_SOURCE_DIR}/include"

	PRIVATE
		"${PROJECT_SOURCE_DIR}/internal"
)
```

This declares the directories where parser's header files are located in. Notice the keyword `PRIVATE`. Unlike `PUBLIC`, `PRIVATE` settings will not be inherited by other targets that link to parser. This is good for settings that are only used internally by the target and you don't want other targets to get them.

```cmake
# Declare the library's files.
target_sources(parser
	PUBLIC
		"${PROJECT_SOURCE_DIR}/include/parser/parser.hpp"

	PRIVATE
		"${PROJECT_SOURCE_DIR}/source/parser.cpp"
		"${PROJECT_SOURCE_DIR}/internal/internal/internal.hpp"
		"${PROJECT_SOURCE_DIR}/source/internal.cpp"
)
```

This lists all the files that the target has including source files and headers.


Now let's look at the math project. This project has a header only library. Since the library is header only(no source files), it needs to be set slightly differently from regular libraries.

```cmake
# The library is a header only library. It won't be compiled.
add_library(math INTERFACE)
```
As you can see, the math library target is defined the same as the parser target but it has the `INTERFACE` keyword indicating that it is "empty". Header files don't get compiled by the compiler. They're just `#include`d into source files which are then compiled into an application. If you try to compile an application or library with no source files, the compiler will complain. `INTERFACE` library targets will not be compiled preventing this problem entirely. The rest of the file is similar to the parser project but with the `INTERFACE` keyword.

```cmake
# Declare that the library uses C++17.
target_compile_features(math INTERFACE cxx_std_17)
# Declare the library's includes.
target_include_directories(math INTERFACE "${PROJECT_SOURCE_DIR}/include")
# Declare the library's files.
target_sources(math INTERFACE "${PROJECT_SOURCE_DIR}/include/math/math.hpp")
```



Finally, let's look at the calculator project which will build an actual application using these libraries.

```cmake
# Declare the executable.
add_executable(calculator)
```

This declares an executable target called calculator.

The rest of the commands are ones you've seen before except for this line here:

```cmake
# Declare the libraries this executable uses.
target_link_libraries(calculator
	PRIVATE
		math
		parser
)
```

This links the targets math and parser to calculator. This command is one of the most useful commands you'd use in CMake. Targets are basically just a collection of settings. Where your headers are located, what files your project has, which version of C++ it uses etc. You can store these settings into small individual targets and then link them together into a large target. With the keywords `PUBLIC`, `PRIVATE` and `INTERFACE`, you can control which settings will be inherited by other targets. This allows you to reuse settings by linking to specific targets saving you from having to set them up again. It's a bit like how C++ uses inheritance for code reuse.

That's pretty much it. This is all you need to create CMake projects and use other CMake projects people make. CMake is incredibly simple to use when used right and with additional commands, you can do incredible things like building different applications for different platforms(Windows, Linux, Android) with one project or automate thousands of tests that debug your application the moment you build it. CMake gives you much more flexibility than what the Visual Studio interface allows.

To learn more about CMake, check out the documentation here:
https://cmake.org/cmake/help/latest/guide/tutorial/index.html