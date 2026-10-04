
bool __fastcall FUN_0059973c(undefined4 *param_1)

{
  char cVar1;
  
  cVar1 = FUN_005b90ab(*param_1);
  if ((cVar1 != '\0') && (cVar1 = FUN_005b90ab(param_1[1]), cVar1 != '\0')) {
    cVar1 = FUN_005b90ab(param_1[2]);
    return cVar1 != '\0';
  }
  return false;
}

