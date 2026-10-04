
undefined4 __thiscall FUN_00471584(int param_1,int param_2,char param_3)

{
  int iVar1;
  char cVar2;
  
  cVar2 = *(char *)(param_1 + 0x5d);
  if (param_3 != -1) {
    cVar2 = param_3;
  }
  if ((0 < param_2) && (iVar1 = FUN_0046fc11(cVar2), param_2 <= iVar1)) {
    return *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x6c) + cVar2 * 0xc) + -8 + param_2 * 0xc);
  }
  return 0;
}

