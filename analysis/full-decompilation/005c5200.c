
void __thiscall FUN_005c5200(int *param_1,undefined1 *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 local_68 [12];
  undefined1 local_5c [12];
  undefined4 local_50;
  undefined1 local_4c [12];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
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
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006613b8;
  local_10 = ExceptionList;
  local_14 = &stack0xffffff8c;
  iVar2 = param_1[1];
  if (iVar2 != param_1[2]) {
    ExceptionList = &local_10;
    local_14 = &stack0xffffff8c;
    if (iVar2 != 0) {
      ExceptionList = &local_10;
      local_14 = &stack0xffffff8c;
      FUN_005c5180(iVar2 + -0x48);
    }
    param_1[1] = param_1[1] + 0x48;
    FUN_00462be8(param_3);
    FUN_00462be8(param_3 + 0xc);
    local_50 = *(undefined4 *)(param_3 + 0x18);
    FUN_00462be8(param_3 + 0x1c);
    local_40 = *(undefined4 *)(param_3 + 0x28);
    local_3c = *(undefined4 *)(param_3 + 0x2c);
    local_38 = *(undefined4 *)(param_3 + 0x30);
    local_34 = *(undefined4 *)(param_3 + 0x34);
    local_30 = *(undefined4 *)(param_3 + 0x38);
    local_2c = *(undefined4 *)(param_3 + 0x3c);
    local_28 = *(undefined4 *)(param_3 + 0x40);
    local_24 = *(undefined4 *)(param_3 + 0x44);
    local_8 = 0;
    FUN_005c5500(param_2,param_1[1] + -0x90,param_1[1] + -0x48,param_2,0);
    if (param_2 != local_68) {
      FUN_00462be8(local_68);
      FUN_00462be8(local_5c);
      *(undefined4 *)(param_2 + 0x18) = local_50;
      FUN_00462be8(local_4c);
      *(undefined4 *)(param_2 + 0x28) = local_40;
      *(undefined4 *)(param_2 + 0x2c) = local_3c;
      *(undefined4 *)(param_2 + 0x30) = local_38;
      *(undefined4 *)(param_2 + 0x34) = local_34;
      *(undefined4 *)(param_2 + 0x38) = local_30;
      *(undefined4 *)(param_2 + 0x3c) = local_2c;
      *(undefined4 *)(param_2 + 0x40) = local_28;
      *(undefined4 *)(param_2 + 0x44) = local_24;
    }
    ExceptionList = local_10;
    return;
  }
  local_18 = (iVar2 - *param_1) / 0x48;
  if (local_18 == 0) {
    local_18 = 1;
  }
  else {
    local_18 = local_18 * 2;
    if (local_18 == 0) {
      local_1c = 0;
      ExceptionList = &local_10;
      local_14 = &stack0xffffff8c;
      goto LAB_005c5381;
    }
  }
  ExceptionList = &local_10;
  local_1c = FUN_00401742(local_18 * 0x48);
LAB_005c5381:
  local_8 = 1;
  local_20 = local_1c;
  iVar2 = FUN_005c55c0(*param_1,param_2,local_1c,param_2);
  FUN_005c5480(iVar2,param_3);
  iVar3 = FUN_005c55c0(param_2,param_1[1],iVar2 + 0x48,param_2);
  for (iVar2 = *param_1; iVar2 != param_1[1]; iVar2 = iVar2 + 0x48) {
  }
  piVar1 = (int *)*param_1;
  iVar2 = (param_1[2] - (int)piVar1) / 0x48;
  if (iVar2 != 0) {
    uVar4 = iVar2 * 0x48;
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
  *param_1 = local_1c;
  param_1[1] = iVar3;
  param_1[2] = local_1c + local_18 * 0x48;
  ExceptionList = local_10;
  return;
}

