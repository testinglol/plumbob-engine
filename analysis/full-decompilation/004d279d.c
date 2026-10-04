
void __thiscall FUN_004d279d(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x154);
  *(undefined4 *)(param_1 + 0x158) = *(undefined4 *)(iVar1 + 0x14);
  *(undefined4 *)(param_1 + 0x15c) = *(undefined4 *)(iVar1 + 0x18);
  *(undefined4 *)(param_1 + 0x160) = *(undefined4 *)(iVar1 + 0x1c);
  iVar1 = *(int *)(iVar1 + 0x20);
  *(int *)(param_1 + 0x164) = iVar1;
  iVar2 = param_2[1] - (iVar1 - *(int *)(param_1 + 0x15c)) / 2;
  iVar1 = *param_2;
  *(int *)(param_1 + 0x15c) = *(int *)(param_1 + 0x15c) + iVar2;
  *(int *)(param_1 + 0x164) = *(int *)(param_1 + 0x164) + iVar2;
  iVar1 = iVar1 - (*(int *)(param_1 + 0x160) - *(int *)(param_1 + 0x158)) / 2;
  *(int *)(param_1 + 0x158) = *(int *)(param_1 + 0x158) + iVar1;
  *(int *)(param_1 + 0x160) = *(int *)(param_1 + 0x160) + iVar1;
  *(undefined1 *)(param_1 + 0x168) = 1;
  if (*(int **)(param_1 + 0x150) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x150) + 0x60))
              (*(undefined4 *)(param_1 + 0x158),*(undefined4 *)(param_1 + 0x15c),
               *(undefined4 *)(param_1 + 0x160),*(undefined4 *)(param_1 + 0x164));
    (**(code **)(**(int **)(param_1 + 0x150) + 0x94))();
  }
  return;
}

