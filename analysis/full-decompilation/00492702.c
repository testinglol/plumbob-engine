
void FUN_00492702(void)

{
  undefined1 uVar1;
  char cVar2;
  int unaff_EBP;
  int iVar3;
  undefined4 uStack_10;
  undefined4 local_c;
  
  FUN_00634c24();
  *(undefined1 *)(unaff_EBP + 10) = 1;
  iVar3 = **(int **)(unaff_EBP + 8);
  uVar1 = (undefined1)((*(int **)(unaff_EBP + 8))[1] >> 4);
  *(undefined1 *)(unaff_EBP + 8) = uVar1;
  *(char *)(unaff_EBP + 9) = (char)(iVar3 >> 4);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 **)(unaff_EBP + -0x10) = &local_c;
  local_c._3_1_ = (char)(iVar3 >> 0x1c);
  local_c._0_3_ =
       CONCAT12(*(undefined1 *)(unaff_EBP + 10),CONCAT11(*(undefined1 *)(unaff_EBP + 9),uVar1));
  uStack_10 = 0x492749;
  cVar2 = FUN_00484b38();
  iVar3 = (int)cVar2 + *(int *)(unaff_EBP + 0xc);
  if (iVar3 < -0x80) {
    iVar3 = -0x80;
  }
  if (0x7f < iVar3) {
    iVar3 = 0x7f;
  }
  *(undefined4 **)(unaff_EBP + 0xc) = &uStack_10;
  local_c = iVar3;
  FUN_00461b74(unaff_EBP + 8);
  FUN_00484b6a();
  *(undefined4 **)(unaff_EBP + 0xc) = &uStack_10;
  local_c = iVar3;
  FUN_00461b74(unaff_EBP + 8);
  FUN_00484aed();
  local_c = unaff_EBP + 8;
  uStack_10 = 0x49279e;
  FUN_00492be0();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

