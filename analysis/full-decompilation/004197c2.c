
undefined4 __fastcall FUN_004197c2(int *param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined1 local_118 [4];
  undefined4 local_114;
  short local_110;
  undefined4 local_8;
  
  FUN_00405584(param_1[10]);
  FUN_006321f0(param_1[10]);
  param_1[10] = 0;
  if (local_110 == 0) {
    uVar2 = 0xffffffce;
  }
  else {
    FUN_005b8e25();
    uVar1 = FUN_005b9ab8(local_114);
    local_8 = CONCAT31(local_8._1_3_,uVar1);
    uVar2 = (**(code **)(*param_1 + 0xc))(local_118,local_8);
    param_1[7] = 0;
  }
  return uVar2;
}

