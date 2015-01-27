template <>
Quadrature<0>::Quadrature (const unsigned int n_q)
    :
    quadrature_points (n_q),
    weights (n_q, 0)
{}



template <>
Quadrature<0>::~Quadrature ()
{}



template <int dim>
Quadrature<dim>::Quadrature (const unsigned int n_q)
    :
    quadrature_points (n_q, Point<dim>()),
    weights (n_q, 0)
{}



template <int dim>
void
Quadrature<dim>::initialize (const std::vector<Point<dim> > &p,
                             const std::vector<double> &w)
{
    AssertDimension (w.size(), p.size());
    quadrature_points = p;
    weights = w;
}



template <int dim>
Quadrature<dim>::Quadrature (const std::vector<Point<dim> > &points,
                             const std::vector<double> &weights)
    :
    quadrature_points(points),
    weights(weights)
{
  Assert (weights.size() == points.size(),
        ExcDimensionMismatch(weights.size(), points.size()));
}



template <int dim>
Quadrature<dim>::Quadrature (const std::vector<Point<dim> > &points)
    :
    quadrature_points(points),
    weights(points.size(), std::atof("Inf"))
{
    Assert(weights.size() == points.size(),
        ExcDimensionMismatch(weights.size(), points.size()));
}


template <int dim>
Quadrature<dim>::Quadrature (const Point<dim> &point)
    :
    quadrature_points(std::vector<Point<dim> > (1, point)),
    weights(std::vector<double> (1, 1.))
  {}
