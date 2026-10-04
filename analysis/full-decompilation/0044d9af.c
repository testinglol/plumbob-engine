
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0044d9af(void)

{
  undefined1 uVar1;
  short sVar2;
  undefined4 *puVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  undefined4 uVar8;
  undefined4 extraout_ECX;
  uint uVar9;
  char cVar10;
  int unaff_EBP;
  int iVar11;
  int *piVar12;
  int iVar13;
  bool bVar14;
  
  FUN_00634c24();
  sVar2 = *(short *)(*(int *)(unaff_EBP + 8) + 4);
  *(undefined4 *)(unaff_EBP + -0x40) = extraout_ECX;
  iVar5 = FUN_00407498((int)sVar2);
  *(int *)(unaff_EBP + -0x10) = iVar5;
  if (iVar5 == 0) {
    *(undefined4 *)(unaff_EBP + 0xc) = 0x15;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(unaff_EBP + 0xc,&DAT_00698f30);
  }
  cVar4 = FUN_00432644();
  if (cVar4 != '\0') {
    uVar6 = FUN_0043acf5(0x24c95f99);
    *(undefined4 *)(unaff_EBP + -0x34) = uVar6;
    iVar5 = *(int *)(unaff_EBP + -0x10);
    cVar4 = **(char **)(unaff_EBP + 0xc);
    iVar11 = *(int *)(iVar5 + 0xf4);
    *(int *)(unaff_EBP + -0x58) = iVar11;
    iVar13 = *(int *)(iVar5 + 0xf8);
    *(int *)(unaff_EBP + -0x54) = iVar13;
    uVar6 = *(undefined4 *)(iVar5 + 0x110);
    if (cVar4 == '\x01') {
      iVar11 = *(int *)(iVar5 + 0xf4);
      iVar13 = *(int *)(iVar5 + 0xf8);
      piVar7 = (int *)FUN_004222bd((int)*(short *)(iVar5 + 0x4c));
      iVar13 = iVar13 + piVar7[1];
      iVar11 = iVar11 + *piVar7;
      *(int *)(unaff_EBP + -0x58) = iVar11;
      *(int *)(unaff_EBP + -0x54) = iVar13;
      uVar6 = *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x110);
    }
    *(char *)(unaff_EBP + -0x2e) = (char)uVar6;
    cVar4 = (char)(iVar13 >> 4);
    *(char *)(unaff_EBP + -0x30) = cVar4;
    cVar10 = (char)(iVar11 >> 4);
    *(char *)(unaff_EBP + -0x2f) = cVar10;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (((('\0' < cVar4) && (iVar5 = *(int *)(DAT_006e54dc + 0x10) + -1, cVar4 < iVar5)) &&
        ('\0' < cVar10)) && (cVar10 < iVar5)) {
      if (**(char **)(unaff_EBP + 0xc) == '\x01') {
        FUN_00479737(unaff_EBP + -0xb4,unaff_EBP + -0x30);
        *(undefined1 *)(unaff_EBP + -4) = 1;
        uVar9 = *(uint *)(&DAT_006f4640 +
                         ((int)*(short *)(*(int *)(unaff_EBP + -0x10) + 0x4c) / 2) * 0x100);
        if ((uVar9 & *(uint *)(unaff_EBP + -0xb4)) == uVar9) {
          iVar5 = FUN_00435221(uVar9,0);
          sVar2 = *(short *)(unaff_EBP + -0xac + iVar5 * 2);
          if (((sVar2 != 3) && (sVar2 != 5)) &&
             ((sVar2 != 6 && ((sVar2 != 0xf && (sVar2 != 0x17)))))) goto LAB_0044e0eb;
        }
        if ((*(byte *)(unaff_EBP + -0xb4) & 0x30) != 0) goto LAB_0044e0eb;
        *(undefined1 *)(unaff_EBP + -4) = 0;
      }
      puVar3 = DAT_006e486c;
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      FUN_0043f371(*puVar3,unaff_EBP + -0x30,0);
      while (iVar5 = *(int *)(unaff_EBP + -0x24), iVar5 != 0) {
        if ((*(byte *)(iVar5 + 0x9a) & 0x20) != 0) {
          *(int *)(unaff_EBP + -0x10) = iVar5;
        }
        if (((*(ushort *)(iVar5 + 0x5a) & 0x800) != 0) ||
           (*(int *)(iVar5 + 0x11c) == *(int *)(unaff_EBP + -0x34))) goto LAB_0044e0eb;
        FUN_0043f3b9();
      }
      if (*(int *)(unaff_EBP + -0x10) != 0) {
        if ((DAT_006e4f2c & 1) == 0) {
          DAT_006e4f2c = DAT_006e4f2c | 1;
          DAT_006e4f20 = (int *)0x0;
          DAT_006e4f24 = (int *)0x0;
          _DAT_006e4f28 = 0;
          FUN_00635543(&LAB_0044e0fe);
        }
        FUN_00448aa5(DAT_006e4f20,DAT_006e4f24);
        FUN_0044845a(unaff_EBP + -0x10);
LAB_0044dc5b:
        do {
          piVar12 = DAT_006e4f24;
          piVar7 = DAT_006e4f20;
          bVar14 = DAT_006e4f20 == DAT_006e4f24;
          *(undefined1 *)(unaff_EBP + 0xb) = 1;
          *(int **)(unaff_EBP + -0x1c) = piVar7;
          piVar7 = DAT_006e4f20;
          if (bVar14) break;
          do {
            iVar5 = **(int **)(unaff_EBP + -0x1c);
            if ((*(short *)(*(int *)(iVar5 + 0x118) + 0x14) != 0) &&
               ((*(byte *)(iVar5 + 0x9a) & 0x20) != 0)) {
              iVar5 = FUN_006359f2(iVar5,0,&cXObject::RTTI_Type_Descriptor,
                                   &cXMTObject::RTTI_Type_Descriptor,0);
              cVar4 = FUN_00423481();
              if (cVar4 == '\0') {
                if (*(int *)(iVar5 + 400) != 0) {
                  iVar5 = *(int *)(iVar5 + 400);
                }
                for (; iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x18c)) {
                  piVar7 = DAT_006e4f20;
                  if (DAT_006e4f20 == DAT_006e4f24) {
LAB_0044dce6:
                    *(int *)(unaff_EBP + 8) = iVar5;
                    FUN_0044845a(unaff_EBP + 8);
                    *(undefined1 *)(unaff_EBP + 0xb) = 0;
                  }
                  else {
                    do {
                      if (*piVar7 == iVar5) break;
                      piVar7 = piVar7 + 1;
                    } while (piVar7 != DAT_006e4f24);
                    if (piVar7 == DAT_006e4f24) goto LAB_0044dce6;
                  }
                }
              }
            }
            if (*(char *)(unaff_EBP + 0xb) == '\0') goto LAB_0044dc5b;
            FUN_0043f371(*DAT_006e486c,**(int **)(unaff_EBP + -0x1c) + 0xfc,0);
            *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x88);
            *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x84);
            *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x80);
            if (*(int *)(unaff_EBP + -0x84) != 0) {
              iVar5 = *(int *)(unaff_EBP + -0x24);
              do {
                if ((*(byte *)(iVar5 + 0x9a) & 0x20) != 0) {
                  piVar7 = DAT_006e4f20;
                  if (DAT_006e4f20 != DAT_006e4f24) {
                    do {
                      if (*piVar7 == iVar5) break;
                      piVar7 = piVar7 + 1;
                    } while (piVar7 != DAT_006e4f24);
                    if (piVar7 != DAT_006e4f24) goto LAB_0044dd85;
                  }
                  *(int *)(unaff_EBP + 8) = iVar5;
                  FUN_0044845a(unaff_EBP + 8);
                  *(undefined1 *)(unaff_EBP + 0xb) = 0;
                }
LAB_0044dd85:
                FUN_0043f3b9();
                iVar5 = *(int *)(unaff_EBP + -0x24);
              } while (iVar5 != 0);
            }
            if (*(char *)(unaff_EBP + 0xb) == '\0') goto LAB_0044dc5b;
            iVar5 = **(int **)(unaff_EBP + -0x1c);
            cVar4 = *(char *)(iVar5 + 0xfc);
            cVar10 = *(char *)(iVar5 + 0xfd);
            uVar1 = *(undefined1 *)(iVar5 + 0xfe);
            *(char *)(unaff_EBP + -0x3c) = cVar4;
            *(char *)(unaff_EBP + -0x3b) = cVar10;
            *(undefined1 *)(unaff_EBP + -0x3a) = uVar1;
            iVar11 = (int)cVar4;
            *(int *)(unaff_EBP + -0x68) = iVar11;
            *(int *)(unaff_EBP + -0x70) = iVar11 << 4;
            iVar5 = (int)cVar10;
            *(int *)(unaff_EBP + -0x14) = iVar5;
            *(int *)(unaff_EBP + -0x74) = iVar5 << 4;
            *(undefined4 *)(unaff_EBP + -0x2c) = 0;
            *(int *)(unaff_EBP + -0x7c) = (iVar5 + 1) * 0x10;
            do {
              if (*(char *)(unaff_EBP + 0xb) == '\0') goto LAB_0044df01;
              *(undefined1 *)(unaff_EBP + -0x36) = *(undefined1 *)(unaff_EBP + -0x3a);
              *(undefined1 *)(unaff_EBP + -4) = 3;
              *(char *)(unaff_EBP + -0x38) =
                   (char)*(undefined4 *)(&DAT_006c2924 + *(int *)(unaff_EBP + -0x2c)) +
                   (char)*(undefined4 *)(unaff_EBP + -0x68);
              *(char *)(unaff_EBP + -0x37) =
                   (char)*(undefined4 *)(&DAT_006c2948 + *(int *)(unaff_EBP + -0x2c)) +
                   (char)*(undefined4 *)(unaff_EBP + -0x14);
              FUN_0043f371(*DAT_006e486c,unaff_EBP + -0x38,0);
              *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -100);
              *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x60);
              *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x5c);
              if (*(int *)(unaff_EBP + -0x60) != 0) {
                iVar5 = *(int *)(unaff_EBP + -0x24);
                do {
                  if (*(char *)(unaff_EBP + 0xb) == '\0') break;
                  *(undefined4 *)(unaff_EBP + -0x50) = *(undefined4 *)(iVar5 + 0x100);
                  iVar13 = *(int *)(iVar5 + 0x118);
                  *(undefined4 *)(unaff_EBP + -0x4c) = *(undefined4 *)(iVar5 + 0x104);
                  *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(iVar5 + 0x108);
                  sVar2 = *(short *)(iVar13 + 0x12);
                  *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(iVar5 + 0x10c);
                  if (sVar2 == 2) {
                    *(int *)(unaff_EBP + -0x44) = *(int *)(unaff_EBP + -0x44) + -2;
                    *(int *)(unaff_EBP + -0x4c) = *(int *)(unaff_EBP + -0x4c) + 2;
                    *(int *)(unaff_EBP + -0x48) = *(int *)(unaff_EBP + -0x48) + -2;
                    *(int *)(unaff_EBP + -0x50) = *(int *)(unaff_EBP + -0x50) + 2;
                  }
                  if ((((*(int *)(unaff_EBP + -0x48) < *(int *)(unaff_EBP + -0x7c)) &&
                       (*(int *)(unaff_EBP + -0x74) < *(int *)(unaff_EBP + -0x50))) &&
                      (*(int *)(unaff_EBP + -0x44) < (iVar11 + 1) * 0x10)) &&
                     (*(int *)(unaff_EBP + -0x70) < *(int *)(unaff_EBP + -0x4c))) {
                    piVar7 = DAT_006e4f20;
                    if (DAT_006e4f20 != DAT_006e4f24) {
                      do {
                        if (*piVar7 == iVar5) break;
                        piVar7 = piVar7 + 1;
                      } while (piVar7 != DAT_006e4f24);
                      if (piVar7 != DAT_006e4f24) goto LAB_0044dec1;
                    }
                    *(int *)(unaff_EBP + 8) = iVar5;
                    FUN_0044845a(unaff_EBP + 8);
                    *(undefined1 *)(unaff_EBP + 0xb) = 0;
                  }
LAB_0044dec1:
                  FUN_0043f3b9();
                  iVar5 = *(int *)(unaff_EBP + -0x24);
                } while (iVar5 != 0);
              }
              *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x2c) + 4;
            } while (*(int *)(unaff_EBP + -0x2c) < 0x20);
            if (*(char *)(unaff_EBP + 0xb) == '\0') {
LAB_0044df01:
              *(undefined1 *)(unaff_EBP + -4) = 0;
              break;
            }
            *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 4;
            *(undefined1 *)(unaff_EBP + -4) = 0;
          } while (*(int **)(unaff_EBP + -0x1c) != DAT_006e4f24);
          piVar7 = DAT_006e4f20;
          piVar12 = DAT_006e4f24;
        } while (*(char *)(unaff_EBP + 0xb) == '\0');
        do {
          if (piVar7 == piVar12) goto LAB_0044df5f;
          uVar9 = (uint)*(short *)(*piVar7 + 0x5a);
          if (((uVar9 >> 0xb & 1) != 0) ||
             (((*(byte *)(*(int *)(unaff_EBP + 0xc) + 1) & 1) == 0 &&
              (((uVar9 >> 5 & 1) != 0 || (0 < *(short *)(*piVar7 + 0xc6))))))) goto LAB_0044e0eb;
          piVar7 = piVar7 + 1;
        } while( true );
      }
      uVar8 = FUN_00440b6d(*(undefined4 *)(unaff_EBP + -0x34));
      *(undefined4 *)(unaff_EBP + 0xc) = uVar8;
      if ((short)uVar8 != 0) {
        piVar7 = (int *)FUN_00407498((int)(short)uVar8);
        cVar4 = (**(code **)(*piVar7 + 0x54))(unaff_EBP + -0x58,uVar6,0,0);
        if (cVar4 != '\0') {
          (**(code **)(*piVar7 + 0x58))(unaff_EBP + -0x58,uVar6,0,0,1);
          goto LAB_0044dbf0;
        }
        FUN_0044127f(*(undefined4 *)(unaff_EBP + 0xc));
      }
    }
  }
