##
## PivotRoot Test
##

assert("PivotRoot#hello") do
  t = PivotRoot
  assert_equal(Module, t.class)
end
