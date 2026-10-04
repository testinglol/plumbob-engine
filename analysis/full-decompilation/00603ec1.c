
uint FUN_00603ec1(void)

{
  int iVar1;
  void *pvVar2;
  int unaff_EBP;
  int *piVar3;
  
  FUN_00634c24();
  pvVar2 = operator_new(0x1bc);
  *(void **)(unaff_EBP + -0x10) = pvVar2;
  piVar3 = (int *)0x0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar2 != (void *)0x0) {
    piVar3 = (int *)FUN_005fab0b(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
                                 *(undefined4 *)(unaff_EBP + 0x10));
  }
  iVar1 = *piVar3;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(iVar1 + 0x14))(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc));
  (**(code **)(*piVar3 + 8))();
  (**(code **)*piVar3)();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return -(uint)(piVar3 != (int *)0x0) & (uint)(piVar3 + 0x5d);
}

