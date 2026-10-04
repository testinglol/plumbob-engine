
bool __fastcall FUN_005997fa(int param_1)

{
  char cVar1;
  
  cVar1 = FUN_005b9095(param_1);
  if ((cVar1 != '\0') && (cVar1 = FUN_005b9095(param_1 + 4), cVar1 != '\0')) {
    cVar1 = FUN_005b9095(param_1 + 8);
    return cVar1 != '\0';
  }
  return false;
}

