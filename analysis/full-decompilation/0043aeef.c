
int __thiscall FUN_0043aeef(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  
  iVar2 = param_2;
  sVar1 = *(short *)(*(int *)(param_2 + 0x60) + 0x14);
  if (sVar1 != 0) {
    param_2 = 0;
    if (0 < (int)(*(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x20) & 0xfffffffcU)) {
      do {
        iVar4 = FUN_0043ad1f(param_2);
        cVar3 = FUN_005c17a6(iVar2);
        if (((cVar3 != '\0') && (*(short *)(*(int *)(iVar4 + 0x60) + 0x14) == sVar1)) &&
           (cVar3 = FUN_0043aedc(), cVar3 != '\0')) {
          return iVar4;
        }
        param_2 = param_2 + 1;
      } while (param_2 < *(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x20) >> 2);
    }
    param_2 = 0;
  }
  return param_2;
}

