
undefined4 __thiscall FUN_00501004(int param_1,int param_2,int param_3)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int local_8;
  
  if (param_2 != 1) {
    if (param_2 != 0x13) {
      return 0;
    }
    if (*(int *)(param_1 + 0x15c) == 0) {
      return 0;
    }
    param_2 = 0;
    iVar5 = *(int *)(param_1 + 0x128) - *(int *)(param_1 + 0x124) >> 2;
    if (iVar5 < 1) {
      return 0;
    }
    do {
      iVar6 = *(int *)(*(int *)(param_1 + 0x124) + param_2 * 4);
      if ((iVar6 != 0) && (iVar3 = FUN_00492d2c(), param_3 == iVar3)) {
        FUN_005083f4(iVar6,param_1);
      }
      param_2 = param_2 + 1;
    } while (param_2 < iVar5);
    return 0;
  }
  if (param_3 == *(int *)(param_1 + 0xe4)) {
    cVar2 = FUN_004cf213();
    if (cVar2 != '\0') {
      FUN_004cf47f();
    }
    return 1;
  }
  if (param_3 != *(int *)(param_1 + 0xe8)) {
    if (param_3 == *(int *)(param_1 + 0xec)) {
      if (*(int *)(param_1 + 0x154) < 1) {
        return 0;
      }
      *(int *)(param_1 + 0x154) = *(int *)(param_1 + 0x154) + -1;
    }
    else {
      if (param_3 != *(int *)(param_1 + 0xf0)) {
        bVar1 = false;
        iVar5 = 0;
        piVar4 = (int *)(param_1 + 0xf4);
        local_8 = param_1;
        do {
          if (param_3 == *piVar4) {
            bVar1 = true;
            local_8 = iVar5;
          }
          else {
            iVar6 = FUN_004cf207();
            if (iVar6 != iVar5) {
              FUN_005e46f0(0);
            }
          }
          iVar5 = iVar5 + 1;
          piVar4 = piVar4 + 1;
        } while (iVar5 < 0xc);
        if (bVar1) {
          iVar5 = 0;
          do {
            FUN_005e46f0(iVar5 == local_8);
            iVar5 = iVar5 + 1;
          } while (iVar5 < 0xc);
          FUN_004cf268(local_8);
          return 1;
        }
        iVar5 = 0;
        iVar6 = *(int *)(param_1 + 0x128) - *(int *)(param_1 + 0x124) >> 2;
        if (iVar6 < 1) {
          return 0;
        }
        while ((*(int *)(*(int *)(param_1 + 0x124) + iVar5 * 4) == 0 ||
               (iVar3 = FUN_00492d2c(), param_3 != iVar3))) {
          iVar5 = iVar5 + 1;
          if (iVar6 <= iVar5) {
            return 0;
          }
        }
        FUN_004cf45f(*(undefined4 *)(iVar5 * 4 + *(int *)(param_1 + 0x124)));
        if (*(int *)(param_1 + 0x15c) == 0) {
          return 1;
        }
        if (*(char *)(*(int *)(param_1 + 0x15c) + 0xf0) == '\0') {
          return 1;
        }
        FUN_005083f4(*(undefined4 *)(iVar5 * 4 + *(int *)(param_1 + 0x124)),param_1);
        return 1;
      }
      *(int *)(param_1 + 0x154) = *(int *)(param_1 + 0x154) + 1;
    }
    FUN_004cee86(0x10);
    return 0;
  }
  cVar2 = FUN_004cf22d();
  if (cVar2 == '\0') {
    return 1;
  }
  FUN_004cf4b6();
  return 1;
}

