
uint FUN_0049f1f4(uint param_1)

{
  return ((param_1 >> 3 & 0x1f0000 | param_1 & 0xf800) >> 3 | param_1 & 0xf8) >> 3;
}

