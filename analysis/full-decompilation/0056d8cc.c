
void FUN_0056d8cc(void)

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
      FUN_0040d335(1);
    }
    else if (iVar1 == 2) {
      FUN_0040da9a(1);
    }
    else if (iVar1 == 4) {
      FUN_0040d782(1);
    }
    else if (iVar1 == 5) {
      FUN_0040ddb2(1);
    }
    else if (iVar1 == 0x11) {
      FUN_0040e0ca(1);
    }
    else if (iVar1 == 0x12) {
      FUN_0040e3e2(1);
    }
    (**(code **)(**(int **)(extraout_ECX + 0x1a8) + 0x8c))();
    FUN_0058a17c(1);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

