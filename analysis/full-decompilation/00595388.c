
undefined4 __thiscall FUN_00595388(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  cVar1 = FUN_005b9169(*(undefined4 *)(param_1 + 4));
  if ((cVar1 != '\0') && (cVar1 = FUN_005b90ab(*(undefined4 *)(param_1 + 0x14)), cVar1 != '\0')) {
    iVar2 = 0;
    if (*(int *)(param_1 + 0x18) == 0) {
      cVar1 = FUN_005b90ab(0);
    }
    else {
      cVar1 = FUN_005b90ab(1);
      if (cVar1 == '\0') {
        return 0;
      }
      cVar1 = FUN_005941db(param_2);
    }
    if ((cVar1 != '\0') &&
       (cVar1 = FUN_005b90ab(*(int *)(param_1 + 0x20) - *(int *)(param_1 + 0x1c) >> 2),
       cVar1 != '\0')) {
      iVar3 = *(int *)(param_1 + 0x20) - *(int *)(param_1 + 0x1c) >> 2;
      if (0 < iVar3) {
        do {
          cVar1 = FUN_00594ca4(param_2);
          if (cVar1 == '\0') {
            return 0;
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < iVar3);
      }
      return 1;
    }
  }
  return 0;
}

