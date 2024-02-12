# EXERCISE:
**Validate the existence of a solution to a BVP for a 2DOF Henon-Heiles hamiltonian.**

### Problem description:
The Henon-Heiles hamiltonian is given by 

$`x" = -x*(1+2*y),\quad     y" = y*(y-1)-x^2 `$

The goal is to show the existence of a solution to the following BVP:

$`u(0)=u_0,\quad u(T)=u_1`$ 

where $`u=(x,y)`$.

## Methodology:
- Solve equation 
 
  $` F(u'(0)) := \pi_u\phi(T,(u_0,u'(0)))-u_1 = 0`$

  for $`u'(0)`$ using for example the Interval Newton Method, where 
  
    - $`\pi_u`$ is the projection onto u-coordinate 
    - $`\phi(t,u,u')`$ is the underlying flow.

### BVP data:
  $`T  = 1`$
  
  $`u(0) = (1,0)`$
  
  $`u(T) = (0,1)`$

