##
## PivotRoot Test
##

assert("PivotRoot#hello") do
  t = PivotRoot.new "hello"
  assert_equal("hello", t.hello)
end

assert("PivotRoot#bye") do
  t = PivotRoot.new "hello"
  assert_equal("hello bye", t.bye)
end

assert("PivotRoot.hi") do
  assert_equal("hi!!", PivotRoot.hi)
end
