
void __fastcall FUN_004d2851(int param_1)

{
  int *piVar1;
  
  if (*(int **)(param_1 + 0x150) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x150) + 0x98))();
  }
  *(undefined1 *)(param_1 + 0x168) = 0;
  if (*(int *)(param_1 + 0x150) != 0) {
    piVar1 = (int *)FUN_004b46a0();
    (**(code **)(*piVar1 + 0x170))(*(int *)(param_1 + 0x150) + 0xc);
  }
  return;
}

