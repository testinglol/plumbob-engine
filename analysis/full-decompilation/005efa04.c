
void FUN_005efa04(void)

{
  int iVar1;
  int *piVar2;
  int unaff_EBP;
  undefined4 uVar3;
  
  FUN_00634c24();
  if (*(char *)(unaff_EBP + 8) == '\0') {
    if (DAT_006feca0 == (int *)0x0) {
      uVar3 = 8;
      iVar1 = *DAT_006fec9c;
      piVar2 = DAT_006fec9c;
    }
    else {
      iVar1 = *DAT_006feca0;
      uVar3 = 0x808;
      piVar2 = DAT_006feca0;
    }
    iVar1 = (**(code **)(iVar1 + 0x50))(piVar2,DAT_006fe8cc,uVar3);
    if (iVar1 == 0) goto LAB_005efab8;
    *(int *)(unaff_EBP + -0x14) = iVar1;
    *(undefined4 *)(unaff_EBP + -4) = 2;
    *(undefined ***)(unaff_EBP + -0x18) = &PTR_FUN_00675034;
    (*(code *)PTR_FUN_00675038)(0);
    iVar1 = *(int *)(unaff_EBP + -0x18);
    *(undefined4 *)(unaff_EBP + -4) = 3;
  }
  else {
    if (DAT_006feca0 == (int *)0x0) {
      uVar3 = 0x11;
      iVar1 = *DAT_006fec9c;
      piVar2 = DAT_006fec9c;
    }
    else {
      iVar1 = *DAT_006feca0;
      uVar3 = 0x811;
      piVar2 = DAT_006feca0;
    }
    iVar1 = (**(code **)(iVar1 + 0x50))(piVar2,DAT_006fe8cc,uVar3);
    if (iVar1 == 0) goto LAB_005efab8;
    *(int *)(unaff_EBP + -0x14) = iVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(undefined ***)(unaff_EBP + -0x18) = &PTR_FUN_00675034;
    (*(code *)PTR_FUN_00675038)(0);
    iVar1 = *(int *)(unaff_EBP + -0x18);
    *(undefined4 *)(unaff_EBP + -4) = 1;
  }
  (**(code **)(iVar1 + 0x10))();
LAB_005efab8:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

