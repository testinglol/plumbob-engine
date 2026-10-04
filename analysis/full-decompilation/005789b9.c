
undefined4 FUN_005789b9(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  int *piVar5;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar2 = DAT_006f63e8;
  *(int **)(unaff_EBP + -0x10) = &DAT_006f63e8;
  *(undefined ***)(unaff_EBP + -0x14) = &PTR_LAB_00669c88;
  (**(code **)(iVar2 + 4))();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x34) = 1;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  uVar3 = FUN_005fd96f();
  *(undefined4 *)(unaff_EBP + -0x1c) = uVar3;
  cVar1 = *(char *)(extraout_ECX + 4);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if ((((cVar1 != '\0') && (*(char *)(extraout_ECX + 0x3c) != '\0')) &&
      (*(char *)(extraout_ECX + 0x40a9) == '\0')) &&
     (((*(int *)(extraout_ECX + 0x28) != 0 &&
       (*(int *)(unaff_EBP + 0xc) < *(int *)(extraout_ECX + 0x28))) &&
      (*(undefined1 *)(extraout_ECX + 0x40b8) = *(undefined1 *)(unaff_EBP + 0x10),
      *(int *)(extraout_ECX + 0x40ac) == 0)))) {
    pvVar4 = operator_new(0x20);
    *(void **)(unaff_EBP + 0x10) = pvVar4;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    if (pvVar4 == (void *)0x0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)FUN_005ed88f();
    }
    *(int **)(extraout_ECX + 0x40ac) = piVar5;
    iVar2 = *piVar5;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    (**(code **)(iVar2 + 0x20))(FUN_00578941,extraout_ECX);
    (**(code **)**(undefined4 **)(extraout_ECX + 0x40ac))(100);
    iVar2 = *(int *)(unaff_EBP + 0xc);
    *(int *)(extraout_ECX + 0x40b4) = iVar2;
    *(int *)(extraout_ECX + 0x40b0) = (iVar2 - *(int *)(extraout_ECX + 0x28)) / 0x14;
    (**(code **)(**(int **)(extraout_ECX + 0x40ac) + 0x10))(*(int *)(unaff_EBP + 8) / 10);
    *(undefined1 *)(extraout_ECX + 0x40a9) = 1;
  }
  iVar2 = DAT_006f63e8;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(iVar2 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

