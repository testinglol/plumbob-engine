
void FUN_00448eb2(void)

{
  undefined4 uVar1;
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffff14;
  *(undefined4 *)(unaff_EBP + -0xd8) = extraout_ECX;
  if (*(int *)(unaff_EBP + 0xc) != 0) {
    if ((uint)(*(int *)(*(int *)(unaff_EBP + -0xd8) + 8) - *(int *)(*(int *)(unaff_EBP + -0xd8) + 4)
              >> 2) < *(uint *)(unaff_EBP + 0xc)) {
      *(undefined4 *)(unaff_EBP + -0x7c) = *(undefined4 *)(*(int *)(unaff_EBP + -0xd8) + 4);
      *(undefined4 *)(unaff_EBP + -0x80) = **(undefined4 **)(unaff_EBP + -0xd8);
      *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x7c) - *(int *)(unaff_EBP + -0x80) >> 2;
      if (*(uint *)(unaff_EBP + -0x28) < *(uint *)(unaff_EBP + 0xc)) {
        *(int *)(unaff_EBP + -0xdc) = unaff_EBP + 0xc;
      }
      else {
        *(int *)(unaff_EBP + -0xdc) = unaff_EBP + -0x28;
      }
      *(undefined4 *)(unaff_EBP + -0x84) = *(undefined4 *)(unaff_EBP + -0xdc);
      *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x28) + **(int **)(unaff_EBP + -0x84);
      if (*(int *)(unaff_EBP + -0x20) == 0) {
        *(undefined4 *)(unaff_EBP + -0xe0) = 0;
      }
      else {
        uVar1 = FUN_00401742(*(int *)(unaff_EBP + -0x20) << 2);
        *(undefined4 *)(unaff_EBP + -0xe0) = uVar1;
      }
      *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(unaff_EBP + -0xe0);
      *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x2c);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      *(undefined4 *)(unaff_EBP + -0x8c) = **(undefined4 **)(unaff_EBP + -0xd8);
      uVar1 = FUN_0044a3ec(*(undefined4 *)(unaff_EBP + -0x8c),*(undefined4 *)(unaff_EBP + 8),
                           *(undefined4 *)(unaff_EBP + -0x2c),*(undefined4 *)(unaff_EBP + -0x88));
      *(undefined4 *)(unaff_EBP + -0xe4) = uVar1;
      *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0xe4);
      *(undefined4 *)(unaff_EBP + -0x94) = *(undefined4 *)(unaff_EBP + 0xc);
      uVar1 = FUN_0044a482(*(undefined4 *)(unaff_EBP + -0x24),*(undefined4 *)(unaff_EBP + -0x94),
                           *(undefined4 *)(unaff_EBP + 0x10),*(undefined4 *)(unaff_EBP + -0x90));
      *(undefined4 *)(unaff_EBP + -0xe8) = uVar1;
      *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0xe8);
      *(undefined4 *)(unaff_EBP + -0x9c) = *(undefined4 *)(*(int *)(unaff_EBP + -0xd8) + 4);
      uVar1 = FUN_0044a3ec(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x9c),
                           *(undefined4 *)(unaff_EBP + -0x24),*(undefined4 *)(unaff_EBP + -0x98));
      *(undefined4 *)(unaff_EBP + -0xec) = uVar1;
      *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0xec);
      FUN_00449243();
      return;
    }
    *(undefined4 *)(unaff_EBP + -0x14) = **(undefined4 **)(unaff_EBP + 0x10);
    *(int *)(unaff_EBP + -0x1c) =
         *(int *)(*(int *)(unaff_EBP + -0xd8) + 4) - *(int *)(unaff_EBP + 8) >> 2;
    *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(*(int *)(unaff_EBP + -0xd8) + 4);
    if (*(uint *)(unaff_EBP + 0xc) < *(uint *)(unaff_EBP + -0x1c)) {
      *(undefined4 *)(unaff_EBP + -0x3c) = *(undefined4 *)(*(int *)(unaff_EBP + -0xd8) + 4);
      *(undefined4 *)(unaff_EBP + -0x38) = *(undefined4 *)(*(int *)(unaff_EBP + -0xd8) + 4);
      *(int *)(unaff_EBP + -0x34) =
           *(int *)(*(int *)(unaff_EBP + -0xd8) + 4) + *(int *)(unaff_EBP + 0xc) * -4;
      FUN_0044a3ec(*(undefined4 *)(unaff_EBP + -0x34),*(undefined4 *)(unaff_EBP + -0x38),
                   *(undefined4 *)(unaff_EBP + -0x3c),*(undefined4 *)(unaff_EBP + -0x30));
      *(int *)(*(int *)(unaff_EBP + -0xd8) + 4) =
           *(int *)(*(int *)(unaff_EBP + -0xd8) + 4) + *(int *)(unaff_EBP + 0xc) * 4;
      *(int *)(unaff_EBP + -0x58) = *(int *)(unaff_EBP + -0x18) + *(int *)(unaff_EBP + 0xc) * -4;
      *(undefined1 *)(unaff_EBP + -0x40) = *(undefined1 *)(unaff_EBP + -0x44);
      *(undefined1 *)(unaff_EBP + -0x54) = *(undefined1 *)(unaff_EBP + -0x40);
      *(undefined4 *)(unaff_EBP + -0x50) = *(undefined4 *)(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -0x4c) = *(undefined4 *)(unaff_EBP + -0x58);
      *(int *)(unaff_EBP + -0x48) = *(int *)(unaff_EBP + -0x4c) - *(int *)(unaff_EBP + 8) >> 2;
      while (0 < *(int *)(unaff_EBP + -0x48)) {
        *(int *)(unaff_EBP + -0x4c) = *(int *)(unaff_EBP + -0x4c) + -4;
        *(int *)(unaff_EBP + -0x50) = *(int *)(unaff_EBP + -0x50) + -4;
        **(undefined4 **)(unaff_EBP + -0x50) = **(undefined4 **)(unaff_EBP + -0x4c);
        *(int *)(unaff_EBP + -0x48) = *(int *)(unaff_EBP + -0x48) + -1;
      }
      *(int *)(unaff_EBP + -0x60) = *(int *)(unaff_EBP + 8) + *(int *)(unaff_EBP + 0xc) * 4;
      *(undefined4 *)(unaff_EBP + -0x5c) = *(undefined4 *)(unaff_EBP + 8);
      while (*(int *)(unaff_EBP + -0x5c) != *(int *)(unaff_EBP + -0x60)) {
        **(undefined4 **)(unaff_EBP + -0x5c) = *(undefined4 *)(unaff_EBP + -0x14);
        *(int *)(unaff_EBP + -0x5c) = *(int *)(unaff_EBP + -0x5c) + 4;
      }
    }
    else {
      *(int *)(unaff_EBP + -0x6c) = *(int *)(unaff_EBP + 0xc) - *(int *)(unaff_EBP + -0x1c);
      *(undefined4 *)(unaff_EBP + -0x68) = *(undefined4 *)(*(int *)(unaff_EBP + -0xd8) + 4);
      FUN_0044a482(*(undefined4 *)(unaff_EBP + -0x68),*(undefined4 *)(unaff_EBP + -0x6c),
                   unaff_EBP + -0x14,*(undefined4 *)(unaff_EBP + -100));
      *(int *)(*(int *)(unaff_EBP + -0xd8) + 4) =
           *(int *)(*(int *)(unaff_EBP + -0xd8) + 4) +
           (*(int *)(unaff_EBP + 0xc) - *(int *)(unaff_EBP + -0x1c)) * 4;
      *(undefined4 *)(unaff_EBP + -0x74) = *(undefined4 *)(*(int *)(unaff_EBP + -0xd8) + 4);
      FUN_0044a3ec(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x18),
                   *(undefined4 *)(unaff_EBP + -0x74),*(undefined4 *)(unaff_EBP + -0x70));
      *(int *)(*(int *)(unaff_EBP + -0xd8) + 4) =
           *(int *)(*(int *)(unaff_EBP + -0xd8) + 4) + *(int *)(unaff_EBP + -0x1c) * 4;
      *(undefined4 *)(unaff_EBP + -0x78) = *(undefined4 *)(unaff_EBP + 8);
      while (*(int *)(unaff_EBP + -0x78) != *(int *)(unaff_EBP + -0x18)) {
        **(undefined4 **)(unaff_EBP + -0x78) = *(undefined4 *)(unaff_EBP + -0x14);
        *(int *)(unaff_EBP + -0x78) = *(int *)(unaff_EBP + -0x78) + 4;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

