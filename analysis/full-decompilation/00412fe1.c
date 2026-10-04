
int __thiscall FUN_00412fe1(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 4) == 0) {
    iVar2 = -0x31;
  }
  else {
    cVar1 = FUN_005b8ff1(param_2);
    iVar2 = (-(uint)(cVar1 != '\0') & 0x32) - 0x32;
  }
  return iVar2;
}

