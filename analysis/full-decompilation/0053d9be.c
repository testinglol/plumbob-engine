
void __thiscall FUN_0053d9be(int param_1,undefined2 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x30);
  if (iVar1 != *(int *)(param_1 + 0x34)) {
    do {
      *(undefined2 *)(iVar1 + 2) = param_2;
      *(undefined2 *)(iVar1 + 4) = param_2;
      iVar1 = iVar1 + 6;
    } while (iVar1 != *(int *)(param_1 + 0x34));
  }
  return;
}

