# Installing `SDL_bgi` on GNU/Linux

The easiest way to install `SDL_bgi` is by using the binary packages
provided at <http://sdl-bgi.sourceforge.io/#download> in `.deb` and
`.rpm` format.

Alternatively, you can easily compile `SDL_bgi` yourself, as shown below.


## Compiling from sources

Please make sure you have SDL2 development packages. On Debian, Mint,
Ubuntu and similar distributions, please install `libsdl2-dev` and its
dependencies; in Fedora, please install `SDL2-devel`. Obviously,
you'll also need `make` and a C compiler; `gcc` or `clang` are fine.


### Using `make`

To compile and install `SDL_bgi`, run the following commands:

    $ VERSION=2.5.1
    $ tar zxvf SDL_bgi-$VERSION.tar.gz
    $ cd SDL_bgi-$VERSION/src
    $ make
    $ sudo make install

Files will be installed in appropriate directories:

    SDL_bgi.h      ->  /usr/include/SDL2/
    graphics.h     ->  /usr/include/
    libSDL_bgi.so  ->  /usr/lib/


### Using `cmake`

This only works if `cmake` and `cpack` are installed.

To compile the `SDL_bgi` library and make `.deb` or `.rpm` packages:

    $ VERSION=2.5.1
    $ tar zxvf SDL_bgi-$VERSION.tar.gz
    $ cd SDL_bgi-$VERSION
    $ ./mkpkg.sh

which creates a subdirectory called `build/`, moves to it, runs
`cmake`, then `cpack`. In a few seconds, in directory `build/` you
will find a package that should be suitable for your system (`.deb` or
`.rpm`). You'll want to install that.

If you prefer the usual way:

    $ mkdir build && cd build
    $ cmake ..
    $ make && sudo make install 

To uninstall:

    $ make uninstall


## Test Programs

Once `SDL_bgi` is installed, you can compile some test programs you
can find in the `test/` directory. Type:

    $ cd test && make

Please see the `using.md` file in the `doc/` directory.

Enjoy!

Guido =8-)
