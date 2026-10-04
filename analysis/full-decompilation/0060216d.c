
undefined1 FUN_0060216d(void)

{
  void *pvVar1;
  int iVar2;
  int extraout_ECX;
  undefined1 uVar3;
  int unaff_EBP;
  uint uVar4;
  int *piVar5;
  
  FUN_00634c24();
  *(undefined ***)(unaff_EBP + -0x1c) = &PTR_LAB_00669c88;
  uVar4 = -(uint)(extraout_ECX != 0x48) & extraout_ECX - 0x38U;
  iVar2 = *(int *)(uVar4 + 4);
  piVar5 = (int *)(uVar4 + 4);
  *(int **)(unaff_EBP + -0x18) = piVar5;
  (**(code **)(iVar2 + 4))();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar2 = *(int *)(extraout_ECX + 8);
  FUN_005e76d4(unaff_EBP + -0x10,unaff_EBP + 8);
  if (*(int *)(unaff_EBP + -0x10) == iVar2) {
    pvVar1 = operator_new(0x68);
    *(void **)(unaff_EBP + -0x10) = pvVar1;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    if (pvVar1 == (void *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_0060162e();
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    if (iVar2 != 0) {
      *(int *)(unaff_EBP + -0x10) = iVar2;
      *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + 8);
      FUN_00602b14(unaff_EBP + -0x24,unaff_EBP + -0x14);
      uVar3 = 1;
      goto LAB_00602202;
    }
  }
  uVar3 = 0;
LAB_00602202:
  iVar2 = *piVar5;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(iVar2 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

