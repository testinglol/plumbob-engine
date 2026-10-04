
float10 __fastcall FUN_00524386(int param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  int local_18;
  int local_14;
  uint local_10;
  int local_c;
  uint local_8;
  
  iVar7 = *(int *)(param_1 + 0xe4);
  if ((iVar7 == 0) || (*(int *)(iVar7 + 0x50) == *(int *)(iVar7 + 0x4c))) {
    iVar7 = FUN_00524b9b();
    if (iVar7 == 0) {
      iVar7 = 100;
    }
  }
  else {
    iVar8 = *(int *)(iVar7 + 0x84);
    iVar7 = *(int *)(iVar7 + 0x7c);
    iVar3 = FUN_00524b9b();
    iVar7 = iVar3 + 0x12 + (iVar8 - iVar7);
  }
  local_10 = 0;
  iVar8 = 0;
  local_8 = 0;
  if (*(int *)(param_1 + 0xf8) - *(int *)(param_1 + 0xf4) >> 2 != 0) {
    piVar9 = *(int **)(param_1 + 0xf4);
    do {
      iVar3 = *piVar9;
      piVar4 = (int *)(iVar3 + 0x7c);
      iVar8 = iVar8 + 0x1e + (*(int *)(iVar3 + 0x84) - *piVar4);
      if ((int)local_10 < *(int *)(iVar3 + 0x84) - *piVar4) {
        local_10 = *(int *)(iVar3 + 0x84) - *piVar4;
      }
      local_8 = local_8 + 1;
      piVar9 = piVar9 + 1;
    } while (local_8 < (uint)(*(int *)(param_1 + 0xf8) - *(int *)(param_1 + 0xf4) >> 2));
  }
  if (iVar7 < iVar8) {
    iVar7 = iVar8;
  }
  FUN_00524b60(&local_18);
  if (*(int *)(*(int *)(param_1 + 0xe8) + 0x84) - *(int *)(*(int *)(param_1 + 0xe8) + 0x7c) < iVar7)
  {
    FUN_004ec186(iVar7);
  }
  piVar9 = *(int **)(param_1 + 0xe4);
  if ((piVar9 == (int *)0x0) || (piVar9[0x14] == piVar9[0x13])) {
    iVar7 = local_14 + 9;
  }
  else {
    (**(code **)(*piVar9 + 0x94))();
    uVar5 = (**(code **)(**(int **)(*(int *)(param_1 + 0xe4) + 0xd8) + 0x58))();
    FUN_004ec1a7(uVar5);
    cVar2 = FUN_005a5e72();
    if (cVar2 == '\0') {
      iVar8 = local_14 + 9;
      iVar7 = (((*(int *)(param_1 + 0x84) - *(int *)(*(int *)(param_1 + 0xe4) + 0x84)) -
               *(int *)(param_1 + 0x7c)) + *(int *)(*(int *)(param_1 + 0xe4) + 0x7c)) / 2;
    }
    else {
      iVar7 = *(int *)(*(int *)(param_1 + 0xe8) + 0xe8);
      iVar3 = *(int *)(*(int *)(param_1 + 0xe4) + 0x84);
      iVar1 = *(int *)(*(int *)(param_1 + 0xe4) + 0x7c);
      iVar8 = local_14 + 9;
      iVar6 = FUN_00524b9b(iVar8);
      iVar7 = (iVar7 - (iVar3 - iVar1)) / 2 + 0x12 + local_18 + iVar6;
    }
    FUN_004cb21d(iVar7,iVar8);
    iVar7 = *(int *)(*(int *)(param_1 + 0xe4) + 0x88) + 0x12;
  }
  FUN_004cb21d(local_18 + 9,iVar7);
  iVar8 = *(int *)(*(int *)(param_1 + 0xe8) + 0x88);
  iVar7 = iVar8 + 0x12;
  if (*(int *)(param_1 + 0xf0) != 0) {
    FUN_004ec1a7(0x24);
    FUN_004ec186(*(int *)(*(int *)(param_1 + 0xe8) + 0x84) -
                 *(int *)(*(int *)(param_1 + 0xe8) + 0x7c));
    FUN_004cb21d(*(undefined4 *)(*(int *)(param_1 + 0xe8) + 0x7c),
                 *(int *)(*(int *)(param_1 + 0xe8) + 0x88) + 9);
    iVar7 = iVar8 + 0x24 +
            (*(int *)(*(int *)(param_1 + 0xf0) + 0x88) - *(int *)(*(int *)(param_1 + 0xf0) + 0x80));
  }
  if ((*(int *)(param_1 + 0xf8) - *(int *)(param_1 + 0xf4) & 0xfffffffcU) != 0) {
    local_c = 0;
    local_8 = 0;
    if (*(int *)(param_1 + 0xf8) - *(int *)(param_1 + 0xf4) >> 2 != 0) {
      piVar9 = *(int **)(param_1 + 0xf4);
      local_10 = *(int *)(param_1 + 0xf8) - *(int *)(param_1 + 0xf4) >> 2;
      do {
        iVar8 = *piVar9;
        piVar9 = piVar9 + 1;
        local_c = local_c + (*(int *)(iVar8 + 0x84) - *(int *)(iVar8 + 0x7c));
        local_8 = local_8 + 1;
      } while (local_8 < local_10);
    }
    uVar10 = 0;
    local_8 = (uint)((*(int *)(*(int *)(param_1 + 0xe8) + 0x84) -
                     *(int *)(*(int *)(param_1 + 0xe8) + 0x7c)) - local_c) /
              ((*(int *)(param_1 + 0xf8) - *(int *)(param_1 + 0xf4) >> 2) + 1U);
    if ((int)local_8 < 0) {
      local_8 = 9;
    }
    local_c = 0;
    if (*(int *)(param_1 + 0xf8) - *(int *)(param_1 + 0xf4) >> 2 != 0) {
      local_10 = local_8;
      do {
        FUN_004cb21d(local_10 + local_c + 9 + local_18,iVar7);
        iVar8 = *(int *)(*(int *)(param_1 + 0xf4) + uVar10 * 4);
        local_10 = local_10 + local_8;
        local_c = local_c + (*(int *)(iVar8 + 0x84) - *(int *)(iVar8 + 0x7c));
        uVar10 = uVar10 + 1;
      } while (uVar10 < (uint)(*(int *)(param_1 + 0xf8) - *(int *)(param_1 + 0xf4) >> 2));
    }
    iVar7 = iVar7 + 9 +
            (*(int *)(**(int **)(param_1 + 0xf4) + 0x88) -
            *(int *)(**(int **)(param_1 + 0xf4) + 0x80));
  }
  FUN_004cb1a2((*(int *)(*(int *)(param_1 + 0xe8) + 0x84) + 0x12 + local_18 * 2) -
               *(int *)(*(int *)(param_1 + 0xe8) + 0x7c),iVar7 + local_14);
  return (float10)(*(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x7c)) /
         (float10)(*(int *)(param_1 + 0x88) - *(int *)(param_1 + 0x80));
}

