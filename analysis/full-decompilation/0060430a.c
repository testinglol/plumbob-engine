
void FUN_0060430a(void)

{
  int *piVar1;
  int iVar2;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar2 = DAT_006fecc8;
  *(undefined ***)(unaff_EBP + -0x18) = &PTR_LAB_00669c88;
  *(int **)(unaff_EBP + -0x14) = &DAT_006fecc8;
  (**(code **)(iVar2 + 4))();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (DAT_006fed00 != 0) {
    FUN_00580a92(unaff_EBP + -0x20);
    *(int **)(unaff_EBP + -0x24) = &DAT_006fed08;
    iVar2 = DAT_006fed08;
    piVar1 = *(int **)(*(int *)(unaff_EBP + -0x20) + 4);
    *(undefined ***)(unaff_EBP + -0x28) = &PTR_LAB_00669c88;
    (**(code **)(iVar2 + 4))();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    *(int **)(unaff_EBP + -0x10) = piVar1;
    FUN_00575b11(unaff_EBP + -0x30,unaff_EBP + -0x10);
    if (*(int *)(unaff_EBP + -0x30) != 0) {
      (**(code **)(*piVar1 + 0x28))();
    }
    iVar2 = DAT_006fed08;
    *(undefined1 *)(unaff_EBP + -4) = 0;
    (**(code **)(iVar2 + 8))();
  }
  iVar2 = DAT_006fecc8;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(iVar2 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

