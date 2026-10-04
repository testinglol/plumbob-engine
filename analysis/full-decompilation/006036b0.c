
undefined4 __fastcall FUN_006036b0(int param_1)

{
  int iVar1;
  int *piVar2;
  
  (**(code **)(*(int *)(param_1 + -4) + 0x38))(1);
  if (*(int *)(param_1 + 0x6c) != 0) {
    FUN_00607a22();
    iVar1 = *(int *)(param_1 + 0x6c);
    if (iVar1 != 0) {
      FUN_0042004f();
      FUN_006321f0(iVar1);
    }
    *(undefined4 *)(param_1 + 0x6c) = 0;
  }
  if (*(int **)(param_1 + 0x58) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x58) + 4))();
    *(undefined4 *)(param_1 + 0x58) = 0;
  }
  if (*(int **)(param_1 + 0x54) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x54) + 0x28))();
    if (*(int **)(param_1 + 0x54) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x54) + 0xcc))(1);
    }
    *(undefined4 *)(param_1 + 0x54) = 0;
  }
  piVar2 = *(int **)(param_1 + 0x4c);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    *(undefined4 *)(param_1 + 0x4c) = 0;
  }
  (**(code **)(*(int *)(param_1 + -4) + 0xb0))(0);
  return 1;
}

