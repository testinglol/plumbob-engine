
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0051e1a1(int param_1)

{
  short sVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int *piVar8;
  int local_18;
  int *local_14;
  int local_10;
  int local_c;
  
  FUN_004e99a9();
  iVar4 = FUN_004e9744();
  if (iVar4 == 0) {
    return;
  }
  cVar3 = FUN_004cff80();
  iVar5 = (cVar3 != '\0') + 3;
  FUN_00636ac8();
  iVar6 = __ftol();
  *(int *)(param_1 + 0x40c) = iVar6;
  if (iVar6 <= *(int *)(param_1 + 0x408)) {
    *(int *)(param_1 + 0x408) = iVar6 + -1;
  }
  if (*(int *)(param_1 + 0x408) == 0) {
    if (iVar6 != 1) {
      (**(code **)(**(int **)(param_1 + 0x340) + 0x98))();
LAB_0051e294:
      (**(code **)(**(int **)(param_1 + 0x344) + 0x94))();
      goto LAB_0051e2a2;
    }
    (**(code **)(**(int **)(param_1 + 0x340) + 0x98))();
  }
  else {
    if (*(int *)(param_1 + 0x408) != iVar6 + -1) {
      (**(code **)(**(int **)(param_1 + 0x340) + 0x94))();
      goto LAB_0051e294;
    }
    (**(code **)(**(int **)(param_1 + 0x340) + 0x94))();
  }
  (**(code **)(**(int **)(param_1 + 0x344) + 0x98))();
LAB_0051e2a2:
  puVar7 = (undefined4 *)(param_1 + 0x35c);
  iVar6 = 0x13;
  do {
    (**(code **)(*(int *)*puVar7 + 0x98))();
    puVar7 = puVar7 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  sVar1 = *(short *)(iVar4 + 0x600);
  if ((sVar1 == 0) || (iVar4 = param_1 + 0x3e4, 0x11 < sVar1)) {
    iVar4 = param_1 + 0x3a8;
  }
  if ((sVar1 == 0) || (0x11 < sVar1)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  iVar6 = 0;
  local_18 = *(int *)(param_1 + 0x408) * *(int *)(param_1 + 0x404) * iVar5;
  if (0 < *(int *)(param_1 + 0x404)) {
    local_14 = (int *)(iVar4 + local_18 * 4);
    do {
      local_c = 0;
      if (iVar5 != 0) {
        local_10 = local_18;
        piVar8 = local_14;
        do {
          if (local_10 == (-(uint)!bVar2 & 7) + 8) {
            return;
          }
          FUN_0050f668();
          iVar4 = *piVar8;
          FUN_004cb21d(((*(int *)(iVar4 + 0x84) - *(int *)(iVar4 + 0x7c)) + 3) * iVar6 +
                       *(int *)(param_1 + 0x348),
                       ((*(int *)(iVar4 + 0x88) - *(int *)(iVar4 + 0x80)) + 2) * local_c +
                       *(int *)(param_1 + 0x34c));
          (**(code **)(*(int *)*piVar8 + 0x94))();
          local_c = local_c + 1;
          local_10 = local_10 + 1;
          piVar8 = piVar8 + 1;
        } while (local_c < iVar5);
      }
      iVar6 = iVar6 + 1;
      local_18 = local_18 + iVar5;
      local_14 = local_14 + iVar5;
    } while (iVar6 < *(int *)(param_1 + 0x404));
  }
  return;
}

