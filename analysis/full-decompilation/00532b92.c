
void FUN_00532b92(void)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  int *piVar6;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar2 = (**(code **)(*extraout_ECX + 200))();
  if (cVar2 == '\0') {
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0x90) = &PTR_FUN_0066643c;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    cVar2 = FUN_004fff98(0x8b,&DAT_006c265c,unaff_EBP + -0x90,0);
    if (cVar2 != '\0') {
      FUN_00471655(unaff_EBP + -0x14);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0046fc87(unaff_EBP + -0x1c,0);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      uVar3 = FUN_0046fc7a();
      FUN_005d4bbf(uVar3);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0042004f();
      FUN_0046fc87(unaff_EBP + -0x1c,0);
      *(undefined1 *)(unaff_EBP + -4) = 3;
      uVar3 = FUN_0046fc7a();
      FUN_005d4bbf(uVar3);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0042004f();
      FUN_0046fc87(unaff_EBP + -0x1c,0);
      *(undefined1 *)(unaff_EBP + -4) = 4;
      uVar3 = FUN_0046fc7a();
      FUN_005d4bbf(uVar3);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0042004f();
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_0042004f();
    }
    pvVar4 = operator_new(0x1ac);
    *(void **)(unaff_EBP + -0x10) = pvVar4;
    *(undefined1 *)(unaff_EBP + -4) = 5;
    if (pvVar4 == (void *)0x0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_0052c6db();
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    extraout_ECX[0x3e] = iVar5;
    if (iVar5 != 0) {
      (**(code **)(*extraout_ECX + 0x20))(iVar5);
      FUN_005e4071(DAT_006f2abc);
      (**(code **)(*(int *)extraout_ECX[0x3e] + 0x19c))(0,4,0);
      *(undefined4 *)(extraout_ECX[0x3e] + 0xf8) = 2;
      *(undefined4 *)(extraout_ECX[0x3e] + 0xf4) = 1;
      FUN_005e4a3a(1);
      piVar6 = (int *)FUN_005e40a5();
      iVar5 = extraout_ECX[0x21];
      iVar1 = extraout_ECX[0x1f];
      uVar3 = (**(code **)(*piVar6 + 0x58))();
      FUN_004cb1a2(iVar5 - iVar1,uVar3);
      FUN_004cb21d(0,(((*(int *)(extraout_ECX[0x3e] + 0x80) - *(int *)(extraout_ECX[0x3e] + 0x88)) -
                      extraout_ECX[0x20]) + extraout_ECX[0x22]) / 2);
    }
    pvVar4 = operator_new(0x84);
    *(void **)(unaff_EBP + -0x10) = pvVar4;
    *(undefined1 *)(unaff_EBP + -4) = 6;
    if (pvVar4 == (void *)0x0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_00510166(extraout_ECX[0x38],extraout_ECX[0x3b],extraout_ECX[0x3e],0,0,0,0,0,0);
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    extraout_ECX[0x40] = iVar5;
    if (iVar5 != 0) {
      FUN_005c1719();
      *(undefined1 *)(unaff_EBP + -4) = 7;
      cVar2 = FUN_00530b47(0xb,unaff_EBP + -0x24,unaff_EBP + -0x10);
      if (cVar2 != '\0') {
        iVar5 = unaff_EBP + -0x24;
        uVar3 = FUN_004096c2(iVar5);
        FUN_0051052c(0,uVar3,iVar5);
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_005a5e09();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00470467();
    FUN_005dbf32();
  }
  else {
    FUN_005dbf32();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

