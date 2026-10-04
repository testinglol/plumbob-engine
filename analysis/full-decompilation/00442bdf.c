
void FUN_00442bdf(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x9c) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(*(int *)(unaff_EBP + -0x9c) + 0x30);
  while (*(int *)(unaff_EBP + -0x20) != 0) {
    *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(*(int *)(unaff_EBP + -0x20) + 0x118);
    if (*(short *)(*(int *)(unaff_EBP + -0x28) + 0x54) != 0) {
      FUN_0044845a(unaff_EBP + -0x20);
    }
    *(undefined4 *)(unaff_EBP + -0x3c) = *(undefined4 *)(*(int *)(unaff_EBP + -0x20) + 0xe0);
    *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x3c);
  }
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  while( true ) {
    uVar2 = FUN_0043ad1f(*(undefined4 *)(unaff_EBP + -0x10));
    *(undefined4 *)(unaff_EBP + -0x24) = uVar2;
    if (*(int *)(unaff_EBP + -0x24) == 0) {
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(unaff_EBP + -0x80) = *(undefined4 *)(unaff_EBP + -0x1c);
      while (*(int *)(unaff_EBP + -0x80) != *(int *)(unaff_EBP + -0x18)) {
        *(int *)(unaff_EBP + -0x80) = *(int *)(unaff_EBP + -0x80) + 4;
      }
      FUN_00448934();
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return;
    }
    *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(*(int *)(unaff_EBP + -0x24) + 0x60);
    if ((*(short *)(*(int *)(unaff_EBP + -0x48) + 0x12) == 7) ||
       (*(undefined4 *)(unaff_EBP + -0x4c) = *(undefined4 *)(*(int *)(unaff_EBP + -0x24) + 0x60),
       *(short *)(*(int *)(unaff_EBP + -0x4c) + 0x12) == 0xc)) break;
LAB_00442c56:
    *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
  }
  *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(*(int *)(unaff_EBP + -0x24) + 0x60);
LAB_00442cb0:
  if (*(short *)(*(int *)(unaff_EBP + -0x2c) + 0x54) != 0) {
    *(undefined2 *)(unaff_EBP + -0x30) = 0;
    *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(unaff_EBP + -0x1c);
    do {
      *(undefined4 *)(unaff_EBP + -0x50) = *(undefined4 *)(unaff_EBP + -0x18);
      if (*(int *)(unaff_EBP + -0x34) == *(int *)(unaff_EBP + -0x50)) {
        if (*(short *)(unaff_EBP + -0x30) == 0) {
          uVar1 = FUN_00440b6d(*(undefined4 *)(unaff_EBP + -0x24));
          *(undefined2 *)(unaff_EBP + -0x30) = uVar1;
        }
        iVar3 = FUN_0045741b();
        if (iVar3 == 0x3eec206c) {
          *(undefined2 *)(*(int *)(unaff_EBP + -0x9c) + 0x80) = *(undefined2 *)(unaff_EBP + -0x30);
        }
        break;
      }
      *(undefined4 *)(unaff_EBP + -0x54) = *(undefined4 *)(**(int **)(unaff_EBP + -0x34) + 0x11c);
      if (*(int *)(unaff_EBP + -0x54) == *(int *)(unaff_EBP + -0x24)) {
        if (*(short *)(unaff_EBP + -0x30) != 0) goto code_r0x00442d01;
        *(undefined2 *)(unaff_EBP + -0x30) = *(undefined2 *)(**(int **)(unaff_EBP + -0x34) + 0xf0);
      }
      *(int *)(unaff_EBP + -0x34) = *(int *)(unaff_EBP + -0x34) + 4;
    } while( true );
  }
  goto LAB_00442c56;
code_r0x00442d01:
  *(undefined2 *)(unaff_EBP + -0x58) = *(undefined2 *)(**(int **)(unaff_EBP + -0x34) + 0xf0);
  FUN_0044127f(*(undefined4 *)(unaff_EBP + -0x58));
  FUN_004486a3(*(undefined4 *)(unaff_EBP + -0x34));
  goto LAB_00442cb0;
}

