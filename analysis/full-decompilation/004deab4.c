
undefined4 FUN_004deab4(void)

{
  undefined2 *puVar1;
  int *piVar2;
  char cVar3;
  undefined2 uVar4;
  int iVar5;
  void *pvVar6;
  int *piVar7;
  uint uVar8;
  undefined3 uVar13;
  byte *pbVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 *puVar12;
  undefined4 extraout_ECX;
  int unaff_EBP;
  undefined1 *puVar14;
  byte *pbVar15;
  undefined4 uStack_54;
  undefined4 uStack_50;
  int iStack_4c;
  int iStack_48;
  undefined4 uVar16;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  cVar3 = FUN_004b8157();
  if (cVar3 == '\0') goto LAB_004dedab;
  iStack_48 = unaff_EBP + -0x18;
  uStack_50 = *(undefined4 *)(*(int *)(unaff_EBP + 8) + 4);
  iStack_4c = unaff_EBP + -0x14;
  uStack_54 = 0x4deaf1;
  iVar5 = FUN_004b85a2();
  *(int *)(unaff_EBP + -0x20) = iVar5;
  if (iVar5 == 0) goto LAB_004dedab;
  uVar16 = 100;
  iStack_48 = 0x4deb06;
  pvVar6 = operator_new(100);
  *(void **)(unaff_EBP + 8) = pvVar6;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar6 == (void *)0x0) {
    piVar7 = (int *)0x0;
  }
  else {
    piVar7 = (int *)FUN_005dfb13();
    uVar16 = extraout_ECX;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(int **)(unaff_EBP + -0x10) = piVar7;
  if (piVar7 == (int *)0x0) goto LAB_004dedab;
  iVar5 = *piVar7;
  iStack_48 = 0;
  iStack_4c = 0;
  *(undefined4 **)(unaff_EBP + 8) = &uStack_54;
  uStack_54 = uVar16;
  uStack_50 = uVar16;
  FUN_00436a50(4);
  cVar3 = (**(code **)(iVar5 + 0xc))
                    (*(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + -0x18));
  if ((cVar3 == '\0') ||
     ((*(int *)(unaff_EBP + -0x34) == 8 && (cVar3 = FUN_005df761(), cVar3 == '\0')))) {
LAB_004deda0:
    puVar12 = (undefined4 *)*piVar7;
  }
  else {
    if (*(int *)(unaff_EBP + -0x34) != 0) {
      piVar2 = (int *)piVar7[0x18];
      cVar3 = (**(code **)(*piVar7 + 0x20))(0x40);
      if ((cVar3 != '\0') && (cVar3 = (**(code **)(*piVar2 + 0x20))(0x40), cVar3 != '\0')) {
        uVar16 = (**(code **)(*piVar7 + 0xcc))();
        *(undefined4 *)(unaff_EBP + -0x28) = uVar16;
        uVar8 = (**(code **)(*piVar7 + 0xd0))();
        iVar5 = *piVar2;
        uVar8 = uVar8 >> 1;
        *(uint *)(unaff_EBP + -0x3c) = uVar8;
        uVar16 = (**(code **)(iVar5 + 0xcc))();
        *(undefined4 *)(unaff_EBP + -0x24) = uVar16;
        uVar16 = (**(code **)(*piVar2 + 0xd0))();
        *(undefined4 *)(unaff_EBP + -0x30) = 0;
        *(undefined4 *)(unaff_EBP + -0x40) = uVar16;
        *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(unaff_EBP + -0x20);
        if (0 < *(int *)(unaff_EBP + -0x18)) {
          do {
            iVar5 = *(int *)(unaff_EBP + -0x14);
            *(undefined4 *)(unaff_EBP + -0x1c) = 0;
            if (0 < iVar5) {
              *(undefined4 *)(unaff_EBP + 8) = *(undefined4 *)(unaff_EBP + -0x28);
              pbVar15 = (byte *)(*(int *)(unaff_EBP + -0x2c) + 1);
              do {
                pbVar9 = (byte *)(*(int *)(unaff_EBP + -0x24) + *(int *)(unaff_EBP + -0x1c));
                *pbVar9 = pbVar15[2];
                if (pbVar15[2] == 0) {
                  uVar4 = (undefined2)DAT_006f2a64;
                }
                else {
                  if ((pbVar15[2] == 0xff) || (DAT_006c8c2c == '\0')) {
                    uVar13 = (undefined3)((uint)pbVar9 >> 8);
                    uVar16 = CONCAT31(uVar13,pbVar15[-1]);
                    uVar10 = CONCAT31(uVar13,*pbVar15);
                    uVar11 = CONCAT31(uVar13,pbVar15[1]);
                  }
                  else {
                    *(uint *)(unaff_EBP + -0x38) = (uint)*pbVar9;
                    *(uint *)(unaff_EBP + -0x38) = (uint)pbVar15[-1];
                    uVar16 = __ftol();
                    *(uint *)(unaff_EBP + -0x38) = (uint)*pbVar15;
                    uVar10 = __ftol(uVar16);
                    *(uint *)(unaff_EBP + -0x38) = (uint)pbVar15[1];
                    uVar11 = __ftol(uVar10);
                  }
                  uVar4 = FUN_005dfe3b(uVar11,uVar10,uVar16);
                }
                puVar1 = *(undefined2 **)(unaff_EBP + 8);
                *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
                *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 2;
                pbVar15 = pbVar15 + 4;
                *puVar1 = uVar4;
                iVar5 = *(int *)(unaff_EBP + -0x14);
              } while (*(int *)(unaff_EBP + -0x1c) < iVar5);
              uVar8 = *(uint *)(unaff_EBP + -0x3c);
            }
            *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
            *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x2c) + iVar5 * 4;
            *(uint *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + uVar8 * 2;
            *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + *(int *)(unaff_EBP + -0x40);
          } while (*(int *)(unaff_EBP + -0x30) < *(int *)(unaff_EBP + -0x18));
        }
        (**(code **)(*piVar7 + 0x24))(0x40);
        (**(code **)(*piVar2 + 0x24))(0x40);
        (**(code **)(*piVar7 + 0x68))(DAT_006f2a64);
        goto LAB_004dedab;
      }
      goto LAB_004deda0;
    }
    cVar3 = (**(code **)(*piVar7 + 0x20))(0x40);
    puVar12 = (undefined4 *)*piVar7;
    if (cVar3 != '\0') {
      uVar16 = (*(code *)puVar12[0x33])();
      *(undefined4 *)(unaff_EBP + -0x28) = uVar16;
      uVar8 = (**(code **)(*piVar7 + 0xd0))();
      *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x20);
      *(undefined4 *)(unaff_EBP + -0x2c) = 0;
      if (0 < *(int *)(unaff_EBP + -0x18)) {
        do {
          iVar5 = *(int *)(unaff_EBP + -0x14);
          *(undefined4 *)(unaff_EBP + -0x1c) = 0;
          if (0 < iVar5) {
            *(undefined4 *)(unaff_EBP + 8) = *(undefined4 *)(unaff_EBP + -0x28);
            iVar5 = *(int *)(unaff_EBP + -0x24);
            puVar14 = (undefined1 *)(iVar5 + 2);
            do {
              uVar13 = (undefined3)((uint)iVar5 >> 8);
              uVar4 = FUN_005dfe3b(CONCAT31(uVar13,*puVar14),CONCAT31(uVar13,puVar14[-1]),
                                   CONCAT31(uVar13,puVar14[-2]));
              puVar1 = *(undefined2 **)(unaff_EBP + 8);
              *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
              *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 2;
              puVar14 = puVar14 + 4;
              *puVar1 = uVar4;
              iVar5 = *(int *)(unaff_EBP + -0x14);
            } while (*(int *)(unaff_EBP + -0x1c) < iVar5);
          }
          *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x2c) + 1;
          *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + iVar5 * 4;
          *(uint *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + (uVar8 & 0xfffffffe);
        } while (*(int *)(unaff_EBP + -0x2c) < *(int *)(unaff_EBP + -0x18));
      }
      (**(code **)(*piVar7 + 0x24))(0x40);
      goto LAB_004dedab;
    }
  }
  (*(code *)*puVar12)(1);
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
LAB_004dedab:
  iStack_48 = 0x4dedb3;
  FUN_006321f0();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x10);
}

