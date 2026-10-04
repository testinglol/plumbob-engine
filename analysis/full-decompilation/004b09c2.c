
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004b09c2(void)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  int *piVar4;
  char cVar5;
  int extraout_ECX;
  int iVar6;
  int unaff_EBP;
  int iVar7;
  float10 fVar8;
  float10 fVar9;
  undefined4 uVar10;
  
  FUN_00634c24();
  iVar1 = *(int *)(unaff_EBP + 8);
  iVar6 = extraout_ECX + DAT_006f0088 * -0xc;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  piVar4 = (int *)FUN_00454ff9(unaff_EBP + -0x18,iVar1);
  *(undefined1 *)(unaff_EBP + 10) = 1;
  iVar7 = *piVar4;
  cVar5 = (char)(piVar4[1] >> 4);
  *(char *)(unaff_EBP + 8) = cVar5;
  cVar3 = (char)(iVar7 >> 4);
  *(char *)(unaff_EBP + 9) = cVar3;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if ('\0' < cVar5) {
    iVar7 = *(int *)(DAT_006e54dc + 0x10) + -1;
    if (((cVar5 < iVar7) && ('\0' < cVar3)) && (cVar3 < iVar7)) {
      uVar2 = *(uint *)(*(int *)(*(int *)(*(int *)(DAT_006e54dc + 0x14) + 0xc) + cVar5 * 4) +
                       cVar3 * 4);
      *(uint *)(unaff_EBP + -0x10) = uVar2;
      *(uint *)(unaff_EBP + -0x10) =
           (uint)*(byte *)(unaff_EBP + -0xd) + (uint)*(byte *)(unaff_EBP + -0xe) +
           (uVar2 >> 8 & 0xff) + (uVar2 & 0xff);
      *(float *)(unaff_EBP + -0x10) = (float)*(int *)(unaff_EBP + -0x10) * _DAT_00666a48;
      fVar8 = (float10)FUN_00454f69(unaff_EBP + -0x10);
      fVar8 = fVar8 * (float10)_DAT_00668728;
      goto LAB_004b0a7c;
    }
  }
  fVar8 = (float10)*(float *)(unaff_EBP + -0x10);
LAB_004b0a7c:
  fVar8 = (float10)*(float *)(iVar1 + 4) - fVar8;
  fVar9 = (float10)*(float *)(iVar6 + 0x174);
  if (fVar8 < fVar9 + fVar9) {
    if (fVar8 < (float10)*(float *)(iVar6 + 0x174)) {
      uVar10 = 1;
    }
    else {
      uVar10 = 2;
    }
  }
  else {
    uVar10 = 3;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar10;
}

