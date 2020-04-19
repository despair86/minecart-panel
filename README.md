this is a minecart server admin panel web app written with [kcgi](https://kristaps.bsd.lv/kcgi/index.html).

requires: openbsd, solaris, or some relatively sane unix-like system. the prod server runs on a sun with [smartos](https://smartos.org) and nginx.

install [kcgi](http://github.com/kristapsdz/kcgi/) by passing this folder path to its [openbsd configure](http://github.com/kristapsdz/oconfigure)
script: `./configure --prefix=/path/to/minecart-panel`, then `[b]make install`. if you are on a non-BSD machine, you may also need to find a copy
of a [BSD-style](http://crufty.net/help/sjg/bmake.html) `make`. you may also want to build your own libz and install here if your OS does not ship
a static library.

the BSD and Linux makefile requires bsd or gnu make. the default makefile could work on RHEL/centos if you happen to have sun studio for linux installed.
otherwise simply `cd src; make -f Makefile.bsd` to use GCC or clang (preferred).

the default templates are CC-BY-SA v3 by their respective authors, see `templates/*/template.xml` for more info.
