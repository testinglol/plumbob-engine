
undefined4 FUN_005df761(void)

{
  int iVar1;
  char cVar2;
  void *pvVar3;
  int *piVar4;
  undefined4 uVar5;
  int *extraout_ECX;
  int unaff_EBP;
  undefined1 auStack_24 [8];
  undefined4 uStack_1c;
  uint uStack_18;
  
  FUN_00634c24();
  uStack_18 = 0x5df778;
  pvVar3 = operator_new(100);
  *(void **)(unaff_EBP + -0x10) = pvVar3;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar3 == (void *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)FUN_005dfb13();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (piVar4 != (int *)0x0) {
    cVar2 = (**(code **)(*extraout_ECX + 0x34))();
    uStack_18 = (uint)(cVar2 != '\0');
    iVar1 = *piVar4;
    uStack_1c = 0;
    *(undefined1 **)(unaff_EBP + -0x10) = auStack_24;
    FUN_00436a50(3);
    uVar5 = FUN_005d90f7();
    uVar5 = FUN_005df7fb(uVar5);
    cVar2 = (**(code **)(iVar1 + 0xc))(uVar5);
    if (cVar2 != '\0') {
      extraout_ECX[0x18] = (int)piVar4;
      FUN_005e357a();
      uVar5 = 1;
      goto LAB_005df7ec;
    }
    (**(code **)*piVar4)(1);
  }
  uVar5 = 0;
LAB_005df7ec:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

