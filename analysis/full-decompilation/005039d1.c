
void __fastcall FUN_005039d1(int param_1)

{
  undefined1 uVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  piVar2 = (int *)FUN_005e40a5();
  if (piVar2 != (int *)0x0) {
    local_c = (**(code **)(*piVar2 + 0x1c))();
    uVar1 = (**(code **)(*piVar2 + 0x28))(4);
    local_10 = CONCAT31(local_10._1_3_,uVar1);
    if (*(int *)(param_1 + 0x160) == 0) {
      iVar3 = (**(code **)(*piVar2 + 0x58))();
      local_14 = *(int *)(param_1 + 0x28);
      local_20 = *(int *)(param_1 + 0x1c);
      local_18 = *(int *)(param_1 + 0x24);
      local_1c = ((*(int *)(param_1 + 0x88) - *(int *)(param_1 + 0x80)) - iVar3) / 2 +
                 *(int *)(param_1 + 0x20);
    }
    else {
      local_20 = *(int *)(param_1 + 0x11c);
      local_1c = *(int *)(param_1 + 0x120);
      local_18 = *(int *)(param_1 + 0x124);
      local_14 = *(int *)(param_1 + 0x128);
      FUN_004ba5ac(param_1 + 0x1c);
    }
    if (*(int *)(param_1 + 0x17c) != 0) {
      FUN_004ba5ac(*(int *)(param_1 + 0x17c) + *(int *)(param_1 + 0xe8) * 8);
    }
    local_8 = 1;
    do {
      (**(code **)(*piVar2 + 0x2c))(4,*(undefined1 *)(param_1 + 0x170));
      if (local_8 == 1) {
        local_20 = local_20 + 1;
        local_18 = local_18 + 1;
        local_1c = local_1c + 1;
        local_14 = local_14 + 1;
        (**(code **)(*piVar2 + 0x20))(0);
      }
      else {
        iVar3 = *piVar2;
        uVar4 = FUN_005e416e(*(undefined4 *)(param_1 + 0xe8));
        (**(code **)(iVar3 + 0x20))(uVar4);
      }
      iVar3 = *piVar2;
      uVar4 = FUN_004096c2(*(int *)(param_1 + 0x50) - *(int *)(param_1 + 0x4c),
                           *(undefined4 *)(param_1 + 0x164));
      (**(code **)(iVar3 + 0x80))(*(undefined4 *)(param_1 + 0x5c),&local_20,uVar4);
      if (local_8 == 1) {
        local_20 = local_20 + -1;
        local_18 = local_18 + -1;
        local_1c = local_1c + -1;
        local_14 = local_14 + -1;
      }
      local_8 = local_8 + 1;
    } while (local_8 < 3);
    (**(code **)(*piVar2 + 0x20))(local_c);
    (**(code **)(*piVar2 + 0x2c))(4,local_10);
  }
  return;
}

