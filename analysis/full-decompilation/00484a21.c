
void FUN_00484a21(void)

{
  int *piVar1;
  char cVar2;
  undefined1 uVar3;
  int unaff_EBP;
  int iVar4;
  undefined4 uStack_14;
  undefined4 local_10;
  
  FUN_00634c24();
  piVar1 = *(int **)(unaff_EBP + 8);
  uStack_14 = 0x484a3f;
  local_10 = piVar1;
  cVar2 = FUN_00484ba0();
  if (cVar2 == '\0') {
    iVar4 = *piVar1;
    uVar3 = (undefined1)(piVar1[1] >> 4);
    *(undefined1 *)(unaff_EBP + 8) = uVar3;
    *(char *)(unaff_EBP + 9) = (char)(iVar4 >> 4);
    *(undefined1 *)(unaff_EBP + 10) = 1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(undefined4 **)(unaff_EBP + -0x10) = &local_10;
    local_10._3_1_ = (char)(iVar4 >> 0x1c);
    local_10._0_3_ =
         CONCAT12(*(undefined1 *)(unaff_EBP + 10),CONCAT11(*(undefined1 *)(unaff_EBP + 9),uVar3));
    uStack_14 = 0x484a87;
    cVar2 = FUN_00484b38();
    iVar4 = (int)cVar2 + *(int *)(unaff_EBP + 0xc);
    if (iVar4 < -0x80) {
      iVar4 = -0x80;
    }
    if (0x7f < iVar4) {
      iVar4 = 0x7f;
    }
    *(undefined4 **)(unaff_EBP + 0xc) = &uStack_14;
    local_10 = (int *)iVar4;
    FUN_00461b74(unaff_EBP + 8);
    FUN_00484b6a();
    *(undefined4 **)(unaff_EBP + 0xc) = &uStack_14;
    local_10 = (int *)iVar4;
    FUN_00461b74(unaff_EBP + 8);
    FUN_00484aed();
    local_10 = (int *)(unaff_EBP + 8);
    uStack_14 = 0x484adc;
    FUN_00492be0();
  }
  else {
    local_10 = (int *)0x484a4a;
    FUN_00492c37();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

