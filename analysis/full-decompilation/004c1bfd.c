
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c1bfd(void)

{
  undefined4 *puVar1;
  bool bVar2;
  int iVar3;
  char cVar4;
  undefined1 uVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int extraout_ECX;
  ushort *puVar10;
  int unaff_EBP;
  uint uVar11;
  undefined4 *puVar12;
  uint uVar13;
  int iVar14;
  float10 fVar15;
  undefined4 uVar16;
  
  FUN_00634c24();
  iVar8 = *(int *)(extraout_ECX + 0xc);
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  puVar10 = (ushort *)(*(int *)(iVar8 + 0xc + *(int *)(unaff_EBP + 0xc) * 4) + iVar8);
  SetRect((LPRECT)(unaff_EBP + -0x60),*(int *)(unaff_EBP + 0x10),*(int *)(unaff_EBP + 0x14),
          (uint)*puVar10 + *(int *)(unaff_EBP + 0x10),(uint)puVar10[1] + *(int *)(unaff_EBP + 0x14))
  ;
  *(int *)(unaff_EBP + -0x2c) = (int)DAT_006f0bc0;
  *(int *)(unaff_EBP + -0x24) = (int)DAT_006f0bc4;
  *(int *)(unaff_EBP + -0x30) = (int)DAT_006f0bc2;
  *(int *)(unaff_EBP + -0x28) = (int)DAT_006f0bc6;
  *(undefined4 *)(unaff_EBP + -0x50) = *(undefined4 *)(unaff_EBP + -0x30);
  *(undefined4 *)(unaff_EBP + -0x4c) = *(undefined4 *)(unaff_EBP + -0x2c);
  *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(unaff_EBP + -0x28);
  *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(unaff_EBP + -0x24);
  *(undefined4 *)(unaff_EBP + -0x70) = *(undefined4 *)(unaff_EBP + -0x60);
  *(undefined4 *)(unaff_EBP + -0x6c) = *(undefined4 *)(unaff_EBP + -0x5c);
  *(undefined4 *)(unaff_EBP + -0x68) = *(undefined4 *)(unaff_EBP + -0x58);
  *(undefined4 *)(unaff_EBP + -100) = *(undefined4 *)(unaff_EBP + -0x54);
  FUN_004a7901();
  if ((((*(int *)(unaff_EBP + -0x60) == *(int *)(unaff_EBP + -0x70)) &&
       (*(int *)(unaff_EBP + -0x5c) == *(int *)(unaff_EBP + -0x6c))) &&
      (*(int *)(unaff_EBP + -0x58) == *(int *)(unaff_EBP + -0x68))) &&
     (*(int *)(unaff_EBP + -0x54) == *(int *)(unaff_EBP + -100))) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  *(bool *)(unaff_EBP + 0xf) = !bVar2;
  if (*(char *)(unaff_EBP + 0xf) == '\0') {
LAB_004c1cf9:
    iVar8 = *(int *)(unaff_EBP + 0x1c);
    cVar4 = FUN_004b465e();
    if ((cVar4 == '\0') || (cVar4 = FUN_004b4665(), cVar4 == '\0')) {
      puVar12 = (undefined4 *)(unaff_EBP + -0x70);
      goto LAB_004c226a;
    }
    *(undefined1 *)(unaff_EBP + -0x14) = 0;
    uVar6 = *(uint *)(unaff_EBP + 0x18) & 4;
    *(uint *)(unaff_EBP + -0x18) = uVar6;
    if ((short)uVar6 != 0) {
      uVar5 = FUN_004b46de();
      *(undefined1 *)(unaff_EBP + -0x14) = uVar5;
      FUN_004b46e2(1);
    }
    cVar4 = FUN_004b4708();
    if (cVar4 == '\0') {
      cVar4 = FUN_004b470c();
      if (cVar4 == '\0') {
        cVar4 = FUN_004b4700();
        if (cVar4 == '\0') {
          cVar4 = FUN_004b4704();
          if (cVar4 == '\0') {
            fVar15 = (float10)FUN_004b46a4();
          }
          else {
            fVar15 = (float10)FUN_004b46a4();
            fVar15 = fVar15 * (float10)_DAT_006f0130;
          }
          iVar14 = FUN_004b9722((float)fVar15);
        }
        else {
          iVar14 = *(int *)(*(int *)(unaff_EBP + -0x10) + 8) + 0x620;
        }
      }
      else {
        iVar14 = *(int *)(*(int *)(unaff_EBP + -0x10) + 8) + 0xa20;
      }
    }
    else {
      iVar14 = *(int *)(*(int *)(unaff_EBP + -0x10) + 8) + 0x820;
    }
    uVar5 = FUN_004b4710();
    *(undefined1 *)(unaff_EBP + 0x1f) = uVar5;
    FUN_004cebb0();
    uVar7 = FUN_0049a73d(iVar8,*(undefined4 *)(iVar8 + 0x24));
    *(undefined4 *)(unaff_EBP + -0x10) = uVar7;
    if (*(char *)(unaff_EBP + 0x20) == '\0') {
      iVar8 = DAT_006f0bd4 >> 1;
      if ((*(byte *)(unaff_EBP + 0x18) & 1) == 0) {
        if (*(char *)(unaff_EBP + 0x1f) == '\0') {
          if (*(char *)(unaff_EBP + 0xf) == '\0') {
            *(int *)(unaff_EBP + -0x24) = iVar8;
            iVar9 = DAT_006f0bcc;
            *(int *)(unaff_EBP + -0x28) =
                 DAT_006f0bd0 +
                 (iVar8 * *(int *)(unaff_EBP + 0x14) + *(int *)(unaff_EBP + 0x10)) * 2;
            iVar8 = DAT_006f0bbc >> 1;
            *(int *)(unaff_EBP + -0x1c) = iVar8;
            *(int *)(unaff_EBP + -0x20) =
                 iVar9 + (iVar8 * *(int *)(unaff_EBP + 0x14) + *(int *)(unaff_EBP + 0x10)) * 2;
            uVar7 = FUN_004ca70b();
            (*DAT_006f0a5c)(unaff_EBP + -0x20,unaff_EBP + -0x28,puVar10,iVar14,
                            *(undefined4 *)(unaff_EBP + -0x10),uVar7);
          }
          else {
            *(int *)(unaff_EBP + -0x24) = iVar8;
            iVar9 = DAT_006f0bcc;
            *(int *)(unaff_EBP + -0x28) =
                 DAT_006f0bd0 +
                 (iVar8 * *(int *)(unaff_EBP + 0x14) + *(int *)(unaff_EBP + 0x10)) * 2;
            iVar8 = DAT_006f0bbc >> 1;
            *(int *)(unaff_EBP + -0x1c) = iVar8;
            *(int *)(unaff_EBP + -0x20) =
                 iVar9 + (iVar8 * *(int *)(unaff_EBP + 0x14) + *(int *)(unaff_EBP + 0x10)) * 2;
            uVar7 = FUN_004ca70b(unaff_EBP + -0x50);
            (*DAT_006f0a60)(unaff_EBP + -0x20,unaff_EBP + -0x28,puVar10,iVar14,
                            *(undefined4 *)(unaff_EBP + -0x10),uVar7);
          }
        }
        else if (*(char *)(unaff_EBP + 0xf) == '\0') {
          *(int *)(unaff_EBP + -0x24) = iVar8;
          iVar9 = DAT_006f0bcc;
          *(int *)(unaff_EBP + -0x28) =
               DAT_006f0bd0 + (iVar8 * *(int *)(unaff_EBP + 0x14) + *(int *)(unaff_EBP + 0x10)) * 2;
          iVar8 = DAT_006f0bbc >> 1;
          *(int *)(unaff_EBP + -0x1c) = iVar8;
          *(int *)(unaff_EBP + -0x20) =
               iVar9 + (iVar8 * *(int *)(unaff_EBP + 0x14) + *(int *)(unaff_EBP + 0x10)) * 2;
          uVar7 = FUN_004ca70b();
          (*DAT_006f0a4c)(unaff_EBP + -0x20,unaff_EBP + -0x28,puVar10,iVar14,
                          *(undefined4 *)(unaff_EBP + -0x10),uVar7);
        }
        else {
          *(int *)(unaff_EBP + -0x24) = iVar8;
          iVar9 = DAT_006f0bcc;
          *(int *)(unaff_EBP + -0x28) =
               DAT_006f0bd0 + (iVar8 * *(int *)(unaff_EBP + 0x14) + *(int *)(unaff_EBP + 0x10)) * 2;
          iVar8 = DAT_006f0bbc >> 1;
          *(int *)(unaff_EBP + -0x1c) = iVar8;
          *(int *)(unaff_EBP + -0x20) =
               iVar9 + (iVar8 * *(int *)(unaff_EBP + 0x14) + *(int *)(unaff_EBP + 0x10)) * 2;
          uVar7 = FUN_004ca70b(unaff_EBP + -0x50);
          (*DAT_006f0a50)(unaff_EBP + -0x20,unaff_EBP + -0x28,puVar10,iVar14,
                          *(undefined4 *)(unaff_EBP + -0x10),uVar7);
        }
      }
      else if (*(char *)(unaff_EBP + 0x1f) == '\0') {
        if (*(char *)(unaff_EBP + 0xf) == '\0') {
          *(int *)(unaff_EBP + -0x24) = iVar8;
          iVar9 = DAT_006f0bcc;
          *(int *)(unaff_EBP + -0x28) =
               DAT_006f0bd0 + (iVar8 * *(int *)(unaff_EBP + 0x14) + *(int *)(unaff_EBP + 0x10)) * 2;
          iVar8 = DAT_006f0bbc >> 1;
          *(int *)(unaff_EBP + -0x1c) = iVar8;
          *(int *)(unaff_EBP + -0x20) =
               iVar9 + (iVar8 * *(int *)(unaff_EBP + 0x14) + *(int *)(unaff_EBP + 0x10)) * 2;
          uVar7 = FUN_004ca70b();
          (*DAT_006f0a64)(unaff_EBP + -0x20,unaff_EBP + -0x28,puVar10,iVar14,
                          *(undefined4 *)(unaff_EBP + -0x10),uVar7);
        }
        else {
          *(int *)(unaff_EBP + -0x24) = iVar8;
          iVar9 = DAT_006f0bcc;
          *(int *)(unaff_EBP + -0x28) =
               DAT_006f0bd0 + (iVar8 * *(int *)(unaff_EBP + 0x14) + *(int *)(unaff_EBP + 0x10)) * 2;
          iVar8 = DAT_006f0bbc >> 1;
          *(int *)(unaff_EBP + -0x1c) = iVar8;
          *(int *)(unaff_EBP + -0x20) =
               iVar9 + (iVar8 * *(int *)(unaff_EBP + 0x14) + *(int *)(unaff_EBP + 0x10)) * 2;
          uVar7 = FUN_004ca70b(unaff_EBP + -0x50);
          (*DAT_006f0a68)(unaff_EBP + -0x20,unaff_EBP + -0x28,puVar10,iVar14,
                          *(undefined4 *)(unaff_EBP + -0x10),uVar7);
        }
      }
      else if (*(char *)(unaff_EBP + 0xf) == '\0') {
        *(int *)(unaff_EBP + -0x1c) = iVar8;
        iVar9 = DAT_006f0bcc;
        *(int *)(unaff_EBP + -0x20) =
             DAT_006f0bd0 + (iVar8 * *(int *)(unaff_EBP + 0x14) + *(int *)(unaff_EBP + 0x10)) * 2;
        iVar8 = DAT_006f0bbc >> 1;
        *(int *)(unaff_EBP + -0x24) = iVar8;
        *(int *)(unaff_EBP + -0x28) =
             iVar9 + (iVar8 * *(int *)(unaff_EBP + 0x14) + *(int *)(unaff_EBP + 0x10)) * 2;
        uVar7 = FUN_004ca70b();
        (*DAT_006f0a54)(unaff_EBP + -0x28,unaff_EBP + -0x20,puVar10,iVar14,
                        *(undefined4 *)(unaff_EBP + -0x10),uVar7);
      }
      else {
        *(int *)(unaff_EBP + -0x24) = iVar8;
        iVar9 = DAT_006f0bcc;
        *(int *)(unaff_EBP + -0x28) =
             DAT_006f0bd0 + (iVar8 * *(int *)(unaff_EBP + 0x14) + *(int *)(unaff_EBP + 0x10)) * 2;
        iVar8 = DAT_006f0bbc >> 1;
        *(int *)(unaff_EBP + -0x1c) = iVar8;
        *(int *)(unaff_EBP + -0x20) =
             iVar9 + (iVar8 * *(int *)(unaff_EBP + 0x14) + *(int *)(unaff_EBP + 0x10)) * 2;
        uVar7 = FUN_004ca70b(unaff_EBP + -0x50);
        (*DAT_006f0a58)(unaff_EBP + -0x20,unaff_EBP + -0x28,puVar10,iVar14,
                        *(undefined4 *)(unaff_EBP + -0x10),uVar7);
      }
    }
    else {
      uVar7 = FUN_00492d2c();
      *(undefined4 *)(unaff_EBP + 0x18) = uVar7;
      iVar9 = FUN_004cebb0();
      *(int *)(unaff_EBP + 0x18) =
           *(int *)(iVar9 + (7 - *(int *)(unaff_EBP + 0x18)) * 4) + DAT_006f0084 * -4 +
           *(int *)(unaff_EBP + 0x14) * 4;
      uVar7 = __ftol();
      *(undefined4 *)(unaff_EBP + -0x3c) = uVar7;
      iVar9 = __ftol();
      *(char *)(unaff_EBP + 0x21) = (char)(iVar9 >> 4);
      uVar7 = *(undefined4 *)(iVar8 + 0xc);
      *(char *)(unaff_EBP + 0x20) = (char)(*(int *)(unaff_EBP + -0x3c) >> 4);
      *(char *)(unaff_EBP + 0x22) = (char)uVar7;
      iVar8 = DAT_006e54d8;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_00434ffd(*(undefined4 *)(iVar8 + 0x84));
      *(int *)(unaff_EBP + -0x10) = (int)*(char *)(unaff_EBP + 0x22);
      uVar7 = FUN_00492d2c();
      *(undefined4 *)(unaff_EBP + 0x1c) = uVar7;
      iVar8 = FUN_004cebb0();
      uVar16 = 0;
      *(undefined4 *)(unaff_EBP + 0x1c) =
           *(undefined4 *)(iVar8 + (0x24 - *(int *)(unaff_EBP + 0x1c)) * 4);
      uVar7 = FUN_00492d2c(0);
      iVar8 = unaff_EBP + 0x20;
      FUN_004cebb0(iVar8,uVar7);
      iVar8 = FUN_004c9f9a(iVar8,uVar7,uVar16);
      iVar9 = (iVar8 + 0x50 + (*(int *)(unaff_EBP + -0x10) + -1) * *(int *)(unaff_EBP + 0x1c)) -
              **(int **)(unaff_EBP + 0x18);
      iVar8 = DAT_006f0bd4 >> 1;
      if (*(char *)(unaff_EBP + 0xf) == '\0') {
        *(int *)(unaff_EBP + -0x24) = iVar8;
        iVar3 = DAT_006f0bcc;
        *(int *)(unaff_EBP + -0x28) =
             DAT_006f0bd0 + (iVar8 * *(int *)(unaff_EBP + 0x14) + *(int *)(unaff_EBP + 0x10)) * 2;
        iVar8 = DAT_006f0bbc >> 1;
        *(int *)(unaff_EBP + -0x1c) = iVar8;
        *(int *)(unaff_EBP + -0x20) =
             iVar3 + (iVar8 * *(int *)(unaff_EBP + 0x14) + *(int *)(unaff_EBP + 0x10)) * 2;
        (*DAT_006f0bac)(unaff_EBP + -0x20,unaff_EBP + -0x28,puVar10,iVar14,iVar9,
                        *(undefined4 *)(unaff_EBP + 0x18));
      }
      else {
        *(int *)(unaff_EBP + -0x34) = iVar8;
        iVar3 = DAT_006f0bcc;
        *(int *)(unaff_EBP + -0x38) =
             DAT_006f0bd0 + (iVar8 * *(int *)(unaff_EBP + 0x14) + *(int *)(unaff_EBP + 0x10)) * 2;
        iVar8 = DAT_006f0bbc >> 1;
        *(int *)(unaff_EBP + -0x3c) = iVar8;
        *(int *)(unaff_EBP + -0x40) =
             iVar3 + (iVar8 * *(int *)(unaff_EBP + 0x14) + *(int *)(unaff_EBP + 0x10)) * 2;
        (*DAT_006f0bb0)(unaff_EBP + -0x40,unaff_EBP + -0x38,puVar10,iVar14,iVar9,
                        *(undefined4 *)(unaff_EBP + 0x18),unaff_EBP + -0x50);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    }
    if (*(short *)(unaff_EBP + -0x18) != 0) {
      FUN_004b46e2(*(undefined4 *)(unaff_EBP + -0x14));
    }
  }
  else {
    uVar6 = *(int *)(unaff_EBP + -0x70) - *(int *)(unaff_EBP + -0x60);
    uVar13 = *(int *)(unaff_EBP + -0x58) - *(int *)(unaff_EBP + -0x68);
    uVar11 = *(int *)(unaff_EBP + -0x54) - *(int *)(unaff_EBP + -100);
    *(uint *)(unaff_EBP + -0x50) = uVar6;
    *(int *)(unaff_EBP + -0x4c) = *(int *)(unaff_EBP + -0x6c) - *(int *)(unaff_EBP + -0x5c);
    *(uint *)(unaff_EBP + -0x48) = uVar13;
    *(uint *)(unaff_EBP + -0x44) = uVar11;
    if ((((int)(uVar13 + uVar6) < (int)(uint)*puVar10) &&
        ((int)(*(int *)(unaff_EBP + -0x4c) + uVar11) < (int)(uint)puVar10[1])) &&
       (-1 < (int)(uVar11 | uVar13 | *(uint *)(unaff_EBP + -0x4c) | uVar6))) goto LAB_004c1cf9;
  }
  puVar12 = (undefined4 *)(unaff_EBP + -0x60);
LAB_004c226a:
  puVar1 = *(undefined4 **)(unaff_EBP + 8);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *puVar1 = *puVar12;
  puVar1[1] = puVar12[1];
  puVar1[2] = puVar12[2];
  puVar1[3] = puVar12[3];
  return;
}

