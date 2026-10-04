
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004a4769(int *param_1,int param_2)

{
  float fVar1;
  
  fVar1 = 0.0;
  if (param_2 == 0) {
    fVar1 = _DAT_006686d8 * (float)_DAT_00668348;
    goto LAB_004a47ad;
  }
  if (param_2 != 1) {
    if (param_2 == 2) {
      fVar1 = _DAT_006686d8 * (float)_DAT_00668710;
      goto LAB_004a47ad;
    }
    if (param_2 != 3) goto LAB_004a47ad;
  }
  fVar1 = _DAT_006686d8 * (float)_DAT_00667ac8;
LAB_004a47ad:
  param_1[0x11] = (int)fVar1;
  (**(code **)(*param_1 + 0xc))();
  return;
}

