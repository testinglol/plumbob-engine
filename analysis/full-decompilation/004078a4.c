
int __thiscall FUN_004078a4(int *param_1,byte param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != param_1[1]) {
    do {
      if (((*(uint *)(iVar1 + 0xc) & 1 << (param_2 & 0x1f)) != 0) &&
         (*(int *)(iVar1 + 0x10) == param_3)) {
        return iVar1;
      }
      iVar1 = iVar1 + 0x14;
    } while (iVar1 != param_1[1]);
  }
  return 0;
}

