
void __thiscall FUN_00423349(int param_1,int param_2,undefined2 param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 400);
  if ((*(int *)(param_1 + 400) != 0) || (iVar1 = param_1, param_1 != 0)) {
    do {
      *(undefined2 *)(param_2 * 2 + 0x4a + iVar1) = param_3;
      iVar1 = *(int *)(iVar1 + 0x18c);
    } while (iVar1 != 0);
  }
  return;
}

