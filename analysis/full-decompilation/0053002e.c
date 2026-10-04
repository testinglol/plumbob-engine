
void __fastcall FUN_0053002e(int param_1)

{
  char *pcVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  size_t sVar5;
  undefined4 uVar6;
  int iVar7;
  int local_20 [4];
  int *local_10;
  int local_c;
  char *local_8;
  
  piVar2 = (int *)FUN_005e40a5();
  if (piVar2 == (int *)0x0) {
    return;
  }
  local_10 = piVar2;
  iVar3 = (**(code **)(*piVar2 + 100))
                    (*(int *)(param_1 + 0x4c),*(int *)(param_1 + 0x50) - *(int *)(param_1 + 0x4c),
                     *(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x7c));
  if (iVar3 == 1) {
LAB_005300e0:
    FUN_005e3d96();
  }
  else {
    local_8 = *(char **)(param_1 + 0x4c);
    local_20[0] = 0;
    local_20[1] = 0;
    iVar7 = local_c;
    if (0 < iVar3) {
      iVar7 = iVar3 * -4;
      local_c = iVar3;
      do {
        iVar3 = *piVar2;
        iVar4 = *(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x7c);
        sVar5 = _strlen(local_8);
        piVar2 = local_10;
        local_20[3] = iVar3;
        iVar4 = (**(code **)(iVar3 + 0x60))(local_8,sVar5,iVar4);
        pcVar1 = local_8;
        iVar3 = *piVar2;
        local_20[3] = iVar4;
        *(int *)((int)local_20 + iVar7) = iVar4;
        uVar6 = (**(code **)(iVar3 + 0x68))(pcVar1,iVar4);
        *(undefined4 *)((int)local_20 + iVar7 + 8) = uVar6;
        local_8 = local_8 + local_20[3];
        iVar7 = iVar7 + 4;
        local_c = local_c + -1;
      } while (local_c != 0);
      local_c = 0;
      iVar7 = 0;
      if (local_20[1] < local_20[0]) goto LAB_005300e0;
    }
    local_c = iVar7;
    piVar2 = DAT_006f2a90;
    local_20[2] = *(int *)(param_1 + 0x1c) + local_20[1];
    local_20[3] = *(int *)(param_1 + 0x20);
    (**(code **)(*DAT_006f2a90 + 0x1c))();
    iVar3 = *piVar2;
    uVar6 = FUN_005e416e(*(undefined4 *)(param_1 + 0xe8));
    (**(code **)(iVar3 + 0x20))(uVar6);
    iVar3 = local_20[2];
    (**(code **)(*piVar2 + 0x78))
              (*(undefined4 *)(param_1 + 0x5c),local_20[2] - local_20[0],local_20[3],
               *(undefined4 *)(param_1 + 0x4c),0,0,0,0);
    iVar7 = (**(code **)(*piVar2 + 0x58))();
    local_20[3] = local_20[3] + iVar7;
    (**(code **)(*piVar2 + 0x78))
              (*(undefined4 *)(param_1 + 0x5c),iVar3 - local_20[1],local_20[3],
               *(undefined4 *)(param_1 + 0x4c),0,0,0,0);
    iVar3 = *piVar2;
    uVar6 = FUN_005e416e(*(undefined4 *)(param_1 + 0xe8));
    (**(code **)(iVar3 + 0x20))(uVar6);
  }
  return;
}

