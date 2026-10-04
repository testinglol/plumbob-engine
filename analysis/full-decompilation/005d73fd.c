
undefined4 FUN_005d73fd(void)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar2 = (**(code **)(*extraout_ECX + 200))();
  if (cVar2 == '\0') {
    uVar3 = 1;
  }
  else {
    (**(code **)(*extraout_ECX + 0x90))(1,0);
    if (extraout_ECX[0x3b] != 0) {
      cVar2 = (**(code **)(*extraout_ECX + 0x38))(extraout_ECX[0x3b]);
      if (cVar2 != '\0') {
        (**(code **)(*extraout_ECX + 0x28))(extraout_ECX[0x3b]);
        extraout_ECX[0x3b] = 0;
      }
    }
    FUN_005d724d(0);
    FUN_005d70ad(0);
    uVar3 = FUN_005d48d9();
    iVar1 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    (**(code **)(iVar1 + 0x9c))(uVar3);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    (**(code **)(*extraout_ECX + 0xcc))(0);
    if ((undefined4 *)extraout_ECX[0x3c] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)extraout_ECX[0x3c])(1);
    }
    iVar1 = extraout_ECX[0x16];
    extraout_ECX[0x3c] = 0;
    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x5c) != 0)) {
      FUN_005e3581();
      *(undefined4 *)(iVar1 + 0x5c) = 0;
    }
    uVar3 = 0;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

