
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00624c20(byte *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
                 ,undefined4 param_6)

{
  byte bVar1;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  int local_24;
  
  if (0 < param_2) {
    local_24 = param_2;
    do {
      fVar2 = (float10)FUN_00624d80((double)param_1[2] - _DAT_00678108,param_3,param_4);
      fVar3 = (float10)FUN_00624d80((double)param_1[1] - _DAT_00678108,param_3,param_4);
      fVar4 = (float10)FUN_00624d80((double)*param_1 - _DAT_00678108,param_3,param_4);
      FUN_00624d40((double)fVar2,param_5,param_6);
      FUN_00624d40((double)fVar3,param_5,param_6);
      bVar1 = __ftol();
      param_1[2] = bVar1;
      bVar1 = __ftol();
      param_1[1] = bVar1;
      FUN_00624d40((double)fVar4,param_5,param_6);
      bVar1 = __ftol();
      *param_1 = bVar1;
      param_1 = param_1 + 4;
      local_24 = local_24 + -1;
    } while (local_24 != 0);
  }
  return;
}

