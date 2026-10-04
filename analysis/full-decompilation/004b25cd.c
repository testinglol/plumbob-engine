
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_004b25cd(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  undefined1 uVar6;
  undefined4 uVar7;
  uint uVar8;
  int *piVar9;
  void *pvVar10;
  int *piVar11;
  int iVar12;
  int *piVar13;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  int iVar14;
  undefined4 *puStack_174;
  undefined4 *puStack_170;
  int iStack_16c;
  int *piStack_168;
  undefined4 *puVar15;
  
  FUN_00634c24();
  FUN_004aa1b9();
  iVar14 = 1 << ((char)DAT_006f0088 - 1U & 0x1f);
  *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) / iVar14;
  *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) / iVar14;
  if (*(int *)(unaff_EBP + 0x10) == 0) {
    *(undefined4 *)(unaff_EBP + -0x20) = 0x7fffffff;
    *(undefined4 *)(unaff_EBP + -0x24) = 0x7fffffff;
  }
  sVar1 = *(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x18);
  *(undefined2 *)(*(int *)(DAT_006e486c + 0x1c) + 0x18) = 0;
  *(int *)(unaff_EBP + -0x38) = (int)sVar1;
  FUN_004c482f();
  (**(code **)(**(int **)(*(int *)(DAT_006e486c + 0x20) + 0x18) + 0x20))();
  FUN_00466c7b();
  FUN_004e609e();
  uVar7 = FUN_004e6141();
  *(undefined4 *)(unaff_EBP + -0x3c) = uVar7;
  FUN_004e609e();
  FUN_004e6166();
  uVar8 = DAT_006f2a64;
  if (*(char *)(unaff_EBP + 0x14) == '\0') {
    uVar8 = FUN_005dfe3b();
    uVar8 = uVar8 & 0xffff;
  }
  *(uint *)(unaff_EBP + 0x20) = uVar8;
  piVar9 = (int *)FUN_004b2d29();
  *(undefined2 *)(*(int *)(DAT_006e486c + 0x1c) + 0x18) = *(undefined2 *)(unaff_EBP + -0x38);
  FUN_004c482f();
  (**(code **)(**(int **)(*(int *)(DAT_006e486c + 0x20) + 0x18) + 0x20))();
  FUN_00466c7b();
  FUN_004e609e();
  FUN_004e6166();
  if (piVar9 != (int *)0x0) {
    *(undefined4 *)(unaff_EBP + -0x34) = 0;
    *(undefined4 *)(unaff_EBP + -0x30) = 0;
    *(undefined4 *)(unaff_EBP + -0x2c) = 0;
    *(undefined4 *)(unaff_EBP + -0x28) = 0;
    FUN_004c3766();
    *(int *)(unaff_EBP + 0x20) = (0x120 - *(int *)(unaff_EBP + -0x28)) - *(int *)(unaff_EBP + -0x30)
    ;
    *(int *)(unaff_EBP + 0x18) = (0x1b0 - *(int *)(unaff_EBP + -0x2c)) - *(int *)(unaff_EBP + -0x34)
    ;
    pvVar10 = operator_new(100);
    *(void **)(unaff_EBP + 0x10) = pvVar10;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar10 == (void *)0x0) {
      piVar11 = (int *)0x0;
    }
    else {
      piVar11 = (int *)FUN_005dfb13();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int **)(unaff_EBP + 0x1c) = piVar11;
    if (piVar11 == (int *)0x0) {
      puVar15 = (undefined4 *)*piVar9;
    }
    else {
      iVar14 = *piVar11;
      *(undefined1 **)(unaff_EBP + 0xc) = &stack0xfffffec8;
      *(int *)(unaff_EBP + 0xc) = iVar14;
      FUN_00436a50();
      cVar5 = (**(code **)(*(int *)(unaff_EBP + 0xc) + 0xc))();
      if ((cVar5 != '\0') && (cVar5 = (**(code **)(*piVar11 + 0x20))(), cVar5 != '\0')) {
        iVar14 = piVar9[5];
        iVar12 = piVar9[7];
        iVar2 = piVar9[8];
        *(int *)(unaff_EBP + -0x4c) = piVar9[6] + *(int *)(unaff_EBP + -0x30);
        *(int *)(unaff_EBP + -0x50) = iVar14 + *(int *)(unaff_EBP + -0x34);
        iVar14 = *(int *)(unaff_EBP + -0x2c);
        iVar3 = *(int *)(unaff_EBP + -0x28);
        *(int *)(unaff_EBP + -0x40) = piVar9[9];
        *(int *)(unaff_EBP + -0x3c) = piVar9[10];
        piVar9[10] = piVar9[10] & 0xfffffffd;
        iVar4 = *piVar9;
        *(int *)(unaff_EBP + -0x48) = iVar12 - iVar14;
        *(int *)(unaff_EBP + -0x44) = iVar2 - iVar3;
        (**(code **)(iVar4 + 0x74))();
        (**(code **)(*piVar11 + 0x9c))();
        (**(code **)(*piVar11 + 0x24))();
        (**(code **)(*piVar11 + 0x74))();
        (**(code **)*piVar9)();
        if (*(char *)(unaff_EBP + 0x14) != '\0') {
          FUN_00429bf0();
          *(undefined4 *)(unaff_EBP + -4) = 1;
          piStack_168 = (int *)(unaff_EBP + -0xd4);
          iStack_16c = 0x4b2889;
          iStack_16c = FUN_00428886();
          puStack_170 = (undefined4 *)0x4b288f;
          cVar5 = FUN_004e1f04();
          iVar14 = DAT_006e486c;
          if (cVar5 != '\0') {
            *(undefined4 *)(unaff_EBP + 0x10) = 0;
            if ((((*(byte *)(iVar14 + 0x66) & 0x80) == 0) ||
                (iVar12 = FUN_00428886(), iVar14 = DAT_006e486c, iVar12 < 0x5a)) ||
               (iVar12 = FUN_00428886(), iVar14 = DAT_006e486c, 0x5c < iVar12)) {
              if ((*(byte *)(iVar14 + 0x66) & 0x20) == 0) {
                *(undefined1 *)(unaff_EBP + 0x17) = 0;
                iVar12 = 5000;
                iStack_16c = 0x14bc;
                *(undefined4 *)(unaff_EBP + 0x20) = 0x3f800000;
              }
              else {
                iVar12 = 6000;
                iStack_16c = 0x18a4;
                *(undefined4 *)(unaff_EBP + 0x20) = 0x40000000;
                *(undefined1 *)(unaff_EBP + 0x17) = 1;
              }
            }
            else {
              *(undefined1 *)(unaff_EBP + 0x17) = 0;
              iVar12 = 0x14ca;
              iStack_16c = 0x14ca;
              *(undefined4 *)(unaff_EBP + 0x20) = 0x3f800000;
              iVar14 = DAT_006e486c;
            }
            piStack_168 = (int *)(unaff_EBP + 0x10);
            if (*(char *)(iVar14 + 100) == '\x01') {
              iStack_16c = iVar12;
            }
            puStack_170 = (undefined4 *)0x4b2929;
            FUN_005a5631();
            if (*(int *)(unaff_EBP + 0x10) != 0) {
              iVar14 = piVar11[7];
              iVar12 = piVar11[8];
              *(undefined4 *)(unaff_EBP + -0x1c) = 0;
              *(undefined4 *)(unaff_EBP + -0x18) = 0;
              piVar9 = (int *)(*(int *)(unaff_EBP + 0x10) + 0x14);
              *(int **)(unaff_EBP + 0x18) = piVar9;
              *(int *)(unaff_EBP + -0x14) = iVar14;
              *(int *)(unaff_EBP + -0x10) = iVar12;
              if (*(char *)(unaff_EBP + 0x17) == '\0') {
                iVar14 = *(int *)(unaff_EBP + -0x60) - iVar14 / 2;
                iVar12 = (*(int *)(unaff_EBP + -0x5c) - iVar12 / 2) + -10;
              }
              else {
                if (iVar14 % 2 < 1) {
                  iVar14 = *(int *)(unaff_EBP + -0x14);
                }
                else {
                  iVar14 = iVar14 + 1;
                }
                if (iVar12 % 2 < 1) {
                  iVar12 = *(int *)(unaff_EBP + -0x10);
                }
                else {
                  iVar12 = iVar12 + 1;
                }
                *(int *)(unaff_EBP + -0x14) = iVar14 / 2;
                *(int *)(unaff_EBP + -0x10) = iVar12 / 2;
                if (*(int *)(unaff_EBP + -0x74) == 0x7fffffff) {
                  piStack_168 = (int *)(unaff_EBP + -0xd4);
                  iStack_16c = 0x4b29b2;
                  iStack_16c = FUN_00428886();
                  puStack_170 = (undefined4 *)0x4b29b8;
                  FUN_004e1f04();
                }
                iVar14 = *(int *)(unaff_EBP + -0x68);
                if (-1 < iVar14) {
                  iVar14 = 0;
                }
                iVar14 = (iVar14 - *(int *)(unaff_EBP + -0x74)) + *(int *)(unaff_EBP + -0x60);
                iVar12 = *(int *)(unaff_EBP + -100);
                if (-1 < iVar12) {
                  iVar12 = 0;
                }
                piVar9 = *(int **)(unaff_EBP + 0x18);
                iVar12 = ((iVar12 - *(int *)(unaff_EBP + -0x6c)) - *(int *)(unaff_EBP + -0x70)) +
                         *(int *)(unaff_EBP + -0x5c);
                if (piVar9[3] < *(int *)(unaff_EBP + -0x10)) {
                  *(int *)(unaff_EBP + -0x10) = piVar9[3];
                }
                if (piVar9[2] < *(int *)(unaff_EBP + -0x14)) {
                  *(int *)(unaff_EBP + -0x14) = piVar9[2];
                }
                if (*(int *)(unaff_EBP + -0x1c) < 0) {
                  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
                }
                if (*(int *)(unaff_EBP + -0x18) < 0) {
                  *(undefined4 *)(unaff_EBP + -0x18) = 0;
                }
              }
              piVar13 = (int *)0x0;
              *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + iVar14;
              *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + iVar14;
              *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + iVar12;
              *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + iVar12;
              if (*(int *)(unaff_EBP + -0x1c) < 0) {
                iVar14 = *(int *)(unaff_EBP + -0x1c);
                *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + -iVar14;
                *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + -iVar14;
              }
              if (*(int *)(unaff_EBP + -0x18) < 0) {
                iVar14 = *(int *)(unaff_EBP + -0x18);
                *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + -iVar14;
                *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + -iVar14;
              }
              if (piVar9[2] - *piVar9 < *(int *)(unaff_EBP + -0x14)) {
                iVar14 = (piVar9[2] - *piVar9) - *(int *)(unaff_EBP + -0x14);
                *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + iVar14;
                *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + iVar14;
              }
              if (piVar9[3] - piVar9[1] < *(int *)(unaff_EBP + -0x10)) {
                iVar14 = (piVar9[3] - piVar9[1]) - *(int *)(unaff_EBP + -0x10);
                *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + iVar14;
                *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + iVar14;
              }
              puVar15 = (undefined4 *)0x64;
              piStack_168 = (int *)0x4b2a81;
              pvVar10 = operator_new(100);
              *(void **)(unaff_EBP + 0x14) = pvVar10;
              *(undefined1 *)(unaff_EBP + -4) = 2;
              if (pvVar10 != (void *)0x0) {
                piVar13 = (int *)FUN_005dfb13();
                puVar15 = extraout_ECX;
              }
              *(undefined1 *)(unaff_EBP + -4) = 1;
              if (piVar13 != (int *)0x0) {
                iVar14 = *piVar13;
                piStack_168 = (int *)0x0;
                iStack_16c = 0;
                *(undefined4 ***)(unaff_EBP + 0x14) = &puStack_174;
                puStack_174 = puVar15;
                puStack_170 = puVar15;
                FUN_00436a50(4);
                uVar7 = FUN_004a946b();
                uVar7 = FUN_004a9465(uVar7);
                cVar5 = (**(code **)(iVar14 + 0xc))(uVar7);
                if (cVar5 != '\0') {
                  piStack_168 = (int *)0x4b2adf;
                  cVar5 = (**(code **)(*piVar13 + 0x20))();
                  if (cVar5 != '\0') {
                    piStack_168 = piVar13 + 5;
                    iStack_16c = unaff_EBP + -0x1c;
                    puStack_170 = *(undefined4 **)(unaff_EBP + 0x10);
                    puStack_174 = (undefined4 *)0x4b2afb;
                    (**(code **)(*piVar13 + 0x9c))();
                    puStack_174 = (undefined4 *)0x10;
                    (**(code **)(*piVar13 + 0x24))();
                    piVar9 = (int *)FUN_004ba969(*(undefined4 *)(unaff_EBP + 0x20),piVar13,0,0);
                    (**(code **)*piVar13)(1);
                    (**(code **)(*piVar11 + 0x68))(DAT_006f2a64);
                    (**(code **)(*piVar9 + 0x20))(0x10);
                    (**(code **)(*piVar9 + 0x9c))(piVar11,piVar11 + 5,piVar11 + 5,0);
                    (**(code **)(*piVar9 + 0x24))(0x10);
                    (**(code **)*piVar11)(1);
                    *(int **)(unaff_EBP + 0x1c) = piVar9;
                  }
                }
              }
              if (*(undefined4 **)(unaff_EBP + 0x10) != (undefined4 *)0x0) {
                piStack_168 = (int *)0x4b2b69;
                (**(code **)**(undefined4 **)(unaff_EBP + 0x10))();
              }
            }
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_004e1909();
        }
        puVar15 = *(undefined4 **)(unaff_EBP + 0x1c);
        piStack_168 = (int *)0x1;
        iStack_16c = 0x5a;
        puStack_170 = (undefined4 *)0x0;
        puStack_174 = puVar15;
        uVar6 = FUN_004b818c(*(undefined4 *)(unaff_EBP + 8));
        if (puVar15 != (undefined4 *)0x0) {
          piStack_168 = (int *)0x4b2b9d;
          (**(code **)*puVar15)();
        }
        goto LAB_004b2bb3;
      }
      (**(code **)*piVar9)();
      puVar15 = (undefined4 *)*piVar11;
    }
    (*(code *)*puVar15)();
  }
  uVar6 = 0;
LAB_004b2bb3:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar6;
}

