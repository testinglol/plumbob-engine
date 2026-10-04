
void __fastcall FUN_004d32bf(int param_1)

{
  int iVar1;
  int *piVar2;
  
  FUN_005de633();
  *(undefined1 *)(param_1 + 0x11b) = 0;
  iVar1 = FUN_004d4090();
  if (iVar1 != 0) {
    piVar2 = (int *)FUN_004d4090();
    (**(code **)(*piVar2 + 0x48))();
  }
  iVar1 = *(int *)(DAT_006e486c + 0x4c);
  *(undefined4 *)(iVar1 + 0x2a4) = 0;
  *(undefined4 *)(iVar1 + 0x2a8) = 0;
  *(undefined4 *)(iVar1 + 0x2ac) = 0;
  *(undefined4 *)(iVar1 + 0x2b0) = 0;
  iVar1 = *(int *)(DAT_006e486c + 0x4c);
  *(undefined4 *)(iVar1 + 0x2b4) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(iVar1 + 0x2b8) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(iVar1 + 700) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(iVar1 + 0x2c0) = *(undefined4 *)(param_1 + 0x88);
  if (*(int **)(param_1 + 0x11bc) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x11bc) + 0x98))();
  }
  *(undefined1 *)(DAT_006fe8f4 + 0x1f8) = 0;
  return;
}

