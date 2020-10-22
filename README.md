kakoune-fuzzers
===============

This repository contains some fuzzers based on
[libFuzzer](https://www.llvm.org/docs/LibFuzzer.html) for the
[Kakoune](https://github.com/mawww/kakoune) code editor.

Dependencies
------------

The code should be compiled with `clang++`, under a version that has
`libFuzzer` available without any extra installation necessary. According to
the [documentation](https://www.llvm.org/docs/LibFuzzer.html#fuzzer-usage),
that would be version 6.0 and up.

The version of Clang used should also be supported by
upstream Kakoune. Make sure to check the project's
[build requirements](https://github.com/mawww/kakoune#building) for further
details.

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

Some fuzzers come with a corpus populated with relevant data (for example,
regular expressions used at runtime by the editor), feel free to use them
by passing their path to the program:

	$ ./fuzzer [options] /path/to/corpus

Using a corpus, whether it is provided by this repository or written by
yourself, is highly recommended to make fuzzing more effective.

If you want to run several fuzzers that rely on the same initial corpus,
create a new corpus directory and perform a merge:

	$ mkdir corpus_fuzzer
	$ ./fuzzer -merge=1 corpus_fuzzer corpus
	$ ./fuzzer [options] corpus_fuzzer
