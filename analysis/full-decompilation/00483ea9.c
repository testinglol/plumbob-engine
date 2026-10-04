
void FUN_00483ea9(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar3 = *(int *)(unaff_EBP + 0x14);
  if (iVar3 != 0) {
    if (iVar3 == 2) {
      uVar2 = __ftol();
      *(float *)(unaff_EBP + 0xc) = -*(float *)(unaff_EBP + 0x10);
      *(undefined4 *)(unaff_EBP + 0x14) = uVar2;
    }
    else if (iVar3 == 4) {
      *(float *)(unaff_EBP + 0xc) = -*(float *)(unaff_EBP + 0xc);
    }
    else if (iVar3 == 6) {
      iVar3 = __ftol();
      uVar2 = *(undefined4 *)(unaff_EBP + 0x10);
      *(int *)(unaff_EBP + 0x10) = -iVar3;
      *(undefined4 *)(unaff_EBP + 0xc) = uVar2;
    }
    else {
      FUN_004550b0(unaff_EBP + -0x70,*(undefined4 *)(unaff_EBP + 0x14));
      *(undefined4 *)(unaff_EBP + -4) = 0;
      *(undefined4 *)(unaff_EBP + 0x14) = 0;
      FUN_00454f0c(unaff_EBP + -0x20,unaff_EBP + 0xc,unaff_EBP + 0x10,unaff_EBP + 0x14);
      puVar1 = (undefined4 *)FUN_005c3840(unaff_EBP + -0x2c,unaff_EBP + -0x20,unaff_EBP + -0x70);
      *(undefined4 *)(unaff_EBP + -0x20) = *puVar1;
      *(undefined4 *)(unaff_EBP + -0x1c) = puVar1[1];
      *(undefined4 *)(unaff_EBP + -0x18) = puVar1[2];
      FUN_00454ff9(unaff_EBP + -0x14,unaff_EBP + -0x20);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(float *)(unaff_EBP + 0xc) = (float)*(int *)(unaff_EBP + -0x10);
      *(float *)(unaff_EBP + 0x10) = (float)*(int *)(unaff_EBP + -0x14);
      FUN_005c4890();
    }
  }
  *(float *)(unaff_EBP + 0xc) =
       (float)*(int *)(*(int *)(unaff_EBP + 8) + 4) + *(float *)(unaff_EBP + 0xc);
  uVar2 = __ftol();
  puVar1 = *(undefined4 **)(unaff_EBP + 0x18);
  puVar1[1] = uVar2;
  uVar2 = __ftol();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *puVar1 = uVar2;
  return;
}

