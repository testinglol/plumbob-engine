
uint FUN_00636918(int param_1)

{
  uint uVar1;
  
  if (1 < DAT_006dae24) {
    uVar1 = FUN_0063cdac(param_1,8);
    return uVar1;
  }
  return (byte)PTR_DAT_006dac18[param_1 * 2] & 8;
}

