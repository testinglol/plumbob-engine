
void FUN_005e6125(void)

{
  undefined4 uVar1;
  char cVar2;
  int extraout_ECX;
  int unaff_EBP;
  char *pcVar3;
  
  FUN_00634c24();
  FUN_005d4956(*(undefined4 *)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d4d37();
  cVar2 = FUN_005e6990(*(undefined4 *)(unaff_EBP + -0x24));
  if (cVar2 == '\0') {
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  else {
    FUN_005b86bd(unaff_EBP + -0x24);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_005343fd(unaff_EBP + 8,unaff_EBP + -0x18);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
    if (*(int *)(unaff_EBP + 8) == *(int *)(extraout_ECX + 4)) {
      FUN_005b86bd(unaff_EBP + -0x24);
      uVar1 = *(undefined4 *)(unaff_EBP + 0xc);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_005e6389(unaff_EBP + -0x30);
      *(undefined4 *)(unaff_EBP + -0x38) = uVar1;
      *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(unaff_EBP + 0x10);
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_005e6c5e(unaff_EBP + -0x14,unaff_EBP + -0x44);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_005b8770();
      if (*(int *)(unaff_EBP + 0x14) == 0) {
        FUN_005d4956(s_<No_Usage_Info_Registered>_006d7624);
        *(undefined1 *)(unaff_EBP + -4) = 9;
        FUN_005b86bd(unaff_EBP + -0x24);
        *(undefined1 *)(unaff_EBP + -4) = 10;
        FUN_005e6389(unaff_EBP + -0x3c);
        *(undefined1 *)(unaff_EBP + -4) = 0xb;
        FUN_005b86bd(unaff_EBP + -0x30);
        *(undefined1 *)(unaff_EBP + -4) = 0xc;
        FUN_005e6d4f(unaff_EBP + -0x14,unaff_EBP + -0x5c);
        *(undefined1 *)(unaff_EBP + -4) = 0xd;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 10;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 9;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 0;
      }
      else {
        FUN_005d4956(*(undefined4 *)(unaff_EBP + 0x14));
        *(undefined1 *)(unaff_EBP + -4) = 4;
        FUN_005b86bd(unaff_EBP + -0x24);
        *(undefined1 *)(unaff_EBP + -4) = 5;
        FUN_005e6389(unaff_EBP + -0x30);
        *(undefined1 *)(unaff_EBP + -4) = 6;
        FUN_005b86bd(unaff_EBP + -0x3c);
        *(undefined1 *)(unaff_EBP + -4) = 7;
        FUN_005e6d4f(unaff_EBP + -0x14,unaff_EBP + -0x5c);
        *(undefined1 *)(unaff_EBP + -4) = 8;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 5;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 4;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 0;
      }
      FUN_005b8770();
    }
    else if (*(int *)(unaff_EBP + 0xc) != 0) {
      uVar1 = *(undefined4 *)(unaff_EBP + 0x10);
      *(int *)(*(int *)(unaff_EBP + 8) + 0x1c) = *(int *)(unaff_EBP + 0xc);
      *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x20) = uVar1;
      FUN_005b86bd(unaff_EBP + -0x24);
      *(undefined1 *)(unaff_EBP + -4) = 0xe;
      FUN_005e6e12(unaff_EBP + 0xc,unaff_EBP + -0x3c);
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_005b8770();
      if (*(int *)(unaff_EBP + 0xc) != *(int *)(extraout_ECX + 0x10)) {
        if (*(int *)(unaff_EBP + 0x14) == 0) {
          pcVar3 = s_<No_Usage_Info_Registered>_006d7624;
        }
        else {
          pcVar3 = *(char **)(unaff_EBP + 0x14);
        }
        FUN_005d4bbf(pcVar3);
      }
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

