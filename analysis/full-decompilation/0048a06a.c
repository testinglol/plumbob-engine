
void FUN_0048a06a(void)

{
  char cVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int iVar3;
  int unaff_EBP;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  FUN_00634c24();
  cVar1 = FUN_00484ba0(unaff_EBP + 8);
  if (cVar1 == '\0') {
    *(undefined4 *)(extraout_ECX + 0x60) = 0;
    FUN_004864ed(0,0xffffffff);
    DAT_006e57e0 = *(undefined4 *)(unaff_EBP + 8);
    puVar4 = *(undefined4 **)(unaff_EBP + 0x14);
    uVar2 = *(undefined4 *)(unaff_EBP + 0xc);
    DAT_006e57e4 = uVar2;
    *(undefined4 *)(extraout_ECX + 0x40) = DAT_006e57e0;
    *(undefined4 *)(extraout_ECX + 0x44) = uVar2;
    puVar5 = (undefined4 *)(extraout_ECX + 0x48);
    for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    uVar2 = FUN_0048a777();
    *(undefined4 *)(extraout_ECX + 0x3c) = uVar2;
    FUN_0048a9df(uVar2);
    puVar4 = (undefined4 *)(*(int *)(unaff_EBP + 0x14) + 0xc);
    FUN_0048a829(unaff_EBP + 8,unaff_EBP + -0x14,puVar4);
    uVar2 = FUN_00492b26();
    *(undefined4 *)(unaff_EBP + 0x14) = uVar2;
    *(char *)(unaff_EBP + -0x10) = (char)(*(int *)(unaff_EBP + 0xc) >> 4);
    *(char *)(unaff_EBP + -0xf) = (char)(*(int *)(unaff_EBP + 8) >> 4);
    *(char *)(unaff_EBP + -0xe) = (char)uVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_0048a909(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),uVar2,
                 *(undefined4 *)(unaff_EBP + -0x14),0);
    if (*(int *)(extraout_ECX + 0x30) != 0) {
      FUN_00493875();
      iVar3 = *(int *)(extraout_ECX + 0x3c);
      if ((iVar3 == 2) || (iVar3 == 3)) {
        cVar1 = FUN_0048aa53(unaff_EBP + 8,*(undefined4 *)(unaff_EBP + 0x14),
                             *(undefined4 *)(unaff_EBP + -0x14),*puVar4,iVar3);
        if (cVar1 == '\0') {
          FUN_00493875();
          *(undefined1 *)(*(int *)(extraout_ECX + 0x30) + 0x40) = 1;
        }
      }
      else {
        cVar1 = FUN_00493897(unaff_EBP + -0x10,iVar3,*(undefined4 *)(unaff_EBP + -0x14),0,0);
        if (cVar1 != '\0') {
          FUN_004939fc(unaff_EBP + -0x10,*(undefined4 *)(extraout_ECX + 0x3c),
                       *(undefined4 *)(unaff_EBP + -0x14),0);
        }
      }
      uVar2 = FUN_00492b26();
      FUN_00540a5b(uVar2);
      FUN_00540ecf(uVar2);
    }
    iVar3 = FUN_00492d2c();
    if (iVar3 != 0) {
      *(undefined4 *)(extraout_ECX + 0x60) = 0x1a;
      uVar2 = FUN_00492d2c();
      FUN_004864ed(*(undefined4 *)(extraout_ECX + 0x60),uVar2);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

