
int FUN_005d2cdc(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  FUN_00634c24();
  *(undefined ***)(unaff_EBP + -0x14) = &PTR_FUN_00673470;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = FUN_005d2d3b(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x14);
  if (iVar1 == 0) {
    iVar1 = (**(code **)**(undefined4 **)(unaff_EBP + -0x10))
                      (*(undefined4 **)(unaff_EBP + -0x10),&DAT_00677278,
                       *(undefined4 *)(unaff_EBP + 0xc));
    iVar2 = 0;
    if (iVar1 == 0) goto LAB_005d2d1e;
  }
  iVar2 = iVar1;
LAB_005d2d1e:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005cb62e();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar2;
}

