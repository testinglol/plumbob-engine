
undefined4 FUN_00433c6a(void)

{
  char cVar1;
  short sVar2;
  undefined2 uVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  char cVar7;
  int iVar8;
  short *psVar9;
  undefined4 uVar10;
  undefined3 uVar11;
  char cVar12;
  int iVar13;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar6 = DAT_006e54dc;
  puVar4 = *(uint **)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + 10) = *(undefined1 *)(unaff_EBP + 0xc);
  uVar5 = *puVar4;
  iVar8 = (int)puVar4[1] >> 4;
  cVar7 = (char)iVar8;
  *(char *)(unaff_EBP + 8) = cVar7;
  cVar12 = (char)((int)uVar5 >> 4);
  *(char *)(unaff_EBP + 9) = cVar12;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if ('\0' < cVar7) {
    iVar8 = (int)cVar7;
    iVar13 = *(int *)(iVar6 + 0x10) + -1;
    if (((iVar8 < iVar13) && ('\0' < cVar12)) && (iVar8 = (int)cVar12, iVar8 < iVar13)) {
      psVar9 = (short *)FUN_00435bca(unaff_EBP + 8);
      sVar2 = *psVar9;
      iVar8 = CONCAT22((short)((uint)psVar9 >> 0x10),sVar2);
      *(int *)(unaff_EBP + 0xc) = iVar8;
      if (sVar2 == -5) {
        uVar10 = FUN_00479737(unaff_EBP + -0x38,unaff_EBP + 8);
        cVar7 = *(char *)(unaff_EBP + 8);
        uVar11 = (undefined3)((uint)uVar10 >> 8);
        iVar8 = CONCAT31(uVar11,cVar7);
        cVar12 = *(char *)(unaff_EBP + 9);
        if (((byte)*(undefined4 *)(unaff_EBP + -0x38) & 0x10) == 0x10) {
          if ((int)(puVar4[1] & 0xf) < (int)(0x10 - (*puVar4 & 0xf))) {
            cVar7 = cVar7 + -1;
LAB_00433d43:
            iVar8 = CONCAT31(uVar11,cVar7);
            cVar12 = *(char *)(unaff_EBP + 9) + -1;
          }
          else {
            cVar7 = cVar7 + '\x01';
LAB_00433d1c:
            iVar8 = CONCAT31(uVar11,cVar7);
            cVar12 = *(char *)(unaff_EBP + 9) + '\x01';
          }
        }
        else if (((byte)*(undefined4 *)(unaff_EBP + -0x38) & 0x20) == 0x20) {
          if (((byte)puVar4[1] & 0xf) < ((byte)*puVar4 & 0xf)) {
            cVar7 = cVar7 + -1;
            goto LAB_00433d1c;
          }
          cVar7 = cVar7 + '\x01';
          goto LAB_00433d43;
        }
        cVar7 = (char)iVar8;
        if ('\0' < cVar7) {
          iVar13 = *(int *)(iVar6 + 0x10) + -1;
          if ((cVar7 < iVar13) && ('\0' < *(char *)(unaff_EBP + 9))) {
            cVar1 = *(char *)(unaff_EBP + 9);
            if (cVar1 < iVar13) {
              iVar8 = *(int *)(*(int *)(iVar6 + 0x28 + *(char *)(unaff_EBP + 10) * 4) + 0xc);
              sVar2 = *(short *)(*(int *)(iVar8 + cVar7 * 4) + cVar1 * 2);
              *(uint *)(unaff_EBP + 0xc) = CONCAT22(cVar1 >> 7,sVar2);
              if (((sVar2 == -5) && ('\0' < *(char *)(unaff_EBP + 8))) &&
                 ((*(char *)(unaff_EBP + 8) < iVar13 && (('\0' < cVar12 && (cVar12 < iVar13)))))) {
                iVar6 = *(int *)(iVar8 + *(char *)(unaff_EBP + 8) * 4);
                uVar3 = *(undefined2 *)(iVar6 + cVar12 * 2);
                iVar8 = CONCAT22((short)((uint)iVar6 >> 0x10),uVar3);
                *(undefined2 *)(unaff_EBP + 0xc) = uVar3;
              }
            }
          }
        }
      }
      uVar10 = CONCAT22((short)((uint)iVar8 >> 0x10),*(undefined2 *)(unaff_EBP + 0xc));
      goto LAB_00433dac;
    }
  }
  uVar10 = CONCAT22((short)((uint)iVar8 >> 0x10),0xfffb);
LAB_00433dac:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar10;
}

