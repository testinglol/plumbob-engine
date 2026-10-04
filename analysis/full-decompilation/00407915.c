
void FUN_00407915(void)

{
  int *piVar1;
  int *piVar2;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_00464973(unaff_EBP + -0x12,1);
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  if (0 < *(short *)(unaff_EBP + -0x12)) {
    do {
      *(undefined4 *)(unaff_EBP + -0x40) = 0;
      *(undefined4 *)(unaff_EBP + -0x3c) = 0;
      *(undefined4 *)(unaff_EBP + -0x38) = 0;
      *(undefined4 *)(unaff_EBP + -0x34) = 0;
      *(undefined4 *)(unaff_EBP + -0x30) = 0;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_00407bdf(unaff_EBP + -0x40);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_00407c07();
      piVar1 = (int *)(*extraout_ECX + -0x14 + ((extraout_ECX[1] - *extraout_ECX) / 0x14) * 0x14);
      FUN_00464973(unaff_EBP + -0x10,1);
      FUN_00464895(unaff_EBP + -0xd,1);
      FUN_00464895(unaff_EBP + -0xe,1);
      piVar1[3] = (int)*(char *)(unaff_EBP + -0xd);
      *(undefined4 *)(unaff_EBP + -0x24) = 0;
      piVar1[4] = (int)*(char *)(unaff_EBP + -0xe);
      if (0 < *(short *)(unaff_EBP + -0x10)) {
        do {
          *(undefined4 *)(unaff_EBP + -0x2c) = 0;
          FUN_00464973(unaff_EBP + -0x14,1);
          FUN_00464973(unaff_EBP + -0x16,1);
          FUN_00464973(unaff_EBP + -0x18,1);
          FUN_00464973(unaff_EBP + -0x1e,1);
          FUN_00464973(unaff_EBP + -0x1a,1);
          FUN_00464973(unaff_EBP + -0x1c,1);
          if (20000 < *(int *)(unaff_EBP + 0xc)) {
            FUN_00464b48(unaff_EBP + -0x2c,1);
          }
          if (*(short *)(unaff_EBP + -0x14) == -3) {
            *(undefined4 *)(unaff_EBP + -0x50) = 0;
            *(undefined4 *)(unaff_EBP + -0x60) = 0;
            *(undefined4 *)(unaff_EBP + -0x4c) = 0;
            *(undefined4 *)(unaff_EBP + -0x5c) = 0;
            *(undefined4 *)(unaff_EBP + -0x58) = 0;
            *(undefined4 *)(unaff_EBP + -0x48) = 0;
            *(undefined4 *)(unaff_EBP + -0x54) = 0;
            *(undefined4 *)(unaff_EBP + -0x44) = 0;
            FUN_00407baf(unaff_EBP + -0x60);
            piVar2 = (int *)((piVar1[1] - *piVar1 >> 5) * 0x20 + -0x20 + *piVar1);
            *piVar2 = (int)*(short *)(unaff_EBP + -0x16);
            piVar2[1] = (int)*(short *)(unaff_EBP + -0x18);
            piVar2[2] = (int)*(short *)(unaff_EBP + -0x1a);
            piVar2[3] = (int)*(short *)(unaff_EBP + -0x1c);
            piVar2[4] = *(int *)(unaff_EBP + -0x2c);
            piVar2[7] = (int)*(short *)(unaff_EBP + -0x1e);
          }
          *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + 1;
        } while (*(int *)(unaff_EBP + -0x24) < (int)*(short *)(unaff_EBP + -0x10));
      }
      *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + 1;
    } while (*(int *)(unaff_EBP + -0x28) < (int)*(short *)(unaff_EBP + -0x12));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

