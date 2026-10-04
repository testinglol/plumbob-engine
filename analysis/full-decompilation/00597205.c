
undefined4 __thiscall FUN_00597205(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  cVar1 = FUN_005b9169(*(undefined4 *)(param_1 + 4));
  if ((((cVar1 != '\0') && (cVar1 = FUN_005b9169(*(undefined4 *)(param_1 + 0x10)), cVar1 != '\0'))
      && (cVar1 = FUN_005b90ab(*(undefined4 *)(param_1 + 0x2c)), cVar1 != '\0')) &&
     (((cVar1 = FUN_005b90ab(*(undefined4 *)(param_1 + 0x30)), cVar1 != '\0' &&
       (cVar1 = FUN_005b90ab(*(undefined4 *)(param_1 + 0x34)), cVar1 != '\0')) &&
      ((cVar1 = FUN_005b90ab(*(undefined4 *)(param_1 + 0x5c)), cVar1 != '\0' &&
       (cVar1 = FUN_005b90ab(*(undefined4 *)(param_1 + 100)), cVar1 != '\0')))))) {
    iVar3 = *(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x20) >> 2;
    cVar1 = FUN_005b90ab(iVar3);
    if (cVar1 != '\0') {
      iVar2 = 0;
      if (0 < iVar3) {
        do {
          cVar1 = FUN_00596aac(param_2);
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

