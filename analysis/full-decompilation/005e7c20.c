
int * FUN_005e7c20(void)

{
  int *piVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int *extraout_ECX;
  int unaff_EBP;
  int *piVar5;
  
  FUN_00634c24();
  pvVar3 = operator_new(0x110);
  *(void **)(unaff_EBP + -0x10) = pvVar3;
  piVar5 = (int *)0x0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar3 != (void *)0x0) {
    piVar5 = (int *)FUN_005e9913();
  }
  uVar4 = *(undefined4 *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  piVar5[2] = *(int *)(unaff_EBP + 8);
  (**(code **)(*piVar5 + 0x9c))(uVar4);
  iVar2 = *extraout_ECX;
  piVar1 = piVar5 + 0x35;
  *(int *)(unaff_EBP + 8) = piVar5[0x35];
  uVar4 = (**(code **)(iVar2 + 8))(0);
  (**(code **)(*(int *)(unaff_EBP + 8) + 0x18))(uVar4);
  (**(code **)(*piVar1 + 0x1c))(1);
  (**(code **)(*piVar1 + 0x14))(0);
  (**(code **)(*piVar1 + 0xc))(2,0);
  (**(code **)*piVar1)();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return piVar5;
}

