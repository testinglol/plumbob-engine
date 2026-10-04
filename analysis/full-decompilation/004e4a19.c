
undefined1 FUN_004e4a19(void)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *piVar6;
  char *_Str;
  size_t sVar7;
  undefined4 extraout_ECX;
  uint uVar8;
  undefined1 uVar9;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x1c) = extraout_ECX;
  FUN_0046ea4d();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = FUN_0046eaca(*(undefined4 *)(unaff_EBP + 8));
  if (iVar1 == 0) {
    iVar1 = 2;
    while( true ) {
      iVar2 = FUN_0046edbd(0,iVar1);
      if (iVar2 == 0) break;
      pvVar3 = operator_new(0x74);
      *(void **)(unaff_EBP + -0x44) = pvVar3;
      *(undefined1 *)(unaff_EBP + -4) = 1;
      if (pvVar3 == (void *)0x0) {
        puVar4 = (undefined4 *)0x0;
      }
      else {
        puVar4 = (undefined4 *)FUN_004e489e();
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      uVar5 = FUN_0046edbd(0,iVar1);
      iVar2 = FUN_00634d24(uVar5,&DAT_006c08e4,unaff_EBP + 8);
      if (iVar2 != 1) {
LAB_004e4bb2:
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_0046ea5a();
        uVar9 = 0;
        goto LAB_004e4bd2;
      }
      *puVar4 = *(undefined4 *)(unaff_EBP + 8);
      iVar2 = FUN_0046edbd(1,iVar1);
      if (iVar2 == 0) goto LAB_004e4bb2;
      FUN_0046f824(unaff_EBP + -0x84,0,0x40);
      *(undefined ***)(unaff_EBP + -0x90) = &PTR_FUN_0066651c;
      FUN_0046f847(iVar2,0xffffffff);
      FUN_0046f8e4(unaff_EBP + -0x90);
      iVar2 = FUN_0046edbd(6,iVar1);
      if (iVar2 == 0) goto LAB_004e4bb2;
      iVar2 = FUN_00634d24(iVar2,s__d__d__d__d__d__d__d__d_006c9bfc,unaff_EBP + -0x40,
                           unaff_EBP + -0x3c,unaff_EBP + -0x38,unaff_EBP + -0x34,unaff_EBP + -0x30,
                           unaff_EBP + -0x2c,unaff_EBP + -0x28,unaff_EBP + -0x24);
      if (iVar2 != 8) goto LAB_004e4bb2;
      uVar8 = 0;
      piVar6 = (int *)(unaff_EBP + -0x40);
      do {
        iVar2 = *piVar6;
        if ((iVar2 < 0) || (0xff < iVar2)) goto LAB_004e4bb2;
        *(char *)(uVar8 + 0x6c + (int)puVar4) = (char)iVar2;
        uVar8 = uVar8 + 1;
        piVar6 = piVar6 + 1;
      } while (uVar8 < 8);
      iVar2 = FUN_0046edbd(2,iVar1);
      if (iVar2 != 0) {
        _Str = (char *)FUN_0046edbd(2,iVar1);
        sVar7 = _strlen(_Str);
        FUN_00431779(_Str,_Str + sVar7);
      }
      *(undefined4 **)(unaff_EBP + -0x20) = puVar4;
      FUN_004e4faf(unaff_EBP + -0x20);
      iVar1 = iVar1 + 1;
    }
    uVar9 = 1;
  }
  else {
    uVar9 = 0;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0046ea5a();
LAB_004e4bd2:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar9;
}

