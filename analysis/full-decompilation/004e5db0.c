
int * FUN_004e5db0(void)

{
  int iVar1;
  char cVar2;
  void *pvVar3;
  int *piVar4;
  int *extraout_ECX;
  undefined4 extraout_ECX_00;
  int unaff_EBP;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  FUN_00634c24();
  uStack_14 = 0x4e5dc6;
  pvVar3 = operator_new(100);
  *(void **)(unaff_EBP + -0x10) = pvVar3;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar3 == (void *)0x0) {
    piVar4 = (int *)0x0;
    uStack_20 = 0;
  }
  else {
    piVar4 = (int *)FUN_005dfb13();
    uStack_20 = extraout_ECX_00;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uStack_14 = 0;
  uStack_18 = 0;
  *(undefined4 **)(unaff_EBP + -0x10) = &uStack_20;
  *extraout_ECX = (int)piVar4;
  iVar1 = *piVar4;
  uStack_1c = uStack_20;
  FUN_00436a50(4);
  cVar2 = (**(code **)(iVar1 + 0xc))(200,200);
  if ((cVar2 == '\0') && ((undefined4 *)*extraout_ECX != (undefined4 *)0x0)) {
    (*(code *)**(undefined4 **)*extraout_ECX)(1);
  }
  if (*extraout_ECX != 0) {
    cVar2 = FUN_005df69e();
    if ((cVar2 == '\0') && ((undefined4 *)*extraout_ECX != (undefined4 *)0x0)) {
      (*(code *)**(undefined4 **)*extraout_ECX)(1);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

