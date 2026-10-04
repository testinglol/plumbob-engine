
undefined4 FUN_005725c4(void)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 extraout_ECX;
  int unaff_EBP;
  int *piVar5;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x18) = extraout_ECX;
  FUN_005d4956(s___hit_006ceff0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0042ecf6(unaff_EBP + -0x11);
  uVar4 = *(undefined4 *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d8277(uVar4,0,0,0);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005d8ab4(unaff_EBP + -0x30,1);
  FUN_005d8632(unaff_EBP + -0x10,8);
  piVar1 = *(int **)(unaff_EBP + -0x10);
  *(int **)(unaff_EBP + 8) = piVar1;
  piVar5 = (int *)*piVar1;
  if (piVar5 != piVar1) {
    do {
      FUN_005b86bd(piVar5 + 2);
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_005728f7(unaff_EBP + -0x48);
      *(undefined1 *)(unaff_EBP + -4) = 4;
      uVar3 = FUN_005729e0();
      FUN_005b86bd(uVar3);
      *(undefined1 *)(unaff_EBP + -4) = 5;
      uVar3 = FUN_00412ab1(unaff_EBP + -0x9c,uVar4,unaff_EBP + -0x24);
      *(undefined1 *)(unaff_EBP + -4) = 6;
      uVar3 = FUN_00412a04(unaff_EBP + -0x90,uVar3,&DAT_006cefe8);
      *(undefined1 *)(unaff_EBP + -4) = 7;
      FUN_005b86bd(uVar3);
      *(undefined1 *)(unaff_EBP + -4) = 10;
      FUN_00401729();
      *(undefined1 *)(unaff_EBP + -4) = 9;
      FUN_00401729();
      FUN_0057d3bd(unaff_EBP + -0x3c);
      uVar3 = FUN_00412ab1(unaff_EBP + -0xa8,uVar4,unaff_EBP + -0x24);
      *(undefined1 *)(unaff_EBP + -4) = 0xb;
      uVar3 = FUN_00412a04(unaff_EBP + -0x6c,uVar3,&DAT_006cefe0);
      *(undefined1 *)(unaff_EBP + -4) = 0xc;
      FUN_005b86bd(uVar3);
      *(undefined1 *)(unaff_EBP + -4) = 0xf;
      FUN_00401729();
      *(undefined1 *)(unaff_EBP + -4) = 0xe;
      FUN_00401729();
      FUN_0057d19b(unaff_EBP + -0x54);
      uVar3 = FUN_00412ab1(unaff_EBP + -0x84,uVar4,unaff_EBP + -0x24);
      *(undefined1 *)(unaff_EBP + -4) = 0x10;
      uVar3 = FUN_00412a04(unaff_EBP + -0x78,uVar3,&DAT_006cefd8);
      *(undefined1 *)(unaff_EBP + -4) = 0x11;
      FUN_005b86bd(uVar3);
      *(undefined1 *)(unaff_EBP + -4) = 0x14;
      FUN_00401729();
      *(undefined1 *)(unaff_EBP + -4) = 0x13;
      FUN_00401729();
      FUN_0057b142(unaff_EBP + -0x60,*(undefined4 *)(unaff_EBP + -0x18));
      *(undefined ***)(unaff_EBP + -0xd8) = &PTR_FUN_006715a4;
      *(undefined1 *)(unaff_EBP + -4) = 0x15;
      cVar2 = FUN_005713cc();
      if (cVar2 == '\0') {
        *(undefined1 *)(unaff_EBP + -4) = 0x13;
        *(undefined ***)(unaff_EBP + -0xd8) = &PTR_FUN_006715a4;
        FUN_0057b1dd();
        *(undefined1 *)(unaff_EBP + -4) = 0xe;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 9;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 5;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 4;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 3;
        FUN_00572aec();
        *(undefined1 *)(unaff_EBP + -4) = 2;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_0042a889();
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_0042ed0e();
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_005b8770();
        uVar4 = 0;
        goto LAB_00572858;
      }
      piVar5 = (int *)*piVar5;
      *(undefined1 *)(unaff_EBP + -4) = 0x13;
      *(undefined ***)(unaff_EBP + -0xd8) = &PTR_FUN_006715a4;
      FUN_0057b1dd();
      *(undefined1 *)(unaff_EBP + -4) = 0xe;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 9;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 5;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_00572aec();
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_005b8770();
    } while (piVar5 != (int *)*(int *)(unaff_EBP + 8));
  }
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0042a889();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0042ed0e();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  uVar4 = 1;
LAB_00572858:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

