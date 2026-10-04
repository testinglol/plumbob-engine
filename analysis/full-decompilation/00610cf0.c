
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00610cf0(undefined4 param_1,undefined4 param_2,int param_3)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_00610c90(param_1,param_2);
  if (fVar1 * (float10)_DAT_00677588 < (float10)param_3 * (float10)_DAT_00677580) {
    return 1;
  }
  return 0;
}

