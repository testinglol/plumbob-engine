
undefined4 FUN_004c624f(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 uVar5;
  int *extraout_ECX;
  int iVar6;
  int unaff_EBP;
  int *piVar7;
  undefined4 *puVar8;
  uint uVar9;
  int iVar10;
  
  FUN_00634c24();
  FUN_00636080();
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(*(int *)(unaff_EBP + 0xc) + 0x10);
  *(int **)(unaff_EBP + -0x28) = extraout_ECX;
  _memset((void *)(unaff_EBP + -0x101b8),0,0xffff);
  puVar3 = (undefined4 *)(unaff_EBP + -0x70);
  for (iVar6 = 0xb; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 1;
  piVar7 = extraout_ECX;
  do {
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    if (0 < *(int *)(unaff_EBP + -0x18)) {
      do {
        *(undefined4 *)(unaff_EBP + -0x1c) = 0;
        do {
          *(undefined1 *)(unaff_EBP + -0x2c) = *(undefined1 *)(unaff_EBP + -0x1c);
          *(undefined1 *)(unaff_EBP + -0x2b) = *(undefined1 *)(unaff_EBP + -0x20);
          *(undefined1 *)(unaff_EBP + -0x2a) = *(undefined1 *)(unaff_EBP + -0x24);
          *(undefined1 *)(unaff_EBP + -4) = 1;
          puVar3 = (undefined4 *)FUN_00479737(unaff_EBP + -0x9c,unaff_EBP + -0x2c);
          puVar8 = (undefined4 *)(unaff_EBP + -0x70);
          for (iVar6 = 0xb; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar8 = *puVar3;
            puVar3 = puVar3 + 1;
            puVar8 = puVar8 + 1;
          }
          if (*(int *)(unaff_EBP + -0x70) == 0) {
            uVar9 = 0;
          }
          else {
            uVar9 = 1;
            if (((byte)*(undefined4 *)(unaff_EBP + -0x70) & 1) != 1) {
              do {
                uVar9 = uVar9 * 2;
              } while ((uVar9 & *(uint *)(unaff_EBP + -0x70)) != uVar9);
            }
          }
          do {
            if (uVar9 == 0) break;
            iVar6 = 1;
            if (uVar9 == 0x10) {
              *(undefined4 *)(unaff_EBP + -0x10) = 4;
              iVar6 = 2;
              *(undefined4 *)(unaff_EBP + -0x14) = 2;
            }
            else if (uVar9 == 0x20) {
              *(undefined4 *)(unaff_EBP + -0x14) = 1;
              *(undefined4 *)(unaff_EBP + -0x10) = 3;
              iVar6 = 2;
            }
            else {
              *(undefined4 *)(unaff_EBP + -0x14) = 0;
            }
            piVar7 = (int *)(unaff_EBP + -0x14);
            do {
              iVar10 = *piVar7;
              if (uVar9 == 0x10) {
                if (iVar10 == 0) {
                  iVar10 = 4;
                }
              }
              else if ((uVar9 == 0x20) && (iVar10 == 0)) {
                iVar10 = 1;
              }
              iVar10 = FUN_00435221(uVar9,iVar10);
              piVar7 = piVar7 + 1;
              iVar6 = iVar6 + -1;
              *(undefined1 *)
               (unaff_EBP + -0x101b8 + (uint)*(ushort *)(unaff_EBP + -0x5c + iVar10 * 2)) = 1;
            } while (iVar6 != 0);
            do {
              uVar9 = uVar9 * 2;
              if ((uVar9 & *(uint *)(unaff_EBP + -0x70)) == uVar9) break;
            } while ((int)uVar9 < 0x20);
          } while ((int)uVar9 < 0x20);
          if ((*(byte *)(unaff_EBP + -0x48) & 0x10) != 0) {
            puVar3 = (undefined4 *)(unaff_EBP + -0x70);
            for (iVar6 = 0xb; iVar6 != 0; iVar6 = iVar6 + -1) {
              *puVar3 = 0;
              puVar3 = puVar3 + 1;
            }
          }
          *(undefined1 *)(unaff_EBP + -4) = 0;
          *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
        } while (*(int *)(unaff_EBP + -0x1c) < *(int *)(unaff_EBP + -0x18));
        *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 1;
      } while (*(int *)(unaff_EBP + -0x20) < *(int *)(unaff_EBP + -0x18));
      piVar7 = *(int **)(unaff_EBP + -0x28);
    }
    *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + 1;
  } while (*(int *)(unaff_EBP + -0x24) < 3);
  piVar1 = piVar7 + 6;
  FUN_004a17d3(piVar7[6],piVar7[7]);
  iVar6 = 0x1f;
  do {
    if (iVar6 == 0xf8) {
      iVar6 = 0x100;
    }
    if (*(char *)(unaff_EBP + -0x101b8 + iVar6) != '\0') {
      *(int *)(unaff_EBP + -0x18) = iVar6;
      FUN_00601485(unaff_EBP + 0xc,unaff_EBP + -0x18);
      iVar10 = *(int *)(unaff_EBP + 0xc);
      if (iVar10 != *piVar7) {
        iVar2 = **(int **)(iVar10 + 0x14);
        for (piVar4 = (int *)*piVar1; piVar4 != (int *)piVar7[7]; piVar4 = piVar4 + 0x47) {
          if (*piVar4 == iVar2) {
            if (piVar4 != (int *)piVar7[7]) goto LAB_004c647c;
            break;
          }
        }
        uVar5 = FUN_004a1e80(iVar2,*(int *)(*(int *)(unaff_EBP + -0x28) + 0x24) + iVar2 * 8);
        *(undefined1 *)(unaff_EBP + -4) = 2;
        FUN_004a16d8(uVar5);
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_004a216a();
        iVar10 = *(int *)(unaff_EBP + 0xc);
LAB_004c647c:
        uVar5 = *(undefined4 *)(*(int *)(iVar10 + 0x14) + 0x2c);
        *(short *)(unaff_EBP + -0x12) = (short)*(undefined4 *)(*(int *)(iVar10 + 0x14) + 4);
        *(short *)(unaff_EBP + -0x14) = (short)iVar6;
        *(undefined4 *)(unaff_EBP + -0x10) = uVar5;
        FUN_004a177b(unaff_EBP + -0x14);
        piVar7 = *(int **)(unaff_EBP + -0x28);
      }
    }
    iVar6 = iVar6 + 1;
    if (0xfffe < iVar6) {
      *(undefined4 *)(unaff_EBP + -0x44) = 0;
      *(undefined4 *)(unaff_EBP + -0x40) = 0;
      *(undefined4 *)(unaff_EBP + -0x3c) = 0;
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_004a1873(0,0);
      FUN_004a1fe2(unaff_EBP + -0x44,piVar1);
      *(int *)(unaff_EBP + -0x14) = unaff_EBP + -0x44;
      *(undefined4 *)(unaff_EBP + -0x10) = 0x57414c6d;
      FUN_004a2893(unaff_EBP + -0x14,0x57414c6d);
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_00464eab(unaff_EBP + -0x38,0,*(undefined4 *)(unaff_EBP + 8),0);
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_00465055();
      *(int **)(unaff_EBP + -0x14) = piVar1;
      *(undefined4 *)(unaff_EBP + -0x10) = 0x57414c6d;
      *(int *)(unaff_EBP + -0x34) = unaff_EBP + -0x14;
      *(undefined4 *)(unaff_EBP + -0x30) = 0x57414c6d;
      *(undefined ***)(unaff_EBP + -0x38) = &PTR_FUN_006686a8;
      *(undefined1 *)(unaff_EBP + -4) = 5;
      uVar5 = FUN_00464eab(unaff_EBP + -0x38,0,*(undefined4 *)(unaff_EBP + 8),1);
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_00465055();
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_004a1740();
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return uVar5;
    }
  } while( true );
}

