
void __fastcall FUN_005ce67e(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(*(int *)(param_1 + 0x60) + 0x38);
  iVar2 = (**(code **)(*piVar1 + 0x28))(piVar1);
  if (iVar2 == 0) {
    *(undefined1 *)(param_1 + 100) = 0;
  }
  return;
}

