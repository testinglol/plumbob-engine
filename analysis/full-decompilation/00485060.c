
void FUN_00485060(void)

{
  int iVar1;
  char cVar2;
  size_t sVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(char *)(extraout_ECX + 0x2c) != '\0') goto LAB_0048520a;
  *(undefined4 *)(extraout_ECX + 0x38) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  sVar3 = _strlen(s_altitude_006c4f68);
  FUN_00401a3c(s_altitude_006c4f68,s_altitude_006c4f68 + sVar3);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_0043162f(unaff_EBP + -0x24);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00401729();
  iVar1 = DAT_006e57e4;
  *(undefined1 *)(unaff_EBP + -0x16) = 1;
  *(char *)(unaff_EBP + -0x18) = (char)(iVar1 >> 4);
  *(char *)(unaff_EBP + -0x17) = (char)(DAT_006e57e0 >> 4);
  iVar1 = DAT_006e57dc;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  *(char *)(unaff_EBP + -0x14) = (char)(iVar1 >> 4);
  *(char *)(unaff_EBP + -0x13) = (char)(DAT_006e57d8 >> 4);
  *(undefined1 *)(unaff_EBP + -0x12) = 1;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  *(undefined4 *)(extraout_ECX + 0x30) = 0;
  cVar2 = FUN_00485361(unaff_EBP + -0x18,unaff_EBP + -0x14);
  *(char *)(unaff_EBP + -0xd) = cVar2;
  if (cVar2 == '\0') {
LAB_0048518a:
    *(undefined4 *)(extraout_ECX + 0x30) = 0;
    *(undefined4 *)(unaff_EBP + -0x30) = 0;
    *(undefined4 *)(unaff_EBP + -0x2c) = 0;
    *(undefined4 *)(unaff_EBP + -0x28) = 0;
    *(undefined1 *)(unaff_EBP + -4) = 4;
    sVar3 = _strlen(s_altitude_006c4f68);
    FUN_00401a3c(s_altitude_006c4f68,s_altitude_006c4f68 + sVar3);
    *(undefined1 *)(unaff_EBP + -4) = 5;
    FUN_0043168c(unaff_EBP + -0x30);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_00401729();
    FUN_00492c37();
  }
  else {
    cVar2 = FUN_00492b81(*(undefined4 *)(extraout_ECX + 0x30));
    if (cVar2 == '\0') {
      *(undefined4 *)(extraout_ECX + 0x38) = 6;
      *(undefined1 *)(extraout_ECX + 0x34) = 0xff;
      *(undefined1 *)(extraout_ECX + 0x35) = 0xff;
      *(undefined1 *)(unaff_EBP + -0xd) = 0;
      *(undefined1 *)(extraout_ECX + 0x36) = 1;
    }
    else {
      FUN_00492bb0(*(undefined4 *)(extraout_ECX + 0x30));
      FUN_00492bc4();
    }
    if (*(char *)(unaff_EBP + -0xd) == '\0') goto LAB_0048518a;
    FUN_00490a23(DAT_006e57cc);
    FUN_0040766a(0x85,0);
    FUN_0057a7f7(s_Ui_terrain_level_006c5e28,0xfffffffc);
  }
  if (*(int **)(extraout_ECX + 0x50) != (int *)0x0) {
    (**(code **)(**(int **)(extraout_ECX + 0x50) + 0x50))(1);
  }
  if (*(int **)(extraout_ECX + 0x54) != (int *)0x0) {
    (**(code **)(**(int **)(extraout_ECX + 0x54) + 0x50))(1);
  }
  FUN_00491331(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
               *(undefined4 *)(unaff_EBP + 0x10),*(undefined4 *)(unaff_EBP + 0x14));
  FUN_00491b2b();
LAB_0048520a:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

