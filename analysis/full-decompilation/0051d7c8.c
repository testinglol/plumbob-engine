
void FUN_0051d7c8(void)

{
  int *piVar1;
  char cVar2;
  void *pvVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int extraout_ECX;
  int unaff_EBP;
  int iVar12;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x40) = 0;
  *(undefined4 *)(unaff_EBP + -0x3c) = 0;
  *(undefined4 *)(unaff_EBP + -0x38) = 0;
  *(undefined4 *)(unaff_EBP + -0x34) = 0;
  *(undefined4 *)(unaff_EBP + -0x30) = 0;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  iVar4 = *(int *)(extraout_ECX + 0x2f0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (iVar4 == 0) {
    pvVar3 = operator_new(0x84);
    *(void **)(unaff_EBP + -0x10) = pvVar3;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    if (pvVar3 == (void *)0x0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_00510166(0,0,0,0,0,0,0,0,0);
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    *(int *)(extraout_ECX + 0x2f0) = iVar4;
    if (iVar4 != 0) {
      FUN_005202d1(&PTR_s_ndex_006c6568_0xa_006c2994,0xffffffff);
      FUN_0046f8e4(unaff_EBP + -0x60);
    }
  }
  piVar1 = (int *)(extraout_ECX + 0x14c);
  if ((uint)(*(int *)(extraout_ECX + 0x150) - *piVar1 >> 2) < *(uint *)(extraout_ECX + 0x188)) {
    do {
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      FUN_00520283(unaff_EBP + -0x14);
      cVar2 = *(char *)(extraout_ECX + 0x2f4);
      *(int *)(unaff_EBP + -0x14) = (*(int *)(extraout_ECX + 0x150) - *piVar1 >> 2) + -1;
      if (cVar2 == '\0') {
        FUN_0046fca5();
        *(undefined ***)(unaff_EBP + -0xcc) = &PTR_FUN_0066643c;
        *(undefined1 *)(unaff_EBP + -4) = 4;
        cVar2 = FUN_004fff98(0x84,&DAT_006c265c,unaff_EBP + -0xcc,0);
        if (cVar2 == '\0') {
          *(undefined1 *)(unaff_EBP + -4) = 0;
          FUN_00470467();
LAB_0051df94:
          ExceptionList = *(void **)(unaff_EBP + -0xc);
          return;
        }
        FUN_00471655(unaff_EBP + -0x1c);
        *(undefined1 *)(unaff_EBP + -4) = 5;
        FUN_0046fc87(unaff_EBP + -0x54,0);
        *(undefined1 *)(unaff_EBP + -4) = 6;
        uVar5 = FUN_0046fc7a();
        FUN_005d4bbf(uVar5);
        *(undefined1 *)(unaff_EBP + -4) = 5;
        FUN_0042004f();
        pvVar3 = operator_new(0x1d4);
        *(void **)(unaff_EBP + -0x10) = pvVar3;
        *(undefined1 *)(unaff_EBP + -4) = 7;
        if (pvVar3 == (void *)0x0) {
          uVar5 = 0;
        }
        else {
          uVar5 = FUN_00527ffb(*(undefined4 *)(extraout_ECX + 0x2f0),unaff_EBP + -0x1c);
        }
        iVar4 = *piVar1;
        *(undefined1 *)(unaff_EBP + -4) = 4;
        iVar12 = *(int *)(unaff_EBP + -0x14) * 4;
        *(undefined4 *)(iVar4 + iVar12) = uVar5;
        *(undefined1 *)(extraout_ECX + 0x2f4) = 1;
        FUN_0042004f();
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_00470467();
      }
      else {
        FUN_0046fc56();
        *(undefined1 *)(unaff_EBP + -4) = 2;
        pvVar3 = operator_new(0x1d4);
        *(void **)(unaff_EBP + -0x10) = pvVar3;
        *(undefined1 *)(unaff_EBP + -4) = 3;
        if (pvVar3 == (void *)0x0) {
          uVar5 = 0;
        }
        else {
          uVar5 = FUN_00527ffb(*(undefined4 *)(extraout_ECX + 0x2f0),unaff_EBP + -0x48);
        }
        iVar4 = *piVar1;
        *(undefined1 *)(unaff_EBP + -4) = 0;
        iVar12 = *(int *)(unaff_EBP + -0x14) * 4;
        *(undefined4 *)(iVar4 + iVar12) = uVar5;
        FUN_0042004f();
      }
      if ((*(int *)(*piVar1 + iVar12) == 0) ||
         (cVar2 = (**(code **)(**(int **)(*piVar1 + iVar12) + 0xc))(), cVar2 == '\0'))
      goto LAB_0051df94;
      (**(code **)(**(int **)(*piVar1 + iVar12) + 0x98))();
      (**(code **)(**(int **)(extraout_ECX + 0x10c) + 0x20))(*(undefined4 *)(*piVar1 + iVar12));
    } while ((uint)(*(int *)(extraout_ECX + 0x150) - *piVar1 >> 2) < *(uint *)(extraout_ECX + 0x188)
            );
  }
  if (*(int *)(*(int *)(extraout_ECX + 0x19c) + 0xe0) == 1) {
    uVar5 = 0;
  }
  else if (*(int *)(*(int *)(extraout_ECX + 0x1a0) + 0xe0) == 1) {
    uVar5 = 1;
  }
  else {
    if (*(int *)(*(int *)(extraout_ECX + 0x1a4) + 0xe0) != 1) goto LAB_0051da7a;
    uVar5 = 2;
  }
  uVar5 = FUN_004e99a9(extraout_ECX + 0x1b8,uVar5);
  FUN_004e9f27(uVar5);
LAB_0051da7a:
  if (*(int *)(*(int *)(extraout_ECX + 0x1a8) + 0xe0) == 1) {
    uVar5 = FUN_004e99a9(extraout_ECX + 0x1b8,3);
    FUN_004e9f27(uVar5);
  }
  if (*(int *)(extraout_ECX + 400) < 0) {
    *(undefined4 *)(extraout_ECX + 400) = 0;
  }
  do {
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    while( true ) {
      if (*(int *)(extraout_ECX + 0x188) <= *(int *)(unaff_EBP + -0x14)) {
        cVar2 = FUN_004cff80();
        iVar4 = *(int *)(extraout_ECX + 0x10c);
        if (cVar2 == '\0') {
          iVar12 = *(int *)(extraout_ECX + 0x194);
          iVar7 = *(int *)(extraout_ECX + 0x19c);
          *(int *)(unaff_EBP + -0x10) = iVar12 + 0x7c;
          *(int *)(unaff_EBP + -0x18) = iVar7 + 0x7c;
          iVar12 = *(int *)(iVar12 + 0x84);
          iVar7 = *(int *)(iVar7 + 0x84);
          iVar8 = **(int **)(unaff_EBP + -0x10);
          iVar9 = **(int **)(unaff_EBP + -0x18);
          iVar10 = *(int *)(iVar4 + 0x84);
          iVar4 = *(int *)(iVar4 + 0x7c);
          *(undefined4 *)(unaff_EBP + -0x3c) = 0x12;
          *(int *)(unaff_EBP + -0x40) = (((iVar12 + iVar7) - iVar8) - iVar9) + 6;
          *(undefined4 *)(unaff_EBP + -0x2c) = 0x96;
          *(int *)(unaff_EBP + -0x30) = (iVar10 - iVar4) + -2;
        }
        else {
          iVar12 = *(int *)(extraout_ECX + 0x194);
          iVar7 = *(int *)(extraout_ECX + 0x19c);
          *(int *)(unaff_EBP + -0x10) = iVar12 + 0x7c;
          iVar12 = *(int *)(iVar12 + 0x84);
          iVar8 = *(int *)(iVar7 + 0x84);
          iVar7 = *(int *)(iVar7 + 0x7c);
          iVar9 = **(int **)(unaff_EBP + -0x10);
          iVar10 = *(int *)(iVar4 + 0x84);
          iVar4 = *(int *)(iVar4 + 0x7c);
          *(undefined4 *)(unaff_EBP + -0x3c) = 0x23;
          *(int *)(unaff_EBP + -0x40) = (((iVar12 + iVar8) - iVar7) - iVar9) + 6;
          *(undefined4 *)(unaff_EBP + -0x2c) = 0x8c;
          *(int *)(unaff_EBP + -0x30) = (iVar10 - iVar4) + -2;
        }
        piVar1 = (int *)*piVar1;
        uVar5 = *(undefined4 *)(extraout_ECX + 0x188);
        iVar4 = *piVar1;
        iVar12 = *(int *)(iVar4 + 0x88);
        iVar7 = *(int *)(iVar4 + 0x80);
        *(int *)(unaff_EBP + -0x38) = *(int *)(iVar4 + 0x84) - *(int *)(iVar4 + 0x7c);
        *(int *)(unaff_EBP + -0x34) = iVar12 - iVar7;
        iVar4 = *piVar1;
        iVar12 = *(int *)(iVar4 + 0x88);
        iVar7 = *(int *)(iVar4 + 0x84);
        iVar8 = *(int *)(iVar4 + 0x80);
        iVar4 = *(int *)(iVar4 + 0x7c);
        *(undefined4 *)(unaff_EBP + -0x20) = 0;
        *(int *)(unaff_EBP + -0x24) = iVar12 - iVar8;
        *(int *)(unaff_EBP + -0x28) = iVar7 - iVar4;
        FUN_004ebf01(piVar1,uVar5);
        cVar2 = FUN_004cff80();
        if (cVar2 == '\0') {
          iVar4 = (**(code **)(*DAT_006f2a8c + 0x58))();
          FUN_004cb21d(3,iVar4 + 1);
          iVar4 = *(int *)(*(int *)(extraout_ECX + 0x19c) + 0x88);
          iVar12 = *(int *)(*(int *)(extraout_ECX + 0x19c) + 0x80);
          iVar7 = (**(code **)(*DAT_006f2a8c + 0x58))();
          FUN_004cb21d(2,iVar7 + 2 + (iVar4 - iVar12));
          iVar4 = *(int *)(*(int *)(extraout_ECX + 0x19c) + 0x88);
          iVar12 = *(int *)(*(int *)(extraout_ECX + 0x19c) + 0x80);
          *(int *)(unaff_EBP + -0x10) =
               *(int *)(*(int *)(extraout_ECX + 0x1a0) + 0x88) -
               *(int *)(*(int *)(extraout_ECX + 0x1a0) + 0x80);
          iVar7 = (**(code **)(*DAT_006f2a8c + 0x58))();
          FUN_004cb21d(2,iVar7 + *(int *)(unaff_EBP + -0x10) + 3 + (iVar4 - iVar12));
          iVar4 = *(int *)(extraout_ECX + 0x1a0);
          *(int *)(unaff_EBP + -0x18) =
               *(int *)(*(int *)(extraout_ECX + 0x19c) + 0x88) -
               *(int *)(*(int *)(extraout_ECX + 0x19c) + 0x80);
          iVar12 = *(int *)(extraout_ECX + 0x1a4);
          *(int *)(unaff_EBP + -0x10) = *(int *)(iVar4 + 0x88) - *(int *)(iVar4 + 0x80);
          iVar4 = *(int *)(iVar12 + 0x88);
          iVar12 = *(int *)(iVar12 + 0x80);
          iVar7 = (**(code **)(*DAT_006f2a8c + 0x58))();
          iVar4 = iVar7 + *(int *)(unaff_EBP + -0x10) + *(int *)(unaff_EBP + -0x18) + 4 +
                  (iVar4 - iVar12);
        }
        else {
          iVar4 = (**(code **)(*DAT_006f2a8c + 0x58))();
          FUN_004cb21d(3,iVar4 + 0x28);
          iVar4 = *(int *)(*(int *)(extraout_ECX + 0x19c) + 0x88);
          iVar12 = *(int *)(*(int *)(extraout_ECX + 0x19c) + 0x80);
          iVar7 = (**(code **)(*DAT_006f2a8c + 0x58))();
          FUN_004cb21d(2,iVar7 + 0x29 + (iVar4 - iVar12));
          iVar4 = *(int *)(*(int *)(extraout_ECX + 0x19c) + 0x88);
          iVar12 = *(int *)(*(int *)(extraout_ECX + 0x19c) + 0x80);
          *(int *)(unaff_EBP + -0x10) =
               *(int *)(*(int *)(extraout_ECX + 0x1a0) + 0x88) -
               *(int *)(*(int *)(extraout_ECX + 0x1a0) + 0x80);
          iVar7 = (**(code **)(*DAT_006f2a8c + 0x58))();
          FUN_004cb21d(2,iVar7 + *(int *)(unaff_EBP + -0x10) + 0x2a + (iVar4 - iVar12));
          iVar4 = *(int *)(extraout_ECX + 0x1a0);
          *(int *)(unaff_EBP + -0x18) =
               *(int *)(*(int *)(extraout_ECX + 0x19c) + 0x88) -
               *(int *)(*(int *)(extraout_ECX + 0x19c) + 0x80);
          iVar12 = *(int *)(extraout_ECX + 0x1a4);
          *(int *)(unaff_EBP + -0x10) = *(int *)(iVar4 + 0x88) - *(int *)(iVar4 + 0x80);
          iVar4 = *(int *)(iVar12 + 0x88);
          iVar12 = *(int *)(iVar12 + 0x80);
          iVar7 = (**(code **)(*DAT_006f2a8c + 0x58))();
          iVar4 = iVar7 + *(int *)(unaff_EBP + -0x10) + *(int *)(unaff_EBP + -0x18) + 0x2b +
                  (iVar4 - iVar12);
        }
        FUN_004cb21d(2,iVar4);
        iVar4 = *(int *)(*(int *)(extraout_ECX + 0x10c) + 0x88);
        iVar12 = *(int *)(*(int *)(extraout_ECX + 0x10c) + 0x80);
        iVar7 = *(int *)(extraout_ECX + 0x19c);
        *(int *)(unaff_EBP + -0x10) =
             *(int *)(*(int *)(extraout_ECX + 0x194) + 0x88) -
             *(int *)(*(int *)(extraout_ECX + 0x194) + 0x80);
        *(int *)(unaff_EBP + -0x18) = *(int *)(iVar7 + 0x84) - *(int *)(iVar7 + 0x7c);
        iVar8 = (**(code **)(*DAT_006f2a8c + 0x58))();
        iVar7 = *(int *)(unaff_EBP + -0x10);
        iVar9 = (**(code **)(*DAT_006f2a8c + 0x58))();
        FUN_004cb21d(*(int *)(unaff_EBP + -0x18) + 4,
                     (((iVar4 - iVar12) - iVar7) - iVar8) / 2 + iVar9);
        iVar4 = *(int *)(extraout_ECX + 0x10c);
        iVar12 = *(int *)(iVar4 + 0x88);
        iVar7 = *(int *)(iVar4 + 0x80);
        iVar8 = *(int *)(iVar4 + 0x84);
        iVar4 = *(int *)(iVar4 + 0x7c);
        iVar9 = *(int *)(extraout_ECX + 0x198);
        *(int *)(unaff_EBP + -0x10) =
             *(int *)(*(int *)(extraout_ECX + 0x194) + 0x88) -
             *(int *)(*(int *)(extraout_ECX + 0x194) + 0x80);
        *(int *)(unaff_EBP + -0x18) = iVar8 - iVar4;
        iVar4 = *(int *)(iVar9 + 0x84);
        iVar8 = *(int *)(iVar9 + 0x7c);
        iVar10 = (**(code **)(*DAT_006f2a8c + 0x58))();
        iVar9 = *(int *)(unaff_EBP + -0x10);
        iVar11 = (**(code **)(*DAT_006f2a8c + 0x58))();
        FUN_004cb21d((*(int *)(unaff_EBP + -0x18) - (iVar4 - iVar8)) + -2,
                     (((iVar12 - iVar7) - iVar9) - iVar10) / 2 + iVar11);
        if (*(int *)(extraout_ECX + 400) < 1) {
          (**(code **)(**(int **)(extraout_ECX + 0x194) + 0x98))();
        }
        else {
          (**(code **)(**(int **)(extraout_ECX + 0x194) + 0x94))();
        }
        if ((uint)((*(int *)(extraout_ECX + 400) + 1) * *(int *)(extraout_ECX + 0x188)) <
            (uint)(*(int *)(extraout_ECX + 0x1bc) - *(int *)(extraout_ECX + 0x1b8) >> 2)) {
          (**(code **)(**(int **)(extraout_ECX + 0x198) + 0x94))();
        }
        else {
          (**(code **)(**(int **)(extraout_ECX + 0x198) + 0x98))();
        }
        goto LAB_0051df94;
      }
      uVar6 = *(int *)(extraout_ECX + 400) * *(int *)(extraout_ECX + 0x188) +
              *(int *)(unaff_EBP + -0x14);
      if (((*(int *)(unaff_EBP + -0x14) == 0) &&
          ((uint)(*(int *)(extraout_ECX + 0x1bc) - *(int *)(extraout_ECX + 0x1b8) >> 2) <= uVar6))
         && (0 < *(int *)(extraout_ECX + 400))) break;
      if (uVar6 < (uint)(*(int *)(extraout_ECX + 0x1bc) - *(int *)(extraout_ECX + 0x1b8) >> 2)) {
        *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(extraout_ECX + 0x1b8);
        *(int *)(unaff_EBP + -0x10) = *piVar1;
        uVar5 = FUN_004e99a9();
        FUN_00528f9f(*(undefined4 *)(*(int *)(unaff_EBP + -0x18) + uVar6 * 4),uVar5);
        FUN_005b8680();
        iVar4 = *(int *)(extraout_ECX + 0x1b8);
        *(undefined1 *)(unaff_EBP + -4) = 8;
        FUN_004e9d82(*(undefined4 *)(iVar4 + uVar6 * 4),unaff_EBP + -0x58);
        uVar5 = FUN_004096c2();
        FUN_005d4956(uVar5);
        iVar4 = *(int *)(unaff_EBP + -0x14);
        *(undefined1 *)(unaff_EBP + -4) = 9;
        FUN_005dd9c8(unaff_EBP + -0x4c);
        *(undefined1 *)(unaff_EBP + -4) = 8;
        FUN_005b8770();
        (**(code **)(**(int **)(*piVar1 + iVar4 * 4) + 0x94))();
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_005b8770();
      }
      else {
        (**(code **)(**(int **)(*piVar1 + *(int *)(unaff_EBP + -0x14) * 4) + 0x98))();
      }
      *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
    }
    *(int *)(extraout_ECX + 400) = *(int *)(extraout_ECX + 400) + -1;
  } while( true );
}

