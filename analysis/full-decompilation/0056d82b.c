
void FUN_0056d82b(void)

{
  int iVar1;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xfffffff0;
  if (*(int *)(extraout_ECX + 0x1ac) != 0) {
    iVar1 = *(int *)(extraout_ECX + 0x1b0);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(undefined1 *)(extraout_ECX + 0x224) = 1;
    if (iVar1 == 0) {
      FUN_0040d1fd(1);
    }
    else if (iVar1 == 2) {
      FUN_0040d9a6(1);
    }
    else if (iVar1 == 4) {
      FUN_0040d68e(1);
    }
    else if (iVar1 == 5) {
      FUN_0040dcbe(1);
    }
    else if (iVar1 == 0x11) {
      FUN_0040dfd6(1);
    }
    else if (iVar1 == 0x12) {
      FUN_0040e2ee(1);
    }
    (**(code **)(**(int **)(extraout_ECX + 0x1a8) + 0x8c))();
    FUN_0058a17c(1);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

