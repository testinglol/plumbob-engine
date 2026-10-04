
uint FUN_004a4558(uint param_1)

{
  return ((param_1 >> 3 & 0x1f0000 | param_1 & 0xf800) >> 3 | param_1 & 0xfc) >> 2;
}

