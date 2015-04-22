import _myrustlib

print(_myrustlib.triple(42))

_myrustlib.stack_push(42)
_myrustlib.stack_push(76)
_myrustlib.stack_push(4)
print(_myrustlib.stack_pull())
print(_myrustlib.stack_pull())
_myrustlib.stack_push(9)
print(_myrustlib.stack_pull())
print(_myrustlib.stack_pull())
print(_myrustlib.stack_pull())

