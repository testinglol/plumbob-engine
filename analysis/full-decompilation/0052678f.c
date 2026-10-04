
float10 __fastcall FUN_0052678f(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  int local_18;
  int local_14;
  uint local_10;
  int local_c;
  uint local_8;
  
  iVar6 = *(int *)(param_1 + 0xec);
  if ((iVar6 == 0) || (*(int *)(iVar6 + 0x50) == *(int *)(iVar6 + 0x4c))) {
    iVar6 = FUN_00526df4();
    if (iVar6 == 0) {
      iVar6 = 100;
    }
  }
  else {
    iVar7 = *(int *)(iVar6 + 0x84);
    iVar6 = *(int *)(iVar6 + 0x7c);
    iVar2 = FUN_00526df4();
    iVar6 = iVar2 + 0x12 + (iVar7 - iVar6);
  }
  local_10 = 0;
  iVar7 = 0;
  local_8 = 0;
  if (*(int *)(param_1 + 0xf8) - *(int *)(param_1 + 0xf4) >> 2 != 0) {
    piVar8 = *(int **)(param_1 + 0xf4);
    do {
      iVar2 = *piVar8;
      piVar3 = (int *)(iVar2 + 0x7c);
      iVar7 = iVar7 + 0x1e + (*(int *)(iVar2 + 0x84) - *piVar3);
      if ((int)local_10 < *(int *)(iVar2 + 0x84) - *piVar3) {
        local_10 = *(int *)(iVar2 + 0x84) - *piVar3;
      }
      local_8 = local_8 + 1;
      piVar8 = piVar8 + 1;
    } while (local_8 < (uint)(*(int *)(param_1 + 0xf8) - *(int *)(param_1 + 0xf4) >> 2));
  }
  if (iVar6 < iVar7) {
    iVar6 = iVar7;
  }
  FUN_00524b60(&local_18);
  if (*(int *)(*(int *)(param_1 + 0xf0) + 0x84) - *(int *)(*(int *)(param_1 + 0xf0) + 0x7c) < iVar6)
  {
    FUN_004ec186(iVar6);
  }
  piVar8 = *(int **)(param_1 + 0xec);
  if ((piVar8 == (int *)0x0) || (piVar8[0x14] == piVar8[0x13])) {
    iVar6 = local_14 + 9;
  }
  else {
    (**(code **)(*piVar8 + 0x94))();
    uVar4 = (**(code **)(**(int **)(*(int *)(param_1 + 0xec) + 0xd8) + 0x58))();
    FUN_004ec1a7(uVar4);
    if (*(int *)(param_1 + 0x100) == 0) {
      iVar7 = local_14 + 9;
      iVar6 = (((*(int *)(param_1 + 0x84) - *(int *)(*(int *)(param_1 + 0xec) + 0x84)) -
               *(int *)(param_1 + 0x7c)) + *(int *)(*(int *)(param_1 + 0xec) + 0x7c)) / 2;
    }
    else {
      iVar6 = *(int *)(*(int *)(param_1 + 0xf0) + 0xe8);
      iVar2 = *(int *)(*(int *)(param_1 + 0xec) + 0x84);
      iVar1 = *(int *)(*(int *)(param_1 + 0xec) + 0x7c);
      iVar7 = local_14 + 9;
      iVar5 = FUN_00526df4(iVar7);
      iVar6 = (iVar6 - (iVar2 - iVar1)) / 2 + 0x12 + local_18 + iVar5;
    }
    FUN_004cb21d(iVar6,iVar7);
    iVar6 = *(int *)(*(int *)(param_1 + 0xec) + 0x88) + 0x12;
  }
  FUN_004cb21d(local_18 + 9,iVar6);
  iVar7 = *(int *)(param_1 + 0xf0);
  iVar2 = *(int *)(iVar7 + 0x88);
  iVar6 = iVar2 + 0x12;
  if ((*(int *)(param_1 + 0xf8) - *(int *)(param_1 + 0xf4) & 0xfffffffcU) != 0) {
    local_c = 0;
    local_8 = 0;
    if (*(int *)(param_1 + 0xf8) - *(int *)(param_1 + 0xf4) >> 2 != 0) {
      piVar8 = *(int **)(param_1 + 0xf4);
      local_10 = *(int *)(param_1 + 0xf8) - *(int *)(param_1 + 0xf4) >> 2;
      do {
        iVar1 = *piVar8;
        piVar8 = piVar8 + 1;
        local_c = local_c + (*(int *)(iVar1 + 0x84) - *(int *)(iVar1 + 0x7c));
        local_8 = local_8 + 1;
      } while (local_8 < local_10);
    }
    uVar9 = 0;
    local_8 = (uint)((*(int *)(iVar7 + 0x84) - *(int *)(iVar7 + 0x7c)) - local_c) /
              ((*(int *)(param_1 + 0xf8) - *(int *)(param_1 + 0xf4) >> 2) + 1U);
    if ((int)local_8 < 0) {
      local_8 = 9;
    }
    local_c = 0;
    if (*(int *)(param_1 + 0xf8) - *(int *)(param_1 + 0xf4) >> 2 != 0) {
      local_10 = local_8;
      do {
        FUN_004cb21d(local_10 + local_c + 9 + local_18,iVar6);
        iVar7 = *(int *)(*(int *)(param_1 + 0xf4) + uVar9 * 4);
        local_10 = local_10 + local_8;
        local_c = local_c + (*(int *)(iVar7 + 0x84) - *(int *)(iVar7 + 0x7c));
        uVar9 = uVar9 + 1;
      } while (uVar9 < (uint)(*(int *)(param_1 + 0xf8) - *(int *)(param_1 + 0xf4) >> 2));
    }
    iVar6 = iVar2 + 0x1b +
            (*(int *)(**(int **)(param_1 + 0xf4) + 0x88) -
            *(int *)(**(int **)(param_1 + 0xf4) + 0x80));
  }
  FUN_004cb1a2((*(int *)(*(int *)(param_1 + 0xf0) + 0x84) + 0x12 + local_18 * 2) -
               *(int *)(*(int *)(param_1 + 0xf0) + 0x7c),iVar6 + 0x1e + local_14);
  return (float10)(*(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x7c)) /
         (float10)(*(int *)(param_1 + 0x88) - *(int *)(param_1 + 0x80));
}

