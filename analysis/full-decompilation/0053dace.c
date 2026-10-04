
void __thiscall FUN_0053dace(int param_1,uint param_2,undefined1 param_3)

{
  int iVar1;
  
  for (iVar1 = *(int *)(param_1 + 0x30); iVar1 != *(int *)(param_1 + 0x34); iVar1 = iVar1 + 6) {
    if (*(byte *)(iVar1 + 1) == param_2) {
      *(undefined1 *)(iVar1 + 1) = param_3;
    }
  }
  return;
}

