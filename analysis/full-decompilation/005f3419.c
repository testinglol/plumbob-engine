
void __thiscall FUN_005f3419(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  DWORD DVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (*(int *)(param_1 + 0x13c) == 2) {
    return;
  }
  if (((((param_2 == -1) && (*(int *)(param_1 + 0xd4) != 0)) ||
       (*(int *)(param_1 + 0x140) < *(int *)(param_1 + 0x144))) ||
      ((*(int *)(param_1 + 0xe4) != 0 &&
       (*(char *)(*(int *)(param_1 + 0xd4) + *(int *)(param_1 + 0xe4)) == ' ')))) ||
     (DVar3 = timeGetTime(), 2999 < DVar3 - *(int *)(param_1 + 0x180))) {
    FUN_005f4710();
  }
  uVar5 = 0;
  if (*(int *)(param_1 + 0x140) < *(int *)(param_1 + 0x144)) {
    FUN_005f4175(*(int *)(param_1 + 0x140));
    iVar1 = *(int *)(param_1 + 0x140);
    if (iVar1 == -1) {
      return;
    }
    FUN_00406466(iVar1,*(int *)(param_1 + 0x144) - iVar1);
    uVar2 = *(undefined4 *)(param_1 + 0x140);
    *(undefined1 *)(param_1 + 0x160) = 1;
    *(undefined4 *)(param_1 + 0xd4) = uVar2;
    FUN_005f371b(uVar2,uVar2);
  }
  else if (param_2 == -1) {
    if (0 < *(int *)(param_1 + 0xd4)) {
      FUN_005f2c6c(0xffffffff,0,1);
      FUN_005f3419(0);
    }
  }
  else if ((param_2 == 0) &&
          (*(int *)(param_1 + 0xd4) < (*(int *)(param_1 + 0xe8) - *(int *)(param_1 + 0xe4)) + -1)) {
    iVar1 = **(int **)(param_1 + 0x114);
    iVar4 = FUN_004096c2(0xffffffff);
    uVar5 = (**(code **)(iVar1 + 0x44))(iVar4 + *(int *)(param_1 + 0xd4));
    FUN_00406466(*(undefined4 *)(param_1 + 0xd4),uVar5);
    uVar5 = *(undefined4 *)(param_1 + 0xd4);
    *(undefined1 *)(param_1 + 0x160) = 1;
  }
  if (*(int *)(param_1 + 0x48) != 0) {
    FUN_005da644(*(int *)(param_1 + 0x48),3,0x16,param_1,0);
  }
  FUN_005f3a06(uVar5);
  FUN_005f2c6c(0,0,1);
  FUN_005f37cd();
  return;
}

