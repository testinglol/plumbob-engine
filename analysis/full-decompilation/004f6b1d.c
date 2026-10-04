
undefined4 FUN_004f6b1d(void)

{
  char cVar1;
  void *pvVar2;
  int *piVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_004f778b();
  *(undefined1 *)(unaff_EBP + -0x14) = *(undefined1 *)(*(int *)(extraout_ECX + 0x84) + 0x119);
  FUN_004d3f37(1);
  *(undefined4 *)(unaff_EBP + -0x10) = 0xffffffff;
  cVar1 = *(char *)(unaff_EBP + 0x18);
  pvVar2 = operator_new(0x144);
  *(void **)(unaff_EBP + 0x18) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar2 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_00526ef7(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),0,
                                 *(undefined4 *)(unaff_EBP + 0x10),*(undefined4 *)(unaff_EBP + 0x14)
                                 ,cVar1 != '\0',40000);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (piVar3 != (int *)0x0) {
    (**(code **)(*(int *)(extraout_ECX + 0x48) + 0x1c))
              (unaff_EBP + 0x10,unaff_EBP + 0x14,unaff_EBP + 0x18);
    FUN_005e57d4(*(undefined4 *)(unaff_EBP + 0x10),*(undefined4 *)(unaff_EBP + 0x14),
                 *(undefined4 *)(unaff_EBP + 0x18));
    FUN_005ddfdc(1);
    (**(code **)(*piVar3 + 0xc))();
    FUN_004e609e();
    cVar1 = FUN_004e6133();
    if (cVar1 == '\0') {
      (**(code **)(*piVar3 + 0x94))();
    }
    else {
      (**(code **)(*piVar3 + 0x98))();
      (**(code **)(*piVar3 + 0xa8))(1,0,0);
    }
    uVar4 = FUN_005daa44(0,piVar3);
    *(undefined4 *)(unaff_EBP + -0x10) = uVar4;
    FUN_005da4c7(piVar3);
  }
  FUN_004d3f37(*(undefined4 *)(unaff_EBP + -0x14));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x10);
}

