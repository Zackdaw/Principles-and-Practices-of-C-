/*
Since this question is more of a theoretical question rather than a coding demonstration, I will answer in comments.
Yes, it is possible to have non-pointer const arguments, however this makes a minimal impact. The reasoning is that
the argument will be providing a copy of the variable anyway, so changing it will only impact the function and it should
be small enough in scope to avoid accidentally doing so. 
*/