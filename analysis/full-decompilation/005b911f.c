
bool FUN_005b911f(void)

{
  char cVar1;
  int iVar2;
  bool bVar3;
  uint local_c;
  byte local_5;
  
  iVar2 = FUN_005b8e6a(&local_5,1);
  if (iVar2 == 1) {
    if (local_5 == 0xff) {
      FUN_005b8e6a(&local_c,4);
    }
    else {
      local_c = (uint)local_5;
    }
    cVar1 = FUN_005b8f4a(local_c);
    bVar3 = cVar1 != '\0';
  }
  else {
    bVar3 = false;
  }
  return bVar3;
}

