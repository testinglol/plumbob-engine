
undefined1 FUN_004d5aa6(void)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar1 = (**(code **)(*extraout_ECX + 200))();
  if (cVar1 == '\0') {
    FUN_004cb1a2(0x15e,0x6e);
    FUN_004cb21d(10,0x5a);
    (**(code **)(*extraout_ECX + 0x90))(0x10,0);
    (**(code **)(*extraout_ECX + 0x90))(4,0);
    iVar3 = FUN_005dd5e1(0x28,0x28,0x28);
    extraout_ECX[0x19] = iVar3;
    cVar1 = FUN_004d55fe();
    uVar2 = 0;
    if (cVar1 != '\0') {
      FUN_004d5ec6(extraout_ECX[0x3c]);
      FUN_005b870f(s_New_Event_Log_006c7d70);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_004d5e20(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      FUN_005b870f(s_Hello__006c7d68);
      *(undefined4 *)(unaff_EBP + -4) = 1;
      FUN_004d5e20(unaff_EBP + -0x24);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      uVar2 = 1;
    }
  }
  else {
    uVar2 = FUN_004d55fe();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

