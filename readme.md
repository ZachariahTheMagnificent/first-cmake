# My First CMake!

__Open this folder in Visual Studio to start using CMake!__

What's CMake? CMake is a build system designed to build C++ projects.

What's a build system? Well, you know how a C++ program is made from a collection of headers(.h/.hpp) and source(.cpp) files? Well, how does the compiler know where to find those files? In fact, how does the compiler know what the program's name is, where to store it, whether or not to build it in debug mode or release mode etc.?

In the past, programmers would pass these settings to the compiler manually using commands every time they want to build their program.

```
compiler build-app "app.exe" -debug_mode -header_files "header.hpp" -source_files "main.cpp"
```

This obviously doesn't scale well once you start using multiple files and external libraries with complex dependencies so programmers use tools like build systems to automate the build process.

Unlike Visual Studio's custom build system(MSBuild), CMake is more universal as it could work with multiple compilers and editors on multiple platforms like Windows and even Linux! Plus, a lot of libraries use it so using CMake means that you can use those libraries a lot easier.

CMake projects are defined by CMakeLists.txt(s). These projects contain "targets" that are a collection of settings that the compiler can use to build libraries and applications. There are various commands you can put in a CMakeLists.txt but the commands shown below are what you'll be using most of the time.

This project contains multiple CMakeLists.txt(s). Let's take a look at them starting with the one in the main directory.

```cmake
cmake_minimum_required(VERSION 3.11)
```

This is the first line of every CMakeLists.txt. It specifies the version of CMake that the project uses.

```cmake
project(first-cmake VERSION 1.0.0 DESCRIPTION "A test to see if I can make a CMake Project" LANGUAGES CXX)
```

This should be the second line of your CMakeLists.txt. It takes the name of your project + some optional details. Those optional details are VERSION(Major.Minor.Patch.Tweak), DESCRIPTION, LANGUAGES like C and CXX(C++) and HOMEPAGE_URL(not shown here). The order you specify these details don't matter.

```cmake
# Build the math project.
```

This is a comment. CMake ignores comments so you can use them to write down any sort of information you want. Be sure that the text are all in one line.

```cmake
# Build the math project.
add_subdirectory("${PROJECT_SOURCE_DIR}/parser")
```

This command tells CMake to include another CMake project to the build. Note that `${PROJECT_SOURCE_DIR}` translates to the directory that the current CMake project is in.

This is a common pattern where you have one main CMake project include all the other CMake projects.

Let's take a look at the parser project that we've included.

```cmake
# Declare the library.
add_library(parser)
```

This'll create the very first example of a CMake target in this article called parser. Parser is considered a "library target" and the commands below will attach some settings to it.

```cmake
# Declare that the library uses C++17
target_compile_features(parser PUBLIC cxx_std_17)
```

This declares that the parser target uses C++17. Notice the `PUBLIC` keyword there. This means that any other CMake target that uses parser will inherit this setting. In other words, targets that use parser will also use C++17.

```cmake
# Declare our includes.
target_include_directories(parser
	PUBLIC
		"${PROJECT_SOURCE_DIR}/include"

	PRIVATE
		"${PROJECT_SOURCE_DIR}/internal"
)
```

This declares the directories where parser's header files are located in. Notice the keyword `PRIVATE`. Unlike `PUBLIC`, `PRIVATE` settings will not be inherited by other targets that use parser. This is good for settings that are only meant to be used internally by the target and no one else.

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

Now let's look at the math project. This project creates a header only library target. Since the library is header only(no source files), it needs to be created slightly differently from regular libraries.

```cmake
# The library is a header only library. It won't be compiled.
add_library(math INTERFACE)
```

As you can see, the math library target is created the same way as the parser target but with the `INTERFACE` keyword specified. This creates an interface library which are libraries that don't build anything. They're just a collection of settings that other targets can inherit.

Header only libraries have to be interface libraries because header files don't actually get compiled by the compiler. They're just `#include`d into source files which are then compiled into an application. If you try to compile an application or library with no source files, the compiler will complain. As an interface library, other targets can link to it to inherit its headers and settings.

The rest of the file is similar to the parser project but with the `INTERFACE` keyword.

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

This creates an executable target called calculator.

The rest of the commands are ones you've seen before except for this command here:

```cmake
# Declare the libraries this executable uses.
target_link_libraries(calculator
	PRIVATE
		math
		parser
)
```

This links the targets math and parser to calculator. This command is one of the most useful commands you'd use in CMake. Targets are basically just a collection of settings. Where your headers are located, what files your project has, which version of C++ it uses etc. You can store these settings into small individual targets and then link them together into a larger target. With the keywords `PUBLIC`, `PRIVATE` and `INTERFACE`, you can control which settings will be inherited by other targets. This allows you to reuse settings by linking to specific targets saving you from having to set them up again. It's a bit like inheritance in OOP languages.

That's pretty much it. This is all you need to create and use CMake projects. CMake is incredibly simple to use when used right and with additional commands, you can do incredible things like building different applications for different platforms(Windows, Linux, Android) with one project or automate thousands of tests that debug your application the moment you build it. CMake gives you much more flexibility than what Visual Studio allows.

To learn more about CMake, check out the documentation here:
https://cmake.org/cmake/help/latest/guide/tutorial/index.html
