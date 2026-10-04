
bool __fastcall FUN_00599915(undefined4 *param_1)

{
  char cVar1;
  
  cVar1 = FUN_005b90ab(*param_1);
  if ((((cVar1 != '\0') && (cVar1 = FUN_005b90ab(param_1[1]), cVar1 != '\0')) &&
      (cVar1 = FUN_005b90ab(param_1[2]), cVar1 != '\0')) &&
     (cVar1 = FUN_005b90ab(param_1[3]), cVar1 != '\0')) {
    cVar1 = FUN_005b90ab(param_1[4]);
    return cVar1 != '\0';
  }
  return false;
}

