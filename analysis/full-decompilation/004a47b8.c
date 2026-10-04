
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004a47b8(int *param_1)

{
  float fVar1;
  
  fVar1 = (float)param_1[0x11] + (float)_DAT_00668348;
  param_1[0x11] = (int)fVar1;
  if (_DAT_006686d8 + _DAT_006686d8 < fVar1) {
    param_1[0x11] = (int)(fVar1 - (_DAT_006686d8 + _DAT_006686d8));
  }
                    /* WARNING: Could not recover jumptable at 0x004a47e2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0xc))();
  return;
}

