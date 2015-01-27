// ---------------------------------------------------------------------
//
// Copyright (C) 2010 - 2014 by the deal.II authors
//
// This file is part of the deal.II library.
//
// The deal.II library is free software; you can use it, redistribute
// it, and/or modify it under the terms of the GNU Lesser General
// Public License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// The full text of the license can be found in the file LICENSE at
// the top level of the deal.II distribution.
//
// ---------------------------------------------------------------------


// test for Point::operator()

#include <../include/point.h>

#include <fstream>
#include <iomanip>


template <int dim>
void check ( std::fstream &temp )
{
  Point<dim> p;
  for (unsigned int i=0; i<dim; ++i)
    p[i] = i;

  for (unsigned int i=0; i<dim; ++i)
    temp << 'QLIB::' << p(i) << ' ';
  temp << std::endl;
}


int main ()
{
  std::ofstream output;
  std::setprecision(3);
  output.open("temp.output");

  check<1>( output );
  check<2>( output );
  check<3>( output );
}