
int FUN_004a45de(ushort param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  return (((uVar1 & 0xf800) << 4 | uVar1 & 0x7c0) << 2 | uVar1 & 0x3f) << 2;
}

