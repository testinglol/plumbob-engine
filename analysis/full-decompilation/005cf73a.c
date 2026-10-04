
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_005cf73a(void)

{
  float fVar1;
  undefined4 uVar2;
  int *piVar3;
  uint uVar4;
  int unaff_EBP;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  FUN_00634c24();
  iVar5 = *(int *)(unaff_EBP + 8);
  uVar2 = FUN_0049b9e6(unaff_EBP + -0xd0,iVar5 + 0xe8,iVar5 + 300);
  uVar4 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0049b9e6(unaff_EBP + -0x8c,uVar2,iVar5 + 0x170);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005c4890();
  iVar5 = 0;
  uVar6 = 0x3f000;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005c7260(unaff_EBP + -0x38);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  piVar3 = (int *)FUN_0059a42e(unaff_EBP + -0x2c);
  if ((int *)(unaff_EBP + -0x24) == piVar3) goto LAB_005cf7d4;
  iVar5 = *piVar3;
  uVar4 = piVar3[1];
  *(int *)(unaff_EBP + -0x24) = iVar5;
  while( true ) {
    *(uint *)(unaff_EBP + -0x20) = uVar4;
LAB_005cf7d4:
    if (uVar4 == *(uint *)(unaff_EBP + -0x34)) break;
    uVar2 = *(undefined4 *)(iVar5 + (uVar4 & 1) * 0xc);
    *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(iVar5 + 4 + (uVar4 >> 1 & 1) * 0xc);
    *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(iVar5 + 8 + (uVar4 >> 2 & 1) * 0xc);
    *(undefined4 *)(unaff_EBP + -0x48) = uVar2;
    *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(unaff_EBP + -0x2c);
    *(undefined4 *)(unaff_EBP + -0x40) = *(undefined4 *)(unaff_EBP + -0x28);
    *(undefined4 *)(unaff_EBP + -0x3c) = 0x3f800000;
    FUN_005c37a0(unaff_EBP + -0x1c,unaff_EBP + -0x48,unaff_EBP + -0x8c);
    if (*(float *)(unaff_EBP + -0x10) <= (float)_DAT_006669e8) {
      uVar7 = uVar6 & 0xfffdffff;
      if (_DAT_0067343c < ABS(*(float *)(unaff_EBP + -0x10))) {
        fVar1 = 1.0 / -*(float *)(unaff_EBP + -0x10);
        *(float *)(unaff_EBP + -0x1c) = fVar1 * *(float *)(unaff_EBP + -0x1c);
        *(float *)(unaff_EBP + -0x18) = *(float *)(unaff_EBP + -0x18) * fVar1;
        *(float *)(unaff_EBP + -0x14) = *(float *)(unaff_EBP + -0x14) * fVar1;
        *(float *)(unaff_EBP + -0x10) = *(float *)(unaff_EBP + -0x10) * fVar1;
      }
      if ((float)_DAT_00671740 <= *(float *)(unaff_EBP + -0x1c)) {
        uVar7 = uVar6 & 0xfffdefff;
      }
      if (*(float *)(unaff_EBP + -0x1c) <= (float)_DAT_00667280) {
        uVar7 = uVar7 & 0xffffdfff;
      }
      if (*(float *)(unaff_EBP + -0x18) <= (float)_DAT_00667280) {
        uVar7 = uVar7 & 0xffffbfff;
      }
      uVar6 = uVar7 | 0x10;
      if ((float)_DAT_00671740 <= *(float *)(unaff_EBP + -0x18)) {
        uVar6 = uVar7 & 0xffff7fff | 0x10;
      }
    }
    else {
      fVar1 = 1.0 / *(float *)(unaff_EBP + -0x10);
      *(float *)(unaff_EBP + -0x1c) = *(float *)(unaff_EBP + -0x1c) * fVar1;
      *(float *)(unaff_EBP + -0x18) = *(float *)(unaff_EBP + -0x18) * fVar1;
      *(float *)(unaff_EBP + -0x14) = *(float *)(unaff_EBP + -0x14) * fVar1;
      *(float *)(unaff_EBP + -0x10) = *(float *)(unaff_EBP + -0x10) * fVar1;
      if ((float)_DAT_00671740 <= *(float *)(unaff_EBP + -0x1c)) {
        uVar6 = uVar6 & 0xffffefff;
      }
      else {
        uVar6 = uVar6 | 1;
      }
      if ((double)*(float *)(unaff_EBP + -0x1c) <= _DAT_00667280) {
        uVar6 = uVar6 & 0xffffdfff;
      }
      else {
        uVar6 = uVar6 | 2;
      }
      if ((double)*(float *)(unaff_EBP + -0x18) <= _DAT_00667280) {
        uVar6 = uVar6 & 0xffffbfff;
      }
      else {
        uVar6 = uVar6 | 4;
      }
      if (_DAT_00671740 <= (double)*(float *)(unaff_EBP + -0x18)) {
        uVar6 = uVar6 & 0xffff7fff;
      }
      else {
        uVar6 = uVar6 | 8;
      }
      if (_DAT_006669e8 <= (double)*(float *)(unaff_EBP + -0x14)) {
        uVar6 = uVar6 & 0xfffeffff;
      }
      else {
        uVar6 = uVar6 | 0x10;
      }
      if ((double)*(float *)(unaff_EBP + -0x14) <= _DAT_00667280) {
        uVar6 = uVar6 & 0xfffdffff;
      }
      else {
        uVar6 = uVar6 | 0x20;
      }
    }
    uVar4 = uVar4 + 1;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005c4890();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar6;
}

