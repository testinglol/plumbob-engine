
void __fastcall FUN_0050acc5(int param_1)

{
  int iVar1;
  int *piVar2;
  
  FUN_005de626();
  iVar1 = *(int *)(param_1 + 0xd8);
  if (iVar1 == 0) {
    piVar2 = *(int **)(param_1 + 0xe4);
  }
  else if (iVar1 == 1) {
    piVar2 = *(int **)(param_1 + 0xe0);
  }
  else if (iVar1 == 2) {
    piVar2 = *(int **)(param_1 + 0xe8);
  }
  else if (iVar1 == 3) {
    piVar2 = *(int **)(param_1 + 0xec);
  }
  else if (iVar1 == 4) {
    piVar2 = *(int **)(param_1 + 0xf0);
  }
  else {
    if (iVar1 != 5) {
      return;
    }
    piVar2 = *(int **)(param_1 + 0xf4);
  }
  (**(code **)(*piVar2 + 0x94))();
  return;
}

