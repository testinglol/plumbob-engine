
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00472b1d(int param_1,undefined4 *param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = FUN_004728e9(param_2);
  if (iVar2 != 0) {
    iVar3 = (**(code **)*param_2)();
    fVar1 = (float)iVar2 / (float)iVar3;
    if (((ABS(fVar1 - *(float *)(param_1 + 0x18)) <= (float)_DAT_00667878) &&
        (*(int *)(param_1 + 0x1c) < iVar2)) || (*(float *)(param_1 + 0x18) < fVar1)) {
      *(float *)(param_1 + 0x18) = fVar1;
      *(int *)(param_1 + 0x1c) = iVar2;
      FUN_0046f8e4(param_2);
    }
  }
  return;
}

