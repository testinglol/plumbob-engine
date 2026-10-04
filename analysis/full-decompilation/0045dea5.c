
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0045dea5(void)

{
  uint *puVar1;
  int *piVar2;
  short sVar3;
  ushort uVar4;
  int iVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  int extraout_ECX;
  int iVar10;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 uVar11;
  uint uVar12;
  undefined2 *puVar13;
  int unaff_EBP;
  uint *puVar14;
  bool bVar15;
  float10 fVar16;
  
  FUN_00634c24();
  if (DAT_006c2970 == '\0') {
    if (*(short *)(extraout_ECX + 0x5cc) == 0) {
      if (((((uint)(int)*(short *)(extraout_ECX + 0x60e) >> 1 & 1) != 0) ||
          (((uint)(int)*(short *)(extraout_ECX + 0x60e) >> 2 & 1) != 0)) && (DAT_006e4f18 == 0))
      goto LAB_0045df1c;
    }
    else if ((*(int *)(*(int *)(*DAT_006e486c + 0x10) + 0x10c) !=
              (int)*(short *)(extraout_ECX + 0x606)) || (1 < *(short *)(extraout_ECX + 0x60e)))
    goto LAB_0045df1c;
  }
  else {
LAB_0045df1c:
    uVar9 = FUN_004e9918(0);
    iVar7 = FUN_004e9744(uVar9);
    if (((*(int *)(*(int *)(*DAT_006e486c + 0x10) + 0x10c) != 0) || (iVar7 != extraout_ECX)) &&
       (DAT_006f2a04 == '\0')) {
      FUN_004b4015(*(undefined4 *)(extraout_ECX + 0x814),*(undefined4 *)(extraout_ECX + 0x818));
      fVar16 = (float10)FUN_00421481();
      uVar9 = DAT_006c4378;
      sVar3 = *(short *)(extraout_ECX + 0x5cc);
      *(float *)(unaff_EBP + -0x28) = (float)fVar16;
      if (sVar3 == 0) {
        uVar9 = DAT_006c4374;
      }
      *(undefined4 *)(unaff_EBP + -0x1c) = uVar9;
      FUN_004583ff(extraout_ECX,1);
      iVar7 = *(int *)(extraout_ECX + 0xdc);
      uVar4 = *(ushort *)(extraout_ECX + 0xf0);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      iVar10 = *(int *)(iVar7 + 0x1c) - *(int *)(iVar7 + 0x18) >> 2;
      iVar7 = DAT_006e486c[7];
      *(int *)(unaff_EBP + -0x30) = iVar10;
      *(uint *)(unaff_EBP + -0x14) = *(int *)(iVar7 + 0x98) + (uint)uVar4 & 3;
      cVar6 = FUN_0045e42a();
      if (cVar6 != '\0') {
        *(undefined4 *)(unaff_EBP + -0x14) = 0;
      }
      *(undefined1 *)(unaff_EBP + -0xd) = 0;
      cVar6 = FUN_00407525();
      if (((cVar6 != '\0') &&
          (*(short *)(extraout_ECX + 0x606) != *(short *)(DAT_006e486c[7] + 0x22))) &&
         (uVar12 = 1, 0 < iVar10)) {
        iVar7 = *(int *)(extraout_ECX + 0xdc);
        do {
          if (((0 < (int)uVar12) &&
              (uVar12 < (*(int *)(iVar7 + 0x1c) - *(int *)(iVar7 + 0x18) >> 2) + 1U)) &&
             ((iVar5 = *(int *)(*(int *)(iVar7 + 0x18) + -4 + uVar12 * 4), iVar5 != 0 &&
              (*(short *)(iVar5 + 0xc0) == 0x2e)))) {
            *(undefined1 *)(unaff_EBP + -0xd) = 1;
            break;
          }
          uVar12 = uVar12 + 1;
        } while ((int)uVar12 <= iVar10);
      }
      uVar12 = 1;
      *(undefined4 *)(unaff_EBP + -0x20) = 1;
      if (0 < iVar10) {
        do {
          iVar7 = *(int *)(extraout_ECX + 0xdc);
          if ((0 < (int)uVar12) &&
             (uVar12 < (*(int *)(iVar7 + 0x1c) - *(int *)(iVar7 + 0x18) >> 2) + 1U)) {
            iVar10 = *(int *)(uVar12 * 4 + -4 + *(int *)(iVar7 + 0x18));
            if (((iVar10 != 0) &&
                ((*(short *)(*(int *)(iVar10 + 0x118) + 0xe) != 0 &&
                 ((*(uint *)(uVar12 * 4 + -4 + *(int *)(iVar7 + 0x24)) >> 0x13 & 1) != 0)))) &&
               ((cVar6 = FUN_0045e447(), uVar11 = extraout_var, cVar6 == '\0' ||
                ((iVar7 = FUN_004573f9(), *(short *)(*(int *)(iVar7 + 0x60) + 0x8a) != 4 &&
                 (iVar7 = FUN_004573f9(), uVar11 = extraout_var_00,
                 *(short *)(*(int *)(iVar7 + 0x60) + 0x8a) != 5)))))) {
              if (iVar10 == extraout_ECX) {
                iVar7 = FUN_006359f2(extraout_ECX,0,&cXPerson::RTTI_Type_Descriptor,
                                     &cXPerson::RTTI_Type_Descriptor,0);
                if (iVar7 == 0) {
                  *(undefined4 *)(unaff_EBP + 8) = 0x1c;
                    /* WARNING: Subroutine does not return */
                  __CxxThrowException_8(unaff_EBP + 8,&DAT_00698f30);
                }
                uVar11 = extraout_var_01;
                if (*(short *)(iVar7 + 0x60e) < 2) goto LAB_0045e309;
              }
              if ((*(short *)(iVar10 + 0x7c) < 1) &&
                 (((((*(char *)(unaff_EBP + -0xd) == '\0' || (*(short *)(iVar10 + 0x84) == -5)) ||
                    (iVar7 = FUN_004670a4(CONCAT22(uVar11,*(short *)(iVar10 + 0x84))), iVar7 == 0))
                   || (cVar6 = FUN_00468851(), cVar6 != '\0')) ||
                  (((sVar3 = *(short *)(iVar10 + 0xc0), sVar3 != 5 && (sVar3 != 6)) && (sVar3 != 7))
                  )))) {
                iVar7 = *(int *)(unaff_EBP + -0x14);
                if (iVar7 != 0) {
                  if (iVar7 != 1) {
                    if (iVar7 == 2) {
                      if ((*(byte *)(iVar10 + 0xf0) & 1) == 0) goto LAB_0045e1d2;
                    }
                    else if ((*(byte *)(iVar10 + 0xf0) & 1) != 0) goto LAB_0045e1d2;
                    goto LAB_0045e309;
                  }
                  fVar16 = (float10)FUN_004341ed(iVar10);
                  if ((float10)_DAT_00666a50 < fVar16) goto LAB_0045e309;
                }
LAB_0045e1d2:
                FUN_0045846c(iVar10);
                if ((DAT_006e50f4 & 1) == 0) {
                  DAT_006e50f4 = DAT_006e50f4 | 1;
                  DAT_006e50e8 = (uint *)0x0;
                  DAT_006e50ec = (uint *)0x0;
                  _DAT_006e50f0 = 0;
                  FUN_00635543(&LAB_0045e4a0);
                }
                FUN_0045fcbd(DAT_006e50e8,DAT_006e50ec);
                FUN_004586ef(&DAT_006e50e8);
                if (((int)DAT_006e50ec - (int)DAT_006e50e8) / 0x44 != 0) {
                  fVar16 = (float10)FUN_004341ed(iVar10);
                  puVar14 = DAT_006e50e8;
                  bVar15 = DAT_006e50e8 != DAT_006e50ec;
                  *(float *)(unaff_EBP + -0x24) = (float)fVar16;
                  if (bVar15) {
                    puVar14 = puVar14 + 0x10;
                    do {
                      *(undefined4 *)(unaff_EBP + -0x18) = 0;
                      FUN_00458485(puVar14 + -0x10,unaff_EBP + -0x18);
                      if ((*puVar14 >> 3 & 1) != 0) {
                        uVar9 = *(undefined4 *)(*(int *)(unaff_EBP + -0x18) + 8);
                        *(float *)(unaff_EBP + -0x2c) =
                             _DAT_00666748 /
                             ((float)puVar14[-7] * *(float *)(unaff_EBP + -0x24) + _DAT_00666748);
                        fVar16 = (float10)FUN_004214d4(uVar9);
                        if (fVar16 != (float10)_DAT_0066657c) {
                          fVar16 = (fVar16 - (float10)*(float *)(unaff_EBP + -0x28)) *
                                   (float10)*(float *)(unaff_EBP + -0x2c);
                          *(float *)(unaff_EBP + -0x38) = (float)fVar16;
                          *(byte *)(unaff_EBP + -0x34) = (byte)*puVar14 & 1;
                          if ((float10)*(float *)(unaff_EBP + -0x1c) <= fVar16) {
                            *(undefined2 *)(unaff_EBP + -0x40) =
                                 *(undefined2 *)(puVar14[-0xe] + 0xf0);
                            *(undefined4 *)(unaff_EBP + -0x3c) =
                                 *(undefined4 *)(*(int *)(unaff_EBP + -0x18) + 0x18);
                            FUN_0045f85c(unaff_EBP + -0x40);
                          }
                        }
                      }
                      puVar1 = puVar14 + 1;
                      puVar14 = puVar14 + 0x11;
                    } while (puVar1 != DAT_006e50ec);
                  }
                }
              }
            }
          }
LAB_0045e309:
          uVar12 = *(int *)(unaff_EBP + -0x20) + 1;
          *(uint *)(unaff_EBP + -0x20) = uVar12;
        } while ((int)uVar12 <= *(int *)(unaff_EBP + -0x30));
      }
      piVar2 = (int *)(extraout_ECX + 0x814);
      iVar7 = *(int *)(extraout_ECX + 0x818) - *piVar2 >> 4;
      *(int *)(unaff_EBP + -0x14) = iVar7;
      if (0 < iVar7) {
        iVar7 = *piVar2;
        *(int *)(unaff_EBP + -0x30) = iVar7;
        FUN_0063560a(iVar7,*(undefined4 *)(unaff_EBP + -0x14),0x10,&LAB_0045e467);
        uVar12 = DAT_006c4380 - (int)*(short *)(extraout_ECX + 0x5b0) / 2000;
        if ((int)uVar12 < 1) {
          uVar12 = 1;
        }
        if (((*(short *)(extraout_ECX + 0x5cc) == 0) &&
            (*(char *)(*(int *)(unaff_EBP + -0x30) + 0xc) == '\0')) ||
           (cVar6 = FUN_004074bc(), cVar6 == '\0')) {
          if (*(int *)(unaff_EBP + -0x14) < (int)uVar12) {
            uVar8 = FUN_0046f556();
            uVar8 = uVar8 % *(uint *)(unaff_EBP + -0x14);
          }
          else {
            uVar8 = FUN_0046f556();
            uVar8 = uVar8 % uVar12;
          }
        }
        else {
          uVar8 = 0;
        }
        if (((int)uVar8 < *(int *)(unaff_EBP + -0x14)) &&
           ((puVar13 = (undefined2 *)(uVar8 * 0x10 + *piVar2), *(short *)(extraout_ECX + 0x58c) == 0
            || (_DAT_006c437c <= *(float *)(puVar13 + 4))))) {
          uVar11 = puVar13[2];
          iVar7 = *(int *)(unaff_EBP + 8);
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          *(undefined2 *)(extraout_ECX + 0x72) = uVar11;
          *(undefined2 *)(iVar7 + 4) = *puVar13;
          FUN_00458449();
          uVar9 = 1;
          goto LAB_0045e419;
        }
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_00458449();
    }
  }
  uVar9 = 0;
LAB_0045e419:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar9;
}

