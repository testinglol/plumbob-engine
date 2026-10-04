
bool __fastcall FUN_005996e6(undefined4 *param_1)

{
  char cVar1;
  bool bVar2;
  
  cVar1 = FUN_005b90ab(*param_1);
  bVar2 = false;
  if (cVar1 != '\0') {
    cVar1 = FUN_005b90ab(param_1[1]);
    bVar2 = cVar1 != '\0';
  }
  return bVar2;
}

