
void FUN_00402024(ushort *param_1)

{
  uint uVar1;
  
  FUN_00473102(param_1);
  uVar1 = *param_1 & 0x7fff;
  if ((*param_1 & 0x7fff) != 0) {
    do {
      param_1 = param_1 + 1;
      FUN_00473102(param_1);
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  return;
}

