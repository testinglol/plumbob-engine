
void FUN_00546cfe(void)

{
  undefined4 *puVar1;
  char cVar2;
  undefined4 uVar3;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar2 = (**(code **)(*extraout_ECX + 200))();
  if (cVar2 == '\0') {
    FUN_005e8e14();
  }
  else {
    if ((char)extraout_ECX[0x4a] == '\0') {
      FUN_004ea674(extraout_ECX[0x47],0,*(char *)((int)extraout_ECX + 0x121) == '\0',1);
      if ((char)extraout_ECX[0x48] != '\0') {
        FUN_004e1e40(extraout_ECX[0x47]);
      }
      *(undefined1 *)(extraout_ECX + 0x4a) = 1;
    }
    if ((undefined4 *)extraout_ECX[0x42] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)extraout_ECX[0x42])(1);
    }
    extraout_ECX[0x42] = 0;
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    FUN_0054821c(5,unaff_EBP + -0xd);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    uVar3 = FUN_005fd5b4(*(undefined4 *)(unaff_EBP + -0x20),5,unaff_EBP + -0x14,
                         *(undefined4 *)(unaff_EBP + -0x14));
    *(undefined4 *)(unaff_EBP + -0x1c) = uVar3;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_0054843e(unaff_EBP + -0x20);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0048c4c9();
    _memset(extraout_ECX + 0x4b,0x34,0);
    extraout_ECX[0x5b] = 0;
    if ((undefined4 *)extraout_ECX[0x62] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)extraout_ECX[0x62])(1);
    }
    extraout_ECX[0x62] = 0;
    *(int *)(DAT_006fe8f4 + 0x1fc) = extraout_ECX[0x69];
    puVar1 = (undefined4 *)extraout_ECX[0x6a];
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    extraout_ECX[0x6a] = 0;
    FUN_005e8e14();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

