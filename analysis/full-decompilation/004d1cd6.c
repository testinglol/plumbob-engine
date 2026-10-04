
void __fastcall FUN_004d1cd6(int param_1)

{
  undefined4 uVar1;
  
  if (DAT_006f0ef8 == '\0') {
    DAT_006f0ef8 = 1;
    uVar1 = FUN_005d51f5(s_DDDSimsView__Draw___006c7c6c,0);
    FUN_004b406a(uVar1);
    FUN_00473170();
    if (*(int **)(param_1 + 0x174) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x174) + 0x30))();
    }
    FUN_004d2a7e();
    if (*(int *)(param_1 + 0x11ac) != 0) {
      FUN_004ffc30();
    }
    FUN_005db0e6();
    (**(code **)(**(int **)(DAT_006e486c + 4) + 0x3c))(0);
    uVar1 = FUN_005d51f5(s_DDDSimsView__DrawEnd_006c7c54,0);
    FUN_004b406a(uVar1);
    if (*(int **)(param_1 + 0x174) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x174) + 0x34))();
    }
    DAT_006f0ef8 = '\0';
  }
  return;
}

