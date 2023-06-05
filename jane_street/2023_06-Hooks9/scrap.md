## Scrap work 

Hooks have to be moving "inward". 
But depending on how you orient a hook it can go in four directions. 
This depends on where the points of the L is. 
E.g. if its top right, then you are moving "down left". 
So there are various orientations where you can move toward the middle. 
Q: is there a best way? 
Q: can we determine all the possible starting points? And recursively work our way up from there? 
   (thinking brute force). 

For filling in hooks, have to put N numbers of digit N in each. 
So the hook with 9, has to have 9 9's in it. 
But, the order can be whatever is needed. 
There is some constraints here, 
e.g. cannot have a 9 used for the 4 hook. 

Constraint: every filled square had to be connected orthogonally (i.e. diagonal connections don't count). 
Constraint: every 2 by 2 region has an empty square. 

GCD... 
hypothesis: if GCD is one, then that row/column has no repeating digits? 
hypothesis: if GCD is 2, 4, 6, then has one 
hypothesis: if GCD is multiple of 5, there is 5 in row/column? 
I'm not sure any of these will work, 
gcd is non-injective so we can't really invert it? Maybe here we can? 


## Notation 

- *N*: the digit used in a given hook. 
- *M-hook*: 
  the hook that has M components in the straight line. 
  For this problem, we have hooks 1, 2, ..., 9. 
  Each M-hook has area 2M - 1. 
  From constraints, we must have N >= 2M - 1, 
  E.g. cannot have 5-hook filled with 9, since 9 > 7. 
- *H(M, N)*: hook of length M filled with digit N, N times. 
  (this doesn't say anything about the position). 
- *O*: the orientation of a hook. 
  This is based off the direction of the point of the hook. 
  (1) Up left, (2) up right, (3) down left, (4) down right. 


## Programming way? 

Brute force I think is out of the question. 
We can try to use constraints to get it? 

Things that we already have from the start 
(or at least can get): 
- Total digits on the board (9*10/2=45). Needed for paths. 
- Possible orientations of hooks (4^8=65,536). 
- Universe of valid paths/regions of filled squares (how to get this? iterate through grid?). 
- Knowing that certain digits cannot be used in small hooks (e.g. H(4, 9) is invalid). 
  Special case: the 1 hook always has to have 1 in it. 
- The valid combinations of hooks and digits to use. 
  Can think of as a set of ordered pairs. 

Just loop through all combinations of constraints. 
Maybe we can be smarter for choosing paths, or checking gcd as we put paths. 
Putting paths seems to be the toughest. 

Can we have constraint on where path has to be? 
I don't think so, since smaller paths can be anywhere. 


## Data structures 

We need a way to represent the following: 
- The grid (for checking gcd). 
- A path (within grid?). 
- The hooks (can be a combo of O/M/N). 
  We need a function to return the valid indices/locations for a hook given the previous ones. 

My thinking is that we will have *overlap* between two things: 
the fill path and hooks. 
And then have to check that against GCD values. 

Features we want: 
- Checking gcd of rows/columns concatenation (so string concatenation, and this depends on each digit). 
- Overlap of OMN vs path (can loop through each to see if counts are correct). 

### Grid 

In general, grid can be a 9*9=81 length array. 
Depending on what context we are using it in, values could be different: 
- Paths: could be booleans, or bytes. 
- 

### OMN indices 

H(O, M, N) will have 2M - 1 indices, so can return array? or vector probably, needs to be dynamic. 
These coordinates are "Markovian" in the sense that they depend on previous. 
E.g. if we have H(0, 9, .), so the corner is at (0,0), then: 
- H(0, 8, .) will have corner at (1, 1). 
- H(1, 8, .) will have corner at (8, 1). 
- H(2, 8, .) will have corner at (1, 8). 
- H(3, 8, .) will have corner at (8, 8). 
I don't think there will be a closed form formula? 
But we just need to know coordinates and orientation H(O, M, .) to get coordinates of H(., M-1, .). 




## Pseudo code 

```python
for fp in fill_paths: # all valid paths we get from doing dfs 
    # read in fp 
    for hk in hooks: # all OMN combinations, about 65k of them 
```