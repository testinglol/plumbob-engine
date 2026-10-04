
undefined1 __thiscall FUN_00596aac(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  char cVar2;
  
  cVar2 = FUN_005b9169(*param_1);
  if (((((cVar2 != '\0') && (cVar2 = FUN_005b90ab(param_1[5]), cVar2 != '\0')) &&
       (cVar2 = FUN_005b90ab(param_1[6]), cVar2 != '\0')) &&
      ((cVar2 = FUN_005b90ab(param_1[7]), cVar2 != '\0' &&
       (cVar2 = FUN_005b90ab(param_1[8]), cVar2 != '\0')))) &&
     ((cVar2 = FUN_005b90ab(param_1[9]), cVar2 != '\0' &&
      (cVar2 = FUN_005b90ab(param_1[10]), cVar2 != '\0')))) {
    iVar1 = param_1[0xb];
    cVar2 = FUN_005b90ab(iVar1 != 0);
    if ((cVar2 != '\0') && ((iVar1 == 0 || (cVar2 = FUN_005941db(param_2), cVar2 != '\0')))) {
      iVar1 = param_1[0xc];
      cVar2 = FUN_005b90ab(iVar1 != 0);
      if ((cVar2 != '\0') && ((iVar1 == 0 || (cVar2 = FUN_00594614(param_2), cVar2 != '\0')))) {
        return 1;
      }
    }
  }
  return 0;
}

