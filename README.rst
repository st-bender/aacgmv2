========
Overview
========

|docs| |version|

This is a Python wrapper for the `AACGM-v2 C library
<https://engineering.dartmouth.edu/superdarn/aacgm.html>`_, which allows converting between geographic and magnetic coordinates. The currently included version of the C library is 2.4. The wrapper is provided "as is" in the hopes that it will be useful to the space science community, and will not automatically be updated when new versions of the C library is released. MLT calculations are included in the wrapper (not part of the C library, please see the documentation for implementation details). The package is free software (MIT license).

Quick start
===========

Install (requires NumPy)::

    pip install aacgmv2

Convert between AACGM and geographic coordinates::

    >>> from aacgmv2 import convert
    >>> from datetime import date
    >>> # geo to AACGM, single numbers
    >>> mlat, mlon, malt = convert(60, 15, 300, date(2013, 11, 3))
    >>> "{0:.8f}".format(float(mlat))
    '57.47357891'
    >>> "{0:.8f}".format(float(mlon))
    '93.61113360'
    >>> "{0:.8f}".format(float(malt))
    '1.04566346'
    >>> # AACGM to geo, mix arrays/numbers
    >>> glat, glon, galt = convert([90, -90], 0, 0, date(2013, 11, 3), a2g=True)
    >>> ["{0:.8f}".format(float(gl)) for gl in glat]
    ['82.96859922', '-74.33899667']
    >>> ["{0:.8f}".format(float(gl)) for gl in glon]
    ['-84.65010944', '125.84759847']
    >>> ["{0:.8f}".format(float(ga)) for ga in galt]
    ['14.12457922', '12.87721946']

Convert between AACGM and MLT::

    >>> from aacgmv2 import convert_mlt
    >>> from datetime import datetime
    >>> mlon = convert_mlt([0, 12], datetime(2013, 11, 3, 18, 0), m2a=True)
    >>> ["{0:.8f}".format(float(ml)) for ml in mlon]
    ['159.08043649', '339.08043649']

If you don't know or use Python, you can also use the command line. See details in the full documentation.

Documentation
=============

https://aacgmv2.readthedocs.org/

Badges
======

.. list-table::
    :stub-columns: 1

    * - docs
      - |docs|
    * - tests
      - | |travis| |appveyor| |requires|
        | |coveralls| |codecov|
        | |scrutinizer| |codacy|
    * - package
      - | |version| |supported-versions|
        | |wheel| |supported-implementations|

.. |docs| image:: https://readthedocs.org/projects/aacgmv2/badge/?version=stable&style=flat
    :target: https://readthedocs.org/projects/aacgmv2
    :alt: Documentation Status

.. |travis| image:: https://travis-ci.org/st-bender/aacgmv2.svg?branch=master
    :alt: Travis-CI Build Status
    :target: https://travis-ci.org/st-bender/aacgmv2

.. |appveyor| image:: https://ci.appveyor.com/api/projects/status/github/st-bender/aacgmv2?branch=master&svg=true
    :alt: AppVeyor Build Status
    :target: https://ci.appveyor.com/project/st-bender/aacgmv2

.. |requires| image:: https://requires.io/github/st-bender/aacgmv2/requirements.svg?branch=master
    :alt: Requirements Status
    :target: https://requires.io/github/st-bender/aacgmv2/requirements/?branch=master

.. |coveralls| image:: https://coveralls.io/repos/st-bender/aacgmv2/badge.svg?branch=master&service=github
    :alt: Coverage Status
    :target: https://coveralls.io/github/st-bender/aacgmv2

.. |codecov| image:: https://codecov.io/github/st-bender/aacgmv2/coverage.svg?branch=master
    :alt: Coverage Status
    :target: https://codecov.io/github/st-bender/aacgmv2

.. |codacy| image:: https://img.shields.io/codacy/grade/2b9d243afe654cb0a70c31544444c774.svg?style=flat
    :target: https://www.codacy.com/app/st-bender/aacgmv2
    :alt: Codacy Code Quality Status

.. |version| image:: https://img.shields.io/pypi/v/aacgmv2.svg?style=flat
    :alt: PyPI Package latest release
    :target: https://pypi.python.org/pypi/aacgmv2

.. |downloads| image:: https://img.shields.io/pypi/dm/aacgmv2.svg?style=flat
    :alt: PyPI Package monthly downloads
    :target: https://pypi.python.org/pypi/aacgmv2

.. |wheel| image:: https://img.shields.io/pypi/wheel/aacgmv2.svg?style=flat
    :alt: PyPI Wheel
    :target: https://pypi.python.org/pypi/aacgmv2

.. |supported-versions| image:: https://img.shields.io/pypi/pyversions/aacgmv2.svg?style=flat
    :alt: Supported versions
    :target: https://pypi.python.org/pypi/aacgmv2

.. |supported-implementations| image:: https://img.shields.io/pypi/implementation/aacgmv2.svg?style=flat
    :alt: Supported implementations
    :target: https://pypi.python.org/pypi/aacgmv2

.. |scrutinizer| image:: https://img.shields.io/scrutinizer/g/st-bender/aacgmv2/master.svg?style=flat
    :alt: Scrutinizer Status
    :target: https://scrutinizer-ci.com/g/st-bender/aacgmv2/
