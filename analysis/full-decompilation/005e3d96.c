
void __fastcall FUN_005e3d96(int param_1)

{
  int *piVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 local_38 [4];
  int local_34;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  piVar1 = *(int **)(param_1 + 0x14c);
  if (piVar1 != (int *)0x0) {
    local_14 = (**(code **)(*piVar1 + 0x1c))();
    iVar4 = *piVar1;
    uVar3 = FUN_005e416e(*(undefined4 *)(param_1 + 0xe8));
    (**(code **)(iVar4 + 0x20))(uVar3);
    uVar2 = (**(code **)(*piVar1 + 0x28))(4);
    local_18 = CONCAT31(local_18._1_3_,uVar2);
    (**(code **)(*piVar1 + 0x2c))(4,*(undefined1 *)(param_1 + 0x170));
    if (*(int *)(param_1 + 0x160) == 0) {
      (**(code **)(*piVar1 + 0x74))(0x41,local_38);
      local_28 = *(int *)(param_1 + 0x1c);
      local_20 = *(int *)(param_1 + 0x24);
      local_1c = *(undefined4 *)(param_1 + 0x28);
      local_24 = ((((*(int *)(param_1 + 0x88) - *(int *)(param_1 + 0x80)) - local_2c) + local_34) /
                  2 + *(int *)(param_1 + 0x20)) - local_34;
    }
    else {
      local_28 = *(int *)(param_1 + 0x11c);
      local_24 = *(int *)(param_1 + 0x120);
      local_20 = *(int *)(param_1 + 0x124);
      local_1c = *(undefined4 *)(param_1 + 0x128);
      FUN_004ba5ac(param_1 + 0x1c);
    }
    if (*(int *)(param_1 + 0x17c) != 0) {
      FUN_004ba5ac(*(int *)(param_1 + 0x17c) + *(int *)(param_1 + 0xe8) * 8);
    }
    if (*(char *)(param_1 + 0x173) == '\0') {
      if (*(int *)(param_1 + 0x164) == 1) {
        iVar4 = *piVar1;
        uVar3 = FUN_004096c2(*(int *)(param_1 + 0x50) - *(int *)(param_1 + 0x4c));
        iVar4 = (**(code **)(iVar4 + 0x68))(uVar3);
        local_28 = local_28 + ((local_20 - iVar4) - local_28) / 2;
      }
      else if (*(int *)(param_1 + 0x164) == 2) {
        iVar4 = *piVar1;
        uVar3 = FUN_004096c2(*(int *)(param_1 + 0x50) - *(int *)(param_1 + 0x4c));
        local_28 = (**(code **)(iVar4 + 0x68))(uVar3);
        local_28 = local_20 - local_28;
      }
      local_8 = local_24;
      local_c = local_28;
      local_10 = *(undefined4 *)(param_1 + 0x5c);
      iVar4 = *piVar1;
      uVar3 = FUN_005d49d6(0,0,0);
      uVar3 = FUN_004096c2(uVar3);
      (**(code **)(iVar4 + 0x78))(local_10,local_c,local_8,uVar3);
    }
    else {
      (**(code **)(*piVar1 + 0x80))
                (*(undefined4 *)(param_1 + 0x5c),&local_28,*(undefined4 *)(param_1 + 0x4c),
                 *(int *)(param_1 + 0x50) - *(int *)(param_1 + 0x4c),
                 *(undefined4 *)(param_1 + 0x164));
    }
    (**(code **)(*piVar1 + 0x20))(local_14);
    (**(code **)(*piVar1 + 0x2c))(4,local_18);
  }
  return;
}

