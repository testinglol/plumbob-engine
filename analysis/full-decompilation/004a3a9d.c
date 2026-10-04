
bool __thiscall FUN_004a3a9d(undefined4 *param_1,int param_2)

{
  char cVar1;
  bool bVar2;
  
  if (*(char *)(param_2 + 0x1d) == '\0') {
    bVar2 = false;
  }
  else {
    cVar1 = FUN_005b9068(*param_1,((int)param_1[1] / 2) * param_1[1]);
    bVar2 = cVar1 != '\0';
  }
  return bVar2;
}

