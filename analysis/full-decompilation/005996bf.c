
bool __fastcall FUN_005996bf(int param_1)

{
  char cVar1;
  bool bVar2;
  
  cVar1 = FUN_005b9095(param_1);
  bVar2 = false;
  if (cVar1 != '\0') {
    cVar1 = FUN_005b9095(param_1 + 4);
    bVar2 = cVar1 != '\0';
  }
  return bVar2;
}

