# ECEN 5813 Projects

Christopher Morroni and Matthew Haney

### Building

```
make [TARGET] [OVERRIDES]
```

Build Targets:

* \<FILE> - Builds \<FILE> object file
* build - Builds and links all source files
* compile-all - Compiles to object files, but stops before linking
* clean - Removes all generated files
* redo - Cleans then rebuilds
* install - Builds then installs on target
* uninstall - Uninstalls from target
* debug - Builds then debugs on target
* test - Builds and runs cmocka unit tests
* testclean - Cleans files generated for unit tests

Overrides:

* PLATFORM - Platform for build (HOST, BBB, KL25Z)
* VERBOSE - Include logging (TRUE, assumes false)
* PROFILE - Include code to profile memory operations (TRUE, assumes false)
