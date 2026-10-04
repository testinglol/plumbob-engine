
void FUN_004024fd(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int unaff_EBP;
  int iVar5;
  undefined *puVar6;
  
  FUN_00634c24();
  iVar5 = 0;
  if (((DAT_006de70c - DAT_006de708) / 0x54 != 0) || (DAT_006de714 != 0)) {
    FUN_00632b81(1);
    uVar2 = DAT_006de5fc;
    uVar1 = DAT_00689070;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_00632c55(uVar2,2,uVar1);
    if (*(int *)(unaff_EBP + -0x6c + *(int *)(*(int *)(unaff_EBP + -0x74) + 4)) == 0) {
      puVar6 = &DAT_006c08dc;
      FUN_0063301c((DAT_006de70c - DAT_006de708) / 0x54);
      FUN_006323d0(puVar6);
      iVar4 = DAT_006de708;
      iVar3 = DAT_006de70c - DAT_006de708;
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      if (iVar3 / 0x54 != 0) {
        do {
          FUN_00401d37(-(uint)(unaff_EBP != 0x74) & unaff_EBP - 0x68U,iVar5 + iVar4);
          iVar3 = DAT_006de70c;
          *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
          iVar5 = iVar5 + 0x54;
          iVar4 = DAT_006de708;
        } while (*(uint *)(unaff_EBP + -0x10) < (uint)((iVar3 - DAT_006de708) / 0x54));
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_00632c42();
      FUN_00632b08();
    }
    else {
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_00632c42();
      FUN_00632b08();
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

