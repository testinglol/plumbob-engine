
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_004340f2(int param_1,float param_2)

{
  float fVar1;
  int iVar2;
  undefined1 local_34 [4];
  undefined4 local_30;
  undefined4 local_2c;
  short local_24;
  undefined1 local_1c [4];
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  
  iVar2 = (int)param_2;
  fVar1 = _DAT_0066657c;
  if ((-1 < (int)param_2) &&
     ((int)param_2 < (*(int *)(param_1 + 0x134) - *(int *)(param_1 + 0x130)) / 0x24 + -1)) {
    param_2 = 0.0;
    while (fVar1 = param_2, param_1 != 0) {
      if ((iVar2 < 0) ||
         ((*(int *)(param_1 + 0x134) - *(int *)(param_1 + 0x130)) / 0x24 + -1 <= iVar2)) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(param_1 + 0x130) + (iVar2 * 9 + 9) * 4;
      }
      if (iVar2 != 0) {
        param_2 = param_2 + *(float *)(iVar2 + 8);
      }
      local_18 = 0;
      local_14 = 0;
      FUN_00432664(local_1c);
      param_1 = local_10;
      local_30 = 0;
      local_2c = 0;
      FUN_00432664(local_34);
      iVar2 = (int)local_24;
    }
  }
  return (float10)fVar1;
}

