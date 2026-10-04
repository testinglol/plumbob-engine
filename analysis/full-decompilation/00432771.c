
void __thiscall FUN_00432771(undefined1 *param_1,undefined1 *param_2)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = *param_2;
  iVar1 = *(int *)(param_2 + 0x10);
  *(int *)(param_1 + 0x10) = iVar1;
  if (iVar1 != -1) {
    *(int *)(param_1 + 0x10) = iVar1 + 1;
  }
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_2 + 0x14);
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 0xc);
  return;
}

