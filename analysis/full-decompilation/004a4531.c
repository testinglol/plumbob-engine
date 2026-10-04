
uint FUN_004a4531(uint param_1)

{
  return ((param_1 >> 2 & 0x3f0000 | param_1 & 0xf800) >> 2 | param_1 & 0xf8) >> 3;
}

