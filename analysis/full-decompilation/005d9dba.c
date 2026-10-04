
void __fastcall FUN_005d9dba(int param_1)

{
  int *piVar1;
  
  *(undefined4 *)(param_1 + 0x178) = 0;
  if ((*(int *)(param_1 + 0x174) != 0) && (*(char *)(param_1 + 0x1a1) != '\0')) {
    (**(code **)(**(int **)(param_1 + 0x2c) + 0x170))(param_1 + 0x1a4);
  }
  piVar1 = *(int **)(param_1 + 0x18c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0xc0))(piVar1 + 0x1f,0);
    (**(code **)(**(int **)(param_1 + 0x18c) + 8))();
    *(undefined4 *)(param_1 + 0x18c) = 0;
  }
  return;
}

