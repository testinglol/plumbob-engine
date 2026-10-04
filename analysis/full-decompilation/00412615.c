
undefined4 FUN_00412615(void)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_00412594();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar3 = FUN_00412cef(unaff_EBP + -0x74,*(undefined4 *)(unaff_EBP + 8),0x2a);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b86bd(uVar3);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_00401729();
  uVar3 = FUN_005b8e25();
  *(undefined4 *)(unaff_EBP + 8) = uVar3;
  cVar2 = FUN_005ba87e(*(undefined4 *)(unaff_EBP + -0x34),unaff_EBP + -0x68);
  if (cVar2 == '\0') {
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = FUN_00412ab1(unaff_EBP + -0x28,unaff_EBP + -0x68,unaff_EBP + -0x5c);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_005b86bd(uVar3);
    *(undefined1 *)(unaff_EBP + -4) = 6;
    FUN_00401729();
    uVar3 = *(undefined4 *)(unaff_EBP + -0x1c);
    FUN_0046f824(unaff_EBP + -0x178,0,0x104);
    *(undefined ***)(unaff_EBP + -0x184) = &PTR_FUN_006664e8;
    FUN_0046f847(uVar3,0xffffffff);
    if (*(char *)(unaff_EBP + -0x50) == '\0') {
      piVar1 = *(int **)(unaff_EBP + -0x10);
      *(undefined1 *)(piVar1 + 1) = *(undefined1 *)(unaff_EBP + -0x4f);
      (**(code **)(*piVar1 + 4))(unaff_EBP + -0x184);
    }
    else {
      iVar4 = (**(code **)**(undefined4 **)(unaff_EBP + -0x10))(unaff_EBP + -0x184);
      if (iVar4 != 0) {
        FUN_004015e4(0x5c);
        FUN_00412615(unaff_EBP + -0x1c);
      }
    }
    *(undefined1 *)(unaff_EBP + -4) = 3;
    while( true ) {
      FUN_005b8770();
      cVar2 = FUN_005ba989(unaff_EBP + -0x68);
      if (cVar2 == '\0') break;
      uVar3 = FUN_00412ab1(unaff_EBP + -0x28,unaff_EBP + -0x68,unaff_EBP + -0x5c);
      *(undefined1 *)(unaff_EBP + -4) = 7;
      FUN_005b86bd(uVar3);
      *(undefined1 *)(unaff_EBP + -4) = 9;
      FUN_00401729();
      uVar3 = *(undefined4 *)(unaff_EBP + -0x1c);
      FUN_0046f824(unaff_EBP + -0x178,0,0x104);
      *(undefined ***)(unaff_EBP + -0x184) = &PTR_FUN_006664e8;
      FUN_0046f847(uVar3,0xffffffff);
      if (*(char *)(unaff_EBP + -0x50) == '\0') {
        piVar1 = *(int **)(unaff_EBP + -0x10);
        *(undefined1 *)(piVar1 + 1) = *(undefined1 *)(unaff_EBP + -0x4f);
        (**(code **)(*piVar1 + 4))(unaff_EBP + -0x184);
      }
      else {
        iVar4 = (**(code **)**(undefined4 **)(unaff_EBP + -0x10))(unaff_EBP + -0x184);
        if (iVar4 != 0) {
          FUN_004015e4(0x5c);
          FUN_00412615(unaff_EBP + -0x1c);
        }
      }
      *(undefined1 *)(unaff_EBP + -4) = 3;
    }
    uVar3 = 0;
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004125d1();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

