
int FUN_004c8f7a(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_00575b11(unaff_EBP + -0x20,unaff_EBP + 8);
  if (*(int *)(unaff_EBP + -0x20) != 0) {
    iVar2 = *(int *)(*(int *)(unaff_EBP + -0x20) + 8);
    goto LAB_004c90bf;
  }
  piVar1 = (int *)*extraout_ECX;
  *(undefined4 **)(unaff_EBP + -0x18) = extraout_ECX + 7;
  iVar2 = FUN_004b8e50();
  if (iVar2 == 0) {
    FUN_004c915f();
  }
  iVar3 = (**(code **)(*piVar1 + 0x38))(0x53505223,*(undefined4 *)(unaff_EBP + 8),FUN_004c90d0);
  iVar2 = 0;
  *(int *)(unaff_EBP + -0x14) = iVar3;
  if (iVar3 == 0) {
    iVar3 = (**(code **)(*piVar1 + 0x38))(0x53505232,*(undefined4 *)(unaff_EBP + 8),0);
    *(int *)(unaff_EBP + -0x14) = iVar3;
    if (iVar3 != 0) {
      pvVar4 = operator_new(0x2c);
      *(void **)(unaff_EBP + -0x1c) = pvVar4;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      if (pvVar4 != (void *)0x0) {
        iVar2 = FUN_004c173f(*(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + -0x14),
                             *(undefined4 *)(unaff_EBP + 8),1,unaff_EBP + -0xd);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      if (iVar2 != 0) {
        FUN_00461765();
        *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + 8);
        iVar3 = extraout_ECX[5];
        *(int *)(unaff_EBP + -0x24) = iVar2;
        FUN_004c9a07(iVar3 + 1);
        iVar3 = unaff_EBP + -0x28;
        iVar5 = unaff_EBP + -0x40;
        goto LAB_004c90a7;
      }
    }
  }
  else {
    pvVar4 = operator_new(0x2c);
    *(void **)(unaff_EBP + -0x1c) = pvVar4;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar4 != (void *)0x0) {
      iVar2 = FUN_004c173f(*(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + -0x14),
                           *(undefined4 *)(unaff_EBP + 8),0,0);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    if (iVar2 != 0) {
      FUN_00461765();
      *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + 8);
      iVar3 = extraout_ECX[5];
      *(int *)(unaff_EBP + -0x1c) = iVar2;
      FUN_004c9a07(iVar3 + 1);
      iVar3 = unaff_EBP + -0x20;
      iVar5 = unaff_EBP + -0x34;
LAB_004c90a7:
      FUN_004c9997(iVar5,iVar3);
      FUN_00465a06(*(undefined4 *)(unaff_EBP + -0x14));
      goto LAB_004c90bf;
    }
  }
  iVar2 = 0;
LAB_004c90bf:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar2;
}

