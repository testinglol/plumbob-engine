
undefined4 FUN_00530296(void)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int *extraout_ECX;
  int iVar8;
  int *piVar9;
  int unaff_EBP;
  undefined4 uVar10;
  
  FUN_00634c24();
  uVar3 = FUN_004e99a9();
  piVar9 = (int *)extraout_ECX[0x17];
  *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
  cVar2 = (**(code **)(*piVar9 + 0x20))(0x10);
  if (cVar2 != '\0') {
    if ((extraout_ECX[0x35] != 0) && (*(int *)(unaff_EBP + -0x10) != -1)) {
      *(undefined4 **)(unaff_EBP + -0x14) = &DAT_006f42b0;
      *(undefined4 **)(unaff_EBP + -0x1c) = &DAT_0066dfec;
      do {
        iVar5 = **(int **)(unaff_EBP + -0x1c);
        iVar4 = FUN_004ea79e(*(undefined4 *)(unaff_EBP + -0x10));
        iVar5 = (int)*(short *)(iVar4 + iVar5 * 2) / 100;
        *(int *)(unaff_EBP + -0x18) = iVar5;
        if (iVar5 < 0xb) {
          if (iVar5 < 0) {
            *(undefined4 *)(unaff_EBP + -0x18) = 0;
          }
        }
        else {
          *(undefined4 *)(unaff_EBP + -0x18) = 10;
        }
        uVar10 = 0;
        iVar4 = *(int *)extraout_ECX[0x17];
        uVar3 = *(undefined4 *)(unaff_EBP + -0x14);
        iVar5 = unaff_EBP + -0x74;
        *(int *)(unaff_EBP + -0x20) = extraout_ECX[0x36] + 0x14;
        FUN_004df599(unaff_EBP + -0x84,extraout_ECX + 7);
        uVar3 = FUN_004df599(iVar5,uVar3);
        (**(code **)(iVar4 + 0x9c))
                  (extraout_ECX[0x36],*(undefined4 *)(unaff_EBP + -0x20),uVar3,uVar10);
        if (0 < *(int *)(unaff_EBP + -0x18)) {
          iVar5 = extraout_ECX[0x35];
          iVar4 = *(int *)(iVar5 + 0x14);
          *(int *)(unaff_EBP + -0x30) = iVar4;
          *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(iVar5 + 0x18);
          iVar1 = *(int *)(iVar5 + 0x1c);
          *(int *)(unaff_EBP + -0x28) = iVar1;
          *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(iVar5 + 0x20);
          iVar6 = extraout_ECX[8] + *(int *)(*(int *)(unaff_EBP + -0x14) + 4);
          iVar8 = extraout_ECX[7] + **(int **)(unaff_EBP + -0x14);
          *(int *)(unaff_EBP + -100) = *(int *)(unaff_EBP + -0x30) + iVar8;
          *(int *)(unaff_EBP + -0x5c) = iVar8 + *(int *)(unaff_EBP + -0x28);
          *(int *)(unaff_EBP + -0x60) = *(int *)(unaff_EBP + -0x2c) + iVar6;
          *(int *)(unaff_EBP + -0x58) = *(int *)(unaff_EBP + -0x24) + iVar6;
          iVar6 = *(int *)(unaff_EBP + -0x18) * 4;
          if ((iVar6 <= iVar1 - iVar4) && (*(int *)(unaff_EBP + -0x18) != 10)) {
            *(int *)(unaff_EBP + -0x5c) = *(int *)(unaff_EBP + -100) + iVar6;
            *(int *)(unaff_EBP + -0x28) = iVar6 + *(int *)(unaff_EBP + -0x30);
          }
          (**(code **)(*(int *)extraout_ECX[0x17] + 0x9c))
                    (iVar5,unaff_EBP + -0x30,unaff_EBP + -100,0);
        }
        *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 4;
        *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 8;
      } while (*(int *)(unaff_EBP + -0x1c) < 0x66e004);
    }
    (**(code **)(*(int *)extraout_ECX[0x17] + 0x24))(0x10);
  }
  cVar2 = FUN_004cff80();
  if (cVar2 == '\0') {
    if (*(char *)(DAT_006e486c + 100) == '\x03') {
      *(undefined4 *)(unaff_EBP + -0x24) = 3;
      *(undefined4 *)(unaff_EBP + -0x28) = 0x23;
      uVar3 = 10;
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x24) = 3;
      *(undefined4 *)(unaff_EBP + -0x28) = 0x23;
      uVar3 = 0xb;
    }
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x28) = 0xd;
    *(undefined4 *)(unaff_EBP + -0x24) = 8;
    uVar3 = 0xb;
  }
  FUN_0051eb1f(extraout_ECX + 0x5a,extraout_ECX[0x17],extraout_ECX + 7,unaff_EBP + -0x28,uVar3);
  iVar5 = FUN_004ea83d(*(undefined4 *)(unaff_EBP + -0x10));
  if (iVar5 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_004096c2();
  }
  FUN_005e4320(uVar3);
  if ((char)extraout_ECX[0x83] == '\0') {
    if (*(int *)(unaff_EBP + -0x10) == -1) goto LAB_00530798;
    if (((int *)extraout_ECX[0x17] != (int *)0x0) &&
       (cVar2 = (**(code **)(*(int *)extraout_ECX[0x17] + 0x20))(4), cVar2 != '\0')) {
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      *(undefined4 **)(unaff_EBP + -0x1c) = &DAT_006f42b0;
      do {
        iVar5 = FUN_004ea95f(*(undefined4 *)(unaff_EBP + -0x10),
                             *(undefined4 *)((int)&DAT_0066dfec + *(int *)(unaff_EBP + -0x18)));
        *(bool *)(unaff_EBP + -0x14) = 0 < iVar5;
        FUN_005e4ae7(*(undefined4 *)(unaff_EBP + -0x14));
        if (*(char *)(unaff_EBP + -0x14) != '\0') {
          iVar6 = extraout_ECX[8] + (*(int **)(unaff_EBP + -0x1c))[1];
          *(int *)(unaff_EBP + -0x20) =
               **(int **)(unaff_EBP + -0x1c) + extraout_ECX[7] + -1 + (iVar5 / 100) * 4;
          iVar4 = (*(int *)(extraout_ECX[0x35] + 0x20) - *(int *)(extraout_ECX[0x35] + 0x18)) + -1 +
                  iVar6;
          piVar9 = (int *)extraout_ECX[0x17];
          *(int *)(unaff_EBP + -0x24) = iVar4;
          iVar1 = piVar9[8];
          if (iVar1 < iVar4) {
            *(int *)(unaff_EBP + -0x24) = iVar1;
          }
          iVar4 = *(int *)(unaff_EBP + -0x20);
          (**(code **)(*piVar9 + 0x7c))
                    (iVar4,iVar6,iVar4,*(undefined4 *)(unaff_EBP + -0x24),DAT_006f2a44,1);
          (**(code **)(*(int *)extraout_ECX[0x17] + 0x7c))
                    (iVar4 + (iVar5 / 100) * -4 + -0xf,*(undefined4 *)(unaff_EBP + -0x24),iVar4,
                     *(undefined4 *)(unaff_EBP + -0x24),DAT_006f2a44,1);
        }
        *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 8;
        *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 4;
      } while (*(int *)(unaff_EBP + -0x1c) < 0x6f42e0);
      (**(code **)(*(int *)extraout_ECX[0x17] + 0x24))(4);
    }
  }
  else {
    (**(code **)(*extraout_ECX + 0x16c))();
    *(undefined1 *)(extraout_ECX + 0x83) = 0;
  }
  if (*(int *)(unaff_EBP + -0x10) != -1) {
    iVar5 = FUN_004ea85e(*(undefined4 *)(unaff_EBP + -0x10));
    *(int *)(unaff_EBP + -0x18) = iVar5;
    iVar4 = FUN_004eabb1(*(undefined4 *)(unaff_EBP + -0x10));
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    *(char *)(unaff_EBP + -0x14) = '\x01' - (iVar4 != 1);
    do {
      iVar4 = *(int *)(unaff_EBP + -0x1c);
      if (iVar4 == 0) {
        if (iVar5 == 0) {
          piVar9 = extraout_ECX + 0x4e;
          iVar4 = **(int **)extraout_ECX[0x3a];
LAB_00530784:
          (**(code **)(iVar4 + 0x9c))(piVar9);
        }
        else {
          uVar3 = FUN_004033bc(*(undefined4 *)(unaff_EBP + -0x14));
          FUN_005d4956(uVar3);
          puVar7 = (undefined4 *)extraout_ECX[0x3a];
          *(undefined4 *)(unaff_EBP + -4) = 0;
          (**(code **)(*(int *)*puVar7 + 0x9c))(unaff_EBP + -0x54);
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005b8770();
        }
      }
      else if (iVar4 == 1) {
        if (iVar5 == 0) {
          piVar9 = extraout_ECX + 0x51;
          iVar4 = **(int **)(extraout_ECX[0x3a] + 4);
          goto LAB_00530784;
        }
        FUN_005d48d9();
        piVar9 = DAT_006fe8bc;
        *(undefined4 *)(unaff_EBP + -4) = 1;
        puVar7 = (undefined4 *)(**(code **)(*piVar9 + 4))();
        *(undefined4 *)(unaff_EBP + -0x20) = *puVar7;
        iVar5 = FUN_004cebb0(unaff_EBP + -0x3c);
        (**(code **)(*(int *)(unaff_EBP + -0x20) + 0x7c))(iVar5,iVar5 >> 0x1f);
        (**(code **)(**(int **)(extraout_ECX[0x3a] + 4) + 0x9c))(unaff_EBP + -0x3c);
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_005b8770();
        iVar5 = *(int *)(unaff_EBP + -0x18);
      }
      else if (iVar4 == 2) {
        iVar4 = FUN_004ea9c8(*(undefined4 *)(unaff_EBP + -0x10));
        if (iVar5 == 0) {
          (**(code **)(**(int **)(extraout_ECX[0x3a] + 8) + 0x9c))(extraout_ECX + 0x54);
        }
        else {
          uVar3 = FUN_00403515(iVar4);
          FUN_005d4956(uVar3);
          iVar1 = extraout_ECX[0x3a];
          *(undefined4 *)(unaff_EBP + -4) = 2;
          (**(code **)(**(int **)(iVar1 + 8) + 0x9c))(unaff_EBP + -0x48);
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005b8770();
          if (iVar4 < 0) {
            FUN_005307ab(0x14d);
            goto LAB_0053078b;
          }
        }
        FUN_005307d9();
      }
      else if (iVar4 == 3) {
        uVar3 = FUN_004eaa0f(*(undefined4 *)(unaff_EBP + -0x10));
        FUN_00531126(uVar3);
      }
LAB_0053078b:
      *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
    } while (*(int *)(unaff_EBP + -0x1c) < 4);
  }
LAB_00530798:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

