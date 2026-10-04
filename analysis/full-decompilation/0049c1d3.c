
bool __thiscall FUN_0049c1d3(undefined4 *param_1,int param_2)

{
  char cVar1;
  bool bVar2;
  
  if (*(char *)(param_2 + 0x1d) == '\0') {
    bVar2 = false;
  }
  else {
    cVar1 = FUN_005b9068(*param_1,param_1[4] * param_1[3]);
    bVar2 = cVar1 != '\0';
  }
  return bVar2;
}

