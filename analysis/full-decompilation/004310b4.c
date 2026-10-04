
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004310b4(void)

{
  short sVar1;
  short sVar2;
  short sVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  short *psVar7;
  int iVar8;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  _DAT_006e4a60 = *(undefined4 *)(unaff_EBP + 0x14);
  iVar5 = **(int **)(unaff_EBP + 8);
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  iVar5 = (**(code **)(iVar5 + 0x38))
                    (*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10),FUN_0042004f
                    );
  *(int *)(unaff_EBP + 0x10) = iVar5;
  if (iVar5 == 0) {
    uVar6 = FUN_00401f6f();
  }
  else {
    psVar7 = (short *)FUN_00420048(iVar5);
    sVar1 = *psVar7;
    if (sVar1 == 0) {
      uVar6 = FUN_00420096(iVar5);
      FUN_004644dc(psVar7,uVar6,0,0);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_0043143a(unaff_EBP + -0x38,0);
      FUN_00465a06(iVar5);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0046453f();
    }
    else {
      sVar2 = psVar7[2];
      sVar3 = psVar7[1];
      *(int *)(extraout_ECX + 0x1c) = (int)sVar1;
      iVar5 = (int)sVar3;
      *(int *)(unaff_EBP + 0x14) = (int)sVar2;
      cVar4 = FUN_004313ae(iVar5,(int)sVar2);
      if (cVar4 == '\0') {
        uVar6 = 0xffffffff;
        goto LAB_004311a3;
      }
      iVar8 = iVar5 * *(int *)(unaff_EBP + 0x14) * (int)sVar1;
      if (iVar8 != 0) {
        FUN_005a92b0(**(undefined4 **)(*(int *)(unaff_EBP + -0x10) + 0xc),psVar7 + iVar5 * 2 + 4,
                     iVar8);
      }
      FUN_00465a06(*(undefined4 *)(unaff_EBP + 0x10));
    }
    uVar6 = 0;
  }
LAB_004311a3:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar6;
}

