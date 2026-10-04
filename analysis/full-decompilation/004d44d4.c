
int * FUN_004d44d4(void)

{
  char cVar1;
  void *pvVar2;
  int *piVar3;
  int unaff_EBP;
  
  FUN_00634c24();
  pvVar2 = operator_new(0x94);
  *(void **)(unaff_EBP + -0x10) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar2 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_004d4529();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if ((piVar3 == (int *)0x0) || (cVar1 = (**(code **)(*piVar3 + 4))(), cVar1 != '\0')) {
    piVar3 = (int *)0x0;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return piVar3;
}

