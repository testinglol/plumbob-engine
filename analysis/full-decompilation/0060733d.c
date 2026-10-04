
void FUN_0060733d(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00676f08;
  iVar2 = extraout_ECX[10];
  piVar1 = extraout_ECX + 10;
  *(undefined4 *)(unaff_EBP + -4) = 4;
  (**(code **)(iVar2 + 0x38))(unaff_EBP + -0x14);
  *(undefined1 *)(extraout_ECX + 0x23) = 1;
  FUN_005771b0();
  iVar2 = (**(code **)(*piVar1 + 0x2c))();
  if (iVar2 != 0) {
    (**(code **)(*piVar1 + 0x14))();
    (**(code **)(*piVar1 + 0x1c))();
    extraout_ECX[6] = 0;
    extraout_ECX[4] = 0;
    extraout_ECX[7] = 0;
    extraout_ECX[5] = 0;
    FUN_005772e2();
    do {
      uVar3 = FUN_005fd8ea();
      if (999 < uVar3) break;
    } while (*(char *)((int)extraout_ECX + 0x8d) != '\0');
  }
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005d9122();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005d9122();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d8e05();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_006078d9();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

