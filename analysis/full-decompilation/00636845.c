
uint FUN_00636845(int param_1)

{
  uint uVar1;
  
  if (1 < DAT_006dae24) {
    uVar1 = FUN_0063cdac(param_1,0x103);
    return uVar1;
  }
  return *(ushort *)(PTR_DAT_006dac18 + param_1 * 2) & 0x103;
}

