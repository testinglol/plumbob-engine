
undefined4 FUN_004338a5(void)

{
  int *piVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  char cVar8;
  int *extraout_ECX;
  int iVar9;
  int unaff_EBP;
  int iVar10;
  bool bVar11;
  
  FUN_00634c24();
  if (*(short *)(extraout_ECX[0x46] + 0x12) != 2) goto LAB_0043394c;
  if ((*(byte *)(extraout_ECX + 0x185) & 1) != 1) {
    if ((*(byte *)(extraout_ECX + 0x18d) & 1) != 1) {
LAB_0043394c:
      piVar1 = *(int **)(unaff_EBP + 8);
      *(undefined4 *)(unaff_EBP + -0x18) = DAT_006e54dc;
      *(undefined4 *)(unaff_EBP + -0x38) = 0;
      *(undefined4 *)(unaff_EBP + -0x34) = 0;
      *(undefined4 *)(unaff_EBP + -0x30) = 0;
      *(undefined4 *)(unaff_EBP + -0x2c) = 0;
      iVar10 = *piVar1;
      iVar4 = piVar1[1];
      *(uint *)(unaff_EBP + -0x14) = (*(ushort *)((int)extraout_ECX + 0x5a) & 4) >> 2;
      *(int *)(unaff_EBP + -0x1c) = (int)(short)extraout_ECX[0x32];
      iVar10 = iVar10 >> 4;
      *(int *)(unaff_EBP + -0x28) = iVar10;
      FUN_00433dbb(piVar1,unaff_EBP + -0x38);
      *(undefined4 *)(unaff_EBP + 8) = 0;
      do {
        *(undefined1 *)(unaff_EBP + -0xe) = *(undefined1 *)(unaff_EBP + 0xc);
        iVar9 = *(int *)(unaff_EBP + 8) * 4;
        cVar2 = (char)*(undefined4 *)(&DAT_006c2924 + iVar9) + (char)(iVar4 >> 4);
        cVar8 = (char)*(undefined4 *)(&DAT_006c2948 + iVar9) + (char)iVar10;
        *(char *)(unaff_EBP + -0x10) = cVar2;
        *(char *)(unaff_EBP + -0xf) = cVar8;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        if ('\0' < cVar2) {
          iVar10 = *(int *)(*(int *)(unaff_EBP + -0x18) + 0x10) + -1;
          if (((cVar2 < iVar10) && ('\0' < cVar8)) && (cVar8 < iVar10)) {
            sVar3 = FUN_004325af(unaff_EBP + -0x10);
            iVar10 = FUN_00407498((int)sVar3);
            while (iVar10 != 0) {
              cVar2 = (**(code **)(*extraout_ECX + 0x5c))(iVar10);
              if (cVar2 == '\0') {
                sVar3 = *(short *)(extraout_ECX[0x46] + 0x12);
                if (sVar3 == 2) {
                  uVar5 = CONCAT22((short)((uint)extraout_ECX[0x46] >> 0x10),
                                   *(ushort *)(iVar10 + 0x5a));
                  if ((*(ushort *)(iVar10 + 0x5a) & 4) == 0) {
                    uVar5 = uVar5 >> 4;
                  }
                  else {
                    uVar5 = CONCAT31((uint3)(uVar5 >> 9),~(byte)(uVar5 >> 1));
                  }
                  uVar5 = uVar5 & 0xffffff01;
                  bVar11 = (char)uVar5 == '\0';
LAB_00433a9f:
                  if (bVar11) {
LAB_00433abb:
                    cVar2 = FUN_00422d79(5,CONCAT22((short)(uVar5 >> 0x10),
                                                    *(undefined2 *)(iVar10 + 0xf0)),0);
                    if (((((cVar2 == '\0') &&
                          (cVar2 = FUN_00422d79(5,(short)extraout_ECX[0x3c],0), cVar2 == '\0')) &&
                         (*(int *)(iVar10 + 0x108) < *(int *)(unaff_EBP + -0x38))) &&
                        ((*(int *)(unaff_EBP + -0x30) < *(int *)(iVar10 + 0x100) &&
                         (*(int *)(iVar10 + 0x10c) < *(int *)(unaff_EBP + -0x34))))) &&
                       (*(int *)(unaff_EBP + -0x2c) < *(int *)(iVar10 + 0x104))) {
                      DAT_006e4a7c = 0xb;
                      DAT_006e4a80 = iVar10;
                      goto LAB_00433c37;
                    }
                  }
                }
                else if (*(short *)(*(int *)(iVar10 + 0x118) + 0x12) == 2) {
                  uVar6 = CONCAT31((int3)((uint)*(int *)(iVar10 + 0x118) >> 8),
                                   *(undefined1 *)(iVar10 + 0x614)) & 0xffffff01;
                  if ((char)uVar6 != '\x01') {
                    uVar5 = CONCAT22((short)(uVar6 >> 0x10),*(ushort *)((int)extraout_ECX + 0x5a));
                    if ((*(ushort *)((int)extraout_ECX + 0x5a) & 4) == 0) {
                      uVar5 = uVar5 >> 4;
                    }
                    else {
                      uVar5 = CONCAT31((uint3)(uVar5 >> 9),~(byte)(uVar5 >> 1));
                    }
                    uVar5 = uVar5 & 0xffffff01;
                    if ((char)uVar5 == '\0') goto LAB_00433abb;
                    if (sVar3 == 2) {
                      uVar5 = CONCAT31((int3)(uVar5 >> 8),(char)extraout_ECX[0x18d]) & 0xffffff01;
                      bVar11 = (char)uVar5 == '\x01';
                      goto LAB_00433a9f;
                    }
                  }
                }
                else {
                  uVar6 = (*(ushort *)(iVar10 + 0x5a) & 4) >> 2;
                  if ((*(int *)(unaff_EBP + -0x14) == 0) && (uVar5 = 0, uVar6 == 0))
                  goto LAB_00433abb;
                  if (*(int *)(unaff_EBP + 8) == 8) {
                    if (((int)*(short *)(iVar10 + 200) & *(uint *)(unaff_EBP + -0x1c) & 1) != 0) {
                      DAT_006e4a7c = 0xb;
                      goto LAB_00433c37;
                    }
                    if ((*(int *)(unaff_EBP + -0x14) != 0) && (uVar6 != 0)) {
                      uVar7 = FUN_00435968();
                      *(undefined4 *)(unaff_EBP + -0x20) = uVar7;
                      uVar7 = FUN_00435968();
                      *(undefined4 *)(unaff_EBP + -0x24) = uVar7;
                      iVar10 = FUN_004573f9();
                      if (*(short *)(*(int *)(iVar10 + 0x60) + 0x8a) == 2) {
                        iVar10 = FUN_004573f9();
                        if (*(short *)(*(int *)(iVar10 + 0x60) + 0x8a) == 2) {
LAB_00433bad:
                          FUN_004573f9();
                          if ((*(int *)(unaff_EBP + -0x20) == *(int *)(unaff_EBP + -0x24)) &&
                             (*(int *)(unaff_EBP + -0x20) != 0)) {
                            DAT_006e4a7c = 0x16;
                            goto LAB_00433c37;
                          }
                        }
                      }
                      else {
                        iVar10 = FUN_004573f9();
                        if (*(short *)(*(int *)(iVar10 + 0x60) + 0x8a) != 2) goto LAB_00433bad;
                      }
                    }
                  }
                }
              }
              iVar10 = FUN_004328d2(0);
            }
          }
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
        if (8 < *(int *)(unaff_EBP + 8)) goto LAB_00433c11;
        iVar10 = *(int *)(unaff_EBP + -0x28);
      } while( true );
    }
    iVar4 = (extraout_ECX[0x4d] - extraout_ECX[0x4c]) / 0x24;
    if (iVar4 == 1 || iVar4 + -1 < 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = extraout_ECX[0x4c] + 0x24;
    }
    if (iVar4 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_00407498((int)*(short *)(iVar4 + 0x10));
    }
    if (iVar4 != 0) goto LAB_0043394c;
    FUN_004678f9();
    FUN_00432664(unaff_EBP + -0x50);
    if (*(int *)(unaff_EBP + -0x44) != 0) goto LAB_0043394c;
  }
  goto LAB_00433c3b;
LAB_00433c11:
  if (((*(byte *)((int)extraout_ECX + 0x9f) & 4) == 0) &&
     (sVar3 = FUN_00476f33(unaff_EBP + -0x38,*(undefined4 *)(unaff_EBP + 0xc)), sVar3 != 0)) {
    DAT_006e4a7c = 7;
LAB_00433c37:
    uVar7 = 0;
    goto LAB_00433c3d;
  }
LAB_00433c3b:
  uVar7 = 1;
LAB_00433c3d:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar7;
}

