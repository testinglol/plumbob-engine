
/* WARNING (jumptable): Unable to track spacebase fully for stack */

undefined4 FUN_0051f4ef(void)

{
  char cVar1;
  void *pvVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  int *extraout_ECX;
  undefined4 uVar7;
  int unaff_EBP;
  int iVar8;
  
  FUN_00634c24();
  pvVar2 = operator_new(0xd4);
  *(void **)(unaff_EBP + -0x10) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar2 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_005dbd68();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  extraout_ECX[0xce] = (int)piVar3;
  if ((piVar3 != (int *)0x0) && (cVar1 = (**(code **)(*piVar3 + 0xc))(), cVar1 != '\0')) {
    cVar1 = FUN_004cff80();
    iVar8 = DAT_006f3ac0;
    uVar7 = DAT_006f3ab8;
    iVar5 = DAT_006f3ab0;
    uVar6 = DAT_006f3aa8;
    if (cVar1 == '\0') {
      *(undefined4 *)(unaff_EBP + -0x2c) = DAT_006f3abc;
      uVar4 = DAT_006f3ac4;
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x2c) = DAT_006f3aac;
      uVar4 = DAT_006f3ab4;
      uVar7 = uVar6;
      iVar8 = iVar5;
    }
    *(undefined4 *)(unaff_EBP + -0x24) = uVar4;
    piVar3 = (int *)FUN_005caed9();
    if (*piVar3 == 0x400) {
      iVar8 = iVar8 + 0xe0;
    }
    (**(code **)(*(int *)extraout_ECX[0xce] + 0x60))
              (uVar7,*(undefined4 *)(unaff_EBP + -0x2c),iVar8,*(undefined4 *)(unaff_EBP + -0x24));
    cVar1 = FUN_004cff80();
    uVar6 = DAT_006f3a80;
    uVar7 = DAT_006f3a84;
    if (cVar1 != '\0') {
      uVar6 = DAT_006f3a78;
      uVar7 = DAT_006f3a7c;
    }
    FUN_004cb21d(uVar6,uVar7);
    (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0xce]);
    pvVar2 = operator_new(0x110);
    *(void **)(unaff_EBP + -0x10) = pvVar2;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    if (pvVar2 == (void *)0x0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_005e9913();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[0xcf] = iVar5;
    if (iVar5 != 0) {
      (**(code **)(*(int *)(iVar5 + 0xd4) + 0x18))(DAT_006f2a8c);
      cVar1 = FUN_004cff80();
      uVar6 = DAT_006f3aa0;
      iVar5 = DAT_006f3aa4;
      if (cVar1 != '\0') {
        uVar6 = DAT_006f3a98;
        iVar5 = DAT_006f3a9c;
      }
      FUN_004cb21d(uVar6,iVar5);
      (**(code **)(*(int *)(extraout_ECX[0xcf] + 0xd4) + 0x14))(0);
      FUN_0046fca5();
      *(undefined ***)(unaff_EBP + -0xa4) = &PTR_FUN_0066643c;
      *(undefined4 *)(unaff_EBP + -4) = 2;
      cVar1 = FUN_004fff98(0x8c,&DAT_006c265c,unaff_EBP + -0xa4,0);
      if (cVar1 != '\0') {
        FUN_00471655(unaff_EBP + -0x1c);
        piVar3 = (int *)extraout_ECX[0xcf];
        *(undefined1 *)(unaff_EBP + -4) = 3;
        iVar5 = *piVar3;
        uVar6 = FUN_0046fc7a();
        (**(code **)(iVar5 + 0x1a0))(uVar6);
        *(undefined1 *)(unaff_EBP + -4) = 2;
        FUN_0042004f();
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_00470467();
        (**(code **)(*(int *)extraout_ECX[0xce] + 0x20))(extraout_ECX[0xcf]);
        (**(code **)(*(int *)(extraout_ECX[0xcf] + 0xd4) + 0xc))(2,0);
        (*(code *)**(undefined4 **)(extraout_ECX[0xcf] + 0xd4))();
        cVar1 = FUN_004cff80();
        iVar5 = extraout_ECX[0xcf];
        if (cVar1 == '\0') {
          iVar8 = *(int *)(iVar5 + 0x88) - *(int *)(iVar5 + 0x80);
          iVar5 = DAT_006f3aa4;
        }
        else {
          iVar8 = *(int *)(iVar5 + 0x88) - *(int *)(iVar5 + 0x80);
          iVar5 = DAT_006f3a9c;
        }
        extraout_ECX[0xd3] = iVar8 + 5 + iVar5;
        FUN_005a5631(100,unaff_EBP + -0x14,4);
        if (*(int **)(unaff_EBP + -0x14) != (int *)0x0) {
          (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x68))(DAT_006f2a64);
        }
        pvVar2 = operator_new(0x194);
        *(void **)(unaff_EBP + -0x10) = pvVar2;
        *(undefined4 *)(unaff_EBP + -4) = 4;
        if (pvVar2 == (void *)0x0) {
          piVar3 = (int *)0x0;
        }
        else {
          piVar3 = (int *)FUN_005e372a();
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        extraout_ECX[0xd0] = (int)piVar3;
        (**(code **)(*piVar3 + 0x19c))(*(undefined4 *)(unaff_EBP + -0x14),4,1);
        *(undefined1 *)(extraout_ECX[0xd0] + 0x16b) = 1;
        *(undefined4 *)(extraout_ECX[0xd0] + 0xf4) = 1;
        (**(code **)(*(int *)extraout_ECX[0xd0] + 0x98))();
        (**(code **)(*(int *)extraout_ECX[0xce] + 0x20))(extraout_ECX[0xd0]);
        FUN_005a5631(0x65,unaff_EBP + -0x14,4);
        if (*(int **)(unaff_EBP + -0x14) != (int *)0x0) {
          (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x68))(DAT_006f2a64);
        }
        pvVar2 = operator_new(0x194);
        *(void **)(unaff_EBP + -0x10) = pvVar2;
        *(undefined4 *)(unaff_EBP + -4) = 5;
        if (pvVar2 == (void *)0x0) {
          piVar3 = (int *)0x0;
        }
        else {
          piVar3 = (int *)FUN_005e372a();
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        extraout_ECX[0xd1] = (int)piVar3;
        (**(code **)(*piVar3 + 0x19c))(*(undefined4 *)(unaff_EBP + -0x14),4,1);
        *(undefined1 *)(extraout_ECX[0xd1] + 0x16b) = 1;
        *(undefined4 *)(extraout_ECX[0xd1] + 0xf4) = 1;
        (**(code **)(*(int *)extraout_ECX[0xd1] + 0x98))();
        (**(code **)(*(int *)extraout_ECX[0xce] + 0x20))(extraout_ECX[0xd1]);
        FUN_004cb21d(2,((((*(int *)(extraout_ECX[0xd0] + 0x80) - *(int *)(extraout_ECX[0xd0] + 0x88)
                          ) - *(int *)(extraout_ECX[0xce] + 0x80)) +
                        *(int *)(extraout_ECX[0xce] + 0x88)) - extraout_ECX[0xd3]) / 2 +
                       extraout_ECX[0xd3]);
        iVar5 = extraout_ECX[0xce];
        FUN_004cb21d(((*(int *)(iVar5 + 0x84) - *(int *)(extraout_ECX[0xd1] + 0x84)) -
                     *(int *)(iVar5 + 0x7c)) + -2 + *(int *)(extraout_ECX[0xd1] + 0x7c),
                     ((((*(int *)(extraout_ECX[0xd0] + 0x80) - *(int *)(extraout_ECX[0xd0] + 0x88))
                       - *(int *)(iVar5 + 0x80)) + *(int *)(iVar5 + 0x88)) - extraout_ECX[0xd3]) / 2
                     + extraout_ECX[0xd3]);
        iVar5 = extraout_ECX[0xce];
        extraout_ECX[0xd2] =
             (*(int *)(extraout_ECX[0xd0] + 0x84) - *(int *)(extraout_ECX[0xd0] + 0x7c)) + 4;
        extraout_ECX[0xd4] =
             ((*(int *)(iVar5 + 0x84) - *(int *)(extraout_ECX[0xd1] + 0x84)) -
             *(int *)(iVar5 + 0x7c)) + -4 + *(int *)(extraout_ECX[0xd1] + 0x7c);
        extraout_ECX[0xd5] = *(int *)(iVar5 + 0x88) - *(int *)(iVar5 + 0x80);
        FUN_0046fca5();
        *(undefined ***)(unaff_EBP + -0x110) = &PTR_FUN_0066643c;
        *(undefined4 *)(unaff_EBP + -4) = 6;
        uVar6 = FUN_0041532c(9,unaff_EBP + -0x110,0);
        cVar1 = FUN_004fff98(0x9a,uVar6);
        if (cVar1 != '\0') {
          FUN_00471655(unaff_EBP + -0x38);
          *(undefined1 *)(unaff_EBP + -4) = 7;
          uVar6 = FUN_0046fc7a();
          FUN_005d4956(uVar6);
          *(undefined1 *)(unaff_EBP + -4) = 8;
          FUN_005dd9c8(unaff_EBP + -0x20);
          *(undefined1 *)(unaff_EBP + -4) = 7;
          FUN_005b8770();
          FUN_005c11ce();
          uVar6 = FUN_0046fc7a();
          FUN_005d4956(uVar6);
          *(undefined1 *)(unaff_EBP + -4) = 9;
          FUN_005dd9c8(unaff_EBP + -0x2c);
          *(undefined1 *)(unaff_EBP + -4) = 7;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 6;
          FUN_0042004f();
        }
        if (extraout_ECX[0xd6] == 0) {
          pvVar2 = operator_new(0x84);
          *(void **)(unaff_EBP + -0x10) = pvVar2;
          *(undefined1 *)(unaff_EBP + -4) = 10;
          if (pvVar2 == (void *)0x0) {
            iVar5 = 0;
          }
          else {
            iVar5 = FUN_00510166(0,0,0,0,0,0,0,0,0);
          }
          *(undefined1 *)(unaff_EBP + -4) = 6;
          extraout_ECX[0xd6] = iVar5;
          if (iVar5 != 0) {
            FUN_00503993(&DAT_006ccae8);
          }
        }
        *(undefined4 *)(unaff_EBP + -0x10) = 0;
        do {
          pvVar2 = operator_new(0x1a4);
          *(void **)(unaff_EBP + -0x18) = pvVar2;
          *(undefined1 *)(unaff_EBP + -4) = 0xb;
          if (pvVar2 == (void *)0x0) {
            iVar5 = 0;
          }
          else {
            iVar5 = FUN_0050f244(extraout_ECX[0xd6],*(undefined4 *)(unaff_EBP + -0x10));
          }
          iVar8 = *(int *)(unaff_EBP + -0x10);
          *(undefined1 *)(unaff_EBP + -4) = 6;
          piVar3 = extraout_ECX + iVar8 + 0xd7;
          *piVar3 = iVar5;
          switch(iVar8) {
          case 0:
            extraout_ECX[0xea] = iVar5;
            break;
          case 1:
            extraout_ECX[0xeb] = iVar5;
            break;
          case 2:
            extraout_ECX[0xec] = iVar5;
            break;
          case 3:
            extraout_ECX[0xed] = iVar5;
            break;
          case 4:
            extraout_ECX[0xee] = iVar5;
            extraout_ECX[0xfd] = *piVar3;
            break;
          case 5:
            extraout_ECX[0xef] = iVar5;
            extraout_ECX[0xfe] = *piVar3;
            break;
          case 6:
            extraout_ECX[0xf0] = iVar5;
            extraout_ECX[0xff] = *piVar3;
            break;
          case 7:
            extraout_ECX[0xf1] = iVar5;
            extraout_ECX[0x100] = *piVar3;
            break;
          case 8:
            extraout_ECX[0xf9] = iVar5;
            break;
          case 9:
            extraout_ECX[0xfa] = iVar5;
            break;
          case 10:
            extraout_ECX[0xfb] = iVar5;
            break;
          case 0xb:
            extraout_ECX[0xfc] = iVar5;
            break;
          case 0xc:
            extraout_ECX[0xf2] = iVar5;
            break;
          case 0xd:
            extraout_ECX[0xf3] = iVar5;
            break;
          case 0xe:
            extraout_ECX[0xf4] = iVar5;
            break;
          case 0xf:
            extraout_ECX[0xf5] = iVar5;
            break;
          case 0x10:
            extraout_ECX[0xf6] = iVar5;
            break;
          case 0x11:
            extraout_ECX[0xf7] = iVar5;
            break;
          case 0x12:
            extraout_ECX[0xf8] = iVar5;
          }
          (**(code **)(*(int *)extraout_ECX[0xce] + 0x20))(*piVar3);
          (**(code **)(*(int *)*piVar3 + 0x98))();
          *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
        } while (*(int *)(unaff_EBP + -0x10) < 0x13);
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        extraout_ECX[0x102] = 0;
        FUN_00470467();
        uVar6 = 1;
        goto LAB_0051f6dd;
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_00470467();
    }
  }
  uVar6 = 0;
LAB_0051f6dd:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar6;
}

