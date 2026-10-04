
uint FUN_0063f67d(uint param_1)

{
  uint uVar1;
  
  if (DAT_006dae24 < 2) {
    uVar1 = (byte)PTR_DAT_006dac18[param_1 * 2] & 4;
  }
  else {
    uVar1 = FUN_0063cdac(param_1,4);
  }
  if (uVar1 == 0) {
    param_1 = (param_1 & 0xffffffdf) - 7;
  }
  return param_1;
}

