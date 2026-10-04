
undefined1 FUN_00525055(void)

{
  int iVar1;
  char cVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  void *pvVar5;
  int *piVar6;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar2 = (**(code **)(*extraout_ECX + 200))();
  if (cVar2 == '\0') {
    cVar2 = FUN_005dbf32();
    uVar3 = 0;
    if (cVar2 != '\0') {
      (**(code **)(*extraout_ECX + 0x174))(1,0);
      FUN_005ddfdc(1);
      uVar4 = FUN_005e749a(0);
      FUN_005dde6d(uVar4);
      FUN_0046fca5();
      *(undefined ***)(unaff_EBP + -0x8c) = &PTR_FUN_0066643c;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      uVar4 = FUN_0041532c(9,unaff_EBP + -0x8c,0);
      cVar2 = FUN_004fff98(0x9c,uVar4);
      if (cVar2 != '\0') {
        uVar4 = FUN_004705f2(1,0xffffffff);
        FUN_005d4956(uVar4);
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_005dd9c8(unaff_EBP + -0x20);
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_005b8770();
      }
      FUN_005a5631(0x1e,unaff_EBP + -0x10,4);
      if (*(int **)(unaff_EBP + -0x10) != (int *)0x0) {
        (**(code **)(**(int **)(unaff_EBP + -0x10) + 0x68))(DAT_006f2a64);
        pvVar5 = operator_new(0x194);
        *(void **)(unaff_EBP + -0x14) = pvVar5;
        *(undefined1 *)(unaff_EBP + -4) = 2;
        if (pvVar5 == (void *)0x0) {
          piVar6 = (int *)0x0;
        }
        else {
          piVar6 = (int *)FUN_005e372a();
        }
        uVar4 = *(undefined4 *)(unaff_EBP + -0x10);
        extraout_ECX[0x3d] = (int)piVar6;
        iVar1 = *piVar6;
        *(undefined1 *)(unaff_EBP + -4) = 0;
        (**(code **)(iVar1 + 0x19c))(uVar4,4,1);
        *(undefined1 *)(extraout_ECX[0x3d] + 0x16b) = 1;
        (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x3d]);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_00470467();
      uVar3 = 1;
    }
  }
  else {
    uVar3 = FUN_005dbf32();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

