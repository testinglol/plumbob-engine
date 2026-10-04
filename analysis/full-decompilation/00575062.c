
undefined4 FUN_00575062(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  void *pvVar5;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  int *piVar6;
  
  FUN_00634c24();
  *extraout_ECX = *(undefined4 *)(unaff_EBP + 8);
  iVar2 = FUN_005d49d6();
  if (iVar2 != 0) {
    iVar2 = FUN_005731df();
    *(int *)(unaff_EBP + -0x1c) = iVar2;
    if (iVar2 != 0) {
      iVar4 = FUN_0057d4e4(iVar2);
      *(int *)(unaff_EBP + -0x14) = iVar4;
      if (iVar4 == 0) {
        uVar3 = FUN_0057d50a(iVar2);
        *(undefined4 *)(unaff_EBP + -0x14) = uVar3;
      }
      FUN_005d4956(&DAT_006cf084);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_0042ecf6(unaff_EBP + 0xb);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_005b86bd(*(undefined4 *)(unaff_EBP + 0xc));
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_005d8277(unaff_EBP + -0x34,0,0,0);
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_005d8ab4(unaff_EBP + -0x50,1);
      FUN_005d8632(unaff_EBP + -0x10,8);
      piVar1 = *(int **)(unaff_EBP + -0x10);
      *(int **)(unaff_EBP + -0x18) = piVar1;
      piVar6 = (int *)*piVar1;
      if (piVar6 != piVar1) {
        do {
          iVar2 = FUN_0057d67f();
          *(int *)(unaff_EBP + 0xc) = iVar2;
          if (iVar2 == 0) break;
          uVar3 = FUN_004fee54(unaff_EBP + -0x5c,s_RadioStationAutoPatch_006cf088,piVar6 + 2);
          *(undefined1 *)(unaff_EBP + -4) = 4;
          FUN_005b86bd(uVar3);
          *(undefined1 *)(unaff_EBP + -4) = 6;
          FUN_00401729();
          uVar3 = FUN_00412a04(unaff_EBP + -0x68,unaff_EBP + -0x34,&DAT_006cc070);
          *(undefined1 *)(unaff_EBP + -4) = 7;
          uVar3 = FUN_00412ab1(unaff_EBP + -0x74,uVar3,piVar6 + 2);
          *(undefined1 *)(unaff_EBP + -4) = 8;
          FUN_005b86bd(uVar3);
          *(undefined1 *)(unaff_EBP + -4) = 0xb;
          FUN_00401729();
          *(undefined1 *)(unaff_EBP + -4) = 10;
          FUN_00401729();
          iVar2 = FUN_005be084(*(undefined4 *)(unaff_EBP + -0x28),unaff_EBP + -0x1c0,0x104);
          if ((iVar2 != 0) && (iVar2 != -1)) {
            FUN_005d4bbf(unaff_EBP + -0x1c0);
          }
          pvVar5 = operator_new(0xe8);
          *(void **)(unaff_EBP + -0x44) = pvVar5;
          *(undefined1 *)(unaff_EBP + -4) = 0xc;
          if (pvVar5 == (void *)0x0) {
            uVar3 = 0;
          }
          else {
            uVar3 = FUN_0057fc94(unaff_EBP + -0x40,unaff_EBP + -0x28,0,0,0,0,0);
          }
          *(undefined1 *)(unaff_EBP + -4) = 10;
          FUN_0057d0ce(*(undefined4 *)(unaff_EBP + 0xc),uVar3);
          FUN_005806fe(*(undefined4 *)(unaff_EBP + 0xc));
          piVar6 = (int *)*piVar6;
          *(undefined1 *)(unaff_EBP + -4) = 6;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 3;
          FUN_005b8770();
        } while (piVar6 != (int *)*(int *)(unaff_EBP + -0x18));
      }
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_0042a889();
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_0042ed0e();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      uVar3 = *(undefined4 *)(unaff_EBP + -0x1c);
      goto LAB_00575299;
    }
  }
  uVar3 = 0;
LAB_00575299:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