LAB_0044e0eb:
  uVar6 = 0;
LAB_0044e0ed:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar6;
LAB_0044df5f:
  piVar7 = DAT_006e4f20;
  if (DAT_006e4f20 != piVar12) {
    do {
      piVar12 = (int *)*piVar7;
      if (*(short *)(piVar12[0x46] + 0x12) == 2) {
        *(int *)(unaff_EBP + -0x18) = piVar12[0x3d];
        *(int *)(unaff_EBP + -0x14) = piVar12[0x3e];
        iVar5 = piVar12[0x44];
        (**(code **)(*piVar12 + 0x38))(0);
        piVar12 = (int *)*piVar7;
        *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffff0;
        *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) | 8;
        *(uint *)(unaff_EBP + -0x18) = *(uint *)(unaff_EBP + -0x18) & 0xfffffff8 | 8;
        (**(code **)(*piVar12 + 0x58))(unaff_EBP + -0x18,iVar5,0,0,1);
        (**(code **)(*(int *)*piVar7 + 0x74))();
      }
      piVar7 = piVar7 + 1;
      piVar12 = DAT_006e4f24;
    } while (piVar7 != DAT_006e4f24);
  }
  piVar7 = DAT_006e4f20;
  *(undefined1 *)(unaff_EBP + 0xf) = 0;
  if (piVar7 != piVar12) {
    do {
      FUN_0043f371(*DAT_006e486c,*piVar7 + 0xfc,0);
      *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -100);
      *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x60);
      *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x5c);
      if (*(int *)(unaff_EBP + -0x60) == 0) {
LAB_0044e02a:
        iVar5 = *(int *)(unaff_EBP + -0x40);
        uVar6 = FUN_00440b6d(*(undefined4 *)(unaff_EBP + -0x34));
        *(undefined4 *)(unaff_EBP + 8) = uVar6;
        if ((short)uVar6 == 0) goto LAB_0044e0eb;
        uVar9 = (uint)(short)uVar6;
        iVar5 = *(int *)(iVar5 + 0xdc);
        piVar12 = (int *)0x0;
        if ((0 < (int)uVar9) &&
           (uVar9 < (*(int *)(iVar5 + 0x1c) - *(int *)(iVar5 + 0x18) >> 2) + 1U)) {
          piVar12 = *(int **)(*(int *)(iVar5 + 0x18) + -4 + uVar9 * 4);
        }
        iVar5 = *piVar7;
        uVar9 = *(uint *)(iVar5 + 0xf4);
        *(uint *)(unaff_EBP + -0x18) = uVar9;
        *(uint *)(unaff_EBP + -0x14) = *(uint *)(iVar5 + 0xf8) & 0xfffffff0 | 8;
        *(uint *)(unaff_EBP + -0x18) = uVar9 & 0xfffffff8 | 8;
        cVar4 = (**(code **)(*piVar12 + 0x54))(unaff_EBP + -0x18,*(undefined4 *)(iVar5 + 0x110),0,0)
        ;
        if (cVar4 == '\0') {
          FUN_0044127f(*(undefined4 *)(unaff_EBP + 8));
        }
        else {
          (**(code **)(*piVar12 + 0x58))(unaff_EBP + -0x18,*(undefined4 *)(*piVar7 + 0x110),0,0,1);
          *(undefined1 *)(unaff_EBP + 0xf) = 1;
        }
      }
      else {
        do {
          if (*(int *)(*(int *)(unaff_EBP + -0x24) + 0x11c) == *(int *)(unaff_EBP + -0x34)) break;
          FUN_0043f3b9();
        } while (*(int *)(unaff_EBP + -0x24) != 0);
        if (*(int *)(unaff_EBP + -0x24) == 0) goto LAB_0044e02a;
      }
      piVar7 = piVar7 + 1;
    } while (piVar7 != DAT_006e4f24);
    if (*(char *)(unaff_EBP + 0xf) != '\0') {
LAB_0044dbf0:
      uVar6 = 1;
      goto LAB_0044e0ed;
    }
  }
  goto LAB_0044e0eb;
}

