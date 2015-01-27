// ---------------------------------------------------------------------
//
// Copyright (C) 1998 - 2014 by the deal.II authors
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



// check accuracy of various quadrature formulas by using them to
// integrate polynomials of increasing degree, and finding the degree
// until which they integrate exactly


//#include "../tests.h"
#include "../include/quadrature.h"
#include <iomanip>
#include <fstream>
#include <cmath>


template <int dim>
Quadrature<dim>
QMidpoint ()
{
  Point<dim> mid_point(0.5);
  std::vector<Point<dim> > points(1);
  points[0] = mid_point;
  double weight(1.);
  std::vector<double> weights(1);
  weights[0] = weight;
  Quadrature<dim> mid_quad(points, weights);
  return mid_quad;

}
template <int dim>
void
fill_vector (std::vector<Quadrature<dim> *> &quadratures)
{
  quadratures.push_back (new QMidpoint<dim>());
  quadratures.push_back (new Quadrature(QMidpoint<dim>()));
}

template <int dim>
void
check_cells (std::vector<Quadrature<dim>*> &quadratures, std::ofstream
&logfile)
{
  Quadrature<dim> quadrature;
  for (unsigned int n=0; n<quadratures.size(); ++n)
    {
      quadrature = *quadratures[n];
      const std::vector<Point<dim> > &points=quadrature.get_points();
      const std::vector<double> &weights=quadrature.get_weights();

      logfile << "Quadrature no." << n;

      unsigned int i=0;
      double quadrature_int=0;
      double exact_int=0;
      double err = 0;

      do
        {
          ++i;

          quadrature_int=0;
          // Check the polynomial x, x+y, x+y+z

          for (unsigned int x=0; x<quadrature.size(); ++x)
            {
              double f=0.;
              switch (dim)
                {
                case 3:
                  f += 0.5 * (points[x](0) + points[x](1) + points[x](2));
                case 2:
                  f += 0.5 * (points[x](0) + points[x](1));
                case 1:
                  f += 0.5 * (points[x](0));
                }
              quadrature_int+=f*weights[x];
            }

          // the exact integral is dim * 1/2
          exact_int=dim * 0.5;
          err = std::fabs(quadrature_int-exact_int);
        }
      while (err<1e-14);
      logfile << " is exact for polynomials of degree 1 " << std::endl;

    }
}


int main()
{
  std::ofstream logfile("temp.output");

  std::vector<Quadrature<1> *> q1;
  std::vector<Quadrature<2> *> q2;
  std::vector<Quadrature<3> *> q3;
  fill_vector (q1);
  fill_vector (q2);
  fill_vector (q3);

  logfile << "Testing for 1d" << std::endl;
  check_cells(q1, logfile);

  logfile << "Testing for 2d" << std::endl;
  check_cells(q2, logfile);

  logfile << "Testing for 3d" << std::endl;
  check_cells(q3, logfile);

  // delete objects again to avoid
  // messages about memory leaks when
  // using purify or other memory
  // checkers
  for (unsigned int i=0; i<q1.size(); ++i)
    delete q1[i];
  for (unsigned int i=0; i<q2.size(); ++i)
    delete q2[i];
  for (unsigned int i=0; i<q3.size(); ++i)
    delete q3[i];
}
