
undefined4 FUN_0050b094(void)

{
  char cVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar1 = (**(code **)(*extraout_ECX + 200))();
  if (cVar1 == '\0') {
    uVar2 = FUN_005e8d11();
    if ((char)uVar2 != '\0') {
      (**(code **)(*extraout_ECX + 0x174))(0,0);
      FUN_005a5631(0xbc0,extraout_ECX + 0x45,4);
      piVar3 = (int *)FUN_005e7743();
      iVar4 = *piVar3;
      uVar2 = FUN_005e50fa(3);
      iVar4 = (**(code **)(iVar4 + 0x24))(0,uVar2);
      extraout_ECX[0x51] = iVar4;
      if (iVar4 != 0) {
        (**(code **)(*extraout_ECX + 0x20))(iVar4);
        iVar4 = extraout_ECX[0x51];
        FUN_004cb21d((((extraout_ECX[0x21] - *(int *)(iVar4 + 0x84)) - extraout_ECX[0x1f]) +
                     *(int *)(iVar4 + 0x7c)) / 2,
                     ((*(int *)(iVar4 + 0x80) - *(int *)(iVar4 + 0x88)) - extraout_ECX[0x20]) +
                     -0x14 + extraout_ECX[0x22]);
      }
      extraout_ECX[0x46] = 0x10;
      extraout_ECX[0x47] = 100;
      extraout_ECX[0x48] = (extraout_ECX[0x21] - extraout_ECX[0x1f]) + -0x10;
      extraout_ECX[0x49] = 0x8c;
      extraout_ECX[0x4a] = 0x10;
      extraout_ECX[0x4b] = (extraout_ECX[0x22] - extraout_ECX[0x20]) + -200;
      extraout_ECX[0x4c] = (extraout_ECX[0x21] - extraout_ECX[0x1f]) + -0x10;
      extraout_ECX[0x4d] = (extraout_ECX[0x22] - extraout_ECX[0x20]) + -0xa0;
      extraout_ECX[0x52] = DAT_006fe838;
      DAT_006f35fc = DAT_006f2aac;
      iVar4 = DAT_006e5490 + 1000;
      DAT_006fe838 = 0;
      extraout_ECX[0x54] = iVar4;
      *(int *)(unaff_EBP + -0x10) = iVar4;
      if ((*(byte *)(DAT_006e486c + 0x66) & 0x80) != 0) {
        FUN_0046fca5();
        *(undefined ***)(unaff_EBP + -0x7c) = &PTR_FUN_0066643c;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        cVar1 = FUN_004fff98(0xab,s_Credits_006cc70c,unaff_EBP + -0x7c,0);
        if (cVar1 != '\0') {
          FUN_0050b4f9(unaff_EBP + -0x10,unaff_EBP + -0x7c);
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_00470467();
      }
      if ((*(byte *)(DAT_006e486c + 0x66) & 0x40) != 0) {
        FUN_0046fca5();
        *(undefined ***)(unaff_EBP + -0x7c) = &PTR_FUN_0066643c;
        *(undefined4 *)(unaff_EBP + -4) = 1;
        cVar1 = FUN_004fff98(0xaa,s_Credits_006cc70c,unaff_EBP + -0x7c,0);
        if (cVar1 != '\0') {
          FUN_0050b4f9(unaff_EBP + -0x10,unaff_EBP + -0x7c);
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_00470467();
      }
      if ((*(byte *)(DAT_006e486c + 0x66) & 0x20) != 0) {
        FUN_0046fca5();
        *(undefined ***)(unaff_EBP + -0x7c) = &PTR_FUN_0066643c;
        *(undefined4 *)(unaff_EBP + -4) = 2;
        cVar1 = FUN_004fff98(0xa9,s_Credits_006cc70c,unaff_EBP + -0x7c,0);
        if (cVar1 != '\0') {
          FUN_0050b4f9(unaff_EBP + -0x10,unaff_EBP + -0x7c);
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_00470467();
      }
      if ((*(byte *)(DAT_006e486c + 0x66) & 8) != 0) {
        FUN_0046fca5();
        *(undefined ***)(unaff_EBP + -0x7c) = &PTR_FUN_0066643c;
        *(undefined4 *)(unaff_EBP + -4) = 3;
        cVar1 = FUN_004fff98(0xa7,s_Credits_006cc70c,unaff_EBP + -0x7c,0);
        if (cVar1 != '\0') {
          FUN_0050b4f9(unaff_EBP + -0x10,unaff_EBP + -0x7c);
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_00470467();
      }
      if ((*(byte *)(DAT_006e486c + 0x66) & 4) != 0) {
        FUN_0046fca5();
        *(undefined ***)(unaff_EBP + -0x7c) = &PTR_FUN_0066643c;
        *(undefined4 *)(unaff_EBP + -4) = 4;
        cVar1 = FUN_004fff98(0xa6,s_Credits_006cc70c,unaff_EBP + -0x7c,0);
        if (cVar1 != '\0') {
          FUN_0050b4f9(unaff_EBP + -0x10,unaff_EBP + -0x7c);
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_00470467();
      }
      if ((*(byte *)(DAT_006e486c + 0x66) & 2) != 0) {
        FUN_0046fca5();
        *(undefined ***)(unaff_EBP + -0x7c) = &PTR_FUN_0066643c;
        *(undefined4 *)(unaff_EBP + -4) = 5;
        cVar1 = FUN_004fff98(0xa5,s_Credits_006cc70c,unaff_EBP + -0x7c,0);
        if (cVar1 != '\0') {
          FUN_0050b4f9(unaff_EBP + -0x10,unaff_EBP + -0x7c);
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_00470467();
      }
      if ((*(byte *)(DAT_006e486c + 0x66) & 0x10) == 0) {
        if ((*(byte *)(DAT_006e486c + 0x66) & 1) != 0) {
          FUN_0046fca5();
          *(undefined ***)(unaff_EBP + -0xe8) = &PTR_FUN_0066643c;
          *(undefined4 *)(unaff_EBP + -4) = 7;
          cVar1 = FUN_004fff98(0xa4,s_Credits_006cc70c,unaff_EBP + -0xe8,0);
          if (cVar1 != '\0') {
            FUN_0050b4f9(unaff_EBP + -0x10,unaff_EBP + -0xe8);
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_00470467();
        }
        FUN_0046fca5();
        *(undefined ***)(unaff_EBP + -0x154) = &PTR_FUN_0066643c;
        *(undefined4 *)(unaff_EBP + -4) = 8;
        cVar1 = FUN_004fff98(0xa3,s_Credits_006cc70c,unaff_EBP + -0x154,0);
        if (cVar1 != '\0') {
          FUN_0050b4f9(unaff_EBP + -0x10,unaff_EBP + -0x154);
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      }
      else {
        FUN_0046fca5();
        *(undefined ***)(unaff_EBP + -0x7c) = &PTR_FUN_0066643c;
        *(undefined4 *)(unaff_EBP + -4) = 6;
        cVar1 = FUN_004fff98(0xa8,s_Credits_006cc70c,unaff_EBP + -0x7c,0);
        if (cVar1 != '\0') {
          FUN_0050b4f9(unaff_EBP + -0x10,unaff_EBP + -0x7c);
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      }
      FUN_00470467();
      iVar4 = 0;
      if ((DAT_006e486c != 0) && (iVar4 = *(int *)(DAT_006e486c + 0x2c), iVar4 != 0)) {
        *(undefined4 *)(iVar4 + 0x60) = 100;
      }
      uVar2 = CONCAT31((int3)((uint)iVar4 >> 8),1);
    }
  }
  else {
    uVar2 = FUN_005e8d11();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

