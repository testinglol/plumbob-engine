
void FUN_004a9fd7(void)

{
  char cVar1;
  undefined4 uVar2;
  short sVar3;
  uint uVar4;
  undefined4 *puVar5;
  byte bVar6;
  undefined4 extraout_ECX;
  int iVar7;
  int iVar8;
  char cVar9;
  uint uVar10;
  int unaff_EBP;
  undefined4 local_20;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = extraout_ECX;
  iVar7 = (int)*(uint *)(unaff_EBP + 0x10) >> 4;
  uVar2 = *(undefined4 *)(unaff_EBP + 0x18);
  local_20 = *(undefined4 *)(unaff_EBP + 0x1c);
  uVar4 = *(uint *)(unaff_EBP + 0x10) & 0xf;
  iVar8 = (int)(short)((int)*(uint *)(unaff_EBP + 0xc) >> 4);
  *(uint *)(unaff_EBP + 0x10) = *(uint *)(unaff_EBP + 0xc) & 0xf;
  *(int *)(unaff_EBP + -0x18) = iVar8;
  puVar5 = (undefined4 *)
           FUN_004a9e60(unaff_EBP + 0x18,(int)(short)iVar7,iVar8,*(undefined4 *)(unaff_EBP + 0x14),
                        uVar2);
  *(undefined4 *)(unaff_EBP + 0x18) = *puVar5;
  if (*(byte **)(unaff_EBP + 0x1c) == (byte *)0x0) {
    cVar9 = (char)iVar7;
    *(char *)(unaff_EBP + 0x1c) = cVar9;
    *(undefined1 *)(unaff_EBP + 0x1d) = *(undefined1 *)(unaff_EBP + -0x18);
    *(undefined1 *)(unaff_EBP + 0x1e) = *(undefined1 *)(unaff_EBP + 0x14);
    iVar7 = DAT_006e54d8;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (((((int)cVar9 < *(int *)(iVar7 + 0x70) + 1) || (*(int *)(iVar7 + 0x74) + -1 < (int)cVar9))
        || (cVar1 = *(char *)(unaff_EBP + -0x18), (int)cVar1 < *(int *)(iVar7 + 0x78) + 1)) ||
       (*(int *)(iVar7 + 0x7c) + -1 < (int)cVar1)) {
      bVar6 = 0;
      *(undefined1 *)(unaff_EBP + 0x16) = 0;
      *(undefined1 *)(unaff_EBP + 0x14) = 0;
      *(undefined1 *)(unaff_EBP + 0x17) = 0;
    }
    else {
      *(undefined4 **)(unaff_EBP + -0x14) = &local_20;
      local_20._3_1_ = (char)cVar1 >> 7;
      local_20._0_3_ =
           CONCAT12(*(undefined1 *)(unaff_EBP + 0x14),
                    CONCAT11(*(undefined1 *)(unaff_EBP + -0x18),cVar9));
      puVar5 = (undefined4 *)FUN_004796d9(unaff_EBP + -0x14);
      *(undefined4 *)(unaff_EBP + 0x14) = *puVar5;
      bVar6 = *(byte *)(unaff_EBP + 0x15);
    }
  }
  else {
    bVar6 = **(byte **)(unaff_EBP + 0x1c);
    *(byte *)(unaff_EBP + 0x17) = bVar6;
    *(byte *)(unaff_EBP + 0x16) = bVar6;
    *(byte *)(unaff_EBP + 0x14) = bVar6;
  }
  cVar9 = (char)uVar2;
  if (uVar4 == *(uint *)(unaff_EBP + 0x10)) {
    *(short *)(unaff_EBP + 0x18) =
         *(short *)(unaff_EBP + 0x18) +
         (short)((int)((((uint)bVar6 - (uint)*(byte *)(unaff_EBP + 0x17)) + 4 << (cVar9 + 1U & 0x1f)
                       ) * uVar4) / 0x10);
  }
  else {
    uVar10 = (uint)bVar6;
    bVar6 = cVar9 + 1;
    if ((int)*(uint *)(unaff_EBP + 0x10) < (int)uVar4) {
      *(int *)(unaff_EBP + 0x1c) =
           (int)(((uVar10 - *(byte *)(unaff_EBP + 0x16)) + 2 << (bVar6 & 0x1f)) * uVar4) / 0x10;
      iVar7 = (int)(*(int *)(*(int *)(unaff_EBP + -0x10) + 0x5c) * uVar4) / 0x10;
      *(short *)(unaff_EBP + 0x18) =
           *(short *)(unaff_EBP + 0x18) +
           (short)((((int)(((uVar10 - *(byte *)(unaff_EBP + 0x17)) + 4 << (bVar6 & 0x1f)) * uVar4) /
                     0x10 - *(int *)(unaff_EBP + 0x1c)) * *(int *)(unaff_EBP + 0x10)) / (int)uVar4)
           + (short)*(undefined4 *)(unaff_EBP + 0x1c);
      sVar3 = (short)((iVar7 * *(int *)(unaff_EBP + 0x10)) / (int)uVar4);
    }
    else {
      *(int *)(unaff_EBP + 0x1c) =
           (int)(((uVar10 - *(byte *)(unaff_EBP + 0x14)) + 2 << (bVar6 & 0x1f)) *
                *(int *)(unaff_EBP + 0x10)) / 0x10;
      iVar7 = (*(int *)(*(int *)(unaff_EBP + -0x10) + 0x5c) * *(int *)(unaff_EBP + 0x10)) / -0x10;
      *(short *)(unaff_EBP + 0x18) =
           *(short *)(unaff_EBP + 0x18) +
           (short)((int)(((int)(((uVar10 - *(byte *)(unaff_EBP + 0x17)) + 4 << (bVar6 & 0x1f)) *
                               *(int *)(unaff_EBP + 0x10)) / 0x10 - *(int *)(unaff_EBP + 0x1c)) *
                        uVar4) / *(int *)(unaff_EBP + 0x10)) +
           (short)*(undefined4 *)(unaff_EBP + 0x1c);
      sVar3 = (short)((int)(iVar7 * uVar4) / *(int *)(unaff_EBP + 0x10));
    }
    *(short *)(unaff_EBP + 0x1a) = *(short *)(unaff_EBP + 0x1a) + ((short)iVar7 - sVar3);
  }
  **(undefined4 **)(unaff_EBP + 8) = *(undefined4 *)(unaff_EBP + 0x18);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

