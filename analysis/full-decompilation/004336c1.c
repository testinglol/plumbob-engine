
void FUN_004336c1(void)

{
  ushort uVar1;
  int iVar2;
  char cVar3;
  short sVar4;
  ushort uVar5;
  short sVar6;
  int iVar7;
  uint uVar8;
  char cVar9;
  int iVar10;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar2 = DAT_006e54dc;
  cVar3 = *(char *)(unaff_EBP + 0xc);
  cVar9 = *(char *)(unaff_EBP + 0x10);
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(char *)(unaff_EBP + -0x10) = cVar3;
  *(char *)(unaff_EBP + -0xf) = cVar9;
  *(undefined1 *)(unaff_EBP + -0xe) = *(undefined1 *)(unaff_EBP + 0x14);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (((('\0' < cVar3) && (iVar7 = *(int *)(iVar2 + 0x10) + -1, cVar3 < iVar7)) && ('\0' < cVar9))
     && (cVar9 < iVar7)) {
    sVar4 = FUN_004325af(unaff_EBP + -0x10);
    uVar8 = (uint)sVar4;
    if (((0 < (int)uVar8) &&
        (iVar7 = *(int *)(unaff_EBP + 8),
        uVar8 < (*(int *)(iVar7 + 0x1c) - *(int *)(iVar7 + 0x18) >> 2) + 1U)) &&
       (iVar10 = *(int *)(*(int *)(iVar7 + 0x18) + -4 + uVar8 * 4), *(int *)(unaff_EBP + 8) = iVar10
       , iVar10 != 0)) {
      *(undefined4 *)(unaff_EBP + 0x14) = 0;
      do {
        iVar10 = *(int *)(unaff_EBP + 0x14) * 4;
        cVar3 = (char)*(undefined4 *)(&DAT_006c2924 + iVar10) + *(char *)(unaff_EBP + 0xc);
        cVar9 = (char)*(undefined4 *)(&DAT_006c2948 + iVar10) + *(char *)(unaff_EBP + 0x10);
        *(char *)(unaff_EBP + -0x10) = cVar3;
        *(char *)(unaff_EBP + -0xf) = cVar9;
        if ((('\0' < cVar3) && (iVar10 = *(int *)(iVar2 + 0x10) + -1, cVar3 < iVar10)) &&
           (('\0' < cVar9 && (cVar9 < iVar10)))) {
          sVar4 = FUN_004325af(unaff_EBP + -0x10);
          uVar8 = (uint)sVar4;
          iVar10 = 0;
          if ((0 < (int)uVar8) &&
             (uVar8 < (*(int *)(iVar7 + 0x1c) - *(int *)(iVar7 + 0x18) >> 2) + 1U)) {
            iVar10 = *(int *)(*(int *)(iVar7 + 0x18) + -4 + uVar8 * 4);
          }
          if (iVar10 != 0) {
            do {
              if ((*(byte *)(iVar10 + 0x5a) & 4) == 0) break;
              iVar10 = FUN_004328d2(0);
            } while (iVar10 != 0);
            if (iVar10 != 0) {
              FUN_00457da4();
              sVar4 = FUN_004561a0(0x1a);
              if ((sVar4 != 0) &&
                 (*(ushort *)(iVar10 + 0x4c) == ((short)*(undefined4 *)(unaff_EBP + 0x14) - 4U & 7))
                 ) {
                sVar4 = 1;
                goto LAB_00433824;
              }
            }
          }
        }
        *(int *)(unaff_EBP + 0x14) = *(int *)(unaff_EBP + 0x14) + 2;
      } while (*(int *)(unaff_EBP + 0x14) < 8);
      sVar4 = (short)*(undefined4 *)(unaff_EBP + -0x14);
LAB_00433824:
      FUN_0043f3a4(*(undefined4 *)(unaff_EBP + 8),0);
      while (iVar2 = *(int *)(unaff_EBP + -0x1c), iVar2 != 0) {
        uVar1 = *(ushort *)(iVar2 + 0x5a);
        if (sVar4 == 0) {
          uVar5 = uVar1 & 0xfeff;
        }
        else {
          uVar5 = uVar1 | 0x100;
        }
        *(ushort *)(iVar2 + 0x5a) = uVar5;
        if ((uVar1 & 0x100) == 0) {
          if (sVar4 != 0) goto LAB_00433868;
        }
        else if (sVar4 == 0) {
LAB_00433868:
          FUN_00457da4();
          sVar6 = FUN_004561a0(0x19);
          if (sVar6 != 0) {
            FUN_00422d79(9,0,0);
          }
        }
        FUN_0043f3b9();
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

