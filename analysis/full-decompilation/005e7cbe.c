
int * FUN_005e7cbe(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  void *pvVar4;
  undefined4 uVar5;
  int *extraout_ECX;
  int unaff_EBP;
  int *piVar6;
  
  FUN_00634c24();
  pvVar4 = operator_new(0x124);
  *(void **)(unaff_EBP + -0x10) = pvVar4;
  piVar6 = (int *)0x0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar4 != (void *)0x0) {
    piVar6 = (int *)FUN_005f5b18();
  }
  iVar1 = *extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar5 = (**(code **)(iVar1 + 0x10))(3);
  uVar3 = (**(code **)(*extraout_ECX + 0x18))(3);
  uVar2 = *(undefined4 *)(unaff_EBP + 0xc);
  *(undefined1 *)(unaff_EBP + -0x10) = uVar3;
  piVar6[2] = *(int *)(unaff_EBP + 8);
  (**(code **)(*piVar6 + 0x9c))(uVar2);
  (**(code **)(*piVar6 + 0x1b4))(2);
  (**(code **)(*piVar6 + 0x1b8))(uVar5,*(undefined4 *)(unaff_EBP + -0x10));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return piVar6;
}

