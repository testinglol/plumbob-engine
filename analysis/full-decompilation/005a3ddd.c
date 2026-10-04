
undefined4 FUN_005a3ddd(undefined4 param_1,int param_2,undefined4 param_3,int *param_4)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined **local_12c [3];
  undefined1 local_120 [260];
  int local_1c;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined1 local_8;
  
  local_c = param_1;
  *param_4 = 0;
  local_8 = (undefined1)param_2;
  FUN_005a3f6a(&local_14,&local_c);
  if (local_14 == 0) {
    if (param_2 != 0) {
      local_8 = 0;
      FUN_005a3f6a(&local_1c,&local_c);
      local_14 = local_1c;
      local_10 = local_18;
      if (local_1c != 0) goto LAB_005a3e3b;
    }
    uVar3 = 0;
  }
  else {
LAB_005a3e3b:
    iVar2 = local_14;
    uVar3 = *(undefined4 *)(local_14 + 0xc);
    FUN_0046f824(local_120,0,0x104);
    local_12c[0] = &PTR_FUN_006664e8;
    FUN_0046f847(uVar3,0xffffffff);
    FUN_0046f8e4(local_12c);
    cVar1 = *(char *)(iVar2 + 0x18);
    *param_4 = (int)cVar1;
    uVar3 = CONCAT31(cVar1 >> 7,1);
  }
  return uVar3;
}

