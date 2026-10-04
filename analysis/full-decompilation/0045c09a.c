
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_0045c09a(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int extraout_ECX;
  int iVar7;
  uint uVar8;
  int unaff_EBP;
  int *piVar9;
  int *piVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  bool bVar13;
  float10 fVar14;
  float10 fVar15;
  float10 fVar16;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 fVar17;
  float10 fVar18;
  
  FUN_00634c24();
  cVar1 = FUN_0045c02d(extraout_ECX);
  if (((cVar1 == '\0') &&
      (1 < (uint)((*(int **)(unaff_EBP + 0xc))[1] - **(int **)(unaff_EBP + 0xc) >> 3))) &&
     ((iVar2 = FUN_0045c4b5(), iVar2 == 0 || (*(int *)(iVar2 + 0x80) == 0)))) {
    *(undefined4 *)(unaff_EBP + -0x50) = *(undefined4 *)(extraout_ECX + 0x100);
    *(undefined4 *)(unaff_EBP + -0x4c) = *(undefined4 *)(extraout_ECX + 0x104);
    *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(extraout_ECX + 0x108);
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(extraout_ECX + 0x10c);
    piVar6 = (int *)**(int **)(unaff_EBP + 0xc);
    piVar10 = (int *)(*(int **)(unaff_EBP + 0xc))[1];
    *(int **)(unaff_EBP + -0x40) = piVar10;
    piVar3 = piVar6;
    piVar9 = piVar6 + 2;
    if (piVar6 + 2 == piVar10) {
LAB_0045c21a:
      *(int *)(unaff_EBP + -0x20) = *piVar6;
      *(int *)(unaff_EBP + -0x1c) = piVar6[1];
      *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(extraout_ECX + 0xf4);
      iVar2 = *(int *)(extraout_ECX + 0xf8);
LAB_0045c244:
      *(int *)(unaff_EBP + -0x14) = iVar2;
    }
    else {
      do {
        if (1 < *(int *)(unaff_EBP + -0x10)) break;
        iVar2 = piVar9[1] - piVar3[1];
        *(int *)(unaff_EBP + -0x30) = piVar3[1];
        *(int *)(unaff_EBP + -0x3c) = iVar2;
        if (iVar2 < 0) {
          iVar2 = -iVar2;
        }
        iVar5 = *piVar3;
        iVar7 = *piVar9;
        *(int *)(unaff_EBP + -0x34) = iVar5;
        iVar7 = iVar7 - iVar5;
        *(int *)(unaff_EBP + -0x38) = iVar7;
        if (iVar7 < 0) {
          iVar7 = -iVar7;
        }
        if (iVar7 < iVar2) {
          *(int *)(unaff_EBP + 0xc) = iVar2 + 1;
        }
        else {
          *(int *)(unaff_EBP + 0xc) = iVar7 + 1;
        }
        fVar14 = (float10)*(int *)(unaff_EBP + -0x3c);
        fVar15 = (float10)*(int *)(unaff_EBP + -0x30);
        fVar16 = (float10)*(int *)(unaff_EBP + -0x38);
        do {
          fVar17 = fVar15;
          fVar18 = fVar14;
          uVar4 = __ftol();
          *(undefined4 *)(unaff_EBP + -0x28) = uVar4;
          fVar15 = extraout_ST1;
          fVar14 = fVar16;
          iVar5 = __ftol();
          iVar2 = *(int *)(unaff_EBP + -0x28);
          if ((((iVar2 < *(int *)(unaff_EBP + -0x4c)) && (*(int *)(unaff_EBP + -0x44) <= iVar2)) &&
              (iVar5 < *(int *)(unaff_EBP + -0x50))) && (*(int *)(unaff_EBP + -0x48) <= iVar5)) {
            if (*(int *)(unaff_EBP + -0x10) == 0) {
              *(int *)(unaff_EBP + -0x20) = iVar5;
              *(int *)(unaff_EBP + -0x1c) = iVar2;
              *(undefined4 *)(unaff_EBP + -0x10) = 1;
            }
          }
          else if (*(int *)(unaff_EBP + -0x10) == 1) {
            *(int *)(unaff_EBP + -0x18) = iVar5;
            *(int *)(unaff_EBP + -0x14) = iVar2;
            *(undefined4 *)(unaff_EBP + -0x10) = 2;
            break;
          }
          fVar16 = extraout_ST1_00;
        } while (fVar17 + fVar18 < (float10)_DAT_00667280);
        piVar10 = piVar9 + 2;
        piVar3 = piVar9;
        piVar9 = piVar10;
      } while (piVar10 != *(int **)(unaff_EBP + -0x40));
      if (*(int *)(unaff_EBP + -0x10) < 1) goto LAB_0045c21a;
      if (*(int *)(unaff_EBP + -0x10) < 2) {
        iVar2 = piVar3[1];
        *(int *)(unaff_EBP + -0x18) = *piVar3;
        goto LAB_0045c244;
      }
    }
    iVar2 = FUN_0043acf5(0x7c4);
    if (iVar2 != 0) {
      uVar4 = FUN_00440b6d(iVar2);
      *(undefined4 *)(unaff_EBP + -0x10) = uVar4;
      if ((short)uVar4 != 0) {
        uVar8 = (uint)*(short *)(unaff_EBP + -0x10);
        iVar2 = *(int *)(extraout_ECX + 0xdc);
        *(undefined4 *)(unaff_EBP + 0xc) = 0;
        if ((0 < (int)uVar8) &&
           (uVar8 < (*(int *)(iVar2 + 0x1c) - *(int *)(iVar2 + 0x18) >> 2) + 1U)) {
          *(undefined4 *)(unaff_EBP + 0xc) =
               *(undefined4 *)(*(int *)(iVar2 + 0x18) + -4 + uVar8 * 4);
        }
        (**(code **)(**(int **)(unaff_EBP + 0xc) + 0x58))
                  (extraout_ECX + 0xf4,*(undefined4 *)(extraout_ECX + 0x110),0,0,1);
        FUN_0046de64();
        iVar2 = *(int *)(unaff_EBP + -0x14);
        *(int *)(unaff_EBP + -0x14) = iVar2;
        *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) - *(int *)(unaff_EBP + -0x20);
        *(int *)(unaff_EBP + -0x14) = iVar2 - *(int *)(unaff_EBP + -0x1c);
        piVar6 = (int *)FUN_00422055(0,0);
        if ((*(int *)(unaff_EBP + -0x14) != piVar6[1]) || (*(int *)(unaff_EBP + -0x18) != *piVar6))
        {
          FUN_00422055(0,0);
          iVar2 = FUN_00452129(unaff_EBP + -0x18);
          FUN_0046df0d((iVar2 + 2) % 8);
          FUN_0046df0d((iVar2 + 6) % 8);
          FUN_0046df27();
          FUN_0046df4f(0x10,0x50,0x10);
          *(undefined4 *)(unaff_EBP + -0x54) = 8;
          FUN_0046df2c();
          FUN_0046dfa0(0,1);
          *(byte *)(unaff_EBP + -0x6f) = *(byte *)(unaff_EBP + -0x6f) & 0xdf;
          *(byte *)(unaff_EBP + -0x6f) = *(byte *)(unaff_EBP + -0x6f) | 0x20;
          FUN_00481798(extraout_ECX,*(undefined4 *)(unaff_EBP + 0xc),unaff_EBP + -0x8c);
          *(undefined4 *)(unaff_EBP + -4) = 0;
          FUN_004824b8();
          *(undefined4 *)(unaff_EBP + -0x24) = 0;
          *(undefined4 *)(unaff_EBP + -0x20) = 0;
          *(undefined4 *)(unaff_EBP + -0x1c) = 0;
          *(undefined1 *)(unaff_EBP + -4) = 1;
          cVar1 = FUN_00482558(unaff_EBP + -0x24);
          if (cVar1 == '\0') {
            FUN_0046df0d(iVar2 % 8);
            FUN_0046df4f(0x10,0x50,0x50);
          }
          *(undefined1 *)(unaff_EBP + -4) = 0;
          FUN_00542b02();
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005db425();
          puVar11 = (undefined4 *)(unaff_EBP + -0x8c);
          puVar12 = *(undefined4 **)(*(int *)(unaff_EBP + 0xc) + 0x13c);
          for (iVar2 = 0xf; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar12 = *puVar11;
            puVar11 = puVar11 + 1;
            puVar12 = puVar12 + 1;
          }
          iVar2 = *(int *)(unaff_EBP + 8);
          iVar5 = FUN_006359f2(*(undefined4 *)(iVar2 + 0x4c),0,&cXObject::RTTI_Type_Descriptor,
                               &cXPerson::RTTI_Type_Descriptor,0);
          FUN_0041f010(extraout_ECX,*(undefined4 *)(unaff_EBP + 0xc),3,
                       (int)*(short *)(iVar5 + 0x5ce));
          *(undefined4 *)(unaff_EBP + -4) = 2;
          cVar1 = FUN_0045d377(unaff_EBP + -0xd0);
          bVar13 = cVar1 != '\0';
          if (bVar13) {
            uVar4 = *(undefined4 *)(unaff_EBP + -0x94);
            *(undefined1 *)(iVar2 + 0x84) = 0;
            *(int *)(iVar2 + 0x80) = extraout_ECX;
            *(undefined4 *)(iVar2 + 0x90) = uVar4;
          }
          else {
            FUN_0044127f(*(undefined4 *)(unaff_EBP + -0x10));
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005b8770();
          goto LAB_0045c4a4;
        }
      }
    }
  }
  bVar13 = false;
LAB_0045c4a4:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return bVar13;
}

