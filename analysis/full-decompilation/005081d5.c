
undefined1 FUN_005081d5(void)

{
  bool bVar1;
  char cVar2;
  undefined1 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar2 = (**(code **)(*extraout_ECX + 200))();
  if (cVar2 == '\0') {
    (**(code **)(*extraout_ECX + 0x90))(0x10,0);
    piVar4 = (int *)FUN_005e7743();
    iVar5 = (**(code **)(*piVar4 + 0x10))(5);
    extraout_ECX[0x45] = iVar5;
    FUN_004cb1a2(0x22f,0x7f);
    extraout_ECX[0x37] = DAT_006f2a94;
    extraout_ECX[0x36] = DAT_006f2a9c;
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0x7c) = &PTR_FUN_0066643c;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    uVar6 = FUN_0041532c(9,unaff_EBP + -0x7c,0);
    cVar2 = FUN_004fff98(0xa0,uVar6);
    if (cVar2 != '\0') {
      *(int **)(unaff_EBP + -0x10) = extraout_ECX + 0x48;
      iVar5 = 1;
      do {
        iVar7 = FUN_004705f2(iVar5,0xffffffff);
        if (iVar7 != 0) {
          uVar6 = FUN_004705f2(iVar5,0xffffffff);
          FUN_005d4bbf(uVar6);
        }
        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 0xc;
        bVar1 = iVar5 < 0xe;
        iVar5 = iVar5 + 1;
      } while (bVar1);
      uVar6 = FUN_004705f2(0xf,0xffffffff);
      FUN_005d4bbf(uVar6);
      uVar6 = FUN_004705f2(0x10,0xffffffff);
      FUN_005d4bbf(uVar6);
      uVar6 = FUN_004705f2(0x12,0xffffffff);
      FUN_005d4bbf(uVar6);
      uVar6 = FUN_004705f2(0x13,0xffffffff);
      FUN_005d4bbf(uVar6);
      uVar6 = FUN_004705f2(0x14,0xffffffff);
      FUN_005d4bbf(uVar6);
      uVar6 = FUN_004705f2(0x11,0xffffffff);
      FUN_005d4bbf(uVar6);
    }
    uVar3 = FUN_005dbf32();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00470467();
  }
  else {
    uVar3 = FUN_005dbf32();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

