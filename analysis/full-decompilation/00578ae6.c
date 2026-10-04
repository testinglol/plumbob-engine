
undefined4 FUN_00578ae6(void)

{
  int iVar1;
  char cVar2;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar1 = DAT_006f63e8;
  *(int **)(unaff_EBP + -0x10) = &DAT_006f63e8;
  *(undefined ***)(unaff_EBP + -0x14) = &PTR_LAB_00669c88;
  (**(code **)(iVar1 + 4))();
  iVar1 = *extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  cVar2 = (**(code **)(iVar1 + 0x1c))();
  if ((cVar2 != '\0') && (extraout_ECX[0x10] != *(int *)(unaff_EBP + 8))) {
    extraout_ECX[0x10] = *(int *)(unaff_EBP + 8);
    FUN_005771b0();
    iVar1 = extraout_ECX[0xc];
    *(undefined4 *)(iVar1 + 0x10) = 0;
    *(undefined4 *)(iVar1 + 8) = 0;
    *(undefined4 *)(iVar1 + 0x14) = 0;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    FUN_005772e2();
    extraout_ECX[0x17] = extraout_ECX[0x18] + extraout_ECX[0x16];
    FUN_005fd8ea();
    FUN_005fd8ea();
  }
  iVar1 = DAT_006f63e8;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(iVar1 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

