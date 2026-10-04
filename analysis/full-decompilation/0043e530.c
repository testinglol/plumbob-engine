
int * FUN_0043e530(void)

{
  char cVar1;
  int *piVar2;
  void *pvVar3;
  int unaff_EBP;
  
  FUN_00634c24();
  piVar2 = (int *)FUN_00411c32(*(undefined4 *)(unaff_EBP + 8));
  if (piVar2 == (int *)0x0) {
    pvVar3 = operator_new(0x268);
    *(void **)(unaff_EBP + -0x10) = pvVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar3 == (void *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = (int *)FUN_004567a6();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00465a37(*(undefined4 *)(unaff_EBP + 8),
                 (-(uint)(*(char *)(unaff_EBP + 0xc) != '\0') & 0xfffffffc) + 4);
    cVar1 = (**(code **)(*piVar2 + 0x28))();
    if (cVar1 == '\0') {
      if (piVar2 != (int *)0x0) {
        (**(code **)*piVar2)(1);
      }
      piVar2 = (int *)0x0;
      goto LAB_0043e5af;
    }
  }
  FUN_00411c82(piVar2);
LAB_0043e5af:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return piVar2;
}

