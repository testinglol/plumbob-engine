
int __thiscall FUN_004131a0(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 4) == 0) {
    iVar2 = -0x31;
  }
  else {
    cVar1 = FUN_005b8f4a(param_2);
    iVar2 = (-(uint)(cVar1 != '\0') & 0x30) - 0x30;
  }
  return iVar2;
}

