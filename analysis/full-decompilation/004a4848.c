
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004a4848(int *param_1)

{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)param_1[0x12];
  fVar2 = (float)_DAT_00668718;
  param_1[0x12] = (int)(fVar1 + fVar2);
  if ((float)_DAT_00668308 < fVar1 + fVar2) {
    param_1[0x12] = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x004a4866. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0xc))();
  return;
}

