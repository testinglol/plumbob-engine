
undefined4 FUN_0042a8e3(void)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  void *pvVar4;
  undefined4 uVar5;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  sVar1 = *(short *)(unaff_EBP + 8);
  for (puVar3 = *(undefined4 **)(extraout_ECX + 0x194);
      (puVar3 != *(undefined4 **)(extraout_ECX + 0x198) && (*(short *)*puVar3 != sVar1));
      puVar3 = puVar3 + 1) {
  }
  if (puVar3 == *(undefined4 **)(extraout_ECX + 0x198)) {
    pvVar4 = operator_new(0x10);
    *(void **)(unaff_EBP + -0x10) = pvVar4;
    uVar5 = 0;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar4 != (void *)0x0) {
      uVar5 = FUN_0041f36b();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + 8) = uVar5;
    FUN_0042ec2b(unaff_EBP + 8);
    iVar2 = *(int *)(extraout_ECX + 0x198);
    **(short **)(iVar2 + -4) = sVar1;
    uVar5 = *(undefined4 *)(iVar2 + -4);
  }
  else {
    uVar5 = *puVar3;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

