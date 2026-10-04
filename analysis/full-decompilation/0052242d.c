
undefined4 FUN_0052242d(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  void *pvVar5;
  int iVar6;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar1 = (**(code **)(*extraout_ECX + 200))();
  if (cVar1 == '\0') {
    FUN_005dbf32();
    FUN_005a5631(0xbc0,extraout_ECX + 0x4a,4);
    FUN_005a5631(0x50,extraout_ECX + 0x4b,4);
    FUN_005a5631(0x51,extraout_ECX + 0x4c,4);
    uVar2 = FUN_0041532c(9,extraout_ECX + 0x50,0);
    FUN_004fff98(0xb4,uVar2);
    FUN_005ddfdc(1);
    (**(code **)(*extraout_ECX + 0x60))(0,0,DAT_006f3b00,DAT_006f3b04);
    FUN_004cb21d(DAT_006f3b08,DAT_006f3b0c);
    FUN_004cb1a2(0x28c,0x1aa);
    iVar3 = FUN_004b46a0();
    (**(code **)(*extraout_ECX + 100))(iVar3 + 0x7c);
    uVar2 = FUN_004705f2(2,0xffffffff);
    FUN_005d4956(uVar2);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    piVar4 = (int *)FUN_005e7743();
    iVar3 = (**(code **)(*piVar4 + 0x24))(0,unaff_EBP + -0x1c);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[0x46] = iVar3;
    FUN_005b8770();
    if ((int *)extraout_ECX[0x46] != (int *)0x0) {
      (**(code **)(*(int *)extraout_ECX[0x46] + 0x90))(0x2000,1);
      FUN_004cb21d(0x14,(((*(int *)(extraout_ECX[0x46] + 0x80) - *(int *)(extraout_ECX[0x46] + 0x88)
                          ) * 3) / 2 - extraout_ECX[0x20]) + extraout_ECX[0x22]);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x46]);
    }
    piVar4 = (int *)FUN_005e7743();
    iVar3 = *piVar4;
    *(int **)(unaff_EBP + -0x10) = piVar4;
    uVar2 = FUN_005e50fa(1);
    piVar4 = (int *)(**(code **)(iVar3 + 0x24))(1,uVar2);
    extraout_ECX[0x47] = (int)piVar4;
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 0x90))(0x2000,1);
      iVar3 = extraout_ECX[0x47];
      FUN_004cb21d(((extraout_ECX[0x21] - *(int *)(iVar3 + 0x84)) - extraout_ECX[0x1f]) + -0x14 +
                   *(int *)(iVar3 + 0x7c),
                   (((*(int *)(iVar3 + 0x80) - *(int *)(iVar3 + 0x88)) * 3) / 2 - extraout_ECX[0x20]
                   ) + extraout_ECX[0x22]);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x47]);
    }
    iVar3 = FUN_0042573e(extraout_ECX[0x43]);
    if (iVar3 == 0) {
      FUN_006358b0(unaff_EBP + -0x428,&DAT_006c3d7c);
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(DAT_006e486c + 0x28);
      uVar2 = FUN_00401f73();
      FUN_0043acf5(uVar2);
      uVar2 = thunk_FUN_00457ea7();
      FUN_005b86bd(uVar2);
      *(undefined4 *)(unaff_EBP + -4) = 1;
      uVar2 = FUN_004096c2();
      FUN_006358b0(unaff_EBP + -0x428,uVar2);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
    }
    FUN_006358c0(unaff_EBP + -0x428,&DAT_006c3d7c);
    uVar2 = FUN_004705f2(3,0xffffffff);
    FUN_006358c0(unaff_EBP + -0x428,uVar2);
    FUN_005233a4();
    FUN_005d4956(unaff_EBP + -0x428);
    *(undefined4 *)(unaff_EBP + -4) = 2;
    piVar4 = (int *)FUN_005e7743();
    iVar3 = (**(code **)(*piVar4 + 0x28))(0,unaff_EBP + -0x28);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[0x48] = iVar3;
    FUN_005b8770();
    if ((int *)extraout_ECX[0x48] != (int *)0x0) {
      (**(code **)(*(int *)extraout_ECX[0x48] + 0x60))(0,0,0x21c,0x19);
      FUN_004cb21d(DAT_006f3ae0,DAT_006f3ae4);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x48]);
    }
    pvVar5 = operator_new(0x118);
    *(void **)(unaff_EBP + -0x10) = pvVar5;
    *(undefined4 *)(unaff_EBP + -4) = 3;
    if (pvVar5 == (void *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_005f4d1c();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[0x44] = iVar3;
    if (iVar3 != 0) {
      FUN_005f58c2(extraout_ECX[0x49]);
      *(undefined4 *)(extraout_ECX[0x44] + 0xe8) = 10;
      iVar3 = *(int *)extraout_ECX[0x44];
      iVar6 = (**(code **)(*(int *)extraout_ECX[0x49] + 0x58))();
      (**(code **)(iVar3 + 0x60))(0,0,DAT_006f3af0,iVar6 * 10);
      FUN_004cb21d(DAT_006f3af8,DAT_006f3afc);
      uVar2 = FUN_005dd5e1(0,0,0x39);
      *(undefined4 *)(extraout_ECX[0x44] + 100) = uVar2;
      FUN_004ec186(DAT_006f3af0 + 10);
      FUN_004ec1a7(DAT_006f3af4);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x44]);
    }
    pvVar5 = operator_new(0x118);
    *(void **)(unaff_EBP + -0x10) = pvVar5;
    *(undefined4 *)(unaff_EBP + -4) = 4;
    if (pvVar5 == (void *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_005f4d1c();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[0x45] = iVar3;
    if (iVar3 != 0) {
      FUN_005f58c2(extraout_ECX[0x49]);
      *(undefined4 *)(extraout_ECX[0x45] + 0xe8) = 10;
      iVar3 = *(int *)extraout_ECX[0x45];
      iVar6 = (**(code **)(*(int *)extraout_ECX[0x49] + 0x58))();
      (**(code **)(iVar3 + 0x60))(0,0,DAT_006f3af0,iVar6 * 10);
      FUN_004cb21d(DAT_006f3ae8,DAT_006f3aec);
      uVar2 = FUN_005dd5e1(0,0,0x39);
      *(undefined4 *)(extraout_ECX[0x45] + 100) = uVar2;
      FUN_004ec186(DAT_006f3af0 + 10);
      FUN_004ec1a7(DAT_006f3af4);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x45]);
    }
    FUN_00522ed3();
    iVar3 = FUN_005f51ce();
    if (iVar3 == 0) {
      piVar4 = (int *)extraout_ECX[0x46];
      if ((char)piVar4[0x5a] != '\0') {
        *(undefined1 *)(piVar4 + 0x5a) = 0;
        (**(code **)(*piVar4 + 0x168))();
      }
    }
    else {
      FUN_005f5543(0);
    }
    FUN_005230a9();
    iVar3 = FUN_005f51ce();
    if (iVar3 != 0) {
      FUN_005f5543(0);
    }
    (**(code **)(*extraout_ECX + 0x90))(0x2000,1);
    uVar2 = 1;
  }
  else {
    uVar2 = FUN_005dbf32();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

