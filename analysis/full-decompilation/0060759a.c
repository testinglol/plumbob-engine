
void FUN_0060759a(void)

{
  int *piVar1;
  int iVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined ***)(unaff_EBP + -0x14) = &PTR_LAB_00669c88;
  piVar1 = (int *)(extraout_ECX + 0x68);
  *(undefined1 *)(extraout_ECX + 0x8c) = 1;
  *(int **)(unaff_EBP + -0x10) = piVar1;
  (**(code **)(*piVar1 + 4))();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  while( true ) {
    iVar2 = FUN_0060783f();
    if (iVar2 == 0) break;
    FUN_00607519(*(undefined4 *)(**(int **)(extraout_ECX + 4) + 8));
  }
  iVar2 = *piVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(iVar2 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

