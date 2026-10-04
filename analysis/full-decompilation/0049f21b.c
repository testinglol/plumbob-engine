
uint FUN_0049f21b(uint param_1)

{
  return ((param_1 >> 3 & 0x1f0000 | param_1 & 0xfc00) >> 2 | param_1 & 0xf8) >> 3;
}

