
int FUN_005b7480(int param_1)

{
  int iVar1;
  uint local_4;
  
  if (DAT_006fd7d8 == 0) {
    DAT_006fd7d8 = FUN_005b6760();
  }
  iVar1 = DAT_006fd7d0;
  if (DAT_006fd7d0 == 0) {
    local_4 = param_1 * 0xc;
    DAT_006fd7d0 = FUN_0064a380(&local_4);
    iVar1 = 0;
    if (DAT_006fd7d0 != 0) {
      FUN_005a9250(DAT_006fd7d0,0,local_4);
      iVar1 = local_4 * -0x55555555;
      DAT_006fd7d4 = local_4 / 0xc;
    }
  }
  return iVar1;
}

