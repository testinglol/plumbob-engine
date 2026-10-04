
uint FUN_004aa923(void)

{
  ushort uVar1;
  byte bVar2;
  undefined4 *puVar3;
  short sVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int *extraout_ECX;
  undefined2 extraout_var;
  uint uVar8;
  int iVar9;
  int iVar10;
  int unaff_EBP;
  int iVar11;
  bool bVar12;
  
  FUN_00634c24();
  uVar6 = *(undefined4 *)(unaff_EBP + 8);
  (**(code **)(*extraout_ECX + 4))(unaff_EBP + -0x3c,uVar6,0);
  (**(code **)(*extraout_ECX + 4))(unaff_EBP + -0x44,uVar6,1);
  iVar10 = *(int *)(unaff_EBP + -0x38) >> 4;
  uVar8 = *(int *)(unaff_EBP + -0x3c) >> 4;
  *(char *)(unaff_EBP + -0x10) = (char)iVar10;
  *(char *)(unaff_EBP + -0xf) = (char)uVar8;
  *(undefined1 *)(unaff_EBP + -0xe) = *(undefined1 *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(char *)(unaff_EBP + -0x28) = (char)(*(int *)(unaff_EBP + -0x40) >> 4);
  *(char *)(unaff_EBP + -0x27) = (char)(*(int *)(unaff_EBP + -0x44) >> 4);
  *(undefined1 *)(unaff_EBP + -0x26) = *(undefined1 *)(unaff_EBP + 0xc);
  iVar11 = DAT_006e54d8;
  puVar3 = DAT_006e486c;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  iVar9 = *(int *)(iVar11 + 0x70);
  *(int *)(unaff_EBP + -0x30) = (int)*(short *)(puVar3[7] + 0x36);
  uVar5 = (uint)(char)iVar10;
  *(uint *)(unaff_EBP + -0x24) = uVar5;
  sVar4 = (short)DAT_006f0084;
  if ((((iVar9 + 1 <= (int)uVar5) && ((int)uVar5 <= *(int *)(iVar11 + 0x74) + -1)) &&
      (uVar5 = (uint)(char)uVar8, *(int *)(iVar11 + 0x78) + 1 <= (int)uVar5)) &&
     ((int)uVar5 <= *(int *)(iVar11 + 0x7c) + -1)) {
    uVar5 = *(int *)(unaff_EBP + 10) - DAT_006f0080;
    *(undefined4 *)(unaff_EBP + -0x14) = uVar6;
    *(short *)(unaff_EBP + -0x14) = *(short *)(unaff_EBP + -0x14) - sVar4;
    *(short *)(unaff_EBP + -0x12) = (short)uVar5;
    *(undefined4 *)(unaff_EBP + 8) = 0;
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    do {
      *(char *)(unaff_EBP + -0x20) = (char)iVar10;
      *(char *)(unaff_EBP + -0x1f) = (char)uVar8;
      *(undefined1 *)(unaff_EBP + -0x1e) = *(undefined1 *)(unaff_EBP + 0xc);
      iVar9 = *(int *)(iVar11 + 0x84);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_00434ffd(-iVar9 & 3);
      FUN_0043f371(*DAT_006e486c,unaff_EBP + -0x20,0);
      iVar9 = *(int *)(unaff_EBP + -0x4c);
      iVar11 = DAT_006e54d8;
      while (DAT_006e54d8 = iVar11, iVar9 != 0) {
        FUN_00438fc0(unaff_EBP + -0x60,3);
        uVar1 = *(ushort *)(iVar9 + 0x9a);
        *(uint *)(unaff_EBP + -0x2c) = CONCAT22(extraout_var,uVar1);
        if ((((int)(short)uVar5 < *(int *)(unaff_EBP + -0x60)) ||
            (*(int *)(unaff_EBP + -0x58) <= (int)(short)uVar5)) ||
           ((iVar11 = (int)*(short *)(unaff_EBP + -0x14), iVar11 < *(int *)(unaff_EBP + -0x5c) ||
            (*(int *)(unaff_EBP + -0x54) <= iVar11)))) {
          if (*(int *)(unaff_EBP + -0x1c) == 0) {
            iVar11 = *(int *)(unaff_EBP + 0x10);
            if (iVar11 == 0) {
LAB_004aab05:
              *(int *)(unaff_EBP + -0x18) = iVar9;
            }
            else if (iVar11 == 1) {
              if ((uVar1 & 0xc000) == 0) {
                if (*(int *)(unaff_EBP + -0x30) == 0) {
                  bVar12 = (*(byte *)(*(int *)(iVar9 + 0x118) + 0xb6) & 1) == 0;
                  goto LAB_004aab03;
                }
                goto LAB_004aab05;
              }
            }
            else {
              if (iVar11 == 2) {
                bVar12 = (uVar1 & 0x8000) == 0;
              }
              else {
                if (iVar11 != 3) goto LAB_004aab08;
                bVar12 = (uVar1 & 0x4000) == 0;
              }
LAB_004aab03:
              if (!bVar12) goto LAB_004aab05;
            }
          }
        }
        else {
          uVar6 = FUN_00636bef((int)*(short *)(unaff_EBP + -0x12) - *(int *)(unaff_EBP + -0x60));
          *(undefined4 *)(unaff_EBP + -0x34) = uVar6;
          uVar6 = FUN_00636bef((int)*(short *)(unaff_EBP + -0x12) - *(int *)(unaff_EBP + -0x58));
          *(undefined4 *)(unaff_EBP + -0x34) = uVar6;
          FUN_00636bef(iVar11 - *(int *)(unaff_EBP + -0x5c));
          FUN_00636bef(iVar11 - *(int *)(unaff_EBP + -0x54));
          iVar11 = *(int *)(unaff_EBP + 0x10);
          if ((iVar11 != 0) && (iVar11 != 1)) {
            if (iVar11 == 2) {
              bVar2 = *(byte *)(unaff_EBP + -0x2b) & 0x80;
            }
            else {
              if (iVar11 != 3) goto LAB_004aab08;
              bVar2 = *(byte *)(unaff_EBP + -0x2b) & 0x40;
            }
            if (bVar2 == 0) goto LAB_004aab08;
          }
          *(int *)(unaff_EBP + 8) = iVar9;
        }
LAB_004aab08:
        FUN_0043f3b9();
        uVar5 = (uint)*(ushort *)(unaff_EBP + -0x12);
        iVar11 = DAT_006e54d8;
        iVar9 = *(int *)(unaff_EBP + -0x4c);
      }
      bVar12 = true;
      if ((*(int *)(unaff_EBP + 8) == 0) && (*(int *)(unaff_EBP + -0x1c) < 0x14)) {
        iVar9 = *(int *)(unaff_EBP + -0x1c) % 3;
        if (iVar9 == 0) {
LAB_004aab47:
          iVar10 = *(int *)(unaff_EBP + -0x24) + 1;
          *(char *)(unaff_EBP + -0x10) = (char)iVar10;
        }
        else if (iVar9 == 1) {
          iVar10 = *(int *)(unaff_EBP + -0x24) + -1;
          *(char *)(unaff_EBP + -0x10) = (char)iVar10;
          *(char *)(unaff_EBP + -0xf) = *(char *)(unaff_EBP + -0xf) + '\x01';
        }
        else if (iVar9 == 2) goto LAB_004aab47;
        iVar9 = *(int *)(iVar11 + 0x70);
        iVar7 = (int)(char)iVar10;
        *(int *)(unaff_EBP + -0x24) = iVar7;
        if ((((iVar7 < iVar9 + 1) || (*(int *)(iVar11 + 0x74) + -1 < iVar7)) ||
            ((int)*(char *)(unaff_EBP + -0xf) < *(int *)(iVar11 + 0x78) + 1)) ||
           (*(int *)(iVar11 + 0x7c) + -1 < (int)*(char *)(unaff_EBP + -0xf))) {
          bVar12 = true;
        }
        else {
          bVar12 = false;
        }
      }
      *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
      *(undefined1 *)(unaff_EBP + -4) = 1;
      if (bVar12) goto code_r0x004aaba2;
      uVar8 = (uint)*(byte *)(unaff_EBP + -0xf);
    } while( true );
  }
  uVar5 = uVar5 & 0xffff0000;
LAB_004aabbc:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
code_r0x004aaba2:
  if (*(int *)(unaff_EBP + 8) == 0) {
    *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + -0x18);
    uVar5 = 0;
    if (*(int *)(unaff_EBP + -0x18) == 0) goto LAB_004aabbc;
  }
  uVar5 = CONCAT22((short)((uint)*(int *)(unaff_EBP + 8) >> 0x10),
                   *(undefined2 *)(*(int *)(unaff_EBP + 8) + 0xf0));
  goto LAB_004aabbc;
}

