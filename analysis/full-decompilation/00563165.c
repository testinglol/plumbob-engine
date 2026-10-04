
void __fastcall FUN_00563165(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int local_3c [2];
  int local_34;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_14;
  int local_10;
  int local_c;
  int *local_8;
  
  local_1c = param_1[0x1f];
  iVar3 = param_1[0x20];
  local_14 = param_1[0x21];
  local_10 = param_1[0x22];
  local_8 = (int *)FUN_005e40a5();
  if (local_8 != (int *)0x0) {
    iVar1 = *local_8;
    uVar2 = FUN_005d49d6();
    uVar2 = FUN_004096c2(uVar2);
    piVar4 = local_8;
    local_c = iVar1;
    (**(code **)(iVar1 + 0x50))(&local_2c,uVar2);
    iVar1 = *piVar4;
    uVar2 = FUN_005d49d6();
    uVar2 = FUN_004096c2(uVar2);
    (**(code **)(iVar1 + 0x50))(local_3c,uVar2);
    local_2c = (param_1[0x6e] - local_24) + -0xe + local_2c;
    iVar1 = param_1[0x66];
    local_34 = ((*(int *)(iVar1 + 0x1c) - local_3c[0]) - *(int *)(iVar1 + 0x14)) + param_1[0x6e] + 4
               + local_34;
    iVar6 = (local_20 - local_28) + 4;
    iVar5 = (*(int *)(iVar1 + 0x20) - *(int *)(iVar1 + 0x18)) + 4;
    if (iVar5 < iVar6) {
      iVar5 = iVar6;
    }
    param_1[0x70] = local_2c + 2;
    param_1[0x72] = local_2c + 2;
    param_1[0x71] = iVar3;
    param_1[0x73] = iVar3;
    param_1[0x72] = (*(int *)(iVar1 + 0x1c) - *(int *)(iVar1 + 0x14)) + 2 + param_1[0x6e];
    param_1[0x70] = param_1[0x70] - local_2c;
    param_1[0x71] = param_1[0x71] - iVar3;
    param_1[0x72] = param_1[0x72] - local_2c;
    param_1[0x73] = param_1[0x73] - iVar3;
    if (((local_2c != local_1c) || (local_34 != local_14)) || (iVar5 + iVar3 != local_10)) {
      FUN_005dda18(local_2c,iVar3,local_34,iVar5 + iVar3);
      if ((undefined4 *)param_1[0x67] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)param_1[0x67])(1);
      }
      param_1[0x67] = 0;
      iVar3 = (**(code **)(*param_1 + 0x18))();
      if (iVar3 != 0) {
        piVar4 = (int *)(**(code **)(*param_1 + 0x18))();
        (**(code **)(*piVar4 + 0x168))();
      }
    }
  }
  return;
}

