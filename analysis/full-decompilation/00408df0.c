
undefined4 * FUN_00408df0(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 extraout_ECX;
  int unaff_EBP;
  int iVar5;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0040d069(unaff_EBP + -0x20);
  iVar5 = DAT_006e4840;
  do {
    if (iVar5 == DAT_006e4844) {
LAB_00408e3c:
      uVar2 = FUN_00408987(unaff_EBP + -0x20);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_0040f538(uVar2);
      iVar5 = DAT_006e4840;
      iVar1 = DAT_006e4844 - DAT_006e4840;
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      iVar5 = (iVar1 / 0x90) * 0x90 + -0x90 + iVar5;
LAB_00408e7b:
      iVar1 = FUN_0040cc3f();
      iVar3 = FUN_0040cd0e();
      iVar1 = (uint)(iVar3 != 0) + (uint)(iVar1 != 0) * 2;
      puVar4 = *(undefined4 **)(iVar5 + 0x30 + iVar1 * 4);
      if (puVar4 == (undefined4 *)0x0) {
        puVar4 = operator_new(0xc);
        if (puVar4 == (undefined4 *)0x0) {
          puVar4 = (undefined4 *)0x0;
        }
        else {
          *puVar4 = 0;
          puVar4[1] = 0;
          puVar4[2] = 0;
        }
        *(undefined4 **)(iVar5 + 0x30 + iVar1 * 4) = puVar4;
        FUN_00409953(puVar4);
      }
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return puVar4;
    }
    iVar1 = FUN_0046f973(unaff_EBP + -0x20);
    if (iVar1 == 0) {
      if (iVar5 != DAT_006e4844) goto LAB_00408e7b;
      goto LAB_00408e3c;
    }
    iVar5 = iVar5 + 0x90;
  } while( true );
}

