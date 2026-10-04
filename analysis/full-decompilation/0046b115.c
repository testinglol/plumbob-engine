
undefined4 FUN_0046b115(undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined1 local_444 [272];
  undefined **local_334 [2];
  short local_32c;
  undefined1 local_328 [260];
  undefined **local_224 [2];
  short local_21c;
  undefined1 local_218 [260];
  undefined **local_114 [3];
  undefined1 local_108 [260];
  
  if (((*param_2 == 0) || (iVar1 = (**(code **)param_2[1])(), iVar1 < 2)) ||
     (*(char *)param_2[2] != '.')) {
    return 0;
  }
  FUN_0046b8c5(param_2 + 1);
  FUN_0046f824(local_328,0,0x104);
  local_334[0] = &PTR_FUN_006664e8;
  FUN_0046f824(local_108,0,0x104);
  local_114[0] = &PTR_FUN_006664e8;
  FUN_00412209(param_1,local_114,local_334);
  if (local_32c == 0) {
    FUN_0046f824(local_218,0,0x104);
    local_224[0] = &PTR_FUN_006664e8;
    FUN_0041218d(local_114,local_224);
    if (local_21c != 0) {
      FUN_0046f8e4(local_114);
      FUN_0046f917(local_444,0xffffffff);
      return 1;
    }
    return 0;
  }
  iVar1 = FUN_0046f973(local_444);
  if (iVar1 != 0) {
    return 0;
  }
  return 1;
}

