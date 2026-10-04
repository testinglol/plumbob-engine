
bool FUN_0045d764(void)

{
  char cVar1;
  int iVar2;
  int extraout_ECX;
  uint uVar3;
  int unaff_EBP;
  bool bVar4;
  
  FUN_00634c24();
  if (*(int *)(unaff_EBP + 8) == *(int *)(extraout_ECX + 0xa84)) {
    *(undefined2 *)(extraout_ECX + 0x5ce) = 0;
    *(byte *)(extraout_ECX + 0xa89) = *(byte *)(extraout_ECX + 0xa89) | 1;
    cVar1 = FUN_0045d92c();
    if (cVar1 == '\0') {
      FUN_0041f010(extraout_ECX,extraout_ECX,0x21,0x32);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      iVar2 = FUN_0041f101();
      if (iVar2 != 0) {
        *(undefined4 *)(unaff_EBP + -0x44) = 0;
        FUN_0045d377(unaff_EBP + -0x50);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
    }
    bVar4 = true;
  }
  else {
    FUN_0045f887();
    iVar2 = *(int *)(extraout_ECX + 0xa44);
    uVar3 = 0;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    if (iVar2 != *(int *)(extraout_ECX + 0xa40)) {
      do {
        iVar2 = (*(int *)(extraout_ECX + 0xa40) + uVar3 & 7) * 0x44 + extraout_ECX + 0x820;
        if (*(int *)(iVar2 + 0x3c) == *(int *)(unaff_EBP + 8)) {
          if (*(int *)(iVar2 + 8) != 0) {
            FUN_00422d79(4,*(undefined2 *)(extraout_ECX + 0xf0),0);
          }
        }
        else {
          FUN_0045f8b0(iVar2);
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < (uint)(*(int *)(extraout_ECX + 0xa44) - *(int *)(extraout_ECX + 0xa40)));
    }
    bVar4 = *(int *)(unaff_EBP + -0x54) - *(int *)(unaff_EBP + -0x58) !=
            *(int *)(extraout_ECX + 0xa44) - *(int *)(extraout_ECX + 0xa40);
    if (bVar4) {
      FUN_0045d8aa(unaff_EBP + -0x278);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00635f6d(unaff_EBP + -0x278,0x44,8,FUN_004434c5);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return bVar4;
}

