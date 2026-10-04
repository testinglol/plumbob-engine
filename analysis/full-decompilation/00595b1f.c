
bool __thiscall FUN_00595b1f(undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  cVar1 = FUN_005b9169(*param_1);
  if ((cVar1 != '\0') && (cVar1 = FUN_005b9169(param_1[4]), cVar1 != '\0')) {
    iVar3 = 0;
    iVar4 = param_1[0xb];
    cVar1 = FUN_005b90ab(iVar4 != 0);
    if ((cVar1 != '\0') && ((iVar4 == 0 || (cVar1 = FUN_005941db(param_2), cVar1 != '\0')))) {
      puVar2 = param_1 + 0xc;
      do {
        cVar1 = FUN_005b90ab(*puVar2);
        if (cVar1 == '\0') {
          return false;
        }
        iVar3 = iVar3 + 1;
        puVar2 = puVar2 + 1;
      } while (iVar3 < 3);
      iVar4 = 0;
      puVar2 = param_1 + 0xf;
      do {
        cVar1 = FUN_005b90ab(*puVar2);
        if (cVar1 == '\0') {
          return false;
        }
        iVar4 = iVar4 + 1;
        puVar2 = puVar2 + 1;
      } while (iVar4 < 4);
      cVar1 = FUN_005b90ab(param_1[0x1b]);
      if ((((cVar1 != '\0') && (cVar1 = FUN_005b90ab(param_1[0x1c]), cVar1 != '\0')) &&
          (cVar1 = FUN_005b90ab(param_1[0x1d]), cVar1 != '\0')) &&
         (cVar1 = FUN_005b90ab(param_1[0x1e]), cVar1 != '\0')) {
        cVar1 = FUN_005b90ab(param_1[0x1f]);
        return cVar1 != '\0';
      }
    }
  }
  return false;
}

