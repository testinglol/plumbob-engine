
undefined4 __fastcall FUN_00535213(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (*(int *)(param_1 + 0xdc) == 0) {
    *(undefined4 *)(param_1 + 0xdc) = DAT_006f2aa4;
  }
  piVar1 = *(int **)(param_1 + 0xdc);
  if (*(int *)(param_1 + 0x5c) == 0) {
    return 1;
  }
  if (piVar1 == (int *)0x0) {
    return 1;
  }
  if (0 < *(int *)(param_1 + 0xf0)) {
    local_14 = *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0xe0);
    local_10 = *(int *)(param_1 + 0x20) + *(int *)(param_1 + 0xe4);
    iVar2 = (**(code **)(*piVar1 + 0x58))();
    local_c = *(int *)(param_1 + 0xe8) + local_14;
    local_8 = iVar2 * *(int *)(param_1 + 0xf0) + local_10;
    (**(code **)(*piVar1 + 0x80))
              (*(undefined4 *)(param_1 + 0x5c),&local_14,*(undefined4 *)(param_1 + 0x4c),
               *(undefined4 *)(param_1 + 0xec),0);
  }
  if (0 < *(int *)(param_1 + 0x100)) {
    if ((*(int *)(param_1 + 0x100) == 1) &&
       (iVar2 = (**(code **)(*piVar1 + 0x68))
                          (*(int *)(param_1 + 0xec) + *(int *)(param_1 + 0x4c),
                           (*(int *)(param_1 + 0x50) - *(int *)(param_1 + 0x4c)) -
                           *(int *)(param_1 + 0xec)), iVar2 <= *(int *)(param_1 + 0xe8))) {
      iVar2 = (**(code **)(*piVar1 + 0x58))();
      local_14 = *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0xe0);
      local_10 = iVar2 * *(int *)(param_1 + 0xf0) +
                 *(int *)(param_1 + 0xe4) + *(int *)(param_1 + 0x20);
      local_8 = (**(code **)(*piVar1 + 0x58))();
      local_c = *(int *)(param_1 + 0xe8) + local_14;
      local_8 = local_8 + local_10;
      iVar2 = *piVar1;
      iVar3 = *(int *)(param_1 + 0xec);
      iVar4 = (*(int *)(param_1 + 0x50) - *(int *)(param_1 + 0x4c)) - iVar3;
    }
    else {
      local_10 = *(int *)(param_1 + 0x20) + *(int *)(param_1 + 0xf8);
      local_14 = *(int *)(param_1 + 0xf4) + *(int *)(param_1 + 0x1c);
      iVar2 = (**(code **)(**(int **)(param_1 + 0xdc) + 0x58))();
      local_c = *(int *)(param_1 + 0xfc) + local_14;
      local_8 = iVar2 * *(int *)(param_1 + 0x100) + local_10;
      iVar2 = *piVar1;
      iVar3 = *(int *)(param_1 + 0xec);
      iVar4 = (*(int *)(param_1 + 0x50) - iVar3) - *(int *)(param_1 + 0x4c);
    }
    (**(code **)(iVar2 + 0x80))
              (*(undefined4 *)(param_1 + 0x5c),&local_14,*(int *)(param_1 + 0x4c) + iVar3,iVar4,0);
    return 1;
  }
  return 1;
}

