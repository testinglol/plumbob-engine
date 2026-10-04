
void FUN_00484eca(void)

{
  char cVar1;
  size_t sVar2;
  int iVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if ((*(char *)(extraout_ECX + 0x2c) == '\0') &&
     ((DAT_006e57dc != *(int *)(unaff_EBP + 0xc) || (DAT_006e57d8 != *(int *)(unaff_EBP + 8))))) {
    cVar1 = FUN_00484ba0(unaff_EBP + 8);
    if (cVar1 == '\0') {
      DAT_006e57d8 = *(int *)(unaff_EBP + 8);
      DAT_006e57dc = *(int *)(unaff_EBP + 0xc);
      FUN_0048521a(0);
      *(undefined4 *)(unaff_EBP + -0x24) = 0;
      *(undefined4 *)(unaff_EBP + -0x20) = 0;
      *(undefined4 *)(unaff_EBP + -0x1c) = 0;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      sVar2 = _strlen(s_altitude_006c4f68);
      FUN_00401a3c(s_altitude_006c4f68,s_altitude_006c4f68 + sVar2);
      *(undefined4 *)(unaff_EBP + -4) = 1;
      FUN_0043162f(unaff_EBP + -0x24);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_00401729();
      iVar3 = DAT_006e57e4;
      *(undefined1 *)(unaff_EBP + -0x12) = 1;
      *(char *)(unaff_EBP + -0x14) = (char)(iVar3 >> 4);
      *(char *)(unaff_EBP + -0x13) = (char)(DAT_006e57e0 >> 4);
      iVar3 = DAT_006e57dc;
      *(undefined4 *)(unaff_EBP + -4) = 2;
      *(char *)(unaff_EBP + -0x10) = (char)(iVar3 >> 4);
      *(char *)(unaff_EBP + -0xf) = (char)(DAT_006e57d8 >> 4);
      *(undefined1 *)(unaff_EBP + -0xe) = 1;
      *(undefined1 *)(unaff_EBP + -4) = 3;
      *(undefined4 *)(extraout_ECX + 0x30) = 0;
      *(undefined4 *)(extraout_ECX + 0x38) = 0;
      cVar1 = FUN_00485361(unaff_EBP + -0x14,unaff_EBP + -0x10);
      *(char *)(unaff_EBP + -0x18) = cVar1;
      if (cVar1 != '\0') {
        iVar3 = FUN_0046d9e5();
        if (iVar3 < *(int *)(extraout_ECX + 0x30)) {
          *(undefined4 *)(extraout_ECX + 0x38) = 6;
          *(undefined1 *)(extraout_ECX + 0x34) = 0xff;
          *(undefined1 *)(extraout_ECX + 0x35) = 0xff;
          *(undefined1 *)(unaff_EBP + -0x18) = 0;
          *(undefined1 *)(extraout_ECX + 0x36) = 1;
        }
      }
      FUN_0049122d(unaff_EBP + -0x14,unaff_EBP + -0x10,*(undefined4 *)(unaff_EBP + -0x18));
      FUN_00491b2b();
      *(undefined4 *)(unaff_EBP + -0x30) = 0;
      *(undefined4 *)(unaff_EBP + -0x2c) = 0;
      *(undefined4 *)(unaff_EBP + -0x28) = 0;
      *(undefined1 *)(unaff_EBP + -4) = 4;
      sVar2 = _strlen(s_altitude_006c4f68);
      FUN_00401a3c(s_altitude_006c4f68,s_altitude_006c4f68 + sVar2);
      *(undefined1 *)(unaff_EBP + -4) = 5;
      FUN_0043168c(unaff_EBP + -0x30);
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_00401729();
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

