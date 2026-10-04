
void FUN_005555bb(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  void *pvVar6;
  int iVar7;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0xdc) = &PTR_FUN_0066643c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar5 = FUN_0041532c(9,unaff_EBP + -0xdc,0);
  FUN_004fff98(0xab,uVar5);
  *(undefined1 *)(unaff_EBP + -0xd) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  do {
    pvVar6 = operator_new(0x194);
    *(void **)(unaff_EBP + -0x40) = pvVar6;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    if (pvVar6 == (void *)0x0) {
      iVar7 = 0;
    }
    else {
      iVar7 = FUN_005e372a();
    }
    iVar2 = *(int *)(unaff_EBP + -0x18);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    piVar1 = (int *)(extraout_ECX + 0xf8 + iVar2 * 4);
    *piVar1 = iVar7;
    if (iVar2 == 0) {
      FUN_005a5631(0x13d4,unaff_EBP + -0x14,4);
      uVar5 = FUN_004705f2(0xd,0xffffffff);
      FUN_005d4956(uVar5);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_005dd9c8(unaff_EBP + -100);
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_005b8770();
      uVar5 = 0x1000;
LAB_0055589c:
      uVar4 = FUN_00555a79(uVar5);
      *(undefined1 *)(unaff_EBP + -0xd) = uVar4;
    }
    else {
      if (iVar2 == 1) {
        FUN_005a5631(0x13c9,unaff_EBP + -0x14,4);
        uVar5 = FUN_004705f2(2,0xffffffff);
        FUN_005d4956(uVar5);
        *(undefined1 *)(unaff_EBP + -4) = 3;
        FUN_005dd9c8(unaff_EBP + -0x4c);
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_005b8770();
        uVar5 = 0x20;
        goto LAB_0055589c;
      }
      if (iVar2 == 2) {
        FUN_005a5631(0x13c7,unaff_EBP + -0x14,4);
        uVar5 = FUN_004705f2(3,0xffffffff);
        FUN_005d4956(uVar5);
        *(undefined1 *)(unaff_EBP + -4) = 4;
        FUN_005dd9c8(unaff_EBP + -0x3c);
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_005b8770();
        uVar5 = 8;
        goto LAB_0055589c;
      }
      if (iVar2 == 3) {
        FUN_005a5631(0x13c6,unaff_EBP + -0x14,4);
        uVar5 = FUN_004705f2(4,0xffffffff);
        FUN_005d4956(uVar5);
        *(undefined1 *)(unaff_EBP + -4) = 5;
        FUN_005dd9c8(unaff_EBP + -0x30);
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_005b8770();
        uVar5 = 4;
        goto LAB_0055589c;
      }
      if (iVar2 == 4) {
        FUN_005a5631(0x13c5,unaff_EBP + -0x14,4);
        uVar5 = FUN_004705f2(5,0xffffffff);
        FUN_005d4956(uVar5);
        *(undefined1 *)(unaff_EBP + -4) = 6;
        FUN_005dd9c8(unaff_EBP + -0x70);
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_005b8770();
        uVar5 = 2;
        goto LAB_0055589c;
      }
      if (iVar2 == 5) {
        FUN_005a5631(0x13ca,unaff_EBP + -0x14,4);
        uVar5 = FUN_004705f2(6,0xffffffff);
        FUN_005d4956(uVar5);
        *(undefined1 *)(unaff_EBP + -4) = 7;
        FUN_005dd9c8(unaff_EBP + -0x24);
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_005b8770();
        uVar5 = 0x40;
        goto LAB_0055589c;
      }
      if (iVar2 == 6) {
        FUN_005a5631(0x13d3,unaff_EBP + -0x14,4);
        uVar5 = FUN_004705f2(0xc,0xffffffff);
        FUN_005d4956(uVar5);
        *(undefined1 *)(unaff_EBP + -4) = 8;
        FUN_005dd9c8(unaff_EBP + -0x58);
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_005b8770();
        uVar5 = 0x800;
        goto LAB_0055589c;
      }
    }
    if (*(int **)(unaff_EBP + -0x14) != (int *)0x0) {
      (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x68))(DAT_006f2a64);
    }
    (**(code **)(*(int *)*piVar1 + 0x19c))(*(undefined4 *)(unaff_EBP + -0x14),4,1);
    *(undefined1 *)(*piVar1 + 0x16b) = 1;
    FUN_005e4817(0,s_UI_Nhood_click_006cd914,0,0);
    piVar3 = (int *)*piVar1;
    if ((char)piVar3[0x5a] != *(char *)(unaff_EBP + -0xd)) {
      *(char *)(piVar3 + 0x5a) = *(char *)(unaff_EBP + -0xd);
      (**(code **)(*piVar3 + 0x168))();
    }
    FUN_004cb21d(*(undefined4 *)(&DAT_006f5480 + *(int *)(unaff_EBP + -0x18) * 8),
                 *(undefined4 *)(&DAT_006f5484 + *(int *)(unaff_EBP + -0x18) * 8));
    (**(code **)(**(int **)(extraout_ECX + 0x188) + 0x20))(*piVar1);
    *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
    if (6 < *(int *)(unaff_EBP + -0x18)) {
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_00470467();
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return;
    }
  } while( true );
}

