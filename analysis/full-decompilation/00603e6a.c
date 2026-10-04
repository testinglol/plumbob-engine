
int * FUN_00603e6a(void)

{
  void *pvVar1;
  int iVar2;
  undefined4 extraout_ECX;
  int unaff_EBP;
  int *piVar3;
  undefined4 uVar4;
  
  FUN_00634c24();
  uVar4 = extraout_ECX;
  pvVar1 = operator_new(0x1bc);
  *(void **)(unaff_EBP + -0x10) = pvVar1;
  iVar2 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar1 != (void *)0x0) {
    iVar2 = FUN_005fa916(uVar4);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  piVar3 = (int *)(-(uint)(iVar2 != 0) & iVar2 + 0x174U);
  (**(code **)(*piVar3 + 8))();
  (**(code **)*piVar3)();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return piVar3;
}

