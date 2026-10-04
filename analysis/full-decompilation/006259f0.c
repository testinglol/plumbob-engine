
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1
FUN_006259f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            byte param_5,undefined1 param_6)

{
  undefined4 uVar1;
  undefined1 uVar2;
  float10 extraout_ST0;
  float10 fVar3;
  byte local_18 [8];
  undefined1 local_10 [8];
  undefined1 local_8 [8];
  
  uVar1 = param_4;
  FUN_00625c10(param_1,param_2,param_3,param_4,local_18,local_8,FUN_00625820);
  FUN_00625c10(param_1,param_2,param_3,uVar1,&param_4,local_10,FUN_00625bd0);
  uVar2 = __ftol();
  param_4 = CONCAT13(uVar2,(undefined3)param_4);
  uVar2 = __ftol();
  param_4._0_3_ = CONCAT12(uVar2,(undefined2)param_4);
  uVar2 = __ftol();
  param_4._0_2_ = CONCAT11(uVar2,(undefined1)param_4);
  fVar3 = (float10)param_5 - (float10)local_18[0] * extraout_ST0;
  if ((fVar3 < (float10)_DAT_006683b0) && (fVar3 < (float10)_DAT_006669e8)) {
    uVar2 = __ftol();
    return uVar2;
  }
  uVar2 = __ftol();
  return uVar2;
}

