
void __fastcall FUN_004223c0(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = *(int **)(param_1 + 0x1ac);
  if ((piVar1 == (int *)0x0) || (*(short *)(piVar1[0x46] + 0x14) == 0)) {
    *(undefined4 *)(param_1 + 0x1a8) = 0;
    *(undefined4 *)(param_1 + 0x1a4) = 0;
    *(undefined4 *)(param_1 + 0x1a0) = 0;
  }
  else {
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x88))();
    }
    iVar3 = *(int *)(param_1 + 400);
    if ((*(int *)(param_1 + 400) != 0) || (iVar3 = param_1, param_1 != 0)) {
      do {
        iVar2 = *(int *)(iVar3 + 0x1ac);
        if (iVar2 != 0) {
          *(undefined4 *)(iVar3 + 0x1a0) = *(undefined4 *)(iVar2 + 0x1a0);
          *(undefined4 *)(iVar3 + 0x1a4) = *(undefined4 *)(iVar2 + 0x1a4);
          *(undefined4 *)(iVar3 + 0x1a8) = *(undefined4 *)(iVar2 + 0x1a8);
        }
        iVar3 = *(int *)(iVar3 + 0x18c);
      } while (iVar3 != 0);
      return;
    }
  }
  return;
}

