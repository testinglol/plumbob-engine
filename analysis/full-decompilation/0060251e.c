
undefined4 FUN_0060251e(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int extraout_ECX;
  int unaff_EBP;
  int *piVar4;
  
  FUN_00634c24();
  *(undefined ***)(unaff_EBP + -0x1c) = &PTR_LAB_00669c88;
  iVar1 = *(int *)(extraout_ECX + 4);
  *(int **)(unaff_EBP + -0x18) = (int *)(extraout_ECX + 4);
  (**(code **)(iVar1 + 4))();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = **(int **)(unaff_EBP + 8);
  *(int *)(unaff_EBP + -0x10) = iVar1;
  if (iVar1 != 0) {
    FUN_005e76d4(unaff_EBP + -0x14,unaff_EBP + -0x10);
    if (*(int *)(unaff_EBP + -0x14) != *(int *)(extraout_ECX + 0x90)) {
      piVar2 = *(int **)(*(int *)(unaff_EBP + -0x14) + 0x14);
      piVar3 = (int *)*piVar2;
      piVar4 = (int *)*piVar3;
      if (piVar4 != piVar3) {
        do {
          (*(code *)**(undefined4 **)piVar4[2])(*(undefined4 *)(unaff_EBP + 8));
          piVar4 = (int *)*piVar4;
        } while (piVar4 != (int *)*piVar2);
      }
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
    }
  }
  iVar1 = *(int *)(extraout_ECX + 4);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(iVar1 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

