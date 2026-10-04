
int __fastcall FUN_005ceecd(int param_1)

{
  int iVar1;
  
  do {
    if ((*(int *)(param_1 + 0x7c) - *(int *)(param_1 + 0x78) & 0xfffffffcU) == 0) {
      return 0;
    }
    iVar1 = FUN_005ced0e(**(undefined4 **)(param_1 + 0x78));
  } while (iVar1 == 0);
  *(int *)(param_1 + 0x5c) = iVar1;
  return iVar1;
}

