kakoune-fuzzers
===============

This repository contains some fuzzers based on
[libFuzzer](https://www.llvm.org/docs/LibFuzzer.html) for the
[Kakoune](https://github.com/mawww/kakoune) code editor.

Setup
-----

Clone this repository, then place a copy of Kakoune's source code in it:

	$ git clone https://github.com/lenormf/kakoune-fuzzers.git
	$ cd kakoune-fuzzers
	$ git clone https://github.com/mawww/kakoune.git

Note that you can download any version of Kakoune that you want to build
the fuzzers against, using Git or not. The code doesn't need to be within
`kakoune-fuzzers` either, it's just more convenient that way.

Compiling
---------

Compile all the fuzzers at once with the following command:

	$ make KAKOUNE="${PWD}/kakoune"

The above command will visit all the directories that contain fuzzers,
and compile them. You have to pass the absolute path to the Kakoune code
to compile against using the `KAKOUNE` variable.

If you only want to compile the fuzzers for a given category, for example
`regex`, then `cd` into that category's directory, and run the same command
above (adjust the path to Kakoune if needed).

Running a fuzzer
----------------

Read the list of all available options using the following command:

	$ ./fuzzer -help=1

Once you've decided which flag you're going to use to run the fuzzer,
run it, and wait for results. For example:

	$ ./fuzzer -only_ascii=1 -detect_leaks=0