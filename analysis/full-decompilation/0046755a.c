
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0046755a(void)

{
  int iVar1;
  int *piVar2;
  float10 fVar3;
  float fVar4;
  short *psVar5;
  undefined4 *puVar6;
  int iVar7;
  int extraout_ECX;
  int iVar8;
  int iVar9;
  int unaff_EBP;
  undefined4 *puVar10;
  bool bVar11;
  float10 fVar12;
  undefined4 local_7c;
  
  FUN_00634c24();
  piVar2 = *(int **)(unaff_EBP + 8);
  *(char *)(unaff_EBP + 8) = (char)(piVar2[1] >> 4);
  *(char *)(unaff_EBP + 9) = (char)(*piVar2 >> 4);
  *(int *)(unaff_EBP + -0x18) = extraout_ECX;
  *(undefined1 *)(unaff_EBP + 10) = *(undefined1 *)(unaff_EBP + 0xc);
  iVar8 = DAT_006e54d8;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  local_7c = -*(int *)(iVar8 + 0x84) & 3;
  FUN_00434ffd();
  local_7c = unaff_EBP + 8;
  psVar5 = (short *)FUN_00435bca();
  if (*psVar5 == -5) {
    puVar6 = (undefined4 *)(unaff_EBP + -0x4c);
    for (iVar8 = 0xb; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    iVar8 = piVar2[1];
    *(undefined4 **)(unaff_EBP + -0x20) = &local_7c;
    local_7c = (uint)CONCAT12(*(undefined1 *)(unaff_EBP + 0xc),
                              CONCAT11((char)(*piVar2 >> 4),(char)(iVar8 >> 4)));
    *(undefined1 *)(unaff_EBP + -4) = 1;
    puVar6 = (undefined4 *)FUN_00467768(unaff_EBP + -0x78);
    local_7c = unaff_EBP + -0x20;
    puVar10 = (undefined4 *)(unaff_EBP + -0x4c);
    for (iVar8 = 0xb; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar10 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar10 = puVar10 + 1;
    }
    FUN_004672d0(unaff_EBP + 8,unaff_EBP + -0x14,unaff_EBP + -0x10,unaff_EBP + -0x1c);
    iVar8 = *(int *)(DAT_006e54d8 + 0x84);
    if (*(int *)(unaff_EBP + -0x1c) == 0) {
      iVar7 = 0;
    }
    else {
      iVar7 = ((*(int *)(unaff_EBP + -0x1c) - iVar8) - 1U & 3) + 1;
    }
    *(int *)(unaff_EBP + -0x1c) = iVar7;
    if (*(int *)(unaff_EBP + -0x20) == 0) {
      iVar8 = 0;
    }
    else {
      iVar8 = ((*(int *)(unaff_EBP + -0x20) - iVar8) - 1U & 3) + 1;
    }
    *(int *)(unaff_EBP + -0x20) = iVar8;
    fVar12 = (float10)_DAT_00666748;
    iVar8 = piVar2[1];
    iVar9 = *piVar2;
    *(int *)(unaff_EBP + 0xc) = iVar8;
    *(int *)(unaff_EBP + -0x18) = iVar9;
    iVar9 = iVar9 >> 4;
    iVar8 = iVar8 >> 4;
    if (((byte)*(undefined4 *)(unaff_EBP + -0x4c) & 0x10) == 0x10) {
      iVar1 = *(int *)(unaff_EBP + -0x18);
      *(int *)(unaff_EBP + -0x18) = iVar9;
      fVar3 = (float10)_DAT_00667278;
      iVar9 = *(int *)(unaff_EBP + 0xc);
      *(int *)(unaff_EBP + 0xc) = iVar8;
      if (fVar12 < ((float10)iVar9 * (float10)_DAT_00667278 - (float10)*(int *)(unaff_EBP + 0xc)) +
                   ((float10)iVar1 * fVar3 - (float10)*(int *)(unaff_EBP + -0x18))) {
        bVar11 = iVar7 == 2;
      }
      else {
        bVar11 = iVar7 == 4;
      }
    }
    else {
      iVar1 = *(int *)(unaff_EBP + 0xc);
      *(int *)(unaff_EBP + 0xc) = iVar8;
      fVar4 = (float)iVar1 * _DAT_00667278;
      iVar8 = *(int *)(unaff_EBP + 0xc);
      *(int *)(unaff_EBP + 0xc) = iVar9;
      if (_DAT_0066657c <
          (fVar4 - (float)iVar8) -
          ((float)*(int *)(unaff_EBP + -0x18) * _DAT_00667278 - (float)*(int *)(unaff_EBP + 0xc))) {
        bVar11 = iVar7 == 3;
      }
      else {
        bVar11 = iVar7 == 1;
      }
    }
    if ((bVar11) || (iVar8 = *(int *)(unaff_EBP + -0x10), iVar7 == 0)) {
      iVar8 = *(int *)(unaff_EBP + -0x14);
    }
    if (iVar8 != 0) {
      if ((*(char *)(iVar8 + 0x75) != '\0') ||
         ((((*(char *)(iVar8 + 0x73) != '\0' && (*(int *)(iVar8 + 0x280) == 0)) &&
           (0 < *(int *)(iVar8 + 0x284))) && (*(float *)(iVar8 + 0x6c) < DAT_00667638)))) {
        fVar12 = (float10)DAT_00667638;
      }
      else {
        fVar12 = (float10)*(float *)(iVar8 + 0x6c);
      }
    }
  }
  else {
    *(uint *)(unaff_EBP + 0xc) =
         (uint)*(byte *)(*(int *)(*(int *)(*(int *)(extraout_ECX + 0x40 +
                                                   *(int *)(unaff_EBP + 0xc) * 4) + 0xc) +
                                 *(char *)(unaff_EBP + 8) * 4) + (int)*(char *)(unaff_EBP + 9));
    fVar12 = (float10)*(int *)(unaff_EBP + 0xc) * (float10)_DAT_00667664;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return fVar12;
}

