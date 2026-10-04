
int __thiscall FUN_0043ae5e(int param_1,int param_2,int param_3)

{
  short sVar1;
  char cVar2;
  int iVar3;
  int local_8;
  
  sVar1 = *(short *)(*(int *)(param_2 + 0x60) + 0x14);
  if ((sVar1 != 0) &&
     (local_8 = 0, 0 < (int)(*(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x20) & 0xfffffffcU))) {
    do {
      iVar3 = FUN_0043ad1f((int)(short)local_8);
      cVar2 = FUN_005c17a6(param_2);
      if ((cVar2 != '\0') &&
         ((*(short *)(*(int *)(iVar3 + 0x60) + 0x14) == sVar1 &&
          (cVar2 = FUN_0043aedc(), cVar2 == '\0')))) {
        if (param_3 == 0) {
          return iVar3;
        }
        param_3 = param_3 + -1;
      }
      local_8 = local_8 + 1;
    } while (local_8 < *(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x20) >> 2);
  }
  return 0;
}

