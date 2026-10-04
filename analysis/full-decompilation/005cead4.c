
undefined4 FUN_005cead4(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  puVar1 = *(undefined4 **)(unaff_EBP + 8);
  *puVar1 = 0;
  pvVar2 = operator_new(0xcc);
  *(void **)(unaff_EBP + -0x10) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar2 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_005d033c(extraout_ECX,*(undefined4 *)(unaff_EBP + 0xc),
                                 *(undefined4 *)(unaff_EBP + 0x10),*(undefined4 *)(unaff_EBP + 0x14)
                                 ,*(undefined4 *)(unaff_EBP + 0x18),
                                 *(undefined4 *)(unaff_EBP + 0x1c));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(int **)(unaff_EBP + 8) = piVar3;
  if (piVar3 == (int *)0x0) {
    uVar4 = 0x9b0b0001;
  }
  else {
    (**(code **)(*piVar3 + 4))();
    (**(code **)(**(int **)(unaff_EBP + 8) + 4))();
    FUN_005cf1fd(unaff_EBP + 8);
    *puVar1 = *(undefined4 *)(unaff_EBP + 8);
    uVar4 = 0;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

