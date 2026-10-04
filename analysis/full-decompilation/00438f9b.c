
int FUN_00438f9b(ushort param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  return (((uVar1 & 0xf800) << 3 | uVar1 & 0x7e0) << 2 | uVar1 & 0x1f) << 3;
}

