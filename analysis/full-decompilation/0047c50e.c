
void __thiscall FUN_0047c50e(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)**(undefined4 **)(param_1 + 0xc);
  iVar1 = *(int *)(param_1 + 8) * *(int *)(param_1 + 4);
  if (-1 < iVar1 + -1) {
    do {
      *puVar2 = *param_2;
      puVar2 = puVar2 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}

