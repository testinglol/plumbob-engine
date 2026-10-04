
undefined4 FUN_005cfc78(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  int iVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  puVar1 = *(undefined4 **)(unaff_EBP + 8);
  *puVar1 = 0;
  pvVar2 = operator_new(0x408);
  *(void **)(unaff_EBP + -0x10) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_005cdf87(extraout_ECX);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(int *)(unaff_EBP + 8) = iVar3;
  if (iVar3 == 0) {
    uVar4 = 0x9b0b0001;
    *(undefined4 *)(extraout_ECX + 4) = 0x9b0b0001;
  }
  else {
    iVar3 = FUN_005ce101(*(undefined4 *)(unaff_EBP + 0xc));
    *(int *)(extraout_ECX + 4) = iVar3;
    if (iVar3 == 0) {
      FUN_005d01e6(unaff_EBP + 8);
      *puVar1 = *(undefined4 *)(unaff_EBP + 8);
      uVar4 = 0;
    }
    else {
      if (*(undefined4 **)(unaff_EBP + 8) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(unaff_EBP + 8))(1);
      }
      uVar4 = *(undefined4 *)(extraout_ECX + 4);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

