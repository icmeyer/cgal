// Copyright (c) 2014
// Utrecht University (The Netherlands),
// ETH Zurich (Switzerland),
// INRIA Sophia-Antipolis (France),
// Max-Planck-Institute Saarbruecken (Germany),
// and Tel-Aviv University (Israel).  All rights reserved.
//
// This file is part of CGAL (www.cgal.org)
//
// $URL$
// $Id$
// SPDX-License-Identifier: LGPL-3.0-or-later OR LicenseRef-Commercial
//
//
// Author(s)     : Laurent Rineau

#include <CGAL/config.h>
#include <CGAL/boost_mp.h>
#if CGAL_USE_GMPXX
#  include <CGAL/gmpxx.h>
#elif CGAL_USE_GMP
#  include <CGAL/Gmpz.h>
#elif CGAL_USE_LEDA
#  include <CGAL/leda_integer.h>
#elif CGAL_USE_CORE
#  include <CGAL/CORE_BigInt.h>
#elif defined CGAL_USE_BOOST_MP
#else
#  error CGAL is configured with none of GMP, LEDA, Boost.Multiprecision and CORE. <CGAL/Exact_integer.h> cannot be used.
#endif

namespace CGAL {

/*!
\ingroup nt_cgal

`Exact_integer` is an exact integer number type.

It is a typedef of another number type. Its exact definition depends on
the availability the third-party libraries \gmp, \core, and \leda. \cgal must
be configured with at least one of those libraries.

\cgalModels `EuclideanRing`
\cgalModels `RealEmbeddable`

*/
#if DOXYGEN_RUNNING

typedef unspecified_type Exact_integer;

#else // not DOXYGEN_RUNNING

#if BOOST_VERSION > 107900 && defined(CGAL_USE_BOOST_MP)
// use boost-mp by default
typedef BOOST_cpp_arithmetic_kernel::Integer Exact_integer;
#else // BOOST_VERSION > 107900
#ifdef CGAL_USE_GMPXX
typedef mpz_class Exact_integer;
#elif defined(CGAL_USE_GMP)
#if defined(CGAL_USE_BOOST_MP)
typedef BOOST_gmp_arithmetic_kernel::Integer Exact_integer;
#else
typedef Gmpz Exact_integer;
#endif
#elif defined(CGAL_USE_LEDA)
typedef leda_integer Exact_integer;
#elif defined(CGAL_USE_BOOST_MP)
typedef BOOST_cpp_arithmetic_kernel::Integer Exact_integer;
#elif defined(CGAL_USE_CORE)
typedef CORE::BigInt Exact_integer;
#else
#error "ERROR: Cannot determine a BigInt type!"
#endif // CGAL_USE_CORE
#endif // BOOST_VERSION > 107800

#endif // not DOXYGEN_RUNNING

} /* end namespace CGAL */
