
undefined4 FUN_0041229a(void)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_00412594();
  puVar4 = *(undefined4 **)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar3 = FUN_00412a04(unaff_EBP + -0x98,puVar4,&DAT_006c12fc);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b86bd(uVar3);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_00401729();
  FUN_005b91e8();
  uVar3 = *puVar4;
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_005b92ee(uVar3,0,1);
  cVar2 = FUN_005ba87e(*(undefined4 *)(unaff_EBP + -0x74),unaff_EBP + -0x68);
  if (cVar2 == '\0') {
    uVar3 = 0xffffffff;
LAB_0041255b:
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_005b922c();
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_004125d1();
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return uVar3;
  }
  uVar3 = FUN_00412ab1(unaff_EBP + -0x28,unaff_EBP + -0x68,unaff_EBP + -0x5c);
  *(undefined1 *)(unaff_EBP + -4) = 5;
  puVar4 = (undefined4 *)FUN_005b86bd(uVar3);
  uVar3 = *puVar4;
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_0046f824(unaff_EBP + -0x1e4,0,0x104);
  *(undefined ***)(unaff_EBP + -0x1f0) = &PTR_FUN_006664e8;
  FUN_0046f847(uVar3,0xffffffff);
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_00401729();
  if (*(char *)(unaff_EBP + -0x50) == '\0') {
    piVar1 = *(int **)(unaff_EBP + -0x10);
    *(undefined1 *)(piVar1 + 1) = *(undefined1 *)(unaff_EBP + -0x4f);
    iVar5 = *piVar1;
    goto LAB_0041242a;
  }
  iVar5 = (**(code **)**(undefined4 **)(unaff_EBP + -0x10))(unaff_EBP + -0x1f0);
  if (iVar5 == 0) goto LAB_0041242e;
  uVar3 = FUN_00412ab1(unaff_EBP + -0x34,unaff_EBP + -0x68,unaff_EBP + -0x5c);
  *(undefined1 *)(unaff_EBP + -4) = 7;
  uVar3 = FUN_00412cef(unaff_EBP + -0x1c,uVar3,0x5c);
  *(undefined1 *)(unaff_EBP + -4) = 8;
  uVar3 = FUN_005b86bd(uVar3);
  *(undefined1 *)(unaff_EBP + -4) = 9;
  FUN_0041229a(uVar3);
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_00401729();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  do {
    FUN_00401729();
LAB_0041242e:
    do {
      while( true ) {
        cVar2 = FUN_005ba989(unaff_EBP + -0x68);
        if (cVar2 == '\0') {
          FUN_005b9292();
          uVar3 = 0;
          goto LAB_0041255b;
        }
        uVar3 = FUN_00412ab1(unaff_EBP + -0x28,unaff_EBP + -0x68,unaff_EBP + -0x5c);
        *(undefined1 *)(unaff_EBP + -4) = 10;
        puVar4 = (undefined4 *)FUN_005b86bd(uVar3);
        uVar3 = *puVar4;
        *(undefined1 *)(unaff_EBP + -4) = 0xb;
        FUN_0046f824(unaff_EBP + -0x1e4,0,0x104);
        *(undefined ***)(unaff_EBP + -0x1f0) = &PTR_FUN_006664e8;
        FUN_0046f847(uVar3,0xffffffff);
        *(undefined1 *)(unaff_EBP + -4) = 10;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 4;
        FUN_00401729();
        if (*(char *)(unaff_EBP + -0x50) != '\0') break;
        piVar1 = *(int **)(unaff_EBP + -0x10);
        *(undefined1 *)(piVar1 + 1) = *(undefined1 *)(unaff_EBP + -0x4f);
        iVar5 = *piVar1;
LAB_0041242a:
        (**(code **)(iVar5 + 4))(unaff_EBP + -0x1f0);
      }
      iVar5 = (**(code **)**(undefined4 **)(unaff_EBP + -0x10))(unaff_EBP + -0x1f0);
    } while (iVar5 == 0);
    uVar3 = FUN_00412ab1(unaff_EBP + -0x80,unaff_EBP + -0x68,unaff_EBP + -0x5c);
    *(undefined1 *)(unaff_EBP + -4) = 0xc;
    uVar3 = FUN_00412cef(unaff_EBP + -0x8c,uVar3,0x5c);
    *(undefined1 *)(unaff_EBP + -4) = 0xd;
    uVar3 = FUN_005b86bd(uVar3);
    *(undefined1 *)(unaff_EBP + -4) = 0xe;
    FUN_0041229a(uVar3);
    *(undefined1 *)(unaff_EBP + -4) = 0xd;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0xc;
    FUN_00401729();
    *(undefined1 *)(unaff_EBP + -4) = 4;
  } while( true );
}

