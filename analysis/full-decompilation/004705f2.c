
undefined4 __thiscall FUN_004705f2(int param_1,int param_2,char param_3)

{
  char cVar1;
  int iVar2;
  
  cVar1 = *(char *)(param_1 + 0x5d);
  if (param_3 != -1) {
    cVar1 = param_3;
  }
  if ((0 < param_2) && (iVar2 = FUN_0046fbe5(cVar1), param_2 <= iVar2)) {
    return *(undefined4 *)(*(int *)(param_1 + 0x60) + -4 + param_2 * 4);
  }
  return 0;
}

