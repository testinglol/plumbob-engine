
void __thiscall FUN_005c6980(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puVar2 = param_2;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00661472;
  local_10 = ExceptionList;
  local_14 = &stack0xffffffc4;
  local_20 = param_1[1];
  if (local_20 != param_1[2]) {
    local_8 = 0;
    ExceptionList = &local_10;
    local_1c = local_20;
    local_14 = &stack0xffffffc4;
    if (local_20 != 0) {
      ExceptionList = &local_10;
      local_14 = &stack0xffffffc4;
      FUN_005c6bc0(local_20 + -0x10);
    }
    iVar5 = param_1[1];
    param_1[1] = iVar5 + 0x10;
    local_30 = *param_3;
    local_2c = param_3[1];
    local_28 = param_3[2];
    local_24 = param_3[3];
    iVar5 = iVar5 + -0x10;
    local_8 = 0xffffffff;
    param_2 = (undefined4 *)(iVar5 - (int)param_2 >> 4);
    if (0 < (int)param_2) {
      do {
        iVar5 = iVar5 + -0x10;
        FUN_005c6be0(iVar5);
        param_2 = (undefined4 *)((int)param_2 + -1);
      } while (param_2 != (undefined4 *)0x0);
    }
    if (&local_30 != puVar2) {
      *puVar2 = local_30;
      puVar2[1] = local_2c;
      puVar2[2] = local_28;
      puVar2[3] = local_24;
    }
    ExceptionList = local_10;
    return;
  }
  local_1c = local_20 - *param_1 >> 4;
  if (local_1c == 0) {
    local_1c = 1;
  }
  else {
    local_1c = local_1c * 2;
    if (local_1c == 0) {
      local_18 = 0;
      ExceptionList = &local_10;
      local_14 = &stack0xffffffc4;
      goto LAB_005c6a8a;
    }
  }
  ExceptionList = &local_10;
  local_18 = FUN_00401742(local_1c << 4);
LAB_005c6a8a:
  local_8 = 1;
  local_20 = local_18;
  iVar5 = FUN_005c71c0(*param_1,param_2,local_18,param_2);
  local_8._0_1_ = 2;
  local_20 = iVar5;
  if (iVar5 != 0) {
    FUN_005c6bc0(param_3);
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar3 = FUN_005c71c0(param_2,param_1[1],iVar5 + 0x10,iVar5);
  for (iVar5 = *param_1; iVar5 != param_1[1]; iVar5 = iVar5 + 0x10) {
  }
  piVar1 = (int *)*param_1;
  iVar5 = param_1[2] - (int)piVar1 >> 4;
  if (iVar5 != 0) {
    uVar4 = iVar5 * 0x10;
    if (uVar4 < 0x81) {
      FUN_004017b8();
      *piVar1 = *(int *)(&DAT_006de560 + (uVar4 + 7 >> 3) * 4);
      *(int **)(&DAT_006de560 + (uVar4 + 7 >> 3) * 4) = piVar1;
      DAT_006de5a4 = 0;
    }
    else {
      FUN_00634ecc(piVar1);
    }
  }
  param_1[1] = iVar3;
  *param_1 = local_18;
  param_1[2] = local_1c * 0x10 + local_18;
  ExceptionList = local_10;
  return;
}

