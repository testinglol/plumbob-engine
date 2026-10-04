
int FUN_004a45b9(ushort param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  return (((uVar1 & 0xfc00) << 2 | uVar1 & 0x3e0) << 3 | uVar1 & 0x1f) << 3;
}

