
void __fastcall FUN_0043de11(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x1244);
  if (piVar2 != *(int **)(param_1 + 0x1248)) {
    do {
      iVar1 = *piVar2;
      if (iVar1 != 0) {
        FUN_0059875f();
        FUN_006321f0(iVar1);
      }
      piVar2 = piVar2 + 1;
    } while (piVar2 != *(int **)(param_1 + 0x1248));
  }
  FUN_0052ea87(*(undefined4 *)(param_1 + 0x1244),*(undefined4 *)(param_1 + 0x1248));
  return;
}

